"""Opt-in native behavior tests. Every fixture and exit receipt is retained."""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import queue
import socket
import subprocess
import sys
import threading
import time
import unittest
import uuid

from .omp_rpc import OmpControl
from .policy import PolicyError, SlotPolicy
from .processes import ProcessManager, active_count, owned_listener
from .runtime import EvaluationRuntime
from .safety import ACTIVE, BUILD, NO_WINDOW, WORKTREE, SafetyError, confined, isolated_environment, save_json
from .state import Ledger, StateError, read_snapshot


def held(manager: ProcessManager, *, revision: int | None = None):
    output = manager.root / "fixture-ready.json"
    process = manager.launch([sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "hold",
                              "--root", str(manager.root), "--output", str(output)], kind="held-test", cwd=manager.root,
                             authorization_revision=revision)
    deadline = time.monotonic() + 15
    while not output.exists():
        if process.process.poll() is not None or time.monotonic() >= deadline:
            raise RuntimeError("Owned native fixture did not reach ready")
        time.sleep(0.02)
    return process


def native_rpc_fixture(manager, *, revision=None, forbidden=None):
    """Bind the real RPC reader/cancellation methods to an actual pipe child."""
    root = manager.root / ("rpc-fixture-" + uuid.uuid4().hex[:8])
    root.mkdir()
    output = root / "ready.json"
    argv = [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process",
            "rpc-fixture", "--root", str(root), "--output", str(output)]
    if forbidden:
        argv += ["--frame", forbidden]
    control = OmpControl.__new__(OmpControl)
    control.root, control.log = root, root / "rpc.jsonl"
    control.owned = manager.launch(argv, kind="native-rpc-fault-fixture", cwd=root, pipe=True,
                                   authorization_revision=revision)
    control.frames, control.log_lock = queue.Queue(), threading.Lock()
    control.reader_error, control._closing = None, False
    control.reader = threading.Thread(target=control._read, daemon=True, name="native-fixture-rpc-reader")
    control.reader.start()
    deadline = time.monotonic() + 15
    while not output.exists():
        if control.owned.process.poll() is not None or time.monotonic() >= deadline:
            raise RuntimeError("Actual native RPC fixture did not become ready")
        time.sleep(0.02)
    return control


