"""Own-only deliveries observed at a genuine native owner turn boundary.

A delivery is data, not approval. These checks establish immutable source/input
bindings; required command checks and independent substantive review remain
separate controller actions.
"""
from __future__ import annotations

from dataclasses import dataclass
import hashlib
import json
import os
from pathlib import Path
import re

from .evidence import (InputError, InputManifest, canonical_json, content_identity,
                       file_identity, input_path, relative_path, validate_inputs)
from .safety import confined


class DeliveryError(ValueError):
    def __init__(self, reason, *, capture=None):
        super().__init__(reason)
        self.capture = capture


def _hex(value, length):
    return isinstance(value, str) and re.fullmatch(r"[0-9a-f]{%d}" % length, value) is not None


def _identity(value):
    if (not isinstance(value, dict) or set(value) != {"sha256", "size"}
            or not _hex(value["sha256"], 64) or type(value["size"]) is not int or value["size"] < 0):
        raise DeliveryError("A file binding requires its exact SHA-256 and byte count")


def _entry(value, *, optional=False):
    if optional and value is None:
        return
    if (not isinstance(value, dict) or set(value) != {"mode", "blob"}
            or value["mode"] != "100644" or not _hex(value["blob"], 40)):
        raise DeliveryError("Only regular own-only source Git entries are permitted")


@dataclass(frozen=True)
class WorkerDelivery:
    payload_json: str
    delivery_id: str

    @property
    def payload(self):
        return json.loads(self.payload_json)

    @property
    def source_identity(self):
        return content_identity(self.payload["changes"])

    @classmethod
    def from_dict(cls, value):
        required = {"schema", "assignment_id", "owner_id", "session_id", "manifest_digest",
                    "candidate_id", "inputs", "changes", "artifacts", "logical_units", "cleanup"}
        if not isinstance(value, dict) or set(value) != required or value["schema"] != 1:
            raise DeliveryError("Unsupported concrete worker delivery")
        for key in ("assignment_id", "owner_id", "session_id", "candidate_id"):
            if not isinstance(value[key], str) or not value[key].strip():
                raise DeliveryError("Missing exact worker/candidate identity")
        if not _hex(value["manifest_digest"], 64):
            raise DeliveryError("Missing immutable manifest identity")
        inputs = InputManifest.from_dict(value["inputs"])
        changes = value["changes"]
        if not isinstance(changes, dict) or not changes:
            raise DeliveryError("Delivery has no own-only changes")
        folded = set()
        for path, change in changes.items():
            relative_path(path)
            if path.casefold() in folded or path not in inputs.paths:
                raise DeliveryError("Every distinct changed path must be a verified relevant input")
            folded.add(path.casefold())
            if not isinstance(change, dict) or set(change) != {"before", "after", "raw"}:
                raise DeliveryError("Changes bind committed preimage, intended Git entry and raw postimage")
            _entry(change["before"], optional=True)
            _entry(change["after"])
            _identity(change["raw"])
        units = value["logical_units"]
        if not isinstance(units, list) or not units:
            raise DeliveryError("Separate logical publication units must be explicit")
        published = []
        for unit in units:
            if (not isinstance(unit, dict) or set(unit) != {"message", "paths"}
                    or not isinstance(unit["message"], str) or not unit["message"].strip()
                    or not isinstance(unit["paths"], list) or not unit["paths"]
                    or not all(isinstance(path, str) for path in unit["paths"])):
                raise DeliveryError("Each logical unit needs its own commit message and exact paths")
            published.extend(unit["paths"])
        if len(published) != len(set(published)) or set(published) != set(changes):
            raise DeliveryError("Each delivered path belongs to exactly one logical commit")
        artifacts = value["artifacts"]
        required_artifacts = {"compile", "object_compare", "data_relocations", "source_link",
                              "binary_hashes", "progress"}
        if not isinstance(artifacts, dict) or set(artifacts) != required_artifacts:
            raise DeliveryError("All fixed reconstruction evidence categories must be retained")
        for artifact in artifacts.values():
            if not isinstance(artifact, dict) or set(artifact) != {"path", "identity"}:
                raise DeliveryError("Artifacts require a relative regular file and byte identity")
            relative_path(artifact["path"])
            _identity(artifact["identity"])
        cleanup = value["cleanup"]
        if not isinstance(cleanup, list):
            raise DeliveryError("Disposable files must be an explicit list, including an empty list")
        disposable = set()
        retained = set(inputs.paths) | {artifact["path"] for artifact in artifacts.values()}
        for item in cleanup:
            if not isinstance(item, dict) or set(item) != {"path", "identity"}:
                raise DeliveryError("Disposable files require exact path and content identity")
            relative_path(item["path"])
            _identity(item["identity"])
            folded_path = item["path"].casefold()
            if folded_path in disposable or folded_path in {path.casefold() for path in retained}:
                raise DeliveryError("Cleanup cannot include retained inputs/evidence or duplicate paths")
            disposable.add(folded_path)
        payload = canonical_json(value)
        return cls(payload, content_identity(value))


