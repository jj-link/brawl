"""Read-only discovery, tailing, and interpretation of omp session journals.

Journals are append-only JSONL files under ``~/.omp/agent/sessions``.  This
module only ever reads them.  Only record kinds that carry safe, structured
signals are interpreted: tool intents, tool result statuses, session/model
metadata, and exit records.  User prompts, system prompts, thinking content,
raw tool arguments/outputs, and credentials are never extracted or emitted.

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
"""

from __future__ import annotations

import json
import os
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


def _clean(value, limit):
    """Collapse whitespace and clamp; returns None for non-strings/empty."""
    if not isinstance(value, str):
        return None
    text = " ".join(value.split())
    return text[:limit] or None


def _parse_ts(value):
    if not isinstance(value, str) or not value:
        return None
    try:
        return datetime.fromisoformat(value.replace("Z", "+00:00"))
    except ValueError:
        return None


def _norm(path):
    return os.path.normcase(os.path.abspath(str(path)))


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

    def __init__(self, path, name, is_parent):
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
        self._seq = 0
        self.events = deque(maxlen=EVENTS_PER_JOURNAL)

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
            self.session_id = record.get("id") or self.session_id
            if "parentSession" not in record and not self.is_parent:
                self.is_parent = True
                self.name = "main"
        elif kind == "model_change":
            model = _clean(record.get("model"), 120)
            if model:
                self.model = model
        elif kind == "session_init":
            # A reused agent's new assignment supersedes any target reported
            # for the previous one: current scope differs or is unknown.
            self.last_target = None
            self.last_target_seq = None
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
        # All other kinds (thinking_level_change, mode_change, compaction,
        # model_usage, credential_pin, custom_message, todo_*) carry no safe
        # dashboard signal and are ignored.

    def _apply_message(self, record):
        message = record.get("message")
        if not isinstance(message, dict):
            return
        role = message.get("role")
        if role == "user":
            # A steering assignment supersedes any previously reported target;
            # reused agents resume without emitting a new session_init.
            # Message content itself is never interpreted or stored.
            self.last_target = None
            self.last_target_seq = None
            return
        if role == "assistant":
            model = message.get("model")
            if isinstance(model, str) and model:
                self.model = model
            self.tail = ("assistant", {"stop": message.get("stopReason")})
            content = message.get("content")
            if not isinstance(content, list):
                return
            for block in content:
                if not isinstance(block, dict) or block.get("type") != "toolCall":
                    continue
                cid = block.get("id")
                tool = _clean(block.get("name"), 60)
                args = block.get("arguments")
                args = args if isinstance(args, dict) else {}
                intent = block.get("intent") or args.get("i")
                intent = _clean(intent, MAX_INTENT_CHARS)
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
                    }
                    if len(self.calls) > MAX_TRACKED_CALLS:
                        self.calls.clear()
        elif role == "toolResult":
            tool = _clean(message.get("toolName"), 60)
            cid = message.get("toolCallId")
            is_error = bool(message.get("isError"))
            details = message.get("details")
            details = details if isinstance(details, dict) else {}
            call = self.calls.get(cid) or {}
            self.pending.pop(cid, None)
            if tool == "yield":
                data = details.get("data")
                data = data if isinstance(data, dict) else {}
                self.last_yield = {
                    "state": _yield_state(details.get("status"))
                    or _yield_state(data.get("status")),
                    "terminal": bool(call.get("yield_terminal")),
                }
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
        # role "user" and anything else: never interpreted.

    def _apply_custom(self, record):
        ctype = record.get("customType")
        data = record.get("data")
        data = data if isinstance(data, dict) else {}
        if ctype == "tool_execution_start":
            tool = _clean(data.get("toolName"), 60)
            cid = data.get("toolCallId")
            call = self.calls.get(cid) or {}
            if cid:
                self.pending[cid] = {"tool": tool}
                if len(self.pending) > MAX_TRACKED_CALLS:
                    self.pending.clear()
            intent = _clean(data.get("intent") or call.get("intent"), MAX_INTENT_CHARS)
            if tool and intent:
                self.last_intent = intent
            self.tail = ("start", {"tool": tool})
            if tool:
                self._add_event(record, "tool", f"{tool}: {intent}" if intent else f"{tool} started")
        elif ctype == "session_exit":
            reason = _clean(data.get("reason"), 40) or "unknown"
            kind_ = _clean(data.get("kind"), 40) or "unknown"
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
            "id": f"{sid}:{rid}",
            "agent": self.name,
            "at": at,
            "kind": kind,
            "text": _clean(text, MAX_INTENT_CHARS + 40) or kind,
        })

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
        # Only structured target identifiers/paths reported by the agent's
        # own yields are shown; assignment/prompt text is never exposed and
        # unknown stays null.  A new user steering message or session_init
        # clears the previous value so completed work is not presented as
        # current.
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
            # Structured correction-attempt count from the latest yield's
            # data (if unambiguous); null rather than a guess otherwise.
            "correction": self.correction,
        }


