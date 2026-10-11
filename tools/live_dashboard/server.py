#!/usr/bin/env python3
"""Read-only live dashboard server for the brawl-decomp project.

Serves the static dashboard (index.html / style.css / app.js, allowlisted)
plus a small JSON + SSE API.  All data comes from live project artifacts:

* omp agent session journals (agents, states, events) -- read-only,
  incrementally tailed; prompts, thinking, tool arguments/outputs and
  credentials are never extracted.
* ``build/RSBE01_02/report.json`` progress via the existing
  ``tools/reconstruction_progress.py`` counter (reused, never modified).

The server binds the loopback interface only, performs no filesystem
browsing, never mutates reconstruction files, and persists nothing outside
``build/live-dashboard/`` (gitignored).

Usage:
    python tools/live_dashboard/server.py [--port 8765] [--session-dir DIR]
        [--root DIR] [--report PATH] [--interval SECONDS] [--verbose]

API:
    GET /api/state   full dashboard state snapshot (JSON)
    GET /api/units   per-unit classification map (JSON, revision-tagged)
    GET /api/events  Server-Sent Events: ``state`` snapshots (~2 s cadence)
                     with comment keepalives; clients reconnect and refetch
"""

from __future__ import annotations

import argparse
import json
import sys
import threading
import time
from datetime import datetime, timezone
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from journals import JournalWatcher  # noqa: E402
from progress import ProgressTracker  # noqa: E402

STATIC_FILES = {
    "/": ("index.html", "text/html; charset=utf-8"),
    "/index.html": ("index.html", "text/html; charset=utf-8"),
    "/app.js": ("app.js", "text/javascript; charset=utf-8"),
    "/style.css": ("style.css", "text/css; charset=utf-8"),
}
SSE_KEEPALIVE_SECONDS = 15.0
MAX_WARNINGS = 12


def _utc_now_iso():
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds").replace("+00:00", "Z")


class DashboardState:
    """Thread-safe cache of the latest serialized state + units payloads."""

    def __init__(self):
        self.lock = threading.Lock()
        self.sse = threading.Condition(self.lock)
        self.version = 0
        self.state_bytes = b"{}"
        self.units_bytes = b"{}"

    def publish(self, state_obj, units_bytes):
        payload = json.dumps(state_obj, separators=(",", ":")).encode("utf-8")
        with self.sse:
            self.state_bytes = payload
            if units_bytes is not None:
                self.units_bytes = units_bytes
            self.version += 1
            self.sse.notify_all()

    def snapshot(self):
        with self.lock:
            return self.version, self.state_bytes, self.units_bytes


def refresher_loop(stop, watcher, progress, state, interval, wake_progress):
    while not stop.is_set():
        started = time.monotonic()
        try:
            watcher.poll()
        except Exception as exc:  # noqa: BLE001 - never let the loop die
            watcher.warnings["watcher"] = f"journal scan failed: {exc.__class__.__name__}: {exc}"
        try:
            if progress.poll():
                wake_progress.set()
        except Exception:  # noqa: BLE001
            pass
        agents, events, journal_warnings = watcher.snapshot()
        progress_dict, report_updated_at, revision, history, progress_warnings = (
            progress.state_parts()
        )
        state_obj = {
            "version": 1,
            "updatedAt": _utc_now_iso(),
            "reportUpdatedAt": report_updated_at,
            "session": watcher.session_label(),
            "progress": progress_dict,
            "agents": agents,
            "events": events,
            "history": history,
            "unitsRevision": revision or "pending",
            "warnings": (journal_warnings + progress_warnings)[:MAX_WARNINGS],
        }
        state.publish(state_obj, progress.units_bytes())
        stop.wait(max(0.0, interval - (time.monotonic() - started)))


def progress_loop(stop, progress, wake):
    while not stop.is_set():
        wake.wait(timeout=1.0)
        if stop.is_set():
            break
        wake.clear()
        progress.refresh()  # keeps last-good data on failure


