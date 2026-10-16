"""Validate observed native journal ancestry, not caller-assigned session names."""
from __future__ import annotations

import ctypes
from ctypes import wintypes
import json
from pathlib import Path
import sys
import uuid

from .safety import ACTIVE, SafetyError, confined


def journal_header(path: Path) -> dict:
    with path.open("rb") as stream:
        for position in range(2):
            line = stream.readline(65537)
            if len(line) > 65536 or not line.endswith(b"\n"):
                raise SafetyError("Native journal header is incomplete or exceeds the bounded header limit")
            try:
                value = json.loads(line)
            except (ValueError, UnicodeError) as exc:
                raise SafetyError("Native journal prefix is not valid JSON") from exc
            if not isinstance(value, dict):
                raise SafetyError("Native journal prefix is not an object")
            if position == 0 and value.get("type") == "title":
                if (type(value.get("v")) is not int or value["v"] != 1 or
                        not all(isinstance(value.get(key), str) for key in ("title", "updatedAt", "pad")) or
                        ("source" in value and value["source"] not in ("auto", "user"))):
                    raise SafetyError("Native journal title slot is malformed")
                continue
            if value.get("type") != "session":
                raise SafetyError("Native journal prefix does not contain its immediate session header")
            break
    try:
        uuid.UUID(value["id"])
    except (ValueError, KeyError, TypeError) as exc:
        raise SafetyError("Native journal has no genuine UUID identity") from exc
    return value


def validate_child(ready: dict, event: dict, owner_id: str) -> dict:
    root_path = Path(ready["root_journal"])
    confined(root_path, root_path.parent)
    root = journal_header(root_path)
    if (root["id"] != ready["root_session_id"] or Path(root.get("cwd", "")) != ACTIVE or
            root_path.suffix != ".jsonl"):
        raise SafetyError("Independent native root journal is not the claimed original project session")
    if event.get("registry_id") != owner_id or event.get("native_kind") != "sub" or event.get("parent_id") != "Main":
        raise SafetyError("Child lacks its actual native owning-root registry membership")
    child_path = confined(Path(event["journal_ref"]), root_path.with_suffix(""))
    child = journal_header(child_path)
    if child["id"] != event.get("session_id") or child["id"] == root["id"]:
        raise SafetyError("Native child UUID does not match its own journal")
    return {"root_session_id": root["id"], "session_id": child["id"], "journal_ref": str(child_path)}


def native_process_identity(owned, pid, executable, *, expected_creation=None):
    """Query the live native executable inside its already-owned Windows job."""
    import ctypes
    from ctypes import wintypes
    from .processes import checked, creation_time
    api = owned.manager.api
    process = checked(api.OpenProcess(0x100000 | 0x1000, False, pid))
    try:
        member = wintypes.BOOL()
        checked(api.IsProcessInJob(process, owned.job, ctypes.byref(member)))
        if not member.value or api.WaitForSingleObject(process, 0) != 258:
            raise SafetyError("Native root is not a live member of its exact owned Windows job")
        created = creation_time(api, process)
        if expected_creation is not None and created != expected_creation:
            raise SafetyError("Native root PID was reused")
        query = api.QueryFullProcessImageNameW
        query.argtypes = [wintypes.HANDLE, wintypes.DWORD, wintypes.LPWSTR, ctypes.POINTER(wintypes.DWORD)]
        query.restype = wintypes.BOOL
        size = wintypes.DWORD(32768)
        image = ctypes.create_unicode_buffer(size.value)
        checked(query(process, 0, image, ctypes.byref(size)))
        if Path(image.value).resolve() != Path(executable).resolve():
            raise SafetyError("Owned native PID is not the pinned executable")
        return {"pid": pid, "creation_time": created, "executable": image.value}
    finally:
        api.CloseHandle(process)


class ProcessEntry(ctypes.Structure):
    _fields_ = [("size", wintypes.DWORD), ("usage", wintypes.DWORD), ("pid", wintypes.DWORD),
                ("heap", ctypes.c_size_t), ("module", wintypes.DWORD), ("threads", wintypes.DWORD),
                ("parent", wintypes.DWORD), ("priority", wintypes.LONG), ("flags", wintypes.DWORD),
                ("executable", wintypes.WCHAR * 260)]


def owned_wrapper_identity(owned, native, *, expected_host_pid, expected_token):
    """Bind the real owned_child host, including Windows' separate venv launcher."""
    from .processes import checked

    child_path = confined(Path(owned.record["record_path"]).parent / "child.json", owned.manager.root)
    child = json.loads(child_path.read_bytes())
    if (owned.process.poll() is not None or child.get("pid") != native["pid"]
            or child.get("host_pid") != expected_host_pid
            or child.get("token") != expected_token or expected_token != owned.record["token"]
            or child["host_pid"] == child["pid"]):
        raise SafetyError("Native child and owned wrapper receipt disagree")
    host = native_process_identity(owned, child["host_pid"], Path(sys._base_executable))
    if not int(owned.record["creation_time"]) <= int(host["creation_time"]) <= int(native["creation_time"]):
        raise SafetyError("Owned wrapper creation identity cannot precede its launcher or follow its child")

    api = owned.manager.api
    api.CreateToolhelp32Snapshot.argtypes = [wintypes.DWORD, wintypes.DWORD]
    api.CreateToolhelp32Snapshot.restype = wintypes.HANDLE
    for name in ("Process32FirstW", "Process32NextW"):
        function = getattr(api, name)
        function.argtypes, function.restype = [wintypes.HANDLE, ctypes.POINTER(ProcessEntry)], wintypes.BOOL
    snapshot = api.CreateToolhelp32Snapshot(2, 0)
    if snapshot == ctypes.c_void_p(-1).value:
        raise ctypes.WinError(ctypes.get_last_error())
    parents = {}
    try:
        entry = ProcessEntry()
        entry.size = ctypes.sizeof(entry)
        present = checked(api.Process32FirstW(snapshot, ctypes.byref(entry)))
        while present:
            if entry.pid in {native["pid"], host["pid"]}:
                parents[entry.pid] = entry.parent
            if len(parents) == 2:
                break
            present = api.Process32NextW(snapshot, ctypes.byref(entry))
            if not present and ctypes.get_last_error() != 18:
                raise ctypes.WinError(ctypes.get_last_error())
    finally:
        api.CloseHandle(snapshot)
    if (parents.get(native["pid"]) != host["pid"]
            or (host["pid"] != owned.record["pid"] and parents.get(host["pid"]) != owned.record["pid"])):
        raise SafetyError("Actual native process ancestry escaped its owned launcher/host chain")
    # Recheck creation and live job membership after the snapshot; never accept
    # a stale parent PID or an exited/replaced child merely from a process list.
    native_process_identity(owned, native["pid"], Path(native["executable"]),
                            expected_creation=native["creation_time"])
    native_process_identity(owned, host["pid"], Path(host["executable"]),
                            expected_creation=host["creation_time"])
    return host