class JournalWatcher:
    """Discovers the current session family and tails its journals."""

    def __init__(self, root, session_dir=None):
        self.root = Path(root)
        self.explicit_dir = Path(session_dir) if session_dir else None
        self.trackers = {}
        self.offsets = {}
        self.buffers = {}
        self.headers = {}  # path -> (mtime_ns, size, info)
        self.parent_path = None
        self.parent_session_id = None
        self.warnings = {
            "initializing": "initial journal scan in progress; agent list fills in shortly",
        }

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
                    "id": record.get("id"),
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

    def _discover(self):
        """Return the journal family (parent first) for the repo root."""
        candidates = self._candidates()
        # Top-level candidates live directly in a base directory; anything
        # deeper is a fork journal inside a session stem directory.
        bases = set(self._bases())
        top_level = [p for p in candidates if p.parent in bases]
        best = None
        for path in top_level:
            info = self._peek(path)
            if not info or info.get("parentSession"):
                continue
            cwd = info.get("cwd")
            if not cwd or _norm(cwd) != _norm(self.root):
                continue
            try:
                mtime = path.stat().st_mtime_ns
            except OSError:
                continue
            if best is None or mtime > best[0]:
                best = (mtime, path, info)
        if best is None and self.explicit_dir is not None:
            # Explicit session dir: fall back to the newest journal anywhere
            # in the tree and say so.
            for path in candidates:
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
                f"no session journal with cwd {_norm(self.root)} found; "
                "agents unavailable (pass --session-dir to override)"
            )
            self.parent_path = None
            return []
        self.warnings.pop("session", None)
        parent = best[1]
        self.parent_path = parent
        self.parent_session_id = best[2].get("id") if best[2] else None
        return self._family(parent, candidates)

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
            if info and info.get("parentSession"):
                by_parent.setdefault(_norm(info["parentSession"]), []).append(path)
        frontier = [_norm(parent)]
        while frontier:
            current = frontier.pop()
            for child in by_parent.get(current, []):
                key = _norm(child)
                if key not in included:
                    included.add(key)
                    family.append(child)
                    frontier.append(key)
        return family

    # ------------------------------------------------------------------
    # tailing
    # ------------------------------------------------------------------
    def poll(self):
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
                self.warnings.pop(f"journal:{path.name}", None)
            except OSError as exc:
                self.warnings[f"journal:{path.name}"] = (
                    f"journal {path.name}: unreadable ({exc.__class__.__name__})"
                )
        for gone in [p for p in self.trackers if p not in seen]:
            self.trackers.pop(gone, None)
            self.offsets.pop(gone, None)
            self.buffers.pop(gone, None)
        if family:
            self.warnings.pop("initializing", None)

    def _tracker_name(self, path, info):
        if info is not None:
            is_parent = not info.get("parentSession")
        else:
            is_parent = path == self.parent_path
        if is_parent:
            return "main", True
        # Nested journals are named "<parent>.<agent>.jsonl"; show the agent
        # segment only.
        stem = path.stem
        return (stem.rsplit(".", 1)[-1] if "." in stem else stem), False

    def _sync(self, path):
        st = path.stat()
        size = st.st_size
        if path not in self.trackers:
            info = self._peek(path) or {}
            name, is_parent = self._tracker_name(path, info)
            self.trackers[path] = JournalTracker(path, name, is_parent)
            self.offsets[path] = 0
            self.buffers[path] = b""
        tracker = self.trackers[path]
        offset = self.offsets.get(path, 0)
        if size < offset:
            # Truncated or replaced on disk: start over honestly.
            self.trackers[path] = JournalTracker(path, tracker.name, tracker.is_parent)
            tracker = self.trackers[path]
            offset = 0
            self.buffers[path] = b""
            self.warnings[f"truncated:{path.name}"] = (
                f"journal {path.name}: truncated/replaced on disk; re-read from start"
            )
        if size == offset:
            return
        read_len = min(size - offset, MAX_INITIAL_READ)
        with open(path, "rb") as handle:
            handle.seek(offset)
            chunk = handle.read(read_len)
        if not chunk:
            return
        data = self.buffers.get(path, b"") + chunk
        lines = data.split(b"\n")
        self.buffers[path] = lines.pop()  # trailing partial record
        malformed_before = tracker.malformed
        for line in lines:
            if not line.strip():
                continue
            try:
                record = json.loads(line)
            except ValueError:
                tracker.malformed += 1
                continue
            tracker.apply(record)
        self.offsets[path] = offset + len(chunk)
        if tracker.malformed > malformed_before:
            self.warnings[f"malformed:{path.name}"] = (
                f"journal {path.name}: {tracker.malformed} malformed record(s) skipped"
            )

    # ------------------------------------------------------------------
    # snapshots
    # ------------------------------------------------------------------
    def snapshot(self):
        """Return (agents, events, warnings) derived from current journals."""
        now_dt = datetime.now(timezone.utc)
        agents = [t.agent_dict(now_dt) for t in self.trackers.values()]
        agents.sort(key=lambda a: (a["lastSeen"] is not None, a["lastSeen"] or ""), reverse=True)
        events = []
        for tracker in self.trackers.values():
            events.extend(tracker.events)
        events.sort(key=lambda e: (e.get("at") or "", e.get("id") or ""))
        del events[:-MAX_EVENTS_GLOBAL]
        return agents, events, list(self.warnings.values())[:12]

    def session_label(self):
        if self.parent_path in self.trackers:
            return self.trackers[self.parent_path].session_id or self.parent_session_id
        return self.parent_session_id
