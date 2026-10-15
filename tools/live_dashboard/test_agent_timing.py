"""Recorded-event run clocks; no wall-clock sleeps, journal files or services."""

import unittest
from datetime import datetime, timedelta, timezone
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

import journals as j


ROOT_ID = "00000000-0000-4000-8000-000000000001"
AGENT_ID = "00000000-0000-4000-8000-000000000002"
BASE = datetime(2026, 10, 14, tzinfo=timezone.utc)


def stamp(seconds):
    return (BASE + timedelta(seconds=seconds)).isoformat()


def event(kind, seconds, **fields):
    return {"type": kind, "timestamp": stamp(seconds) if seconds is not None else None,
            **fields}


def message(role, seconds, **fields):
    return event("message", seconds, message={"role": role, **fields})


def tool_start(seconds, tool="bash", cid="call"):
    return event("custom", seconds, customType="tool_execution_start",
                 data={"toolName": tool, "toolCallId": cid})


def yield_records(seconds, args=None, details=None, is_error=False):
    """Actual journal shape: assistant call, execution start, accepted result."""
    return [
        message("assistant", seconds, stopReason="toolUse", content=[{
            "type": "toolCall", "id": "yield-call", "name": "yield",
            "arguments": args if args is not None else {"data": {"status": "success"}},
        }]),
        tool_start(seconds + 1, "yield", "yield-call"),
        message("toolResult", seconds + 2, toolName="yield", toolCallId="yield-call",
                isError=is_error, details=details if details is not None else {
                    "status": "success", "data": {"status": "success"},
                }, content=[{"type": "text", "text": "Result submitted."}]),
    ]