def bounded_test_command(manager, *, crash_owner=False):
    root = confined(BUILD / "runs" / ("test-stop-probe-" + uuid.uuid4().hex[:12]))
    target = root / "focused-worktree/tools/orchestration_eval/test_bounded_native.py"
    target.parent.mkdir(parents=True)
    ready = root / "pytest-ready.json"
    target.write_text(
        "import json, os, time\nfrom pathlib import Path\n"
        "def test_bounded_native_child():\n"
        f"    Path({str(ready)!r}).write_text(json.dumps({{'pid': os.getpid()}}), encoding='utf-8')\n"
        "    deadline = time.monotonic() + 20\n"
        "    while time.monotonic() < deadline:\n        time.sleep(0.05)\n",
        encoding="utf-8")
    argv = [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "test-command-driver",
            "--root", str(root), "--output", str(manager.root / "test-driver-result.json")]
    if crash_owner:
        argv.append("--crash-test-owner")
    driver = manager.launch(argv, kind="bounded-test-command-driver", cwd=manager.root)
    return root, driver


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Requires native Windows and explicit isolated-fixtures test authorization")
class RuntimeTests(unittest.TestCase):
    def setUp(self):
        self.root = confined(BUILD / "tests" / "runtime" / uuid.uuid4().hex)
        self.root.mkdir(parents=True)
        self.environment = isolated_environment(self.root)
        self.manager = ProcessManager(self.root, self.environment)

    def tearDown(self):
        self.manager.stop_all()

    def test_hidden_wrapper_captures_actual_executable_version(self):
        process = self.manager.launch([sys.executable, "--version"], kind="version-capture-test", cwd=self.root)
        process.process.wait(timeout=15)
        proof = process.stop()
        log = Path(process.record["record_path"]).with_name("stdout.log").read_text(encoding="utf-8")
        self.assertIn(f"Python {sys.version_info.major}.{sys.version_info.minor}.{sys.version_info.micro}", log)
        self.assertEqual(proof["exit_code"], 0)

    def test_hidden_wrapper_preserves_binary_stdin_stdout_and_stderr(self):
        source = self.root / "measured.bin"
        content = bytes(range(256)) * 17
        source.write_bytes(content)
        expected = hashlib.sha256(content).hexdigest()
        for supplied, code in ((expected, 0), ("0" * 64, 23)):
            with self.subTest(exit_code=code):
                output = self.root / f"measurement-{code}.json"
                process = self.manager.launch(
                    [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "stdio-measure",
                     "--root", str(self.root), "--output", str(output)],
                    kind="stdio-measurement-test", cwd=self.root, pipe=True)
                request = json.dumps({"relative_path": source.name, "expected_sha256": supplied}).encode("utf-8") + b"\n"
                stdout, _ = process.process.communicate(input=request, timeout=15)
                proof = process.stop()
                measured = json.loads(stdout)
                self.assertEqual(measured["sha256"], expected)
                self.assertEqual(measured["size"], len(content))
                self.assertEqual(measured, json.loads(output.read_text(encoding="utf-8")))
                self.assertEqual(measured["matches"], code == 0)
                self.assertEqual(proof["exit_code"], code)
                stderr = Path(process.record["record_path"]).with_name("stderr.log").read_text(encoding="utf-8")
                self.assertIn(f"Measured {len(content)} bytes", stderr)

    def test_stop_bypasses_stalled_startup_lock_and_proves_native_exit(self):
        from .acceptance import exercise_stalled_startup
        result = exercise_stalled_startup(self.root / "startup-race", 1)
        self.assertTrue(result["startup_lock_still_held"])
        self.assertEqual(result["authorization"]["mode"], "STOPPED")
        self.assertTrue(result["exit_proof"]["observed_exit"])
        self.assertTrue(result["queued_launch"]["refused"])

    def test_wrapper_failure_before_job_assignment_cannot_admit_target(self):
        from .acceptance import exercise_pre_assignment_failure
        result = exercise_pre_assignment_failure(self.root / "pre-assignment")
        self.assertTrue(result["wrapper_exit"]["observed_exit"])
        self.assertFalse(result["wrapper_exit"]["job_assigned"])
        self.assertFalse(result["wrapper_exit"]["gate_released"])
        self.assertTrue(result["target_never_admitted"])

    def test_real_process_exit_and_unmanaged_pid_refusal(self):
        process = held(self.manager)
        with self.assertRaises(SafetyError):
            self.manager.terminate_registered(str(os.getpid()))
        self.assertIsNone(process.process.poll())
        receipt = process.stop(grace=0.1)
        self.assertTrue(receipt["observed_exit"])
        self.assertIsNotNone(process.process.poll())
        self.assertEqual(receipt, self.manager.terminate_registered(process.process_id))
        self.assertIn("empty-windows-job", receipt["method"])

    def test_listener_identity_uses_actual_windows_job_membership(self):
        output = self.root / "listener.json"
        process = self.manager.launch(
            [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "listen",
             "--root", str(self.root), "--output", str(output)], kind="listener-test", cwd=self.root)
        deadline = time.monotonic() + 15
        while not output.exists():
            self.assertIsNone(process.process.poll())
            self.assertLess(time.monotonic(), deadline)
            time.sleep(0.02)
        port = json.loads(output.read_text(encoding="utf-8"))["port"]
        self.assertTrue(owned_listener(process, port))
        with socket.socket() as external:
            external.bind(("127.0.0.1", 0))
            external.listen()
            with self.assertRaises(SafetyError):
                owned_listener(process, external.getsockname()[1])
        self.assertIsNone(process.process.poll())
        process.stop(grace=0.1)

    def test_slot_and_pause_gates_refuse_before_native_startup(self):
        ledger = Ledger(self.root / "slots.sqlite3",
                        policy=SlotPolicy(astra_capacity=1, overrides={"sol": 0}, paused=("qwen",)))
        revision = ledger.authorize("RUN", event_id="slot-run", reason="Explicit zero/paused fixture slots",
                                    expected_revision=0)["revision"]
        runtime = EvaluationRuntime(self.root, ledger)
        for stage in ("sol", "qwen"):
            with self.assertRaises(SafetyError):
                runtime.launch_assignment("blocked-" + stage, {"symbol": "blocked-" + stage},
                                          Path("must-not-launch.exe"), revision=revision, stage=stage)
        self.assertEqual(runtime.manager.records(), [])
        self.assertEqual(ledger.assignments(), [])

    def test_stop_is_persisted_and_restart_cannot_launch(self):
        ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy(astra_capacity=1))
        revision = ledger.authorize("RUN", event_id="run", reason="Native test fixture", expected_revision=0)["revision"]
        runtime = EvaluationRuntime(self.root, ledger)
        process = held(runtime.manager, revision=revision)
        runtime.register_process(process, revision)
        try:
            runtime.stop(event_id="stop", reason="Test persisted STOP and actual exit")
            stopped = read_snapshot(ledger.path)
            self.assertEqual(stopped["authorization"]["mode"], "STOPPED")
            self.assertIsNotNone(process.process.poll())
            before_cancel = json.loads((self.root / "snapshots" / "stop-stop-persisted.json").read_text(encoding="utf-8"))
            self.assertEqual(before_cancel["authorization"]["mode"], "STOPPING")
            self.assertTrue(before_cancel["processes"][process.process_id]["active"])
            reopened = Ledger(ledger.path)
            with self.assertRaises(PolicyError):
                reopened.require_operation("launch", authorization_revision=revision)
            reopened.authorize("RUN", event_id="run", reason="Native test fixture", expected_revision=0)
            self.assertEqual(reopened.authorization()["mode"], "STOPPED")
            with self.assertRaises(PolicyError):
                runtime.launch_assignment("queued", {"symbol": "queued"}, Path("never-launched.exe"), revision=revision)
        finally:
            runtime.manager.stop_all()

    def test_parent_crash_kills_owned_job_and_recovery_proves_exit(self):
        crash_root = self.root / "crashed-owner"
        crash_root.mkdir()
        env = isolated_environment(crash_root)
        result = subprocess.run([sys.executable, "-B", "-m", "tools.orchestration_eval.test_runtime", "crash-owner", str(crash_root)],
                                cwd=crash_root, env=env, capture_output=True, text=True, creationflags=NO_WINDOW, timeout=45)
        save_json(self.root / "parent-crash.json", {"returncode": result.returncode, "stdout": result.stdout, "stderr": result.stderr})
        self.assertEqual(result.returncode, 76)
        recovered = ProcessManager(crash_root, env)
        records = recovered.records()
        self.assertEqual(len(records), 1)
        proof = recovered.terminate_registered(records[0]["process_id"])
        self.assertTrue(proof["observed_exit"])
        self.assertIn("OS-recovery", proof["method"])

    def test_reused_pid_identity_refuses_cancellation(self):
        process = held(self.manager)
        record = dict(process.record)
        record["creation_time"] = str(int(record["creation_time"]) + 1)
        save_json(Path(record["record_path"]), record)
        recovered = ProcessManager(self.root, self.environment)
        with self.assertRaises(SafetyError):
            recovered.terminate_registered(process.process_id)
        self.assertIsNone(process.process.poll())
        # Restore only the exact test-owned metadata; retain the rejected identity separately.
        save_json(self.root / "rejected-identity.json", record)
        save_json(Path(process.record["record_path"]), process.record)
        process.stop(grace=0.1)

    def test_active_paths_and_hardlink_are_refused(self):
        for path in (ACTIVE, ACTIVE / ".git", WORKTREE / "PLAN.md"):
            with self.assertRaises(SafetyError):
                confined(path)
        original = self.root / "original.txt"
        link = self.root / "linked.txt"
        original.write_text("preserved", encoding="utf-8")
        os.link(original, link)
        with self.assertRaises(SafetyError):
            confined(link)
        self.assertEqual(original.read_text(encoding="utf-8"), "preserved")

    def test_default_status_does_not_create_state_or_processes(self):
        run_id = "not-created-" + uuid.uuid4().hex
        target = BUILD / "runs" / run_id
        result = subprocess.run([sys.executable, "-B", "-m", "tools.orchestration_eval", "status", "--run-id", run_id],
                                cwd=self.root, env=self.environment, capture_output=True, text=True,
                                creationflags=NO_WINDOW, timeout=30)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(json.loads(result.stdout)["state"], "not_initialized")
        self.assertFalse(target.exists())
        self.assertEqual(self.manager.records(), [])

    def test_fixture_git_refuses_add_and_commit_after_durable_stop(self):
        from .acceptance import fixture_git
        from .publication import FixtureScope, initialize_fixture, _text
        from .safety import digest
        ledger = Ledger(self.root / "ledger.sqlite3")
        ledger.authorize("RUN", event_id="run", reason="Owned Git dispatch regression", expected_revision=0)
        runtime = EvaluationRuntime(self.root, ledger)
        scope = FixtureScope(self.root, authorized=True)
        fixture = initialize_fixture(scope, "g")
        before_head = _text(fixture.repository, ["rev-parse", "HEAD"], fixture.evidence_dir)
        before_index = digest(fixture.repository / ".git/index")
        (fixture.repository / "source.cpp").write_bytes(b"int fixture_value() { return 9; }\n")
        ledger.request_stop(event_id="stop-before-git", reason="STOP wins before fixture dispatch")
        outcomes = []
        try:
            for arguments in (["add", "--", "source.cpp"], ["commit", "-m", "Must not dispatch after STOP"]):
                try:
                    fixture_git(runtime, scope, fixture, arguments)
                    outcomes.append({"arguments": arguments, "refused": False})
                except (SafetyError, PolicyError, StateError) as exc:
                    outcomes.append({"arguments": arguments, "refused": True, "error": repr(exc)})
            after_head = _text(fixture.repository, ["rev-parse", "HEAD"], fixture.evidence_dir)
            after_index = digest(fixture.repository / ".git/index")
            save_json(self.root / "fixture-git-stop-regression.json", {
                "authorization": ledger.authorization(), "outcomes": outcomes,
                "before_head": before_head, "after_head": after_head,
                "before_index": before_index, "after_index": after_index,
                "owned_processes": runtime.manager.records()})
            self.assertTrue(all(item["refused"] for item in outcomes), outcomes)
            self.assertEqual(before_head, after_head)
            self.assertEqual(before_index, after_index)
            self.assertEqual(runtime.manager.records(), [])
        finally:
            runtime.stop(event_id="git-fixture-final-stop", reason="Close the exact owned regression")

    def test_test_command_exact_run_stop_owns_real_bounded_pytest(self):
        root, driver = bounded_test_command(self.manager)
        run_id, ready = root.name, root / "pytest-ready.json"
        try:
            deadline = time.monotonic() + 20
            while not ready.exists():
                self.assertIsNone(driver.process.poll(), "Actual focused pytest child exited before readiness")
                self.assertLess(time.monotonic(), deadline, "Actual focused pytest did not start")
                time.sleep(0.02)
            stopper = self.manager.launch(
                [sys.executable, "-B", "-m", "tools.orchestration_eval", "stop",
                 "--run-id", run_id, "--authorize-isolated-evaluation"],
                kind="exact-test-run-stopper", cwd=self.root)
            stopper.process.wait(timeout=20)
            proof = stopper.stop(grace=0)
            logs = Path(stopper.record["record_path"]).parent
            record = {"run": str(root), "ready": json.loads(ready.read_text(encoding="utf-8")),
                      "stop_exit_proof": proof, "stop_returncode": stopper.process.returncode,
                      "stdout": (logs / "stdout.log").read_text(encoding="utf-8"),
                      "stderr": (logs / "stderr.log").read_text(encoding="utf-8"),
                      "ledger_exists": (root / "ledger.sqlite3").is_file(),
                      "qualification": "One bounded actual pytest fixture; no nested/full-suite execution"}
            save_json(self.root / "test-command-stop-regression.json", record)
            self.assertEqual(stopper.process.returncode, 0, record)
            snapshot = read_snapshot(root / "ledger.sqlite3")
            self.assertEqual(snapshot["authorization"]["mode"], "STOPPED")
            self.assertTrue(snapshot["processes"])
            self.assertTrue(all(not p["active"] for p in snapshot["processes"].values()))
        finally:
            driver.stop(grace=0)

    def test_test_command_parent_exit_recovers_exact_run_without_adoption(self):
        root, driver = bounded_test_command(self.manager, crash_owner=True)
        try:
            self.assertEqual(driver.process.wait(timeout=30), 77)
            before = read_snapshot(root / "ledger.sqlite3")
            self.assertEqual(before["authorization"]["mode"], "RUN")
            self.assertTrue(any(p["active"] for p in before["processes"].values()))
            # Observe parent-death containment before the supervising test calls
            # stop on its own outer job, so outer cleanup cannot fake this proof.
            deadline = time.monotonic() + 5
            while active_count(self.manager.api, driver.job):
                self.assertLess(time.monotonic(), deadline, "Dead test owner left a real descendant alive")
                time.sleep(0.02)
            stopper = self.manager.launch(
                [sys.executable, "-B", "-m", "tools.orchestration_eval", "stop",
                 "--run-id", root.name, "--authorize-isolated-evaluation"],
                kind="crashed-test-run-recovery", cwd=self.root)
            stopper.process.wait(timeout=20)
            stop_proof = stopper.stop(grace=0)
            logs = Path(stopper.record["record_path"]).parent
            after = read_snapshot(root / "ledger.sqlite3")
            save_json(self.root / "test-command-parent-exit-recovery.json", {
                "run": str(root), "parent_exit_code": driver.process.returncode,
                "outer_job_empty_before_cleanup": True, "before": before, "after": after,
                "stop_exit_proof": stop_proof, "stop_returncode": stopper.process.returncode,
                "stdout": (logs / "stdout.log").read_text(encoding="utf-8"),
                "stderr": (logs / "stderr.log").read_text(encoding="utf-8")})
            self.assertEqual(stopper.process.returncode, 0)
            self.assertEqual(after["authorization"]["mode"], "STOPPED")
            for process in after["processes"].values():
                self.assertFalse(process["active"])
                self.assertTrue(process["exit_proof"]["observed_exit"])
                self.assertIn("creation-time-checked-OS-recovery", process["exit_proof"]["method"])
        finally:
            driver.stop(grace=0)

    def test_native_stopped_commit_recovers_without_admitting_push(self):
        from .acceptance import exercise_publication_stop
        result = exercise_publication_stop(self.root / "commit", "commit")
        self.assertNotEqual(result["actual_commit"], result["actual_remote"])
        self.assertFalse(result["recovered"]["pushed"])
        self.assertTrue(result["fresh_publication_launch_refused"]["refused"])
        self.assertTrue(result["all_owned_processes_exited"])
        self.assertEqual(result["final_authorization"]["mode"], "STOPPED")

    def test_native_stopped_push_recovers_without_replaying_mutation(self):
        from .acceptance import exercise_publication_stop
        result = exercise_publication_stop(self.root / "push", "push")
        self.assertEqual(result["actual_commit"], result["actual_remote"])
        self.assertTrue(result["recovered"]["pushed"])
        self.assertTrue(result["fresh_publication_launch_refused"]["refused"])
        self.assertTrue(result["all_owned_processes_exited"])
        self.assertEqual(result["final_authorization"]["mode"], "STOPPED")

    def test_forbidden_rpc_frames_terminate_without_pending_receiver(self):
        for frame in ("agent_start", "host_tool_call", "host_uri_request"):
            with self.subTest(frame=frame):
                control = native_rpc_fixture(self.manager, forbidden=frame)
                try:
                    save_json(control.root / "send-frame.json", {"send": frame})
                    deadline = time.monotonic() + 5
                    while control.owned.process.poll() is None and time.monotonic() < deadline:
                        time.sleep(0.02)
                    observed_exit = control.owned.process.poll() is not None
                    save_json(control.root / "forbidden-frame-regression.json", {
                        "frame": frame, "pending_receiver": False, "observed_exit": observed_exit,
                        "reader_alive": control.reader.is_alive(), "queued_frames": control.frames.qsize()})
                    self.assertTrue(observed_exit, "Forbidden native frame left the owned job alive")
                finally:
                    control.owned.stop(grace=0)
                    control.reader.join(timeout=5)

    def test_cancel_reaps_native_job_when_reader_already_failed(self):
        control = native_rpc_fixture(self.manager, forbidden="agent_start")
        try:
            save_json(control.root / "send-frame.json", {"send": "agent_start"})
            control.reader.join(timeout=10)
            self.assertFalse(control.reader.is_alive(), "Actual forbidden frame was not consumed")
            error = None
            try:
                control.cancel()
            except Exception as exc:
                error = repr(exc)
            observed_exit = control.owned.process.poll() is not None
            save_json(control.root / "cancel-reader-error-regression.json",
                      {"cancel_error": error, "observed_exit": observed_exit})
            self.assertTrue(observed_exit, "Cancellation raised before proving owned-job exit")
        finally:
            control.owned.stop(grace=0)
            control.reader.join(timeout=5)

    def test_stop_has_one_total_deadline_for_unresponsive_native_controls(self):
        ledger = Ledger(self.root / "ledger.sqlite3")
        revision = ledger.authorize("RUN", event_id="run", reason="Native aggregate shutdown regression",
                                    expected_revision=0)["revision"]
        runtime = EvaluationRuntime(self.root, ledger)
        controls, errors = [], []
        finished = threading.Event()
        for number in range(3):
            control = native_rpc_fixture(runtime.manager, revision=revision)
            runtime.register_process(control.owned, revision)
            runtime.controls[str(number)] = control
            controls.append(control)
        def stop():
            try:
                runtime.stop(event_id="aggregate-stop", reason="Bound total shutdown, not per control")
            except BaseException as exc:
                errors.append(repr(exc))
            finally:
                finished.set()
        worker = threading.Thread(target=stop, daemon=True, name="aggregate-native-stopper")
        began = time.monotonic()
        worker.start()
        try:
            within_bound = finished.wait(6)
            snapshot = ledger.snapshot()
            observed_exits = [c.owned.process.poll() is not None for c in controls]
            save_json(self.root / "aggregate-stop-regression.json", {
                "controls": len(controls), "finished_within_six_seconds": within_bound,
                "elapsed_seconds": time.monotonic() - began, "authorization": snapshot["authorization"],
                "native_exits_before_test_cleanup": observed_exits, "errors": errors})
            self.assertTrue(within_bound, "STOP serialized unresponsive RPC timeout budgets")
            self.assertEqual(errors, [])
            self.assertTrue(all(observed_exits))
            self.assertEqual(snapshot["authorization"]["mode"], "STOPPED")
        finally:
            # Known handles contain all fixtures; cleanup does not depend on the
            # broken RPC path and releases any blocked reader with actual EOF.
            for control in controls:
                control.owned.stop(grace=0)
                control.reader.join(timeout=5)
            worker.join(timeout=15)
            self.assertFalse(worker.is_alive(), "Owned stop thread outlived fixture cleanup")

    def initial_setup_case(self, boundary):
        root = confined(BUILD / "runs" / ("setup-probe-" + uuid.uuid4().hex[:12]))
        output = self.root / "initial-setup-result.json"
        driver = self.manager.launch(
            [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "initial-setup-probe",
             "--root", str(root), "--output", str(output), "--setup-boundary", boundary],
            kind="initial-main-flow-test-driver", cwd=self.root)
        stop_receipt = None
        try:
            if boundary in ("during", "materialization"):
                ready = root / "setup-boundary.json"
                deadline = time.monotonic() + 30
                while not ready.exists():
                    self.assertIsNone(driver.process.poll(), "Initial main-flow driver failed before the real Git boundary")
                    self.assertLess(time.monotonic(), deadline)
                    time.sleep(0.02)
                ledger = Ledger(root / "ledger.sqlite3")
                if boundary == "during":
                    stop_receipt = EvaluationRuntime(root, ledger).stop(
                        event_id="stop-during-initial-setup", reason="Stop the actual owning setup job after real Git init")
                else:
                    stop_receipt = ledger.request_stop(
                        event_id="stop-before-materialization", reason="Durable STOP before fixture sealing/probe/expected writes")
                save_json(root / "release-setup.json", {"stop_receipt": stop_receipt})
            self.assertEqual(driver.process.wait(timeout=40), 0)
            result = json.loads(output.read_text(encoding="utf-8"))
            result["driver_exit"] = driver.stop(grace=0)
            result["external_stop_receipt"] = stop_receipt
            save_json(self.root / "initial-setup-regression.json", result)
            self.assertEqual(result["authorization"]["mode"], "STOPPED")
            self.assertTrue(all(p.get("exit_proof", {}).get("observed_exit") for p in result["owned_processes"]))
            if boundary == "normal":
                self.assertTrue(result["entered_assignment"])
                self.assertTrue(result["fixture_sealed"] and result["probe_present"])
                self.assertEqual(result["expected"], "int fixture_value() { return 2; }\n")
                self.assertTrue(result["local_ref"])
                self.assertEqual(result["local_ref"], result["remote_ref"])
                self.assertEqual(len(result["owned_processes"]), 1, "Main-flow initialization was not a durable owned job")
            else:
                self.assertFalse(result["probe_present"], "Initial setup wrote probe.py after STOP")
                self.assertIsNone(result["expected"], "Initial setup wrote expected.txt after STOP")
                self.assertFalse(result["fixture_sealed"], "Partial stopped setup was falsely sealed complete")
                self.assertFalse(result["entered_assignment"])
                if boundary == "before":
                    self.assertFalse(result["fixture_exists"], "STOP allowed initial fixture creation")
                    self.assertEqual(result["git_observations"], [])
                    self.assertEqual(result["owned_processes"], [])
                else:
                    self.assertTrue(result["fixture_exists"], "Partial native evidence was not preserved")
                    self.assertEqual(len(result["owned_processes"]), 1)
                    self.assertTrue(all(row["authorization_before_dispatch"]["mode"] == "RUN"
                                        for row in result["git_observations"]), "Later native Git dispatch occurred after STOP")
                    if boundary == "during":
                        self.assertEqual(len(result["git_observations"]), 1)
                        self.assertIsNone(result["local_ref"])
                    else:
                        self.assertTrue(result["local_ref"])
                        self.assertEqual(result["local_ref"], result["remote_ref"])
        finally:
            driver.stop(grace=0)

    def test_initial_main_flow_stop_before_setup(self):
        self.initial_setup_case("before")

    def test_initial_main_flow_stop_during_setup(self):
        self.initial_setup_case("during")

    def test_initial_main_flow_stop_before_materialization(self):
        self.initial_setup_case("materialization")

    def test_initial_main_flow_normal_owned_setup(self):
        self.initial_setup_case("normal")


def crash_owner(root: Path) -> None:
    manager = ProcessManager(confined(root), isolated_environment(root))
    process = held(manager)
    save_json(root / "crash-boundary.json", {"process_id": process.process_id, "pid": process.process.pid})
    os._exit(76)


if __name__ == "__main__":
    if len(sys.argv) == 3 and sys.argv[1] == "crash-owner":
        crash_owner(Path(sys.argv[2]))
    else:
        unittest.main()
