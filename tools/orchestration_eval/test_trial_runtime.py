"""Permanent consumer boundary tests; no provider calls, echo host, or fake native agents."""
from __future__ import annotations

from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import subprocess
import threading
import unittest
from unittest.mock import patch
from types import SimpleNamespace
import uuid

from .omp_rpc import OmpControl
from .policy import SlotPolicy
from .safety import ACTIVE, BUILD, SafetyError, check_worktree, confined, isolated_environment, now
from .state import Ledger
from .test_state import trial_manifest
from .trial import canonical_digest, record_after_stop, recover, report, submit
from .trial_rpc import TrialRpc
from .trial_runtime import TrialRuntime, immutable_json, owner_reporting_argv
from .trial_identity import journal_header, validate_child


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit native isolated-fixtures verification required")
class TrialRuntimeTests(unittest.TestCase):
    def setUp(self):
        self.root = confined(BUILD / "tests/trial-runtime" / uuid.uuid4().hex)
        self.root.mkdir(parents=True)
        self.ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
        self.manifest = trial_manifest(self.root)
        self.trial = self.ledger.register_trial(manifest=self.manifest, event_id="manifest")
        self.revision = self.ledger.authorize("RUN", event_id="authorized", expected_revision=0,
                                             reason="Synthetic consumer boundary test; no provider effects")["revision"]

    def envelope(self, identifier="delivery", **changes):
        return {"event_id": identifier, "manifest_digest": self.trial["manifest_digest"],
                "operation": "activate", "payload": {"coordinator_ref": "synthetic-unexecuted"}, **changes}

    def assert_delivery_only(self, before, after, envelope, role):
        self.assertEqual(after["event_count"], before["event_count"] + 1)
        self.assertEqual({k: v for k, v in before.items() if k not in {"updated_at", "trial", "event_count"}},
                         {k: v for k, v in after.items() if k not in {"updated_at", "trial", "event_count"}})
        self.assertEqual({k: v for k, v in before["trial"].items() if k not in {"deliveries", "capacity_history"}},
                         {k: v for k, v in after["trial"].items() if k not in {"deliveries", "capacity_history"}})
        delivery = after["trial"]["deliveries"][envelope["event_id"]]
        self.assertEqual(delivery["role"], role)
        self.assertEqual(delivery["envelope"], envelope)
        self.assertIsNone(delivery["consumed_at"])

    def test_additive_control_plane_does_not_open_original_exercise_guard(self):
        check_worktree(control_plane=True)
        check_worktree(real_trial=True)
        with self.assertRaises(SafetyError):
            check_worktree()

    def test_coordinator_history_delivery_changes_effective_history_not_manifest_or_effects(self):
        root = self.root / "recovered-history"
        manifest = trial_manifest(root)
        recovered = manifest["reservations"][4]["history"]
        manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-incomplete-scan"]}
        ledger = Ledger(root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
        trial = ledger.register_trial(manifest=manifest, event_id="unknown-manifest")
        ledger.authorize("RUN", event_id="history-run", expected_revision=0, reason="Synthetic consumer test")
        runtime = TrialRuntime(root, ledger, Path("unused-native.exe"), {})
        value = {"event_id": "history-recovery", "operation": "history", "assignment_id": "trial-4",
                 "manifest_digest": trial["manifest_digest"], "payload": {"history": recovered,
                     "record": {"assignment_id": "trial-4", "manifest_digest": trial["manifest_digest"],
                                "observed_by": "coordinator", "observed_at": now(),
                                "timestamp_provenance": {"source": "synthetic-test", "clock_id": "host-utc"},
                                "evidence_refs": ["synthetic-confirmed-full-coverage"]}}}
        delivered = submit(root, value)
        self.assertFalse(delivered["executed"])
        self.assertEqual(ledger.trial_history("trial-4")["status"], "unknown")
        result = runtime.handle(json.loads(Path(delivered["path"]).read_text()))
        before_duplicate = ledger.snapshot()
        self.assertEqual(runtime.handle(value), result)
        self.assertEqual(ledger.snapshot(), before_duplicate)
        after = ledger.snapshot()
        self.assertEqual(after["trial"]["manifest"], manifest)
        self.assertEqual(after["trial"]["manifest_digest"], trial["manifest_digest"])
        self.assertEqual(ledger.trial_history("trial-4"), recovered)
        self.assertEqual(after["trial"]["effects"], {})
        self.assertEqual(after["trial"]["claims"], {})
        self.assertEqual(runtime.roots, {})

    def test_canonical_manifest_digest_is_actual_ledger_identity(self):
        self.assertEqual(canonical_digest(self.manifest), self.trial["manifest_digest"])
        unicode_manifest = dict(self.manifest, confirmation_refs=["synthetic-évidence"])
        other = Ledger(self.root / "unicode/ledger.sqlite3", policy=SlotPolicy.real_trial())
        stored = other.register_trial(manifest=unicode_manifest, event_id="unicode")
        self.assertEqual(canonical_digest(unicode_manifest), stored["manifest_digest"])

    def test_submission_is_retained_not_executed_and_duplicate_cannot_rebind(self):
        before = self.ledger.snapshot()
        value = self.envelope()
        result = submit(self.root, value)
        self.assertFalse(result["executed"])
        self.assertEqual(json.loads(Path(result["path"]).read_text()), value)
        self.assert_delivery_only(before, self.ledger.snapshot(), value, "coordinator")
        self.assertTrue(submit(self.root, value)["duplicate"])
        with self.assertRaises(SafetyError):
            submit(self.root, self.envelope(payload={"coordinator_ref": "different"}))
        self.assertEqual(json.loads(Path(result["path"]).read_text()), value)

    def test_concurrent_duplicate_delivery_publishes_one_complete_envelope(self):
        barrier = threading.Barrier(8)
        value = self.envelope()
        def deliver(_):
            barrier.wait()
            return submit(self.root, value)
        with ThreadPoolExecutor(max_workers=8) as pool:
            results = list(pool.map(deliver, range(8)))
        self.assertEqual(sum(not result["duplicate"] for result in results), 1)
        self.assertEqual(json.loads((self.root / "inbox/delivery.json").read_text()), value)
        self.assertEqual(self.ledger.snapshot()["assignments"], {})

    def test_concurrent_conflicting_delivery_never_overwrites_winner(self):
        barrier = threading.Barrier(2)
        def deliver(number):
            value = self.envelope(payload={"number": number})
            barrier.wait()
            try:
                submit(self.root, value)
                return value
            except SafetyError:
                return None
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(deliver, range(2)))
        winners = [result for result in results if result is not None]
        self.assertEqual(len(winners), 1)
        self.assertEqual(json.loads((self.root / "inbox/delivery.json").read_text()), winners[0])

    def test_wrong_manifest_and_path_escape_never_enter_consumer_inbox(self):
        for envelope in (self.envelope(manifest_digest="f" * 64), self.envelope("../escape"),
                         self.envelope(operation="prompt"), self.envelope(operation="publish")):
            with self.subTest(envelope=envelope), self.assertRaises(SafetyError):
                submit(self.root, envelope)
        self.assertFalse((self.root / "inbox").exists())

    def test_stopped_delivery_cannot_wake_or_resume_existing_owner(self):
        self.ledger.request_stop(event_id="stop", reason="Synthetic STOP")
        with self.assertRaises(SafetyError):
            submit(self.root, self.envelope())
        with self.assertRaises(SafetyError):
            record_after_stop(self.root, self.envelope())
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPING")
        self.assertEqual(self.ledger.assignments(), [])

    def test_observation_recovery_never_creates_an_unknown_run(self):
        absent = self.root / "not-a-run"
        with self.assertRaises(SafetyError):
            record_after_stop(absent, self.envelope())
        self.assertFalse(absent.exists())

    def test_owner_reporting_uses_reviewed_module_from_historical_workspace_cwd(self):
        workspace = self.root / "historical-workspace"
        package = workspace / "tools/orchestration_eval"
        package.mkdir(parents=True)
        # A historical target baseline contains the original regular package,
        # but not this later trial module. Python must not import that package.
        (workspace / "tools/__init__.py").write_text("")
        (package / "__init__.py").write_text("")
        envelope = self.root / "unsubmitted-observation.json"
        envelope.write_text("{}")
        run_id = "realtrial-owner-path-" + uuid.uuid4().hex
        environment = isolated_environment(self.root / "report-environment")
        environment.pop("PYTHONSAFEPATH", None)
        result = subprocess.run(owner_reporting_argv(run_id) + [str(envelope)],
                                cwd=workspace, env=environment, capture_output=True, text=True, timeout=30)
        self.assertEqual(result.returncode, 1)
        self.assertEqual(result.stderr.strip(), "Owner observation requires an existing exact-run ledger")
        self.assertFalse((BUILD / "runs" / run_id).exists())

    def test_owner_reports_bind_retained_identity_without_coordinator_authority(self):
        from .test_state import TrialLedgerTests
        fixture = TrialLedgerTests()
        fixture.setUp()
        fixture.initial()
        value = {"event_id": "owner-phase", "assignment_id": "trial-0",
                 "owner_id": "owner-0", "session_id": "child-0", "manifest_digest": fixture.digest,
                 "operation": "event", "payload": {"kind": "phase",
                     "record": fixture.observation(owner_id="owner-0", phase="tool_wait")}}
        before = fixture.ledger.snapshot()
        accepted = report(fixture.root, value)
        self.assertFalse(accepted["executed"])
        self.assert_delivery_only(before, fixture.ledger.snapshot(), value, "owner")
        forbidden = [{"operation": op, "payload": {}} for op in
                     ("activate", "prepare-children", "activate-refill", "message", "close", "history")]
        forbidden += [{"operation": "receipt", "payload": {"kind": kind}}
                      for kind in ("review", "commit", "push", "ack", "closed")]
        forbidden += [{"owner_id": "other-owner"}, {"session_id": "replacement-session"},
                      {"manifest_digest": "f" * 64},
                      {"operation": "transition", "payload": {"status": "closed"}}]
        for index, changes in enumerate(forbidden):
            envelope = dict(value, event_id=f"forbidden-{index}", **changes)
            with self.subTest(changes=changes), self.assertRaises(SafetyError):
                report(fixture.root, envelope)
            self.assertFalse((fixture.root / "inbox" / f"forbidden-{index}.json").exists())

    def test_result_consumer_waits_for_completed_record_not_partial_json(self):
        from .test_runtime import held
        runtime = TrialRuntime(self.root, self.ledger, Path("unused-native.exe"), {})
        owned = held(runtime.manager, revision=self.revision)
        runtime.register_process(owned, self.revision)
        # Exercise the actual file consumer with an owned Windows job. This
        # deliberately does not instantiate or claim a native agent/RPC stream.
        rpc = object.__new__(TrialRpc)
        rpc.directory, rpc.owned, rpc.failure = self.root, owned, None
        runtime.roots["consumer"] = rpc
        path = self.root / "result-consumer.json"
        path.write_text('{"id":', encoding="utf-8")
        try:
            with ThreadPoolExecutor(max_workers=1) as pool:
                future = pool.submit(runtime.await_native_result, "consumer", "consumer", timeout=2)
                with self.assertRaises(TimeoutError):
                    future.result(timeout=0.15)
                result = {"id": "consumer", "success": True, "observed": "complete-file-only"}
                path.write_text(json.dumps(result), encoding="utf-8")
                path.with_name(path.name + ".complete").write_bytes(b"")
                value, consumed = future.result(timeout=2)
                self.assertEqual(value, result)
                self.assertEqual(consumed, path)
        finally:
            runtime.stop(event_id="consumer-cleanup", reason="Completed real file-consumer boundary test")

    def test_default_control_still_rejects_prompt_and_new_transport_has_no_public_prompt(self):
        # Rejection happens before any process/pipe access; these are real
        # public consumer guards, not mocked RPC results.
        control = OmpControl.__new__(OmpControl)
        rpc = TrialRpc.__new__(TrialRpc)
        for command in ("prompt", "open_session", "switch_session", "steer_subagent", "bash"):
            with self.subTest(command=command):
                with self.assertRaises(SafetyError):
                    control._send(command, {})
                with self.assertRaises(SafetyError):
                    rpc.request(command)

    def test_immutable_evidence_retains_predecessor_and_refuses_outside_run(self):
        path = self.root / "immutable.json"
        immutable_json(path, {"receipt": 1})
        with self.assertRaises(FileExistsError):
            immutable_json(path, {"receipt": 2})
        self.assertEqual(json.loads(path.read_text()), {"receipt": 1})
        with self.assertRaises(SafetyError):
            immutable_json(BUILD.parent / "unowned.json", {"receipt": 1})

    def test_exact_run_recovery_proves_real_native_job_exit_without_provider_replay(self):
        from .test_runtime import held
        runtime = TrialRuntime(self.root, self.ledger, Path("unused-native.exe"), {})
        owned = held(runtime.manager, revision=self.revision)
        runtime.register_process(owned, self.revision)
        result = recover(self.root, "Consumer crash recovery test")
        self.assertEqual(result["mode"], "STOPPED")
        record = runtime.manager.records()[0]
        self.assertTrue(record["exit_proof"]["observed_exit"])
        self.assertEqual(record["exit_proof"]["creation_time"], owned.record["creation_time"])
        self.assertEqual(self.ledger.snapshot()["trial"]["effects"], {})
        evidence = json.loads((self.root / "recovery.json").read_text())
        self.assertEqual(evidence["provider_effects_replayed"], 0)
        self.assertFalse(evidence["session_adoption"])
        owned.stop(grace=0)

    def test_trial_stop_cancels_actual_owned_work_without_releasing_unfinished_assignments(self):
        from .test_runtime import held
        runtime = TrialRuntime(self.root, self.ledger, Path("unused-native.exe"), {})
        owned = held(runtime.manager, revision=self.revision)
        runtime.register_process(owned, self.revision)
        result = runtime.stop(event_id="trial-consumer-stop", reason="Explicit native shutdown test")
        self.assertEqual(result["mode"], "STOPPED")
        self.assertTrue(owned.record["exit_proof"]["observed_exit"])
        self.assertEqual(self.ledger.assignments(), [])
        self.assertEqual(self.ledger.snapshot()["trial"]["claims"], {})

    def test_journal_parser_rejects_root_as_child_and_foreign_ancestry(self):
        # Synthetic FILE FORMAT fixtures, never a claim that a native agent ran.
        root_id, child_id = str(uuid.uuid4()), str(uuid.uuid4())
        root_file = self.root / "synthetic-root.jsonl"
        root_file.write_text(json.dumps({"type": "session", "id": root_id, "cwd": str(ACTIVE)}) + "\n")
        child_file = root_file.with_suffix("") / "synthetic-child.jsonl"
        child_file.parent.mkdir()
        child_file.write_text(json.dumps({"type": "session", "id": child_id, "cwd": "synthetic"}) + "\n")
        ready = {"root_journal": str(root_file), "root_session_id": root_id}
        event = {"registry_id": "SyntheticOwner", "native_kind": "sub", "parent_id": "Main",
                 "journal_ref": str(child_file), "session_id": child_id}
        title = json.dumps({"type": "title", "v": 1, "title": "", "updatedAt": "", "pad": ""}) + "\n"
        for prefix in ("", title):
            root_file.write_text(prefix + json.dumps({"type": "session", "id": root_id, "cwd": str(ACTIVE)}) + "\n")
            child_file.write_text(prefix + json.dumps({"type": "session", "id": child_id, "cwd": "synthetic"}) + "\n")
            parsed = validate_child(ready, event, "SyntheticOwner")
            self.assertEqual(parsed["session_id"], child_id)
            for changes in ({"journal_ref": str(root_file), "session_id": root_id},
                            {"native_kind": "main"}, {"parent_id": "AnotherRoot"},
                            {"session_id": str(uuid.uuid4())}, {"registry_id": "OtherOwner"}):
                with self.subTest(prefix=prefix, changes=changes), self.assertRaises(SafetyError):
                    validate_child(ready, dict(event, **changes), "SyntheticOwner")

    def test_journal_header_must_be_complete_real_session_type(self):
        path = self.root / "header.jsonl"
        for raw in ('{"type":"session"', json.dumps({"type": "message", "id": str(uuid.uuid4())}) + "\n",
                    json.dumps({"type": "session", "id": "fabricated-owner-name"}) + "\n"):
            path.write_text(raw)
            with self.subTest(raw=raw), self.assertRaises(SafetyError):
                journal_header(path)

    def test_journal_prefix_is_bounded_and_does_not_scan_for_identity(self):
        # Format-only adversarial fixtures; native compatibility is exercised separately.
        path = self.root / "bounded-prefix.jsonl"
        header = json.dumps({"type": "session", "id": str(uuid.uuid4())}) + "\n"
        title = json.dumps({"type": "title", "v": 1, "title": "", "updatedAt": "", "pad": ""}) + "\n"
        for raw in ("[]\n" + header, "{bad}\n" + header, title, title + title + header,
                    title + header.rstrip("\n"), title + "{}\n" + header,
                    '{"type":"title","v":1}\n' + header,
                    " " * 65537 + "\n" + header, title + " " * 65537 + header,
                    title + '{"type":"session","id":"not-a-uuid"}\n'):
            path.write_text(raw, encoding="utf-8")
            with self.subTest(prefix=raw[:100]), self.assertRaises(SafetyError):
                journal_header(path)
        path.write_bytes(b"\xff\n" + header.encode())
        with self.assertRaises(SafetyError):
            journal_header(path)
        path.write_text(title + header + "{unfinished later event", encoding="utf-8")
        self.assertEqual(journal_header(path)["id"], json.loads(header)["id"])


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned consumer verification required")
class RuntimeHistoryTests(unittest.TestCase):
    """Real durable ledger/file boundaries; native effects stop at a test tripwire."""
    def setUp(self):
        from .test_state import TrialLedgerTests
        self.fixture = TrialLedgerTests()
        self.fixture.setUp()
        self.runtime = None

    def runtime_for_claims(self):
        f = self.fixture
        self.runtime = TrialRuntime(f.root, f.ledger, Path("never-launched.exe"), {})
        for index in range(4):
            key = f"trial-{index}"
            directory = f.root / "native-contract" / key
            directory.mkdir(parents=True)
            immutable_json(directory / "reservation.json", f.manifest["reservations"][index])
            self.runtime.roots[key] = SimpleNamespace(directory=directory)
            self.runtime.ready[key] = {"root_session_id": f"root-{index}"}
            self.runtime.slots[key] = index
        self.runtime.prepared.update(self.runtime.roots)
        return self.runtime

    def test_unknown_preparation_uses_deferred_history_reference(self):
        from . import trial_runtime
        f = self.fixture
        f.manifest["reservations"][0]["history"] = {"status": "unknown", "evidence_refs": ["original-unknown"]}
        f.initial(activate=False)
        runtime = self.runtime_for_claims()
        identity = {"synthetic_workspace_identity": True}
        class NativeBoundaryReached(Exception):
            pass
        def inspect_launch(key, operation, **values):
            self.assertEqual((key, operation), ("trial-0", "launch"))
            self.assertIn(str(runtime.roots[key].directory / "dispatch-history.json"), values["task"])
            self.assertIn(str(runtime.roots[key].directory / "reservation.json"), values["task"])
            self.assertNotIn('"effective_history"', values["task"])
            self.assertNotIn('"status": "unknown"', values["task"])
            self.assertFalse((runtime.roots[key].directory / "dispatch-history.json").exists())
            raise NativeBoundaryReached()
        with patch.object(trial_runtime, "require_fresh_workspace"), \
             patch.object(trial_runtime, "validate_approval"), \
             patch.object(trial_runtime, "validate_runtime_identity"), \
             patch.object(runtime, "create_workspace", return_value=identity), \
             patch.object(runtime, "workspace_identity", return_value=identity), \
             patch.object(runtime, "native_command", side_effect=inspect_launch):
            runtime.launch_contract = {"runtime": {}}
            with self.assertRaises(NativeBoundaryReached):
                runtime.start_assignment("trial-0")
        self.assertFalse(any(effect["kind"] == "prompt" for effect in f.ledger.snapshot()["trial"]["effects"].values()))

    def test_release_persists_exact_history_for_same_owner_before_native_boundary(self):
        f = self.fixture
        f.initial(prompts=False)
        f.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"trial-{i}-initial" for i in range(4)},
                                    event_id=f.event(), authorization_revision=f.auth["revision"])
        runtime = self.runtime_for_claims()
        runtime.held.add("trial-0")
        class NativeBoundaryReached(Exception):
            pass
        def inspect_release(key, operation, **values):
            self.assertEqual((key, operation, values["session_id"]), ("trial-0", "release", "child-0"))
            path = runtime.roots[key].directory / "dispatch-history.json"
            self.assertTrue(path.is_file(), "First provider release preceded canonical history publication")
            payload = json.loads(path.read_text())
            self.assertEqual(payload["assignment_id"], key)
            self.assertEqual(payload["owner_id"], "owner-0")
            self.assertEqual(payload["session_id"], "child-0")
            self.assertEqual(payload["root_session_id"], "root-0")
            self.assertEqual(payload["manifest_digest"], f.digest)
            self.assertEqual(payload["authorization_revision"], f.auth["revision"])
            self.assertEqual(payload["effective_history"], f.ledger.trial_history(key))
            self.assertIsNone(payload["history_resolution"])
            self.assertEqual(payload["original_reservation_ref"], str(runtime.roots[key].directory / "reservation.json"))
            raise NativeBoundaryReached()
        with patch.object(runtime, "verify_observer"), patch.object(runtime, "native_command", side_effect=inspect_release):
            with self.assertRaises(NativeBoundaryReached):
                runtime.release_provider("trial-0")

    def test_unknown_history_cannot_cross_release_boundary(self):
        f = self.fixture
        f.manifest["reservations"][0]["history"] = {"status": "unknown", "evidence_refs": ["original-unknown"]}
        f.initial(activate=False)
        f.attach(0)
        runtime = self.runtime_for_claims()
        runtime.held.add("trial-0")
        with patch.object(runtime, "verify_observer"), \
             patch.object(runtime, "native_command", side_effect=AssertionError("Unresolved owner reached release")):
            with self.assertRaises(SafetyError):
                runtime.release_provider("trial-0")
        self.assertFalse((runtime.roots["trial-0"].directory / "dispatch-history.json").exists())

    def test_stop_during_history_publication_cannot_release(self):
        from . import trial_runtime
        from .policy import PolicyError
        f = self.fixture
        f.initial(prompts=False)
        f.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"trial-{i}-initial" for i in range(4)},
                                    event_id=f.event(), authorization_revision=f.auth["revision"])
        runtime = self.runtime_for_claims()
        runtime.held.add("trial-0")
        def stopped_after_record(path, value):
            immutable_json(path, value)
            f.ledger.request_stop(event_id="stop-at-history-publication", reason="Synthetic native-boundary race")
        def forbidden_native(_path):
            raise AssertionError("STOP or missing canonical history reached native command")
        runtime.roots["trial-0"].local_command = forbidden_native
        with patch.object(runtime, "verify_observer"), patch.object(trial_runtime, "immutable_json", side_effect=stopped_after_record):
            with self.assertRaises(PolicyError):
                runtime.release_provider("trial-0")
        self.assertTrue((runtime.roots["trial-0"].directory / "dispatch-history.json").is_file())
        self.assertEqual(f.ledger.authorization()["mode"], "STOPPING")

    def test_unknown_queued_history_does_not_block_zero_provider_refill_root(self):
        f = self.fixture
        f.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["queued-unknown"]}
        f.pushed()
        f.observe("ack")
        f.observe("cleanup")
        f.exit()
        f.observe("closed")
        runtime = self.runtime_for_claims()
        observed = []
        registration = f.root / "synthetic-empty-registration.json"
        registration.write_text('{"sessions":[]}', encoding="utf-8")
        runtime.launch_contract = {"observer": {"registration": str(registration)}}
        entered, release = threading.Event(), threading.Event()
        def prepared_boundary(row, slot):
            observed.append((row["assignment_id"], slot))
            entered.set()
            if not release.wait(10):
                raise TimeoutError("Scheduler test did not release its preparation boundary")
        with patch.object(runtime, "prepare", side_effect=prepared_boundary):
            try:
                runtime.prepare_refill()
                self.assertTrue(entered.wait(5))
                self.assertFalse(runtime.refill_jobs["trial-4"][1].done())
                self.assertEqual(observed, [("trial-4", 0)])
            finally:
                release.set()
                runtime.refill_jobs["trial-4"][1].result(timeout=10)
                runtime.refill_pool.shutdown()
        self.assertNotIn("trial-4", f.ledger.snapshot()["trial"]["claims"])

    def test_recorded_resolution_is_exposed_to_same_held_owner_at_release(self):
        from .test_state import recorded_trial_history
        f = self.fixture
        for reservation in f.manifest["reservations"]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["original-unknown"]}
        f.initial(activate=False)
        for index in range(4):
            f.attach(index)
            f.ledger.resolve_trial_history(f"trial-{index}", history=recorded_trial_history(f.root),
                                           record=f.history_resolution_record(index), event_id=f.event())
        f.ledger.activate_trial(gates=f.gates, event_id=f.event(), authorization_revision=f.auth["revision"])
        f.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"trial-{i}-initial" for i in range(4)},
                                    event_id=f.event(), authorization_revision=f.auth["revision"])
        runtime = self.runtime_for_claims()
        runtime.held.add("trial-0")
        class NativeBoundaryReached(Exception):
            pass
        def inspect_release(key, operation, **values):
            payload = json.loads((runtime.roots[key].directory / "dispatch-history.json").read_text())
            snapshot = f.ledger.snapshot()
            self.assertEqual(payload["session_id"], "child-0")
            self.assertEqual(values["session_id"], "child-0")
            self.assertEqual(payload["effective_history"], f.ledger.trial_history(key))
            self.assertEqual(payload["effective_history"]["status"], "recorded")
            self.assertEqual(payload["effective_history"]["lifetime_totals"], "unknown")
            self.assertEqual(payload["history_resolution"], snapshot["trial"]["history_resolutions"][key])
            self.assertEqual(payload["provider_admission"], snapshot["trial"]["effects"][key + "-initial"])
            original = json.loads(Path(payload["original_reservation_ref"]).read_text())
            self.assertEqual(original["history"]["status"], "unknown")
            self.assertEqual(snapshot["trial"]["manifest"], f.manifest)
            raise NativeBoundaryReached()
        with patch.object(runtime, "verify_observer"), patch.object(runtime, "native_command", side_effect=inspect_release):
            with self.assertRaises(NativeBoundaryReached):
                runtime.release_provider("trial-0")
