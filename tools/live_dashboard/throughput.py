"""Read-only, backend-wide output-token telemetry (stdlib only).

Configuration: {"providers": {"qwen": {"url": "http://host/metrics",
"backend": "auto", "model": "optional exact model_name label"}, ...}}.
Provider keys are qwen/glm/openai/other; backend is auto/vllm/sglang/llama.cpp/
tensorfold. Missing providers are unavailable. Optional top-level interval,
timeout and staleAfter are seconds (defaults 2/2/10). No credentials, endpoint
URLs, model labels, response bodies or exception text enter public snapshots.

Total rate is a cumulative *output* token delta divided by monotonic elapsed
time. Average is total divided by the mean of the two endpoint active gauges
(trapezoidal sampled concurrency over that same window), NOT the arithmetic
mean of individual request speeds. Short-lived requests between scrapes can
be missed by the denominator; a positive token delta with zero endpoint
concurrency therefore has a null average. activeStreams is that window's mean
concurrency (the current gauge while establishing the first baseline).
vLLM/SGLang running gauges include prefill; this limitation is public in reason.
TensorFold and recent llama.cpp slots distinguish decoding from prefill.

Primary definitions and implementation evidence:
- vLLM generation_tokens increments per iteration; num_requests_running is
  requests in model-execution batches (not decoding-only):
  https://github.com/vllm-project/vllm/blob/main/vllm/v1/metrics/loggers.py
  https://docs.vllm.ai/en/latest/design/metrics/
- SGLang realtime_tokens_total{mode="decode"} counts live decode-phase output
  (not prefill-produced first tokens); collector/reporting cadence is version-dependent:
  https://github.com/sgl-project/sglang/blob/main/python/sglang/srt/observability/metrics_collector.py
  https://github.com/sgl-project/sglang/blob/main/python/sglang/srt/managers/scheduler_components/metrics_reporter.py
  generation_tokens_total is finished-request accounting, NOT live throughput:
  https://github.com/sgl-project/sglang/blob/v0.5.4/python/sglang/srt/metrics/collector.py
- llama.cpp tokens_predicted_total flushes on release. Recent /slots exposes
  next_token.n_decoded and resets it on release, alongside prompt-progress fields:
  https://github.com/ggml-org/llama.cpp/blob/master/tools/server/server-context.cpp
  https://github.com/ggml-org/llama.cpp/blob/master/tools/server/server-task.cpp
  https://github.com/ggml-org/llama.cpp/blob/master/tools/server/README.md
  We bracket /slots with equal finished-token counters, yielding a coherent
  finished + in-flight cumulative count. Old slot formats retain prior-request
  n_decoded during prefill and are refused, not guessed. Enable --metrics and
  leave /slots enabled; no backend flags are changed by this module.
- TensorFold is NOT assumed llama.cpp compatible. CUDA /health includes live
  completion_tokens_total and streams.decoding (without streams, no denominator):
  https://github.com/ashhart/TensorFold/blob/v0.5.0/src/tensorfold/cuda/health.py
  https://github.com/ashhart/TensorFold/blob/v0.5.0/docs/api.md
  The deployed /metrics HELP at http://100.92.139.82:8888/metrics identifies
  tensorfold_health:completion_tokens_total as including running replies and
  tensorfold_health:streams{state="decoding"} as the decoder state gauge.
  tensorfold:generation_tokens_total is finished-only and never used. When the
  live metrics are absent, auto/tensorfold probes sibling /health each poll.

Each configured provider has one polling thread, independent of dashboard
clients. Socket operations and body reads have bounded timeouts and body size;
HTTP never occurs under the snapshot lock. Like stdlib HTTP clients generally,
OS DNS resolution is not governed by the socket timeout; stale snapshots still
expire independently even if a resolver stalls. No retries or remote writes.
"""

from __future__ import annotations

import http.client
import json
import math
import re
import threading
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from urllib.parse import urlsplit, urlunsplit

PROVIDERS = ("qwen", "glm", "openai", "other")
BACKENDS = ("auto", "vllm", "sglang", "llama.cpp", "tensorfold")
MAX_RESPONSE_BYTES = 2 * 1024 * 1024
_SAMPLE = re.compile(
    r'^([a-zA-Z_:][a-zA-Z0-9_:]*)(?:\{((?:[^"}]|"(?:[^"\\]|\\.)*")*)\})?'
    r'\s+([^\s]+)(?:\s+[-+0-9.eE]+)?(?:\s+#.*)?$'
)
_LABEL = re.compile(r'\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*"((?:[^"\\]|\\.)*)"\s*(,|$)')
_ESCAPE = re.compile(r'\\(.)')


