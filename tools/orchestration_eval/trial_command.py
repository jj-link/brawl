"""Execute one controller-approved command inside an already owned Windows job.

The outer ProcessManager owns this process and all descendants. This child adds
an exact cwd/action/spec check at the final subprocess boundary; it is not a
provider client or an agent tool host.
"""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

from .evidence import reject_links
from .policy import WORKFLOW_ACTION_OPERATIONS, require_allowed
from .safety import SafetyError, confined, now, save_json
from .state import read_snapshot


def authorize_command(spec):
    doc = read_snapshot(Path(spec["ledger_path"]))
    auth = doc["authorization"]
    if auth["revision"] != spec["authorization_revision"]:
        raise SafetyError("Owned command admission was revoked before subprocess creation")
    workflow = doc["trial"]["workflow"]
    if workflow["config_digest"] != spec["config_digest"]:
        raise SafetyError("Immutable workflow configuration changed")
    action = workflow["actions"].get(spec["effect_id"])
    if (action is None or action["status"] != "admitted"
            or action["authorization_revision"] != auth["revision"]
            or action["binding"] != spec["binding"]):
        raise SafetyError("Command lacks its exact admitted lifecycle effect")
    require_allowed(auth["mode"], WORKFLOW_ACTION_OPERATIONS[action["kind"]])
    allowed = {Path(workflow["config"]["publication_target"]["repository"]).resolve(),
               Path(spec["run_root"]).resolve()}
    if action["assignment_id"] is not None:
        assignment = doc["assignments"][action["assignment_id"]]
        allowed.add(Path(assignment["identity"]["reservation"]["workspace"]).resolve())
    elif action["kind"] != "prepare_target":
        raise SafetyError("Only exact target preparation may execute without an assignment")
    cwd = Path(spec["cwd"])
    reject_links(cwd)
    if not cwd.is_absolute() or cwd.resolve() not in allowed or not cwd.is_dir():
        raise SafetyError("Command cwd is not this action's exact owned repository/workspace")
    return doc


def main(argv=None):
    args = sys.argv[1:] if argv is None else argv
    if len(args) != 2:
        raise SafetyError("Owned command requires an immutable spec path and digest")
    spec_path = confined(Path(args[0]))
    raw = spec_path.read_bytes()
    if hashlib.sha256(raw).hexdigest() != args[1]:
        raise SafetyError("Owned command specification bytes changed")
    spec = json.loads(raw)
    directory = confined(spec_path.parent, Path(spec["run_root"]))
    environment = {key: value for key, value in os.environ.items() if not key.upper().startswith("GIT_")}
    environment.update(spec["environment"])
    stdin = None
    if spec.get("stdin"):
        path = confined(Path(spec["stdin"]["path"]), directory)
        if hashlib.sha256(path.read_bytes()).hexdigest() != spec["stdin"]["sha256"]:
            raise SafetyError("Owned command stdin changed")
        stdin = path.open("rb")
    result = {"argv": spec["argv"], "cwd": spec["cwd"], "effect_id": spec["effect_id"],
              "binding": spec["binding"], "started_at": now(), "returncode": None}
    try:
        with (directory / "stdout.bin").open("xb") as stdout, (directory / "stderr.bin").open("xb") as stderr:
            authorize_command(spec)
            process = subprocess.Popen(spec["argv"], cwd=spec["cwd"], env=environment,
                stdin=stdin or subprocess.DEVNULL, stdout=stdout, stderr=stderr,
                creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
            result["pid"] = process.pid
            if os.name == "nt":
                from .processes import creation_time, kernel
                result["creation_time"] = creation_time(kernel(), int(process._handle))
            save_json(directory / "command-started.json", result)
            try:
                result["returncode"] = process.wait(timeout=spec["timeout_seconds"])
            except subprocess.TimeoutExpired:
                # The owning runtime terminates the entire job, not only this
                # parent PID, when the missing final receipt raises uncertainty.
                result["error"] = "Owned command deadline expired; full job termination required"
                raise
    finally:
        if stdin is not None:
            stdin.close()
        result["observed_at"] = now()
        save_json(directory / "command-result.json", result)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        print(str(error), file=sys.stderr)
        raise SystemExit(1)
