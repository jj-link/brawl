"""Read-only discovery, tailing, and interpretation of omp session journals.

Journals are read-only JSONL files under ``~/.omp/agent/sessions``. Recorded
user/assistant text and thinking, peer messages, tool arguments and result
content are delivered separately from state summaries. Session content is
preserved without path/tag filtering or per-item truncation; retention bounds
whole entries only. Provider payloads, auth headers and signatures are not sent.

States are derived strictly from recorded evidence:

* ``stopped``   -- a ``session_exit`` record or a trailing aborted/error turn.
* ``completed`` -- a terminal successful ``yield`` at the tail (possibly
  followed by a clean exit).
* ``waiting``   -- an unresolved ``wait`` tool call, or a ``yield`` whose
  structured data reports waiting/blocked/queued.
* ``working``   -- an unresolved tool call (or very recent activity) with a
  fresh ``lastSeen``.
* ``quiet``     -- the same evidence but stale: observed activity stopped and
  nothing proves the agent terminated (parked/dead cannot be distinguished
  from a journal alone).
* ``unknown``   -- no interpretable records yet.

Assignment membership is separate from these activity labels. The owning
runner's registry snapshot is authoritative when available; otherwise only an
accepted terminal yield or an explicit ``.jsonl.tombstone`` proves retirement.
Neither a normal model-turn end nor quiet/waiting age proves completion.

Run clocks are independent of membership/target steering timestamps. The first
session/assignment starts a run; steering during a live run does not restart it.
Accepted terminal yields, aborted/error assistant turns, exits and explicit
retirement evidence freeze it. A subsequent assignment or tool execution resumes
with a new clock. Waiting, quiet time, model changes and normal turn ends count
toward the same run. Missing timestamps stay unknown; lastSeen is never an end.
Registry retirement without an agent-specific timestamp leaves the end unknown.
Clock evidence is ingested on journal/registry updates, never snapshot reads.
"""

from __future__ import annotations

import json
import os
import threading
import uuid
from collections import deque
from datetime import datetime, timezone
from pathlib import Path

WORKING_WINDOW_SECONDS = 600.0
EVENTS_PER_JOURNAL = 300
MAX_EVENTS_GLOBAL = 500
MAX_INTENT_CHARS = 120
MAX_TARGET_CHARS = 160
HEADER_PEEK_BYTES = 65536
MAX_INITIAL_READ = 256 * 1024 * 1024
MAX_TRACKED_CALLS = 4096
STREAMS_PER_JOURNAL = 200
TAIL_ANCHOR_BYTES = 256


def load_independent_roots(path):
    """Load sessions[{id,label,observerPort?}] from independent-roots.json.

    A unique loopback port opts into /api/live?root=UUID only in the project's
    default configuration; custom config paths support recorded-only entries.
    Loading source edits also requires runner extension reload/rebinding, not
    a settings toggle. Neither path accepts upstream URLs.
    """
    config = json.loads(Path(path).read_text(encoding="utf-8"))
    entries = config.get("sessions") if isinstance(config, dict) else None
    if not isinstance(entries, list):
        raise ValueError("expected an object with a sessions array")
    requested, ports = {}, set()
    for entry in entries:
        if not isinstance(entry, dict) or not isinstance(entry.get("id"), str):
            raise ValueError("each session requires a UUID and label")
        sid = str(uuid.UUID(entry["id"]))
        label = entry.get("label")
        if not isinstance(label, str) or not label.strip() or label.strip().casefold() == "main":
            raise ValueError("each independent session requires a non-main label")
        if sid in requested:
            raise ValueError(f"duplicate independent session UUID {sid}")
        registration = {"id": sid, "label": label.strip()}
        if "observerPort" in entry:
            port = entry["observerPort"]
            if type(port) is not int or not 1 <= port <= 65535 or port in (8765, 8766):
                raise ValueError("observerPort must be a loopback port other than 8765/8766")
            if port in ports:
                raise ValueError(f"duplicate independent observer port {port}")
            ports.add(port)
            registration["observerPort"] = port
        requested[sid] = registration
    return requested


def _visible_text(value):
    """Preserve session text verbatim, without reading provider metadata."""
    return value if isinstance(value, str) else ""


def _content_blocks(content):
    """Select documented user-visible content fields, not provider signatures."""
    if isinstance(content, str):
        return [{"type": "text", "text": content}]
    blocks = []
    if not isinstance(content, list):
        return blocks
    for block in content:
        if not isinstance(block, dict):
            continue
        kind = block.get("type")
        fields = {
            "text": ("text",),
            "thinking": ("thinking", "summary"),
            "reasoning": ("text", "thinking", "reasoning", "summary"),
            "image": ("data", "mimeType"),
        }.get(kind)
        if fields is not None:
            blocks.append({"type": kind, **{
                key: block[key] for key in fields
                if key in block and (key != "summary" or isinstance(block[key], bool))
            }})
    return blocks


def _content_text(blocks):
    """Faithful textual projection; images remain available in ``blocks``."""
    return "\n".join(
        _visible_text(block.get("text") if block.get("type") == "text" else
                      block.get("thinking", block.get("reasoning", block.get("text"))))
        for block in blocks if block.get("type") != "image"
    )


def _clean(value, limit):
    """Collapse whitespace and clamp; returns None for non-strings/empty."""
    if not isinstance(value, str):
        return None
    text = " ".join(_visible_text(value).split())
    return text[:limit] or None


def _parse_ts(value):
    if not isinstance(value, str) or not value:
        return None
    try:
        parsed = datetime.fromisoformat(value.replace("Z", "+00:00"))
        return parsed if parsed.tzinfo else parsed.replace(tzinfo=timezone.utc)
    except ValueError:
        return None


