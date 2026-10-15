"""Windows jobs, creation-time identity, and durable exit receipts; no PID-only kills."""
from __future__ import annotations

from contextlib import contextmanager
import ctypes
from ctypes import wintypes as w
import json
import os
from pathlib import Path
import subprocess
import sys
import threading
import time
import uuid

from .safety import NO_WINDOW, SafetyError, confined, now, save_json


class IO_COUNTERS(ctypes.Structure):
    _fields_ = [(name, ctypes.c_ulonglong) for name in (
        "ReadOperationCount", "WriteOperationCount", "OtherOperationCount",
        "ReadTransferCount", "WriteTransferCount", "OtherTransferCount")]


class BASIC_LIMIT(ctypes.Structure):
    _fields_ = [("PerProcessUserTimeLimit", ctypes.c_longlong), ("PerJobUserTimeLimit", ctypes.c_longlong),
                ("LimitFlags", w.DWORD), ("MinimumWorkingSetSize", ctypes.c_size_t),
                ("MaximumWorkingSetSize", ctypes.c_size_t), ("ActiveProcessLimit", w.DWORD),
                ("Affinity", ctypes.c_size_t), ("PriorityClass", w.DWORD), ("SchedulingClass", w.DWORD)]


class EXTENDED_LIMIT(ctypes.Structure):
    _fields_ = [("BasicLimitInformation", BASIC_LIMIT), ("IoInfo", IO_COUNTERS),
                ("ProcessMemoryLimit", ctypes.c_size_t), ("JobMemoryLimit", ctypes.c_size_t),
                ("PeakProcessMemoryUsed", ctypes.c_size_t), ("PeakJobMemoryUsed", ctypes.c_size_t)]


class ACCOUNTING(ctypes.Structure):
    _fields_ = [("TotalUserTime", ctypes.c_longlong), ("TotalKernelTime", ctypes.c_longlong),
                ("ThisPeriodTotalUserTime", ctypes.c_longlong), ("ThisPeriodTotalKernelTime", ctypes.c_longlong),
                ("TotalPageFaultCount", w.DWORD), ("TotalProcesses", w.DWORD),
                ("ActiveProcesses", w.DWORD), ("TotalTerminatedProcesses", w.DWORD)]


def kernel():
    if os.name != "nt":
        raise SafetyError("Native Windows is required")
    api = ctypes.WinDLL("kernel32", use_last_error=True)
    signatures = {
        "CreateJobObjectW": ([ctypes.c_void_p, w.LPCWSTR], w.HANDLE),
        "OpenJobObjectW": ([w.DWORD, w.BOOL, w.LPCWSTR], w.HANDLE),
        "SetInformationJobObject": ([w.HANDLE, ctypes.c_int, ctypes.c_void_p, w.DWORD], w.BOOL),
        "QueryInformationJobObject": ([w.HANDLE, ctypes.c_int, ctypes.c_void_p, w.DWORD, ctypes.c_void_p], w.BOOL),
        "AssignProcessToJobObject": ([w.HANDLE, w.HANDLE], w.BOOL),
        "TerminateJobObject": ([w.HANDLE, w.UINT], w.BOOL),
        "OpenProcess": ([w.DWORD, w.BOOL, w.DWORD], w.HANDLE),
        "GetProcessTimes": ([w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p], w.BOOL),
        "WaitForSingleObject": ([w.HANDLE, w.DWORD], w.DWORD),
        "GetExitCodeProcess": ([w.HANDLE, ctypes.POINTER(w.DWORD)], w.BOOL),
        "IsProcessInJob": ([w.HANDLE, w.HANDLE, ctypes.POINTER(w.BOOL)], w.BOOL),
        "CloseHandle": ([w.HANDLE], w.BOOL),
    }
    for name, (args, result) in signatures.items():
        fn = getattr(api, name)
        fn.argtypes, fn.restype = args, result
    return api


def checked(result):
    if not result:
        raise ctypes.WinError(ctypes.get_last_error())
    return result


def creation_time(api, handle) -> str:
    values = [ctypes.c_ulonglong() for _ in range(4)]
    checked(api.GetProcessTimes(handle, *[ctypes.byref(v) for v in values]))
    return str(values[0].value)


def active_count(api, job) -> int:
    value = ACCOUNTING()
    checked(api.QueryInformationJobObject(job, 1, ctypes.byref(value), ctypes.sizeof(value), None))
    return value.ActiveProcesses


