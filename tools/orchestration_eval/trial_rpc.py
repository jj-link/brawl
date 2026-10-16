"""Real native OMP roots with normal tools; separate from the closed control probe."""
from __future__ import annotations

import importlib.metadata
import sys
import json
import hashlib
import re
from pathlib import Path
import threading
import time
import uuid

from .processes import ProcessManager
from .safety import ACTIVE, WORKTREE, SafetyError, confined, digest, isolated_environment, now, save_json

READ_COMMANDS = frozenset({"get_state", "get_subagents", "get_available_commands",
                           "get_session_stats", "set_subagent_subscription", "abort"})

NATIVE_OMP = Path("C:/Users/josep/AppData/Local/omp/omp.exe")
NATIVE_OMP_VERSION = "18.11.1"
REUSED_PYTHON = ACTIVE / "build/isolated-workers/PrefectOmpEvaluation/build/orchestration-eval/dependencies/venv/Scripts/python.exe"


def runtime_identity_candidate() -> dict:
    """Read-only proposal, not approval or proof of the executable's version."""
    distribution = importlib.metadata.distribution("prefect")
    metadata = next(distribution.locate_file(entry) for entry in distribution.files
                    if str(entry).replace("\\", "/").endswith(".dist-info/METADATA"))
    return {"omp": {"path": str(NATIVE_OMP), "sha256": digest(NATIVE_OMP), "version": NATIVE_OMP_VERSION},
            "python": {"path": str(Path(sys.executable)), "sha256": digest(Path(sys.executable)),
                       "version": sys.version.split()[0]},
            "prefect": {"version": distribution.version, "metadata_path": str(metadata.resolve()),
                        "metadata_sha256": digest(metadata)}}


def validate_runtime_identity(executable: Path, approved: dict, *, require_version_receipt=True) -> dict:
    """Check reviewed bytes before running native code; this grants no execution."""
    try:
        omp, python, prefect = approved["omp"], approved["python"], approved["prefect"]
        for path in (executable, NATIVE_OMP, Path(sys.executable), REUSED_PYTHON):
            confined(path, path.parent)
        if (executable != NATIVE_OMP or Path(omp["path"]) != NATIVE_OMP or omp["version"] != NATIVE_OMP_VERSION or
                Path(sys.executable) != REUSED_PYTHON or Path(python["path"]) != REUSED_PYTHON):
            raise SafetyError("Unreviewed native OMP/Python path or OMP API version")
        if digest(executable) != omp["sha256"] or digest(Path(sys.executable)) != python["sha256"]:
            raise SafetyError("Approved OMP/Python binary bytes changed")
        if require_version_receipt:
            pointer = omp["version_receipt"]
            raw = confined(Path(pointer["path"]), ACTIVE / "build").read_bytes()
            if hashlib.sha256(raw).hexdigest() != pointer["sha256"]:
                raise SafetyError("Native version receipt bytes changed")
            receipt = json.loads(raw)
            proof = receipt["process"]["exit_proof"]
            if (receipt["expected"]["sha256"] != omp["sha256"] or
                    receipt["process"]["argv"] != [str(executable), "--version"] or
                    not re.search(r"\b" + re.escape(NATIVE_OMP_VERSION) + r"\b", receipt["stdout"]) or
                    not proof["observed_exit"] or proof["exit_code"] != 0):
                raise SafetyError("Approved executable lacks an actual matching owned version observation")
        distribution = importlib.metadata.distribution("prefect")
        metadata = next(distribution.locate_file(entry) for entry in distribution.files
                        if str(entry).replace("\\", "/").endswith(".dist-info/METADATA"))
        if (sys.version.split()[0] != python["version"] or distribution.version != prefect["version"] or
                str(metadata.resolve()) != str(Path(prefect["metadata_path"]).resolve()) or
                digest(metadata) != prefect["metadata_sha256"]):
            raise SafetyError("Approved Python/Prefect runtime identity changed")
        return approved
    except (KeyError, TypeError, StopIteration, importlib.metadata.PackageNotFoundError) as exc:
        raise SafetyError("Complete coordinator-approved runtime identities are required") from exc


