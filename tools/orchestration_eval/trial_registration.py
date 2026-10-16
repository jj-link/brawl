"""Controller-owned root rows with native atomic conflict detection, not writer promises."""
from __future__ import annotations

import ctypes
from ctypes import wintypes
import hashlib
import json
import os
from pathlib import Path
import socket
import time
import uuid

from .evidence import reject_links
from .processes import runtime_lock
from .safety import ACTIVE, SafetyError, confined, now, save_json
from .trial_identity import journal_header, native_process_identity


class RegistryConflict(SafetyError):
    """A real writer or port conflict; reread before another bounded attempt."""


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


def registration_scope(manifest, registry):
    return {"mode": "controller-owned-v1", "registry_path": str(Path(registry)), "slots": 4,
            "assignment_ids": [row["assignment_id"] for row in manifest["reservations"]]}


class FileInformation(ctypes.Structure):
    _fields_ = [("attributes", wintypes.DWORD), ("created", wintypes.FILETIME),
                ("accessed", wintypes.FILETIME), ("written", wintypes.FILETIME),
                ("volume", wintypes.DWORD), ("size_high", wintypes.DWORD),
                ("size_low", wintypes.DWORD), ("links", wintypes.DWORD),
                ("index_high", wintypes.DWORD), ("index_low", wintypes.DWORD)]


def atomic_registry_update(path, before, after, authorize):
    """NTFS commits publish a complete view; ordinary writers need not share a lock.

    TxF is a native-Windows capability, not a portable fallback. Unsupported volumes
    fail closed. See Microsoft 'Programming Considerations for Transactional NTFS'.
    """
    if os.name != "nt" or len(after) > 1024 * 1024:
        raise SafetyError("Registration requires bounded native Windows file transactions")
    reject_links(path)
    kernel = ctypes.WinDLL("kernel32", use_last_error=True)
    ktm = ctypes.WinDLL("KtmW32", use_last_error=True)
    signatures = {
        "CreateFileTransactedW": ([wintypes.LPCWSTR, wintypes.DWORD, wintypes.DWORD, ctypes.c_void_p,
            wintypes.DWORD, wintypes.DWORD, wintypes.HANDLE, wintypes.HANDLE, ctypes.c_void_p, ctypes.c_void_p], wintypes.HANDLE),
        "ReadFile": ([wintypes.HANDLE, ctypes.c_void_p, wintypes.DWORD, ctypes.POINTER(wintypes.DWORD), ctypes.c_void_p], wintypes.BOOL),
        "WriteFile": ([wintypes.HANDLE, ctypes.c_void_p, wintypes.DWORD, ctypes.POINTER(wintypes.DWORD), ctypes.c_void_p], wintypes.BOOL),
        "SetFilePointerEx": ([wintypes.HANDLE, ctypes.c_longlong, ctypes.c_void_p, wintypes.DWORD], wintypes.BOOL),
        "SetEndOfFile": ([wintypes.HANDLE], wintypes.BOOL),
        "GetFileInformationByHandle": ([wintypes.HANDLE, ctypes.POINTER(FileInformation)], wintypes.BOOL),
        "GetFinalPathNameByHandleW": ([wintypes.HANDLE, wintypes.LPWSTR, wintypes.DWORD, wintypes.DWORD], wintypes.DWORD),
        "CloseHandle": ([wintypes.HANDLE], wintypes.BOOL),
    }
    for name, (arguments, result) in signatures.items():
        function = getattr(kernel, name)
        function.argtypes, function.restype = arguments, result
    ktm.CreateTransaction.argtypes = [ctypes.c_void_p, ctypes.c_void_p, wintypes.DWORD,
                                     wintypes.DWORD, wintypes.DWORD, wintypes.DWORD, wintypes.LPWSTR]
    ktm.CreateTransaction.restype = wintypes.HANDLE
    for name in ("CommitTransaction", "RollbackTransaction"):
        function = getattr(ktm, name)
        function.argtypes, function.restype = [wintypes.HANDLE], wintypes.BOOL
    invalid = ctypes.c_void_p(-1).value

    def checked(value):
        if not value or value == invalid:
            raise ctypes.WinError(ctypes.get_last_error())
        return value

    transaction = checked(ktm.CreateTransaction(None, None, 0, 0, 0, 2000, "Bounded controller root registration"))
    handle, committed = None, False
    try:
        # OPEN_REPARSE_POINT plus handle checks prevents following a swapped leaf.
        handle = checked(kernel.CreateFileTransactedW(str(path), 0xC0000000, 7, None,
                         1 if before is None else 3, 0x00200000, None, transaction, None, None))
        info = FileInformation()
        checked(kernel.GetFileInformationByHandle(handle, ctypes.byref(info)))
        name = ctypes.create_unicode_buffer(32768)
        length = checked(kernel.GetFinalPathNameByHandleW(handle, name, len(name), 0))
        if (length >= len(name) or Path(name.value.removeprefix("\\\\?\\")) != path
                or info.attributes & (0x400 | 0x10) or info.links != 1):
            raise SafetyError("Registry native handle is an alias, reparse point or foreign path")
        buffer, count = ctypes.create_string_buffer(1024 * 1024 + 1), wintypes.DWORD()
        checked(kernel.ReadFile(handle, buffer, len(buffer), ctypes.byref(count), None))
        if count.value > 1024 * 1024 or buffer.raw[:count.value] != (before or b""):
            raise RegistryConflict("Registry changed before native transactional comparison")
        checked(kernel.SetFilePointerEx(handle, 0, None, 0))
        checked(kernel.WriteFile(handle, after, len(after), ctypes.byref(count), None))
        if count.value != len(after):
            raise SafetyError("Incomplete transacted registry write")
        checked(kernel.SetEndOfFile(handle))
        reject_links(path)
        authorize()  # STOP or lost authority rolls back before anything becomes visible.
        checked(kernel.CloseHandle(handle))
        handle = None
        checked(ktm.CommitTransaction(transaction))
        committed = True
    except OSError as error:
        if error.winerror in (2, 3, 32, 33, 80, 183, 6800):
            raise RegistryConflict("Native registry writer conflict: " + str(error)) from error
        raise
    finally:
        if handle is not None:
            kernel.CloseHandle(handle)
        if not committed:
            ktm.RollbackTransaction(transaction)
        kernel.CloseHandle(transaction)


