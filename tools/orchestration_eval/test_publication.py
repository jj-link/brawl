"""Real local Git regression exercises; all fixtures and evidence are retained."""
from __future__ import annotations

import json
import unittest
import uuid
from pathlib import Path
from unittest.mock import patch

from . import publication as publication_module

from .evidence import InputError, capture_inputs, file_identity
from .policy import PolicyError
from .publication import (EVALUATION_DATA, WORKTREE, Fixture, FixtureScope, GitPublisher,
                          InjectedCrash, PublicationError, PublicationRequest,
                          _git, _text, initialize_fixture, prepare_publication,
                          validate_fixture)
from .state import Ledger
from .test_evidence import INPUTS, RECIPE


class PublicationTests(unittest.TestCase):
    def setUp(self):
        self.root = EVALUATION_DATA / "publication-tests" / uuid.uuid4().hex[:16]
        self.scope = FixtureScope(self.root, authorized=True)
        self.fixture = initialize_fixture(self.scope, "case")
        self.db = self.root / "ledger.sqlite3"
        self.ledger = Ledger(self.db)
        self.authorization = self.ledger.authorize("RUN", event_id="authorize",
            reason="Explicit owned fixture regression", expected_revision=0)
        self.publisher = GitPublisher(self.scope, self.ledger, self.root / "p")
        self.baseline = self.git("rev-parse", "HEAD")

    def git(self, *arguments, bare=False):
        return _text(self.fixture.remote if bare else self.fixture.repository,
                     list(arguments), self.fixture.evidence_dir, bare=bare)

    def prepare(self, assignment="assignment-one", path="source.cpp", *, approve=True, raw_content=None):
        owner = f"owner-{assignment}"
        expected = raw_content if raw_content is not None else f"int value_{assignment.replace('-', '_')}() {{ return 2; }}\n".encode("utf-8")
        (self.fixture.repository / path).write_bytes(expected)
        inputs = INPUTS | {"source": [path]}
        if (self.fixture.repository / ".gitattributes").is_file():
            inputs = inputs | {"config": [*INPUTS["config"], ".gitattributes"]}
        manifest = capture_inputs(self.fixture.repository, inputs, RECIPE)
        self.assertEqual(expected, (self.fixture.repository / path).read_bytes())
        measurement = self.fixture.evidence_dir / f"{assignment}-measurement.json"
        measurement.write_text(json.dumps({"scope": "evaluation_fixture", "check": "exact fixture raw-byte comparison",
            "matched": True, "actual": file_identity(self.fixture.repository / path),
            "input_identity": manifest.identity, "semantic_correctness": "not established"}, indent=2), encoding="utf-8")
        manifest_path = self.fixture.evidence_dir / f"{assignment}-inputs.json"
        manifest_path.write_text(json.dumps(manifest.to_dict(), indent=2), encoding="utf-8")
        revision = self.authorization["revision"]
        self.ledger.create_assignment(assignment_id=assignment, function={"fixture_symbol": assignment},
            stage="sol", provider="openai-codex", model="gpt-6.1-sol", owner_id=owner,
            session_id=f"session-{assignment}", event_id=f"{assignment}:created", authorization_revision=revision)
        self.ledger.record_attempt(assignment, event_id=f"{assignment}:measured", candidate_id="candidate-0",
            source_ref={"path": str(self.fixture.repository / path), **file_identity(self.fixture.repository / path)},
            input_identity=manifest.identity, recipe_ref=str(manifest_path), outcome="matching",
            evidence_refs=[str(measurement)], quality=1.0, authorization_revision=revision)
        self.ledger.record_verification(assignment, event_id=f"{assignment}:verified", candidate_id="candidate-0",
            input_identity=manifest.identity, evidence={"scope": "evaluation_fixture",
                "checks": {"raw_byte_comparison": str(measurement)}, "runtime_status": "unavailable"},
            authorization_revision=revision)
        request = prepare_publication(self.fixture, assignment, [path], manifest)
        (self.fixture.evidence_dir / f"{assignment}-request.json").write_text(
            json.dumps(request.to_dict(), indent=2), encoding="utf-8")
        publication_target = request.publication_target
        if approve:
            self.ledger.transition(assignment, "review_wait", event_id=f"{assignment}:review-wait", details={})
            self.ledger.transition(assignment, "reconciling", event_id=f"{assignment}:reviewed", details={"review": {
                "approved_by": "fixture-parent", "input_identity": manifest.identity,
                "publication_target": publication_target, "request_digest": request.request_digest,
                "evidence_refs": [str(measurement)]}})
            self.ledger.transition(assignment, "publication_wait", event_id=f"{assignment}:materialized", details={"materialization": {
                "owner_id": owner, "input_identity": manifest.identity,
                "patch_identity": request.patch_identity, "publication_target": publication_target,
                "request_digest": request.request_digest, "evidence_refs": [str(measurement)]}})
        return request

    def restart(self):
        self.ledger = Ledger(self.db)
        self.publisher = GitPublisher(self.scope, self.ledger, self.root / "p")

    def assert_single_assignment_commit(self, request, commit):
        self.assertEqual(commit, self.git("rev-parse", "HEAD"))
        self.assertEqual("2", self.git("rev-list", "--count", "HEAD"))
        self.assertIn(f"OMP-Evaluation-Assignment: {request.assignment_id}", self.git("show", "-s", "--format=%B", commit))
        self.assertEqual("source.cpp", self.git("diff-tree", "--no-commit-id", "--name-only", "-r", commit))

    def test_long_receive_paths_use_sealed_fixture_local_configuration(self):
        # Native unpack-objects checks its quarantine directory before loading
        # core.longpaths. Keep that directory bootstrap-readable while forcing
        # real received object leaves beyond MAX_PATH, as in the pilot failure.
        name_length = 220 - len(str(self.root / "fixtures" / "remote.git")) - 1
        self.assertGreaterEqual(name_length, len("long-receive-"))
        self.assertLessEqual(name_length, 120)
        name = "long-receive-" + "x" * (name_length - len("long-receive-"))
        self.fixture = initialize_fixture(self.scope, name)
        quarantine_directory = self.fixture.remote / "objects" / "tmp_objdir-incoming-123456"
        self.assertLess(len(str(quarantine_directory)), 260)
        self.assertGreater(len(str(quarantine_directory / "ab" / ("c" * 38))), 260)
        self.assertEqual("true", self.git("config", "--local", "--get", "core.longpaths"))
        self.assertEqual("true", self.git("config", "--local", "--get", "core.longpaths", bare=True))
        self.baseline = self.git("rev-parse", "HEAD")
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        initial_object = self.fixture.remote / "objects" / self.baseline[:2] / self.baseline[2:]
        self.assertGreater(len(str(initial_object)), 260)
        self.assertTrue(initial_object.is_file())
        self.assertEqual("commit", self.git("cat-file", "-t", self.baseline, bare=True))
        request = self.prepare("long-receive-assignment")
        result = self.publisher.publish(request, event_id="long-receive-completion")
        self.assertTrue(result.pushed)
        self.assertEqual(result.commit_id, self.git("rev-parse", "refs/heads/main", bare=True))
        published_object = self.fixture.remote / "objects" / result.commit_id[:2] / result.commit_id[2:]
        self.assertGreater(len(str(published_object)), 260)
        self.assertTrue(published_object.is_file())
        self.assertEqual("commit", self.git("cat-file", "-t", result.commit_id, bare=True))
        self.assert_single_assignment_commit(request, result.commit_id)
        validate_fixture(self.scope, self.fixture)

    def test_duplicate_events_preserve_index_working_files_and_one_commit(self):
        request = self.prepare()
        unrelated = self.fixture.repository / "unrelated.txt"
        unrelated.write_bytes(b"separately staged bytes\r\n")
        self.git("add", "--", "unrelated.txt")
        unrelated.write_bytes(b"separately unstaged bytes\r\n")
        (self.fixture.repository / "untracked-note.txt").write_bytes(b"must remain untouched\n")
        index = (self.fixture.repository / ".git" / "index").read_bytes()
        files = {path.name: path.read_bytes() for path in self.fixture.repository.iterdir() if path.is_file()}
        first = self.publisher.publish(request, event_id="completion")
        second = self.publisher.publish(request, event_id="completion")
        self.restart()
        third = self.publisher.publish(request, event_id="duplicate-reconnect")
        self.assertEqual(first.commit_id, second.commit_id)
        self.assertEqual(first.commit_id, third.commit_id)
        self.assertTrue(first.pushed and second.pushed and third.pushed)
        self.assertEqual(first.commit_id, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assert_single_assignment_commit(request, first.commit_id)
        self.assertEqual(index, (self.fixture.repository / ".git" / "index").read_bytes())
        self.assertEqual(files, {path.name: path.read_bytes() for path in self.fixture.repository.iterdir() if path.is_file()})
        self.assertEqual("unrelated baseline", self.git("show", "HEAD:unrelated.txt"))
        self.assertEqual("separately staged bytes", self.git("show", ":unrelated.txt"))
        assignment = self.ledger.assignment(request.assignment_id)
        self.assertEqual("pushed", assignment["status"])
        self.assertEqual("owner-assignment-one", assignment["owner_id"])
        self.assertIsNone(assignment["publication_acknowledgment"])
        self.assertIsNone(assignment["cleanup"])

    def test_crash_after_commit_recovers_observed_commit_without_duplicate(self):
        request = self.prepare()
        with self.assertRaises(InjectedCrash):
            self.publisher.publish(request, event_id="completion", fault_at="after_commit")
        intent = self.ledger.publication(request.assignment_id)
        self.assertIsNone(intent.get("commit"))
        self.assertEqual(intent["planned_commit"], self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        self.restart()
        recovered_request = PublicationRequest.from_dict(self.ledger.publication(request.assignment_id)["request"])
        result = self.publisher.publish(recovered_request, event_id="completion")
        self.assertTrue(result.recovered and result.pushed)
        self.assertEqual(intent["planned_commit"], result.commit_id)
        self.assertEqual(result.commit_id, self.ledger.publication(request.assignment_id)["commit"])
        self.assert_single_assignment_commit(request, result.commit_id)

    def test_crash_after_push_recovers_real_remote_before_acknowledgment(self):
        request = self.prepare()
        with self.assertRaises(InjectedCrash):
            self.publisher.publish(request, event_id="completion", fault_at="after_push")
        pending = self.ledger.publication(request.assignment_id)
        self.assertFalse(pending["pushed"])
        self.assertEqual(pending["commit"], self.git("rev-parse", "refs/heads/main", bare=True))
        self.restart()
        result = self.publisher.publish(request, event_id="completion")
        self.assertTrue(result.recovered and result.pushed)
        self.assertEqual(pending["commit"], result.commit_id)
        self.assertTrue(self.ledger.publication(request.assignment_id)["remote_contains_commit"])
        self.assert_single_assignment_commit(request, result.commit_id)

    def test_remote_advancement_refuses_non_fast_forward_without_forcing(self):
        request = self.prepare()
        tree = self.git("rev-parse", "HEAD^{tree}", bare=True)
        advancement = self.git("commit-tree", tree, "-p", self.baseline, "-m", "Independent remote advancement", bare=True)
        self.git("update-ref", "refs/heads/main", advancement, self.baseline, bare=True)
        result = self.publisher.publish(request, event_id="completion")
        self.assertFalse(result.pushed)
        self.assertTrue(result.push_error)
        self.assertEqual(advancement, result.remote_head)
        self.assertEqual(advancement, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual("committed", self.ledger.assignment(request.assignment_id)["status"])
        self.restart()
        repeated = self.publisher.publish(request, event_id="recovery")
        self.assertEqual(result.commit_id, repeated.commit_id)
        self.assertFalse(repeated.pushed)
        self.assert_single_assignment_commit(request, result.commit_id)

    def test_remote_descendant_is_observed_as_pushed_without_rewriting_remote(self):
        request = self.prepare()
        first = self.publisher.publish(request, event_id="completion")
        tree = self.git("rev-parse", "HEAD^{tree}", bare=True)
        advanced = self.git("commit-tree", tree, "-p", first.commit_id, "-m", "Remote checkpoint after publication", bare=True)
        self.git("update-ref", "refs/heads/main", advanced, first.commit_id, bare=True)
        self.restart()
        result = self.publisher.publish(request, event_id="recovery")
        self.assertTrue(result.pushed)
        self.assertEqual(advanced, result.remote_head)
        self.assertEqual(advanced, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assert_single_assignment_commit(request, result.commit_id)

    def test_unrelated_head_advancement_does_not_require_reverification(self):
        request = self.prepare()
        (self.fixture.repository / "unrelated.txt").write_bytes(b"unrelated new committed checkpoint\n")
        self.git("add", "--", "unrelated.txt")
        self.git("commit", "-m", "Unrelated owner checkpoint")
        unrelated_head = self.git("rev-parse", "HEAD")
        self.assertNotEqual(request.to_dict()["prepared_head"], unrelated_head)
        result = self.publisher.publish(request, event_id="completion")
        self.assertTrue(result.pushed)
        self.assertEqual(unrelated_head, self.git("rev-parse", f"{result.commit_id}^"))
        self.assertTrue(self.ledger.assignment(request.assignment_id)["verification"]["valid"])

    def test_relevant_header_change_invalidates_approval_before_git_mutation(self):
        request = self.prepare()
        index = (self.fixture.repository / ".git" / "index").read_bytes()
        (self.fixture.repository / "shared.h").write_bytes(b"#define FIXTURE_VALUE 99\n")
        with self.assertRaisesRegex(PublicationError, "re-verification"):
            self.publisher.publish(request, event_id="completion")
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual(index, (self.fixture.repository / ".git" / "index").read_bytes())
        assignment = self.ledger.assignment(request.assignment_id)
        self.assertFalse(assignment["verification"]["valid"])
        self.assertEqual("verifying", assignment["status"])
        self.assertIsNone(assignment["review"])
        self.assertIsNone(assignment["materialization"])
        self.assertIsNone(self.ledger.publication(request.assignment_id))

    def test_parent_review_is_required(self):
        request = self.prepare(approve=False)
        with self.assertRaises(PublicationError):
            self.publisher.publish(request, event_id="unapproved")
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))

    def test_publish_existing_permits_publication_without_replacing_owner(self):
        request = self.prepare()
        self.ledger.authorize("PUBLISH_EXISTING", event_id="publish-only", reason="Publish approved existing result only",
            expected_revision=self.authorization["revision"])
        before = self.ledger.assignment(request.assignment_id)
        result = self.publisher.publish(request, event_id="completion")
        after = self.ledger.assignment(request.assignment_id)
        self.assertTrue(result.pushed)
        self.assertEqual(before["session_id"], after["session_id"])
        self.assertEqual(before["stages"], after["stages"])

    def test_stop_survives_restart_and_prevents_publication(self):
        request = self.prepare()
        self.ledger.request_stop(event_id="stop", reason="Stop wins over queued completion")
        self.restart()
        with self.assertRaises(PolicyError):
            self.publisher.publish(request, event_id="queued-completion")
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))

    def test_two_assignments_get_separate_commits_and_retained_publisher(self):
        self.ledger.register_publisher(owner_id="retained-publisher", session_id="retained-publisher-session",
            provider="openai-codex", model="gpt-6.1-sol", event_id="publisher",
            authorization_revision=self.authorization["revision"])
        first = self.publisher.publish(self.prepare(), event_id="first-completion")
        second = self.publisher.publish(self.prepare("assignment-two", "second.cpp"), event_id="second-completion")
        self.assertNotEqual(first.commit_id, second.commit_id)
        self.assertEqual(first.commit_id, self.git("rev-parse", f"{second.commit_id}^"))
        self.assertEqual("second.cpp", self.git("diff-tree", "--no-commit-id", "--name-only", "-r", second.commit_id))
        for index, result in enumerate((first, second)):
            self.ledger.publisher_checkpoint(event_id=f"checkpoint-{index}", checkpoint_id=result.commit_id,
                record={"source_commit": result.commit_id, "report_ref": result.observation_ref,
                        "observation_ref": result.observation_ref})
        publisher = self.ledger.snapshot()["publisher"]
        self.assertEqual("retained-publisher", publisher["owner_id"])
        self.assertEqual("retained-publisher-session", publisher["session_id"])
        self.assertEqual(2, len(publisher["checkpoints"]))
        self.assertEqual("awaiting-parent", publisher["status"])
        self.assertTrue(self.ledger.session("retained-publisher-session")["active"])
        self.assertEqual("pushed", self.ledger.assignment("assignment-one")["status"])
        self.assertEqual("pushed", self.ledger.assignment("assignment-two")["status"])

    def test_independently_staged_owned_path_is_refused_and_preserved(self):
        request = self.prepare()
        self.git("add", "--", "source.cpp")
        index = (self.fixture.repository / ".git" / "index").read_bytes()
        with self.assertRaisesRegex(PublicationError, "Independently staged"):
            self.publisher.publish(request, event_id="completion")
        self.assertEqual(index, (self.fixture.repository / ".git" / "index").read_bytes())
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))

    def test_scope_and_linked_common_git_are_refused_before_publication(self):
        with self.assertRaises(PublicationError):
            FixtureScope(WORKTREE, authorized=True)
        with self.assertRaises(PublicationError):
            initialize_fixture(FixtureScope(self.root), "unauthorized")
        outside = Fixture(WORKTREE, self.fixture.remote, self.fixture.evidence_dir)
        with self.assertRaises((PublicationError, InputError)):
            validate_fixture(self.scope, outside)
        protected = FixtureScope(self.root, protected_roots=(self.fixture.repository,), authorized=True)
        with self.assertRaises(PublicationError):
            validate_fixture(protected, self.fixture)
        request = self.prepare()
        retained_git = self.fixture.repository / "retained-independent-git"
        (self.fixture.repository / ".git").rename(retained_git)
        # Only the owned fixture pointer is written. The active/common Git tree
        # is neither opened by Git nor mutated by this attempted publication.
        worktree_pointer = (WORKTREE / ".git").read_text(encoding="utf-8")
        (self.fixture.repository / ".git").write_text(worktree_pointer, encoding="utf-8")
        index = (retained_git / "index").read_bytes()
        with self.assertRaises(PublicationError):
            self.publisher.publish(request, event_id="protected-common-git")
        self.assertEqual(index, (retained_git / "index").read_bytes())
        self.assertEqual(worktree_pointer, (self.fixture.repository / ".git").read_text(encoding="utf-8"))
        self.assertIsNone(self.ledger.publication(request.assignment_id))

    def test_changed_git_configuration_is_refused(self):
        request = self.prepare()
        config = self.fixture.remote / "config"
        with config.open("a", encoding="utf-8") as stream:
            stream.write("\n[core]\n\thooksPath = ../outside-hooks\n")
        with self.assertRaisesRegex(PublicationError, "configuration changed"):
            self.publisher.publish(request, event_id="unsafe-config")
        self.assertIsNone(self.ledger.publication(request.assignment_id))

    def test_raw_postimage_and_git_blob_are_not_conflated_by_eol_filters(self):
        (self.fixture.repository / ".gitattributes").write_bytes(b"* text eol=lf\n")
        self.git("add", "--", ".gitattributes")
        self.git("commit", "-m", "Declare fixture Git normalization")
        raw = b"int fixture_value() { return 7; }\r\n// intentionally mixed endings\n"
        request = self.prepare(raw_content=raw)
        normalized_blob = _text(self.fixture.repository,
            ["hash-object", "--path=source.cpp", "--stdin"], self.fixture.evidence_dir, data=raw)
        raw_blob = _text(self.fixture.repository,
            ["hash-object", "--no-filters", "--stdin"], self.fixture.evidence_dir, data=raw)
        self.assertNotEqual(raw_blob, normalized_blob)
        index_before = (self.fixture.repository / ".git" / "index").read_bytes()
        result = self.publisher.publish(request, event_id="raw-publication")
        actual_blob = self.git("rev-parse", f"{result.commit_id}:source.cpp")
        committed = _git(self.fixture.repository, ["show", f"{result.commit_id}:source.cpp"],
                         self.fixture.evidence_dir).stdout
        self.assertEqual(raw_blob, actual_blob)
        self.assertEqual(raw, committed)
        self.assertEqual(raw, (self.fixture.repository / "source.cpp").read_bytes())
        self.assertEqual(index_before, (self.fixture.repository / ".git" / "index").read_bytes())
        record = self.ledger.publication(request.assignment_id)
        self.assertEqual(f"100644 {raw_blob} 0\tsource.cpp\0", record["private_index_entries"])
        self.assertTrue(Path(record["private_index"]).is_file())

    def test_approved_assignment_cannot_substitute_an_identical_fixture_target(self):
        request = self.prepare()
        other = initialize_fixture(self.scope, "other-target")
        (other.repository / "source.cpp").write_bytes((self.fixture.repository / "source.cpp").read_bytes())
        other_inputs = capture_inputs(other.repository, INPUTS, RECIPE)
        substituted = prepare_publication(other, request.assignment_id, ["source.cpp"], other_inputs)
        self.assertEqual(request.inputs.identity, substituted.inputs.identity)
        self.assertEqual(request.patch_identity, substituted.patch_identity)
        self.assertNotEqual(request.request_digest, substituted.request_digest)
        expected_target = {"repository": str(self.fixture.repository),
                           "remote": str(self.fixture.remote), "branch": self.fixture.branch}
        approved = self.ledger.assignment(request.assignment_id)
        self.assertEqual(expected_target, approved["review"]["publication_target"])
        self.assertEqual(expected_target, approved["materialization"]["publication_target"])
        other_before = _text(other.repository, ["rev-parse", "HEAD"], other.evidence_dir)
        original_index = (self.fixture.repository / ".git" / "index").read_bytes()
        other_index = (other.repository / ".git" / "index").read_bytes()
        refusal = None
        try:
            self.publisher.publish(substituted, event_id="substituted-target")
        except (PublicationError, PolicyError) as error:
            refusal = str(error)
        observed = {
            "approved_head": self.git("rev-parse", "HEAD"),
            "approved_remote": self.git("rev-parse", "refs/heads/main", bare=True),
            "substituted_head": _text(other.repository, ["rev-parse", "HEAD"], other.evidence_dir),
            "substituted_remote": _text(other.remote, ["rev-parse", "refs/heads/main"], other.evidence_dir, bare=True)}
        (self.fixture.evidence_dir / "target-substitution-observed.json").write_text(json.dumps({
            "approved_target": expected_target, "observed": observed, "refusal": refusal,
            "publication": self.ledger.publication(request.assignment_id)}, indent=2), encoding="utf-8")
        self.assertEqual({"approved_head": self.baseline, "approved_remote": self.baseline,
                          "substituted_head": other_before, "substituted_remote": other_before}, observed)
        self.assertIsNotNone(refusal)
        self.assertIsNone(self.ledger.publication(request.assignment_id))
        self.assertEqual(original_index, (self.fixture.repository / ".git" / "index").read_bytes())
        self.assertEqual(other_index, (other.repository / ".git" / "index").read_bytes())

    def _exercise_stop_at_native_mutation(self, boundary):
        request = self.prepare()
        original_git = publication_module._git
        mutations = []
        stop_inserted = False
        stopped_revision = None

        def stop_then_execute_real_git(repository, arguments, evidence_dir, **kwargs):
            nonlocal stop_inserted, stopped_revision
            command = arguments[0]
            if command in {"update-ref", "push"}:
                mutations.append(command)
            if command == boundary and not stop_inserted:
                # This is the native-call boundary immediately after the
                # publisher's authorization/admission returned, not fake Git.
                stopped = self.ledger.request_stop(event_id=f"stop-before-{boundary}",
                    reason=f"Deterministic STOP at the real {boundary} mutation window")
                stopped_revision = stopped["revision"]
                stop_inserted = True
            return original_git(repository, arguments, evidence_dir, **kwargs)

        interrupted = None
        with patch.object(publication_module, "_git", stop_then_execute_real_git):
            try:
                self.publisher.publish(request, event_id=f"window-{boundary}")
            except (PublicationError, PolicyError) as error:
                interrupted = str(error)
        self.assertTrue(stop_inserted)
        head = self.git("rev-parse", "HEAD")
        remote = self.git("rev-parse", "refs/heads/main", bare=True)
        publication = self.ledger.publication(request.assignment_id)
        observed = {"boundary": boundary, "head": head, "remote": remote,
                    "mutations": mutations, "interrupted": interrupted,
                    "authorization": self.ledger.authorization(), "publication": publication}
        (self.fixture.evidence_dir / f"stop-window-{boundary}-observed.json").write_text(
            json.dumps(observed, indent=2), encoding="utf-8")
        self.assertNotEqual(self.baseline, head)
        self.assertEqual(["update-ref"] if boundary == "update-ref" else ["update-ref", "push"], mutations)
        self.assertEqual(self.baseline if boundary == "update-ref" else head, remote)
        self.assertEqual("STOPPING", self.ledger.authorization()["mode"])
        self.assertEqual(stopped_revision, self.ledger.authorization()["revision"])
        self.assertIsNotNone(publication)
        # Already-admitted effects must remain durably observable after STOP;
        # a bare PolicyError with a changed Git ref is not sufficient recovery.
        self.assertEqual(head, publication.get("commit"))
        self.assertEqual(boundary == "push", bool(publication.get("pushed")))
        if boundary == "push":
            self.assertEqual(remote, publication.get("remote_head"))
            self.assertTrue(publication.get("remote_contains_commit"))
        self.restart()
        self.assertEqual("STOPPING", self.ledger.authorization()["mode"])
        with patch.object(publication_module, "_git", stop_then_execute_real_git):
            try:
                self.publisher.publish(request, event_id=f"stopped-recovery-{boundary}")
            except (PublicationError, PolicyError):
                pass
        self.assertEqual(["update-ref"] if boundary == "update-ref" else ["update-ref", "push"], mutations)
        self.assertEqual(head, self.git("rev-parse", "HEAD"))
        self.assertEqual(remote, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual(head, self.ledger.publication(request.assignment_id).get("commit"))
        self.assertEqual("STOPPING", self.ledger.authorization()["mode"])

    def test_stop_in_commit_window_preserves_admitted_observation_without_push(self):
        self._exercise_stop_at_native_mutation("update-ref")

    def test_stop_in_push_window_preserves_actual_remote_observation(self):
        self._exercise_stop_at_native_mutation("push")

    def _recover_with_real_reads_only(self, request, event_id):
        original_git = publication_module._git
        commands = []

        def observe_without_mutation(repository, arguments, evidence_dir, **kwargs):
            commands.append(arguments[0])
            self.assertIn(arguments[0], {"rev-parse", "merge-base", "ls-remote", "cat-file"})
            return original_git(repository, arguments, evidence_dir, **kwargs)

        with patch.object(publication_module, "_git", observe_without_mutation):
            result = self.publisher.recover(request, event_id=event_id)
        self.assertTrue(commands)
        return result

    def _exercise_stopped_crash_recovery(self, boundary):
        request = self.prepare()
        with self.assertRaises(InjectedCrash):
            self.publisher.publish(request, event_id="crashing-publication", fault_at=boundary)
        planned = self.ledger.publication(request.assignment_id)["planned_commit"]
        self.assertEqual(planned, self.git("rev-parse", "HEAD"))
        expected_remote = planned if boundary == "after_push" else self.baseline
        self.assertEqual(expected_remote, self.git("rev-parse", "refs/heads/main", bare=True))
        stopped = self.ledger.request_stop(event_id="stop-after-crash", reason="Recover outcomes without restarting work")
        index = (self.fixture.repository / ".git" / "index").read_bytes()
        self.restart()
        result = self._recover_with_real_reads_only(request, "stopped-observation")
        self.assertIsNotNone(result)
        self.assertEqual(planned, result.commit_id)
        self.assertEqual(boundary == "after_push", result.pushed)
        durable = self.ledger.publication(request.assignment_id)
        self.assertEqual(planned, durable["commit"])
        self.assertEqual(boundary == "after_push", durable["pushed"])
        self.assertEqual(stopped, self.ledger.authorization())
        repeated = self._recover_with_real_reads_only(request, "repeated-stopped-observation")
        self.assertEqual(result.commit_id, repeated.commit_id)
        self.assertEqual(result.pushed, repeated.pushed)
        self.assertEqual(stopped, self.ledger.authorization())
        self.assertEqual(index, (self.fixture.repository / ".git" / "index").read_bytes())
        self.assertEqual(planned, self.git("rev-parse", "HEAD"))
        self.assertEqual(expected_remote, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual("2", self.git("rev-list", "--count", "HEAD"))
        with self.assertRaises(PolicyError):
            self.publisher.publish(request, event_id="forbidden-fresh-work")

    def test_stopped_recovery_observes_commit_crash_without_admitting_push(self):
        self._exercise_stopped_crash_recovery("after_commit")
        effects = self.ledger.publication_effects("assignment-one")
        self.assertEqual(["commit"], [effect["kind"] for effect in effects])

    def test_stopped_recovery_observes_push_crash_without_reexecuting_git(self):
        self._exercise_stopped_crash_recovery("after_push")
        effects = self.ledger.publication_effects("assignment-one")
        self.assertEqual(["commit", "push"], sorted(effect["kind"] for effect in effects))

    def test_stopped_observation_does_not_reapprove_changed_current_inputs(self):
        request = self.prepare()
        with self.assertRaises(InjectedCrash):
            self.publisher.publish(request, event_id="historical-commit", fault_at="after_commit")
        committed = self.git("rev-parse", "HEAD")
        (self.fixture.repository / "shared.h").write_bytes(b"#define FIXTURE_VALUE 71\n")
        changed = capture_inputs(self.fixture.repository, INPUTS, RECIPE)
        evidence = self.fixture.evidence_dir / "changed-current-inputs.json"
        evidence.write_text(json.dumps(changed.to_dict(), indent=2), encoding="utf-8")
        self.ledger.check_input_identity(request.assignment_id, event_id="invalidate-current-inputs",
            input_identity=changed.identity, evidence_ref=str(evidence))
        stopped = self.ledger.request_stop(event_id="stop-invalidated", reason="Observe historical effect only")
        self.restart()
        result = self._recover_with_real_reads_only(request, "observe-historical-commit")
        self.assertIsNotNone(result)
        self.assertEqual(committed, result.commit_id)
        self.assertFalse(result.pushed)
        assignment = self.ledger.assignment(request.assignment_id)
        self.assertFalse(assignment["verification"]["valid"])
        self.assertIsNone(assignment["review"])
        self.assertIsNone(assignment["materialization"])
        self.assertEqual(0, assignment["accepted_credit"])
        self.assertEqual(stopped, self.ledger.authorization())
        self.assertEqual(committed, self.ledger.publication(request.assignment_id)["commit"])
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual(["commit"], [effect["kind"] for effect in self.ledger.publication_effects(request.assignment_id)])

    def test_unexecuted_admission_is_observed_not_replayed_after_stop(self):
        request = self.prepare()
        admit = self.ledger.admit_publication_effect

        def admit_stop_and_crash(*args, **kwargs):
            receipt = admit(*args, **kwargs)
            if kwargs["kind"] == "commit" and receipt["execute"]:
                self.ledger.request_stop(event_id="stop-before-execution", reason="Admission persisted before owner crash")
                raise InjectedCrash("Admitted command has not executed")
            return receipt

        with patch.object(self.ledger, "admit_publication_effect", admit_stop_and_crash):
            with self.assertRaises(InjectedCrash):
                self.publisher.publish(request, event_id="admitted-but-unexecuted")
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        self.restart()
        result = self._recover_with_real_reads_only(request, "stopped-absent-observation")
        self.assertIsNone(result)
        self.assertIsNone(self.ledger.publication(request.assignment_id)["commit"])
        effects = self.ledger.publication_effects(request.assignment_id)
        self.assertEqual(1, len(effects))
        self.assertEqual("STOPPING", self.ledger.authorization()["mode"])
        with self.assertRaises(PolicyError):
            self.publisher.publish(request, event_id="admitted-but-unexecuted")
        self.assertEqual(self.baseline, self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))

    def _exercise_stop_before_admission(self, kind):
        request = self.prepare()
        admit = self.ledger.admit_publication_effect

        def stop_before_admit(*args, **kwargs):
            if kwargs["kind"] == kind:
                self.ledger.request_stop(event_id=f"stop-before-{kind}-admission",
                    reason="STOP persisted before the durable mutation ordering point")
            return admit(*args, **kwargs)

        with patch.object(self.ledger, "admit_publication_effect", stop_before_admit):
            with self.assertRaises(PolicyError):
                self.publisher.publish(request, event_id="denied-admission")
        intent = self.ledger.publication(request.assignment_id)
        expected_head = intent["planned_commit"] if kind == "push" else self.baseline
        self.assertEqual(expected_head, self.git("rev-parse", "HEAD"))
        self.assertEqual(self.baseline, self.git("rev-parse", "refs/heads/main", bare=True))
        self.assertEqual(intent["planned_commit"] if kind == "push" else None, intent["commit"])
        self.assertFalse(intent["pushed"])
        self.assertEqual(["commit"] if kind == "push" else [],
                         [effect["kind"] for effect in self.ledger.publication_effects(request.assignment_id)])
        self.assertEqual("STOPPING", self.ledger.authorization()["mode"])

    def test_stop_before_commit_admission_prevents_ref_mutation(self):
        self._exercise_stop_before_admission("commit")

    def test_stop_before_push_admission_preserves_commit_without_remote_mutation(self):
        self._exercise_stop_before_admission("push")


if __name__ == "__main__":
    unittest.main()
