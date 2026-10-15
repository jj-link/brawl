"""Checkpoint behavior regressions; run with unittest discovery here."""

import json
import os
import shutil
import stat
import subprocess
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import Mock, patch
from uuid import uuid4

import checkpoint_history as history
import progress


NEW_COMMIT = "cdda4dc309050d8f4a7cc9df636a170d1b2a5512"
OLD_COMMIT = "283271c9885e89ce3822183b0312657ac3983754"
ORDINARY_DCD4 = """## Dedede DCD4 — exact GLM source reconstruction

- Accepted fn_117_DCD4: 8 code bytes from its exact initial candidate.
- The owner verified all 127 native hashes and source-object linkage.
- Gameplay verification was unavailable; cumulative accepted-source accounting
  belongs to the retained publisher.

"""


def checkpoint(title="Committed-source checkpoint cdda4dc3", accepted=471424,
               units=1379, commit=NEW_COMMIT, declaration="Cumulative accepted-source progress is"):
    total = 15833556
    return (f"## {title}\n\n"
            f"- {declaration} **{100 * accepted / total:.6f}%**: "
            f"**{accepted:,} / {total:,} accepted code bytes**, "
            f"**{total - accepted:,} code bytes remaining**, and "
            f"**{units:,} accepted source units**.\n"
            f"- Verification passed all 127 native hashes for committed snapshot `{commit}`.\n\n")


def previous_checkpoint():
    return checkpoint("Committed-source checkpoint 283271c9", 471416, 1378, OLD_COMMIT)


def memory_tracker(text):
    # No counter, report or history files are read or written by these tests.
    with patch.object(progress, "_load_counter"), patch.object(progress.ProgressTracker, "_load_history", return_value=[]):
        tracker = progress.ProgressTracker("unused-report.json", Path("."), "unused-history.json")
    tracker.changelog_path = Mock()
    tracker.changelog_path.read_text.return_value = text
    tracker.changelog_path.stat.return_value = SimpleNamespace(st_mtime=1)
    tracker._changelog_fingerprint = Mock(return_value="first-input")
    tracker._persist_history = Mock()
    return tracker


def published_blame(text, timestamp=1791849600):
    return SimpleNamespace(stdout="".join(
        f"{'a' * 40} {number} {number} 1\ncommitter-time {timestamp}\n\t{line}\n"
        for number, line in enumerate(text.splitlines(), 1)))