def owned_listener(owned: "OwnedProcess", port: int) -> bool:
    """Refuse a port race before sending even a health request to an external service."""
    import socket
    api = ctypes.WinDLL("iphlpapi", use_last_error=True)
    function = api.GetExtendedTcpTable
    function.argtypes = [ctypes.c_void_p, ctypes.POINTER(w.ULONG), w.BOOL, w.ULONG, ctypes.c_int, w.ULONG]
    function.restype = w.DWORD
    size = w.ULONG()
    function(None, ctypes.byref(size), False, socket.AF_INET, 3, 0)
    for _ in range(3):
        buffer = ctypes.create_string_buffer(size.value)
        result = function(buffer, ctypes.byref(size), False, socket.AF_INET, 3, 0)
        if result == 122:
            continue
        if result:
            raise OSError(result, "Cannot inspect owned loopback listener")
        count = w.DWORD.from_buffer_copy(buffer).value
        row_type = w.DWORD * 6
        for index in range(count):
            row = row_type.from_buffer_copy(buffer, 4 + index * ctypes.sizeof(row_type))
            if socket.ntohs(row[2] & 0xFFFF) != port or row[1] not in (0, 0x0100007F):
                continue
            process = checked(owned.manager.api.OpenProcess(0x1000, False, row[5]))
            try:
                member = w.BOOL()
                checked(owned.manager.api.IsProcessInJob(process, owned.job, ctypes.byref(member)))
                if not member.value or row[1] != 0x0100007F:
                    raise SafetyError("Loopback port is not exclusively owned by this evaluation job")
                return True
            finally:
                owned.manager.api.CloseHandle(process)
        return False
    raise SafetyError("Listener identity changed repeatedly; refusing API adoption")


@contextmanager
def runtime_lock(root: Path, *, timeout: float = 120):
    import msvcrt
    path = confined(root / "runtime.lock")
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as stream:
        if stream.tell() == 0:
            stream.write(b"0")
            stream.flush()
        stream.seek(0)
        deadline = time.monotonic() + timeout
        while True:
            try:
                msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
                break
            except OSError:
                if time.monotonic() >= deadline:
                    raise TimeoutError("Owned runtime mutation lock is occupied; no overlap permitted")
                time.sleep(0.1)
        try:
            yield
        finally:
            stream.seek(0)
            msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)


class OwnedProcess:
    def __init__(self, manager, record, process, job, streams):
        self.manager, self.record, self.process, self.job, self.streams = manager, record, process, job, streams
        self._stop_lock = threading.Lock()

    @property
    def process_id(self):
        return self.record["process_id"]

    def stop(self, *, grace: float = 3, deadline: float | None = None) -> dict:
        deadline = deadline if deadline is not None else time.monotonic() + grace + 15
        if not self._stop_lock.acquire(timeout=max(0, deadline - time.monotonic())):
            raise SafetyError("Owned stop did not acquire its remaining shutdown budget")
        try:
            return self._stop(grace=grace, deadline=deadline)
        finally:
            self._stop_lock.release()

    def _stop(self, *, grace: float, deadline: float) -> dict:
        if self.record.get("exit_proof"):
            return self.record["exit_proof"]
        if self.process.stdin and not self.process.stdin.closed:
            try:
                self.process.stdin.close()
            except OSError as exc:
                self.record["stdin_close_error"] = repr(exc)
        try:
            self.process.wait(timeout=min(grace, max(0, deadline - time.monotonic())))
        except subprocess.TimeoutExpired:
            checked(self.manager.api.TerminateJobObject(self.job, 137))
            try:
                self.process.wait(timeout=max(0, deadline - time.monotonic()))
            except subprocess.TimeoutExpired as exc:
                raise SafetyError("Owned process did not exit within the shared shutdown budget; lease retained") from exc
        # Even a successful wrapper exit cannot release a lease while descendants remain.
        if active_count(self.manager.api, self.job):
            checked(self.manager.api.TerminateJobObject(self.job, 137))
        while active_count(self.manager.api, self.job):
            if time.monotonic() >= deadline:
                raise SafetyError("Windows job still has live processes; lease retained")
            time.sleep(min(0.05, max(0, deadline - time.monotonic())))
        proof = self.manager.receipt(self.record, self.process.returncode,
                                     "process-handle-wait+empty-windows-job", deadline=deadline)
        checked(self.manager.api.CloseHandle(self.job))
        self.job = None
        for stream in self.streams:
            stream.close()
        return proof


