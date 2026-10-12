"""Progress computation for the live dashboard.

The latest verified cumulative checkpoint in CHANGELOG.md supplies headline
progress. The existing counter supplies the separately labelled report unit
map; the two sources are never presented as the same checkpoint merely because
a build report exists. Each input is fingerprint-cached, and refresh failures
retain the last-good data with explicit provenance and warnings.

Chart history backfills verified cumulative totals only before the first valid
dashboard observation. From that boundary onward, observations are authoritative;
later Git publication dates must not replay older cumulative totals. Equal-time
backfill keeps the latest checkpoint in newest-first document order, even when
its count is lower. Checkpoints are never used to fabricate observation times.
The observation serving limit applies only to the recent observed tail; the
first observation is retained across cache pruning/reloads to keep the boundary
stable. All reachable earlier backfill remains available, independent of that
limit. Undated checkpoints are omitted rather than assigned a guessed time.
"""

from __future__ import annotations

import hashlib
import importlib.util
import json
import subprocess
import threading
import re
from datetime import datetime, timezone
from pathlib import Path

from checkpoint_history import read_checkpoint_history

HISTORY_MAX_POINTS = 5000
HISTORY_SERVE_POINTS = 1000
HISTORY_HEARTBEAT_SECONDS = 300.0
MAX_MISSING_SOURCES_NAMED = 3

INITIAL_PROGRESS = {
    "available": False,
    "acceptedBytes": 0,
    "totalBytes": 0,
    "remainingBytes": 0,
    "percent": 0.0,
    "acceptedUnits": 0,
    "error": "progress not computed yet",
}


def _load_counter(path):
    spec = importlib.util.spec_from_file_location("reconstruction_progress", str(path))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