class HeadlineCheckpointTests(unittest.TestCase):
    def test_reported_ordinary_entry_does_not_hide_prior_checkpoint(self):
        result = progress.ProgressTracker._parse_checkpoint(ORDINARY_DCD4 + checkpoint() + previous_checkpoint())
        self.assertEqual(result["commit"], NEW_COMMIT)
        self.assertEqual(result["checkpointTitle"], "Committed-source checkpoint cdda4dc3")
        self.assertEqual((result["acceptedBytes"], result["totalBytes"], result["remainingBytes"],
                          result["percent"], result["acceptedUnits"]),
                         (471424, 15833556, 15362132, 2.977373, 1379))

    def test_ordinary_entries_with_complete_private_counts_are_not_checkpoints(self):
        ordinary = checkpoint("Unit reconstruction verification", 471432, 1380)
        ordinary = ordinary.replace("Cumulative accepted-source progress is", "Source reconstruction is now")
        result = progress.ProgressTracker._parse_checkpoint(ordinary + ORDINARY_DCD4 + checkpoint())
        self.assertEqual(result["acceptedBytes"], 471424)
        self.assertEqual(result["checkpointTitle"], "Committed-source checkpoint cdda4dc3")

    def test_accepted_entry_referencing_publisher_is_not_a_legacy_record(self):
        ordinary = ORDINARY_DCD4.replace("Dedede DCD4 — exact GLM source reconstruction", "Accepted reconstruction — DCD4")
        self.assertEqual(progress.ProgressTracker._parse_checkpoint(ordinary + checkpoint())["commit"], NEW_COMMIT)

    def test_checkpoint_with_measurements_needs_no_incidental_cumulative_phrase(self):
        text = checkpoint(declaration="Published committed-source measurements are")
        self.assertEqual(progress.ProgressTracker._parse_checkpoint(text)["acceptedBytes"], 471424)

    def test_missing_newest_measurements_raise_instead_of_falling_back(self):
        variants = [
            checkpoint().replace("471,424 / 15,833,556 accepted code bytes", "accepted byte counts pending"),
            checkpoint().replace("15,362,132 code bytes remaining", "remaining measurement pending"),
            checkpoint().replace("1,379 accepted source units", "accepted unit count pending"),
            checkpoint().replace("2.977373%", "percentage pending"),
            "## Committed-source checkpoint unfinished\n\n- Verification passed; measurements pending.\n\n",
            "## Verified reconstruction checkpoint unfinished\n\n",
            checkpoint("Accepted source reconstruction — legacy", declaration="Source reconstruction is now")
                .replace("2.977373%", "percentage pending"),
        ]
        for newest in variants:
            with self.subTest(newest=newest), self.assertRaisesRegex(ValueError, "lacks complete counts"):
                progress.ProgressTracker._parse_checkpoint(newest + previous_checkpoint())

    def test_inconsistent_newest_measurements_raise_instead_of_falling_back(self):
        variants = [
            checkpoint().replace("15,362,132 code bytes remaining", "15,362,140 code bytes remaining"),
            checkpoint().replace("2.977373%", "2.977322%"),
            checkpoint().replace("15,833,556 accepted code bytes", "0 accepted code bytes"),
            checkpoint("Accepted isolated reconstruction — legacy", declaration="Cumulative accepted-source accounting is")
                .replace("2.977373%", "2.977322%"),
        ]
        for newest in variants:
            with self.subTest(newest=newest), self.assertRaisesRegex(ValueError, "inconsistent accounting"):
                progress.ProgressTracker._parse_checkpoint(newest + previous_checkpoint())

    def test_unverified_dedicated_record_does_not_fall_back(self):
        newest = checkpoint().replace("Verification passed all 127 native hashes", "Native checking pending")
        with self.assertRaisesRegex(ValueError, "lacks verification"):
            progress.ProgressTracker._parse_checkpoint(newest + previous_checkpoint())

    def test_supported_legacy_headlines(self):
        for title, declaration in (
            ("Accepted reconstructions — group", "Cumulative accepted-source progress is"),
            ("Accepted isolated reconstruction — group", "Cumulative accepted-source accounting is"),
            ("Accepted source reconstruction — group", "Source reconstruction is now"),
            ("Verified reconstruction checkpoint — group", "Cumulative accepted-source progress is"),
            ("Source reconstruction checkpoint (2026-09-30)", "Cumulative accepted-source progress is"),
        ):
            with self.subTest(title=title):
                result = progress.ProgressTracker._parse_checkpoint(checkpoint(title, declaration=declaration))
                self.assertEqual(result["acceptedUnits"], 1379)
                self.assertEqual(result["checkpointTitle"], title)

    def test_newest_selection_survives_repeated_and_malformed_older_records(self):
        malformed = "## Verified reconstruction checkpoint older\n\n- Verification passed; measurements missing.\n\n"
        result = progress.ProgressTracker._parse_checkpoint(checkpoint() + checkpoint("Committed-source checkpoint repeated")
                                                           + malformed + previous_checkpoint())
        self.assertEqual(result["checkpointTitle"], "Committed-source checkpoint cdda4dc3")
        self.assertEqual(result["acceptedUnits"], 1379)

    def test_failed_refresh_retains_last_good_headline_history_and_warning(self):
        tracker = memory_tracker(checkpoint())
        dated = [{"at": "2026-10-13", "acceptedBytes": 471424, "totalBytes": 15833556,
                  "acceptedUnits": 1379, "checkpointCommit": NEW_COMMIT,
                  "checkpointTitle": "Committed-source checkpoint cdda4dc3",
                  "timestampMeaning": "recorded checkpoint date (day precision)"}]
        with patch.object(progress, "read_checkpoint_history", return_value=(dated, None)) as reader, \
                patch.object(progress, "read_checkpoint_publication", return_value=(dated[0], None)):
            tracker._refresh_checkpoint()
            original_observations = list(tracker._history)
            tracker._changelog_fingerprint.return_value = "malformed-input"
            tracker.changelog_path.read_text.return_value = (
                "## Committed-source checkpoint newer\n\n- Verification passed; counts pending.\n\n" + checkpoint())
            tracker._refresh_checkpoint()
            reader.assert_called_once()
        selected, _, _, _, warnings = tracker.state_parts()
        self.assertEqual(selected["commit"], NEW_COMMIT)
        self.assertEqual(selected["updatedAt"], "2026-10-13")
        self.assertIsNone(selected["ageSeconds"])
        self.assertTrue(selected["lastGood"])
        self.assertEqual(tracker._checkpoint_history, dated)
        self.assertEqual(tracker._history, original_observations)
        self.assertEqual(len(warnings), 1)
        self.assertIn("checkpoint refresh failed:", warnings[0])
        self.assertIn("lacks complete counts", warnings[0])
        tracker._changelog_fingerprint.return_value = "corrected-input"
        tracker.changelog_path.read_text.return_value = ORDINARY_DCD4 + checkpoint()
        with patch.object(progress, "read_checkpoint_history", return_value=(dated, None)), \
                patch.object(progress, "read_checkpoint_publication", return_value=(dated[0], None)):
            tracker._refresh_checkpoint()
        self.assertFalse(tracker.state_parts()[0]["lastGood"])
        self.assertEqual(tracker.state_parts()[4], [])


