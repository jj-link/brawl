"""Real file/SQLite/scheduling boundaries; synthetic admissions are not native-agent proof."""
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import threading
from types import SimpleNamespace
import unittest
from unittest.mock import patch
import uuid

from .safety import SafetyError, now, save_json
from .test_state import WorkflowFixture
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned behavioral verification required")
class TrialWorkflowBoundaryTests(unittest.TestCase):
    def setUp(self):
        self.f = WorkflowFixture()
        self.f.start()
        self.runtime = TrialRuntime(self.f.root, self.f.ledger, Path("not-a-native-host.exe"), {})

    def tearDown(self):
        self.runtime.workflow.shutdown()
        self.runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
        self.runtime.manager.stop_all()

    def test_failed_native_result_is_not_discarded_with_action_left_admitted(self):
        self.f.capture()
        self.f.validate()
        action = self.f.admit()
        self.assertEqual(action["kind"], "prepare_review")
        directory = self.f.root / "native" / "explicit-format-fixture"
        directory.mkdir(parents=True)
        identifier = uuid.uuid4().hex
        result = {"id": identifier, "operation": "prepare-review", "workflow_effect_id": action["effect_id"],
                  "success": False, "error": "Explicit file-format failure fixture; no native task ran"}
        path = directory / ("result-" + identifier + ".json")
        save_json(path, result)
        event = {"kind": "local_result", "id": identifier, "operation": result["operation"],
                 "workflow_effect_id": action["effect_id"], "success": False,
                 "result_ref": str(path), "observed_at": now()}
        journal = directory / "native-events.jsonl"
        journal.write_text(json.dumps(event) + "\n", encoding="utf-8")
        self.assertTrue(self.runtime.workflow.native_event("trial-0", event, journal),
                        "Actual failure-file consumer discarded its admitted workflow effect")
        self.runtime.workflow.process_native("trial-0", event, str(journal))
        stored = self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]
        self.assertEqual(stored["status"], "uncertain")
        self.assertEqual(stored["result"]["native_failure_ref"], str(path))
        self.assertFalse(self.f.ledger.trial_readiness("trial-0")["ready"])

    def test_review_cannot_cross_native_boundary_without_owned_listener(self):
        from .test_runtime import held
        self.f.capture()
        self.f.validate()
        self.f.prepare_review()
        action = self.f.admit()
        action.pop("execute")
        self.assertEqual(action["kind"], "review")
        owned = held(self.runtime.manager, revision=self.f.ledger.authorization()["revision"])
        self.runtime.register_process(owned, self.f.ledger.authorization()["revision"])
        directory = self.f.root / "native" / "no-listener-owned-job"
        directory.mkdir(parents=True)
        class ForbiddenNativeBoundary(Exception):
            pass
        def forbidden(_path):
            raise ForbiddenNativeBoundary("Review crossed native command boundary before positive listener proof")
        self.runtime.roots["trial-0"] = SimpleNamespace(directory=directory, owned=owned, local_command=forbidden)
        self.runtime.ready["trial-0"] = {"root_session_id": "explicit-synthetic-root", "observer_port": 49152}
        with self.assertRaises(SafetyError):
            self.runtime.workflow.dispatch(action)
        self.assertFalse(list(directory.glob("command-*.json")))
        self.assertIsNone(owned.process.poll(), "Negative listener proof must not pretend job exit")

    def test_completed_refill_claim_is_not_resubmitted_from_stale_snapshot(self):
        self.f.reviewed()
        self.f.materialize()
        self.f.publish()
        self.f.cleanup()
        self.f.close()
        runtime, ledger = self.runtime, self.f.ledger
        runtime.prepared.update(f"trial-{index}" for index in range(5))
        runtime.refill_slots["trial-4"] = 0
        runtime.slots["trial-4"] = 0
        runtime.observed.add("trial-4")
        runtime.ready["trial-4"] = {"root_session_id": "root-4"}
        registration = self.f.root / "empty-registration.json"
        save_json(registration, {"sessions": []})
        runtime.launch_contract = {"observer": {"registration": str(registration)}}
        release = threading.Event()
        original = ledger.snapshot
        first = True
        def claim():
            if not release.wait(10):
                raise TimeoutError("Test did not permit its real SQLite claim")
            return ledger.claim_trial_refill(claim=self.f.case.claim(4, 0), event_id="racing-real-claim",
                                              authorization_revision=ledger.authorization()["revision"])
        with ThreadPoolExecutor(max_workers=1) as pool:
            future = pool.submit(claim)
            runtime.refill_jobs["trial-4"] = ("child", future)
            def snapshot_then_finish():
                nonlocal first
                value = original()
                if first:
                    first = False
                    release.set()
                    future.result(timeout=10)
                return value
            with patch.object(ledger, "snapshot", side_effect=snapshot_then_finish):
                runtime.prepare_refill()
        self.assertIn("trial-4", ledger.snapshot()["trial"]["claims"])
        self.assertNotIn("trial-4", runtime.refill_jobs, "Stale snapshot scheduled a second child start")
        self.assertNotIn("trial-4", runtime.refill_failures)

    def test_malformed_actual_delivery_is_archived_and_routes_same_owner_without_attempt(self):
        workspace = Path(self.f.case.manifest["reservations"][0]["workspace"])
        path = workspace / "evidence/controller-delivery.json"
        path.parent.mkdir(parents=True, exist_ok=True)
        raw = b'{"unterminated":'
        path.write_bytes(raw)
        before = self.f.ledger.assignment("trial-0")["stages"]
        record = self.f.owner_record()
        self.runtime.workflow.capture_delivery("trial-0", record["native_event"], record)
        state = self.f.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]
        failure = state["delivery_errors"]["prompt-0"]["error"]
        self.assertEqual(Path(failure["archive"]["path"]).read_bytes(), raw)
        self.assertTrue(failure["reason"])
        self.assertEqual(self.f.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertEqual(self.f.ledger.assignment("trial-0")["owner_id"], "owner-0")
        self.assertEqual(self.f.ledger.assignment("trial-0")["stages"], before)

    def test_timing_envelope_is_refused_and_host_consumer_rechecks_retained_bytes(self):
        from .trial import report
        event = {"kind": "native_interval", "owner": "owner-0", "session_id": "child-0",
                 "phase": "model_execution", "started_at": now(), "observed_at": now(),
                 "qualification": "Explicit native-format fixture; no model ran"}
        envelope = {"event_id": "forged-timing", "operation": "event", "assignment_id": "trial-0",
                    "owner_id": "owner-0", "session_id": "child-0", "manifest_digest": self.f.case.digest,
                    "payload": {"kind": "interval", "record": dict(event, owner_id="owner-0")}}
        before = self.f.ledger.snapshot()["event_count"]
        with self.assertRaises(SafetyError):
            report(self.f.root, envelope)
        self.assertEqual(self.f.ledger.snapshot()["event_count"], before)
        path = self.f.root / "explicit-native-format.jsonl"
        raw = (json.dumps(event) + "\n").encode()
        path.write_bytes(raw)
        self.runtime.workflow.native_event("trial-0", event, path, raw=raw)
        key, native, reference = self.runtime.workflow.events.pop()
        self.runtime.workflow.process_native(key, native, reference)
        accepted = self.f.ledger.snapshot()["event_count"]
        self.assertGreater(accepted, before)
        Path(reference).write_bytes(b'{"changed":true}\n')
        with self.assertRaises(SafetyError):
            self.runtime.workflow.process_native(key, native, reference)
        self.assertEqual(self.f.ledger.snapshot()["event_count"], accepted)

    def review_boundary(self, *, finalized=True):
        from .safety import digest
        self.f.capture()
        self.f.validate()
        self.f.prepare_review()
        action = self.f.admit()
        action.pop("execute")
        directory = self.f.root / "native" / "explicit-review-format-fixture"
        directory.mkdir(parents=True)
        self.runtime.roots["trial-0"] = SimpleNamespace(directory=directory)
        _, decision, _ = self.runtime.workflow.review_paths("trial-0", action["binding"]["delivery_id"])
        save_json(decision, {"delivery_id": action["binding"]["delivery_id"], "effect_id": action["effect_id"],
            "reviewer_id": action["reviewer"]["owner_id"], "session_id": action["reviewer"]["session_id"],
            "decision": "approve", "findings": [],
            "reviewed_criteria": sorted(action["binding"]["unresolved_criteria"])})
        native = {"kind": "reviewer_turn_end", "registry_id": action["reviewer"]["owner_id"],
            "session_id": action["reviewer"]["session_id"], "journal_ref": action["reviewer"]["journal_ref"],
            "root_session_id": "root-0", "request_id": action["effect_id"], "will_continue": False,
            "started_at": action["admitted_at"], "observed_at": now()}
        if finalized:
            command = uuid.uuid4().hex
            result = directory / ("result-" + command + ".json")
            lifecycle = directory / ("lifecycle-" + action["effect_id"] + ".json")
            save_json(result, {"id": command, "operation": "prepare-review",
                "workflow_effect_id": action["effect_id"], "success": True, "task_result_required": True,
                "result": {"details": {"results": [{"exitCode": 0, "aborted": False}]}}})
            save_json(lifecycle, {"request_id": action["effect_id"], "payload": {
                "id": native["registry_id"], "sessionFile": native["journal_ref"], "status": "completed"}})
            native["native_completion"] = {"source": "native-task-finalization", "success": True,
                "command_id": command, "command_result_ref": str(result), "command_result_sha256": digest(result),
                "lifecycle_ref": str(lifecycle), "lifecycle_sha256": digest(lifecycle)}
        journal = directory / "native-events.jsonl"
        journal.write_text(json.dumps(native) + "\n", encoding="utf-8")
        return action, native, journal, decision

    def test_agent_end_alone_cannot_accept_review_before_native_task_settlement(self):
        action, native, journal, _ = self.review_boundary(finalized=False)
        with self.assertRaises(SafetyError):
            self.runtime.workflow.process_native("trial-0", native, str(journal))
        self.assertEqual(self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]["status"],
                         "admitted")

    def test_malformed_final_review_is_failed_without_escaping_controller_tick(self):
        action, native, journal, decision = self.review_boundary()
        decision.write_text("[]", encoding="utf-8")
        self.runtime.workflow.native_event("trial-0", native, journal)
        self.runtime.workflow.tick()
        stored = self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]
        self.assertEqual(stored["status"], "failed")
        self.assertIn("error", stored["result"])
        self.assertIsNone(self.f.ledger.assignment("trial-0")["materialization"])

    def test_refill_without_registration_authority_is_explicitly_blocked_not_silently_idle(self):
        self.f.reviewed()
        self.f.materialize()
        self.f.publish()
        self.f.cleanup()
        self.f.close()
        self.runtime.prepared.update(f"trial-{index}" for index in range(5))
        self.runtime.refill_slots["trial-4"] = 0
        self.runtime.slots["trial-4"] = 0
        self.runtime.ready["trial-4"] = {"root_session_id": "unregistered-fixture-root"}
        registry = self.f.root / "empty-registration.json"
        save_json(registry, {"sessions": []})
        self.runtime.launch_contract = {"observer": {"registration": str(registry)}}
        self.runtime.prepare_refill()
        for phase, future in list(self.runtime.refill_jobs.values()):
            try:
                future.result(timeout=10)
            except SafetyError:
                pass
        self.runtime.prepare_refill()
        self.assertIn("trial-4", self.runtime.refill_failures)
        self.assertIn("grant", self.runtime.refill_failures["trial-4"]["error"].lower())

    def test_failed_final_task_cannot_accept_already_written_approve_decision(self):
        from .safety import digest
        action, native, journal, _ = self.review_boundary()
        path = Path(native["native_completion"]["command_result_ref"])
        result = json.loads(path.read_bytes())
        result["success"] = False
        result["result"]["details"]["results"][0]["exitCode"] = 1
        save_json(path, result)
        native["native_completion"].update(success=False, command_result_sha256=digest(path))
        self.runtime.workflow.native_event("trial-0", native, journal)
        self.runtime.workflow.tick()
        stored = self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]
        self.assertEqual(stored["status"], "failed")
        self.assertIsNone(self.f.ledger.assignment("trial-0")["review"])
        self.assertIsNone(self.f.ledger.assignment("trial-0")["materialization"])

    def test_live_and_recovery_decision_parser_refuses_all_malformed_shapes(self):
        from .trial_completion import review_decision
        action, _, _, path = self.review_boundary()
        valid = json.loads(path.read_bytes())
        for value in ([], None, {}, dict(valid, decision=[]), dict(valid, findings={}),
                      dict(valid, findings=[{"criterion": [], "path": "", "reason": "bad"}]),
                      dict(valid, reviewed_criteria=[]),
                      dict(valid, reviewed_criteria=valid["reviewed_criteria"] * 2),
                      dict(valid, reviewed_criteria=valid["reviewed_criteria"] + ["compile"]),
                      dict(valid, decision="reject", findings=[{
                          "criterion": "compile", "path": "", "reason": "A model cannot waive or replace compilation"}])):
            with self.subTest(value=value):
                save_json(path, value)
                with self.assertRaises(SafetyError):
                    review_decision(path, action)
        save_json(path, valid)
        self.assertEqual(review_decision(path, action)["decision"], "approve")

    def test_review_packet_contains_only_exact_unresolved_judgments(self):
        from .trial_delivery import WorkerDelivery
        action, _, _, _ = self.review_boundary()
        state = self.f.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]
        delivery = WorkerDelivery.from_dict(state["deliveries"][action["binding"]["delivery_id"]]["delivery"])
        task, decision, _ = self.runtime.workflow.review_task(action, delivery)
        scope = json.loads((decision.parent / (action["effect_id"] + "-judgments.json")).read_bytes())
        self.assertEqual(scope["unresolved_criteria"], action["binding"]["unresolved_criteria"])
        self.assertNotIn("compile", scope["unresolved_criteria"])
        self.assertIn("cannot be waived", task)
        self.assertIn("reviewed_criteria", task)
        with self.assertRaises(SafetyError):
            self.runtime.workflow.review_task(dict(action, binding=dict(action["binding"], unresolved_criteria={})), delivery)

    def test_unsettled_turn_stays_uncertain_without_freeing_reviewer_capacity(self):
        action, native, journal, _ = self.review_boundary(finalized=False)
        self.runtime.workflow.native_event("trial-0", native, journal)
        self.runtime.workflow.tick()
        stored = self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]
        self.assertEqual(stored["status"], "uncertain")
        self.assertEqual(self.f.ledger.trial_prompt_readiness()["reason"], "model_capacity")
