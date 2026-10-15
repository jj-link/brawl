"""Deterministic reporting boundaries; synthetic records are not trial execution."""

from copy import deepcopy
from datetime import datetime, timedelta, timezone
import unittest

from . import test_state
from .state import StateError
from .trial_metrics import trial_report


class TrialMetricsTests(unittest.TestCase):
    def setUp(self):
        self.fixture = test_state.TrialLedgerTests("test_default_policy_is_unchanged_and_real_trial_is_explicit")
        self.fixture.setUp()

    def report(self, seconds=3600):
        snapshot = self.fixture.ledger.snapshot()
        cutoff = datetime.fromisoformat(snapshot["updated_at"]) + timedelta(seconds=seconds)
        return trial_report(snapshot, as_of=cutoff.isoformat())

    def test_fixture_success_never_earns_reconstruction_credit(self):
        report = trial_report({"assignments": {"fixture": {"status": "closed", "accepted_credit": 9000}}})
        self.assertEqual(report["accepted_matching_functions"], 0)
        self.assertEqual(report["accepted_original_bytes"], 0)
        self.assertIsNone(report["functions_per_hour"])

    def test_private_match_and_push_are_not_acceptance(self):
        self.fixture.pushed()
        report = self.report()
        self.assertEqual(report["accepted_matching_functions"], 0)
        self.assertIn("trial-0", report["unfinished_assignment_ids"])
        self.assertTrue(report["assignments"]["trial-0"]["unobserved_intervals"])
        self.assertEqual(report["production_progress_credit"], 0)

    def test_only_bound_coordinator_ack_counts_matching_original_bytes(self):
        self.fixture.pushed()
        self.fixture.observe("ack")
        report = self.report()
        self.assertEqual(report["accepted_matching_functions"], 1)
        self.assertEqual(report["accepted_original_bytes"], 8)
        self.assertAlmostEqual(report["bytes_per_hour"], 8 * 3600 / report["elapsed_seconds"])
        self.assertEqual(report["production_progress_credit"], 0)
        self.assertIn("trial-0", report["unfinished_assignment_ids"])
        self.fixture.ledger.check_input_identity("trial-0", input_identity="f" * 64,
                                                 evidence_ref="synthetic-invalidation", event_id=self.fixture.event())
        self.assertEqual(self.report()["accepted_matching_functions"], 0)

    def test_closed_input_observation_preserves_historical_accepted_credit(self):
        from .trial import record_after_stop
        self.fixture.pushed()
        self.fixture.observe("ack")
        self.fixture.observe("cleanup")
        self.fixture.exit()
        self.fixture.observe("closed")
        before_assignment = self.fixture.ledger.assignment("trial-0")
        envelope, stopped = self.fixture.consumed_observation_gap(
            "inputs", {"input_identity": "f" * 64, "evidence_ref": "synthetic-later-workspace-inputs"},
            role="coordinator")
        cutoff = (datetime.fromisoformat(self.fixture.ledger.snapshot()["updated_at"]) + timedelta(hours=1)).isoformat()
        before = trial_report(self.fixture.ledger.snapshot(), as_of=cutoff)
        self.assertEqual(before["accepted_matching_functions"], 1)
        first = record_after_stop(self.fixture.root, envelope)
        self.assertEqual(record_after_stop(self.fixture.root, envelope), first)
        after = trial_report(self.fixture.ledger.snapshot(), as_of=cutoff)
        self.assertEqual(after["accepted_matching_functions"], 1)
        for field in ("accepted_original_bytes", "functions_per_hour", "bytes_per_hour"):
            self.assertEqual(after[field], before[field], field)
        assignment = self.fixture.ledger.assignment("trial-0")
        for field in ("verification", "review", "materialization", "publication_acknowledgment",
                      "current_input_identity", "input_epoch", "status"):
            self.assertEqual(assignment[field], before_assignment[field], field)
        self.assertEqual(len(assignment["post_closure_input_observations"]), 1)
        self.assertEqual(assignment["post_closure_input_observations"][0]["input_identity"], "f" * 64)
        self.assertEqual(self.fixture.ledger.authorization(), stopped)
        self.assertEqual(after["production_progress_credit"], 0)

    def test_recorded_history_reporting_preserves_lifetime_unknown_and_held_nulls(self):
        for reservation in self.fixture.manifest["reservations"]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.fixture.initial(activate=False)
        history = test_state.recorded_trial_history(self.fixture.root)
        self.fixture.ledger.resolve_trial_history("trial-0", history=history,
            record=self.fixture.history_resolution_record(0), event_id=self.fixture.event())
        report = self.report()
        recorded, pending = report["assignments"]["trial-0"], report["assignments"]["trial-1"]
        self.assertEqual(recorded["inherited_history"], history)
        self.assertEqual(recorded["attempt_count_scope"], "attributable_recorded_within_inventory")
        self.assertEqual(recorded["lifetime_history_totals"], "unknown")
        self.assertEqual(recorded["measured_counts"]["qwen"], {"initial": 0, "corrections": 0})
        self.assertEqual(pending["attempt_count_scope"], "unresolved")
        self.assertEqual(pending["lifetime_history_totals"], "unknown")
        self.assertEqual(pending["measured_counts"]["qwen"], {"initial": None, "corrections": None})
        self.assertEqual(report["accepted_original_bytes"], 0)

    def test_phase_clocks_must_match_and_open_native_intervals_stay_unknown(self):
        self.fixture.initial()
        base = datetime.now(timezone.utc) - timedelta(seconds=30)
        for offset, phase, clock in ((0, "reconstruction", "native-clock"),
                                      (7, "verification", "native-clock"),
                                      (11, "parent_review_wait", "different-clock")):
            record = self.fixture.observation(owner_id="owner-0", phase=phase)
            record["observed_at"] = (base + timedelta(seconds=offset)).isoformat()
            record["timestamp_provenance"]["clock_id"] = clock
            self.fixture.ledger.trial_event("trial-0", kind="phase", record=record, event_id=self.fixture.event())
        report = self.report()
        assignment = report["assignments"]["trial-0"]
        self.assertEqual(assignment["observed_phase_seconds"]["reconstruction"], 7)
        self.assertEqual(assignment["observed_phase_seconds"]["verification"], 0)
        self.assertEqual(len(assignment["unobserved_intervals"]), 2)

    def test_capacity_distinguishes_eligible_pause_and_no_work(self):
        self.fixture.prepare()
        snapshot = self.fixture.ledger.snapshot()
        base = datetime(2026, 1, 1, tzinfo=timezone.utc)
        at = lambda seconds: (base + timedelta(seconds=seconds)).isoformat()
        snapshot["trial"]["created_at"] = at(0)
        snapshot["updated_at"] = at(20)
        snapshot["trial"]["capacity_history"] = [
            {"at": at(0), "free_slots": 4, "eligible_idle_slots": 4, "reason": "eligible",
             "queued_reasons": {"one": "eligible"}},
            {"at": at(10), "free_slots": 4, "eligible_idle_slots": 0, "reason": "explicit_pause",
             "queued_reasons": {"one": "tool_wait"}},
            {"at": at(20), "free_slots": 4, "eligible_idle_slots": 0, "reason": "no_eligible_work",
             "queued_reasons": {"one": "parent_wait"}}]
        report = trial_report(snapshot, as_of=at(30))
        self.assertEqual(report["eligible_idle_slot_seconds"], 40)
        self.assertEqual(report["idle_slot_seconds_by_reason"],
                         {"eligible": 40, "explicit_pause": 40, "no_eligible_work": 40})
        self.assertEqual(report["queued_assignment_seconds_by_reason"]["tool_wait"], 10)
        self.assertEqual(report["queued_assignment_seconds_by_reason"]["parent_wait"], 10)

    def test_interventions_violations_and_recovery_are_observed_not_assumed(self):
        self.fixture.initial()
        self.assertEqual(self.report()["observed_interventions"], [])
        for kind in ("intervention", "violation", "recovery"):
            event = self.fixture.event()
            record = self.fixture.observation(description=f"Synthetic {kind}")
            self.fixture.ledger.trial_event(None, kind=kind, record=record, event_id=event)
            self.fixture.ledger.trial_event(None, kind=kind, record=record, event_id=event)
        report = self.report()
        self.assertEqual(len(report["observed_interventions"]), 1)
        self.assertEqual(len(report["observed_violations"]), 1)
        self.assertEqual(len(report["observed_recoveries"]), 1)

    def test_actual_close_and_independent_refill_latencies_do_not_wait_for_peers(self):
        self.fixture.pushed()
        self.fixture.observe("ack")
        self.fixture.observe("cleanup")
        self.fixture.exit()
        self.fixture.observe("closed")
        self.fixture.ledger.claim_trial_refill(claim=self.fixture.claim(4, 0), event_id=self.fixture.event(),
                                               authorization_revision=self.fixture.auth["revision"])
        report = self.report()
        self.assertEqual(len(report["independent_refills"]), 1)
        self.assertGreaterEqual(report["independent_refills"][0]["seconds"], 0)
        self.assertIsNotNone(report["assignments"]["trial-0"]["cleanup_to_native_close_seconds"])
        self.assertEqual(report["closed_assignment_ids"], ["trial-0"])
        self.assertIn("trial-1", report["unfinished_assignment_ids"])

    def test_report_does_not_mutate_or_backdate_snapshot(self):
        self.fixture.initial()
        snapshot = self.fixture.ledger.snapshot()
        before = repr(snapshot)
        trial_report(snapshot)
        self.assertEqual(repr(snapshot), before)
        with self.assertRaises(StateError):
            trial_report(snapshot, as_of="2000-01-01T00:00:00Z")


    def completed_snapshot(self):
        """Synthetic eight-close reporting fixture, not eight reconstruction runs."""
        self.fixture.pushed()
        self.fixture.observe("ack")
        self.fixture.observe("cleanup")
        self.fixture.exit()
        self.fixture.observe("closed")
        snapshot = self.fixture.ledger.snapshot()
        source_assignment = deepcopy(snapshot["assignments"]["trial-0"])
        source_claim = deepcopy(snapshot["trial"]["claims"]["trial-0"])
        source_process = deepcopy(snapshot["processes"]["process-0"])
        base = datetime(2026, 1, 1, tzinfo=timezone.utc)
        at = lambda seconds: (base + timedelta(seconds=seconds)).isoformat()
        snapshot["trial"]["created_at"] = at(0)
        snapshot["updated_at"] = at(20)
        snapshot["trial"]["events"] = []
        snapshot["assignments"] = {}
        snapshot["trial"]["claims"] = {}
        snapshot["processes"] = {}
        for index in range(8):
            key, session, process_id = f"trial-{index}", f"child-{index}", f"process-{index}"
            claimed, closed = (1, 10) if index < 4 else (11, 20)
            assignment = deepcopy(source_assignment)
            assignment.update(assignment_id=key, owner_id=f"owner-{index}", session_id=session, created_at=at(claimed), updated_at=at(closed))
            assignment["identity"]["reservation"] = deepcopy(snapshot["trial"]["manifest"]["reservations"][index])
            assignment["function"] = assignment["identity"]["reservation"]["function"]
            for kind, entries in assignment["external_receipts"].items():
                for entry in entries:
                    entry["recorded_at"] = at(closed)
                    entry["receipt"].update(assignment_id=key, owner_id=f"owner-{index}", session_id=session,
                                             started_at=at(closed - 1), observed_at=at(closed))
                    if kind == "closed":
                        entry["receipt"]["process_id"] = process_id
            assignment["history"] = []
            snapshot["assignments"][key] = assignment
            snapshot["trial"]["claims"][key] = dict(source_claim, assignment_id=key, owner_id=f"owner-{index}",
                                                    root_session_id=f"root-{index}", session_id=session,
                                                    process_id=process_id, slot=index % 4,
                                                    claimed_at=at(claimed), closed_at=at(closed))
            process = deepcopy(source_process)
            process.update(process_id=process_id, session_id=session, active=False)
            process["exit_proof"]["verified_at"] = at(closed - 1)
            snapshot["processes"][process_id] = process
        snapshot["trial"]["capacity_history"] = [
            {"at": at(0), "free_slots": 4, "eligible_idle_slots": 0,
             "reason": "explicit_pause", "queued_reasons": {}},
            {"at": at(1), "free_slots": 0, "eligible_idle_slots": 0,
             "reason": "eligible", "queued_reasons": {}},
            {"at": at(20), "free_slots": 4, "eligible_idle_slots": 0,
             "reason": "no_eligible_work", "queued_reasons": {}},
        ]
        return snapshot

    def test_completed_trial_rates_and_idle_time_do_not_drift_on_later_reads(self):
        snapshot = self.completed_snapshot()
        early = trial_report(snapshot, as_of="2026-01-01T01:00:00+00:00")
        late = trial_report(snapshot, as_of="2026-01-02T01:00:00+00:00")
        self.assertEqual(early["elapsed_seconds"], 20)
        for field in ("elapsed_seconds", "functions_per_hour", "bytes_per_hour",
                      "eligible_idle_slot_seconds", "idle_slot_seconds_by_reason"):
            self.assertEqual(early[field], late[field], field)
        self.assertEqual(early["accepted_matching_functions"], 8)
        self.assertEqual(early["accepted_original_bytes"], 64)

    def test_unfinished_trial_keeps_live_as_of_denominator(self):
        self.fixture.initial()
        early, late = self.report(seconds=60), self.report(seconds=120)
        self.assertGreater(late["elapsed_seconds"], early["elapsed_seconds"])

    def test_closed_labels_without_native_exit_are_not_observed_terminal_proof(self):
        snapshot = self.completed_snapshot()
        snapshot["processes"]["process-7"]["exit_proof"] = None
        snapshot["processes"]["process-7"]["active"] = True
        early = trial_report(snapshot, as_of="2026-01-01T01:00:00+00:00")
        late = trial_report(snapshot, as_of="2026-01-02T01:00:00+00:00")
        self.assertGreater(late["elapsed_seconds"], early["elapsed_seconds"])