class CheckpointDeltaTests(unittest.TestCase):
    def test_distinct_zero_credit_checkpoint_keeps_zero_delta_and_last_good(self):
        newest = checkpoint("Committed-source checkpoint nonmatching (2026-10-15)")
        prior = checkpoint("Committed-source checkpoint prior (2026-10-14)", commit=OLD_COMMIT)
        earlier = checkpoint("Committed-source checkpoint earlier (2026-10-13)", 471416, 1378, "a" * 40)
        tracker = memory_tracker(newest + prior + earlier)
        tracker._refresh_checkpoint()
        selected, _, _, chart, warnings = tracker.state_parts()
        self.assertEqual((selected["acceptedBytesDelta"], selected["acceptedUnitsDelta"]), (0, 0))
        self.assertEqual((selected["commit"], selected["acceptedBytes"], selected["acceptedUnits"]),
                         (NEW_COMMIT, 471424, 1379))
        self.assertEqual(selected["updatedAt"], "2026-10-15")
        self.assertEqual(chart[-1]["acceptedBytes"], 471424)
        self.assertEqual(warnings, [])
        tracker._changelog_fingerprint.return_value = "malformed-newest"
        tracker.changelog_path.read_text.return_value = (
            "## Committed-source checkpoint unfinished\n\n- Verification passed; counts pending.\n\n"
            + newest + prior + earlier)
        tracker._refresh_checkpoint()
        retained, _, _, retained_chart, warnings = tracker.state_parts()
        self.assertTrue(retained["lastGood"])
        self.assertEqual((retained["acceptedBytesDelta"], retained["acceptedUnitsDelta"]), (0, 0))
        self.assertEqual((retained["commit"], retained["updatedAt"]), (NEW_COMMIT, "2026-10-15"))
        self.assertEqual(retained_chart, chart)
        self.assertIn("lacks complete counts", warnings[0])

    def test_same_source_documentation_repeats_do_not_reset_positive_delta(self):
        text = checkpoint() + checkpoint("Committed-source checkpoint repeated documentation")
        text += previous_checkpoint() + checkpoint("Committed-source checkpoint oldest", 471408, 1377, "a" * 40)
        selected = progress.ProgressTracker._parse_checkpoint(text)
        self.assertEqual(selected["commit"], NEW_COMMIT)
        self.assertEqual((selected["acceptedBytesDelta"], selected["acceptedUnitsDelta"]), (8, 1))

    def test_same_source_repeat_stops_at_distinct_equal_total_checkpoint(self):
        text = checkpoint() + checkpoint("Committed-source checkpoint repeated documentation")
        text += checkpoint("Committed-source checkpoint prior", commit=OLD_COMMIT) + previous_checkpoint()
        selected = progress.ProgressTracker._parse_checkpoint(text)
        self.assertEqual((selected["acceptedBytesDelta"], selected["acceptedUnitsDelta"]), (0, 0))

    def test_legacy_records_without_source_identity_do_not_borrow_older_credit(self):
        latest = checkpoint("Accepted source reconstruction — latest", declaration="Source reconstruction is now")
        latest = latest.replace(f" for committed snapshot `{NEW_COMMIT}`", "")
        for prior_bytes, prior_units, expected in ((471424, 1379, (0, 0)), (471416, 1378, (8, 1))):
            with self.subTest(prior_bytes=prior_bytes):
                prior = checkpoint("Accepted source reconstruction — prior", prior_bytes, prior_units,
                                   declaration="Source reconstruction is now")
                prior = prior.replace(f" for committed snapshot `{NEW_COMMIT}`", "")
                earlier = checkpoint("Committed-source checkpoint earlier", 471408, 1377, "a" * 40)
                selected = progress.ProgressTracker._parse_checkpoint(latest + prior + earlier)
                self.assertIsNone(selected["commit"])
                self.assertEqual((selected["acceptedBytesDelta"], selected["acceptedUnitsDelta"]), expected)

    def test_missing_baseline_and_decreasing_totals_remain_unknown(self):
        for text in (checkpoint(), checkpoint() + checkpoint(
                "Committed-source checkpoint higher prior", 471432, 1380, OLD_COMMIT)):
            with self.subTest(text=text):
                selected = progress.ProgressTracker._parse_checkpoint(text)
                self.assertEqual((selected["acceptedBytesDelta"], selected["acceptedUnitsDelta"]), (None, None))
                self.assertEqual((selected["acceptedBytes"], selected["acceptedUnits"]), (471424, 1379))


