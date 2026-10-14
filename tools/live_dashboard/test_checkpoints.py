"""Checkpoint behavior regressions; run with unittest discovery here."""

import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import Mock, patch

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
        dated = [{"at": "2026-10-13", "acceptedBytes": 471424,
                  "checkpointTitle": "Committed-source checkpoint cdda4dc3"}]
        with patch.object(progress, "read_checkpoint_history", return_value=(dated, None)) as reader:
            tracker._refresh_checkpoint()
            original_observations = list(tracker._history)
            tracker._changelog_fingerprint.return_value = "malformed-input"
            tracker.changelog_path.read_text.return_value = (
                "## Committed-source checkpoint newer\n\n- Verification passed; counts pending.\n\n" + checkpoint())
            tracker._refresh_checkpoint()
            reader.assert_called_once()
        selected, _, _, _, warnings = tracker.state_parts()
        self.assertEqual(selected["commit"], NEW_COMMIT)
        self.assertTrue(selected["lastGood"])
        self.assertEqual(tracker._checkpoint_history, dated)
        self.assertEqual(tracker._history, original_observations)
        self.assertEqual(len(warnings), 1)
        self.assertIn("checkpoint refresh failed:", warnings[0])
        self.assertIn("lacks complete counts", warnings[0])
        tracker._changelog_fingerprint.return_value = "corrected-input"
        tracker.changelog_path.read_text.return_value = ORDINARY_DCD4 + checkpoint()
        with patch.object(progress, "read_checkpoint_history", return_value=(dated, None)):
            tracker._refresh_checkpoint()
        self.assertFalse(tracker.state_parts()[0]["lastGood"])
        self.assertEqual(tracker.state_parts()[4], [])


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
        cached = {"at": "2026-10-02T12:00:00Z", "acceptedBytes": 20,
                  "checkpointTitle": "Source reconstruction checkpoint (2026-09-30)",
                  "source": "changelog", "timestampMeaning": "Git publication time, not verification time"}
        with patch.object(history.subprocess, "run", side_effect=OSError("Git unavailable")):
            points, warning = history.read_checkpoint_history("unused", text, 100, [cached])
        self.assertEqual([point["at"] for point in points], ["2026-10-01", cached["at"]])
        self.assertEqual(points[1], cached)
        self.assertIn("Git publication dates unavailable", warning)

    def test_git_publication_provenance_still_uses_actual_accounting_line(self):
        text = checkpoint()
        number = next(index for index, line in enumerate(text.splitlines(), 1) if "471,424 /" in line)
        blame = f"{'a' * 40} 1 {number} 1\ncommitter-time 1791849600\n\taccounting line\n"
        with patch.object(history.subprocess, "run", return_value=SimpleNamespace(stdout=blame)) as git:
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