class _TelemetryError(ValueError):
    def __init__(self, reason, status="unavailable", http_status=None):
        super().__init__(reason)
        self.reason = reason
        self.status = status
        self.http_status = http_status


def _number(value, name, integer=False):
    if (isinstance(value, bool) or not isinstance(value, (int, float))
            or not math.isfinite(value) or value < 0 or (integer and value != int(value))):
        raise _TelemetryError(f"Missing or invalid {name}.")
    return int(value) if integer else value


def validate_config(config):
    """Return a detached normalized config, or raise a secret-free ValueError."""
    if not isinstance(config, dict) or set(config) - {"providers", "interval", "timeout", "staleAfter"}:
        raise ValueError("Throughput config must be an object with providers and optional interval/timeout/staleAfter.")
    providers = config.get("providers", {})
    if not isinstance(providers, dict) or set(providers) - set(PROVIDERS):
        raise ValueError("Throughput providers must be an object keyed by qwen/glm/openai/other.")
    result = {"providers": {}}
    for key, default, low, high in (("interval", 2.0, 0.25, 60.0),
                                   ("timeout", 2.0, 0.1, 10.0),
                                   ("staleAfter", 10.0, 1.0, 300.0)):
        value = config.get(key, default)
        if (isinstance(value, bool) or not isinstance(value, (int, float))
                or not math.isfinite(value) or not low <= value <= high):
            raise ValueError(f"Throughput {key} must be finite seconds in [{low}, {high}].")
        result[key] = float(value)
    if result["staleAfter"] <= result["interval"]:
        raise ValueError("Throughput staleAfter must exceed interval.")
    for provider, item in providers.items():
        if not isinstance(item, dict) or set(item) - {"url", "backend", "model"}:
            raise ValueError(f"Throughput {provider} requires url, optional backend/model, and no other fields.")
        url, backend, model = item.get("url"), item.get("backend", "auto"), item.get("model")
        try:
            if not isinstance(url, str) or any(ord(ch) <= 32 for ch in url):
                raise ValueError
            parsed = urlsplit(url)
            if (parsed.scheme not in ("http", "https") or not parsed.hostname
                    or parsed.username is not None or parsed.password is not None
                    or parsed.fragment or parsed.port == 0):
                raise ValueError
        except (ValueError, TypeError):
            raise ValueError(f"Throughput {provider} url must be absolute HTTP(S), without userinfo or fragment.") from None
        if not isinstance(backend, str) or backend not in BACKENDS:
            raise ValueError(f"Throughput {provider} backend must be auto/vllm/sglang/llama.cpp/tensorfold.")
        if model is not None and (not isinstance(model, str) or not model):
            raise ValueError(f"Throughput {provider} model must be a nonempty exact label.")
        normalized = {"url": url, "backend": backend}
        if model is not None:
            normalized["model"] = model
        result["providers"][provider] = normalized
    return result


def load_config(path):
    """Load JSON; missing files disable telemetry, malformed files fail startup."""
    try:
        with Path(path).open(encoding="utf-8") as stream:
            config = json.load(stream)
    except FileNotFoundError:
        config = {}
    except (json.JSONDecodeError, UnicodeError):
        raise ValueError("Throughput configuration is not valid UTF-8 JSON.") from None
    return validate_config(config)


def _unescape_label(value):
    def replace(match):
        escaped = match.group(1)
        if escaped not in ('\\', '"', 'n'):
            raise _TelemetryError("Invalid Prometheus label escape.")
        return '\n' if escaped == 'n' else escaped
    return _ESCAPE.sub(replace, value)


def _parse_metrics(text):
    """Parse Prometheus/OpenMetrics samples, including escaped labels/exponents."""
    metrics = {}
    for line in text.splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        match = _SAMPLE.fullmatch(line)
        if match is None:
            raise _TelemetryError("Malformed Prometheus sample.")
        name, label_text, raw_value = match.groups()
        labels, offset = {}, 0
        while label_text and offset < len(label_text):
            label = _LABEL.match(label_text, offset)
            if label is None or label.group(1) in labels:
                raise _TelemetryError("Malformed or duplicate Prometheus label.")
            labels[label.group(1)] = _unescape_label(label.group(2))
            offset = label.end()
        try:
            value = float(raw_value)
        except ValueError:
            raise _TelemetryError("Invalid Prometheus numeric sample.") from None
        metrics.setdefault(name, []).append((labels, value))
    return metrics


