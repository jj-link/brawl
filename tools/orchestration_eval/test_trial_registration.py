"""Real owned file/socket/SQLite boundaries; never genuine agent or observer proof."""
import copy
import hashlib
import json
import os
from pathlib import Path
import socket
import threading
import unittest
from unittest.mock import patch
import uuid

from .safety import SafetyError, now, save_json
from .test_state import WorkflowFixture
from .trial_registration import (RegistrationAdapter, RegistryConflict, atomic_registry_update,
                                 encoded, registration_scope, retain)
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Exact owned fixture authorization required")
class TrialRegistrationTests(unittest.TestCase):
    def setUp(self):
        self.f = WorkflowFixture()
        self.f.start()
        self.registry = self.f.root / "observer-fixture" / "independent-roots.json"
        self.foreign = {"id": str(uuid.uuid4()), "label": "unrelated-observer", "observerPort": 21000,
                        "opaque": {"preserve": [1, 2, 3]}}
        self.original = {"sessions": [self.foreign], "owner_metadata": {"must_survive": True}}
        save_json(self.registry, self.original)
        manifest = self.f.ledger.snapshot()["trial"]["manifest"]
        scope = registration_scope(manifest, self.registry)
        self.runtime = TrialRuntime(self.f.root, self.f.ledger, Path("never-a-native-host.exe"),
                                    {"observer": {"registration": str(self.registry)}, "registration": scope})
        self.adapter = self.runtime.registrations
        self.value = {"schema": "brawl-controller-registration-authority/v1", "run_id": self.f.root.name,
            "manifest_digest": self.f.case.digest, "controller_id": "coordinator", "scope": scope,
            "initial_roots": {key: {"root_session_id": str(uuid.uuid4())} for key in scope["assignment_ids"][:4]}}
        raw = encoded(self.value)
        self.authority_hash = hashlib.sha256(raw).hexdigest()
        # Storage fixture only: never call creation/identity and claim synthetic roots are real.
        retain(self.adapter.root / "authority.json", raw)
        retain(self.adapter.root / "authority-identity.json", encoded({"sha256": self.authority_hash}))
        self.row = {"id": self.value["initial_roots"]["trial-0"]["root_session_id"], "label": "fixture-trial",
                    "observerPort": 21001, "controllerTrial": {
                        "run_id": self.f.root.name, "controller_id": "coordinator", "assignment_id": "trial-0",
                        "slot": 0, "process_id": "process-0"}}
        self.retain_ownership(self.row)

    def retain_ownership(self, row):
        retain(self.adapter.root / "trial-0" / ("owned-row-" + uuid.uuid4().hex + ".json"),
               encoded({"row": row, "process_id": "process-0", "authority_sha256": self.authority_hash}))

    def tearDown(self):
        for key in list(self.adapter.reservations):
            self.adapter.release_reservation(key)
        self.runtime.workflow.shutdown()
        self.runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
        self.f.case.tearDown()

    def publish(self, authorize=lambda: None):
        _, before, registry = self.adapter.read_registry(self.value)
        registry["sessions"].append(self.row)
        self.adapter.publish(self.value, before, registry, "trial-0", "register", authorize)

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

    def test_native_transaction_excludes_uncooperative_writers_and_keeps_old_reader_view(self):
        before = self.registry.read_bytes()
        contender = self.registry.with_name("contender.json")
        contender.write_bytes(encoded({"foreign_writer": True}))
        def during_transaction():
            self.assertEqual(self.registry.read_bytes(), before)
            with self.assertRaises(OSError):
                self.registry.write_bytes(b"uncooperative writer")
            with self.assertRaises(OSError) as conflict:
                os.replace(contender, self.registry)
            self.assertEqual(conflict.exception.winerror, 6800)
            self.assertEqual(self.registry.read_bytes(), before)
        self.publish(during_transaction)
        self.assertEqual(json.loads(self.registry.read_bytes())["sessions"], [self.foreign, self.row])
        self.assertEqual(contender.read_bytes(), encoded({"foreign_writer": True}))

    def test_authorization_failure_rolls_back_invisible_pending_registration(self):
        before = self.registry.read_bytes()
        revision = self.f.ledger.authorization()["revision"]
        def stop_before_commit():
            self.assertEqual(self.registry.read_bytes(), before)
            self.f.ledger.request_stop(event_id="registration-stop-at-commit", reason="Owned transaction boundary")
            self.f.ledger.require_operation("launch", authorization_revision=revision)
        with self.assertRaises((ValueError, RuntimeError)):
            self.publish(stop_before_commit)
        self.assertEqual(self.registry.read_bytes(), before)
        self.assertFalse(list((self.adapter.root / "trial-0").glob("*/complete.json")))

    def test_stale_preimage_and_hardlink_alias_refuse_without_overwriting_registry(self):
        _, before, registry = self.adapter.read_registry(self.value)
        registry["owner_metadata"]["foreign_update"] = 42
        save_json(self.registry, registry)
        actual = self.registry.read_bytes()
        with self.assertRaises(RegistryConflict):
            self.adapter.publish(self.value, before, self.original, "trial-0", "register", lambda: None)
        self.assertEqual(self.registry.read_bytes(), actual)
        alias = self.registry.with_name("alias.json")
        os.link(self.registry, alias)
        with self.assertRaises(SafetyError):
            self.adapter.authority()
        self.assertEqual(alias.read_bytes(), actual)

    def test_competing_native_transaction_cannot_overwrite_committed_foreign_update(self):
        before = self.registry.read_bytes()
        foreign = copy.deepcopy(self.original)
        foreign["concurrent_field"] = "must survive"
        entered, release = threading.Event(), threading.Event()
        failures = []
        def hold():
            entered.set()
            if not release.wait(1):
                raise RuntimeError("Owned contention fixture did not release")
        def writer():
            try:
                atomic_registry_update(self.registry, before, encoded(foreign), hold)
            except BaseException as error:
                failures.append(error)
        thread = threading.Thread(target=writer)
        thread.start()
        try:
            self.assertTrue(entered.wait(1))
            with self.assertRaises(RegistryConflict):
                self.publish()
        finally:
            release.set()
            thread.join(timeout=3)
        self.assertFalse(thread.is_alive())
        self.assertEqual(failures, [])
        self.assertEqual(json.loads(self.registry.read_bytes()), foreign)
        self.publish()
        actual = json.loads(self.registry.read_bytes())
        self.assertEqual(actual["concurrent_field"], "must survive")
        self.assertEqual(actual["sessions"], [self.foreign, self.row])

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

    def test_interrupted_actual_commit_recovers_exact_row_only_after_exit(self):
        original_retain = retain
        def interrupted(path, raw):
            if path.name == "complete.json":
                raise OSError("Controlled fixture interruption after actual native commit")
            return original_retain(path, raw)
        with patch("tools.orchestration_eval.trial_registration.retain", side_effect=interrupted):
            with self.assertRaises(OSError):
                self.publish()
        self.assertEqual(json.loads(self.registry.read_bytes())["sessions"], [self.foreign, self.row])
        self.assertFalse(list((self.adapter.root / "trial-0").glob("*/complete.json")))
        self.exited()
        outcomes = RegistrationAdapter(self.runtime).close_exited()
        self.assertTrue(outcomes[0]["result"]["row_absent"])
        self.assertEqual(json.loads(self.registry.read_bytes()), self.original)
        self.assertTrue(RegistrationAdapter(self.runtime).close_exited()[0]["result"]["row_absent"])

    def test_port_reassignment_history_closes_only_actual_owned_version(self):
        self.publish()
        replacement = copy.deepcopy(self.row)
        replacement["observerPort"] = 21002
        self.retain_ownership(replacement)
        _, before, registry = self.adapter.read_registry(self.value)
        registry["sessions"][1] = replacement
        self.adapter.publish(self.value, before, registry, "trial-0", "register", lambda: None)
        self.exited()
        outcomes = RegistrationAdapter(self.runtime).close_exited()
        self.assertTrue(outcomes[0]["result"]["row_absent"])
        self.assertEqual(json.loads(self.registry.read_bytes()), self.original)
        self.assertEqual(len(self.adapter.owned_rows("trial-0")), 2)

    def test_available_port_reservations_are_exclusive_and_do_not_adopt_foreign_listener(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as foreign:
            foreign.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
            foreign.bind(("127.0.0.1", 0))
            foreign.listen()
            occupied = foreign.getsockname()[1]
            ports = [self.adapter.reserve_port(str(index), {occupied, 8765, 8766}) for index in range(4)]
            self.assertEqual(len(set(ports)), 4)
            self.assertNotIn(occupied, ports)
            for port in ports:
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as contender:
                    contender.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
                    with self.assertRaises(OSError):
                        contender.bind(("127.0.0.1", port))
            self.runtime.ready["foreign-port-fixture"] = {"observer_port": occupied}
            self.assertTrue(self.adapter.port_conflict("foreign-port-fixture"))
            self.assertEqual(foreign.getsockname()[1], occupied)
        self.assertEqual(json.loads(self.registry.read_bytes()), self.original)

    def test_authority_cannot_be_rebound_and_stop_prevents_refill_writes(self):
        self.assertEqual(self.adapter.authority(), self.value)
        before = self.registry.read_bytes()
        self.f.ledger.request_stop(event_id="registration-fixture-stop", reason="Owned fixture STOP")
        self.runtime.slots["trial-4"] = 0
        with self.assertRaises((ValueError, RuntimeError)):
            self.adapter.register("trial-4")
        self.assertEqual(self.registry.read_bytes(), before)
        changed = copy.deepcopy(self.value)
        changed["scope"]["assignment_ids"][-1] = "foreign-assignment"
        (self.adapter.root / "authority.json").write_bytes(encoded(changed))
        with self.assertRaises(SafetyError):
            self.adapter.authority()