class CheckpointTimestampTests(unittest.TestCase):
    def test_recorded_dates_preserve_precision_and_ignore_file_mtime(self):
        cases = [
            (checkpoint("Committed-source checkpoint (2026-10-13)"),
             "2026-10-13", "recorded checkpoint date (day precision)"),
            (checkpoint().replace("- Cumulative", "- 2026-10-13T10:20:30-07:00: Cumulative"),
             "2026-10-13T17:20:30Z", "recorded checkpoint timestamp"),
        ]
        for text, expected, meaning in cases:
            with self.subTest(expected=expected):
                tracker = memory_tracker(text)
                with patch.object(history.subprocess, "run") as git:
                    tracker._refresh_checkpoint()
                    tracker.changelog_path.stat.return_value.st_mtime = 9999999999
                    tracker.changelog_path.read_text.return_value = ORDINARY_DCD4 + text
                    tracker._changelog_fingerprint.return_value = "unrelated-input"
                    tracker._refresh_checkpoint()
                git.assert_not_called()
                selected = tracker.state_parts()[0]
                self.assertEqual(selected["updatedAt"], expected)
                self.assertEqual(selected["timestampMeaning"], meaning)
                self.assertEqual(selected["commit"], NEW_COMMIT)
                self.assertEqual(selected["acceptedBytes"], 471424)
                self.assertEqual(selected["ageSeconds"] is None, len(expected) == 10)

    def test_undated_checkpoint_does_not_borrow_equal_byte_recorded_date(self):
        title = "Committed-source checkpoint repeated title"
        newest = checkpoint(title, commit="f" * 40)
        older = checkpoint(title).replace("- Cumulative", "- 2026-10-12: Cumulative")
        for outcome in (OSError("Git unavailable"), SimpleNamespace(stdout="")):
            with self.subTest(outcome=outcome):
                tracker = memory_tracker(newest + older)
                with patch.object(history.subprocess, "run") as git:
                    if isinstance(outcome, Exception):
                        git.side_effect = outcome
                    else:
                        git.return_value = outcome
                    tracker._refresh_checkpoint()
                selected, _, _, chart, warnings = tracker.state_parts()
                self.assertEqual(selected["commit"], "f" * 40)
                self.assertEqual(selected["acceptedBytes"], 471424)
                self.assertIsNone(selected["updatedAt"])
                self.assertIsNone(selected["ageSeconds"])
                self.assertEqual(selected["timestampMeaning"],
                                 "checkpoint publication date unknown (uncommitted or Git unavailable)")
                self.assertTrue(any(point["at"] == "2026-10-12" for point in chart))
                self.assertEqual(bool(warnings), isinstance(outcome, Exception))

    def test_cached_publication_is_checkpoint_specific_when_git_disappears(self):
        text = checkpoint()
        tracker = memory_tracker(text)
        with patch.object(history.subprocess, "run", return_value=published_blame(text)):
            tracker._refresh_checkpoint()
        original = tracker.state_parts()[0]
        self.assertEqual(original["timestampMeaning"], "Git publication time, not verification time")
        with patch.object(history.subprocess, "run", side_effect=OSError("Git unavailable")):
            tracker._changelog_fingerprint.return_value = "git-unavailable"
            tracker.changelog_path.read_text.return_value = ORDINARY_DCD4 + text
            tracker._refresh_checkpoint()
            cached, _, _, _, warnings = tracker.state_parts()
            self.assertEqual(cached["updatedAt"], original["updatedAt"])
            self.assertEqual(cached["timestampMeaning"], original["timestampMeaning"])
            self.assertEqual(warnings, [])  # Cached published identities require no Git lookup.
            # Same title and byte count do not establish the same checkpoint:
            # either a different snapshot or different unit count invalidates its cache.
            for newest in (checkpoint(commit="f" * 40), checkpoint(units=1380)):
                tracker._changelog_fingerprint.return_value = newest
                tracker.changelog_path.read_text.return_value = newest + text
                tracker._refresh_checkpoint()
                self.assertIsNone(tracker.state_parts()[0]["updatedAt"])


