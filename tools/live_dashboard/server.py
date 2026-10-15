#!/usr/bin/env python3
"""Read-only live dashboard server for the brawl-decomp project.

Serves the static dashboard (index.html / style.css / app.js, allowlisted)
plus a small JSON + SSE API. Data comes from live project artifacts and
the narrowly scoped in-process omp observer:

* omp session journals supply identity/status and opt-in recorded history.
* The owning runner's registry supplies optional per-UUID assignment membership;
  outages retain the last known snapshot, never imply retirement.
* Its loopback observer supplies session-visible messages, reasoning and actual
  tool arguments/results, including supported content blocks and UI details.
  Journal polling is never substituted for live events. Observer module changes
  require explicit runner extension loading; settings toggles do not reload code.
  The runtime's current main session owns the observer; --session-id may pin a
  resumed/forked main journal. Live snapshots and root switches are checked
  against that pin before any frame is relayed.
* ``CHANGELOG.md`` verified checkpoints for headline progress, with the
  existing report/counter retained as a separately labelled unit-map source.
* Provider throughput comes from configured read-only backend telemetry, sampled
  independently of dashboard clients. Rates are backend-wide, including other
  clients; averages use sampled active concurrency, not visible terminal counts.
  ``throughput.json`` selects endpoints and auto-detects vLLM, SGLang, llama.cpp,
  or TensorFold. See throughput.py for backend/version requirements and counting
  semantics. Missing telemetry is unavailable, never inferred from text length.

The server binds the loopback interface only, performs no filesystem
browsing, never mutates reconstruction files, and persists nothing outside
``build/live-dashboard/`` (gitignored). Private HTTPS reverse-proxy access
requires an explicit ``--proxy-origin``; this does not authenticate requests,
so use it only behind a private proxy such as Tailscale Serve, never Funnel.

Usage:
    python tools/live_dashboard/server.py [--port 8765] [--session-dir DIR]
        [--session-id ROOT_UUID] [--root DIR] [--report PATH] [--interval SECONDS] [--verbose]
        [--proxy-origin https://HOST.tailnet.ts.net]
        [--throughput-config PATH]

Private Tailscale access (the observer remains local):
    python tools/live_dashboard/server.py --proxy-origin https://HOST.tailnet.ts.net
    tailscale serve --bg --https=443 http://127.0.0.1:8765

API:
    GET /api/state   full dashboard state snapshot (JSON)
    GET /api/units   per-unit classification map (JSON, revision-tagged)
    GET /api/events  Server-Sent Events: ``state`` snapshots (~2 s cadence)
                     with comment keepalives; clients reconnect and refetch
    GET /api/streams opt-in, labeled recorded message/reasoning/tool/peer history
    GET /api/live   immediate SSE relay; ?root=UUID selects a registered independent root
    GET /api/live-status observer connectivity (503 when not loaded), same optional root
    GET /api/throughput cached provider output-token rates and measurement status
"""

from __future__ import annotations

import argparse
import json
import sys
import threading
import time
from datetime import datetime, timezone
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlsplit
from urllib.error import URLError
from urllib.request import urlopen

sys.path.insert(0, str(Path(__file__).resolve().parent))

from journals import JournalWatcher  # noqa: E402
from progress import ProgressTracker  # noqa: E402
from throughput import ThroughputTracker, load_config  # noqa: E402

STATIC_FILES = {
    "/": ("index.html", "text/html; charset=utf-8"),
    "/index.html": ("index.html", "text/html; charset=utf-8"),
    "/app.js": ("app.js", "text/javascript; charset=utf-8"),
    "/stream-format.js": ("stream-format.js", "text/javascript; charset=utf-8"),
    "/stream-content.js": ("stream-content.js", "text/javascript; charset=utf-8"),
    "/stream-content.css": ("stream-content.css", "text/css; charset=utf-8"),
    "/style.css": ("style.css", "text/css; charset=utf-8"),
}
SSE_KEEPALIVE_SECONDS = 15.0
MAX_WARNINGS = 12
OBSERVER_URL = "http://127.0.0.1:8766"