class AgentTimingTests(unittest.TestCase):
    def tracker(self, started=0):
        tracker = j.JournalTracker(Path("agent.jsonl"), "agent", False)
        tracker.apply(event("session", started, id=AGENT_ID, parentSession=ROOT_ID))
        return tracker

    def apply_all(self, tracker, records):
        for record in records:
            tracker.apply(record)

    def assert_clock(self, tracker, start, end=None, now=10000):
        agent = tracker.agent_dict(BASE + timedelta(seconds=now))
        self.assertEqual(agent["runStartedAt"], stamp(start) if start is not None else None)
        self.assertEqual(agent["runEndedAt"], stamp(end) if end is not None else None)
        return agent

    def watcher(self, tracker):
        watcher = j.JournalWatcher(".")
        watcher.parent_session_id = ROOT_ID
        watcher.trackers[tracker.path] = tracker
        return watcher

    def membership(self, watcher, seconds, active=False, revision=1, complete=True,
                   include_agent=True):
        watcher.update_membership({
            "rootSessionId": ROOT_ID, "epoch": "registry-epoch",
            "membership": {
                "source": "runner-registry", "complete": complete,
                "revision": revision, "updatedAt": stamp(seconds) if seconds is not None else None,
                "agents": [{"id": AGENT_ID, "active": active}] if include_agent else [],
            },
        })

    def test_initial_session_init_and_active_steering_preserve_start(self):
        tracker = self.tracker()
        tracker.apply(event("session_init", 1, agent="task", resolvedModel="gpt-6.1-sol"))
        tracker.apply(message("user", 2, content="Initial assignment"))
        tracker.apply(message("user", 20, content="Steering while active"))
        self.assert_clock(tracker, 0)
        # Existing target/membership steering semantics deliberately remain separate.
        self.assertEqual(tracker.assignment_started_at, BASE + timedelta(seconds=20))
        self.assertIsNone(tracker.last_target)

    def test_assignment_without_session_header_can_start_a_clock(self):
        tracker = j.JournalTracker("agent.jsonl", "agent", False)
        tracker.apply(message("user", 10, content="Assignment"))
        self.assert_clock(tracker, 10)

    def test_waiting_and_quiet_age_are_elapsed_time_not_end_evidence(self):
        tracker = self.tracker()
        tracker.apply(tool_start(10, "wait"))
        self.assertEqual(self.assert_clock(tracker, 0, now=100000)["state"], "waiting")
        tracker.apply(message("toolResult", 30, toolName="wait", toolCallId="call"))
        self.assertEqual(self.assert_clock(tracker, 0, now=31)["state"], "working")
        self.assertEqual(self.assert_clock(tracker, 0, now=100000)["state"], "quiet")
        tracker.apply(message("user", 100001, content="Continue the current task"))
        self.assert_clock(tracker, 0, now=100002)

    def test_model_changes_and_normal_tools_and_turns_do_not_restart(self):
        tracker = self.tracker()
        for reason in ("stop", "endTurn", "toolUse"):
            tracker.apply(message("assistant", 10, model="gpt-6.1-sol", stopReason=reason,
                                  content="Normal turn"))
            self.assert_clock(tracker, 0)
        tracker.apply(tool_start(20))
        tracker.apply(message("toolResult", 30, toolName="bash", toolCallId="call",
                              isError=True, content="Command failed"))
        tracker.apply(event("model_change", 40, model="another-recorded-model"))
        self.assert_clock(tracker, 0)

    def test_accepted_terminal_yield_freezes_before_later_exit(self):
        tracker = self.tracker()
        self.apply_all(tracker, yield_records(10))
        self.assert_clock(tracker, 0, 12)
        tracker.apply(message("assistant", 15, stopReason="stop", content="Trailing turn end"))
        tracker.apply(event("model_change", 18, model="gpt-6.1-sol"))
        tracker.apply(event("custom", 40, customType="session_exit",
                            data={"reason": "dispose", "kind": "normal", "recordedAt": stamp(40)}))
        self.assert_clock(tracker, 0, 12, now=100000)
        self.assertEqual(tracker.last_seen, stamp(40))

    def test_terminal_waiting_blocked_and_aborted_results_still_end_run(self):
        for state in ("waiting", "blocked", "success"):
            for status in ("success", "aborted"):
                with self.subTest(state=state, status=status):
                    tracker = self.tracker()
                    self.apply_all(tracker, yield_records(10, args={"data": {"status": state}},
                                                         details={"status": status,
                                                                  "data": {"status": state}}))
                    self.assert_clock(tracker, 0, 12)
                    self.assertTrue(tracker.assignment_retired)

    def test_incremental_and_rejected_yields_do_not_stop_clock(self):
        for args, details, error in (
            ({"type": ["section"], "data": {"status": "waiting"}},
             {"status": "success", "data": {"status": "waiting"}}, False),
            ({"data": {"status": "success"}}, {"status": "error"}, True),
        ):
            with self.subTest(args=args):
                tracker = self.tracker()
                self.apply_all(tracker, yield_records(10, args, details, error))
                tracker.apply(message("user", 30, content="Steer this live assignment"))
                self.assert_clock(tracker, 0)
                self.assertFalse(tracker.assignment_retired)

    def test_incremental_target_still_clears_on_steering_without_clock_reset(self):
        tracker = self.tracker()
        self.apply_all(tracker, yield_records(
            10, args={"type": ["section"], "data": {"target": "unit.cpp"}},
            details={"status": "success", "data": {"target": "unit.cpp"}}))
        self.assertEqual(tracker.agent_dict(BASE)["target"], "unit.cpp")
        tracker.apply(message("user", 30, content="Steer the current assignment"))
        self.assertIsNone(tracker.agent_dict(BASE)["target"])
        self.assert_clock(tracker, 0)

    def test_result_complete_flag_is_terminal_evidence_without_call(self):
        tracker = self.tracker()
        tracker.apply(message("toolResult", 12, toolName="yield", toolCallId="unseen-call",
                              details={"status": "success", "complete": True}))
        self.assert_clock(tracker, 0, 12)

    def test_aborted_and_error_turn_freeze_then_user_resumes(self):
        for reason in ("aborted", "error"):
            with self.subTest(reason=reason):
                tracker = self.tracker()
                tracker.apply(message("assistant", 10, stopReason=reason,
                                      errorMessage="Recorded failure", content=[]))
                self.assertEqual(self.assert_clock(tracker, 0, 10)["state"], "stopped")
                tracker.apply(message("user", 30, content="Resume assignment"))
                tracker.apply(message("user", 40, content="Steering, not another run"))
                self.assert_clock(tracker, 30)

    def test_exit_freezes_and_session_init_resumes_without_user_record(self):
        tracker = self.tracker()
        tracker.apply(event("custom", 10, customType="session_exit",
                            data={"reason": "sigint", "kind": "signal"}))
        self.assert_clock(tracker, 0, 10)
        tracker.apply(event("session_init", 30, agent="task", resolvedModel="gpt-6.1-sol"))
        tracker.apply(message("user", 40, content="New assignment payload"))
        self.assert_clock(tracker, 30)

    def test_tool_execution_can_prove_resumption_after_terminal_yield(self):
        tracker = self.tracker()
        self.apply_all(tracker, yield_records(10))
        tracker.apply(tool_start(30))
        tracker.apply(tool_start(40, "wait", "next-call"))
        self.assert_clock(tracker, 30)
        self.assertFalse(tracker.assignment_retired)
        self.assertEqual(tracker.assignment_started_at, BASE + timedelta(seconds=30))

    def test_missing_or_invalid_start_is_not_replaced_by_steering(self):
        for timestamp in (None, "not-a-timestamp"):
            with self.subTest(timestamp=timestamp):
                tracker = j.JournalTracker("agent.jsonl", "agent", False)
                tracker.apply({"type": "session", "timestamp": timestamp, "id": AGENT_ID})
                tracker.apply(message("user", 10, content="Steering"))
                tracker.apply(tool_start(20))
                self.assert_clock(tracker, None)
                self.apply_all(tracker, yield_records(30))
                self.assert_clock(tracker, None, 32)

    def test_partial_history_tool_activity_does_not_invent_initial_start(self):
        tracker = j.JournalTracker("agent.jsonl", "agent", False)
        tracker.apply(tool_start(10))
        tracker.apply(message("assistant", 20, stopReason="stop", content="A normal turn"))
        self.assert_clock(tracker, None)

    def test_missing_end_stays_unknown_not_last_seen_or_snapshot_time(self):
        tracker = self.tracker()
        tracker.apply(message("assistant", None, stopReason="aborted", content=[]))
        self.assert_clock(tracker, 0)
        self.assertTrue(tracker._run_ended)
        tracker.apply(event("model_change", 20, model="gpt-6.1-sol"))
        self.assert_clock(tracker, 0)
        tracker.apply(message("user", 30, content="Resume after unknown-time abort"))
        self.assert_clock(tracker, 30)

    def test_exit_can_use_explicit_recorded_at_but_not_last_seen(self):
        tracker = self.tracker()
        tracker.apply(tool_start(5))
        tracker.apply(event("custom", None, customType="session_exit",
                            data={"reason": "dispose", "kind": "normal", "recordedAt": stamp(10)}))
        self.assert_clock(tracker, 0, 10)

    def test_membership_inactive_never_uses_global_updated_at_as_end(self):
        for include_agent in (True, False):
            with self.subTest(include_agent=include_agent):
                tracker = self.tracker()
                tracker.apply(tool_start(5))
                watcher = self.watcher(tracker)
                self.membership(watcher, 20, include_agent=include_agent)
                self.assertTrue(tracker._run_ended)
                self.assert_clock(tracker, 0)
                self.assertFalse(watcher.snapshot()[0][0]["active"])
                self.membership(watcher, 50, revision=2, include_agent=include_agent)
                self.assert_clock(tracker, 0)
                # A browser refresh/replay against the same cold registry also
                # has no agent-specific finish time to invent.
                fresh = self.tracker()
                fresh.apply(tool_start(5))
                refreshed = self.watcher(fresh)
                self.membership(refreshed, 50, include_agent=include_agent)
                self.assert_clock(fresh, 0)

    def test_membership_missing_time_does_not_fabricate_end(self):
        tracker = self.tracker()
        watcher = self.watcher(tracker)
        self.membership(watcher, None)
        self.assert_clock(tracker, 0)
        self.assertTrue(tracker._run_ended)

    def test_membership_observations_do_not_extend_known_terminal_time(self):
        tracker = self.tracker()
        self.apply_all(tracker, yield_records(10))
        watcher = self.watcher(tracker)
        for revision, at in enumerate((20, 50, 100), 1):
            self.membership(watcher, at, revision=revision)
            self.assert_clock(tracker, 0, 12)
        tracker.apply(message("user", 110, content="Resumed"))
        # Cached inactive registry is older than the recorded assignment.
        watcher._record_run_retirements()
        self.assert_clock(tracker, 110)
        self.assertNotIn("active", watcher.snapshot()[0][0])
        self.membership(watcher, 120, active=True, revision=4)
        tracker.apply(message("user", 130, content="Active steering"))
        self.assert_clock(tracker, 110)
        self.assertTrue(watcher.snapshot()[0][0]["active"])

    def test_unknown_time_membership_retirement_then_assignment_resumes(self):
        tracker = self.tracker()
        watcher = self.watcher(tracker)
        self.membership(watcher, 20)
        self.assert_clock(tracker, 0)
        tracker.apply(message("user", 30, content="Resume the retired assignment"))
        watcher._record_run_retirements()
        self.assert_clock(tracker, 30)
        self.assertFalse(tracker._run_ended)
        self.membership(watcher, 40, active=True, revision=2)
        tracker.apply(message("user", 50, content="Steering while active"))
        self.assert_clock(tracker, 30)

    def test_incomplete_or_unknown_membership_does_not_retire_absent_agent(self):
        for active, include_agent in ((None, True), (False, False)):
            with self.subTest(active=active, include_agent=include_agent):
                tracker = self.tracker()
                watcher = self.watcher(tracker)
                self.membership(watcher, 20, active=active, complete=False,
                                include_agent=include_agent)
                tracker.apply(message("user", 30, content="Still active"))
                self.assert_clock(tracker, 0)
                self.assertFalse(tracker._run_ended)

    def test_tombstone_poll_records_persisted_time_and_snapshots_are_read_only(self):
        tracker = self.tracker()
        tracker.apply(tool_start(5))
        watcher = self.watcher(tracker)
        with patch.object(watcher, "_discover", return_value=[tracker.path]), \
                patch.object(watcher, "_sync"), \
                patch.object(j.Path, "stat", return_value=SimpleNamespace(
                    st_mtime=(BASE + timedelta(seconds=20)).timestamp())):
            watcher.poll()
            watcher.poll()
        self.assert_clock(tracker, 0, 20)
        before = (tracker.run_started_at, tracker.run_ended_at,
                  tracker._run_started, tracker._run_ended)
        for _ in range(3):
            agent = watcher.snapshot()[0][0]
            self.assertEqual(agent["runEndedAt"], stamp(20))
            self.assertFalse(agent["active"])
        self.assertEqual(before, (tracker.run_started_at, tracker.run_ended_at,
                                  tracker._run_started, tracker._run_ended))

    def test_earlier_terminal_evidence_wins_over_tombstone(self):
        tracker = self.tracker()
        self.apply_all(tracker, yield_records(10))
        tracker.tombstoned = True
        tracker.tombstoned_at = BASE + timedelta(seconds=20)
        watcher = self.watcher(tracker)
        watcher._record_run_retirements()
        self.assert_clock(tracker, 0, 12)
        tracker.apply(message("user", 30, content="New run"))
        watcher._record_run_retirements()
        self.assert_clock(tracker, 30)

    def test_replay_and_incremental_ingestion_have_identical_current_run(self):
        records = [
            event("session", 0, id=AGENT_ID, parentSession=ROOT_ID),
            event("session_init", 1, agent="task", resolvedModel="gpt-6.1-sol"),
            message("user", 2, content="Initial assignment"),
            tool_start(5, "wait"),
            message("user", 8, content="Steering while waiting"),
            *yield_records(10),
            event("custom", 20, customType="session_exit",
                  data={"reason": "dispose", "kind": "normal"}),
            event("session_init", 30, agent="task", resolvedModel="gpt-6.1-sol"),
            message("user", 40, content="New assignment"),
            tool_start(50),
            message("assistant", 60, stopReason="error", content=[]),
        ]
        incremental = j.JournalTracker("agent.jsonl", "agent", False)
        for record in records:
            incremental.apply(record)
            incremental.agent_dict(BASE + timedelta(days=1))
        replayed = j.JournalTracker("agent.jsonl", "agent", False)
        self.apply_all(replayed, records)
        self.assertEqual(incremental.agent_dict(BASE + timedelta(days=1)),
                         replayed.agent_dict(BASE + timedelta(days=1)))
        self.assert_clock(replayed, 30, 60)


if __name__ == "__main__":
    unittest.main()
