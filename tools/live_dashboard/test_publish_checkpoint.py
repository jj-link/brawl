"""Consumer-visible checkpoint tests with retained real Git/HTTP fixtures.

Run once with: python -m unittest discover -s tools/live_dashboard -p test_publish_checkpoint.py -v
Fixtures remain under build/checkpoint-publication-tests; no temporary directory,
real dashboard/service modification, compiler invocation or evidence cleanup.
The tiny ELF files are explicit test fixtures, not claimed production builds.
"""

import argparse
import json
import os
import struct
import subprocess
import sys
import threading
import unittest
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from uuid import uuid4

import publish_checkpoint as publisher
from progress import ProgressTracker


ROOT = Path(__file__).resolve().parents[2]


def write(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(content if isinstance(content, bytes) else content.encode("utf-8"))


def tiny_elf(definitions, instruction=b"\x4e\x80\x00\x20"):
    """A real ELF32/PPC fixture with .text and defined global function symbols."""
    names = b"\0" + b"\0".join(name.encode() for name, _ in definitions) + b"\0"
    shnames = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    symbols = bytes(16)
    for name, value in definitions:
        symbols += struct.pack(">IIIBBH", names.index(name.encode() + b"\0"), value, 4, 0x12, 0, 1)
    payloads = [instruction * len(definitions), symbols, names, shnames]
    data = bytearray(bytes(52))
    offsets = []
    for payload in payloads:
        while len(data) % 4:
            data.append(0)
        offsets.append(len(data))
        data.extend(payload)
    while len(data) % 4:
        data.append(0)
    shoff = len(data)
    data.extend(bytes(40))
    for i, (name, kind, flags, link, info, alignment, stride) in enumerate([
        (".text", 1, 6, 0, 0, 4, 0), (".symtab", 2, 0, 3, 1, 4, 16),
        (".strtab", 3, 0, 0, 0, 1, 0), (".shstrtab", 3, 0, 0, 0, 1, 0)]):
        data.extend(struct.pack(">IIIIIIIIII", shnames.index(name.encode() + b"\0"), kind, flags, 0,
                                offsets[i], len(payloads[i]), link, info, alignment, stride))
    data[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    struct.pack_into(">HHIIIIIHHHHHH", data, 16, 1, 20, 1, 0, 0, shoff, 0, 52, 0, 0, 40, 5, 4)
    return bytes(data)


def checkpoint(source, accepted, units, report_hash):
    return (f"## Committed-source checkpoint {source[:8]}\n\n"
            f"- Verified committed snapshot `{source}`; report SHA-256 `{report_hash}`.\n"
            f"- **{100 * accepted / 20:.6f}%**: **{accepted} / 20 accepted code bytes**, "
            f"**{20 - accepted} code bytes remaining**, **{units} accepted source units**.\n\n")


class Fixture:
    def __init__(self):
        self.base = ROOT / "build/checkpoint-publication-tests" / uuid4().hex
        self.root = self.base / "checkout"
        self.build = self.base / "verified-build"
        self.evidence = self.base / "integration-evidence"
        self.receipts = self.base / "receipts"
        self.root.mkdir(parents=True)
        publisher.git(self.root, "init", "--bare", str(self.base / "origin.git"))
        publisher.git(self.root, "init", "-b", "main")
        publisher.git(self.root, "config", "user.name", "Checkpoint fixture")
        publisher.git(self.root, "config", "user.email", "checkpoint@example.invalid")
        publisher.git(self.root, "config", "core.autocrlf", "false")
        publisher.git(self.root, "remote", "add", "origin", str(self.base / "origin.git"))
        sources = {"src/old.cpp": "void fn_old() {}\n", "src/new.cpp": "void fn_new() {}\n",
                   "src/draft.cpp": "void fn_draft() {}\n", "src/unit.s": "blr\n",
                   "src/inline.cpp": "void fn_inline() { asm { blr } }\n",
                   "configure.py": "MATCH_NEW = False\n", "user.txt": "original\r\n",
                   ".gitignore": "build/\n", "CHANGELOG.md": "# Changelog\n\n"}
        hashes = []
        for i in range(127):
            name = "build/RSBE01_02/main.dol" if not i else f"build/RSBE01_02/m{i:03}/m{i:03}.rel"
            raw = f"retained original fixture binary {i}\n".encode()
            write(self.build / name, raw)
            hashes.append(f"{publisher.digest(raw, 'sha1')}  {name}\n")
        sources["config/RSBE01_02/build.sha1"] = "".join(hashes)
        sources["config/RSBE01_02/rels/test/splits.txt"] = "Sections:\n\t.text type:code align:4\n\nold.cpp:\n\t.text start:4 end:8\n\nnew.cpp:\n\t.text start:8 end:12\n"
        for name, text in sources.items():
            write(self.root / name, text)
        publisher.git(self.root, "add", ".")
        publisher.git(self.root, "commit", "-m", "Fixture source baseline")
        self.previous = publisher.git(self.root, "rev-parse", "HEAD").decode().strip()
        self.report = self.make_report(True)
        old_report = self.make_report(False)
        write(self.root / "CHANGELOG.md", "# Changelog\n\n" + checkpoint(self.previous, 4, 1, "0" * 64))
        publisher.git(self.root, "add", "CHANGELOG.md")
        publisher.git(self.root, "commit", "-m", "Fixture previous checkpoint")
        write(self.root / "configure.py", "MATCH_NEW = True\n")
        publisher.git(self.root, "add", "configure.py")
        publisher.git(self.root, "commit", "-m", "Fixture newly matching source")
        publisher.git(self.root, "push", "origin", "HEAD:main")
        self.source = publisher.git(self.root, "rev-parse", "HEAD").decode().strip()
        write(self.root / "user.txt", b"preserve unrelated user bytes\r\n")
        self.unrelated = (self.root / "user.txt").read_bytes()
        registrations, linked, prefix = [], [], []
        for name in ("old", "new", "draft", "unit", "inline"):
            base = f"build/RSBE01_02/src/{name}.o"
            target = f"build/RSBE01_02/obj/{name}.o"
            raw = tiny_elf([(f"fn_{name}", 0)])
            write(self.build / base, raw)
            write(self.build / target, raw)
            registrations.append({"name": f"main/{name}", "base_path": base, "target_path": target})
            linked.append(target if name == "draft" else base)
            if name == "old":
                prefix.append({"unit": "main/old", "source_path": "src/old.cpp", "source_object": base,
                               "source_sha256": publisher.digest((self.root / "src/old.cpp").read_bytes()),
                               "source_object_sha256": publisher.digest(raw)})
        graph = "build build/RSBE01_02/main.elf: link " + " ".join(linked) + "\n"
        write(self.build / "build.ninja", graph)
        write(self.evidence / "actual-native-source-link-inputs.txt", graph)
        write(self.build / "build/RSBE01_02/main.elf", tiny_elf([("fn_old", 4), ("fn_new", 8)]))
        write(self.build / "objdiff.json", publisher.encode({"units": registrations}))
        manifest = {}
        for name in sources:
            if name in ("user.txt", ".gitignore", "CHANGELOG.md"):
                continue
            raw = (self.root / name).read_bytes()
            if name == "src/new.cpp":
                raw = raw.replace(b"\n", b"\r\n")
            if name.endswith("splits.txt"):
                raw = b"Sections:\n\t.text type:code align:4\n\nnew.cpp:\n\t.text start:8 end:12\n\nold.cpp:\n\t.text start:4 end:8\n"
            write(self.build / name, raw)
            manifest[name] = publisher.digest(raw)
        write(self.evidence / "complete-materialized-inputs.json", publisher.encode(manifest))
        executable = Path(sys.executable).read_bytes()
        write(self.evidence / "native-tool-identities.json", publisher.encode({sys.executable: {
            "sha256": publisher.digest(executable), "bytes": len(executable)}}))
        report_bytes = publisher.encode(self.report)
        write(self.evidence / "final-report.json", report_bytes)
        write(self.evidence / "source-published.json", publisher.encode({"commit": self.source, "report_sha256": publisher.digest(report_bytes)}))
        tracker = ProgressTracker(self.evidence / "final-report.json", self.root, self.base / "not-created-history.json")
        write(self.evidence / "source-progress-tool-output.json", publisher.encode(tracker._counter.calculate(self.report, self.root)))
        write(self.evidence / "previous-accepted-source-object-identities.json", publisher.encode(prefix))
        write(self.root / "build/RSBE01_02/report.json", publisher.encode(old_report))
        write(self.root / "build/live-dashboard/history.json", publisher.encode([{"at": "2020-01-01T00:00:00Z", "acceptedBytes": 4}]))
        self.tracker = ProgressTracker(self.root / "build/RSBE01_02/report.json", self.root,
                                       self.root / "build/live-dashboard/history.json")
        self.response_mutation = None
        fixture = self

        class Handler(BaseHTTPRequestHandler):
            def do_GET(self):
                with fixture.http_lock:
                    fixture.tracker.refresh()
                    p, updated, revision, history, warnings = fixture.tracker.state_parts()
                    value = {"session": "fixture-session", "progress": p, "history": history,
                             "warnings": warnings, "reportUpdatedAt": updated,
                             "unitsProvenance": fixture.tracker.units_provenance()}
                    if self.path == "/api/units":
                        value = json.loads(fixture.tracker.units_bytes())
                    if fixture.response_mutation:
                        value = fixture.response_mutation(self.path, value)
                payload = publisher.encode(value)
                self.send_response(200)
                self.send_header("Content-Type", "application/json")
                self.send_header("Content-Length", str(len(payload)))
                self.end_headers()
                self.wfile.write(payload)

            def log_message(self, *_args):
                pass

        self.http_lock = threading.Lock()
        self.servers = [ThreadingHTTPServer(("127.0.0.1", 0), Handler) for _ in range(2)]
        for server in self.servers:
            threading.Thread(target=server.serve_forever, daemon=True).start()

    @staticmethod
    def make_report(complete):
        units = []
        for name, suffix, done in [("old", "cpp", True), ("new", "cpp", complete),
                                   ("draft", "cpp", False), ("unit", "s", True), ("inline", "cpp", True)]:
            units.append({"name": f"main/{name}", "metadata": {"source_path": f"src/{name}.{suffix}",
                "complete": done, "module_name": "main"}, "measures": {"total_code": "4", "matched_code_percent": 100},
                "functions": [{"name": f"fn_{name}", "size": "4", "metadata": {"virtual_address": "4" if name == "old" else "8"}}]})
        units += [{"name": f"m{i:03}/auto", "metadata": {"source_path": None, "module_name": f"m{i:03}", "complete": False},
                   "measures": {"total_code": "0"}} for i in range(1, 127)]
        return {"measures": {"total_code": "20"}, "units": units}

    def change_prior_source_without_compiling(self, raw):
        before = (self.root / "src/old.cpp").read_bytes()
        write(self.root / "src/old.cpp", raw)
        write(self.build / "src/old.cpp", raw)
        manifest = publisher.load(self.evidence / "complete-materialized-inputs.json")
        manifest["src/old.cpp"] = publisher.digest(raw)
        write(self.evidence / "complete-materialized-inputs.json", publisher.encode(manifest))
        publisher.git(self.root, "add", "src/old.cpp")
        publisher.git(self.root, "commit", "-m", "Fixture changed prior source with retained stale object")
        publisher.git(self.root, "push", "origin", "HEAD:main")
        self.source = publisher.git(self.root, "rev-parse", "HEAD").decode().strip()
        receipt = publisher.load(self.evidence / "source-published.json")
        receipt["commit"] = self.source
        write(self.evidence / "source-published.json", publisher.encode(receipt))
        return before

    def args(self):
        state = publisher.guard(self.root)
        return argparse.Namespace(root=self.root, source=self.source, integration_root=self.build,
            evidence=self.evidence, receipts=self.receipts, session="fixture-session",
            public_url=f"http://127.0.0.1:{self.servers[1].server_port}",
            local_url=f"http://127.0.0.1:{self.servers[0].server_port}",
            history=self.root / "build/live-dashboard/history.json", publish=True,
            expected_head=state["head"], expected_index_sha256=state["index_sha256"], timeout=5)

    def close(self):
        for server in self.servers:
            server.shutdown()
            server.server_close()


class CheckpointPublicationTests(unittest.TestCase):
    def setUp(self):
        self.f = Fixture()
        self.addCleanup(self.f.close)

    def preimages(self):
        return {name: (self.f.root / name).read_bytes() for name in (
            "CHANGELOG.md", "build/RSBE01_02/report.json", "user.txt")}

    def expect_preflight_failure(self, args, message):
        before = self.preimages()
        head = publisher.git(self.f.root, "rev-parse", "HEAD")
        with self.assertRaisesRegex(publisher.PublicationError, message):
            publisher.run(args)
        self.assertEqual(before, self.preimages())
        self.assertEqual(head, publisher.git(self.f.root, "rev-parse", "HEAD"))
        self.assertFalse((self.f.receipts / "last-verified.json").exists())

    def test_real_git_http_publication_duplicate_and_frozen_reuse(self):
        result = publisher.run(self.f.args())
        self.assertFalse(result["duplicate"])
        self.assertEqual(result["metrics"]["accepted_source_code_bytes"], 8)
        self.assertEqual(result["metrics"]["accepted_source_units"], 2)
        self.assertEqual(result["native_artifacts"], 127)
        self.assertEqual(result["endpoints"]["public"]["module_count"], 127)
        self.assertEqual((self.f.root / "user.txt").read_bytes(), self.f.unrelated)
        before = publisher.git(self.f.root, "rev-parse", "HEAD")
        self.assertEqual(publisher.git(self.f.root, "diff-tree", "--no-commit-id", "--name-only", "-r", "HEAD").decode().strip(), "CHANGELOG.md")
        # Mutable future private work must not replace the frozen checkpoint.
        write(self.f.build / "src/new.cpp", "future unverified source\n")
        args = self.f.args()
        args.publish = False
        duplicate = publisher.run(args)
        self.assertTrue(duplicate["duplicate"])
        self.assertEqual(before, publisher.git(self.f.root, "rev-parse", "HEAD"))
        mapping = publisher.load(self.f.receipts / self.f.source / "expected-unit-map.json")
        self.assertTrue(next(u for u in mapping if u["id"] == "main/new")["accepted"])
        for name in ("draft", "unit", "inline"):
            self.assertFalse(next(u for u in mapping if u["id"] == "main/" + name)["accepted"])

    def test_wrong_full_source_commit_does_not_publish(self):
        args = self.f.args()
        args.source = self.f.previous
        self.expect_preflight_failure(args, "different full source commit")

    def test_changed_compiled_input_does_not_publish(self):
        write(self.f.build / "src/new.cpp", "unverified source\n")
        self.expect_preflight_failure(self.f.args(), "compiled input hash mismatch")

    def test_self_consistent_wrong_input_still_fails_committed_binding(self):
        raw = b"void unverified_body() {}\n"
        write(self.f.build / "src/new.cpp", raw)
        manifest = publisher.load(self.f.evidence / "complete-materialized-inputs.json")
        manifest["src/new.cpp"] = publisher.digest(raw)
        write(self.f.evidence / "complete-materialized-inputs.json", publisher.encode(manifest))
        self.expect_preflight_failure(self.f.args(), "unbound committed compiler input")

    def test_wrong_dashboard_root_is_not_verified(self):
        def wrong_root(route, value):
            if route == "/api/state":
                value["session"] = "another-real-session"
            return value
        self.f.response_mutation = wrong_root
        with self.assertRaisesRegex(publisher.PublicationError, "dashboard root/session mismatch"):
            publisher.run(self.f.args())
        self.assertFalse((self.f.receipts / "last-verified.json").exists())

    def test_single_unit_classification_mismatch_is_not_verified(self):
        def wrong_unit(route, value):
            if route == "/api/units":
                next(u for u in value["units"] if u["id"] == "main/draft")["accepted"] = True
            return value
        self.f.response_mutation = wrong_unit
        with self.assertRaisesRegex(publisher.PublicationError, "complete unit/module classifications differ"):
            publisher.run(self.f.args())
        self.assertFalse((self.f.receipts / "last-verified.json").exists())

    def test_changed_report_hash_does_not_publish(self):
        write(self.f.evidence / "final-report.json", b"{}")
        self.expect_preflight_failure(self.f.args(), "saved report hash differs")

    def test_wrong_native_hash_does_not_publish(self):
        write(self.f.build / "build/RSBE01_02/main.dol", b"wrong binary")
        self.expect_preflight_failure(self.f.args(), "native final hash mismatch")

    def test_wrong_index_guard_does_not_publish(self):
        args = self.f.args()
        args.expected_index_sha256 = "0" * 64
        self.expect_preflight_failure(args, "index hash guard conflict")

    def test_duplicate_write_mode_still_requires_explicit_window_guards(self):
        publisher.run(self.f.args())
        head = publisher.git(self.f.root, "rev-parse", "HEAD")
        before = self.preimages()
        args = self.f.args()
        args.expected_head = args.expected_index_sha256 = None
        with self.assertRaisesRegex(publisher.PublicationError, "including duplicate pushes"):
            publisher.run(args)
        self.assertEqual(before, self.preimages())
        self.assertEqual(head, publisher.git(self.f.root, "rev-parse", "HEAD"))

    def test_wrong_actual_linked_symbol_address_is_not_accepted(self):
        write(self.f.build / "build/RSBE01_02/main.elf", tiny_elf([("fn_old", 4), ("fn_new", 12)]))
        self.expect_preflight_failure(self.f.args(), "final linked symbol identity differs: fn_new")

    def test_changed_prior_source_cannot_reuse_stale_object_without_bound_exception(self):
        self.f.change_prior_source_without_compiling(
            b"extern void uncompiled_call();\nvoid fn_old() { uncompiled_call(); }\n")
        self.expect_preflight_failure(self.f.args(), "prior accepted source binding changed")

    def test_missing_prior_accepted_unit_cannot_disappear(self):
        report = publisher.load(self.f.evidence / "final-report.json")
        report["units"] = [u for u in report["units"] if u["name"] != "main/old"]
        raw = publisher.encode(report)
        write(self.f.evidence / "final-report.json", raw)
        receipt = publisher.load(self.f.evidence / "source-published.json")
        receipt["report_sha256"] = publisher.digest(raw)
        write(self.f.evidence / "source-published.json", publisher.encode(receipt))
        metrics = self.f.tracker._counter.calculate(report, self.f.root)
        write(self.f.evidence / "source-progress-tool-output.json", publisher.encode(metrics))
        self.expect_preflight_failure(self.f.args(), "previous accepted unit missing")

    def test_input_bound_interface_exception_preserves_prior_object(self):
        post = b"extern void unused_helper(void*);\nvoid fn_old() {}\n"
        pre = self.f.change_prior_source_without_compiling(post)
        base = "build/RSBE01_02/src/old.o"
        record = {"unit": "main/old", "source_path": "src/old.cpp", "source_object": base,
                  "preimage": "prefix/pre.cpp", "postimage": "prefix/post.cpp",
                  "compiled_object": "prefix/measured.o", "compiled_inputs": "complete-materialized-inputs.json"}
        write(self.f.evidence / record["preimage"], pre)
        write(self.f.evidence / record["postimage"], post)
        write(self.f.evidence / record["compiled_object"], (self.f.build / base).read_bytes())
        write(self.f.evidence / "accepted-prefix-exceptions.json", publisher.encode([record]))
        result = publisher.run(self.f.args())
        self.assertEqual(result["metrics"]["accepted_source_units"], 2)
        proof = publisher.load(self.f.receipts / self.f.source / "source-provenance-link-proof.json")
        self.assertIn("complete inputs bound", next(row for row in proof if row["unit"] == "main/old")["prior_source_binding"])

    def test_prior_source_object_path_identity_cannot_change(self):
        rows = publisher.load(self.f.evidence / "previous-accepted-source-object-identities.json")
        rows[0]["source_object"] = "build/RSBE01_02/src/not-the-prior-object.o"
        write(self.f.evidence / "previous-accepted-source-object-identities.json", publisher.encode(rows))
        self.expect_preflight_failure(self.f.args(), "source/object path identity changed")

    def test_unrelated_staged_bytes_are_not_committed(self):
        args = self.f.args()
        publisher.git(self.f.root, "add", "user.txt")
        self.expect_preflight_failure(args, "index contains staged paths")
        self.assertEqual(publisher.git(self.f.root, "diff", "--cached", "--name-only").decode().strip(), "user.txt")

    def test_substring_is_not_a_native_link_edge(self):
        graph = (self.f.build / "build.ninja").read_text(encoding="utf-8").replace("src/new.o", "src/new.o.evil")
        write(self.f.build / "build.ninja", graph)
        write(self.f.evidence / "actual-native-source-link-inputs.txt", graph)
        self.expect_preflight_failure(self.f.args(), "not exclusively linked")

    def test_changed_allocated_object_is_not_accepted(self):
        write(self.f.build / "build/RSBE01_02/src/new.o", tiny_elf([("fn_new", 0)], b"\x60\x00\x00\x00"))
        self.expect_preflight_failure(self.f.args(), "allocated bytes/relocations differ")

    def test_http_wrong_source_keeps_verified_receipt_and_resumes_without_extra_commit(self):
        sentinel = {"source_commit": "prior-verified-checkpoint"}
        write(self.f.receipts / "last-verified.json", publisher.encode(sentinel))
        def wrong_source(route, value):
            if route == "/api/state":
                value["progress"]["commit"] = "f" * 40
            return value
        self.f.response_mutation = wrong_source
        with self.assertRaisesRegex(publisher.PublicationError, "full-source/headline mismatch"):
            publisher.run(self.f.args())
        self.assertEqual(publisher.load(self.f.receipts / "last-verified.json"), sentinel)
        committed = publisher.git(self.f.root, "rev-parse", "HEAD")
        self.f.response_mutation = None
        resumed = publisher.run(self.f.args())
        self.assertTrue(resumed["duplicate"])
        self.assertEqual(publisher.git(self.f.root, "rev-parse", "HEAD"), committed)
        self.assertEqual(publisher.load(self.f.receipts / "last-verified.json")["source_commit"], self.f.source)

    def test_corrupted_persisted_history_is_not_success(self):
        def corrupt_history(route, value):
            if route == "/api/state":
                write(self.f.root / "build/live-dashboard/history.json", publisher.encode([{"at": "2020-01-01T00:00:00Z", "acceptedBytes": 999}]))
            return value
        self.f.response_mutation = corrupt_history
        with self.assertRaisesRegex(publisher.PublicationError, "served/persisted history mismatch"):
            publisher.run(self.f.args())
        self.assertFalse((self.f.receipts / "last-verified.json").exists())

    def test_precommit_failure_restores_owned_report_changelog_and_index(self):
        before = self.preimages()
        index = self.f.root / ".git/index"
        oldindex = index.read_bytes()
        # A real failing Git hook, not a patched publisher function.
        hook = self.f.root / ".git/hooks/pre-commit"
        write(hook, "#!/bin/sh\nexit 1\n")
        hook.chmod(0o755)
        with self.assertRaisesRegex(publisher.PublicationError, "git commit"):
            publisher.run(self.f.args())
        self.assertEqual(before, self.preimages())
        self.assertEqual(index.read_bytes(), oldindex)
        self.assertFalse((self.f.receipts / "last-verified.json").exists())


if __name__ == "__main__":
    unittest.main()