# build/live-dashboard/independent-roots.json opts in exact same-project journals:
# {"sessions":[{"id":"<UUID>","label":"Independent Sol","observerPort":18766}]}
# observerPort is a unique integer 1..65535, excluding dashboard/default observer
# ports 8765/8766; omitted ports retain explicitly recorded-history behavior.
# Custom --independent-roots paths support recorded-only entries; observerPort
# entries are rejected there because the extension reads only the project path.
# Independent APIs accept only validated UUID registrations, never upstream URLs.
# The owning runner must actually load/rebind the updated observer extension;
# settings toggles do not reload code (Windows Bun may cache same-path imports).


def _utc_now_iso():
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")


class ObserverRouteError(ValueError):
    """A requested feed is not an opted-in, validated independent root."""


def _observer_route(watcher, root=None):
    if root is None:
        return {"url": OBSERVER_URL, "rootSessionId": watcher.session_label()}
    try:
        registration = watcher.independent_observer(root)
    except ValueError as exc:
        raise ObserverRouteError(str(exc)) from exc
    return {**registration, "url": f"http://127.0.0.1:{registration['observerPort']}"}


def _validate_observer_root(payload, watcher, root=None, route=None):
    if not isinstance(payload, dict):
        raise ValueError("Observer payload must be an object.")
    current = _observer_route(watcher, root)
    if route is not None and current != route:
        raise ValueError("Observer registration changed during this connection.")
    expected = current["rootSessionId"]
    actual = payload.get("rootSessionId")
    if not expected or not isinstance(actual, str) or actual.casefold() != expected.casefold():
        raise ValueError(
            f"Observer root session {actual or '(unknown)'} "
            f"does not match dashboard root session {expected or '(not found)'}. "
            "Select the intended owning root session and load its observer extension."
        )


def _annotate_observer(payload, route):
    if route.get("scope") != "independent-root":
        return payload
    if not isinstance(payload, dict):
        raise ValueError("Observer agent/snapshot payload must be an object.")
    identity = {key: route[key] for key in ("scope", "rootSessionId", "streamSource")}
    def annotate(agent):
        if isinstance(agent, dict) and isinstance(agent.get("id"), str) \
                and agent["id"].casefold() == route["rootSessionId"].casefold():
            return {**agent, **identity, "name": route["label"]}
        return agent
    payload = {**payload}
    if isinstance(payload.get("agents"), list):
        payload["agents"] = [annotate(agent) for agent in payload["agents"]]
    if isinstance(payload.get("id"), str) \
            and payload["id"].casefold() == route["rootSessionId"].casefold():
        payload = annotate(payload)
    return payload


def observer_status(watcher, root=None, route=None):
    route = route or _observer_route(watcher, root)
    with urlopen(route["url"] + "/status", timeout=2) as response:
        status = json.load(response)
    _validate_observer_root(status, watcher, root, route)
    return _annotate_observer(status, route)


def _observer_frame(upstream, watcher, root=None, route=None):
    """Read one intact SSE frame, rejecting root/registration changes first."""
    route = route or _observer_route(watcher, root)
    lines, data, event = [], [], None
    while True:
        line = upstream.readline()
        if not line:
            raise ValueError("Observer stream ended before a complete frame.")
        lines.append(line)
        field = line.rstrip(b"\r\n")
        if field.startswith(b"event:"):
            event = field[6:].strip()
        elif field.startswith(b"data:"):
            data.append(field[5:].lstrip(b" "))
        if field:
            continue
        if _observer_route(watcher, root) != route:
            raise ValueError("Observer registration changed during this connection.")
        if event in (b"snapshot", b"membership"):
            _validate_observer_root(json.loads(b"\n".join(data)), watcher, root, route)
        if root is not None and event in (b"snapshot", b"agent"):
            payload = _annotate_observer(json.loads(b"\n".join(data)), route)
            return event, b"event: " + event + b"\ndata: " + json.dumps(
                payload, separators=(",", ":")).encode("utf-8") + b"\n\n"
        return event, b"".join(lines)


def membership_loop(stop, watcher, interval):
    """Read owning registry metadata independently of output/state delivery."""
    while not stop.is_set():
        try:
            watcher.update_membership(observer_status(watcher))
        except (OSError, ValueError, URLError):
            pass  # Connection loss is not assignment retirement.
        stop.wait(interval)