class CheckpointPublicationTimeoutTests(unittest.TestCase):
    def test_new_headline_and_observation_publish_before_history_timeout(self):
        tracker = memory_tracker(previous_checkpoint())
        with patch.object(history.subprocess, "run", return_value=published_blame(previous_checkpoint())):
            tracker._refresh_checkpoint()
        text = checkpoint() + previous_checkpoint() + checkpoint(
            "Committed-source checkpoint ancient", 471408, 1377, "1" * 40)
        tracker.changelog_path.read_text.return_value = text
        tracker._changelog_fingerprint.return_value = "new-publication"
        calls = []

        def slow_history(command, **kwargs):
            selected, _, _, chart, _ = tracker.state_parts()
            self.assertEqual((selected["commit"], selected["acceptedBytes"]), (NEW_COMMIT, 471424))
            self.assertEqual(chart[-1]["acceptedBytes"], 471424)
            calls.append(command)
            if len(calls) == 1:
                # Even a slow selected-record lookup cannot retain old counters
                # or borrow the predecessor's publication date.
                self.assertIsNone(selected["updatedAt"])
                return published_blame(text, timestamp=1792023178)
            self.assertEqual(selected["updatedAt"], "2026-10-15T00:12:58Z")
            raise subprocess.TimeoutExpired(command, kwargs["timeout"])

        with patch.object(history.subprocess, "run", side_effect=slow_history):
            tracker._refresh_checkpoint()
        self.assertEqual(len(calls), 2)
        selected, _, _, chart, warnings = tracker.state_parts()
        self.assertEqual(selected["commit"], NEW_COMMIT)
        self.assertEqual(selected["updatedAt"], "2026-10-15T00:12:58Z")
        self.assertEqual(chart[-1]["acceptedBytes"], 471424)
        self.assertIn("TimeoutExpired", warnings[0])

    def test_selected_timeout_keeps_new_counters_and_recovers_without_file_change(self):
        tracker = memory_tracker(previous_checkpoint())
        with patch.object(history.subprocess, "run", return_value=published_blame(previous_checkpoint())):
            tracker._refresh_checkpoint()
        text = checkpoint() + previous_checkpoint()
        tracker.changelog_path.read_text.return_value = text
        tracker._changelog_fingerprint.return_value = "new-publication"
        with patch.object(history.subprocess, "run",
                          side_effect=subprocess.TimeoutExpired("git blame", 3)):
            tracker._refresh_checkpoint()
        selected, _, _, chart, warnings = tracker.state_parts()
        self.assertEqual((selected["commit"], selected["acceptedBytes"]), (NEW_COMMIT, 471424))
        self.assertIsNone(selected["updatedAt"])
        self.assertIsNone(selected["ageSeconds"])
        self.assertIn("unknown", selected["timestampMeaning"])
        self.assertEqual(chart[-1]["acceptedBytes"], 471424)
        self.assertIn("TimeoutExpired", warnings[0])
        with patch.object(history.subprocess, "run", return_value=published_blame(text, timestamp=1792023178)):
            tracker._refresh_checkpoint()
        selected, _, _, _, warnings = tracker.state_parts()
        self.assertEqual(selected["updatedAt"], "2026-10-15T00:12:58Z")
        self.assertEqual(warnings, [])

    def test_history_can_recover_selected_date_in_same_refresh(self):
        text = checkpoint()
        tracker = memory_tracker(text)
        with patch.object(history.subprocess, "run", side_effect=[
                subprocess.TimeoutExpired("git blame", 3),
                published_blame(text, timestamp=1792023178)]):
            tracker._refresh_checkpoint()
        selected, _, _, _, warnings = tracker.state_parts()
        self.assertEqual(selected["commit"], NEW_COMMIT)
        self.assertEqual(selected["updatedAt"], "2026-10-15T00:12:58Z")
        self.assertEqual(warnings, [])


