"""Read-only discovery, tailing, and interpretation of omp session journals.

Journals are read-only JSONL files under ``~/.omp/agent/sessions``. Visible
assistant text, peer messages and tool activity are delivered separately from
state summaries. Thinking, prompts, provider payloads and credential metadata
are never extracted. Tool arguments are summarized rather than dumped; visible
output has credential patterns redacted and bounded retention.

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
"""

from __future__ import annotations

import json
import os
import re
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
MAX_STREAM_CHARS = 4000
MAX_STREAM_BYTES_PER_JOURNAL = 128 * 1024
TAIL_ANCHOR_BYTES = 256


def _visible_text(value):
    """Only call on visible text, never on reasoning or provider metadata."""
    if not isinstance(value, str):
        return ""
    text = re.sub(
        r"<(system(?:-reminder|-notice)?|developer|thinking|analysis|contextSnapshot)"
        r"\b[^>]*>.*?</\1>", "[private context omitted]", value,
        flags=re.I | re.S,
    )
    text = re.sub(r"-----BEGIN [^-]*PRIVATE KEY-----.*?"
                  r"-----END [^-]*PRIVATE KEY-----", "[credential redacted]",
                  text, flags=re.S)
    text = re.sub(
        r"(?i)(\b(?:api[_-]?key|access[_-]?token|refresh[_-]?token|"
        r"client[_-]?secret|password|passwd|authorization|credential)"
        r"[\"']?\s*[:=]\s*)(?:\"[^\"\n]*\"|'[^'\n]*'|[^\s,;]+)",
        r"\1[redacted]", text,
    )
    text = re.sub(r"(?i)\b(Bearer|Basic)\s+[A-Za-z0-9+/_.=-]+",
                  r"\1 [redacted]", text)
    text = re.sub(r"\b(?:sk-[A-Za-z0-9_-]{16,}|gh[pousr]_[A-Za-z0-9_]{16,}|"
                  r"github_pat_[A-Za-z0-9_]{16,}|AKIA[A-Z0-9]{16})\b",
                  "[credential redacted]", text)
    text = re.sub(r"(https?://)[^/\s:@]+:[^/\s@]+@", r"\1[redacted]@", text)
    return text


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
        self._seq = 0
        self._stream_seq = 0
        self.events = deque(maxlen=EVENTS_PER_JOURNAL)
        self.stream = deque()
        self.stream_bytes = 0
        self.evicted_order = 0
        self._stream_sink = stream_sink

    def _add_stream(self, record, kind, text, suffix="", **fields):
        text = _visible_text(text)
        if not text:
            return
        self._stream_seq += 1
        sid = self.session_id or self.path.stem
        rid = record.get("id") or str(self._seq)
        item = {
            "id": f"{sid}:{rid}:{kind}:{suffix}", "agentId": sid,
            "agent": self.name, "at": record.get("timestamp") or self.last_seen,
            "sequence": self._stream_seq, "kind": kind, "role": None,
            "tool": None, "callId": None, "intent": None, "isError": False,
            "text": text[:MAX_STREAM_CHARS], "truncated": len(text) > MAX_STREAM_CHARS,
        }
        item.update(fields)
        if self._stream_sink:
            self._stream_sink(item)
        self.stream.append(item)
        self.stream_bytes += len(item["text"].encode("utf-8"))
        while len(self.stream) > STREAMS_PER_JOURNAL \
                or self.stream_bytes > MAX_STREAM_BYTES_PER_JOURNAL:
            removed = self.stream.popleft()
            self.evicted_order = removed.get("_order", 0)
            self.stream_bytes -= len(removed["text"].encode("utf-8"))

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
                    self._add_stream(record, "message", details.get("message"),
                                     role="peer", sender=sender)
            elif record.get("customType") == "async-result":
                # The visible completion body is useful; wrapper system notice
                # tags are removed, not interpreted as privileged instructions.
                body = record.get("content")
                if isinstance(body, str):
                    body = re.sub(r"</?system-notice[^>]*>", "", body)
                    self._add_stream(record, "tool_result", body, role="tool")
        # Other record kinds, including compaction summaries, credential pins,
        # developer messages and provider metadata, are intentionally ignored.

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
            self.last_yield = None
            self.exit_info = None
            self.assignment_retired = False
            self.assignment_started_at = _parse_ts(record.get("timestamp"))
            self.assignment_retired_at = None
            self.tail = ("spawn", {})
            return
        if role == "assistant":
            model = message.get("model")
            if isinstance(model, str) and model:
                self.model = model
            self.tail = ("assistant", {"stop": message.get("stopReason")})
            self.last_yield = None
            content = message.get("content")
            if not isinstance(content, list):
                return
            for index, block in enumerate(content):
                if not isinstance(block, dict):
                    continue
                if block.get("type") == "text":
                    self._add_stream(record, "message", block.get("text"),
                                     suffix=str(index), role="assistant")
                    continue
                if block.get("type") != "toolCall":
                    continue
                cid = block.get("id")
                tool = _clean(block.get("name"), 60)
                args = block.get("arguments")
                args = args if isinstance(args, dict) else {}
                intent = block.get("intent") or args.get("i")
                intent = _clean(intent, MAX_INTENT_CHARS)
                target = _clean(args.get("path"), 200)
                text = f"{tool or 'tool'}: {intent or 'called'}"
                if target:
                    text += f"\nTarget: {target}"
                self._add_stream(record, "tool_call", text, suffix=str(index),
                                 role="assistant", tool=tool, callId=cid, intent=intent)
                if tool and intent:
                    self.last_intent = intent
                if cid and tool:
                    self.calls[cid] = {
                        "tool": tool,
                        "intent": intent,
                        "target": target,
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
        elif role == "toolResult":
            tool = _clean(message.get("toolName"), 60)
            cid = message.get("toolCallId")
            is_error = bool(message.get("isError"))
            details = message.get("details")
            details = details if isinstance(details, dict) else {}
            call = self.calls.get(cid) or {}
            content = message.get("content")
            visible = "\n".join(
                b.get("text", "") for b in content
                if isinstance(b, dict) and b.get("type") == "text"
                and isinstance(b.get("text"), str)
            ) if isinstance(content, list) else ""
            target = (call.get("target") or "").lower()
            if any(s in target for s in (
                    "history://", "skill://", "omp://", ".env", "credential",
                    "secrets", "id_rsa", "id_ed25519")):
                visible = "[private target output omitted]"
            self._add_stream(record, "tool_result",
                             visible or f"{tool or 'tool'} - {'error' if is_error else 'ok'}",
                             role="tool", tool=tool, callId=cid,
                             intent=call.get("intent"), isError=is_error)
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

    def __init__(self, root, session_dir=None, session_id=None):
        self.root = Path(root)
        self.explicit_dir = Path(session_dir) if session_dir else None
        self.requested_session_id = _session_id(session_id)
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
            if membership:
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
                "maxTextChars": MAX_STREAM_CHARS,
                "maxBytesPerAgent": MAX_STREAM_BYTES_PER_JOURNAL,
                "visibility": "assistant text, peer messages, tool summaries and visible output; "
                              "no prompts, thinking or provider metadata",
                "parserIssues": list(self.parser_issues.values()),
                "journalRewrites": [
                    {"journal": path.name, "count": count}
                    for path, count in self.rewrites.items()
                ],
            }

    def streams(self, agent=None, cursor=None, limit=300):
        with self.lock:
            # Historical transport is deliberately narrower than the internal
            # status parser: tool output/peer assignments can contain private
            # prompts or provider payloads. Only visible assistant text crosses.
            items = [
                item for tracker in self.trackers.values() for item in tracker.stream
                if (agent is None or item["agentId"] == agent)
                and item["kind"] == "message" and item.get("role") == "assistant"
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
            return {
                "cursor": f"{self.stream_epoch}:{next_order}", "reset": reset,
                "hasMore": has_more, "retentionPerAgent": STREAMS_PER_JOURNAL,
                "source": "recorded-history",
                "items": [
                    {**{k: v for k, v in item.items() if k != "_order"},
                     "source": "recorded-history", "complete": True}
                    for item in chosen
                ],
            }

    def session_label(self):
        tracker = self.trackers.get(self.parent_path)
        return (tracker.session_id if tracker else None) or self.parent_session_id