class DashboardState:
    """Thread-safe cache of the latest serialized state + units payloads."""

    def __init__(self):
        self.lock = threading.Lock()
        self.sse = threading.Condition(self.lock)
        self.version = 0
        self.state_bytes = b"{}"
        self.units_bytes = b"{}"

    def publish(self, state_obj, units_bytes):
        payload = json.dumps(state_obj, separators=(",", ":")).encode("utf-8")
        with self.sse:
            self.state_bytes = payload
            if units_bytes is not None:
                self.units_bytes = units_bytes
            self.version += 1
            self.sse.notify_all()

    def snapshot(self):
        with self.lock:
            return self.version, self.state_bytes, self.units_bytes


def refresher_loop(stop, watcher, progress, state, interval, wake_progress):
    while not stop.is_set():
        started = time.monotonic()
        try:
            watcher.poll()
        except Exception as exc:  # noqa: BLE001 - never let the loop die
            watcher.warnings["watcher"] = f"journal scan failed: {exc.__class__.__name__}: {exc}"
        try:
            if progress.poll():
                wake_progress.set()
        except Exception:  # noqa: BLE001
            pass
        agents, events, journal_warnings = watcher.snapshot()
        progress_dict, report_updated_at, revision, history, progress_warnings = (
            progress.state_parts()
        )
        streams = watcher.stream_metadata()
        state_obj = {
            "version": 1,
            "updatedAt": _utc_now_iso(),
            "reportUpdatedAt": report_updated_at,
            "session": watcher.session_label(),
            "progress": progress_dict,
            "agents": agents,
            "history": history,
            "unitsRevision": revision or "pending",
            "unitsProvenance": progress.units_provenance(),
            "streamRevision": streams.pop("revision"),
            "streams": streams,
            "warnings": (journal_warnings + progress_warnings)[:MAX_WARNINGS],
        }
        state.publish(state_obj, progress.units_bytes())
        stop.wait(max(0.0, interval - (time.monotonic() - started)))


def progress_loop(stop, progress, wake):
    while not stop.is_set():
        wake.wait(timeout=1.0)
        if stop.is_set():
            break
        wake.clear()
        progress.refresh()  # keeps last-good data on failure