class ProgressTracker:
    """Fingerprint-cached progress/units built on the existing counter."""

    def __init__(self, report_path, root, history_path, counter_path=None):
        self.report_path = Path(report_path)
        self.root = Path(root)
        self.history_path = Path(history_path)
        self.changelog_path = self.root / "CHANGELOG.md"
        self._changelog_fp = None
        self._checkpoint = None
        self._report_progress = None
        if counter_path is None:
            counter_path = Path(__file__).resolve().parents[1] / "reconstruction_progress.py"
        self._counter = _load_counter(counter_path)
        self._lock = threading.Lock()
        self._fingerprint = None
        self._failed_fp = None
        self._missing = False
        self._progress = dict(INITIAL_PROGRESS)
        self._report_updated_at = None
        self._revision = None
        self._units_payload = b'{"revision":"pending","units":[]}'
        self._history = self._load_history()
        self._checkpoint_history = []
        self._warnings = {}

    # ------------------------------------------------------------------
    # public API
    # ------------------------------------------------------------------
    def fingerprint(self):
        try:
            st = self.report_path.stat()
        except OSError:
            return None
        return f"{st.st_mtime_ns}:{st.st_size}"

    def _changelog_fingerprint(self):
        try:
            st = self.changelog_path.stat()
        except OSError:
            return None
        # A commit can date a previously uncommitted checkpoint without changing
        # the working file's mtime. Unrelated commits need no history rebuild.
        try:
            revision = subprocess.run(
                ["git", "log", "-1", "--format=%H", "--", "CHANGELOG.md"],
                cwd=self.root, text=True, encoding="utf-8", errors="replace",
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=3, check=True,
            ).stdout.strip()
        except (OSError, subprocess.SubprocessError):
            revision = ""
        return f"{st.st_mtime_ns}:{st.st_size}:{revision}"

    def poll(self):
        """Watch both artifacts, including changelog-only publications."""
        return (self.fingerprint() != self._fingerprint
                or self._changelog_fingerprint() != self._changelog_fp)

    def refresh(self):
        """Refresh independent inputs, preserving their last-good snapshots."""
        self._refresh_checkpoint()
        fp = self.fingerprint()
        if fp is None:
            if not self._missing:
                self._missing = True
                with self._lock:
                    self._fingerprint = None  # re-arm when the report reappears
                self._fail(f"report not found: {self.report_path}")
            return
        with self._lock:
            unchanged = fp == self._fingerprint
            already_failed = fp == self._failed_fp
        if unchanged or already_failed:
            return
        self._missing = False
        try:
            self._recompute(fp)
        except json.JSONDecodeError:
            self._fail("report.json is not valid JSON (partial write?) - keeping last-good data")
            with self._lock:
                self._failed_fp = fp
        except Exception as exc:  # noqa: BLE001 - surfaced as error/warning below
            self._fail(f"report refresh failed: {exc.__class__.__name__}: {exc}")
            with self._lock:
                self._failed_fp = fp

    def state_parts(self):
        with self._lock:
            progress = dict(self._progress)
            updated = _parse_ts(progress.get("updatedAt") or "")
            progress["ageSeconds"] = (
                max(0, int((datetime.now(timezone.utc) - updated).total_seconds()))
                if updated else None
            )
            return (
                progress,
                self._report_updated_at,
                self._revision,
                self._chart_history(),
                list(self._warnings.values()),
            )

    def units_provenance(self):
        with self._lock:
            report = self._report_progress or {}
            stale = (not report or bool(self._warnings.get("report"))
                     or any(report.get(k) != self._progress.get(k)
                            for k in ("acceptedBytes", "totalBytes", "acceptedUnits")))
            return {
                "source": "report", "updatedAt": self._report_updated_at,
                "acceptedBytes": report.get("acceptedBytes"),
                "acceptedUnits": report.get("acceptedUnits"), "stale": stale,
                "reason": ("Report-derived unit map differs from the displayed checkpoint "
                           "or its report is unavailable; it is not the changelog checkpoint."
                           if stale else "Report counts agree with the displayed checkpoint; "
                           "unit classifications still come from report.json."),
            }

    def units_bytes(self):
        with self._lock:
            return self._units_payload

    # ------------------------------------------------------------------
    # internals
    # ------------------------------------------------------------------
    def _recompute(self, fp):
        st = self.report_path.stat()
        report_updated_iso = datetime.fromtimestamp(
            st.st_mtime, timezone.utc
        ).isoformat(timespec="milliseconds").replace("+00:00", "Z")
        report = json.loads(self.report_path.read_text(encoding="utf-8"))

        units, missing = self._classify_units(report)
        # The existing counter is the authoritative accepted-source gate.
        result = self._counter.calculate(report, self.root)

        revision = hashlib.sha1(
            f"{fp}:{len(units)}:{result['accepted_source_units']}".encode("utf-8")
        ).hexdigest()[:16]
        progress = {
            "available": True,
            "acceptedBytes": int(result["accepted_source_code_bytes"]),
            "totalBytes": int(result["total_code_bytes"]),
            "remainingBytes": int(result["remaining_code_bytes"]),
            "percent": round(float(result["percent_complete"]), 6),
            "acceptedUnits": int(result["accepted_source_units"]),
            "error": None,
            "source": "report", "updatedAt": report_updated_iso,
            "commit": None, "checkpointTitle": None, "precision": 6,
            "lastGood": False,
        }


        payload = json.dumps(
            {"revision": revision, "source": "report", "updatedAt": report_updated_iso,
             "acceptedBytes": progress["acceptedBytes"],
             "acceptedUnits": progress["acceptedUnits"], "units": units},
            separators=(",", ":")
        ).encode("utf-8")

        warnings = dict(self._warnings)
        if missing:
            shown = ", ".join(missing[:MAX_MISSING_SOURCES_NAMED])
            warnings["units"] = (
                f"{len(missing)} unit source file(s) missing on disk; marked unaccepted "
                f"(e.g. {shown})"
            )
        else:
            warnings.pop("units", None)
        warnings.pop("report", None)

        with self._lock:
            self._fingerprint = fp
            self._report_progress = progress
            self._report_updated_at = report_updated_iso
            self._revision = revision
            self._units_payload = payload
            self._select_progress()
            self._warnings = warnings

    def _refresh_checkpoint(self):
        fp = self._changelog_fingerprint()
        if fp == self._changelog_fp and fp is not None:
            return
        try:
            if fp is None:
                raise ValueError("CHANGELOG.md is unavailable")
            text = self.changelog_path.read_text(encoding="utf-8")
            checkpoint = self._parse_checkpoint(text)
            checkpoint.update({
                "available": True, "source": "changelog", "precision": 6,
                "updatedAt": datetime.fromtimestamp(
                    self.changelog_path.stat().st_mtime, timezone.utc
                ).isoformat(timespec="milliseconds").replace("+00:00", "Z"),
                "timestampMeaning": "CHANGELOG.md modification time, not verification time",
                "error": None, "lastGood": False,
            })
        except (OSError, ValueError) as exc:
            with self._lock:
                self._changelog_fp = fp
                self._warnings["changelog"] = f"checkpoint refresh failed: {exc}"
                if self._checkpoint:
                    self._checkpoint = dict(self._checkpoint, lastGood=True)
                self._select_progress()
            return
        history, history_warning = read_checkpoint_history(
            self.root, text, checkpoint["totalBytes"], cached_points=self._checkpoint_history)
        with self._lock:
            self._changelog_fp = fp
            self._checkpoint = checkpoint
            self._warnings.pop("changelog", None)
            # The reader restores cached dates in current document order so a
            # partial Git failure cannot change equal-time checkpoint priority.
            self._checkpoint_history = history
            if history_warning:
                self._warnings["history"] = history_warning
            else:
                self._warnings.pop("history", None)
            self._select_progress()

    @staticmethod
    def _parse_checkpoint(text):
        # CHANGELOG is newest-first. Only a section recording verification and
        # cumulative accepted-source accounting can supply a checkpoint.
        for section in re.split(r"(?m)^## ", text)[1:]:
            plain = section.replace("**", "")
            if not re.search(r"verified|verification|passing.*hashes", plain, re.I):
                continue
            if not re.search(r"cumulative accepted-source|source reconstruction is now",
                             plain, re.I):
                continue
            counts = re.search(
                r"([\d,]+)\s*/\s*([\d,]+)\s+(?:accepted\s+)?code bytes", plain)
            remaining = re.search(r"([\d,]+)\s+(?:code\s+)?bytes remaining", plain)
            units = re.findall(r"([\d,]+)\s+accepted source units", plain)
            percent = re.search(r"(\d+\.\d+)%", plain)
            if not counts or not remaining or not units or not percent:
                raise ValueError("latest verified cumulative section lacks complete counts")
            accepted, total = (int(s.replace(",", "")) for s in counts.groups())
            left = int(remaining.group(1).replace(",", ""))
            pct = float(percent.group(1))
            if total <= 0 or accepted < 0 or left != total - accepted \
                    or abs(pct - 100 * accepted / total) > 0.00000051:
                raise ValueError("latest verified checkpoint has inconsistent accounting")
            commit = re.search(
                r"(?:committed snapshot|snapshot)\s+`([0-9a-f]{7,40})`", section)
            return {
                "acceptedBytes": accepted, "totalBytes": total,
                "remainingBytes": left, "percent": round(pct, 6),
                "acceptedUnits": int(units[-1].replace(",", "")),
                "commit": commit.group(1) if commit else None,
                "checkpointTitle": section.splitlines()[0].strip(),
            }
        raise ValueError("no verified cumulative accepted-source checkpoint found")

    def _select_progress(self):
        """Caller holds the lock; history records only displayed checkpoints."""
        selected = self._checkpoint or self._report_progress
        if selected is None:
            return
        self._progress = dict(selected)
        now = datetime.now(timezone.utc)
        if self._history_should_append(self._history, selected["acceptedBytes"], now):
            self._history.append({
                "at": now.isoformat(timespec="milliseconds").replace("+00:00", "Z"),
                "acceptedBytes": selected["acceptedBytes"],
            })
            # Keep the first observation as the durable backfill boundary,
            # plus the recent tail. The persisted format remains a point list.
            if len(self._history) > HISTORY_MAX_POINTS:
                del self._history[1:len(self._history) - HISTORY_MAX_POINTS + 1]
            self._persist_history(self._history)

    def _classify_units(self, report):
        """Per-unit accepted flags using the counter's exact rule."""
        suffixes = self._counter.SOURCE_SUFFIXES
        non_code = self._counter.NON_CODE
        assembly = self._counter.ASSEMBLY
        units_out = []
        missing = []
        raw_units = report.get("units")
        if not isinstance(raw_units, list):
            return units_out, missing
        for unit in raw_units:
            if not isinstance(unit, dict):
                continue
            metadata = unit.get("metadata") if isinstance(unit.get("metadata"), dict) else {}
            measures = unit.get("measures") if isinstance(unit.get("measures"), dict) else {}
            name = unit.get("name") if isinstance(unit.get("name"), str) else ""
            try:
                size = int(measures.get("total_code", 0) or 0)
            except (TypeError, ValueError):
                size = 0
            source = metadata.get("source_path")
            source = source if isinstance(source, str) and source else None
            accepted = False
            if metadata.get("complete", False) and size > 0 and source:
                if Path(source).suffix.lower() in suffixes:
                    try:
                        text = (self.root / source).read_text(encoding="utf-8")
                        accepted = not assembly.search(non_code.sub(" ", text))
                    except OSError:
                        missing.append(source)
            match = measures.get("matched_code_percent")
            try:
                match_pct = round(float(match), 2) if match is not None else None
            except (TypeError, ValueError):
                match_pct = None
            module = metadata.get("module_name")
            units_out.append({
                "id": name,
                "name": name,
                "module": module if isinstance(module, str) and module else None,
                "bytes": size,
                "accepted": accepted,
                "source": source,
                "matchPercent": match_pct,
            })
        return units_out, missing

    def _fail(self, message):
        with self._lock:
            if self._report_progress:
                self._report_progress = dict(self._report_progress, lastGood=True)
            if not self._checkpoint and not self._report_progress:
                self._progress = dict(INITIAL_PROGRESS, error=message)
            self._warnings["report"] = message
            self._select_progress()

    # ------------------------------------------------------------------
    # history (persisted observations plus independently dated checkpoints)
    # ------------------------------------------------------------------
    def _chart_history(self):
        observations = []
        for point in self._history:
            at = _parse_ts(point["at"])
            if at is not None:
                observations.append((at, point))
        boundary = min((at for at, _ in observations), default=None)
        backfill = {}
        for point in self._checkpoint_history:
            at = _parse_ts(point["at"])
            if at is not None and (boundary is None or at < boundary):
                # The reader retains newest-first document order. An identical
                # publication time cannot date the intermediate checkpoints;
                # keep the document's latest total, not the numeric maximum.
                backfill.setdefault(at, point)
        points = list(backfill.items()) + observations[-HISTORY_SERVE_POINTS:]
        return [point for _, point in sorted(points, key=lambda pair: pair[0])]

    def _load_history(self):
        try:
            data = json.loads(self.history_path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return []
        if not isinstance(data, list):
            return []
        points = []
        for item in data:
            if (isinstance(item, dict) and isinstance(item.get("acceptedBytes"), int)
                    and isinstance(item.get("at"), str) and _parse_ts(item["at"]) is not None):
                points.append({"at": item["at"], "acceptedBytes": item["acceptedBytes"]})
        # Heartbeats are real observations. Do not move their first timestamp
        # by collapsing equal counts on reload, which would shift the boundary.
        if len(points) > HISTORY_MAX_POINTS:
            return points[:1] + points[-(HISTORY_MAX_POINTS - 1):]
        return points

    @staticmethod
    def _history_should_append(history, accepted_bytes, now):
        if not history:
            return True
        last = history[-1]
        if last["acceptedBytes"] != accepted_bytes:
            return True
        last_dt = _parse_ts(last["at"])
        if last_dt is None:
            return True
        return (now - last_dt).total_seconds() >= HISTORY_HEARTBEAT_SECONDS

    def _persist_history(self, history):
        self.history_path.parent.mkdir(parents=True, exist_ok=True)
        tmp = self.history_path.parent / (self.history_path.name + ".tmp")
        tmp.write_text(json.dumps(history, separators=(",", ":")), encoding="utf-8")
        tmp.replace(self.history_path)


def _parse_ts(value):
    try:
        date = datetime.fromisoformat(value.replace("Z", "+00:00"))
        return date if date.tzinfo else date.replace(tzinfo=timezone.utc)
    except ValueError:
        return None