class DashboardHandler(BaseHTTPRequestHandler):
    server_version = "BrawlLiveDashboard/1.0"
    protocol_version = "HTTP/1.1"
    # Injected before serving: {"state", "static_dir", "stop", "verbose"}
    dashboard = None

    def log_message(self, fmt, *args):  # noqa: A003
        if self.dashboard and self.dashboard.get("verbose"):
            super().log_message(fmt, *args)

    # -- helpers -------------------------------------------------------
    def _send_json(self, code, payload, extra_headers=None):
        self.send_response(code)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("Cache-Control", "no-store")
        for key, value in (extra_headers or {}).items():
            self.send_header(key, value)
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(payload)

    def _send_static(self, path):
        name, ctype = STATIC_FILES[path]
        file_path = self.dashboard["static_dir"] / name
        try:
            payload = file_path.read_bytes()
        except OSError:
            self._send_json(404, b'{"error":"not found"}')
            return
        self.send_response(200)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(payload)

    # -- guards --------------------------------------------------------
    def _host_allowed(self):
        """Reject Host headers that do not name this loopback server.

        A DNS-rebinding page reaches 127.0.0.1 with an attacker-controlled
        Host; the allowlist keeps journal-derived API data localhost-only
        without any auth or remote-access infrastructure.
        """
        port = self.server.server_address[1]
        host = (self.headers.get("Host") or "").strip().lower()
        return host in (
            f"127.0.0.1:{port}", "127.0.0.1",
            f"localhost:{port}", "localhost",
        )

    def _origin_allowed(self):
        """Allow API reads only from the dashboard's own origin (when sent)."""
        origin = self.headers.get("Origin")
        if origin is None:
            return True  # direct navigation / non-browser clients
        port = self.server.server_address[1]
        return origin.strip().lower() in (
            f"http://127.0.0.1:{port}", f"http://localhost:{port}",
        )

    # -- routes --------------------------------------------------------
    def do_GET(self):
        if not self._host_allowed():
            self._send_json(403, b'{"error":"forbidden host"}')
            return
        path = self.path.split("?", 1)[0].split("#", 1)[0]
        if path.startswith("/api/") and not self._origin_allowed():
            self._send_json(403, b'{"error":"forbidden origin"}')
            return
        if path == "/api/state":
            _, payload, _ = self.dashboard["state"].snapshot()
            self._send_json(200, payload)
        elif path == "/api/units":
            _, _, payload = self.dashboard["state"].snapshot()
            self._send_json(200, payload)
        elif path == "/api/events":
            self._handle_sse()
        elif path in STATIC_FILES:
            self._send_static(path)
        else:
            # Exact allowlist only: no directory browsing, no path traversal.
            self._send_json(404, b'{"error":"not found"}')

    def do_HEAD(self):
        path = self.path.split("?", 1)[0].split("#", 1)[0]
        if path == "/api/events":
            self._send_json(405, b'{"error":"method not allowed"}', {"Allow": "GET"})
        else:
            self.do_GET()

    def do_POST(self):
        self._send_json(405, b'{"error":"method not allowed"}', {"Allow": "GET, HEAD"})

    # -- SSE -----------------------------------------------------------
    def _handle_sse(self):
        state = self.dashboard["state"]
        self.send_response(200)
        self.send_header("Content-Type", "text/event-stream; charset=utf-8")
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.close_connection = True
        try:
            self.wfile.write(b"retry: 3000\n\n")
            self.wfile.flush()
            version, payload, _ = state.snapshot()
            self._write_state(payload)
            last_version, last_keepalive = version, time.monotonic()
            while not self.dashboard["stop"].is_set():
                with state.sse:
                    state.sse.wait(timeout=2.0)
                version, payload, _ = state.snapshot()
                now = time.monotonic()
                if version != last_version:
                    self._write_state(payload)
                    last_version = version
                    last_keepalive = now
                elif now - last_keepalive >= SSE_KEEPALIVE_SECONDS:
                    self.wfile.write(b": keepalive\n\n")
                    self.wfile.flush()
                    last_keepalive = now
        except (BrokenPipeError, ConnectionResetError, OSError):
            pass  # client disconnected; end this handler thread cleanly

    def _write_state(self, payload):
        self.wfile.write(b"event: state\ndata: " + payload + b"\n\n")
        self.wfile.flush()