class DashboardHandler(BaseHTTPRequestHandler):
    server_version = "BrawlLiveDashboard/1.0"
    protocol_version = "HTTP/1.1"
    # Injected before serving: {"state", "static_dir", "stop", "verbose"}
    dashboard = None

    def log_message(self, fmt, *args):  # noqa: A003
        if self.dashboard and self.dashboard.get("verbose"):
            super().log_message(fmt, *args)

    # -- helpers -------------------------------------------------------
    def _send_json(self, code, payload, extra_headers=None):
        self.send_response(code)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("Cache-Control", "no-store")
        for key, value in (extra_headers or {}).items():
            self.send_header(key, value)
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(payload)

    def _send_static(self, path):
        name, ctype = STATIC_FILES[path]
        file_path = self.dashboard["static_dir"] / name
        try:
            payload = file_path.read_bytes()
        except OSError:
            self._send_json(404, b'{"error":"not found"}')
            return
        self.send_response(200)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(payload)

    # -- guards --------------------------------------------------------
    def _host_allowed(self):
        """Reject hosts other than loopback or the explicitly trusted proxy.

        Exact allowlisting blocks DNS-rebinding hosts. Private proxy access
        is opt-in; the HTTP server itself still listens only on loopback.
        """
        port = self.server.server_address[1]
        host = (self.headers.get("Host") or "").strip().lower()
        return host in (
            f"127.0.0.1:{port}", "127.0.0.1",
            f"localhost:{port}", "localhost",
            self.dashboard.get("proxy_host"),
        )

    def _origin_allowed(self):
        """Allow API reads only from the dashboard's own origin (when sent)."""
        origin = self.headers.get("Origin")
        if origin is None:
            return True  # direct navigation / non-browser clients
        port = self.server.server_address[1]
        return origin.strip().lower() in (
            f"http://127.0.0.1:{port}", f"http://localhost:{port}",
            self.dashboard.get("proxy_origin"),
        )

    # -- routes --------------------------------------------------------
    def do_GET(self):
        if not self._host_allowed():
            self._send_json(403, b'{"error":"forbidden host"}')
            return
        path = self.path.split("?", 1)[0].split("#", 1)[0]
        if path.startswith("/api/") and not self._origin_allowed():
            self._send_json(403, b'{"error":"forbidden origin"}')
            return
        if path == "/api/state":
            _, payload, _ = self.dashboard["state"].snapshot()
            self._send_json(200, payload)
        elif path == "/api/units":
            _, _, payload = self.dashboard["state"].snapshot()
            self._send_json(200, payload)
        elif path == "/api/throughput":
            payload = self.dashboard["throughput"].snapshot()
            self._send_json(200, json.dumps(payload, separators=(",", ":")).encode("utf-8"))
        elif path == "/api/live-status":
            try:
                observer = self._observer_status()
                self._send_json(200, json.dumps(observer).encode("utf-8"))
            except ObserverRouteError as exc:
                self._send_json(400, json.dumps({"connected": False, "error": str(exc)}).encode("utf-8"))
            except (OSError, ValueError, URLError) as exc:
                self._send_json(503, json.dumps({
                    "connected": False,
                    "error": str(exc),
                    "prerequisite": "Use --session-id to select the owning root session; its omp runner must load .omp/extensions/live-output.js.",
                }).encode("utf-8"))
        elif path == "/api/live":
            self._handle_live()
        elif path == "/api/streams":
            query = parse_qs(urlsplit(self.path).query)
            try:
                limit = int(query.get("limit", ["300"])[0])
                if not 1 <= limit <= 1000:
                    raise ValueError
            except (ValueError, TypeError):
                self._send_json(400, b'{"error":"limit must be an integer from 1 to 1000"}')
                return
            payload = self.dashboard["watcher"].streams(
                agent=query.get("agent", [None])[0],
                cursor=query.get("cursor", [None])[0], limit=limit,
            )
            self._send_json(200, json.dumps(payload, separators=(",", ":")).encode("utf-8"))
        elif path == "/api/events":
            self._handle_sse()
        elif path in STATIC_FILES:
            self._send_static(path)
        else:
            # Exact allowlist only: no directory browsing, no path traversal.
            self._send_json(404, b'{"error":"not found"}')

    def do_HEAD(self):
        path = self.path.split("?", 1)[0].split("#", 1)[0]
        if path in ("/api/events", "/api/live"):
            self._send_json(405, b'{"error":"method not allowed"}', {"Allow": "GET"})
        else:
            self.do_GET()

    def do_POST(self):
        self._send_json(405, b'{"error":"method not allowed"}', {"Allow": "GET, HEAD"})

    def _observer_root(self):
        query = parse_qs(urlsplit(self.path).query, keep_blank_values=True)
        if "root" not in query:
            return None
        if len(query["root"]) != 1 or not query["root"][0]:
            raise ObserverRouteError("root must identify one registered independent live observer")
        return query["root"][0]

    def _observer_status(self):
        return observer_status(self.dashboard["watcher"], self._observer_root())

    def _handle_live(self):
        """Relay actual observer frames immediately, without journal backfill."""
        try:
            root = self._observer_root()
            route = _observer_route(self.dashboard["watcher"], root)
            observer_status(self.dashboard["watcher"], root, route)
            upstream = urlopen(route["url"] + "/events", timeout=15)
            try:
                initial = []
                while True:
                    event, frame = _observer_frame(upstream, self.dashboard["watcher"], root, route)
                    initial.append(frame)
                    if event == b"snapshot":
                        break
                    if event is not None:
                        raise ValueError("Observer feed must start with a scoped snapshot.")
            except (OSError, ValueError):
                upstream.close()
                raise
        except ObserverRouteError as exc:
            self._send_json(400, json.dumps({"connected": False, "error": str(exc)}).encode("utf-8"))
            return
        except (OSError, ValueError, URLError) as exc:
            self._send_json(503, json.dumps({"connected": False, "error": str(exc)}).encode("utf-8"))
            return
        with upstream:
            self.send_response(200)
            self.send_header("Content-Type", "text/event-stream; charset=utf-8")
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            self.close_connection = True
            self.wfile.write(b"".join(initial))
            self.wfile.flush()
            try:
                while not self.dashboard["stop"].is_set():
                    # Heartbeats arrive inside the socket deadline. Rooted
                    # frames are checked before any of their bytes reach the
                    # browser, including switches after the status request.
                    _, frame = _observer_frame(upstream, self.dashboard["watcher"], root, route)
                    self.wfile.write(frame)
                    self.wfile.flush()
            except (OSError, ValueError):
                pass  # downstream close or upstream restart; EventSource reconnects
    # -- SSE -----------------------------------------------------------
    def _handle_sse(self):
        state = self.dashboard["state"]
        self.send_response(200)
        self.send_header("Content-Type", "text/event-stream; charset=utf-8")
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.close_connection = True
        try:
            self.wfile.write(b"retry: 3000\n\n")
            self.wfile.flush()
            version, payload, _ = state.snapshot()
            self._write_state(payload, version)
            last_version, last_keepalive = version, time.monotonic()
            while not self.dashboard["stop"].is_set():
                with state.sse:
                    state.sse.wait(timeout=2.0)
                version, payload, _ = state.snapshot()
                now = time.monotonic()
                if version != last_version:
                    self._write_state(payload, version)
                    last_version = version
                    last_keepalive = now
                elif now - last_keepalive >= SSE_KEEPALIVE_SECONDS:
                    self.wfile.write(b": keepalive\n\n")
                    self.wfile.flush()
                    last_keepalive = now
        except (BrokenPipeError, ConnectionResetError, OSError):
            pass  # client disconnected; end this handler thread cleanly

    def _write_state(self, payload, version):
        self.wfile.write(f"id: {version}\nevent: state\ndata: ".encode("ascii")
                         + payload + b"\n\n")
        self.wfile.flush()