def _norm(path):
    return os.path.normcase(os.path.abspath(str(path)))


def _session_id(value):
    """Canonicalize UUID identity while retaining legacy opaque journal IDs."""
    if not isinstance(value, str) or not value:
        return None
    try:
        return str(uuid.UUID(value))
    except ValueError:
        return value


def _session_ref(value):
    """Session parent references may be UUIDs or legacy journal paths."""
    if not isinstance(value, str) or not value:
        return None
    try:
        return str(uuid.UUID(value))
    except ValueError:
        return _norm(value)


def _yield_state(status):
    """Classify a recorded yield status string into a dashboard keyword.

    Recorded statuses may be short tokens or full sentences (e.g. "Queued
    for shared acceptance window; awaiting Main's explicit grant"), so the
    classification matches the recorded wording instead of exact equality.
    Returns None when nothing conclusive is recorded.
    """
    if not isinstance(status, str) or not status:
        return None
    lowered = status.lower()
    if "blocked" in lowered:
        return "blocked"
    if "queued" in lowered or "waiting" in lowered:
        return "waiting"
    if "error" in lowered or "failed" in lowered or "failure" in lowered:
        return "error"
    if "success" in lowered or "succeeded" in lowered or lowered.startswith("complete"):
        return "success"
    return None


def _extract_correction(data, depth=0):
    """Return the structured correction-attempt count in yield data, or None.

    Only explicit integer fields whose key mentions "correction" (possibly
    nested, e.g. preserved_counts.sol_correction_attempts) count; absent or
    conflicting values yield None rather than a guess.
    """
    if not isinstance(data, dict) or depth > 2:
        return None
    found = []
    for key, value in data.items():
        if isinstance(value, bool):
            continue
        if isinstance(value, int) and "correction" in str(key).lower():
            found.append(value)
        elif isinstance(value, dict):
            nested = _extract_correction(value, depth + 1)
            if nested is not None:
                found.append(nested)
    if len(set(found)) != 1:
        return None  # absent or ambiguous
    return found[0]