class WorkflowMetricsTests(unittest.TestCase):
    def setUp(self):
        self.fixture = test_state.WorkflowFixture()
        self.fixture.start()

    def report(self, seconds=3600):
        snapshot = self.fixture.ledger.snapshot()
        cutoff = datetime.fromisoformat(snapshot["updated_at"]) + timedelta(seconds=seconds)
        return trial_report(snapshot, as_of=cutoff.isoformat())

    def test_native_turn_wall_time_does_not_invent_model_compute_or_parent_wait(self):
        self.fixture.reviewed()
        report = self.report()
        workflow = report["automatic_workflow"]
        self.assertTrue(workflow["native_owner_turn_intervals"])
        self.assertIsNone(workflow["explicit_interval_seconds_by_phase"]["model_execution"])
        self.assertIsNone(workflow["explicit_interval_seconds_by_phase"]["tool_queue"])
        self.assertIn("instrumentation", workflow["unobserved_execution_categories"])
        self.assertIsNone(report["assignments"]["trial-0"]["ledger_ingestion_wait_seconds"]["parent_review_wait"])
        self.assertEqual(report["accepted_matching_functions"], 0)
        self.assertEqual(report["production_progress_credit"], 0)
        self.assertEqual(workflow["profile"], self.fixture.config["profile"])
        self.assertEqual(workflow["publication_target"], self.fixture.config["publication_target"])

    def test_explicit_native_intervals_are_distinct_from_lifecycle_occupancy(self):
        self.fixture.capture()
        start = datetime.fromisoformat(self.fixture.ledger.snapshot()["trial"]["created_at"])
        record = self.fixture.case.observation(
            owner_id="owner-0", phase="model_execution", started_at=start.isoformat(),
            observed_at=(start + timedelta(seconds=2)).isoformat(),
            timestamp_provenance={"source": "synthetic native event pair", "clock_id": "synthetic-native-clock"})
        reference = str(self.fixture.root / "synthetic-native-interval.json")
        record.update(native_actor_id="owner-0", native_session_id="child-0",
                      native_event=dict(kind="native_interval", owner="owner-0", session_id="child-0",
                                        **{key: record[key] for key in ("phase", "started_at", "observed_at")}),
                      native_evidence={"path": reference, "sha256": "a" * 64}, evidence_refs=[reference])
        self.fixture.ledger.observe_trial_interval("trial-0", record=record, event_id="native-model-span")
        self.fixture.ledger.observe_trial_interval("trial-0", record=record, event_id="native-model-span-duplicate")
        workflow = self.report()["automatic_workflow"]
        self.assertEqual(workflow["explicit_interval_seconds_by_phase"]["model_execution"], 2)
        self.assertEqual(len(workflow["explicit_execution_intervals"]), 1)
        self.assertIsNone(workflow["explicit_interval_seconds_by_phase"]["tool_execution"])
        self.assertNotIn("model_execution", workflow["observed_action_seconds_by_kind"])

    def test_legacy_reported_intervals_do_not_become_native_observations(self):
        snapshot = self.fixture.ledger.snapshot()
        stamp = snapshot["updated_at"]
        snapshot["trial"]["events"].append(dict(assignment_id="trial-0", event_id="untrusted-old-interval",
            kind="interval", recorded_at=stamp, record=self.fixture.case.observation(
                owner_id="owner-0", phase="model_execution", started_at=stamp, observed_at=stamp)))
        report = trial_report(snapshot, as_of=stamp)["automatic_workflow"]
        self.assertIsNone(report["explicit_interval_seconds_by_phase"]["model_execution"])
        self.assertEqual(report["explicit_execution_intervals"], [])
        self.assertEqual(len(report["untrusted_reported_intervals"]), 1)

    def test_acknowledged_work_retains_historical_credit_without_claiming_closure(self):
        self.fixture.reviewed()
        self.fixture.materialize()
        self.fixture.publish()
        before = self.fixture.ledger.assignment("trial-0")
        self.fixture.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="synthetic-later-environment", event_id="after-actual-ack")
        after = self.fixture.ledger.assignment("trial-0")
        self.assertEqual(after["verification"], before["verification"])
        self.assertEqual(after["current_input_identity"], before["current_input_identity"])
        report = self.report()
        self.assertEqual(report["accepted_matching_functions"], 1)
        self.assertEqual(report["accepted_original_bytes"], 8)
        self.assertIn("trial-0", report["unfinished_assignment_ids"])
        self.assertNotIn("trial-0", report["closed_assignment_ids"])
        self.assertEqual(len(report["assignments"]["trial-0"]["post_ack_input_observations"]), 1)
        self.assertEqual(report["production_progress_credit"], 0)
        self.assertTrue(self.fixture.ledger.session("child-0")["active"])

    def test_remote_recovery_reports_query_time_not_an_invented_push_execution(self):
        self.fixture.reviewed()
        self.fixture.materialize()
        commit = self.fixture.admit()
        self.fixture.complete(commit, self.fixture.commit_result(commit))
        push = self.fixture.admit()
        self.fixture.complete(push, {"error": "Synthetic missing transport result"}, outcome="uncertain")
        result = self.fixture.push_result(push) | {"push_exit_code": None, "recovered_from_remote": True}
        self.fixture.complete(push, result)
        self.fixture.complete(self.fixture.admit(), {})
        report = self.report()
        action = next(row for row in report["automatic_workflow"]["actions"] if row["effect_id"] == push["effect_id"])
        self.assertIsNone(action["observed_action_seconds"])
        self.assertIsNotNone(action["recovery_query_seconds"])
        self.assertNotIn("push", report["automatic_workflow"]["observed_action_seconds_by_kind"])
        self.assertEqual(report["assignments"]["trial-0"]["receipt_elapsed_seconds"]["push"][0]["timing_scope"],
                         "remote_recovery_query")
        self.assertEqual(report["accepted_matching_functions"], 1)

    def test_completed_automatic_run_freezes_rates_readiness_and_model_lease_windows(self):
        fixture = self.fixture
        for index in range(8):
            fixture.reviewed(index)
            fixture.materialize(index)
            fixture.publish(index)
            fixture.cleanup(index)
            fixture.close(index)
            if index < 4:
                following = index + 4
                fixture.ledger.claim_trial_refill(claim=fixture.case.claim(following, slot=index),
                    event_id=fixture.case.event(), authorization_revision=1)
                fixture.case.attach(following)
                fixture.ledger.admit_trial_effect(f"trial-{following}", kind="prompt", effect_id=f"prompt-{following}",
                    event_id=fixture.case.event(), authorization_revision=1)
        before = fixture.ledger.snapshot()
        early, late = self.report(60), self.report(7200)
        self.assertEqual(early["accepted_matching_functions"], 8)
        self.assertEqual(early["accepted_original_bytes"], 64)
        self.assertEqual(early["unfinished_assignment_ids"], [])
        self.assertEqual(len(early["independent_refills"]), 4)
        self.assertTrue(early["terminal_cutoff_observed"])
        for name in ("elapsed_seconds", "functions_per_hour", "bytes_per_hour", "eligible_idle_slot_seconds"):
            self.assertEqual(early[name], late[name], name)
        for name in ("assignment_readiness_seconds_by_reason", "model_lease_slot_seconds",
                     "controller_eligible_action_wait_seconds"):
            self.assertEqual(early["automatic_workflow"][name], late["automatic_workflow"][name], name)
        self.assertEqual(before, fixture.ledger.snapshot())
        self.assertEqual(early["production_progress_credit"], 0)


if __name__ == "__main__":
    unittest.main()
