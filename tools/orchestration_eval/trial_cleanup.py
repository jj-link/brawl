"""Exact-file cleanup performed by the retained owner; directories are never pruned."""
from __future__ import annotations

import ctypes
import hashlib
import json
import os
from pathlib import Path
import sys

from .evidence import InputManifest, file_identity, input_path, reject_links
from .policy import require_allowed
from .safety import SafetyError, confined, digest, now, save_json
from .state import read_snapshot


def retained_files(workspace, assignment, deliveries, specification):
    """Retain every recorded draft/evidence path, not merely the current best."""
    workspace = Path(workspace)
    found = {}

    def retain(path, expected=None, *, readonly=False):
        path = Path(path)
        if not path.is_absolute():
            path = workspace / path
        if not path.is_file():
            if expected is not None:
                raise SafetyError(f"Required retained input is missing: {path}")
            return
        if not readonly:
            reject_links(path)
        actual = file_identity(path)
        if expected and any(actual.get(key) != value for key, value in expected.items()):
            raise SafetyError(f"Required retained input changed: {path}")
        found[str(path)] = {"path": str(path), "resolved_path": str(path.resolve()), "identity": actual}

    def recorded(value):
        if isinstance(value, dict):
            if isinstance(value.get("path"), str) and isinstance(value.get("sha256"), str):
                retain(value["path"], {"sha256": value["sha256"]})
            for child in value.values():
                recorded(child)
        elif isinstance(value, list):
            for child in value:
                recorded(child)
        elif isinstance(value, str):
            path = Path(value)
            if path.is_absolute() or "/" in value or "\\" in value:
                retain(path)

    recorded(assignment)
    for entry in deliveries.values():
        delivery = entry["delivery"]
        manifest = InputManifest.from_dict(delivery["inputs"])
        for name in manifest.paths:
            retain(workspace / name)
        for artifact in delivery["artifacts"].values():
            retain(workspace / artifact["path"], artifact["identity"])
        recorded(entry["record"])
    for item in specification["workspace_inputs"]:
        # Approved original read-only sources may intentionally be addressed
        # through existing aliases. Bind both resolved identity and bytes; no
        # such exception exists for any disposable path or its ancestors.
        retain(item["source"], item["identity"], readonly=True)
        retain(workspace / item["destination"], item["identity"])
    return list(found.values())


def delivery_plan(workspace, assignment, deliveries, specification, delivery, tracked):
    """Reject unrepairable cleanup proposals before publication starts."""
    workspace = Path(workspace)
    retained = retained_files(workspace, assignment, deliveries, specification)
    fixed = set(specification["binary_hashes"])
    fixed.update(specification["selection"][key] for key in ("source", "object", "link_output", "fallback_object"))
    disposable = {row["path"].casefold() for row in delivery.payload["cleanup"]}
    if disposable & {name.casefold() for name in fixed}:
        raise SafetyError("Cleanup includes fixed compile/link or native-hash outputs")
    for name in sorted(fixed):
        path = input_path(workspace, name, must_exist=False)
        if path.is_file():
            retained.append({"path": str(path), "resolved_path": str(path.resolve()), "identity": file_identity(path)})
    plan = {"workspace": str(workspace), "files": delivery.payload["cleanup"],
            "tracked": tracked, "retained": retained}
    validate_plan(plan)
    return plan


def validate_plan(plan):
    workspace = Path(plan["workspace"])
    reject_links(workspace)
    protected = {}
    for row in plan["retained"]:
        path = Path(row["path"])
        if str(path.resolve()) != row["resolved_path"] or file_identity(path) != row["identity"]:
            raise SafetyError(f"Retained file changed before cleanup: {path}")
        stat = path.stat()
        protected[(stat.st_dev, stat.st_ino)] = str(path)
    tracked = {name.casefold() for name in plan["tracked"]}
    for name, expected in plan["tracked"].items():
        if file_identity(input_path(workspace, name)) != expected:
            raise SafetyError("Tracked source/configuration changed before cleanup")
    seen = set()
    for row in plan["files"]:
        path = input_path(workspace, row["path"])
        stat = path.stat()
        key = row["path"].casefold()
        if key in seen or key in tracked or (stat.st_dev, stat.st_ino) in protected:
            raise SafetyError("Disposable file aliases retained or tracked content")
        seen.add(key)
        if file_identity(path) != row["identity"]:
            raise SafetyError("Disposable content differs from its exact approved manifest")
    return protected