class RealGitCheckpointTimestampTests(unittest.TestCase):
    def test_publication_survives_unrelated_edits_and_dates_equal_byte_successors(self):
        root = (Path(__file__).resolve().parents[2] / "build" / "checkpoint-publication-time"
                / ("git-fixture-" + uuid4().hex))
        root.mkdir(parents=True)

        def remove_readonly(function, path, _exc_info):
            # Git object files may be read-only on Windows.
            os.chmod(path, stat.S_IWRITE)
            function(path)

        # unittest runs cleanups even when setup, Git or an assertion fails.
        self.addCleanup(shutil.rmtree, root, onerror=remove_readonly)
        changelog = root / "CHANGELOG.md"
        report = root / "report.json"
        report.write_text(json.dumps({"measures": {"total_code": 15833556}, "units": []}), encoding="utf-8")

        def git(*args, date=None):
            env = dict(os.environ)
            if date:
                env.update(GIT_AUTHOR_DATE=date, GIT_COMMITTER_DATE=date)
            return subprocess.run(
                ["git", "-c", "user.name=Checkpoint regression", "-c", "user.email=checkpoint@example.invalid",
                 "-c", "commit.gpgsign=false", "-c", f"core.hooksPath={root / 'no-hooks'}", *args],
                cwd=root, env=env, text=True, encoding="utf-8", errors="replace",
                creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0),
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, timeout=30).stdout.strip()

        def publish(date):
            git("add", "CHANGELOG.md")
            return git("commit", "-m", "Fixture publication", date=date)

        git("init", "--quiet")
        changelog.write_text(previous_checkpoint(), encoding="utf-8")
        publish("2026-10-10T10:00:00Z")
        text = checkpoint() + previous_checkpoint()
        changelog.write_text(text, encoding="utf-8")
        publish("2026-10-11T11:00:00Z")
        tracker = progress.ProgressTracker(report, root, root / "observations.json")
        report_state = None

        def observe(stage, expected_date, expected_commit=NEW_COMMIT):
            nonlocal report_state
            tracker.refresh()
            selected, report_time, revision, chart, _warnings = tracker.state_parts()
            self.assertEqual(selected["updatedAt"], expected_date)
            self.assertEqual(selected["commit"], expected_commit)
            self.assertEqual((selected["acceptedBytes"], selected["acceptedUnits"]), (471424, 1379))
            self.assertEqual(selected["source"], "changelog")
            self.assertEqual(chart[-1]["acceptedBytes"], 471424)
            current_report = (report_time, revision, tracker.units_bytes(), tracker.units_provenance())
            if report_state is None:
                report_state = current_report
            self.assertEqual(current_report, report_state)
            return selected

        published = "2026-10-11T11:00:00Z"
        observe("published checkpoint", published)
        text = ORDINARY_DCD4 + text
        changelog.write_text(text, encoding="utf-8")
        observe("unrelated section insertion", published)
        text = text.replace(previous_checkpoint(),
                            "- Follow-up verification on 2026-10-12T12:00:00Z passed again.\n\n"
                            + previous_checkpoint())
        changelog.write_text(text, encoding="utf-8")
        observe("follow-up verification prose", published)
        st = changelog.stat()
        os.utime(changelog, ns=(st.st_atime_ns, st.st_mtime_ns + 60000000000))
        observe("file touch", published)
        publish("2026-10-12T12:00:00Z")
        observe("unrelated changelog documentation commit", published)
        (root / "notes.txt").write_text("Unrelated documentation.\n", encoding="utf-8")
        git("add", "notes.txt")
        git("commit", "-m", "Unrelated fixture docs", date="2026-10-12T13:00:00Z")
        observe("unrelated other-file documentation commit", published)
        successor = checkpoint("Committed-source checkpoint successor", commit="f" * 40)
        text = successor + text
        changelog.write_text(text, encoding="utf-8")
        unknown = observe("uncommitted equal-byte successor", None, "f" * 40)
        self.assertIn("unknown", unknown["timestampMeaning"])
        publish("2026-10-13T13:00:00Z")
        observe("published equal-byte successor", "2026-10-13T13:00:00Z", "f" * 40)
        text = text.replace("f" * 40, "e" * 40)
        changelog.write_text(text, encoding="utf-8")
        observe("uncommitted same-title new snapshot", None, "e" * 40)
        publish("2026-10-14T14:00:00Z")
        selected = observe("published same-title new snapshot", "2026-10-14T14:00:00Z", "e" * 40)
        self.assertEqual(selected["timestampMeaning"], "Git publication time, not verification time")
        with patch.object(history.subprocess, "run", side_effect=OSError("Git unavailable")):
            observe("cached publication while Git unavailable", "2026-10-14T14:00:00Z", "e" * 40)
        # Exercise real selected-record Git dating while historical dating hits
        # the observed timeout. The current headline must already be available.
        cold = progress.ProgressTracker(report, root, root / "cold-observations.json")
        run_git = subprocess.run
        timed_out = []

        def interrupted_backfill(command, **kwargs):
            if "blame" in command and kwargs.get("timeout") == 30:
                headline = cold.state_parts()[0]
                self.assertEqual(headline["commit"], "e" * 40)
                self.assertEqual(headline["updatedAt"], "2026-10-14T14:00:00Z")
                timed_out.append(True)
                raise subprocess.TimeoutExpired(command, 30)
            return run_git(command, **kwargs)

        with patch.object(history.subprocess, "run", side_effect=interrupted_backfill):
            cold.refresh()
        headline, _, _, chart, warnings = cold.state_parts()
        self.assertTrue(timed_out)
        self.assertEqual(headline["commit"], "e" * 40)
        self.assertEqual(headline["updatedAt"], "2026-10-14T14:00:00Z")
        self.assertEqual(chart[-1]["acceptedBytes"], 471424)
        self.assertIn("TimeoutExpired", warnings[0])