class ProcessManager:
    def __init__(self, root: Path, environment: dict[str, str], *, authorize=None):
        self.root, self.environment = confined(root), environment
        self.directory = confined(root / "processes")
        self.directory.mkdir(parents=True, exist_ok=True)
        self.api = kernel()
        self.owned: dict[str, OwnedProcess] = {}
        self.authorize = authorize

    def records(self) -> list[dict]:
        records = []
        for path in self.directory.glob("*/record.json"):
            confined(path, self.directory)
            record = json.loads(path.read_text(encoding="utf-8"))
            token = path.parent.name
            if (len(token) != 32 or any(c not in "0123456789abcdef" for c in token)
                    or record.get("token") != token or record.get("process_id") != token
                    or record.get("job_name") != "Local\\PrefectOmpEvaluation-" + token
                    or Path(record.get("record_path", "")) != path):
                raise SafetyError("Process ownership record is inconsistent; refusing adoption")
            confined(record["cwd"], self.root)
            records.append(record)
        return records

    def launch(self, argv: list[str], *, kind: str, cwd: Path, pipe: bool = False,
               authorization_revision: int | None = None, operation: str = "launch",
               fault_at: str | None = None) -> OwnedProcess:
        if fault_at not in (None, "before_job_assignment"):
            raise SafetyError("Unknown owned-process exercise boundary")
        with runtime_lock(self.root / "process-admission"):
            self._authorize(operation, authorization_revision)
            return self._launch(argv, kind=kind, cwd=cwd, pipe=pipe,
                                authorization_revision=authorization_revision,
                                operation=operation, fault_at=fault_at)

    def _authorize(self, operation: str, revision: int | None) -> None:
        if self.authorize is not None:
            if revision is None:
                raise SafetyError("An owned runtime launch requires its captured authorization revision")
            self.authorize(operation, revision)

    def _launch(self, argv: list[str], *, kind: str, cwd: Path, pipe: bool,
                authorization_revision: int | None, operation: str, fault_at: str | None) -> OwnedProcess:
        cwd = confined(cwd, self.root)
        token = uuid.uuid4().hex
        directory = confined(self.directory / token)
        directory.mkdir()
        job_name = "Local\\PrefectOmpEvaluation-" + token
        job = checked(self.api.CreateJobObjectW(None, job_name))
        limits = EXTENDED_LIMIT()
        limits.BasicLimitInformation.LimitFlags = 0x2000  # JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE
        checked(self.api.SetInformationJobObject(job, 9, ctypes.byref(limits), ctypes.sizeof(limits)))
        spec = {"argv": argv, "cwd": str(cwd), "token": token, "directory": str(directory)}
        save_json(directory / "launch.json", spec)
        stdout = subprocess.PIPE if pipe else (directory / "stdout.log").open("wb")
        stderr = (directory / "stderr.log").open("wb")
        streams = [stderr] + ([] if pipe else [stdout])
        proc = None
        assigned = False
        try:
            proc = subprocess.Popen(
                [sys.executable, "-B", "-m", "tools.orchestration_eval.owned_child", str(directory / "launch.json")],
                cwd=cwd, env=self.environment, stdin=subprocess.PIPE if pipe else subprocess.DEVNULL,
                stdout=stdout, stderr=stderr, creationflags=NO_WINDOW,
            )
            if fault_at == "before_job_assignment":
                raise RuntimeError("Injected failure after native wrapper creation, before job assignment")
            checked(self.api.AssignProcessToJobObject(job, int(proc._handle)))
            assigned = True
            record = {"process_id": token, "pid": proc.pid, "creation_time": creation_time(self.api, int(proc._handle)),
                      "token": token, "job_name": job_name, "kind": kind, "argv": argv,
                      "cwd": str(cwd), "launched_at": now(), "record_path": str(directory / "record.json")}
            save_json(directory / "record.json", record)
            owned = OwnedProcess(self, record, proc, job, streams)
            self.owned[token] = owned
            # No target executable starts until containment and ownership are durable.
            self._authorize(operation, authorization_revision)
            save_json(directory / "go.json", {"token": token})
            return owned
        except BaseException as exc:
            self.owned.pop(token, None)
            failure = {"error": repr(exc), "job_assigned": assigned, "gate_released": (directory / "go.json").exists()}
            if proc is not None:
                failure.update(pid=proc.pid, creation_time=creation_time(self.api, int(proc._handle)))
                proc.kill()
                proc.wait(timeout=15)
                failure.update(observed_exit=True, exit_code=proc.returncode)
            self.api.CloseHandle(job)
            for stream in streams:
                stream.close()
            save_json(directory / "launch-failure.json", failure)
            raise

    def receipt(self, record: dict, code: int, method: str, *, status_known: bool = True,
                deadline: float | None = None) -> dict:
        path = confined(Path(record["record_path"]).with_name("exit.json"), self.directory)
        with runtime_lock(path.parent, timeout=120 if deadline is None else max(0, deadline - time.monotonic())):
            identity = {key: record[key] for key in ("process_id", "pid", "creation_time", "token", "job_name")}
            if path.exists():
                proof = json.loads(path.read_text(encoding="utf-8"))
                if any(proof.get(key) != value for key, value in identity.items()) or proof.get("observed_exit") is not True:
                    raise SafetyError("Exit receipt does not belong to this native process")
                if proof.get("exit_status_known", True) and status_known and proof["exit_code"] != code:
                    raise SafetyError("Conflicting native process exit observations")
            else:
                proof = dict(identity, observed_exit=True, exit_code=code, exit_status_known=status_known,
                             verified_at=now(), method=method, evidence_ref=str(path))
                save_json(path, proof)
            record["exit_proof"] = proof
            save_json(Path(record["record_path"]), record)
            return proof

    def terminate_registered(self, process_id: str, *, deadline: float | None = None) -> dict:
        # No API accepts a caller-supplied PID/session to adopt or kill.
        deadline = deadline if deadline is not None else time.monotonic() + 15
        records = {r["process_id"]: r for r in self.records()}
        if process_id not in records:
            raise SafetyError("Refusing unmanaged process identity")
        return self._terminate_record(records[process_id], deadline)

    def _terminate_record(self, record: dict, deadline: float) -> dict:
        process_id = record["process_id"]
        if process_id in self.owned:
            return self.owned[process_id].stop(grace=0, deadline=deadline)
        if record.get("exit_proof"):
            return record["exit_proof"]
        process = self.api.OpenProcess(0x100000 | 0x1000, False, record["pid"])
        process_error = ctypes.get_last_error() if not process else 0
        job = self.api.OpenJobObjectW(0x0004 | 0x0008, False, record["job_name"])
        job_error = ctypes.get_last_error() if not job else 0
        try:
            if not job and job_error != 2:
                raise SafetyError(f"Cannot prove owned Windows job identity: error {job_error}")
            if process:
                if creation_time(self.api, process) != record["creation_time"]:
                    raise SafetyError("PID reused; refusing cancellation or lease release")
                if self.api.WaitForSingleObject(process, 0) != 0:
                    if job:
                        checked(self.api.TerminateJobObject(job, 137))
                    # A vanished job after parent death may still be finishing its
                    # kill-on-close; wait for proof, never fall back to a PID kill.
                    if self.api.WaitForSingleObject(process, max(0, int((deadline - time.monotonic()) * 1000))) != 0:
                        raise SafetyError("Owned process did not exit; lease retained")
                code = w.DWORD()
                checked(self.api.GetExitCodeProcess(process, ctypes.byref(code)))
                exit_code, known = code.value, True
            else:
                error = process_error
                if error not in (0, 87, 1168):
                    raise SafetyError(f"Cannot prove owned process exit: Windows error {error}")
                exit_code, known = -1, False
            if job:
                checked(self.api.TerminateJobObject(job, 137))
                while active_count(self.api, job):
                    if time.monotonic() >= deadline:
                        raise SafetyError("Recovered job exceeded the shared shutdown budget; lease retained")
                    time.sleep(min(0.05, max(0, deadline - time.monotonic())))
            return self.receipt(record, exit_code, "creation-time-checked-OS-recovery+job-exit",
                                status_known=known, deadline=deadline)
        finally:
            if process:
                self.api.CloseHandle(process)
            if job:
                self.api.CloseHandle(job)

    def stop_all(self, *, exclude_kinds: tuple[str, ...] = (), deadline: float | None = None) -> list[dict]:
        # Fence only native creation + durable ownership + go-gate release.
        # Never wait for a server/RPC startup lock before cancelling its child.
        deadline = deadline if deadline is not None else time.monotonic() + 5
        with runtime_lock(self.root / "process-admission", timeout=max(0, deadline - time.monotonic())):
            receipts, failures = [], []
            for record in reversed(self.records()):
                if record["kind"] in exclude_kinds:
                    continue
                try:
                    receipts.append(self._terminate_record(record, deadline))
                except Exception as exc:
                    failures.append(f"{record['process_id']}: {exc}")
            if failures:
                raise SafetyError("; ".join(failures))
            return receipts