def observe_delivery(workspace, path, *, assignment, manifest_digest, native_event, archive_directory):
    """Archive actual owner bytes before interpreting this untrusted delivery."""
    if (native_event.get("kind") != "owner_turn_end" or native_event.get("will_continue") is not False
            or native_event.get("registry_id") != assignment["owner_id"]
            or native_event.get("session_id") != assignment["session_id"]):
        raise DeliveryError("A worker file alone is not a genuine retained-owner delivery")
    file = input_path(Path(workspace), path)
    raw = file.read_bytes()
    sha256 = hashlib.sha256(raw).hexdigest()
    directory = confined(Path(archive_directory))
    directory.mkdir(parents=True, exist_ok=True)
    archive = input_path(directory, sha256 + ".json", must_exist=False)
    try:
        with archive.open("xb") as stream:
            stream.write(raw)
            stream.flush()
            os.fsync(stream.fileno())
    except FileExistsError:
        if archive.read_bytes() != raw:
            raise DeliveryError("Retained raw delivery archive differs; preserve the incomplete/conflicting capture")
    captured = {"path": str(archive), "original_path": str(file), "sha256": sha256,
                "size": len(raw), "native_event": native_event}
    try:
        delivery = WorkerDelivery.from_dict(json.loads(raw))
        payload = delivery.payload
        expected = {"assignment_id": assignment["assignment_id"], "owner_id": assignment["owner_id"],
                    "session_id": assignment["session_id"], "manifest_digest": manifest_digest}
        if any(payload[key] != value for key, value in expected.items()):
            raise DeliveryError("Delivery belongs to a different reserved owner/session/manifest")
        reservation = assignment["identity"]["reservation"]
        if not set(payload["changes"]).issubset(set(reservation["owned_paths"])):
            raise DeliveryError("Delivery changes paths outside the reserved source/registration scope")
        candidates = [stage["candidates"][payload["candidate_id"]] for stage in assignment["stages"]
                      if payload["candidate_id"] in stage["candidates"]]
        if len(candidates) != 1 or candidates[0]["input_identity"] != payload["inputs"]["identity"]:
            raise DeliveryError("Delivery does not identify one preserved measured candidate and its inputs")
        if file.read_bytes() != raw:
            raise DeliveryError("Delivery changed while being captured")
    except (ValueError, OSError) as error:
        raise DeliveryError(str(error), capture=captured) from error
    return delivery, captured


def validate_delivery_files(workspace, delivery):
    """Recheck immutable dependencies and actual source/evidence/disposable bytes."""
    workspace = Path(workspace)
    payload = delivery.payload
    inputs = InputManifest.from_dict(payload["inputs"])
    validation = validate_inputs(workspace, inputs)
    if not validation.valid:
        raise DeliveryError(f"Relevant delivery inputs changed: {validation.changed}")
    for path, change in payload["changes"].items():
        if file_identity(input_path(workspace, path)) != change["raw"]:
            raise DeliveryError(f"Raw source postimage changed: {path}")
    for artifact in payload["artifacts"].values():
        if file_identity(input_path(workspace, artifact["path"])) != artifact["identity"]:
            raise DeliveryError(f"Retained evidence changed: {artifact['path']}")
    for item in payload["cleanup"]:
        if file_identity(input_path(workspace, item["path"])) != item["identity"]:
            raise DeliveryError(f"Disposable file changed before authorization: {item['path']}")
    return {"delivery_id": delivery.delivery_id, "source_identity": delivery.source_identity,
            "input_identity": inputs.identity, "paths": sorted(payload["changes"])}


def verify_binary_hashes(workspace, expected):
    """Recompute all canonical native binary hashes; counts or claimed logs cannot pass."""
    if not isinstance(expected, dict) or len(expected) != 127:
        raise DeliveryError("The approved verification contract must identify all 127 binaries")
    if not all(isinstance(path, str) for path in expected) or len({path.casefold() for path in expected}) != 127:
        raise DeliveryError("Native binary coverage requires 127 distinct Windows paths")
    rows = []
    identities = set()
    for path, wanted in expected.items():
        if not _hex(wanted, 40):
            raise DeliveryError("Canonical binary expectations require SHA-1 identities")
        actual = hashlib.sha1()
        with input_path(Path(workspace), path).open("rb") as stream:
            stat = os.fstat(stream.fileno())
            identity = (stat.st_dev, stat.st_ino)
            if identity in identities:
                raise DeliveryError("Native binary paths alias the same physical file")
            identities.add(identity)
            for chunk in iter(lambda: stream.read(1024 * 1024), b""):
                actual.update(chunk)
        observed = actual.hexdigest()
        if observed != wanted:
            raise DeliveryError(f"Native binary hash mismatch: {path}")
        rows.append({"path": path, "expected": wanted, "observed": observed})
    return rows
