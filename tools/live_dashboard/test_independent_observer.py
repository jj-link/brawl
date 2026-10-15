"""Independent observer registration/routing without sockets or journal polling."""

import io
import json
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

import journals as j
import server as s


ROOT = "00000000-0000-4000-8000-000000000001"
PEER = "00000000-0000-4000-8000-000000000002"
OTHER = "00000000-0000-4000-8000-000000000003"
PORT = 18766


def registration(**extra):
    return {"id": PEER, "label": "Independent Sol", "observerPort": PORT, **extra}


def frame(event, payload):
    return f"event: {event}\ndata: {json.dumps(payload)}\n\n".encode()


class IndependentObserverTests(unittest.TestCase):
    def watcher(self, entry=None):
        watcher = j.JournalWatcher(".")
        watcher.parent_session_id = ROOT
        peer = Path("sessions/peer.jsonl")
        entry = registration() if entry is None else entry
        config = json.dumps({"sessions": [entry]})
        info = {"id": PEER, "cwd": "."}
        config_patch = patch.object(j.Path, "read_text", return_value=config)
        header_patch = patch.object(watcher, "_peek", return_value=info)
        config_patch.start()
        header_patch.start()
        self.addCleanup(config_patch.stop)
        self.addCleanup(header_patch.stop)
        watcher._registered_roots([peer], [])
        tracker = j.JournalTracker(peer, "main", True)
        tracker.apply({"type": "session", "id": PEER, "timestamp": "2026-10-14T00:00:00Z"})
        watcher.trackers[peer] = tracker
        return watcher

    def test_live_registration_metadata_and_friendly_label(self):
        watcher = self.watcher()
        self.assertEqual(watcher.independent_observer(PEER)["observerPort"], PORT)
        agent = watcher.snapshot()[0][0]
        self.assertEqual(agent["name"], "Independent Sol")
        self.assertEqual(agent["streamSource"], "live-observer")
        self.assertEqual(agent["rootSessionId"], PEER)
        self.assertNotIn("active", agent)  # No inheritance from the owning registry.

    def test_legacy_registration_remains_history_and_cannot_route(self):
        watcher = self.watcher({"id": PEER, "label": "Recorded peer"})
        self.assertEqual(watcher.snapshot()[0][0]["streamSource"], "recorded-history")
        with self.assertRaises(s.ObserverRouteError):
            s._observer_route(watcher, PEER)

    def test_ports_are_explicit_integers_unique_and_not_reserved(self):
        for port in (True, None, "18766", "http://example.invalid", 0, 65536, 8765, 8766):
            with self.subTest(port=port), patch.object(j.Path, "read_text", return_value=json.dumps({
                    "sessions": [registration(observerPort=port)]})):
                with self.assertRaises(ValueError):
                    j.load_independent_roots(Path("config.json"))
        with patch.object(j.Path, "read_text", return_value=json.dumps({"sessions": [
                registration(), registration(id=OTHER)]})):
            with self.assertRaises(ValueError):
                j.load_independent_roots(Path("config.json"))

    def test_routing_uses_only_registered_loopback_and_preserves_default(self):
        watcher = self.watcher()
        self.assertEqual(s._observer_route(watcher)["url"], s.OBSERVER_URL)
        self.assertEqual(s._observer_route(watcher, PEER)["url"], f"http://127.0.0.1:{PORT}")
        for root in (ROOT, OTHER, "", "http://example.invalid", "../sessions"):
            with self.subTest(root=root), self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, root)

    def test_status_checks_actual_root_before_returning(self):
        watcher = self.watcher()
        with patch.object(s, "urlopen", return_value=io.BytesIO(json.dumps({
                "rootSessionId": PEER, "connected": True}).encode())) as upstream:
            self.assertTrue(s.observer_status(watcher, PEER)["connected"])
            upstream.assert_called_once_with(f"http://127.0.0.1:{PORT}/status", timeout=2)
        with patch.object(s, "urlopen", return_value=io.BytesIO(json.dumps({
                "rootSessionId": ROOT}).encode())):
            with self.assertRaises(ValueError):
                s.observer_status(watcher, PEER)

    def test_snapshot_and_membership_mismatch_fail_closed(self):
        watcher = self.watcher()
        for kind in ("snapshot", "membership"):
            with self.subTest(kind=kind), self.assertRaises(ValueError):
                s._observer_frame(io.BytesIO(frame(kind, {"rootSessionId": ROOT})), watcher, PEER)
        route = s._observer_route(watcher, PEER)
        upstream = io.BytesIO(frame("snapshot", {"rootSessionId": PEER, "agents": [{"id": PEER, "name": "main"}]}))
        kind, encoded = s._observer_frame(upstream, watcher, PEER, route)
        self.assertEqual(kind, b"snapshot")
        payload = json.loads(encoded.split(b"data: ")[1])
        self.assertEqual(payload["agents"][0]["name"], "Independent Sol")
        self.assertEqual(payload["agents"][0]["scope"], "independent-root")
        with self.assertRaises(ValueError):
            s._observer_frame(io.BytesIO(frame("membership", {"rootSessionId": OTHER})), watcher, PEER, route)

    def test_default_feed_remains_pinned_to_owning_root(self):
        watcher = self.watcher()
        original = frame("snapshot", {"rootSessionId": ROOT, "agents": []})
        self.assertEqual(s._observer_frame(io.BytesIO(original), watcher),
                         (b"snapshot", original))
        with self.assertRaises(ValueError):
            s._observer_frame(io.BytesIO(frame("membership", {"rootSessionId": PEER})), watcher)

    def test_revocation_or_port_change_stops_even_unrooted_delta(self):
        watcher = self.watcher()
        route = s._observer_route(watcher, PEER)
        for entries in ([], [registration(observerPort=18767)]):
            with self.subTest(entries=entries), patch.object(j.Path, "read_text", return_value=json.dumps({"sessions": entries})):
                with self.assertRaises(ValueError):
                    s._observer_frame(io.BytesIO(frame("text", {"agentId": PEER, "text": "delta"})), watcher, PEER, route)

    def test_rewritten_foreign_journal_cannot_route(self):
        watcher = self.watcher()
        with patch.object(watcher, "_peek", return_value={"id": PEER, "cwd": "other-project"}):
            with self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, PEER)
        with patch.object(watcher, "_peek", return_value={"id": OTHER, "cwd": "."}):
            with self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, PEER)
        with patch.object(watcher, "_peek", return_value={
                "id": PEER, "cwd": ".", "parentSession": ROOT}):
            with self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, PEER)


    def test_unregistered_request_rejected_before_any_upstream_connection(self):
        watcher = self.watcher()
        handler = object.__new__(s.DashboardHandler)
        handler.path = f"/api/live?root={OTHER}"
        handler.dashboard = {"watcher": watcher}
        responses = []
        handler._send_json = lambda *args: responses.append(args)
        with patch.object(s, "urlopen") as upstream:
            handler._handle_live()
            upstream.assert_not_called()
        self.assertEqual(responses[0][0], 400)

    def test_blank_and_multiple_root_queries_do_not_select_default(self):
        handler = object.__new__(s.DashboardHandler)
        for query in ("root=", f"root={PEER}&root={ROOT}"):
            handler.path = "/api/live?" + query
            with self.subTest(query=query), self.assertRaises(s.ObserverRouteError):
                handler._observer_root()

    def test_automatic_owner_excludes_newer_registered_peer_and_keeps_primary_family(self):
        primary = Path("sessions/primary.jsonl")
        child = Path("sessions/primary/child.jsonl")
        peer = Path("sessions/peer.jsonl")
        peer_child = Path("sessions/peer/child.jsonl")
        child_id = "00000000-0000-4000-8000-000000000004"
        headers = {
            primary: {"id": ROOT, "cwd": "."},
            child: {"id": child_id, "cwd": ".", "parentSession": ROOT},
            peer: {"id": PEER, "cwd": "."},
            peer_child: {"id": OTHER, "cwd": ".", "parentSession": PEER},
        }
        mtimes = {primary: 10, child: 20, peer: 100, peer_child: 110}
        for registered in (registration(), {"id": PEER, "label": "Recorded independent"}):
            with self.subTest(registration=registered):
                watcher = j.JournalWatcher(".")
                with patch.object(watcher, "_bases", return_value=[Path("sessions")]), \
                        patch.object(watcher, "_candidates", return_value=list(headers)), \
                        patch.object(watcher, "_peek", side_effect=headers.get), \
                        patch.object(j.Path, "is_dir", return_value=False), \
                        patch.object(j.Path, "stat", autospec=True, side_effect=lambda path, **_:
                                     SimpleNamespace(st_mtime_ns=mtimes[path])), \
                        patch.object(j.Path, "read_text", return_value=json.dumps({"sessions": [registered]})):
                    discovered = watcher._discover()
                    self.assertEqual(watcher.parent_path, primary)
                    self.assertEqual(watcher.session_label(), ROOT)
                    self.assertEqual(discovered[:2], [primary, child])
                    self.assertEqual(set(discovered), {primary, child, peer})
                    self.assertNotIn(peer_child, discovered)
                    self.assertEqual(watcher.independent_roots, {peer: registered["label"]})
                    self.assertEqual(watcher._discover()[:2], [primary, child])

    def test_custom_registration_config_rejects_live_ports_without_advertising_feed(self):
        watcher = j.JournalWatcher(
            ".", independent_roots="build/live-dashboard/custom-independent-roots.json")
        peer = Path("sessions/peer.jsonl")
        with patch.object(watcher, "_peek", return_value={"id": PEER, "cwd": "."}), \
                patch.object(j.Path, "read_text", return_value=json.dumps({"sessions": [registration()]})):
            discovered = watcher._registered_roots([peer], [])
            self.assertEqual(discovered, [])
            self.assertEqual(watcher.independent_observers, {})
            warning = watcher.warnings.get("independent-roots", "")
            self.assertIn("observerPort", warning)
            self.assertIn("project", warning.lower())
            with self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, PEER)
            self.assertFalse(any(agent.get("streamSource") == "live-observer"
                                 for agent in watcher.snapshot()[0]))

    def test_custom_registration_config_keeps_recorded_only_support(self):
        watcher = j.JournalWatcher(
            ".", independent_roots="build/live-dashboard/custom-independent-roots.json")
        peer = Path("sessions/peer.jsonl")
        recorded = {"id": PEER, "label": "Recorded independent"}
        with patch.object(watcher, "_peek", return_value={"id": PEER, "cwd": "."}), \
                patch.object(j.Path, "read_text", return_value=json.dumps({"sessions": [recorded]})):
            self.assertEqual(watcher._registered_roots([peer], []), [peer])
            self.assertEqual(watcher.independent_roots, {peer: recorded["label"]})
            self.assertEqual(watcher.independent_observers, {})
            with self.assertRaises(s.ObserverRouteError):
                s._observer_route(watcher, PEER)


if __name__ == "__main__":
    unittest.main()
