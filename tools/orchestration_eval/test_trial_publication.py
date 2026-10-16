"""Actual owned Git history and normal launch-input consumer; no model or compile proof."""
import copy
import json
import os
from pathlib import Path
import unittest

from . import test_trial_repository as repository_fixtures
from .evidence import file_identity
from .safety import SafetyError, digest, save_json
from .test_state import WorkflowFixture
from .trial_publication import build_publication_inputs
from .trial_repository import IndependentRepository
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned Git/process verification required")
class TrialPublicationTests(unittest.TestCase):
    def setUp(self):
        # Reuse the established real Git setup, not a simulated repository/client.
        self.fixture = repository_fixtures.TrialRepositoryTests(
            "test_exact_engineering_correction_continues_without_reinitializing_target")
        self.addCleanup(self.fixture.doCleanups)
        self.addCleanup(self.fixture.tearDown)
        self.fixture.setUp()
        self.units, self.files = [], {}
        self.head = self.fixture.baseline

    def publish(self, name, raw):
        fixture = self.fixture
        path = fixture.target / name
        path.write_bytes(raw)
        parent = self.head
        fixture.git(fixture.target, "add", "--", name)
        fixture.git(fixture.target, "commit", "-m", "Owned incremental publication fixture " + name)
        self.head = fixture.git(fixture.target, "rev-parse", "HEAD")
        fixture.git(fixture.target, "push", "origin", "HEAD:refs/heads/controller-trial")
        self.assertEqual(fixture.git(fixture.remote, "rev-parse", "refs/heads/controller-trial"), self.head)
        image = {"mode": "100644", "blob": fixture.git(fixture.target, "rev-parse", self.head + ":" + name),
                 "raw": file_identity(path)}
        directory = fixture.fixture_root / "engineering-units" / str(len(self.units) + 1)
        published = directory / "pushed.json"
        save_json(published, {"commit": self.head, "parent": parent, "paths": [name], "files": {name: image},
            "remote": str(fixture.remote), "branch": "refs/heads/controller-trial", "remote_head": self.head,
            "qualification": "Actual owned local Git commit/push; no reconstruction/compiler inference"})
        self.units.append({"commit": self.head, "parent": parent, "paths": [name], "receipt": str(published),
                           "postimages": {name: {key: image[key] for key in ("mode", "blob")}}})
        self.files[name] = image
        declaration = directory / "last-delta-source-identities.json"
        entry = {"path": name, **image["raw"]}
        save_json(declaration, {"sources": [] if name == "ORCHESTRATION_PLAN.md" else [entry],
                               "documentation": [entry] if name == "ORCHESTRATION_PLAN.md" else []})
        descriptor = {"schema": "brawl-owned-engineering-publication/v2",
            "engineering_baseline": fixture.baseline, "repository": str(fixture.target),
            "git_dir": str(fixture.target / ".git"), "remote": str(fixture.remote), "branch": "controller-trial",
            "head": self.head, "remote_head": self.head, "directory_identity": fixture.target.stat().st_ino,
            "config_sha256": digest(fixture.target / ".git/config"), "files": self.files, "units": self.units,
            "controller_id": fixture.f.config["controller_id"], "next_run_id": "previous-unlaunched-input",
            "source_manifest": {"path": str(declaration), "sha256": digest(declaration)},
            "evidence_refs": [str(directory)]}
        original = directory / "engineering-publication.json"
        save_json(original, descriptor)
        return original

    def admit_built_inputs(self, original):
        fixture = self.fixture
        original_bytes = original.read_bytes()
        index_before = file_identity(fixture.target / ".git/index")
        builder_results = []
        def prepare(continuation):
            continuation.case.manifest["publication_target"] = dict(fixture.f.case.manifest["publication_target"])
        def configure(continuation):
            target = continuation.config["publication_target"]
            target.update(fixture.f.config["publication_target"], baseline=self.head)
            result = build_publication_inputs(original, run_id=continuation.root.name,
                                              output=continuation.root / "publication-inputs")
            builder_results.append(result)
            target["prepared_repository"] = result["publication"]
        continuation = WorkflowFixture(prepare=prepare, configure=configure)
        runtime = TrialRuntime(continuation.root, continuation.ledger, Path("never-a-native-model-host.exe"), {})
        try:
            action = continuation.admit(None)
            action.pop("execute")
            repository = IndependentRepository(runtime)
            result = repository.prepare_target(action)
            self.assertEqual(result["head"], self.head)
            self.assertTrue(result["retained_engineering_publication"])
            runtime.workflow.complete(action, result, refs=result["evidence_refs"])
            built = builder_results[0]
            manifest = json.loads(Path(built["source_manifest"]["path"]).read_bytes())
            self.assertEqual({entry["path"] for entry in manifest["sources"] + manifest["documentation"]},
                             {"engineering.py", "ORCHESTRATION_PLAN.md"})
            normalized = json.loads(Path(built["publication"]["path"]).read_bytes())
            retained = json.loads(original_bytes)
            for key in ("files", "units", "engineering_baseline", "head", "remote_head"):
                self.assertEqual(normalized[key], retained[key])
            self.assertEqual(normalized["next_run_id"], continuation.root.name)
            self.assertEqual(original.read_bytes(), original_bytes)
            self.assertEqual(file_identity(fixture.target / ".git/index"), index_before)
            self.assertEqual(file_identity(fixture.source / ".git/index"), fixture.source_index)
            with self.assertRaises(SafetyError):
                build_publication_inputs(original, run_id=continuation.root.name,
                                         output=continuation.root / "publication-inputs")
        finally:
            runtime.workflow.shutdown()
            runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
            runtime.manager.stop_all()

    def test_successive_source_and_doc_deltas_build_complete_actual_git_admission(self):
        self.publish("engineering.py", b"value = 1\n")
        first = self.publish("ORCHESTRATION_PLAN.md", b"# Owned fixture documentation one\n")
        self.admit_built_inputs(first)
        first_units = copy.deepcopy(self.units)
        self.publish("engineering.py", b"value = 2\n")
        second = self.publish("ORCHESTRATION_PLAN.md", b"# Owned fixture documentation two\n")
        self.admit_built_inputs(second)
        self.assertEqual(self.units[:2], first_units)
        self.assertEqual(len(self.units), 4)
        bad = json.loads(second.read_bytes())
        bad["units"][0]["postimages"]["engineering.py"]["blob"] = self.files["engineering.py"]["blob"]
        malformed = self.fixture.fixture_root / "changed-historical-postimage.json"
        save_json(malformed, bad)
        output = self.fixture.fixture_root / "refused-inputs"
        with self.assertRaises(SafetyError):
            build_publication_inputs(malformed, run_id="refused-history", output=output)
        self.assertFalse(output.exists())