def parse_args(argv=None):
    parser = argparse.ArgumentParser(
        description="Read-only live decompilation dashboard server (loopback with optional private HTTPS proxy).",
        epilog=(
            "Data sources: omp session journals (auto-discovered from the repo cwd,"
            " override with --session-dir), latest verified CHANGELOG.md checkpoint,"
            " and a separately labelled report-derived unit map. Persisted state"
            " lives only in build/live-dashboard/."
        ),
    )
    parser.add_argument("--port", type=int, default=8765,
                        help="TCP port to listen on (default: 8765)")
    parser.add_argument("--host", default="127.0.0.1",
                        help="bind address; loopback only (default: 127.0.0.1)")
    parser.add_argument("--proxy-origin", default=None, metavar="HTTPS_ORIGIN",
                        help="exact HTTPS origin of a trusted private reverse proxy;"
                             " localhost-only requests remain allowed")
    parser.add_argument("--session-dir", type=Path, default=None, metavar="DIR",
                        help="explicit omp session directory (default: auto-discover"
                             " the session matching the repo cwd under"
                             " ~/.omp/agent/sessions)")
    parser.add_argument("--session-id", default=None, metavar="ROOT_UUID",
                        help="pin to this root session UUID (including a forked main);"
                             " default selects the newest matching non-fork root once,"
                             " excluding registered independent roots, and retains it until restart")
    parser.add_argument("--independent-roots", type=Path, default=None, metavar="PATH",
                        help="opt-in UUID/label registrations for independent root journals;"
                             " custom paths support recorded-only entries (no observerPort);"
                             " live registrations require the default project path:"
                             " <root>/build/live-dashboard/independent-roots.json")
    parser.add_argument("--root", type=Path, default=None, metavar="DIR",
                        help="project root (default: the repository containing"
                             " tools/live_dashboard)")
    parser.add_argument("--report", type=Path, default=None, metavar="PATH",
                        help="objdiff report.json (default: <root>/build/RSBE01_02/report.json)")
    parser.add_argument("--interval", type=float, default=2.0,
                        help="state refresh cadence in seconds (default: 2.0)")
    parser.add_argument("--throughput-config", type=Path,
                        default=Path(__file__).with_name("throughput.json"), metavar="PATH",
                        help="provider telemetry endpoints (default: throughput.json beside server.py)")
    parser.add_argument("--verbose", action="store_true",
                        help="log HTTP requests to stderr")
    args = parser.parse_args(argv)
    if args.host not in ("127.0.0.1", "localhost"):
        parser.error("--host must be a loopback address; the dashboard never binds a public interface")
    if not 1 <= args.port <= 65535:
        parser.error("--port must be 1-65535")
    if args.interval < 0.5:
        parser.error("--interval must be at least 0.5 seconds")
    if args.proxy_origin is not None:
        try:
            proxy = urlsplit(args.proxy_origin)
            proxy_port = proxy.port
        except ValueError:
            parser.error("--proxy-origin must be a valid HTTPS origin")
        if (proxy.scheme != "https" or not proxy.hostname
                or proxy.username is not None or proxy.password is not None
                or proxy.path not in ("", "/") or proxy.query or proxy.fragment
                or proxy_port == 0):
            parser.error("--proxy-origin must be an HTTPS origin without credentials, path, query, or fragment")
        authority = proxy.hostname.lower()
        if ":" in authority:
            authority = f"[{authority}]"
        if proxy_port is not None and proxy_port != 443:
            authority += f":{proxy_port}"
        args.proxy_origin = f"https://{authority}"
    return args