class JournalTracker:
    """Incrementally derived, journal-backed state for one agent."""

    def __init__(self, path, name, is_parent, stream_sink=None):
        self.path = Path(path)
        self.name = name
        self.is_parent = is_parent
        self.session_id = None
        self.agent_type = None
        self.model = None
        self.records = 0
        self.malformed = 0
        self.last_seen = None
        self.last_seen_dt = None
        self.last_intent = None
        self.pending = {}   # toolCallId -> {"tool": str}
        self.calls = {}     # toolCallId -> {"tool", "intent", "yield_terminal"}
        self.tail = None    # (kind, payload) describing the last applied record
        self.exit_info = None
        self.last_yield = None
        self.last_target = None
        self.last_target_seq = None
        self.correction = None
        self.assignment_retired = False
        self.assignment_started_at = None
        self.assignment_retired_at = None
        self.tombstoned = False
        self.tombstoned_at = None
        self.run_started_at = None
        self.run_ended_at = None
        # Separate evidence flags preserve unknown timestamps across steering.
        self._run_started = False
        self._run_ended = False
        self._seq = 0
        self._stream_seq = 0
        self.events = deque(maxlen=EVENTS_PER_JOURNAL)
        self.stream = deque()
        self.evicted_order = 0
        self._stream_sink = stream_sink

    def _start_run(self, at):
        if not self._run_started or self._run_ended:
            self.run_started_at = at
            self.run_ended_at = None
            self._run_started = True
            self._run_ended = False

    def _finish_run(self, at):
        if at is not None and self.run_started_at is not None \
                and at < self.run_started_at:
            return  # Stale retirement belongs to a previous run.
        self._run_ended = True
        if at is not None and (self.run_ended_at is None or at < self.run_ended_at):
            self.run_ended_at = at

    def _add_stream(self, record, kind, text, suffix="", **fields):
        text = _visible_text(text)
        if not text and kind != "tool" and not any(
                fields.get(key) is not None
                for key in ("blocks", "args", "details", "errorMessage", "stopReason")):
            return
        self._stream_seq += 1
        sid = self.session_id or self.path.stem
        rid = record.get("id") or str(self._seq)
        item = {
            "id": f"{sid}:{rid}:{kind}:{suffix}", "agentId": sid,
            "agent": self.name, "at": record.get("timestamp") or self.last_seen,
            "sequence": self._stream_seq, "kind": kind, "role": None,
            "tool": None, "callId": None, "intent": None, "isError": False,
            "text": text, "complete": True,
        }
        item.update(fields)
        if self._stream_sink:
            self._stream_sink(item)
        self.stream.append(item)
        while len(self.stream) > STREAMS_PER_JOURNAL:
            removed = self.stream.popleft()
            self.evicted_order = removed.get("_order", 0)

    # ------------------------------------------------------------------
    # record application
    # ------------------------------------------------------------------
    def apply(self, record):
        if not isinstance(record, dict):
            return
        self.records += 1
        self._seq += 1
        ts = record.get("timestamp")
        if isinstance(ts, str) and ts:
            self.last_seen = ts
            self.last_seen_dt = _parse_ts(ts)
        kind = record.get("type")
        if kind == "session":
            self.session_id = _session_id(record.get("id")) or self.session_id
            self.assignment_started_at = _parse_ts(ts)
            self._start_run(_parse_ts(ts))
            if "parentSession" not in record and not self.is_parent:
                self.is_parent = True
                self.name = "main"
        elif kind == "model_change":
            model = _clean(record.get("model"), 120)
            if model:
                self.model = model
        elif kind == "session_init":
            self._start_run(_parse_ts(ts))
            # A reused agent's new assignment supersedes any target reported
            # for the previous one: current scope differs or is unknown.
            self.last_target = None
            self.last_target_seq = None
            self.last_yield = None
            self.exit_info = None
            self.assignment_retired = False
            self.assignment_started_at = _parse_ts(ts)
            self.assignment_retired_at = None
            agent_type = _clean(record.get("agent"), 60)
            if agent_type:
                self.agent_type = agent_type
            model = _clean(record.get("resolvedModel"), 120)
            if model:
                self.model = model
            self.tail = ("spawn", {})
            if record.get("id"):
                text = f"agent spawned ({agent_type})" if agent_type else "session started"
                if model:
                    text += f" - {model}"
                self._add_event(record, "spawn", text)
        elif kind == "message":
            self._apply_message(record)
        elif kind == "custom":
            self._apply_custom(record)
        elif kind == "custom_message" and record.get("display") is True:
            if record.get("customType") == "irc:incoming":
                details = record.get("details") or {}
                if isinstance(details, dict):
                    sender = _clean(details.get("from"), 80) or "peer"
                    blocks = _content_blocks(details.get("message", record.get("content")))
                    self._add_stream(record, "message", _content_text(blocks),
                                     role="peer", sender=sender, blocks=blocks)
            elif record.get("customType") == "async-result":
                body = record.get("content")
                blocks = _content_blocks(body)
                self._add_stream(record, "tool", _content_text(blocks),
                                 role="tool", blocks=blocks,
                                 details=record.get("details"))
            else:
                blocks = _content_blocks(record.get("content"))
                self._add_stream(record, "message", _content_text(blocks),
                                 role="custom", blocks=blocks)
        # Other record kinds, including compaction summaries, credential pins
        # and raw provider metadata, are intentionally ignored.

    def _apply_message(self, record):
        message = record.get("message")
        if not isinstance(message, dict):
            return
        role = message.get("role")
        if role == "user":
            self._start_run(_parse_ts(record.get("timestamp")))
            # A steering assignment supersedes any previously reported target;
            # reused agents resume without emitting a new session_init.
            # Preserve only recorded content, not provider request metadata.
            self.last_target = None
            self.last_target_seq = None
            self.last_yield = None
            self.exit_info = None
            self.assignment_retired = False
            self.assignment_started_at = _parse_ts(record.get("timestamp"))
            self.assignment_retired_at = None
            self.tail = ("spawn", {})
            blocks = _content_blocks(message.get("content"))
            self._add_stream(record, "message", _content_text(blocks),
                             role="user", blocks=blocks)
            return
        if role == "assistant":
            model = message.get("model")
            if isinstance(model, str) and model:
                self.model = model
            self.tail = ("assistant", {"stop": message.get("stopReason")})
            self.last_yield = None
            outcome = {
                key: message[key] for key in ("stopReason", "errorMessage")
                if message.get(key) is not None
            }
            outcome["isError"] = message.get("stopReason") in ("error", "aborted")
            if outcome["isError"]:
                self._finish_run(_parse_ts(record.get("timestamp")))
            stream_before = self._stream_seq
            content = message.get("content")
            if isinstance(content, str):
                content = [{"type": "text", "text": content}]
            if not isinstance(content, list):
                content = []
            for index, block in enumerate(content):
                if not isinstance(block, dict):
                    continue
                if block.get("type") != "toolCall":
                    blocks = _content_blocks([block])
                    if blocks:
                        fields = {"role": "assistant", "blocks": blocks, **outcome}
                        if block.get("type") in ("thinking", "reasoning"):
                            fields["channel"] = "thinking"
                        self._add_stream(record, "message", _content_text(blocks),
                                         suffix=str(index), **fields)
                    continue
                cid = block.get("id")
                tool = _clean(block.get("name"), 60)
                arguments = block.get("arguments")
                args = arguments if isinstance(arguments, dict) else {}
                intent = block.get("intent") or args.get("i")
                intent = _clean(intent, MAX_INTENT_CHARS)
                self._add_stream(record, "tool", "", suffix=str(index),
                                 role="assistant", tool=tool, callId=cid, intent=intent,
                                 args=arguments, complete=False)
                if tool and intent:
                    self.last_intent = intent
                if cid and tool:
                    self.calls[cid] = {
                        "tool": tool,
                        "intent": intent,
                        # type: string (or absent) is a terminal yield;
                        # type: array is an incremental section yield.
                        "yield_terminal": tool == "yield"
                        and not isinstance(args.get("type"), list),
                        "yield_error": tool == "yield" and args.get("error") is not None,
                        "yield_state": _yield_state(args.get("data", {}).get("status"))
                        if tool == "yield" and isinstance(args.get("data"), dict) else None,
                    }
                    if len(self.calls) > MAX_TRACKED_CALLS:
                        self.calls.clear()
            if self._stream_seq == stream_before and (
                    outcome["isError"] or outcome.get("errorMessage")):
                self._add_stream(record, "message", "", suffix="outcome",
                                 role="assistant", **outcome)
        elif role == "toolResult":
            tool = _clean(message.get("toolName"), 60)
            cid = message.get("toolCallId")
            is_error = bool(message.get("isError"))
            details = message.get("details")
            details = details if isinstance(details, dict) else {}
            call = self.calls.get(cid) or {}
            blocks = _content_blocks(message.get("content"))
            self._add_stream(record, "tool", _content_text(blocks),
                             role="tool", tool=tool, callId=cid,
                             intent=call.get("intent"), isError=is_error,
                             blocks=blocks, details=message.get("details"),
                             status="error" if is_error else "completed")
            self.pending.pop(cid, None)
            if tool == "yield":
                data = details.get("data")
                data = data if isinstance(data, dict) else {}
                self.last_yield = {
                    "state": "error" if (
                        is_error or call.get("yield_error") or details.get("error") is not None
                        or _yield_state(details.get("status")) == "error"
                    ) else (
                        _yield_state(data.get("status")) or call.get("yield_state")
                        or _yield_state(details.get("status"))),
                    "terminal": bool(call.get("yield_terminal")),
                }
                # The runner accepts success/aborted terminal yields as the
                # assignment result, even when data.status says "waiting".
                # A rejected schema/tool error and an incremental section are
                # not terminal acceptance. Keep this evidence through the
                # trailing assistant/model-turn end.
                if not is_error and details.get("status") in ("success", "aborted") \
                        and (call.get("yield_terminal") or details.get("complete") is True):
                    self.assignment_retired = True
                    self.assignment_retired_at = _parse_ts(record.get("timestamp"))
                    self._finish_run(self.assignment_retired_at)
                target = (data.get("target") or data.get("source")
                          or data.get("source_path") or data.get("unit"))
                target = _clean(target, MAX_TARGET_CHARS)
                if target:
                    self.last_target = target
                    self.last_target_seq = self._seq
                correction = _extract_correction(data)
                if correction is not None:
                    self.correction = correction
            self.tail = ("toolResult", {"tool": tool})
            if tool == "yield":
                raw_status = _clean(details.get("status"), MAX_TARGET_CHARS)
                text = f"yield - {raw_status}" if raw_status else "yield"
            else:
                text = f"{tool or 'tool'} - error" if is_error else f"{tool or 'tool'} - ok"
                wall = details.get("wallTimeMs")
                if not is_error and tool != "yield" and isinstance(wall, (int, float)) \
                        and 0 <= wall < 3_600_000:
                    text += f" ({int(wall)} ms)"
            self._add_event(record, "result", text)
        # Other roles and provider metadata are not interpreted.

    def _apply_custom(self, record):
        ctype = record.get("customType")
        data = record.get("data")
        data = data if isinstance(data, dict) else {}
        if ctype == "tool_execution_start":
            tool = _clean(data.get("toolName"), 60)
            cid = data.get("toolCallId")
            call = self.calls.get(cid) or {}
            if self._run_ended:
                self._start_run(_parse_ts(record.get("timestamp")))
            if self.assignment_retired:
                self.assignment_retired = False
                self.assignment_retired_at = None
                self.assignment_started_at = _parse_ts(record.get("timestamp"))
            if cid:
                self.pending[cid] = {"tool": tool}
                if len(self.pending) > MAX_TRACKED_CALLS:
                    self.pending.clear()
            intent = _clean(data.get("intent") or call.get("intent"), MAX_INTENT_CHARS)
            if tool and intent:
                self.last_intent = intent
            self.tail = ("start", {"tool": tool})
            self.last_yield = None
            if tool:
                self._add_event(record, "tool", f"{tool}: {intent}" if intent else f"{tool} started")
        elif ctype == "session_exit":
            reason = _clean(data.get("reason"), 40) or "unknown"
            kind_ = _clean(data.get("kind"), 40) or "unknown"
            self._finish_run(_parse_ts(record.get("timestamp"))
                             or _parse_ts(data.get("recordedAt")))
            self.exit_info = {"reason": reason, "kind": kind_}
            self.tail = ("exit", {"reason": reason})
            self._add_event(record, "exit", f"session exit ({reason})")

    def _add_event(self, record, kind, text):
        rid = record.get("id")
        at = self.last_seen
        if not rid or not at:
            return
        sid = self.session_id or self.path.stem
        self.events.append({
            "id": f"{sid}:{rid}:{kind}",
            "agent": self.name,
            "at": at,
            "kind": kind,
            "text": _clean(text, MAX_INTENT_CHARS + 40) or kind,
        })
        if kind in ("spawn", "exit"):
            self._add_stream(record, "lifecycle", text)

    # ------------------------------------------------------------------
    # derivation
    # ------------------------------------------------------------------
    def derive_state(self, now_dt):
        if self.tail is None:
            return "unknown"
        kind, payload = self.tail
        if kind == "exit":
            if (self.exit_info.get("kind") == "signal"
                    or self.exit_info.get("reason") in ("sigint", "signal", "error")):
                return "stopped"
            last = self.last_yield or {}
            state = last.get("state")
            if state == "waiting":
                return "waiting"  # reported queue/blocked outcome survives a clean exit
            if state == "blocked":
                return "blocked"
            if state == "success" and last.get("terminal"):
                return "completed"
            return "stopped"
        if kind == "assistant" and payload.get("stop") in ("aborted", "error"):
            return "stopped"
        fresh = False
        if self.last_seen_dt is not None:
            fresh = (now_dt - self.last_seen_dt).total_seconds() <= WORKING_WINDOW_SECONDS
        if kind == "start":
            if payload.get("tool") == "wait":
                return "waiting"  # recorded, unresolved wait stays waiting
            return "working" if fresh else "quiet"
        if kind == "toolResult":
            if payload.get("tool") == "yield":
                last = self.last_yield or {}
                state = last.get("state")
                if state in ("waiting", "blocked"):
                    return state
                if state == "success" and last.get("terminal"):
                    return "completed"
                return "working" if fresh else "quiet"
            return "working" if fresh else "quiet"
        if kind == "assistant":
            return "quiet"  # turn ended normally; nothing since
        if kind in ("spawn", "custom_message"):
            return "working" if fresh else "quiet"
        return "unknown"

    def _target(self):
        # Target summaries use only structured identifiers/paths reported by
        # the agent's yields, never guesses from assignment text. Recorded
        # session content is streamed separately. A new steering message or
        # session_init clears the old target; unknown stays null.
        return self.last_target

    def agent_dict(self, now_dt):
        return {
            "id": self.session_id or f"journal:{self.name}",
            "name": self.name,
            "model": self.model,
            "state": self.derive_state(now_dt),
            "activity": self.last_intent,
            "target": self._target(),
            "lastSeen": self.last_seen,
            "runStartedAt": self.run_started_at.isoformat() if self.run_started_at else None,
            "runEndedAt": self.run_ended_at.isoformat() if self.run_ended_at else None,
            # Structured correction-attempt count from the latest yield's
            # data (if unambiguous); null rather than a guess otherwise.
            "correction": self.correction,
        }