def _series(metrics, name, backend, model=None, match_labels=None, optional=False):
    """One scheduler per DP replica, never sum TP/PP mirrors or priority totals."""
    groups = {}
    for labels, value in metrics.get(name, []):
        if model is not None and labels.get("model_name") != model:
            continue
        if match_labels and any(labels.get(k) != v for k, v in match_labels.items()):
            continue
        if backend == "sglang" and labels.get("priority", "") != "":
            continue
        clean = dict(labels)
        for key in match_labels or {}:
            clean.pop(key, None)
        if backend == "sglang":
            clean.pop("priority", None)
            ranks = []
            for key in ("pp_rank", "tp_rank", "moe_ep_rank"):
                rank = clean.pop(key, "0")
                if not rank.isdigit():
                    raise _TelemetryError("Invalid SGLang scheduler rank label.")
                ranks.append(int(rank))
            identity = tuple(sorted(clean.items()))
            rank = tuple(ranks)
        else:
            identity, rank = tuple(sorted(clean.items())), ()
        value = _number(value, name, integer=True)
        previous = groups.get(identity)
        if previous is None or rank < previous[0]:
            groups[identity] = (rank, value)
        elif rank == previous[0]:
            raise _TelemetryError(f"Duplicate or ambiguous {name} series.")
    if not groups:
        if optional:
            return None
        raise _TelemetryError(f"Missing {name} or exact model label.")
    if backend == "vllm":
        # Aggregate and per-engine exports must not be added together.
        dimensions = {tuple(k for k, _ in key) for key in groups}
        if len(dimensions) != 1:
            raise _TelemetryError("Mixed aggregate/per-engine vLLM series are ambiguous.")
        allowed = {"model_name", "engine"}
        if len(groups) > 1 and any(set(dict(key)) - allowed for key in groups):
            raise _TelemetryError("Unrecognized vLLM series dimensions; refusing to double-count replicas.")
    if backend == "sglang" and len(groups) > 1:
        allowed = {"model_name", "engine_type", "dp_rank"}
        if any(set(dict(key)) - allowed for key in groups):
            raise _TelemetryError("Unrecognized SGLang series dimensions; refusing to double-count replicas.")
        dimensions = {tuple(k for k, _ in key) for key in groups}
        if len(dimensions) != 1:
            raise _TelemetryError("Mixed aggregate/per-replica SGLang series are ambiguous.")
    if backend in ("tensorfold", "llama.cpp") and len(groups) != 1:
        raise _TelemetryError("Multiple global counter/gauge series are ambiguous; refusing to double-count ranks.")
    # Preserve the chosen physical scheduler in the baseline identity so rank
    # replacement cannot masquerade as an increase in the old counter.
    return {(key, item[0]): item[1] for key, item in groups.items()}


@dataclass
class _Observation:
    counters: dict
    active: int | None
    source: str
    reason: str
    at: float
    sampled_at: str
    reset_markers: dict


def _observation(counters, active, source, reason, at=None, reset_markers=None):
    if active is not None:
        active = _number(active, "active requests", integer=True)
    return _Observation(counters, active, source, reason,
                        time.monotonic() if at is None else at,
                        datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z"),
                        reset_markers or {})


def _prometheus_observation(metrics, backend, model):
    if backend == "tensorfold":
        counters = _series(metrics, "tensorfold_health:completion_tokens_total", backend, model)
        gauge = _series(metrics, "tensorfold_health:streams", backend, model,
                        {"state": "decoding"}, optional=True)
        if gauge is not None and gauge.keys() != counters.keys():
            raise _TelemetryError("TensorFold counter and decoding gauge scopes differ.")
        active = None if gauge is None else sum(gauge.values())
        return _observation(counters, active,
                            "TensorFold live health metrics: completion_tokens_total / streams decoding",
                            "Backend-wide generated tokens; decoding streams exclude prefill and paused work.")
    if backend == "vllm":
        counter, running = "vllm:generation_tokens_total", "vllm:num_requests_running"
        source = "vLLM generation_tokens_total / num_requests_running"
        reason = "Backend-wide generated tokens; active requests include prefill (not decoding-only)."
        selector = None
    else:
        counter, running = "sglang:realtime_tokens_total", "sglang:num_running_reqs"
        source = 'SGLang realtime_tokens_total mode=decode / num_running_reqs'
        reason = "Backend-wide decode-phase output tokens (not prefill-produced first tokens); active requests include prefill."
        selector = {"mode": "decode"}
    counters = _series(metrics, counter, backend, model, selector)
    gauge = _series(metrics, running, backend, model, optional=True)
    if gauge is not None and gauge.keys() != counters.keys():
        raise _TelemetryError("Output counter and active-request gauge scopes differ.")
    return _observation(counters, None if gauge is None else sum(gauge.values()), source, reason)


