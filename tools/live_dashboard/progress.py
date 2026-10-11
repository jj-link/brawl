"""Progress computation for the live dashboard.

Reuses ``tools/reconstruction_progress.py`` (read-only import; the counter
module is never modified) as the accepted-source gate, and replicates its
per-unit rule -- complete C/C++ source without inline assembly -- for the
per-unit map.  Report refreshes are fingerprint-gated (mtime + size) so the
~4.5k source files are only rescanned when the report actually changes, and
any failure keeps the last-good snapshot instead of faking zeros.
"""

from __future__ import annotations

import hashlib
import importlib.util
import json
import threading
from datetime import datetime, timezone
from pathlib import Path

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

    def poll(self):
        """True when the report inputs changed since the last recompute."""
        fp = self.fingerprint()
        return fp is not None and fp != self._fingerprint

    def refresh(self):
        """Recompute only when report inputs changed; keep last-good on failure.

        Called every loop tick, so it is deliberately cheap when the
        fingerprint is unchanged (a single stat) and memoizes persistent
        failures per fingerprint instead of rescanning sources each second.
        """
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
            return (
                dict(self._progress),
                self._report_updated_at,
                self._revision,
                list(self._history[-HISTORY_SERVE_POINTS:]),
                list(self._warnings.values()),
            )

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
            "percent": round(float(result["percent_complete"]), 4),
            "acceptedUnits": int(result["accepted_source_units"]),
            "error": None,
        }

        now = datetime.now(timezone.utc)
        history = list(self._history)
        if self._history_should_append(history, progress["acceptedBytes"], now):
            history.append({
                "at": now.isoformat(timespec="milliseconds").replace("+00:00", "Z"),
                "acceptedBytes": progress["acceptedBytes"],
            })
            del history[:-HISTORY_MAX_POINTS]
            self._persist_history(history)

        payload = json.dumps(
            {"revision": revision, "units": units}, separators=(",", ":")
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
            self._progress = progress
            self._report_updated_at = report_updated_iso
            self._revision = revision
            self._units_payload = payload
            self._history = history
            self._warnings = warnings

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
            if self._progress.get("available"):
                # Keep last-good numbers; the warning explains the staleness.
                self._warnings["report"] = message
            else:
                self._progress = dict(INITIAL_PROGRESS, error=message)
                self._warnings["report"] = message

    # ------------------------------------------------------------------
    # history (observed snapshots only; persisted under build/live-dashboard)
    # ------------------------------------------------------------------
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
                    and isinstance(item.get("at"), str)):
                points.append({"at": item["at"], "acceptedBytes": item["acceptedBytes"]})
        # Collapse consecutive duplicates so reloads do not invent flat runs.
        deduped = []
        for point in points:
            if deduped and deduped[-1]["acceptedBytes"] == point["acceptedBytes"]:
                deduped[-1] = point
            else:
                deduped.append(point)
        return deduped[-HISTORY_MAX_POINTS:]

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
        return datetime.fromisoformat(value.replace("Z", "+00:00"))
    except ValueError:
        return None
