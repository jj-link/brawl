"""One admitted CARDS grant; exact owned rows, never a general registry writer."""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import uuid

from .evidence import reject_links
from .processes import runtime_lock
from .safety import ACTIVE, SafetyError, confined, now, save_json
from .trial_identity import journal_header, native_process_identity


def retain(path, raw):
    path = confined(path)
    reject_links(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    try:
        with path.open("xb") as stream:
            stream.write(raw)
            stream.flush()
            os.fsync(stream.fileno())
    except FileExistsError:
        if path.read_bytes() != raw:
            raise SafetyError("Immutable registration ownership evidence changed")
    return path


def encoded(value):
    return (json.dumps(value, sort_keys=True, allow_nan=False) + "\n").encode()


class RegistrationAdapter:
    def __init__(self, runtime):
        self.runtime = runtime
        self.root = runtime.root / "registrations"

    def validate_grant(self, value):
        trial = self.runtime.ledger.snapshot()["trial"]
        manifest = trial["manifest"]
        if (not isinstance(value, dict) or value.get("schema") != "brawl-controller-registration-grant/v1"
                or value.get("run_id") != self.runtime.root.name
                or value.get("manifest_digest") != trial["manifest_digest"]
                or value.get("controller_id") != manifest["coordinator_id"]
                or value.get("writer_boundary") != "all-registry-writers-share-lock"
                or not isinstance(value.get("owner_id"), str) or not value["owner_id"]):
            raise SafetyError("Registration grant lacks exact run/controller and cooperative writer authority")
        keys = [row["assignment_id"] for row in manifest["reservations"]]
        if value.get("assignment_ids") != keys or len(keys) != 8:
            raise SafetyError("Registration grant must bind the immutable eight assignments in order")
        slots = value.get("slots")
        if not isinstance(slots, list) or len(slots) != 4:
            raise SafetyError("Registration grant requires exactly four independently owned slot ports")
        roots, ports = set(), set()
        for index, slot in enumerate(slots):
            if (not isinstance(slot, dict) or type(slot.get("slot")) is not int or slot["slot"] != index
                    or slot.get("initial_assignment_id") != keys[index]
                    or type(slot.get("port")) is not int or not 1 <= slot["port"] <= 65535
                    or slot["port"] in {8765, 8766} or slot["port"] in ports
                    or type(slot.get("initial_native_pid")) is not int or slot["initial_native_pid"] <= 0
                    or not isinstance(slot.get("initial_native_creation_time"), str)
                    or not slot["initial_native_creation_time"].isdigit()):
                raise SafetyError("Registration grant has invalid or overlapping slot/native identities")
            try:
                identifier = str(uuid.UUID(slot["initial_root_session_id"]))
            except (KeyError, TypeError, ValueError) as error:
                raise SafetyError("Registration grant requires genuine initial root UUIDs") from error
            if identifier != slot["initial_root_session_id"] or identifier in roots:
                raise SafetyError("Registration initial root identities must be canonical and distinct")
            roots.add(identifier)
            ports.add(slot["port"])
        for name in ("registry_path", "lock_directory"):
            if not isinstance(value.get(name), str) or not Path(value[name]).is_absolute():
                raise SafetyError("Registration grant paths must be exact absolute paths")
            reject_links(Path(value[name]))
        registry = confined(Path(value["registry_path"]), ACTIVE)
        lock = confined(Path(value["lock_directory"]), registry.parent)
        if lock == registry or lock == registry.parent:
            raise SafetyError("Registration lock requires its separately scoped directory")
        return value

    def grant(self):
        path = self.root / "grant.json"
        if not path.is_file():
            raise SafetyError("Missing one-time scoped registration grant; refill cannot wait for manual rows")
        raw = path.read_bytes()
        binding = json.loads((self.root / "grant-admission.json").read_bytes())
        admitted = self.runtime.ledger.trial_delivery(binding["event_id"])
        pointer = admitted["envelope"].get("payload", {}).get("registration_grant")
        if (admitted["role"] != "coordinator" or admitted["consumed_at"] is None
                or admitted["envelope"].get("operation") != "observe"
                or pointer != binding["pointer"] or hashlib.sha256(raw).hexdigest() != pointer["sha256"]):
            raise SafetyError("Retained registration grant lost its exact consumed coordinator admission")
        return self.validate_grant(json.loads(raw))

    def bind(self, pointer, event_id):
        if not isinstance(pointer, dict) or set(pointer) != {"path", "sha256"}:
            raise SafetyError("Initial observer activation requires the exact scoped registration grant pointer")
        path = confined(Path(pointer["path"]), ACTIVE)
        reject_links(path)
        raw = path.read_bytes()
        if hashlib.sha256(raw).hexdigest() != pointer["sha256"]:
            raise SafetyError("Registration grant bytes differ from coordinator admission")
        grant = self.validate_grant(json.loads(raw))
        expected = Path(self.runtime.launch_contract["observer"]["registration"]).absolute()
        if Path(grant["registry_path"]).absolute() != expected:
            raise SafetyError("Registration grant escaped the approved original observer registry")
        for slot in grant["slots"]:
            ready = self.runtime.ready[slot["initial_assignment_id"]]
            self.identity(slot["initial_assignment_id"])
            if (ready["root_session_id"] != slot["initial_root_session_id"]
                    or ready["native_process"]["pid"] != slot["initial_native_pid"]
                    or ready["native_process"]["creation_time"] != slot["initial_native_creation_time"]):
                raise SafetyError("CARDS grant does not name all four actually prepared native roots")
        retain(self.root / "grant.json", raw)
        binding = self.root / "grant-admission.json"
        if not binding.exists():
            retain(binding, encoded({"event_id": event_id, "pointer": pointer}))
        return self.grant()

    def identity(self, key):
        runtime = self.runtime
        ready, rpc = runtime.ready[key], runtime.roots[key]
        native = ready["native_process"]
        actual = native_process_identity(rpc.owned, native["pid"], runtime.executable,
                                         expected_creation=native["creation_time"])
        if (ready["pid"] != actual["pid"] or native["host_pid"] != rpc.owned.record["pid"]
                or native["token"] != rpc.owned.record["token"]):
            raise SafetyError("Native registration identity escaped its actual wrapper/job ancestry")
        reject_links(Path(ready["root_journal"]))
        header = journal_header(Path(ready["root_journal"]))
        if (header["id"] != ready["root_session_id"] or Path(header.get("cwd", "")) != ACTIVE
                or Path(ready["root_journal"]).parent != Path(runtime.launch_contract["session_directory"])):
            raise SafetyError("Registration requires the actual original-project standard-store root journal")
        handshake = json.loads((rpc.directory / "handshake.json").read_bytes())
        if (handshake["state"]["sessionId"] != ready["root_session_id"]
                or handshake["native"]["root_session_id"] != ready["root_session_id"]
                or handshake["native"]["pid"] != actual["pid"]
                or handshake["executable_sha256"] != runtime.launch_contract["runtime"]["omp"]["sha256"]):
            raise SafetyError("Native handshake and prepared journal UUID disagree")
        return dict(actual, process_id=rpc.owned.process_id, root_session_id=ready["root_session_id"],
                    root_journal=ready["root_journal"])

    def read_registry(self, grant):
        path = Path(grant["registry_path"])
        reject_links(path)
        raw = path.read_bytes()
        value = json.loads(raw)
        if not isinstance(value, dict) or not isinstance(value.get("sessions"), list):
            raise SafetyError("Observer registry must preserve its existing sessions object")
        roots, ports = set(), set()
        for row in value["sessions"]:
            if not isinstance(row, dict):
                raise SafetyError("Malformed existing observer registry row")
            try:
                identifier = str(uuid.UUID(row["id"]))
            except (KeyError, TypeError, ValueError) as error:
                raise SafetyError("Malformed existing observer root UUID") from error
            port = row.get("observerPort")
            if (identifier != row["id"] or identifier in roots or type(port) is not int
                    or not 1 <= port <= 65535 or port in ports or port in {8765, 8766}):
                raise SafetyError("Observer registry contains invalid or overlapping identities/ports")
            roots.add(identifier)
            ports.add(port)
        return path, raw, value

    def publish(self, grant, before, after, key, operation):
        path = Path(grant["registry_path"])
        identifier = uuid.uuid4().hex
        directory = self.root / key / identifier
        retain(directory / "before.json", before)
        raw = encoded(after)
        retain(directory / "after.json", raw)
        retain(directory / "intent.json", encoded({"operation": operation, "registry": str(path),
            "grant_sha256": hashlib.sha256((self.root / "grant.json").read_bytes()).hexdigest(),
            "before_sha256": hashlib.sha256(before).hexdigest(), "after_sha256": hashlib.sha256(raw).hexdigest(),
            "observed_at": now()}))
        reject_links(path)
        if path.read_bytes() != before:
            raise SafetyError("Observer registry changed despite its granted writer lock")
        pending = path.with_name(path.name + "." + self.runtime.root.name + "." + identifier + ".pending")
        reject_links(pending)
        with pending.open("xb") as stream:
            stream.write(raw)
            stream.flush()
            os.fsync(stream.fileno())
        reject_links(path)
        if path.read_bytes() != before:
            raise SafetyError("Observer registry changed before atomic publication; pending bytes retained")
        os.replace(pending, path)
        if path.read_bytes() != raw:
            raise SafetyError("Published observer registration differs from its exact intended postimage")
        retain(directory / "complete.json", encoded({"observed_at": now(), "postimage_verified": True}))

    def register(self, key):
        grant = self.grant()
        if key not in grant["assignment_ids"]:
            raise SafetyError("Registration assignment is outside the eight-target grant")
        slot = grant["slots"][self.runtime.slots[key]]
        revision = self.runtime.ledger.authorization()["revision"]
        with runtime_lock(self.runtime.root / "process-admission", timeout=1):
            self.runtime.ledger.require_operation("launch", authorization_revision=revision)
            reject_links(Path(grant["lock_directory"]))
            with runtime_lock(Path(grant["lock_directory"]), scope=Path(grant["lock_directory"]), timeout=1):
                self.runtime.ledger.require_operation("launch", authorization_revision=revision)
                snapshot = self.runtime.ledger.snapshot()
                if key != slot["initial_assignment_id"]:
                    predecessors = [assignment for assignment, claim in snapshot["trial"]["claims"].items()
                                    if claim["slot"] == slot["slot"] and assignment != key]
                    if not predecessors or any(snapshot["assignments"][item]["status"] != "closed"
                                               for item in predecessors):
                        raise SafetyError("Refill registration requires a durably closed preceding slot owner")
                identity = self.identity(key)
                if key == slot["initial_assignment_id"] and any(identity[name] != slot[bound] for name, bound in (
                        ("root_session_id", "initial_root_session_id"), ("pid", "initial_native_pid"),
                        ("creation_time", "initial_native_creation_time"))):
                    raise SafetyError("Initial registration substituted its granted actual native root")
                path, raw, registry = self.read_registry(grant)
                existing = [row for row in registry["sessions"] if row["id"] == identity["root_session_id"]]
                tag = dict(identity, run_id=self.runtime.root.name, controller_id=grant["controller_id"],
                           assignment_id=key, slot=slot["slot"])
                row = {"id": identity["root_session_id"], "label": "trial-" + key,
                       "observerPort": slot["port"], "controllerTrial": tag}
                if existing:
                    prior = existing[0]
                    if prior.get("controllerTrial") == tag:
                        row = prior
                    elif (key == slot["initial_assignment_id"] and prior["id"] == slot["initial_root_session_id"]
                          and prior["observerPort"] == slot["port"] and "controllerTrial" not in prior
                          and isinstance(prior.get("label"), str) and prior["label"].strip().lower() != "main"):
                        row = dict(prior, controllerTrial=tag)
                    else:
                        raise SafetyError("Existing registration is not the exact granted initial or owned row")
                if any(item["observerPort"] == slot["port"] and item["id"] != row["id"] for item in registry["sessions"]):
                    raise SafetyError("Granted refill port remains occupied by another registration")
                ownership = {"row": row, "process_id": identity["process_id"], "grant_sha256":
                             hashlib.sha256((self.root / "grant.json").read_bytes()).hexdigest()}
                retain(self.root / key / "owned-row.json", encoded(ownership))
                registry["sessions"] = [row if item["id"] == row["id"] else item for item in registry["sessions"]]
                if not existing:
                    registry["sessions"].append(row)
                self.runtime.ledger.require_operation("launch", authorization_revision=revision)
                self.publish(grant, raw, registry, key, "register")
                return slot["port"]

    def close(self, key, proof, *, timeout=1):
        ownership_path = self.root / key / "owned-row.json"
        if not ownership_path.exists():
            return {"registered": False}
        grant = self.grant()
        ownership = json.loads(ownership_path.read_bytes())
        tag = ownership.get("row", {}).get("controllerTrial", {})
        if (key not in grant["assignment_ids"] or tag.get("assignment_id") != key
                or tag.get("run_id") != self.runtime.root.name
                or tag.get("controller_id") != grant["controller_id"]
                or tag.get("process_id") != ownership.get("process_id")
                or ownership.get("grant_sha256") != hashlib.sha256((self.root / "grant.json").read_bytes()).hexdigest()):
            raise SafetyError("Registration closure ownership does not bind this exact grant/run/assignment")
        expected = self.runtime.ledger.snapshot()["processes"].get(ownership["process_id"])
        if (not isinstance(proof, dict) or expected is None or expected.get("exit_proof") != proof
                or proof.get("observed_exit") is not True
                or proof.get("process_id") != ownership["process_id"]):
            raise SafetyError("Registration closure requires its actual verified owned-job exit")
        reject_links(Path(grant["lock_directory"]))
        with runtime_lock(Path(grant["lock_directory"]), scope=Path(grant["lock_directory"]), timeout=timeout):
            path, raw, registry = self.read_registry(grant)
            row = ownership["row"]
            matches = [item for item in registry["sessions"] if item["id"] == row["id"]]
            if matches and matches != [row]:
                raise SafetyError("Owned observer row changed; closure must preserve the foreign edit")
            if matches:
                registry["sessions"] = [item for item in registry["sessions"] if item["id"] != row["id"]]
                self.publish(grant, raw, registry, key, "close")
            result = {"row_absent": True, "exit_evidence_ref": proof["evidence_ref"], "observed_at": now()}
            save_json(self.root / key / "closed.json", result)
            return result

    def close_exited(self):
        outcomes = []
        for path in self.root.glob("*/owned-row.json"):
            key = path.parent.name
            try:
                ownership = json.loads(path.read_bytes())
                proof = self.runtime.ledger.snapshot()["processes"][ownership["process_id"]]["exit_proof"]
                outcomes.append({"assignment_id": key, "result": self.close(key, proof, timeout=0)})
            except (OSError, ValueError, RuntimeError, KeyError, TypeError) as error:
                outcomes.append({"assignment_id": key, "error": repr(error)})
        if outcomes:
            save_json(self.root / ("closure-" + uuid.uuid4().hex + ".json"), {"outcomes": outcomes})
        return outcomes