def _tensorfold_health(payload, model):
    if not isinstance(payload, dict) or payload.get("backend") != "tensorfold" or payload.get("ok") is not True:
        raise _TelemetryError("Endpoint is not healthy TensorFold live telemetry.")
    if model is not None:
        raise _TelemetryError("TensorFold health has no model_name label; exact model filtering is unavailable.")
    total = _number(payload.get("completion_tokens_total"), "completion_tokens_total", integer=True)
    streams = payload.get("streams")
    active = streams.get("decoding") if isinstance(streams, dict) else None
    if isinstance(streams, dict) and "decoding" in streams:
        active = _number(active, "streams.decoding", integer=True)
    return _observation({(): total}, active, "TensorFold /health completion_tokens_total / streams.decoding",
                        "Backend-wide generated tokens including running replies; decoding excludes prefill and paused work.")


def _sibling_url(url, route):
    parsed = urlsplit(url)
    prefix = parsed.path.rstrip("/").rsplit("/", 1)[0]
    return urlunsplit((parsed.scheme, parsed.netloc, prefix + "/" + route, parsed.query, ""))


def _fetch(url, timeout):
    """One bounded, size-limited GET; no redirects, proxies or auth discovery."""
    parsed = urlsplit(url)
    connection_type = http.client.HTTPSConnection if parsed.scheme == "https" else http.client.HTTPConnection
    connection = connection_type(parsed.hostname, parsed.port, timeout=timeout)
    deadline = time.monotonic() + timeout
    try:
        connection.request("GET", urlunsplit(("", "", parsed.path or "/", parsed.query, "")),
                           headers={"Accept": "application/json, text/plain", "Accept-Encoding": "identity"})
        if connection.sock is not None:
            connection.sock.settimeout(max(0.001, deadline - time.monotonic()))
        response = connection.getresponse()
        if response.status != 200:
            raise _TelemetryError(f"Telemetry HTTP {response.status}; check endpoint and metrics enablement.",
                                  http_status=response.status)
        body = bytearray()
        while True:
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                raise TimeoutError
            if connection.sock is not None:
                connection.sock.settimeout(remaining)
            chunk = response.read1(min(65536, MAX_RESPONSE_BYTES + 1 - len(body)))
            if not chunk:
                break
            body.extend(chunk)
            if len(body) > MAX_RESPONSE_BYTES:
                raise _TelemetryError("Telemetry response exceeds the size limit.")
        return bytes(body).decode("utf-8"), response.getheader("Process-Start-Time-Unix")
    finally:
        connection.close()