class CheckpointHistoryTests(unittest.TestCase):
    def test_committed_records_join_history_in_document_order(self):
        newest = checkpoint("Committed-source checkpoint newest (2026-10-13)")
        older = checkpoint("Committed-source checkpoint older (2026-10-12)", 471416, 1378, OLD_COMMIT)
        with patch.object(history.subprocess, "run") as git:
            points, warning = history.read_checkpoint_history("unused", ORDINARY_DCD4 + newest + older, 15833556)
        git.assert_not_called()
        self.assertIsNone(warning)
        self.assertEqual([point["acceptedBytes"] for point in points], [471424, 471416])
        self.assertEqual([point["at"] for point in points], ["2026-10-13", "2026-10-12"])
        self.assertTrue(all(point["source"] == "changelog" for point in points))
        self.assertTrue(all(point["timestampMeaning"] == "recorded checkpoint date (day precision)" for point in points))

    def test_supported_historical_sections_and_report_declarations(self):
        for title, declaration in (
            ("Accepted reconstruction", "Cumulative accepted-source progress is"),
            ("Accepted isolated reconstructions", "Cumulative accepted-source accounting is"),
            ("Accepted source reconstructions", "Source reconstruction is now"),
            ("Accepted source reconstruction", "The regenerated source-reconstruction report records"),
            ("Accepted source reconstruction", "The regenerated report records"),
            ("Accepted source reconstruction", "Regenerated the report and calculated"),
            ("Verified reconstruction checkpoint", "Cumulative accepted-source progress is"),
            ("Source reconstruction checkpoint", "Whole-project accepted source reconstruction is"),
        ):
            with self.subTest(title=title, declaration=declaration):
                text = checkpoint(title + " (2026-09-30)", declaration=declaration)
                text = text.replace("accepted code bytes", "accepted source code bytes")
                # Historical chart records need no unit counter; headline records do.
                text = text.replace(" and **1,379 accepted source units**", "")
                points, warning = history.read_checkpoint_history("unused", text, 15833556)
                self.assertIsNone(warning)
                self.assertEqual(len(points), 1)
                self.assertEqual(points[0]["acceptedBytes"], 471424)
                self.assertEqual(points[0]["at"], "2026-09-30")

    def test_history_ignores_ordinary_entries_even_with_private_measurements(self):
        ordinary = checkpoint("Unit reconstruction verification (2026-10-13)")
        ordinary += ORDINARY_DCD4.replace("Dedede DCD4 — exact GLM source reconstruction", "Accepted reconstruction — DCD4")
        ordinary += checkpoint("Accepted reconstruction — private run (2026-10-13)",
                               declaration="Private verification measurements are")
        ordinary += "- Cumulative accepted-source accounting belongs to the publisher.\n"
        self.assertEqual(history.read_checkpoint_history("unused", ordinary, 15833556), ([], None))

    def test_running_log_does_not_assign_heading_date_to_later_totals(self):
        text = ("## Source reconstruction checkpoint (2026-09-30)\n\n"
                "### Accepted entries\n- Verification passed all native hashes.\n"
                "- 2026-10-01: 10 / 100 accepted code bytes, 90 bytes remaining.\n"
                "- 20 / 100 accepted code bytes, 80 bytes remaining.\n")
        cached = {"at": "2026-10-02T12:00:00Z", "acceptedBytes": 20, "totalBytes": 100,
                  "acceptedUnits": None, "checkpointCommit": None,
                  "checkpointTitle": "Source reconstruction checkpoint (2026-09-30)",
                  "source": "changelog", "timestampMeaning": "Git publication time, not verification time"}
        with patch.object(history.subprocess, "run", side_effect=OSError("Git unavailable")):
            points, warning = history.read_checkpoint_history("unused", text, 100, [cached])
        self.assertEqual([point["at"] for point in points], ["2026-10-01", cached["at"]])
        self.assertEqual(points[1], cached)
        self.assertIsNone(warning)

    def test_git_publication_provenance_still_uses_actual_accounting_line(self):
        text = checkpoint()
        with patch.object(history.subprocess, "run", return_value=published_blame(text)) as git:
            points, warning = history.read_checkpoint_history("unused", text, 15833556)
        self.assertIsNone(warning)
        self.assertEqual(len(points), 1)
        self.assertEqual(points[0]["commit"], "a" * 40)
        self.assertEqual(points[0]["timestampMeaning"], "Git publication time, not verification time")
        self.assertEqual(git.call_args.kwargs["input"], text)

    def test_invalid_old_history_measurements_are_not_fabricated(self):
        invalid = checkpoint("Committed-source checkpoint invalid (2026-10-13)")
        invalid = invalid.replace("15,362,132 code bytes remaining", "15,362,140 code bytes remaining")
        self.assertEqual(history.read_checkpoint_history("unused", invalid, 15833556), ([], None))

    def test_equal_time_history_keeps_document_latest_not_numeric_maximum(self):
        text = checkpoint("Committed-source checkpoint latest (2026-10-13)", 471416, 1378, OLD_COMMIT)
        text += checkpoint("Committed-source checkpoint earlier (2026-10-13)")
        points, warning = history.read_checkpoint_history("unused", text, 15833556)
        tracker = memory_tracker(text)
        tracker._checkpoint_history = points
        self.assertIsNone(warning)
        self.assertEqual(tracker.state_parts()[3][0]["acceptedBytes"], 471416)


if __name__ == "__main__":
    unittest.main()
