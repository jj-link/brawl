"""Owned registry/SQLite fixtures; these are NOT genuine child or observer proof."""
import copy
import hashlib
import json
import os
from pathlib import Path
import threading
import unittest
from unittest.mock import patch
import uuid

from .processes import runtime_lock
from .safety import SafetyError, now, save_json
from .test_state import WorkflowFixture
from .trial_registration import RegistrationAdapter, encoded, retain
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Exact owned fixture authorization required")
class TrialRegistrationTests(unittest.TestCase):
    def setUp(self):
        self.f = WorkflowFixture()
        self.f.start()
        self.runtime = TrialRuntime(self.f.root, self.f.ledger, Path("never-a-native-host.exe"), {})
        self.adapter = self.runtime.registrations
        self.registry = self.f.root / "observer-fixture" / "independent-roots.json"
        self.lock = self.registry.parent / "writer-lock"
        self.foreign = {"id": str(uuid.uuid4()), "label": "unrelated-observer", "observerPort": 21000,
                        "opaque": {"preserve": [1, 2, 3]}}
        self.original = {"sessions": [self.foreign], "owner_metadata": {"must_survive": True}}
        save_json(self.registry, self.original)
        self.value = {"schema": "brawl-controller-registration-grant/v1", "run_id": self.f.root.name,
            "manifest_digest": self.f.case.digest, "controller_id": "coordinator", "owner_id": "fixture-CARDS",
            "registry_path": str(self.registry), "lock_directory": str(self.lock),
            "writer_boundary": "all-registry-writers-share-lock",
            "assignment_ids": [f"trial-{i}" for i in range(8)], "slots": [
                {"slot": i, "port": 21001 + i, "initial_assignment_id": f"trial-{i}",
                 "initial_root_session_id": str(uuid.uuid4()), "initial_native_pid": 100 + i,
                 "initial_native_creation_time": str(10000 + i)} for i in range(4)]}
        raw = encoded(self.value)
        pointer = {"path": str(self.f.root / "fixture-grant-source.json"), "sha256": hashlib.sha256(raw).hexdigest()}
        retain(Path(pointer["path"]), raw)
        self.event_id = "fixture-registration-" + uuid.uuid4().hex
        envelope = {"event_id": self.event_id, "manifest_digest": self.f.case.digest,
                    "assignment_id": "trial-0", "operation": "observe", "payload": {
                        "port": 21001, "registration_grant": pointer}}
        content = encoded(envelope)
        self.f.ledger.admit_trial_delivery(event_id=self.event_id, role="coordinator", envelope=envelope,
            content_sha256=hashlib.sha256(content).hexdigest(), authorization_revision=1)
        self.f.ledger.consume_trial_delivery(event_id=self.event_id, role="coordinator", envelope=envelope,
            content_sha256=hashlib.sha256(content).hexdigest())
        # Storage-only setup deliberately does NOT call bind()/claim genuine roots.
        retain(self.adapter.root / "grant.json", raw)
        retain(self.adapter.root / "grant-admission.json", encoded({"event_id": self.event_id, "pointer": pointer}))
        self.row = {"id": self.value["slots"][0]["initial_root_session_id"], "label": "fixture-trial",
                    "observerPort": 21001, "controllerTrial": {
                        "run_id": self.f.root.name, "controller_id": "coordinator", "assignment_id": "trial-0",
                        "slot": 0, "process_id": "process-0", "root_session_id": self.value["slots"][0]["initial_root_session_id"]}}
        retain(self.adapter.root / "trial-0" / "owned-row.json", encoded({"row": self.row,
            "process_id": "process-0", "grant_sha256": pointer["sha256"]}))

    def tearDown(self):
        self.runtime.workflow.shutdown()
        self.runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
        self.f.case.tearDown()

    def publish(self):
        with runtime_lock(self.lock, scope=self.lock, timeout=1):
            _, before, registry = self.adapter.read_registry(self.value)
            registry["sessions"].append(self.row)
            self.adapter.publish(self.value, before, registry, "trial-0", "register")

    def exited(self):
        self.f.reviewed()
        self.f.materialize()
        self.f.publish()
        self.f.cleanup()
        process = self.f.ledger.process("process-0")
        self.f.ledger.record_process_exit("process-0", event_id=self.f.case.event(), proof={
            **process["identity"], "process_id": "process-0", "observed_exit": True, "exit_code": 0,
            "verified_at": now(), "evidence_ref": "synthetic-exit-0"})
        self.f.close()
        return self.f.ledger.snapshot()["processes"]["process-0"]["exit_proof"]

    def test_atomic_registry_publication_preserves_foreign_rows_and_top_level_fields(self):
        self.publish()
        actual = json.loads(self.registry.read_bytes())
        self.assertEqual(actual["sessions"], [self.foreign, self.row])
        self.assertEqual(actual["owner_metadata"], self.original["owner_metadata"])
        receipts = list((self.adapter.root / "trial-0").glob("*/complete.json"))
        self.assertEqual(len(receipts), 1)
        self.assertEqual(json.loads((receipts[0].parent / "before.json").read_bytes()), self.original)
        self.assertEqual((receipts[0].parent / "after.json").read_bytes(), self.registry.read_bytes())
        self.assertEqual(self.runtime.manager.records(), [])

    def test_stale_preimage_and_hardlink_alias_refuse_without_overwriting_registry(self):
        _, before, registry = self.adapter.read_registry(self.value)
        registry["owner_metadata"]["foreign_update"] = 42
        save_json(self.registry, registry)
        actual = self.registry.read_bytes()
        with self.assertRaises(SafetyError):
            self.adapter.publish(self.value, before, self.original, "trial-0", "register")
        self.assertEqual(self.registry.read_bytes(), actual)
        alias = self.registry.with_name("alias.json")
        os.link(self.registry, alias)
        with self.assertRaises(ValueError):
            self.adapter.validate_grant(self.value)
        self.assertEqual(alias.read_bytes(), actual)

    def test_closure_requires_exit_and_preserves_foreign_owned_row_edits(self):
        self.publish()
        before = self.registry.read_bytes()
        with self.assertRaises(SafetyError):
            self.adapter.close("trial-0", {"observed_exit": True, "process_id": "process-0"})
        self.assertEqual(self.registry.read_bytes(), before)
        proof = self.exited()
        value = json.loads(before)
        value["sessions"][1]["foreign_note"] = "retain me"
        save_json(self.registry, value)
        drift = self.registry.read_bytes()
        with self.assertRaises(SafetyError):
            self.adapter.close("trial-0", proof)
        self.assertEqual(self.registry.read_bytes(), drift)

    def test_interrupted_actual_replace_recovers_exact_row_only_after_exit(self):
        replace = os.replace
        def interrupted(source, destination):
            replace(source, destination)
            raise OSError("Controlled fixture interruption after actual atomic replacement")
        with patch("tools.orchestration_eval.trial_registration.os.replace", side_effect=interrupted):
            with self.assertRaises(OSError):
                self.publish()
        self.assertEqual(json.loads(self.registry.read_bytes())["sessions"], [self.foreign, self.row])
        self.assertFalse(list((self.adapter.root / "trial-0").glob("*/complete.json")))
        self.exited()
        outcomes = RegistrationAdapter(self.runtime).close_exited()
        self.assertTrue(outcomes[0]["result"]["row_absent"])
        self.assertEqual(json.loads(self.registry.read_bytes()), self.original)
        self.assertTrue(RegistrationAdapter(self.runtime).close_exited()[0]["result"]["row_absent"])

    def test_contended_writer_lock_blocks_registration_without_native_or_observer_work(self):
        ready, release = threading.Event(), threading.Event()
        def hold():
            with runtime_lock(self.lock, scope=self.lock, timeout=1):
                ready.set()
                release.wait(5)
        thread = threading.Thread(target=hold)
        thread.start()
        try:
            self.assertTrue(ready.wait(2))
            self.runtime.slots["trial-4"] = 0
            with self.assertRaises(TimeoutError):
                self.adapter.register("trial-4")
            self.assertEqual(json.loads(self.registry.read_bytes()), self.original)
            self.assertEqual(self.runtime.manager.records(), [])
        finally:
            release.set()
            thread.join(timeout=3)
            self.assertFalse(thread.is_alive())

    def test_retained_grant_cannot_be_rebound_and_stop_prevents_refill_writes(self):
        self.assertEqual(self.adapter.grant(), self.value)
        before = self.registry.read_bytes()
        self.f.ledger.request_stop(event_id="registration-fixture-stop", reason="Owned fixture STOP")
        self.runtime.slots["trial-4"] = 0
        with self.assertRaises((ValueError, RuntimeError)):
            self.adapter.register("trial-4")
        self.assertEqual(self.registry.read_bytes(), before)
        changed = copy.deepcopy(self.value)
        changed["slots"][0]["port"] += 100
        (self.adapter.root / "grant.json").write_bytes(encoded(changed))
        with self.assertRaises(SafetyError):
            self.adapter.grant()
