"""Require native executor settlement and command outcome, not an early agent_end."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

from .evidence import input_path
from .safety import SafetyError


def completion(native, journal):
    proof = native.get("native_completion")
    if not isinstance(proof, dict) or proof.get("source") != "native-task-finalization":
        raise SafetyError("Native completion lacks finalized task and command evidence")
    directory = Path(journal).parent
    values = {}
    for name in ("lifecycle", "command_result"):
        reference = proof.get(name + "_ref")
        if not isinstance(reference, str):
            raise SafetyError("Native completion evidence reference is missing")
        try:
            relative = Path(reference).absolute().relative_to(directory.absolute()).as_posix()
        except ValueError as error:
            raise SafetyError("Native completion evidence escaped its owned journal directory") from error
        path = input_path(directory, relative)
        raw = path.read_bytes()
        if hashlib.sha256(raw).hexdigest() != proof.get(name + "_sha256"):
            raise SafetyError("Native completion evidence bytes changed")
        value = json.loads(raw)
        if not isinstance(value, dict):
            raise SafetyError("Native completion evidence must be an object")
        values[name] = value
    lifecycle, command = values["lifecycle"], values["command_result"]
    payload = lifecycle.get("payload")
    if (lifecycle.get("request_id") != native.get("request_id") or not isinstance(payload, dict)
            or payload.get("id") != native.get("registry_id")
            or payload.get("sessionFile") != native.get("journal_ref")
            or payload.get("status") not in {"completed", "failed", "aborted"}):
        raise SafetyError("Native finalization substituted its dispatch or actual session")
    if (command.get("id") != proof.get("command_id")
            or command.get("workflow_effect_id") != native.get("request_id")
            or command.get("operation") not in {"launch", "prepare-review", "review", "owner-action"}
            or type(command.get("task_result_required")) is not bool
            or type(command.get("success")) is not bool):
        raise SafetyError("Native command result does not bind the finalized dispatch")
    if command["success"]:
        result = command.get("result")
        if not isinstance(result, dict) or result.get("isError"):
            raise SafetyError("Successful native command has no successful actual result")
        if command["task_result_required"]:
            details = result.get("details")
            rows = details.get("results") if isinstance(details, dict) else None
            if (not isinstance(rows, list) or len(rows) != 1 or not isinstance(rows[0], dict)
                    or type(rows[0].get("exitCode")) is not int or rows[0]["exitCode"] != 0
                    or rows[0].get("aborted") is not False):
                raise SafetyError("Native task success lacks its single successful non-aborted child exit")
    success = command["success"] and payload["status"] == "completed"
    if type(proof.get("success")) is not bool or proof["success"] != success:
        raise SafetyError("Native terminal success differs from actual executor and command outcomes")
    return success


def review_decision(path, action):
    raw = Path(path).read_bytes()
    value = json.loads(raw)
    expected = {"delivery_id": action["binding"]["delivery_id"], "effect_id": action["effect_id"],
                "reviewer_id": action["reviewer"]["owner_id"], "session_id": action["reviewer"]["session_id"]}
    if not isinstance(value, dict) or any(value.get(name) != wanted for name, wanted in expected.items()):
        raise SafetyError("Actual review decision must be an object with its exact native identity and delivery")
    findings = value.get("findings")
    if (value.get("decision") not in ("approve", "reject") or not isinstance(findings, list)
            or any(not isinstance(item, dict) or any(not isinstance(item.get(name), str)
                   for name in ("criterion", "path", "reason")) for item in findings)):
        raise SafetyError("Actual review decision requires approve/reject and typed concrete findings")
    return {"decision": value["decision"], "findings": findings,
            "decision_file": {"path": str(path), "sha256": hashlib.sha256(raw).hexdigest()}}