def main(argv=None):
    args = parse_args(argv)
    root = (args.root or Path(__file__).resolve().parents[2]).resolve()
    report_path = args.report or (root / "build" / "RSBE01_02" / "report.json")
    history_path = root / "build" / "live-dashboard" / "history.json"
    static_dir = Path(__file__).resolve().parent

    watcher = JournalWatcher(root, session_dir=args.session_dir, session_id=args.session_id,
                             independent_roots=args.independent_roots)
    progress = ProgressTracker(report_path, root, history_path)
    throughput = ThroughputTracker(load_config(args.throughput_config))

    stop = threading.Event()
    wake_progress = threading.Event()
    dashboard = DashboardState()
    DashboardHandler.dashboard = {
        "state": dashboard,
        "watcher": watcher,
        "static_dir": static_dir,
        "throughput": throughput,
        "stop": stop,
        "verbose": args.verbose,
        "proxy_origin": args.proxy_origin,
        "proxy_host": urlsplit(args.proxy_origin).netloc if args.proxy_origin else None,
    }

    # Publish a valid initializing snapshot so the port serves immediately;
    # the refresher/progress threads replace it on their first ticks.
    progress_dict, report_updated_at, revision, history, progress_warnings = (
        progress.state_parts()
    )
    dashboard.publish({
        "version": 1,
        "updatedAt": _utc_now_iso(),
        "reportUpdatedAt": report_updated_at,
        "session": None,
        "progress": progress_dict,
        "agents": [],
        "history": history,
        "unitsRevision": revision or "pending",
        "unitsProvenance": progress.units_provenance(),
        "streamRevision": f"{watcher.stream_epoch}:0",
        "streams": {"available": False, "retentionPerAgent": 200},
        "warnings": ["dashboard starting: agent list and progress fill in on the first scan"],
    }, progress.units_bytes())

    server = ThreadingHTTPServer((args.host, args.port), DashboardHandler)
    server.daemon_threads = True

    threads = [
        threading.Thread(target=refresher_loop,
                         args=(stop, watcher, progress, dashboard, args.interval, wake_progress),
                         name="dashboard-refresher", daemon=True),
        threading.Thread(target=progress_loop, args=(stop, progress, wake_progress),
                         name="dashboard-progress", daemon=True),
        threading.Thread(target=membership_loop, args=(stop, watcher, args.interval),
                         name="dashboard-membership", daemon=True),
        threading.Thread(target=throughput.run, args=(stop,),
                         name="dashboard-throughput", daemon=True),
    ]
    for thread in threads:
        thread.start()

    print(f"live dashboard on http://{args.host}:{args.port} "
          f"(session: {watcher.session_label() or 'not found'})", file=sys.stderr)
    try:
        server.serve_forever(poll_interval=0.5)
    except KeyboardInterrupt:
        pass
    finally:
        stop.set()
        wake_progress.set()
        server.server_close()


if __name__ == "__main__":
    main()