def _llama_observation(url, metrics, process_start, model, timeout):
    name = "llamacpp:tokens_predicted_total"
    before = _series(metrics, name, "llama.cpp", model)
    if len(before) != 1:
        raise _TelemetryError("llama.cpp slot telemetry requires a single backend/model counter.")
    slot_text, _ = _fetch(_sibling_url(url, "slots"), timeout)
    at = time.monotonic()
    slots = json.loads(slot_text)
    if not isinstance(slots, list):
        raise _TelemetryError("llama.cpp /slots is unavailable; enable slots monitoring.")
    live_tokens, active, seen = 0, 0, set()
    for slot in slots:
        if not isinstance(slot, dict) or not isinstance(slot.get("is_processing"), bool):
            raise _TelemetryError("Invalid llama.cpp slot state.")
        slot_id = _number(slot.get("id"), "slot id", integer=True)
        if slot_id in seen:
            raise _TelemetryError("Duplicate llama.cpp slots would double-count output.")
        seen.add(slot_id)
        if not slot["is_processing"]:
            continue
        # The current source resets stats on release. Legacy formats do not;
        # their prior-request n_decoded can persist through the next prefill.
        if "n_prompt_tokens_processed" not in slot:
            raise _TelemetryError("Legacy llama.cpp slots lack reset-safe prompt progress; update the backend for live metrics.")
        next_token = slot.get("next_token")
        if isinstance(next_token, list) and len(next_token) == 1:
            next_token = next_token[0]
        if not isinstance(next_token, dict):
            raise _TelemetryError("Missing llama.cpp next_token slot counters.")
        decoded = _number(next_token.get("n_decoded"), "slot n_decoded", integer=True)
        live_tokens += decoded
        active += decoded > 0
    after_text, after_start = _fetch(url, timeout)
    after = _series(_parse_metrics(after_text), name, "llama.cpp", model)
    if before != after or process_start != after_start:
        raise _TelemetryError("llama.cpp completion/reset occurred during the slot scrape; awaiting a coherent sample.", "warming")
    finished = next(iter(before.values()))
    return _observation({(): finished + live_tokens}, active,
                        "llama.cpp bracketed tokens_predicted_total + /slots next_token.n_decoded",
                        "Backend-wide finished plus live output tokens; decoding slots exclude prefill; coherent metrics/slots bracket.",
                        at, {"finished": finished, "process": process_start})


def _sample_provider(item, timeout):
    url, backend, model = item["url"], item["backend"], item.get("model")
    try:
        text, process_start = _fetch(url, timeout)
    except _TelemetryError as exc:
        if (backend in ("auto", "tensorfold") and urlsplit(url).path.rstrip("/").endswith("/metrics")
                and exc.http_status == 404):
            health_text, _ = _fetch(_sibling_url(url, "health"), timeout)
            return _tensorfold_health(json.loads(health_text), model)
        raise
    if text.lstrip().startswith("{"):
        if backend not in ("auto", "tensorfold"):
            raise _TelemetryError("Expected Prometheus metrics, received JSON.")
        return _tensorfold_health(json.loads(text), model)
    metrics = _parse_metrics(text)
    if backend == "auto":
        detected = set()
        for name in metrics:
            for prefix, kind in (("vllm:", "vllm"), ("sglang:", "sglang"),
                                 ("llamacpp:", "llama.cpp"), ("tensorfold:", "tensorfold"),
                                 ("tensorfold_health:", "tensorfold")):
                if name.startswith(prefix):
                    detected.add(kind)
        if len(detected) != 1:
            raise _TelemetryError("Metrics backend is unknown or ambiguous; configure an explicit backend.")
        backend = detected.pop()
    if backend == "tensorfold" and "tensorfold_health:completion_tokens_total" not in metrics:
        health_text, _ = _fetch(_sibling_url(url, "health"), timeout)
        return _tensorfold_health(json.loads(health_text), model)
    if backend == "llama.cpp":
        return _llama_observation(url, metrics, process_start, model, timeout)
    return _prometheus_observation(metrics, backend, model)


def _empty_metric(status, reason, source="not configured", sampled_at=None):
    return {"totalTokensPerSecond": None, "averageTokensPerSecond": None,
            "activeStreams": None, "status": status, "source": source,
            "scope": "backend", "reason": reason, "sampledAt": sampled_at}