class TrialRpc:
    """Correlate concurrent replies without discarding genuine asynchronous events.

    Every frame is retained. A broken transport kills only its owned Windows job;
    no request, session, or provider effect is retried/adopted.
    """
    def __init__(self, owned, directory: Path):
        self.owned, self.directory = owned, confined(directory)
        self.log = self.directory / "rpc.jsonl"
        self.condition, self.writer = threading.Condition(), threading.Lock()
        self.responses, self.ready, self.failure = {}, None, None
        self.closing = False
        self.reader = threading.Thread(target=self._read, daemon=True, name="bounded-native-rpc")
        self.reader.start()

    def _log(self, direction: str, frame: dict):
        with self.log.open("a", encoding="utf-8", newline="\n") as stream:
            stream.write(json.dumps({"observed_at": now(), "direction": direction, "frame": frame}) + "\n")
            stream.flush()

    def _read(self):
        try:
            while True:
                raw = self.owned.process.stdout.readline(1048577)
                if not raw:
                    if self.closing:
                        return
                    raise EOFError("Retained native OMP transport closed unexpectedly")
                if len(raw) > 1048576 or not raw.endswith(b"\n"):
                    raise SafetyError("Native v1 frame exceeded its limit; no truncation accepted")
                frame = json.loads(raw)
                if not isinstance(frame, dict):
                    raise SafetyError("Native RPC frame is not an object")
                with self.condition:
                    self._log("out", frame)
                    if frame.get("type") == "ready":
                        if self.ready is not None or frame.get("protocolVersion") != 1:
                            raise SafetyError("Unexpected native protocol/startup frame")
                        self.ready = frame
                    elif frame.get("type") == "response":
                        identifier = frame.get("id")
                        if identifier in self.responses:
                            raise SafetyError("Duplicate native response identity")
                        self.responses[identifier] = frame
                    elif frame.get("type") in {"rpc_frame_error", "host_tool_call", "host_uri_request", "extension_error"}:
                        raise SafetyError(f"Unsupported or failed native execution: {frame}")
                    self.condition.notify_all()
        except BaseException as exc:
            with self.condition:
                self.failure = exc
                self.condition.notify_all()
            proof, failure = None, None
            try:
                proof = self.owned.stop(grace=0, deadline=time.monotonic() + 5)
            except BaseException as error:
                failure = repr(error)
            save_json(self.directory / "transport-failure.json", {
                "error": repr(exc), "exit_proof": proof, "termination_error": failure, "observed_at": now()})

    def wait_ready(self, timeout=60):
        deadline = time.monotonic() + timeout
        with self.condition:
            while self.ready is None:
                if self.failure:
                    raise self.failure
                remaining = deadline - time.monotonic()
                if remaining <= 0:
                    raise TimeoutError("Native OMP startup timed out")
                self.condition.wait(remaining)
            return self.ready

    def _request(self, command: str, values: dict, *, timeout=30):
        identifier = uuid.uuid4().hex
        frame = {"id": identifier, "type": command, **values}
        deadline = time.monotonic() + timeout
        with self.writer:
            with self.condition:
                if self.failure:
                    raise self.failure
                self._log("in", frame)
            self.owned.process.stdin.write((json.dumps(frame) + "\n").encode("utf-8"))
            self.owned.process.stdin.flush()
        with self.condition:
            while identifier not in self.responses:
                if self.failure:
                    raise self.failure
                remaining = deadline - time.monotonic()
                if remaining <= 0:
                    raise TimeoutError(f"Native {command} outcome unknown; request must not be replayed")
                self.condition.wait(remaining)
            response = self.responses.pop(identifier)
        if response.get("command") != command or response.get("success") is not True:
            raise SafetyError(f"Native {command} refused: {response}")
        return response.get("data")

    def request(self, command: str, **values):
        if command not in READ_COMMANDS:
            raise SafetyError("Only observation/cancellation is available on the public RPC surface")
        return self._request(command, values)

    def local_command(self, path: Path):
        path = confined(path, self.directory)
        # Only the exact local command can traverse prompt. The native input hook
        # handles all other root input, and its provider hook refuses root calls.
        return self._request("prompt", {"message": "/bounded-trial " + str(path)})

    def close(self):
        self.closing = True
        deadline = time.monotonic() + 5
        proof = self.owned.stop(grace=0.5, deadline=deadline)
        self.reader.join(timeout=max(0, deadline - time.monotonic()))
        return proof


def model_registration(definition: dict, execution: dict) -> dict:
    """Convert a resolved native cache entry back to its model-config input."""
    model = dict(definition)
    if (model.pop("provider", None) != execution["provider"] or
            model.pop("baseUrl", None) != execution["endpoint"] or model["id"] != execution["model"]):
        raise SafetyError("Observed model registration does not equal the approved identity")
    # Resolved compatibility includes internal defaults which are not valid
    # models.yml input (for example toolStrictMode=mixed). Replay only the
    # original config, not a guessed translation of those computed defaults.
    model.pop("compat", None)
    configured = model.pop("compatConfig", None)
    if configured is not None:
        if not isinstance(configured, dict):
            raise SafetyError("Native compatibility configuration must be an object")
        model["compat"] = configured
    return model