class JournalWatcher:
    """Discovers the current session family and tails its journals."""

    def __init__(self, root, session_dir=None, session_id=None, independent_roots=None):
        self.root = Path(root)
        self.explicit_dir = Path(session_dir) if session_dir else None
        self.requested_session_id = _session_id(session_id)
        self.default_independent_config = (
            self.root / "build" / "live-dashboard" / "independent-roots.json")
        self.independent_config = (
            Path(independent_roots) if independent_roots else self.default_independent_config)
        self.independent_roots = {}
        self.independent_observers = {}
        self.trackers = {}
        self.offsets = {}
        self.buffers = {}
        self.headers = {}  # path -> (mtime_ns, size, info)
        self.anchors = {}
        self.identities = {}
        self.lock = threading.RLock()
        self.stream_epoch = uuid.uuid4().hex[:12]
        self.stream_order = 0
        self.rewrites = {}
        self.parser_issues = {}
        self.parent_path = None
        self.parent_session_id = None
        self.warnings = {
            "initializing": "initial journal scan in progress; agent list fills in shortly",
        }
        self.membership = None

    # ------------------------------------------------------------------
    # discovery
    # ------------------------------------------------------------------
    def _bases(self):
        if self.explicit_dir is not None:
            return [self.explicit_dir]
        sessions_root = Path.home() / ".omp" / "agent" / "sessions"
        if not sessions_root.is_dir():
            return []
        needle = self.root.name.lower()
        return [child for child in sorted(sessions_root.iterdir())
                if child.is_dir() and needle in child.name.lower()]

    def _peek(self, path):
        """Return {'id','cwd','parentSession'} from the session record, cached."""
        try:
            st = path.stat()
        except OSError:
            return None
        key = (st.st_mtime_ns, st.st_size)
        cached = self.headers.get(path)
        if cached and cached[0] == key[0] and cached[1] == key[1]:
            return cached[2]
        info = None
        try:
            with open(path, "rb") as handle:
                head = handle.read(HEADER_PEEK_BYTES)
        except OSError:
            self.headers[path] = (key[0], key[1], None)
            return None
        for line in head.split(b"\n"):
            if b'"type":"session"' not in line and b'"type": "session"' not in line:
                continue
            try:
                record = json.loads(line)
            except ValueError:
                continue
            if isinstance(record, dict) and record.get("type") == "session":
                info = {
                    "id": _session_id(record.get("id")),
                    "cwd": record.get("cwd"),
                    "parentSession": record.get("parentSession"),
                }
                break
        self.headers[path] = (key[0], key[1], info)
        return info

    def _candidates(self):
        out = []
        for base in self._bases():
            try:
                # Forks nest arbitrarily deep (agent stem directories inside
                # agent stem directories), so scan recursively.
                out.extend(base.rglob("*.jsonl"))
            except OSError:
                continue
        return out

    def _load_registrations(self):
        requested = load_independent_roots(self.independent_config)
        if _norm(self.independent_config) != _norm(self.default_independent_config) \
                and any("observerPort" in entry for entry in requested.values()):
            raise ValueError(
                "observerPort live registrations require the project configuration "
                "build/live-dashboard/independent-roots.json; custom paths support recorded-only entries")
        return requested

    def _requested_roots(self):
        self.warnings.pop("independent-roots", None)
        try:
            return self._load_registrations()
        except FileNotFoundError:
            return {}
        except (OSError, UnicodeError, ValueError) as exc:
            self.warnings["independent-roots"] = f"independent-root registration unavailable: {exc}"
            return {}

    def _registered_roots(self, candidates, family, requested=None):
        """Opt in exact same-project root journals, never their descendants."""
        self.independent_roots = {}
        self.independent_observers = {}
        if requested is None:
            requested = self._requested_roots()
        found = {}
        for path in candidates:
            info = self._peek(path) or {}
            sid = info.get("id")
            if sid in requested and info.get("cwd") and _norm(info["cwd"]) == _norm(self.root):
                found.setdefault(sid, []).append(path)
        rejected = []
        for sid, registration in requested.items():
            matches = found.get(sid, [])
            if len(matches) != 1 or matches[0] in family:
                rejected.append(sid)
                continue
            self.independent_roots[matches[0]] = registration["label"]
            if "observerPort" in registration:
                self.independent_observers[sid] = {
                    **registration, "path": matches[0],
                    "parentSession": (self._peek(matches[0]) or {}).get("parentSession"),
                }
        if rejected:
            self.warnings["independent-roots"] = (
                "independent roots must identify one same-project root outside the owning family: "
                + ", ".join(rejected))
        return list(self.independent_roots)

    def independent_observer(self, root):
        """Resolve only a discovered same-project independent live registration.

        Recheck the config and journal header on reads, including during SSE:
        revocation, reassignment and a rewritten journal fail closed.
        """
        try:
            sid = str(uuid.UUID(root))
        except (ValueError, TypeError, AttributeError):
            raise ValueError("root must identify a registered independent live observer") from None
        with self.lock:
            known = self.independent_observers.get(sid)
            if not known:
                raise ValueError("root is not a registered independent live observer")
            try:
                current = self._load_registrations().get(sid)
            except (OSError, UnicodeError, ValueError) as exc:
                raise ValueError(f"independent-root registration unavailable: {exc}") from exc
            info = self._peek(known["path"]) or {}
            if not current or "observerPort" not in current \
                    or info.get("id") != sid or not info.get("cwd") \
                    or _norm(info["cwd"]) != _norm(self.root) \
                    or info.get("parentSession") != known["parentSession"]:
                raise ValueError("independent live registration or journal identity changed")
            return {**current, "scope": "independent-root", "rootSessionId": sid,
                    "streamSource": "live-observer"}

    def _discover(self):
        """Return the journal family (parent first) for the repo root."""
        self.independent_roots = {}
        self.independent_observers = {}
        requested = self._requested_roots()
        candidates = self._candidates()
        # Top-level candidates live directly in a base directory; anything
        # deeper is a fork journal inside a session stem directory.
        bases = set(self._bases())
        top_level = [p for p in candidates if p.parent in bases]
        best = None
        for path in top_level:
            info = self._peek(path)
            if not info:
                continue
            # Opted-in independent roots are additional panels, never an
            # automatic replacement for the primary owning session.
            if not (self.requested_session_id or self.parent_session_id) \
                    and info.get("id") in requested:
                continue
            # A main session may be an in-place fork with parentSession set.
            # Only an explicit UUID selects such a root; ancestry alone must
            # not retarget the dashboard to some other session.
            if info.get("parentSession") and not (
                    self.requested_session_id or self.parent_session_id):
                continue
            cwd = info.get("cwd")
            if not cwd or _norm(cwd) != _norm(self.root):
                continue
            if self.requested_session_id and info.get("id") != self.requested_session_id:
                continue
            if self.parent_session_id and info.get("id") != self.parent_session_id:
                continue
            try:
                mtime = path.stat().st_mtime_ns
            except OSError:
                continue
            if best is None or mtime > best[0]:
                best = (mtime, path, info)
        if best is None and self.explicit_dir is not None and not (
                self.requested_session_id or self.parent_session_id):
            # Explicit session dir: fall back to the newest journal anywhere
            # in the tree and say so.
            independent_family = {
                member for root in top_level
                if (self._peek(root) or {}).get("id") in requested
                for member in self._family(root, candidates)
            }
            for path in candidates:
                if path in independent_family:
                    continue
                try:
                    mtime = path.stat().st_mtime_ns
                except OSError:
                    continue
                if best is None or mtime > best[0]:
                    info = self._peek(path) or {}
                    best = (mtime, path, info)
            if best is not None:
                self.warnings["session"] = (
                    "explicit session dir: no journal with matching cwd found; "
                    f"using newest journal {best[1].name}"
                )
        if best is None:
            self.warnings["session"] = (
                f"no session journal with cwd {_norm(self.root)} found"
                f" for root session {self.requested_session_id or self.parent_session_id or '(auto)'}; "
                "agents unavailable (check --session-id and --session-dir)"
            )
            self.parent_path = None
            return []
        self.warnings.pop("session", None)
        parent = best[1]
        self.parent_path = parent
        self.parent_session_id = best[2].get("id") if best[2] else None
        family = self._family(parent, candidates)
        return family + self._registered_roots(top_level, family, requested)

    def _family(self, parent, candidates):
        """Collect the parent plus every descendant fork journal.

        Each agent's forks live in a directory named after its journal stem,
        nested to arbitrary depth (sub-subagents); the walk follows those
        directories, and a parentSession-chain pass catches stragglers that
        live outside them.  Other sessions/projects are never included.
        """
        family = [parent]
        included = {_norm(parent)}
        stack = [parent]
        while stack:
            stem_dir = stack.pop().with_suffix("")
            if not stem_dir.is_dir():
                continue
            try:
                children = sorted(stem_dir.glob("*.jsonl"))
            except OSError:
                continue
            for child in children:
                key = _norm(child)
                if key not in included:
                    included.add(key)
                    family.append(child)
                    stack.append(child)
        by_parent = {}
        for path in candidates:
            if _norm(path) in included:
                continue
            info = self._peek(path)
            ref = _session_ref(info.get("parentSession")) if info else None
            if ref:
                by_parent.setdefault(ref, []).append(path)
        # Seed every directory-discovered descendant too: an out-of-tree
        # grandchild may point at its UUID rather than the root's file path.
        frontier = list(family)
        while frontier:
            current = frontier.pop()
            info = self._peek(current) or {}
            refs = {_norm(current), _session_ref(info.get("id"))}
            for ref in refs - {None}:
                for child in by_parent.get(ref, []):
                    key = _norm(child)
                    if key not in included:
                        included.add(key)
                        family.append(child)
                        frontier.append(child)
        return family

    # ------------------------------------------------------------------
    # tailing
    # ------------------------------------------------------------------
    def poll(self):
        with self.lock:
            self._poll()

    def _poll(self):
        """Rescan discovery targets and incrementally ingest new records."""
        try:
            family = self._discover()
        except OSError as exc:
            self.warnings["watcher"] = f"journal scan failed: {exc.__class__.__name__}: {exc}"
            family = []
        else:
            self.warnings.pop("watcher", None)
        seen = set()
        for path in family:
            seen.add(path)
            try:
                self._sync(path)
                # Explicit kills leave this sidecar for persisted roster
                # revival to honor. Missing/unreadable evidence is not death.
                try:
                    marker = path.with_name(path.name + ".tombstone").stat()
                except FileNotFoundError:
                    self.trackers[path].tombstoned = False
                    self.trackers[path].tombstoned_at = None
                except OSError:
                    pass
                else:
                    self.trackers[path].tombstoned = True
                    self.trackers[path].tombstoned_at = datetime.fromtimestamp(
                        marker.st_mtime, timezone.utc)
                self.warnings.pop(f"journal:{path.name}", None)
            except OSError as exc:
                self.warnings[f"journal:{path.name}"] = (
                    f"journal {path.name}: unreadable ({exc.__class__.__name__})"
                )
        for gone in [p for p in self.trackers if p not in seen]:
            self.trackers.pop(gone, None)
            self.offsets.pop(gone, None)
            self.buffers.pop(gone, None)
            self.anchors.pop(gone, None)
            self.identities.pop(gone, None)
            self.parser_issues.pop(gone, None)
            self.rewrites.pop(gone, None)
        self._record_run_retirements()
        if family:
            self.warnings.pop("initializing", None)

    def _tracker_name(self, path, info):
        if path in self.independent_roots:
            return self.independent_roots[path], True
        # The selected owning root is main even when its journal was forked.
        # parentSession describes ancestry, not its current runner role.
        is_parent = path == self.parent_path or (
            info is not None and not info.get("parentSession"))
        if is_parent:
            return "main", True
        # Nested journals are named "<parent>.<agent>.jsonl"; show the agent
        # segment only.
        stem = path.stem
        return (stem.rsplit(".", 1)[-1] if "." in stem else stem), False

    def _stream_sink(self, item):
        self.stream_order += 1
        item["_order"] = self.stream_order

    def _sync(self, path):
        st = path.stat()
        size = st.st_size
        identity = (st.st_dev, st.st_ino)
        offset = self.offsets.get(path, 0)
        rewrite = size < offset or (
            path in self.identities and self.identities[path] != identity)
        with open(path, "rb") as handle:
            anchor = self.anchors.get(path)
            if offset and anchor and not rewrite:
                handle.seek(offset - len(anchor))
                rewrite = handle.read(len(anchor)) != anchor
            if path not in self.trackers or rewrite:
                info = self._peek(path) or {}
                name, is_parent = self._tracker_name(path, info)
                self.trackers[path] = JournalTracker(
                    path, name, is_parent, stream_sink=self._stream_sink)
                offset = 0
                self.buffers[path] = b""
                self.anchors.pop(path, None)
                self.offsets[path] = 0
                self.identities[path] = identity
                self.parser_issues.pop(path, None)
                self.warnings.pop(f"malformed:{path.name}", None)
                if rewrite:
                    self.stream_epoch = uuid.uuid4().hex[:12]
                    # Successful resynchronization is diagnostic metadata, not
                    # a warning; unreadable/malformed errors remain reportable.
                    self.rewrites[path] = self.rewrites.get(path, 0) + 1
            tracker = self.trackers[path]
            handle.seek(offset)
            chunk = handle.read(min(max(0, size - offset), MAX_INITIAL_READ))
            if not chunk:
                return
            buffered = self.buffers.get(path, b"")
            data_start = offset - len(buffered)
            lines = (buffered + chunk).split(b"\n")
            self.buffers[path] = lines.pop()
            line_offset = data_start
            for line in lines:
                if line.strip():
                    try:
                        record = json.loads(line)
                        if not isinstance(record, dict):
                            raise ValueError("record must be a JSON object")
                    except (ValueError, UnicodeDecodeError) as exc:
                        tracker.malformed += 1
                        self.parser_issues[path] = {
                            "journal": path.name, "byteOffset": line_offset,
                            "bytes": len(line), "error": str(exc),
                            "count": tracker.malformed,
                        }
                    else:
                        tracker.apply(record)
                line_offset += len(line) + 1
            new_offset = offset + len(chunk)
            self.anchors[path] = (self.anchors.get(path, b"") + chunk)[-TAIL_ANCHOR_BYTES:]
        self.offsets[path] = new_offset
        self.identities[path] = identity
        issue = self.parser_issues.get(path)
        if issue:
            self.warnings[f"malformed:{path.name}"] = (
                f"journal {path.name}: {issue['count']} invalid complete record(s); "
                f"last at byte {issue['byteOffset']}: {issue['error']}"
            )

    # ------------------------------------------------------------------
    # snapshots
    # ------------------------------------------------------------------
    def update_membership(self, observer):
        """Accept only UUID-keyed, root-scoped runner registry evidence.

        Failures/old observers leave the last good snapshot intact. A new
        complete epoch replaces the previous one, never names or model-turn
        state. Entries with unknown membership stay explicitly unknown.
        Incomplete snapshots retain known entries but never retire absent UUIDs.
        """
        if not isinstance(observer, dict):
            return
        membership = observer.get("membership")
        if not isinstance(membership, dict) \
                or membership.get("source") != "runner-registry" \
                or type(membership.get("complete")) is not bool:
            return
        epoch = observer.get("epoch")
        revision = membership.get("revision")
        entries = membership.get("agents")
        if not isinstance(epoch, str) or not epoch \
                or type(revision) is not int or revision < 0 \
                or not isinstance(entries, list):
            return
        members = {}
        for entry in entries:
            if not isinstance(entry, dict) or not isinstance(entry.get("id"), str):
                return
            try:
                sid = str(uuid.UUID(entry["id"]))
            except ValueError:
                return
            active = entry.get("active")
            if (active is not None and type(active) is not bool) or sid in members:
                return
            members[sid] = active
        with self.lock:
            root = _session_id(observer.get("rootSessionId"))
            if not root or root != self.session_label():
                return
            previous = self.membership
            if previous and previous["epoch"] == epoch \
                    and revision < previous["revision"]:
                return
            complete = membership["complete"]
            if not complete and previous and previous["root"] == root:
                members = {**previous["agents"], **members}
            self.membership = {
                "root": root, "epoch": epoch, "revision": revision, "agents": members,
                "complete": complete,
                "at": (_parse_ts(membership.get("updatedAt")) or datetime.now(timezone.utc))
                if complete or not previous else previous["at"],
            }
            self._record_run_retirements()

    def _record_run_retirements(self):
        """Ingest external terminal evidence without changing activity/membership.

        Registry membership can prove retirement, but its global updatedAt is
        not this agent's finish time: leave an unrecorded end unknown. Tombstone
        mtime is the persisted explicit-kill timestamp. Neither source uses
        lastSeen/now, and repeated snapshots never mutate clock evidence.
        """
        membership = self.membership
        if membership and membership["root"] != self.session_label():
            membership = None
        for tracker in self.trackers.values():
            if tracker.tombstoned:
                tracker._finish_run(tracker.tombstoned_at)
            if not membership or tracker.path in self.independent_roots:
                continue
            sid = tracker.session_id
            active = membership["agents"].get(
                sid, False if membership["complete"] else None)
            if active is False and not (
                    tracker.assignment_started_at
                    and tracker.assignment_started_at > membership["at"]):
                tracker._finish_run(None)

    def snapshot(self):
        with self.lock:
            return self._snapshot()

    def _snapshot(self):
        """Return (agents, events, warnings) derived from current journals."""
        now_dt = datetime.now(timezone.utc)
        agents = [t.agent_dict(now_dt) for t in self.trackers.values()]
        membership = self.membership
        if membership and membership["root"] != self.session_label():
            membership = None
        for tracker, agent in zip(self.trackers.values(), agents):
            active = None
            independent = tracker.path in self.independent_roots
            if independent:
                agent.update(name=self.independent_roots[tracker.path],
                             scope="independent-root",
                             streamSource="live-observer" if agent["id"] in
                             self.independent_observers else "recorded-history",
                             rootSessionId=agent["id"])
            if membership and not independent:
                # A complete owning registry proves an absent UUID is not a
                # current assignment; a present-but-unknown ref does not.
                active = membership["agents"].get(
                    agent["id"], False if membership["complete"] else None)
                if active is False and tracker.assignment_started_at \
                        and tracker.assignment_started_at > membership["at"]:
                    active = None  # A new recorded assignment supersedes cached retirement.
            if tracker.assignment_retired and (active is None or (
                    membership and tracker.assignment_retired_at
                    and tracker.assignment_retired_at > membership["at"])):
                active = False
            if tracker.tombstoned and (active is None or (
                    membership and tracker.tombstoned_at
                    and tracker.tombstoned_at > membership["at"])):
                active = False
            if active is not None:
                agent["active"] = active
        agents.sort(key=lambda a: (a["lastSeen"] is not None, a["lastSeen"] or ""), reverse=True)
        events = []
        for tracker in self.trackers.values():
            if tracker.path in self.independent_roots:
                events.extend({**event, "agent": self.independent_roots[tracker.path],
                               "scope": "independent-root", "rootSessionId": tracker.session_id}
                              for event in tracker.events)
            else:
                events.extend(tracker.events)
        events.sort(key=lambda e: (e.get("at") or "", e.get("id") or ""))
        del events[:-MAX_EVENTS_GLOBAL]
        return agents, events, list(self.warnings.values())[:12]

    def stream_metadata(self):
        with self.lock:
            return {
                "revision": f"{self.stream_epoch}:{self.stream_order}",
                "available": bool(self.trackers),
                "retentionPerAgent": STREAMS_PER_JOURNAL,
                "retentionUnit": "whole entries",
                "visibility": "user/assistant text and thinking, peer messages, tool arguments "
                              "and result content; no provider metadata",
                "parserIssues": list(self.parser_issues.values()),
                "journalRewrites": [
                    {"journal": path.name, "count": count}
                    for path, count in self.rewrites.items()
                ],
            }

    def streams(self, agent=None, cursor=None, limit=300):
        with self.lock:
            # All extracted session-output categories share the history
            # transport. Retention evicts whole entries, never clips content.
            items = [
                item for tracker in self.trackers.values() for item in tracker.stream
                if (agent is None or item["agentId"] == agent)
            ]
            items.sort(key=lambda item: item["_order"])
            reset = False
            after = None
            if cursor:
                try:
                    epoch, number = cursor.split(":")
                    after = int(number)
                    reset = epoch != self.stream_epoch or after > self.stream_order \
                        or after < 0
                    # Per-agent eviction can produce holes, not just prefix loss.
                    reset = reset or any(
                        tracker.evicted_order > after
                        for tracker in self.trackers.values()
                        if agent is None or (tracker.session_id or tracker.path.stem) == agent
                    )
                except (ValueError, AttributeError):
                    reset = True
            if after is None or reset:
                items.sort(key=lambda item: (item["at"] or "", item["_order"]))
                chosen = items[-limit:]
                next_order = self.stream_order
                has_more = False
            else:
                pending = [item for item in items if item["_order"] > after]
                chosen = pending[:limit]
                has_more = len(pending) > limit
                next_order = chosen[-1]["_order"] if has_more else self.stream_order
            independent_names = {
                tracker.session_id: self.independent_roots[path]
                for path, tracker in self.trackers.items() if path in self.independent_roots
            }
            return {
                "cursor": f"{self.stream_epoch}:{next_order}", "reset": reset,
                "hasMore": has_more, "retentionPerAgent": STREAMS_PER_JOURNAL,
                "source": "recorded-history",
                "items": [
                    {**{k: v for k, v in item.items() if k != "_order"},
                     "source": "recorded-history",
                     **({"scope": "independent-root", "rootSessionId": item["agentId"],
                         "agent": independent_names[item["agentId"]]}
                        if item["agentId"] in independent_names else {})}
                    for item in chosen
                ],
            }

    def session_label(self):
        tracker = self.trackers.get(self.parent_path)
        return (tracker.session_id if tracker else None) or self.parent_session_id