class ThroughputTracker:
    """Thread-safe cached snapshot; run(stop) is the sole polling entry point."""

    def __init__(self, config):
        self.config = validate_config(config)
        self._created_at = time.monotonic()
        self._lock = threading.Lock()
        self._running = False
        self._previous = {}
        self._seen = {}
        self._metrics = {}
        for provider in PROVIDERS:
            configured = provider in self.config["providers"]
            self._metrics[provider] = _empty_metric(
                "warming" if configured else "unavailable",
                "Awaiting the first backend sample." if configured else "No backend telemetry endpoint configured.",
                "configured backend telemetry" if configured else "not configured")

    def _publish(self, provider, sample):
        with self._lock:
            previous = self._previous.get(provider)
            self._previous[provider] = sample
            self._seen[provider] = sample.at
            metric = _empty_metric("warming", "First output-counter baseline; awaiting the next sample.",
                                   sample.source, sample.sampled_at)
            metric["activeStreams"] = sample.active
            if previous is not None:
                elapsed = sample.at - previous.at
                changed = (sample.source != previous.source or sample.counters.keys() != previous.counters.keys()
                           or sample.reset_markers.keys() != previous.reset_markers.keys())
                reset = any(sample.counters[k] < previous.counters[k] for k in sample.counters.keys() & previous.counters.keys())
                for key, value in sample.reset_markers.items():
                    old = previous.reset_markers.get(key)
                    reset |= (value != old if key == "process" else old is not None and value < old)
                if changed:
                    metric["reason"] = "Backend or output-counter series changed; establishing a new baseline."
                elif reset:
                    metric["reason"] = "Output counter/process reset; establishing a new baseline."
                elif elapsed <= 0 or elapsed > self.config["staleAfter"]:
                    metric["reason"] = "Sampling window expired or is invalid; establishing a new baseline."
                else:
                    delta = sum(sample.counters[k] - previous.counters[k] for k in sample.counters)
                    total = delta / elapsed
                    if not math.isfinite(total):
                        metric["reason"] = "Non-finite output-token rate; establishing a new baseline."
                    else:
                        metric.update(totalTokensPerSecond=total, status="ok", reason=sample.reason)
                        if sample.active is None or previous.active is None:
                            metric["reason"] += " Average unavailable: missing active-request gauge for this window."
                        else:
                            denominator = (sample.active + previous.active) / 2.0
                            metric["activeStreams"] = denominator
                            if denominator > 0:
                                metric["averageTokensPerSecond"] = total / denominator
                                metric["reason"] += " Average uses sampled mean active concurrency over the same window."
                            elif delta == 0:
                                metric["averageTokensPerSecond"] = 0.0
                                metric["reason"] += " Measured idle window (zero output and active requests)."
                            else:
                                metric["reason"] += " Average unavailable: output advanced but no active requests were captured at either endpoint."
            if metric["status"] == "warming":
                metric["reason"] += " " + sample.reason
            self._metrics[provider] = metric

    def _failure(self, provider, reason, status="unavailable"):
        with self._lock:
            self._previous.pop(provider, None)
            old = self._metrics[provider]
            if provider in self._seen and status != "warming":
                status = "stale"
            self._metrics[provider] = _empty_metric(status, reason, old["source"], old["sampledAt"])

    def _poll_provider(self, provider, item, stop):
        while not stop.is_set():
            started = time.monotonic()
            try:
                self._publish(provider, _sample_provider(item, self.config["timeout"]))
            except _TelemetryError as exc:
                self._failure(provider, exc.reason, exc.status)
            except (OSError, http.client.HTTPException):
                self._failure(provider, "Backend telemetry connection failed or exceeded its timeout.")
            except (ValueError, UnicodeError, RecursionError, OverflowError):
                self._failure(provider, "Backend telemetry response is malformed or contains invalid values.")
            stop.wait(max(0.0, self.config["interval"] - (time.monotonic() - started)))

    def run(self, stop):
        """Block until a threading.Event is set; at most four daemon pollers."""
        with self._lock:
            if self._running:
                raise RuntimeError("ThroughputTracker.run is already running.")
            self._running = True
        threads = []
        try:
            for provider, item in self.config["providers"].items():
                worker = threading.Thread(target=self._poll_provider, args=(provider, item, stop),
                                          name=f"throughput-{provider}", daemon=True)
                worker.start()
                threads.append(worker)
            stop.wait()
        finally:
            # Do not hold shutdown hostage to OS DNS. No worker performs writes.
            deadline = time.monotonic() + 3 * self.config["timeout"] + 0.5
            for worker in threads:
                worker.join(max(0.0, deadline - time.monotonic()))
            with self._lock:
                self._running = any(worker.is_alive() for worker in threads)

    def snapshot(self):
        """Return a detached contract dict, expiring cached numbers without I/O."""
        now = time.monotonic()
        with self._lock:
            providers = {provider: dict(metric) for provider, metric in self._metrics.items()}
            for provider, metric in providers.items():
                last = self._seen.get(provider)
                if last is not None and now - last > self.config["staleAfter"]:
                    providers[provider] = _empty_metric("stale", "Backend telemetry sample expired.",
                                                       metric["source"], metric["sampledAt"])
                elif (last is None and metric["status"] == "warming"
                      and now - self._created_at > self.config["staleAfter"]):
                    providers[provider] = _empty_metric("unavailable", "No successful backend telemetry sample received.",
                                                       metric["source"])
        return {"providers": providers}
