"""Recover accepted-byte checkpoints without guessing verification timestamps.

Explicit checkpoint dates take precedence. Otherwise Git blame supplies the
publication date of the cumulative-total line, following its move from PLAN.md.
Per-unit, current-wave and assembly-match figures are not whole-project totals.
Candidates retain newest-first document order, including cached dates when Git
cannot recover them. The chart can then retain the document's latest total at
an indistinguishable publication time without choosing the numeric maximum.

Checkpoint headings identify dedicated records even when measurements are missing.
Legacy accepted-reconstruction sections need an explicit cumulative/report
declaration; references to publisher accounting do not declare a checkpoint.
"""

from __future__ import annotations

import re
import subprocess
from datetime import datetime, timezone


SECTION = re.compile(r"^## (.+)$", re.M)
CHECKPOINT_SECTION = re.compile(
    r"^(?:Committed-source checkpoint|Verified reconstruction checkpoint|"
    r"Source reconstruction checkpoint)\b", re.I)
ACCEPTED_SECTION = re.compile(
    r"^Accepted(?: isolated| source)? reconstructions?\b", re.I)
LEGACY_RECORD = re.compile(
    r"\bcumulative accepted-source (?:progress|accounting)"
    r"(?: from [^\n]*?)? is\b|"
    r"\bsource reconstruction is now\b|"
    r"\bregenerated (?:source-reconstruction )?report records\b|"
    r"\bregenerated the report and calculated\b", re.I)
COUNTS = re.compile(
    r"([\d,]+)\s*/\s*([\d,]+)\s+(?:accepted\s+)?(?:source\s+)?code bytes", re.I)
DATE = re.compile(r"\b\d{4}-\d{2}-\d{2}(?:T\d{2}:\d{2}:\d{2}(?:\.\d+)?(?:Z|[+-]\d{2}:\d{2}))?\b")


def is_checkpoint_section(title, section):
    """Recognize record intent without requiring valid measurements."""
    return bool(CHECKPOINT_SECTION.search(title) or (
        ACCEPTED_SECTION.search(title)
        and LEGACY_RECORD.search(section.replace("**", ""))))


def _recorded_date(text):
    match = DATE.search(text)
    if not match:
        return None
    value = match.group()
    try:
        date = datetime.fromisoformat(value.replace("Z", "+00:00"))
    except ValueError:
        return None
    if len(value) == 10:
        # Preserve day precision; do not claim a verification time of midnight.
        return value, "recorded checkpoint date (day precision)"
    return date.astimezone(timezone.utc).isoformat().replace("+00:00", "Z"), "recorded checkpoint timestamp"


def _candidates(text, expected_total):
    headings = list(SECTION.finditer(text))
    candidates = []
    for index, heading in enumerate(headings):
        title = heading.group(1).strip()
        end = headings[index + 1].start() if index + 1 < len(headings) else len(text)
        section = text[heading.end():end]
        if not is_checkpoint_section(title, section):
            continue
        if not re.search(r"\bverified\b|\bverification\b|\bpass(?:ed|ing)?\b", section, re.I):
            continue
        first_line = text.count("\n", 0, heading.end()) + 1
        section_points = []
        for offset, line in enumerate(section.splitlines()):
            plain = line.replace("**", "")
            counts = COUNTS.search(plain)
            remaining = re.search(r"([\d,]+)\s+(?:code\s+)?bytes remaining", plain, re.I)
            if not counts or not remaining:
                continue
            accepted, total = (int(value.replace(",", "")) for value in counts.groups())
            left = int(remaining.group(1).replace(",", ""))
            percent = re.search(r"(\d+\.\d+)%", plain)
            if total != expected_total or not 0 <= accepted <= total or left != total - accepted:
                continue
            if percent and abs(float(percent.group(1)) - 100 * accepted / total) > 0.00000051:
                continue
            section_points.append({
                "line": first_line + offset,
                "acceptedBytes": accepted,
                "checkpointTitle": title,
                "recorded": _recorded_date(plain),
            })
        # A dated running log can contain entries added days later. Its heading
        # is not a date for those later checkpoints.
        if len(section_points) == 1 and not re.search(r"^### ", section, re.M):
            section_points[0]["recorded"] = section_points[0]["recorded"] or _recorded_date(title)
        candidates.extend(section_points)
    return candidates


def read_checkpoint_history(root, text, expected_total, cached_points=()):
    """Return document-ordered dated points and a dating warning; never mutate Git."""
    candidates = _candidates(text, expected_total)
    if not candidates:
        return [], None
    cached = {}
    for point in cached_points:
        cached.setdefault((point["checkpointTitle"], point["acceptedBytes"]), point)
    dates = {}
    git_error = None
    if any(not point["recorded"] for point in candidates):
        try:
            result = subprocess.run(
                ["git", "blame", "-w", "-C", "--line-porcelain", "--contents", "-", "--", "CHANGELOG.md"],
                cwd=root, input=text, text=True, encoding="utf-8", errors="replace",
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30, check=True,
            )
            commit = None
            line_number = None
            timestamp = None
            for line in result.stdout.splitlines():
                header = re.fullmatch(r"([0-9a-f]{40,64}) \d+ (\d+)(?: \d+)?", line)
                if header:
                    commit, line_number = header.group(1), int(header.group(2))
                    timestamp = None
                elif line.startswith("committer-time "):
                    timestamp = int(line.split()[1])
                elif line.startswith("\t") and commit and timestamp is not None and set(commit) != {"0"}:
                    dates[line_number] = (commit, datetime.fromtimestamp(timestamp, timezone.utc)
                                          .isoformat(timespec="seconds").replace("+00:00", "Z"))
        except (OSError, subprocess.SubprocessError, ValueError, OverflowError) as exc:
            git_error = f"Git publication dates unavailable ({type(exc).__name__})"
    points = []
    undated = 0
    for candidate in candidates:
        recorded = candidate["recorded"]
        publication = dates.get(candidate["line"])
        if not recorded and not publication:
            undated += 1
            previous = cached.get((candidate["checkpointTitle"], candidate["acceptedBytes"]))
            if previous is not None:
                points.append(previous)
            continue
        point = {
            "at": recorded[0] if recorded else publication[1],
            "acceptedBytes": candidate["acceptedBytes"],
            "source": "changelog",
            "checkpointTitle": candidate["checkpointTitle"],
            "timestampMeaning": recorded[1] if recorded else "Git publication time, not verification time",
        }
        if publication:
            point["commit"] = publication[0]
        points.append(point)
    # Uncommitted additions are expected during reconstruction. The tracker
    # retains live observations and retries dating when the changelog is committed.
    return points, git_error if undated else None
