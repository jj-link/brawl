"""Owned, receipt-producing OS commands for automatic lifecycle actions."""
from __future__ import annotations

from dataclasses import dataclass
import json
import os
from pathlib import Path
import re
import sys
import time
import uuid

from .policy import WORKFLOW_ACTION_OPERATIONS
from .processes import ProcessManager
from .safety import SafetyError, confined, digest, save_json


@dataclass(frozen=True)
class CommandResult:
    returncode: int
    stdout: bytes
    stderr: bytes
    receipt: Path
    process_id: str

    def text(self):
        return self.stdout.decode("utf-8").strip()


class OwnedCommands:
    def __init__(self, runtime):
        self.runtime = runtime

    def run(self, action, argv, *, cwd, data=None, environment=None, timeout=120, check=True):
        if not isinstance(argv, list) or not argv or any(not isinstance(arg, str) or "\0" in arg for arg in argv):
            raise SafetyError("An owned command requires explicit native argv, never a shell string")
        effect_id = action["effect_id"]
        if not re.fullmatch(r"[A-Za-z0-9-]{1,100}", effect_id):
            raise SafetyError("Unsafe workflow effect identity")
        current = self.runtime.ledger.snapshot()
        if current["trial"]["workflow"]["actions"].get(effect_id) != action or action["status"] != "admitted":
            raise SafetyError("Command action changed before process admission")
        revision = action["authorization_revision"]
        operation = WORKFLOW_ACTION_OPERATIONS[action["kind"]]
        self.runtime.ledger.require_operation(operation, authorization_revision=revision)
        directory = confined(self.runtime.root / "workflow" / effect_id / "commands" / uuid.uuid4().hex,
                             self.runtime.root)
        directory.mkdir(parents=True, exist_ok=False)
        extra = {"GIT_CONFIG_GLOBAL": os.devnull, "GIT_CONFIG_NOSYSTEM": "1",
                 "GIT_TERMINAL_PROMPT": "0", "GIT_OPTIONAL_LOCKS": "0"}
        extra.update(environment or {})
        spec = {"run_root": str(self.runtime.root), "ledger_path": str(self.runtime.ledger.path),
                "config_digest": current["trial"]["workflow"]["config_digest"],
                "effect_id": effect_id, "binding": action["binding"], "authorization_revision": revision,
                "argv": argv, "cwd": str(Path(cwd)), "environment": extra,
                "timeout_seconds": timeout, "stdin": None}
        if data is not None:
            path = directory / "stdin.bin"
            with path.open("xb") as stream:
                stream.write(data)
            spec["stdin"] = {"path": str(path), "sha256": digest(path)}
        spec_path = directory / "command.json"
        save_json(spec_path, spec)
        manager = ProcessManager(self.runtime.root, self.runtime.environment,
                                 authorize=self.runtime.manager.authorize)
        owned = manager.launch([sys.executable, "-B", "-m", "tools.orchestration_eval.trial_command",
                                str(spec_path), digest(spec_path)],
                               kind="workflow-" + action["kind"], cwd=self.runtime.root,
                               authorization_revision=revision, operation=operation)
        self.runtime.manager.owned[owned.process_id] = owned
        try:
            self.runtime.register_process(owned, revision, operation=operation)
            wrapper_exit = owned.process.wait(timeout=timeout + 10)
            path = directory / "command-result.json"
            if not path.is_file():
                raise SafetyError(f"Command outcome is uncertain; retain owned process {owned.process_id}")
            result = json.loads(path.read_text(encoding="utf-8"))
            if wrapper_exit != 0 or type(result.get("returncode")) is not int:
                raise SafetyError(f"Command did not establish a final native outcome: {path}")
            value = CommandResult(result["returncode"], (directory / "stdout.bin").read_bytes(),
                                  (directory / "stderr.bin").read_bytes(), path, owned.process_id)
            if check and value.returncode != 0:
                raise SafetyError(f"Owned command failed ({value.returncode}); actual evidence {path}")
            return value
        finally:
            proof = owned.stop(grace=0, deadline=time.monotonic() + 5)
            if owned.process_id in self.runtime.ledger.snapshot()["processes"]:
                self.runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
