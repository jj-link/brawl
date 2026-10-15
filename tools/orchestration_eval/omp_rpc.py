"""Documented OMP JSONL v1 control-only client. No prompting or session adoption API."""
from __future__ import annotations

import json
from pathlib import Path
import queue
import threading
import time
import uuid

from .processes import ProcessManager
from .safety import SafetyError, confined, now, save_json

CONTROL_COMMANDS = frozenset({"get_state", "new_session", "abort", "get_session_stats",
                              "set_auto_retry", "set_auto_compaction", "set_cache_warming"})


class OmpControl:
    def __init__(self, manager: ProcessManager, executable: Path, *, provider: str, model: str,
                 authorization_revision: int):
        executable = executable.resolve(strict=True)
        if executable.suffix.lower() != ".exe":
            raise SafetyError("OMP must be the native executable, never a shell launcher")
        self.root = confined(manager.root / "omp-probes" / uuid.uuid4().hex)
        self.root.mkdir(parents=True)
        self.sessions = self.root / "sessions"
        self.sessions.mkdir()
        config = self.root / "config.yml"
        save_json(config, {
            "autoResume": False, "enabledProviders": [],
            "disabledProviders": ["native", "claude", "codex", "gemini", "github", "opencode", "cursor", "agents-md"],
            "providers": {"cacheWarming": "off"}, "telemetry": {"otlpExportEnabled": False},
            "advisor": {"enabled": False}, "memory": {"enabled": False},
            "plan": {"defaultOnStartup": False}, "retry": {"enabled": False},
        })
        self.owned = manager.launch(
            [str(executable), "--mode", "rpc", "--no-ui", "--no-tools", "--no-extensions", "--no-title",
             "--no-skills", "--no-rules", "--no-lsp", "--no-pty", "--config", str(config),
             "--cwd", str(self.root), "--session-dir", str(self.sessions), "--model", f"{provider}/{model}"],
            kind="omp-control", cwd=self.root, pipe=True, authorization_revision=authorization_revision,
        )
        self.frames: queue.Queue = queue.Queue()
        self.log_lock = threading.Lock()
        self.log = self.root / "rpc.jsonl"
        self.reader_error = None
        self._closing = False
        self.reader = threading.Thread(target=self._read, daemon=True, name="owned-omp-rpc-reader")
        self.reader.start()
        self.ready = self._receive(lambda f: f.get("type") == "ready", 60)
        if self.ready.get("protocolVersion") != 1:
            raise SafetyError("Unsupported OMP startup protocol; no control commands sent")
        self.expected_model = {"provider": provider, "id": model}
        self.initial = self.state()
        self.request("set_auto_retry", enabled=False)
        self.request("set_auto_compaction", enabled=False)
        self.request("set_cache_warming", mode="off")

    def _log(self, direction: str, frame: dict) -> None:
        with self.log_lock, self.log.open("a", encoding="utf-8", newline="\n") as stream:
            stream.write(json.dumps({"at": now(), "direction": direction, "frame": frame}) + "\n")

    def _read(self) -> None:
        try:
            while True:
                raw = self.owned.process.stdout.readline(1048577)
                if not raw:
                    raise EOFError("Owned OMP stdout closed")
                if len(raw) > 1048576 or not raw.endswith(b"\n"):
                    raise SafetyError("OMP frame exceeded documented v1 limit")
                frame = json.loads(raw.decode("utf-8"))
                self._log("out", frame)
                if frame.get("type") in {"agent_start", "host_tool_call", "host_uri_request"}:
                    raise SafetyError("Unexpected agent/provider work in a control-only evaluation")
                self.frames.put(frame)
        except BaseException as exc:
            unexpected = not isinstance(exc, EOFError) or not getattr(self, "_closing", False)
            if unexpected:
                self.reader_error = exc
            self.frames.put(exc)
            # An unsolicited forbidden frame cannot wait for a future request
            # to consume the error. Contain the actual owned job immediately.
            proof, failure = None, None
            try:
                proof = self.owned.stop(grace=0, deadline=time.monotonic() + 5)
            except BaseException as stop_error:
                failure = repr(stop_error)
            save_json(self.root / "reader-termination.json", {
                "error": repr(exc), "unexpected": unexpected, "exit_proof": proof,
                "termination_error": failure, "observed_at": now()})

    def _receive(self, predicate, seconds: float):
        deadline = time.monotonic() + seconds
        while True:
            try:
                frame = self.frames.get(timeout=max(0.001, deadline - time.monotonic()))
            except queue.Empty as exc:
                raise TimeoutError("Owned OMP control handshake timed out") from exc
            if isinstance(frame, BaseException):
                raise frame
            if predicate(frame):
                return frame
            if time.monotonic() >= deadline:
                raise TimeoutError("Owned OMP control response timed out")

    def _send(self, command: str, values: dict) -> str:
        if command not in CONTROL_COMMANDS:
            raise SafetyError("Only control commands are authorized; prompts and session adoption are forbidden")
        if command == "new_session" and values:
            raise SafetyError("Fresh sessions cannot inherit an external parent")
        if getattr(self, "reader_error", None) is not None:
            raise self.reader_error
        identifier = uuid.uuid4().hex
        frame = {"id": identifier, "type": command, **values}
        self._log("in", frame)
        stream = self.owned.process.stdin
        stream.write((json.dumps(frame) + "\n").encode("utf-8"))
        stream.flush()
        return identifier

    def request(self, command: str, *, timeout: float = 30, **values):
        if timeout <= 0:
            raise TimeoutError("Owned OMP control response budget is exhausted")
        identifier = self._send(command, values)
        response = self._receive(lambda f: f.get("type") == "response" and f.get("id") == identifier, timeout)
        if response.get("command") != command or response.get("success") is not True:
            raise RuntimeError(f"OMP control failed: {response}")
        return response.get("data")

    def state(self, *, timeout: float = 30) -> dict:
        state = self.request("get_state", timeout=timeout)
        if not state.get("sessionId") or not state.get("sessionFile"):
            raise SafetyError("OMP did not return a persistent owned session identity")
        confined(Path(state["sessionFile"]), self.sessions)
        selected = state.get("model") or {}
        if any(selected.get(k) != v for k, v in self.expected_model.items()):
            raise SafetyError(f"OMP selected an unexpected model: {selected}")
        if state.get("isStreaming") or state.get("isCompacting") or state.get("messageCount", 0) or state.get("queuedMessageCount", 0) or state.get("hasPendingAsyncWork"):
            raise SafetyError("OMP session is not a fresh idle control-only session")
        return state

    def fresh_session(self) -> dict:
        before = self.state()
        result = self.request("new_session")
        if isinstance(result, dict) and result.get("cancelled"):
            raise SafetyError("OMP vetoed the new-session transition")
        after = self.state()
        if before["sessionId"] == after["sessionId"]:
            raise SafetyError("OMP reused a session identity")
        save_json(self.root / "session-handshake.json", {"before": before, "after": after, "ready": self.ready,
                                                       "provider_prompt_commands": 0, "protocol": "documented-jsonl-v1"})
        return after

    def abort_without_wait(self) -> None:
        """Send documented cancellation without spending a per-control reply budget."""
        self._closing = True
        self._send("abort", {})

    def cancel(self) -> dict:
        deadline = time.monotonic() + 5
        control_deadline = time.monotonic() + 3
        self._closing = True
        state, error = None, None
        try:
            self.request("abort", timeout=max(0, control_deadline - time.monotonic()))
            state = self.state(timeout=max(0, control_deadline - time.monotonic()))
        except BaseException as exc:
            error = exc
        finally:
            # A protocol error, EOF or timeout never bypasses native ownership
            # cleanup. Preserve the original error, but only after proving exit.
            proof = self.owned.stop(grace=0, deadline=deadline)
            self.reader.join(timeout=max(0, deadline - time.monotonic()))
            save_json(self.root / "cancellation.json", {"idle_state": state, "exit_proof": proof,
                                                       "control_error": repr(error) if error else None})
        if error is not None:
            raise error
        return proof