def launch_root(manager: ProcessManager, executable: Path, directory: Path, spec: dict,
                model_definition: dict, revision: int) -> tuple[TrialRpc, dict]:
    validate_runtime_identity(executable, spec["runtime"])
    directory = confined(directory, manager.root)
    directory.mkdir(parents=True, exist_ok=False)
    session_directory = confined(Path(spec["session_directory"]), Path(spec["session_directory"]))
    if not session_directory.is_dir():
        raise SafetyError("Coordinator-approved standard native session directory is unavailable")
    environment = isolated_environment(directory)
    # Every process has its own model registration and home; no global changes,
    # inherited credentials, discovery/fallback, or user-home session adoption.
    agent_dir = Path(environment["PI_CODING_AGENT_DIR"])
    execution = spec["execution"]
    model = model_registration(model_definition, execution)
    providers = {execution["provider"]: {
        "baseUrl": execution["endpoint"], "api": model["api"], "auth": "none", "models": [model]}}
    review = spec.get("review")
    if review:
        expected = review["execution"]
        selected = model_registration(review["model_definition"], expected)
        provider = providers.setdefault(expected["provider"], {
            "baseUrl": expected["endpoint"], "api": selected["api"], "auth": "none", "models": []})
        if provider["baseUrl"] != expected["endpoint"] or provider["api"] != selected["api"]:
            raise SafetyError("One native provider cannot silently select two endpoint/API identities")
        existing = next((item for item in provider["models"] if item["id"] == selected["id"]), None)
        if existing is not None and existing != selected:
            raise SafetyError("Worker and reviewer definitions disagree for the same model")
        if existing is None:
            provider["models"].append(selected)
    save_json(agent_dir / "models.yml", {"providers": providers})
    agents = agent_dir / "agents"
    agents.mkdir()
    worker_source = Path(spec["agent_definition"]["path"])
    if digest(worker_source) != spec["agent_definition"]["sha256"]:
        raise SafetyError("Coordinator-approved native reconstruction instructions changed")
    worker_text = worker_source.read_text(encoding="utf-8")
    if not worker_text.startswith("---\n") or "\n---\n" not in worker_text:
        raise SafetyError("Native reconstruction definition lacks its expected frontmatter")
    worker_body = worker_text.split("\n---\n", 1)[1]
    (agents / "bounded-trial-worker.md").write_text(
        "---\nname: bounded-trial-worker\ndescription: One authorized matching reconstruction assignment\n"
        f"model: {execution['provider']}/{execution['model']}\n"
        "thinking: high\ntools: read, bash, edit, write, grep, glob\n---\n"
        + worker_body + "\nCurrent canonical bounded-trial overrides: do not hand off to Sol or any other model. "
        "After the inherited Qwen ten-correction bound, preserve/publish the best nonmatching draft with original-code fallback "
        "and zero accepted credit. Keep the same owner through automatic independent review, concrete reconciliation, "
        "controller-owned separate source commit/push acknowledgment, safe cleanup and verified closure. "
        "Do not send agent://Main messages: this process's "
        "Main is a zero-inference control root, not the external coordinator. Use the supplied durable receipt channel and yield. "
        "Never fabricate missing history or measurements; tool/environment failures remain blocked.\n",
        encoding="utf-8", newline="\n")
    overrides = {"bounded-trial-worker": f"{execution['provider']}/{execution['model']}"}
    if review:
        selected = review["execution"]
        overrides["bounded-trial-reviewer"] = f"{selected['provider']}/{selected['model']}"
        (agents / "bounded-trial-reviewer.md").write_text(
            "---\nname: bounded-trial-reviewer\ndescription: Independent scoped reconstruction review\n"
            f"model: {selected['provider']}/{selected['model']}\n"
            "thinking: high\ntools: read, grep, glob, write\n---\n"
            "Review only the exact supplied assignment/delivery and its explicit unresolved-criteria packet. "
            "Independently inspect source, original assembly and retained evidence only as needed for those named judgments. "
            "The controller's mandatory mechanical checks cannot be waived, replaced or broadened into another review. "
            "Do not redo already covered criteria or infer a new runtime gate from unavailable in-game execution. "
            "An exhausted NonMatching draft retains original fallback and zero accepted credit. "
            "Reject concrete findings only within the recorded unresolved scope, not unrelated repository advancement. "
            "Do not edit source or perform integration. Your only write is the exact supplied decision filename. "
            "Read the supplied native review-identity record after your preparation gate opens, and bind your JSON decision "
            "to that actual reviewer/session/action and delivery. Return reviewed_criteria listing exactly those unresolved "
            "IDs once, decision approve or reject and concrete findings (criterion,path,reason). "
            "Never manufacture acceptance, a native identity, or measurements.\n",
            encoding="utf-8", newline="\n")
    config = directory / "config.yml"
    save_json(config, {
        "autoResume": False, "autoTitle": False, "enabledProviders": [],
        "disabledProviders": ["claude", "codex", "gemini", "github", "opencode", "cursor", "agents-md"],
        "enabledModels": sorted(set(overrides.values())),
        # No auxiliary title/auto-thinking/model work. Unresolvable exact
        # selectors plus disabled fallback are checked by the native bridge.
        "modelRoles": {role: "bounded-trial-disabled/no-auxiliary-model" for role in ("tiny", "commit", "smol")},
        "providers": {"cacheWarming": "off"}, "telemetry": {"otlpExportEnabled": False},
        "advisor": {"enabled": False}, "memory": {"enabled": False, "backend": "off"},
        "compaction": {"enabled": False}, "completion": {"enabled": False}, "plan": {"defaultOnStartup": False},
        "retry": {"enabled": False, "maxRetries": 0, "modelFallback": False},
        "async": {"enabled": False}, "bash": {"autoBackground": {"enabled": False}, "direnv": "off"},
        "task": {"batch": True, "maxConcurrency": 2 if review else 1, "maxRecursionDepth": 1,
                 "agentIdleTtlMs": 0, "speculativeLaunch": False, "isolation": {"enabled": False},
                 "agentModelOverrides": overrides},
        "shellPath": "C:/Program Files/Git/bin/bash.exe", "tools": {"approvalMode": "yolo"},
    })
    spec_path = directory / "spec.json"
    save_json(spec_path, spec)
    environment.update(OMP_BOUNDED_TRIAL_SPEC=str(spec_path), OMP_BOUNDED_TRIAL_SPEC_SHA256=digest(spec_path))
    native_manager = ProcessManager(manager.root, environment, authorize=manager.authorize)
    argv = [str(executable), "--mode", "rpc", "--no-ui", "--no-extensions", "--no-title",
            "--no-skills", "--no-rules", "--no-lsp", "--no-pty", "--thinking", "high",
            "--config", str(config), "--cwd", str(ACTIVE), "--session-dir", str(session_directory),
            "--extension", str(WORKTREE / "tools/orchestration_eval/trial_native.mjs"),
            "--model", f"{execution['provider']}/{execution['model']}"]
    owned = native_manager.launch(argv, kind="omp-real-trial-root", cwd=directory, pipe=True,
                                  authorization_revision=revision)
    manager.owned[owned.process_id] = owned
    rpc = TrialRpc(owned, directory)
    try:
        rpc.wait_ready()
        state = rpc.request("get_state")
        ready = json.loads((directory / "native-ready.json").read_text(encoding="utf-8"))
        if (state.get("sessionId") != ready["root_session_id"] or
                state.get("sessionFile") != ready["root_journal"] or
                not all(tool["available"] for tool in ready["tools"]) or
                ready.get("enforceable_guard") is not True or state.get("messageCount", 0) or state.get("isStreaming")):
            raise SafetyError("Native root lacks fresh identity or required actual tools")
        confined(Path(ready["root_journal"]), session_directory)
        selected = state.get("model") or {}
        if any(selected.get(key) != execution[field] for key, field in
               (("provider", "provider"), ("id", "model"), ("baseUrl", "endpoint"))):
            raise SafetyError("Native root selected a different provider/model/endpoint")
        catalog = rpc.request("get_available_commands")
        if not any(row.get("name") == "bounded-trial" for row in catalog.get("commands", [])):
            raise SafetyError("Native bounded local command is unavailable; no prompt sent")
        rpc.request("set_subagent_subscription", level="events")
        save_json(directory / "handshake.json", {"state": state, "native": ready, "commands": catalog,
                  "executable_sha256": digest(executable), "provider_requests_sent": 0})
        return rpc, ready
    except BaseException:
        rpc.close()
        raise