def delete_exact_file(path, expected, protected):
    """Use the checked native file handle, not a second path-following unlink.

    The final resolved handle name rejects junction ancestry even if an ancestor
    changed after the lexical check. Denying write/delete sharing keeps the
    checked bytes and file identity stable until handle-based disposition.
    """
    path = Path(path)
    reject_links(path)
    if os.name != "nt":
        raise SafetyError("Real trial cleanup requires native Windows handle deletion")
    import msvcrt
    from ctypes import wintypes
    kernel = ctypes.WinDLL("kernel32", use_last_error=True)
    kernel.CreateFileW.argtypes = [wintypes.LPCWSTR, wintypes.DWORD, wintypes.DWORD, ctypes.c_void_p,
                                  wintypes.DWORD, wintypes.DWORD, wintypes.HANDLE]
    kernel.CreateFileW.restype = wintypes.HANDLE
    kernel.GetFinalPathNameByHandleW.argtypes = [wintypes.HANDLE, wintypes.LPWSTR, wintypes.DWORD, wintypes.DWORD]
    kernel.GetFinalPathNameByHandleW.restype = wintypes.DWORD
    kernel.SetFileInformationByHandle.argtypes = [wintypes.HANDLE, ctypes.c_int, ctypes.c_void_p, wintypes.DWORD]
    kernel.SetFileInformationByHandle.restype = wintypes.BOOL
    kernel.CloseHandle.argtypes = [wintypes.HANDLE]
    kernel.CloseHandle.restype = wintypes.BOOL
    handle = kernel.CreateFileW(str(path), 0x80000000 | 0x10000, 1, None, 3, 0x00200000, None)
    if handle == ctypes.c_void_p(-1).value:
        raise ctypes.WinError(ctypes.get_last_error())
    fd = None
    try:
        name = ctypes.create_unicode_buffer(32768)
        length = kernel.GetFinalPathNameByHandleW(handle, name, len(name), 0)
        if not length or length >= len(name):
            raise ctypes.WinError(ctypes.get_last_error())
        actual_name = name.value.removeprefix("\\\\?\\")
        if os.path.normcase(os.path.abspath(actual_name)) != os.path.normcase(os.path.abspath(path)):
            raise SafetyError("Native cleanup handle resolves through unexpected junction ancestry")
        fd = msvcrt.open_osfhandle(handle, os.O_RDONLY | os.O_BINARY)
        handle = None  # descriptor now owns it
        with os.fdopen(fd, "rb", closefd=True) as stream:
            fd = None
            stat = os.fstat(stream.fileno())
            if getattr(stat, "st_file_attributes", 0) & 0x400:
                raise SafetyError("Native cleanup handle is a reparse point")
            if stat.st_nlink != 1 or (stat.st_dev, stat.st_ino) in protected:
                raise SafetyError("Native cleanup handle aliases retained content")
            sha = hashlib.sha256()
            for chunk in iter(lambda: stream.read(1024 * 1024), b""):
                sha.update(chunk)
            if {"sha256": sha.hexdigest(), "size": stat.st_size} != expected:
                raise SafetyError("Disposable bytes changed before native disposition")
            disposition = ctypes.c_ubyte(1)
            if not kernel.SetFileInformationByHandle(msvcrt.get_osfhandle(stream.fileno()), 4,
                                                     ctypes.byref(disposition), ctypes.sizeof(disposition)):
                raise ctypes.WinError(ctypes.get_last_error())
    finally:
        if fd is not None:
            os.close(fd)
        elif handle is not None:
            kernel.CloseHandle(handle)


def authorize(plan):
    doc = read_snapshot(Path(plan["ledger_path"]))
    auth = doc["authorization"]
    require_allowed(auth["mode"], "cleanup")
    action = doc["trial"]["workflow"]["actions"].get(plan["effect_id"])
    if (auth["revision"] != plan["authorization_revision"] or not action
            or action["status"] != "admitted" or action["kind"] != "cleanup"
            or action["binding"] != plan["binding"]):
        raise SafetyError("Owner cleanup is not authorized for this exact active effect")


def execute_plan(path, sha256):
    path = confined(Path(path))
    if digest(path) != sha256:
        raise SafetyError("Immutable owner cleanup plan changed")
    plan = json.loads(path.read_text(encoding="utf-8"))
    authorize(plan)
    protected = validate_plan(plan)
    directory = path.parent
    removed = []
    with (directory / "cleanup-effects.jsonl").open("x", encoding="utf-8") as journal:
        for item in plan["files"]:
            authorize(plan)
            target = input_path(Path(plan["workspace"]), item["path"])
            delete_exact_file(target, item["identity"], protected)
            row = {"path": str(target), "bytes": item["identity"]["size"],
                   "sha256": item["identity"]["sha256"], "observed_at": now()}
            removed.append(row)
            journal.write(json.dumps(row, sort_keys=True) + "\n")
            journal.flush()
            os.fsync(journal.fileno())
    # Do not prune even empty directories. Retaining them avoids the historical
    # junction-pruning failure and preserves directory metadata without recursion.
    check = dict(plan, files=[])
    validate_plan(check)
    result = {"binding": plan["binding"], "effect_id": plan["effect_id"], "pid": os.getpid(),
              "observed_at": now(), "removed_paths": removed, "removed_bytes": sum(row["bytes"] for row in removed),
              "tracked_files_preserved": True, "directories_pruned": False,
              "ancestor_links_checked": True, "directory_pruning_checked": True,
              "retained_evidence_refs": [row["path"] for row in plan["retained"]],
              "deletion_manifest_ref": str(path), "shared_link_checks_ref": str(path),
              "original_input_checks_ref": str(path), "retained_evidence_checks_ref": str(directory / "cleanup-result.json")}
    save_json(directory / "cleanup-result.json", result)
    return result


def main(argv=None):
    args = sys.argv[1:] if argv is None else argv
    if len(args) != 2:
        raise SafetyError("Cleanup requires the exact plan path and SHA256")
    print(json.dumps(execute_plan(*args), sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
