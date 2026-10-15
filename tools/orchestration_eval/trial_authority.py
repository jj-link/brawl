"""Exact coordinator approval and fresh-workspace checks; no execution authority."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

from .safety import ACTIVE, SafetyError, confined


def validate_approval(manifest: dict, contract: dict) -> dict:
    try:
        pointer = contract["approval_packet"]
        path = confined(Path(pointer["path"]), ACTIVE)
        raw = path.read_bytes()
        if hashlib.sha256(raw).hexdigest() != pointer["sha256"]:
            raise SafetyError("Coordinator approval packet changed")
        packet = json.loads(raw)
        manifest_digest = hashlib.sha256(json.dumps(manifest, sort_keys=True, separators=(",", ":"),
                                                    allow_nan=False).encode()).hexdigest()
        if (packet["manifest_digest"] != manifest_digest or packet["coordinator_id"] != manifest["coordinator_id"] or
                packet["schema"] != "brawl-qwen-trial-approval/v2"):
            raise SafetyError("Approval packet does not authorize this exact immutable manifest")
        fields = ("assignment_id", "workspace", "baseline_commit", "instruction_revision", "input_identity",
                  "recipe_ref", "owned_paths", "function")
        expected = [{key: reservation[key] for key in fields} for reservation in manifest["reservations"]]
        if packet["reservations"] != expected:
            raise SafetyError("Coordinator-approved inputs/revisions/workspaces differ from dispatch reservations")
        for key in ("runtime", "observer", "agent_definition", "session_directory", "session_store_grant_ref",
                    "preparation_grant_ref", "configuration_sha256", "model_definition",
                    "workflow_config", "review_model_definition"):
            if packet[key] != contract[key]:
                raise SafetyError(f"Coordinator approval does not bind launch identity: {key}")
        if packet["execution"] != manifest["execution"]:
            raise SafetyError("Coordinator-approved provider identity differs")
        return {"path": str(path), "sha256": pointer["sha256"], "raw_utf8": raw.decode("utf-8"), "packet": packet}
    except (KeyError, TypeError, ValueError) as exc:
        raise SafetyError("Complete actual coordinator approval packet is required") from exc


def require_fresh_workspace(reservation: dict) -> Path:
    workspace = confined(Path(reservation["workspace"]), ACTIVE / "build/isolated-workers")
    expected = ACTIVE / "build/isolated-workers" / f"QwenTrial{reservation['function']['start']:X}"
    if workspace != expected or workspace.exists() or workspace.is_symlink():
        raise SafetyError("Dispatch requires the exact absent reservation workspace and ordinary ancestors")
    return workspace