def parse_args(argv=None):
    parser = argparse.ArgumentParser(
        description="Read-only live decompilation dashboard server (localhost only).",
        epilog=(
            "Data sources: omp session journals (auto-discovered from the repo cwd,"
            " override with --session-dir) and build/RSBE01_02/report.json via the"
            " existing reconstruction_progress counter. Persisted state lives only"
            " in build/live-dashboard/."
        ),
    )
    parser.add_argument("--port", type=int, default=8765,
                        help="TCP port to listen on (default: 8765)")
    parser.add_argument("--host", default="127.0.0.1",
                        help="bind address; loopback only (default: 127.0.0.1)")
    parser.add_argument("--session-dir", type=Path, default=None, metavar="DIR",
                        help="explicit omp session directory (default: auto-discover"
                             " the session matching the repo cwd under"
                             " ~/.omp/agent/sessions)")
    parser.add_argument("--root", type=Path, default=None, metavar="DIR",
                        help="project root (default: the repository containing"
                             " tools/live_dashboard)")
    parser.add_argument("--report", type=Path, default=None, metavar="PATH",
                        help="objdiff report.json (default: <root>/build/RSBE01_02/report.json)")
    parser.add_argument("--interval", type=float, default=2.0,
                        help="state refresh cadence in seconds (default: 2.0)")
    parser.add_argument("--verbose", action="store_true",
                        help="log HTTP requests to stderr")
    args = parser.parse_args(argv)
    if args.host not in ("127.0.0.1", "localhost"):
        parser.error("--host must be a loopback address; the dashboard never binds a public interface")
    if not 1 <= args.port <= 65535:
        parser.error("--port must be 1-65535")
    if args.interval < 0.5:
        parser.error("--interval must be at least 0.5 seconds")
    return args


def main(argv=None):
    args = parse_args(argv)
    root = (args.root or Path(__file__).resolve().parents[2]).resolve()
    report_path = args.report or (root / "build" / "RSBE01_02" / "report.json")
    history_path = root / "build" / "live-dashboard" / "history.json"
    static_dir = Path(__file__).resolve().parent

    watcher = JournalWatcher(root, session_dir=args.session_dir)
    progress = ProgressTracker(report_path, root, history_path)

    stop = threading.Event()
    wake_progress = threading.Event()
    dashboard = DashboardState()
    DashboardHandler.dashboard = {
        "state": dashboard,
        "static_dir": static_dir,
        "stop": stop,
        "verbose": args.verbose,
    }

    # Publish a valid initializing snapshot so the port serves immediately;
    # the refresher/progress threads replace it on their first ticks.
    progress_dict, report_updated_at, revision, history, progress_warnings = (
        progress.state_parts()
    )
    dashboard.publish({
        "version": 1,
        "updatedAt": _utc_now_iso(),
        "reportUpdatedAt": report_updated_at,
        "session": None,
        "progress": progress_dict,
        "agents": [],
        "events": [],
        "history": history,
        "unitsRevision": revision or "pending",
        "warnings": ["dashboard starting: agent list and progress fill in on the first scan"],
    }, progress.units_bytes())

    server = ThreadingHTTPServer((args.host, args.port), DashboardHandler)
    server.daemon_threads = True

    threads = [
        threading.Thread(target=refresher_loop,
                         args=(stop, watcher, progress, dashboard, args.interval, wake_progress),
                         name="dashboard-refresher", daemon=True),
        threading.Thread(target=progress_loop, args=(stop, progress, wake_progress),
                         name="dashboard-progress", daemon=True),
    ]
    for thread in threads:
        thread.start()

    print(f"live dashboard on http://{args.host}:{args.port} "
          f"(session: {watcher.session_label() or 'not found'})", file=sys.stderr)
    try:
        server.serve_forever(poll_interval=0.5)
    except KeyboardInterrupt:
        pass
    finally:
        stop.set()
        wake_progress.set()
        server.server_close()


if __name__ == "__main__":
    main()