class RegistrationAdapter:
    def __init__(self, runtime):
        self.runtime = runtime
        self.root = runtime.root / "registrations"
        self.reservations = {}

    def authority(self):
        trial = self.runtime.ledger.snapshot()["trial"]
        contract = getattr(self.runtime, "launch_contract", None)
        if contract is None:
            contract = json.loads((self.runtime.root / "launch-contract.json").read_bytes())
        scope = registration_scope(trial["manifest"], contract["observer"]["registration"])
        if contract.get("registration") != scope or len(scope["assignment_ids"]) != 8:
            raise SafetyError("Launch authority does not bind controller-owned registration for eight assignments")
        registry = confined(Path(scope["registry_path"]), ACTIVE)
        reject_links(registry)
        expected = {"schema": "brawl-controller-registration-authority/v1", "run_id": self.runtime.root.name,
                    "manifest_digest": trial["manifest_digest"], "controller_id": trial["manifest"]["coordinator_id"],
                    "scope": scope}
        path = self.root / "authority.json"
        if not path.exists():
            revision = self.runtime.ledger.authorization()["revision"]
            self.runtime.ledger.require_operation("launch", authorization_revision=revision)
            roots = {key: self.identity(key) for key in scope["assignment_ids"][:4]}
            value = dict(expected, initial_roots=roots, recorded_at=now(), authorization_revision=revision)
            raw = encoded(value)
            retain(path, raw)
            retain(self.root / "authority-identity.json", encoded({"sha256": hashlib.sha256(raw).hexdigest()}))
        raw = path.read_bytes()
        anchor = json.loads((self.root / "authority-identity.json").read_bytes())
        value = json.loads(raw)
        if (anchor != {"sha256": hashlib.sha256(raw).hexdigest()}
                or any(value.get(key) != item for key, item in expected.items())
                or set(value.get("initial_roots", {})) != set(scope["assignment_ids"][:4])):
            raise SafetyError("Recorded controller registration authority changed")
        return value

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

    def read_registry(self, authority):
        path = Path(authority["scope"]["registry_path"])
        reject_links(path)
        try:
            raw = path.read_bytes()
        except FileNotFoundError:
            return path, None, {"sessions": []}
        if len(raw) > 1024 * 1024:
            raise SafetyError("Observer registry exceeds its bounded size")
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
                    or not 1 <= port <= 65535 or port in ports or port in {8765, 8766}
                    or not isinstance(row.get("label"), str) or not row["label"].strip()
                    or row["label"].strip().lower() == "main"):
                raise SafetyError("Observer registry contains invalid or overlapping identities/ports")
            roots.add(identifier)
            ports.add(port)
        return path, raw, value

    def publish(self, authority, before, after, key, operation, authorize):
        path = Path(authority["scope"]["registry_path"])
        directory = self.root / key / uuid.uuid4().hex
        retain(directory / "before.json", before or b"")
        raw = encoded(after)
        retain(directory / "after.json", raw)
        retain(directory / "intent.json", encoded({"operation": operation, "registry": str(path),
            "authority_sha256": hashlib.sha256((self.root / "authority.json").read_bytes()).hexdigest(),
            "before_sha256": None if before is None else hashlib.sha256(before).hexdigest(),
            "after_sha256": hashlib.sha256(raw).hexdigest(), "observed_at": now(),
            "mechanism": "native-NTFS-transaction", "cooperative_external_writers_assumed": False}))
        atomic_registry_update(path, before, raw, authorize)
        if path.read_bytes() != raw:
            raise RegistryConflict("Registry changed after native atomic commit; retained intent requires reread")
        retain(directory / "complete.json", encoded({"observed_at": now(), "postimage_verified": True}))

    def owned_rows(self, key):
        return [json.loads(path.read_bytes()) for path in sorted((self.root / key).glob("owned-row-*.json"))]

    def release_reservation(self, key):
        reservation = self.reservations.pop(key, None)
        if reservation is not None:
            reservation.close()

    def reserve_port(self, key, excluded):
        self.release_reservation(key)
        for _ in range(16):
            listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            try:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
                listener.bind(("127.0.0.1", 0))
                port = listener.getsockname()[1]
                if port not in excluded and port not in {8765, 8766}:
                    self.reservations[key] = listener
                    return port
            finally:
                if self.reservations.get(key) is not listener:
                    listener.close()
        raise RegistryConflict("No unregistered available observer port found in the bounded allocation")

    def port_conflict(self, key):
        port = self.runtime.ready[key]["observer_port"]
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as candidate:
            candidate.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
            try:
                candidate.bind(("127.0.0.1", port))
            except OSError as error:
                if error.winerror in (10013, 10048):
                    return True
                raise
        return False

    def register(self, key, *, replace_port=False):
        authority = self.authority()
        keys = authority["scope"]["assignment_ids"]
        if key not in keys:
            raise SafetyError("Registration assignment is outside the immutable eight targets")
        revision = self.runtime.ledger.authorization()["revision"]
        for attempt in range(4):
            try:
                with runtime_lock(self.runtime.root / "process-admission", timeout=1):
                    authorize = lambda: self.runtime.ledger.require_operation("launch", authorization_revision=revision)
                    authorize()
                    slot = self.runtime.slots[key]
                    if type(slot) is not int or not 0 <= slot < 4:
                        raise SafetyError("Registration requires one of the four owned slots")
                    snapshot = self.runtime.ledger.snapshot()
                    if key != keys[slot]:
                        predecessors = [assignment for assignment, claim in snapshot["trial"]["claims"].items()
                                        if claim["slot"] == slot and assignment != key]
                        if not predecessors or any(snapshot["assignments"][item]["status"] != "closed" for item in predecessors):
                            raise SafetyError("Refill registration requires a durably closed preceding slot owner")
                    identity = self.identity(key)
                    if key in keys[:4] and identity != authority["initial_roots"][key]:
                        raise SafetyError("Initial registration substituted its actual prepared native root")
                    _, before, registry = self.read_registry(authority)
                    existing = [row for row in registry["sessions"] if row["id"] == identity["root_session_id"]]
                    known = self.owned_rows(key)
                    if existing and not any(item["row"] == existing[0] for item in known):
                        raise SafetyError("Existing root registration is not an exact controller-owned row")
                    if existing and not replace_port:
                        return existing[0]["observerPort"]
                    port = self.reserve_port(key, {row["observerPort"] for row in registry["sessions"]})
                    tag = dict(identity, run_id=self.runtime.root.name, controller_id=authority["controller_id"],
                               assignment_id=key, slot=slot)
                    row = {"id": identity["root_session_id"], "label": "trial-" + key,
                           "observerPort": port, "controllerTrial": tag}
                    ownership = {"row": row, "process_id": identity["process_id"], "authority_sha256":
                                 hashlib.sha256((self.root / "authority.json").read_bytes()).hexdigest()}
                    retain(self.root / key / ("owned-row-" + uuid.uuid4().hex + ".json"), encoded(ownership))
                    registry["sessions"] = [row if item["id"] == row["id"] else item for item in registry["sessions"]]
                    if not existing:
                        registry["sessions"].append(row)
                    self.publish(authority, before, registry, key, "register", authorize)
                    return port
            except RegistryConflict as error:
                self.release_reservation(key)
                retain(self.root / key / ("conflict-" + uuid.uuid4().hex + ".json"),
                       encoded({"attempt": attempt + 1, "error": str(error), "observed_at": now()}))
                if attempt == 3:
                    raise
                time.sleep(0.025)

    def close(self, key, proof):
        self.release_reservation(key)
        ownerships = self.owned_rows(key)
        if not ownerships:
            return {"registered": False}
        authority = self.authority()
        authority_hash = hashlib.sha256((self.root / "authority.json").read_bytes()).hexdigest()
        process_ids = {item["process_id"] for item in ownerships}
        if len(process_ids) != 1:
            raise SafetyError("A retained function cannot substitute its native process ownership")
        process_id = next(iter(process_ids))
        for ownership in ownerships:
            tag = ownership["row"].get("controllerTrial", {})
            if (key not in authority["scope"]["assignment_ids"] or tag.get("assignment_id") != key
                    or tag.get("run_id") != self.runtime.root.name or tag.get("controller_id") != authority["controller_id"]
                    or tag.get("process_id") != process_id or ownership.get("authority_sha256") != authority_hash):
                raise SafetyError("Registration closure ownership does not bind this exact run/assignment")
        expected = self.runtime.ledger.snapshot()["processes"].get(process_id)
        if (not isinstance(proof, dict) or expected is None or expected.get("exit_proof") != proof
                or proof.get("observed_exit") is not True or proof.get("process_id") != process_id):
            raise SafetyError("Registration closure requires its actual verified owned-job exit")
        root_ids = {item["row"]["id"] for item in ownerships}
        if len(root_ids) != 1:
            raise SafetyError("Registration ownership cannot span unrelated root identities")
        for attempt in range(4):
            try:
                _, before, registry = self.read_registry(authority)
                matches = [item for item in registry["sessions"] if item["id"] in root_ids]
                if any(not any(item == owned["row"] for owned in ownerships) for item in matches):
                    raise SafetyError("Owned observer row changed; closure must preserve the foreign edit")
                if matches:
                    registry["sessions"] = [item for item in registry["sessions"] if item["id"] not in root_ids]
                    self.publish(authority, before, registry, key, "close", lambda: None)
                result = {"row_absent": True, "exit_evidence_ref": proof["evidence_ref"], "observed_at": now()}
                save_json(self.root / key / "closed.json", result)
                return result
            except RegistryConflict:
                if attempt == 3:
                    raise
                time.sleep(0.025)

    def close_exited(self):
        for key in list(self.reservations):
            self.release_reservation(key)
        outcomes = []
        keys = {path.parent.name for path in self.root.glob("*/owned-row-*.json")}
        for key in sorted(keys):
            try:
                process_id = self.owned_rows(key)[0]["process_id"]
                proof = self.runtime.ledger.snapshot()["processes"][process_id]["exit_proof"]
                outcomes.append({"assignment_id": key, "result": self.close(key, proof)})
            except (OSError, ValueError, RuntimeError, KeyError, TypeError) as error:
                outcomes.append({"assignment_id": key, "error": repr(error)})
        if outcomes:
            save_json(self.root / ("closure-" + uuid.uuid4().hex + ".json"), {"outcomes": outcomes})
        return outcomes
