"""Parent-approved commit/push of owner-materialized, independently owned fixtures.

This is not source integration or checked-handoff. No working file or ordinary
index is modified by publication. A private index builds one assignment's commit;
Git ref observations, not task success, establish commit and push outcomes.
"""
from __future__ import annotations

import contextlib
import json
import os
import re
import subprocess
import time
import uuid
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Callable, Iterator, Mapping, Sequence

from .evidence import (InputError, InputManifest, canonical_json, content_identity,
                       file_identity, input_path, reject_links, relative_path,
                       validate_inputs)


WORKTREE = Path(__file__).resolve().parents[2]
EVALUATION_DATA = WORKTREE / "build" / "orchestration-eval"


class PublicationError(RuntimeError):
    """Publication is unsafe, unauthorized, stale, or lacks real Git evidence."""


class InjectedCrash(RuntimeError):
    """Deterministic exercise boundary after a real Git side effect."""


@dataclass(frozen=True)
class FixtureScope:
    evaluation_root: Path
    protected_roots: tuple[Path, ...] = ()
    authorized: bool = False

    def __post_init__(self) -> None:
        root = Path(self.evaluation_root).absolute()
        reject_links(root)
        if not root.resolve().is_relative_to(EVALUATION_DATA.resolve()):
            raise PublicationError(f"Fixture scope must be under {EVALUATION_DATA}")
        object.__setattr__(self, "evaluation_root", root)
        object.__setattr__(self, "protected_roots", tuple(Path(p).resolve() for p in self.protected_roots))

    def check_path(self, path: str | Path) -> Path:
        candidate = Path(path).absolute()
        reject_links(candidate)
        resolved = candidate.resolve()
        if not resolved.is_relative_to(self.evaluation_root.resolve()):
            raise PublicationError(f"Path escapes the authorized fixture scope: {candidate}")
        if resolved in self.protected_roots:
            raise PublicationError(f"Protected repository: {candidate}")
        return candidate

    def require_write(self) -> None:
        if not self.authorized:
            raise PublicationError("Explicit evaluation authorization is required for fixture writes")


@dataclass(frozen=True)
class Fixture:
    repository: Path
    remote: Path
    evidence_dir: Path
    branch: str = "main"

    @property
    def root(self) -> Path:
        return self.repository.parent


def _environment(extra: Mapping[str, str] | None = None) -> dict[str, str]:
    result = {key: value for key, value in os.environ.items() if not key.upper().startswith("GIT_")}
    result.update({"GIT_CONFIG_NOSYSTEM": "1", "GIT_CONFIG_GLOBAL": os.devnull,
                   "GIT_TERMINAL_PROMPT": "0", "GIT_OPTIONAL_LOCKS": "0",
                   "GIT_AUTHOR_NAME": "OMP evaluation fixture", "GIT_AUTHOR_EMAIL": "evaluation@invalid.local",
                   "GIT_COMMITTER_NAME": "OMP evaluation fixture", "GIT_COMMITTER_EMAIL": "evaluation@invalid.local"})
    if extra:
        result.update(extra)
    return result


def _git(repository: Path, arguments: Sequence[str], evidence_dir: Path, *,
         extra: Mapping[str, str] | None = None, data: bytes | None = None,
         check: bool = True, bare: bool = False, record: bool = True) -> subprocess.CompletedProcess[bytes]:
    scope = FixtureScope(EVALUATION_DATA)
    scope.check_path(repository)
    scope.check_path(evidence_dir)
    reject_links(evidence_dir / "git-observations.jsonl")
    if (evidence_dir / "disabled-hooks").exists():
        raise PublicationError("The disabled Git hooks path must remain absent")
    git_dir = repository if bare else repository / ".git"
    scope.check_path(git_dir)
    if git_dir.is_file() or (git_dir / "commondir").exists() or (git_dir / "gitdir").exists():
        raise PublicationError("Git commands cannot address a linked or common production repository")
    # Git rejects an explicit GIT_DIR longer than PATH_MAX - 40 before its
    # long-path filesystem support applies. Anchor its short spelling to the
    # validated absolute cwd; this still selects the exact owned metadata and
    # never enables repository discovery or shortens the actual fixture path.
    command = ["git", "--git-dir", "." if bare else ".git"]
    if not bare:
        command += ["--work-tree", str(repository)]
    command += ["-c", f"core.hooksPath={evidence_dir / 'disabled-hooks'}",
                "-c", "core.fsmonitor=false", "-c", "core.autocrlf=false", "-c", "core.longpaths=true",
                "-c", "protocol.allow=never", "-c", "protocol.file.allow=always", *arguments]
    result = subprocess.run(command, cwd=repository, input=data, capture_output=True,
                            env=_environment({**(extra or {}), "TEMP": str(evidence_dir),
                                              "TMP": str(evidence_dir), "TMPDIR": str(evidence_dir)}),
                            timeout=120, check=False,
                            creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
    if record:
        evidence_dir.mkdir(parents=True, exist_ok=True)
        with (evidence_dir / "git-observations.jsonl").open("a", encoding="utf-8") as stream:
            stream.write(canonical_json({"observed_at_ns": time.time_ns(), "command": command,
                                        "cwd": str(repository),
                                        "returncode": result.returncode,
                                        "stdout": result.stdout.decode("utf-8", "replace"),
                                        "stderr": result.stderr.decode("utf-8", "replace")}) + "\n")
            stream.flush()
            os.fsync(stream.fileno())
    if check and result.returncode:
        raise PublicationError(f"Git {arguments[0]} failed ({result.returncode}): {result.stderr.decode('utf-8', 'replace').strip()}")
    return result


def _text(repository: Path, arguments: Sequence[str], evidence_dir: Path, **kwargs: Any) -> str:
    return _git(repository, arguments, evidence_dir, **kwargs).stdout.decode("utf-8").strip()


def _metadata_guard(scope: FixtureScope, repository: Path, *, bare: bool = False) -> None:
    scope.check_path(repository)
    metadata = repository if bare else repository / ".git"
    scope.check_path(metadata)
    if not metadata.is_dir() or (metadata / "commondir").exists() or (metadata / "gitdir").exists():
        raise PublicationError("Only separately initialized fixture Git repositories are allowed")
    # Git can otherwise follow object alternates, ref links, or worktree metadata
    # into a protected common directory despite an apparently safe worktree path.
    for directory, directories, files in os.walk(metadata, followlinks=False):
        for name in (*directories, *files):
            scope.check_path(Path(directory) / name)
    if (metadata / "objects" / "info" / "alternates").exists() or (metadata / "objects" / "info" / "http-alternates").exists():
        raise PublicationError("External object stores are not owned fixture repositories")
    hooks = metadata / "hooks"
    if hooks.exists() and any(path.is_file() and not path.name.endswith(".sample") for path in hooks.iterdir()):
        raise PublicationError("Fixture hooks must not execute external code")
    config = metadata / "config"
    if config.is_file():
        # Factory configuration is deliberately tiny; includes can redirect
        # hooks, worktrees, transports or object storage outside the fixture.
        text = config.read_text(encoding="utf-8").casefold()
        if re.search(r"\[\s*(include|includeif|extensions)\b", text):
            raise PublicationError("Fixture Git configuration cannot include external configuration")


def validate_fixture(scope: FixtureScope, fixture: Fixture) -> None:
    scope.check_path(fixture.root)
    scope.check_path(fixture.evidence_dir)
    marker_path = scope.check_path(fixture.root / "fixture.json")
    if not marker_path.is_file():
        raise PublicationError("Repository has no owned fixture identity")
    marker = json.loads(marker_path.read_text(encoding="utf-8"))
    expected = {"repository": str(fixture.repository.absolute()), "remote": str(fixture.remote.absolute()),
                "evidence_dir": str(fixture.evidence_dir.absolute()), "branch": fixture.branch}
    if marker.get("paths") != expected or marker.get("schema") != 1:
        raise PublicationError("Fixture paths do not match their recorded identity")
    if fixture.repository != fixture.root / "repository" or fixture.remote != fixture.root / "remote.git":
        raise PublicationError("Fixture repositories must use their independently initialized layout")
    if fixture.branch != "main":
        raise PublicationError("Evaluation fixture publication is confined to its main branch")
    _metadata_guard(scope, fixture.repository)
    _metadata_guard(scope, fixture.remote, bare=True)
    configs = {"repository": file_identity(fixture.repository / ".git" / "config"),
               "remote": file_identity(fixture.remote / "config")}
    if marker.get("configs") != configs:
        raise PublicationError("Fixture Git configuration changed since independent initialization")


def initialize_fixture(scope: FixtureScope, name: str, *, before_step: Callable[[str], None] | None = None) -> Fixture:
    """Initialize a fresh fixture; runtime callers supply owned-job STOP checkpoints."""
    scope.require_write()
    def step(label: str) -> None:
        if before_step is not None:
            before_step(label)
    if not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]{0,120}", name):
        raise PublicationError("Fixture name must be a single portable path component")
    relative_path(name)
    root = scope.check_path(scope.evaluation_root / "fixtures" / name)
    if root.exists():
        raise PublicationError("Fixture already exists; evidence must not be overwritten")
    step("create-root")
    root.mkdir(parents=True)
    fixture = Fixture(root / "repository", root / "remote.git", root / "evidence")
    step("create-repository")
    fixture.repository.mkdir()
    step("create-remote")
    fixture.remote.mkdir()
    step("create-evidence")
    fixture.evidence_dir.mkdir()
    step("git-init-remote")
    _git(fixture.remote, ["init", "--bare", "--initial-branch=main"], fixture.evidence_dir, bare=True)
    step("git-init-repository")
    _git(fixture.repository, ["init", "--initial-branch=main"], fixture.evidence_dir)
    # Local receive-pack drops the sender's command-scoped Git configuration.
    # Pin this in each owned repository before receive/unpack creates long
    # quarantine/object paths; these configs are included in the fixture seal.
    step("git-config-remote")
    _git(fixture.remote, ["config", "--local", "core.longpaths", "true"], fixture.evidence_dir, bare=True)
    step("git-config-repository")
    _git(fixture.repository, ["config", "--local", "core.longpaths", "true"], fixture.evidence_dir)
    files = {"source.cpp": b"int fixture_value() { return 1; }\n", "shared.h": b"#define FIXTURE_VALUE 1\n",
             "config.json": b'{"fixture":true}\n', "tool.txt": b"owned deterministic tool identity v1\n",
             "unrelated.txt": b"unrelated baseline\n"}
    for path, value in files.items():
        step("write-" + path)
        (fixture.repository / path).write_bytes(value)
    step("git-add-baseline")
    _git(fixture.repository, ["add", "--", *files], fixture.evidence_dir)
    step("git-commit-baseline")
    _git(fixture.repository, ["commit", "-m", "Initialize independent evaluation fixture"], fixture.evidence_dir)
    step("git-push-baseline")
    _git(fixture.repository, ["push", str(fixture.remote), "HEAD:refs/heads/main"], fixture.evidence_dir)
    paths = {"repository": str(fixture.repository), "remote": str(fixture.remote),
             "evidence_dir": str(fixture.evidence_dir), "branch": fixture.branch}
    configs = {"repository": file_identity(fixture.repository / ".git" / "config"),
               "remote": file_identity(fixture.remote / "config")}
    step("seal-fixture")
    (root / "fixture.json").write_text(canonical_json({
        "schema": 1, "fixture_id": uuid.uuid4().hex, "paths": paths, "configs": configs}), encoding="utf-8")
    validate_fixture(scope, fixture)
    return fixture


def _entry(fixture: Fixture, revision: str, path: str, *, record: bool = True) -> dict[str, str] | None:
    output = _git(fixture.repository, ["ls-tree", "-z", revision, "--", path],
                  fixture.evidence_dir, record=record).stdout
    if not output:
        return None
    records = output.rstrip(b"\0").split(b"\0")
    if len(records) != 1:
        raise PublicationError(f"Expected exactly one regular blob for {path}")
    metadata, actual_path = records[0].split(b"\t", 1)
    mode, kind, blob = metadata.decode("ascii").split()
    if actual_path.decode("utf-8") != path or kind != "blob" or mode != "100644":
        raise PublicationError(f"Only ordinary non-executable file changes are supported: {path}")
    return {"mode": mode, "blob": blob}


@dataclass(frozen=True)
class PublicationRequest:
    payload_json: str

    @property
    def request_digest(self) -> str:
        return content_identity(self.to_dict())

    @property
    def patch_identity(self) -> str:
        return content_identity(self.to_dict()["changes"])

    @property
    def assignment_id(self) -> str:
        return self.to_dict()["assignment_id"]

    @property
    def inputs(self) -> InputManifest:
        return InputManifest.from_dict(self.to_dict()["inputs"])

    @property
    def fixture(self) -> Fixture:
        value = self.to_dict()["fixture"]
        return Fixture(Path(value["repository"]), Path(value["remote"]), Path(value["evidence_dir"]), value["branch"])

    @property
    def publication_target(self) -> dict[str, str]:
        fixture = self.fixture
        return {"repository": str(fixture.repository.resolve()),
                "remote": str(fixture.remote.resolve()), "branch": fixture.branch}

    def to_dict(self) -> dict[str, Any]:
        return json.loads(self.payload_json)

    @classmethod
    def from_dict(cls, value: Mapping[str, Any]) -> "PublicationRequest":
        if set(value) != {"schema", "assignment_id", "fixture", "prepared_head", "changes", "inputs"} or value["schema"] != 1:
            raise PublicationError("Unsupported publication request schema")
        assignment = value["assignment_id"]
        if not isinstance(assignment, str) or not assignment or any(ord(c) < 32 for c in assignment):
            raise PublicationError("Invalid immutable assignment identity")
        InputManifest.from_dict(value["inputs"])
        if not value["changes"]:
            raise PublicationError("An assignment publication must contain changes")
        names = set()
        for name, change in value["changes"].items():
            relative_path(name)
            if name.casefold() in names:
                raise PublicationError("Case-colliding publication paths")
            names.add(name.casefold())
            if set(change) != {"before", "after"} or set(change["after"]) != {"sha256", "size"}:
                raise PublicationError("Invalid approved change identity")
            if name not in InputManifest.from_dict(value["inputs"]).paths:
                raise PublicationError("Every published path must be a verified relevant input")
        return cls(canonical_json(dict(value)))


def prepare_publication(fixture: Fixture, assignment_id: str, owned_paths: Sequence[str], inputs: InputManifest) -> PublicationRequest:
    """Bind reviewed raw postimages and committed preimages; never apply a patch."""
    # Read-only preparation still refuses arbitrary repository identities.
    scope = FixtureScope(fixture.root.parent.parent)
    validate_fixture(scope, fixture)
    validation = validate_inputs(fixture.repository, inputs)
    if not validation.valid:
        raise PublicationError(f"Relevant verification inputs changed: {validation.changed}")
    if len(owned_paths) != len(set(owned_paths)):
        raise PublicationError("Duplicate owned publication paths")
    head = _text(fixture.repository, ["rev-parse", "refs/heads/main"], fixture.evidence_dir, record=False)
    changes: dict[str, Any] = {}
    for path in sorted(owned_paths):
        actual = input_path(fixture.repository, path)
        before = _entry(fixture, head, path, record=False)
        blob = _text(fixture.repository, ["hash-object", "--no-filters", "--stdin"],
                     fixture.evidence_dir, data=actual.read_bytes(), record=False)
        if before is not None and before["blob"] == blob:
            raise PublicationError(f"Declared publication path has no change: {path}")
        changes[path] = {"before": before, "after": file_identity(actual)}
    return PublicationRequest.from_dict({"schema": 1, "assignment_id": assignment_id,
        "fixture": {"repository": str(fixture.repository), "remote": str(fixture.remote),
                    "evidence_dir": str(fixture.evidence_dir), "branch": fixture.branch},
        "prepared_head": head, "changes": changes, "inputs": inputs.to_dict()})


@dataclass(frozen=True)
class PublicationResult:
    assignment_id: str
    commit_id: str
    pushed: bool
    remote_head: str | None
    recovered: bool
    observation_ref: str
    push_error: str | None = None


@contextlib.contextmanager
def _publication_lock(path: Path) -> Iterator[None]:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as stream:
        if stream.tell() == 0:
            stream.write(b"\0")
            stream.flush()
        stream.seek(0)
        try:
            if os.name == "nt":
                import msvcrt
                msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError as error:
            raise PublicationError("Another fixture commit/push is in progress") from error
        try:
            yield
        finally:
            stream.seek(0)
            if os.name == "nt":
                msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(stream.fileno(), fcntl.LOCK_UN)


class GitPublisher:
    def __init__(self, scope: FixtureScope, ledger: Any, evidence_dir: str | Path):
        self.scope = scope
        self.ledger = ledger
        self.evidence_dir = scope.check_path(evidence_dir)

    def _authorize(self, revision: int) -> None:
        self.ledger.require_operation("publish", authorization_revision=revision)

    def _approved(self, request: PublicationRequest) -> None:
        assignment = self.ledger.assignment(request.assignment_id)
        review = assignment.get("review") or {}
        materialization = assignment.get("materialization") or {}
        selection = assignment.get("selection")
        verification = selection or assignment.get("verification") or {}
        if verification.get("valid") is False:
            raise PublicationError("Relevant input evidence was invalidated")
        if not selection and verification.get("valid") is not True:
            raise PublicationError("Current measured verification is required")
        if selection and (selection.get("accepted_credit") != 0 or not selection.get("fallback_ref")):
            raise PublicationError("Nonmatching publication must preserve fallback and zero accepted credit")
        if not review.get("approved_by") or not review.get("evidence_refs"):
            raise PublicationError("Parent-approved review evidence is required")
        for approval in (review, materialization):
            if (approval.get("publication_target") != request.publication_target or
                    approval.get("request_digest") != request.request_digest):
                raise PublicationError("Review and materialization must bind the exact publication request and target")
        if any(record.get("input_identity") != request.inputs.identity for record in (review, materialization, verification)):
            raise PublicationError("Verification, review and materialization must bind these exact inputs")
        if materialization.get("patch_identity") != request.patch_identity or not materialization.get("evidence_refs"):
            raise PublicationError("Owner-materialized changes do not match the approved publication")
        if materialization.get("owner_id") != assignment.get("owner_id"):
            raise PublicationError("Only the original/current owner may materialize an assignment")
        if assignment.get("status") not in {"publication_wait", "committed", "pushed", "publication_acknowledged", "cleanup", "closed"}:
            raise PublicationError("Assignment is not ready for source publication")

    def _record(self, request: PublicationRequest, event: str, /, **fields: Any) -> dict[str, Any]:
        return self.ledger.record_publication(request.assignment_id, event_id=event, record={
            "request_digest": request.request_digest, "patch_identity": request.patch_identity,
            "input_identity": request.inputs.identity, "branch": request.fixture.branch,
            "remote": str(request.fixture.remote), "publication_target": request.publication_target, **fields})

    def _validate_current_inputs(self, request: PublicationRequest, event_id: str) -> None:
        validation = validate_inputs(request.fixture.repository, request.inputs)
        if validation.valid:
            return
        directory = self.scope.check_path(self.evidence_dir / request.request_digest)
        directory.mkdir(parents=True, exist_ok=True)
        report = self.scope.check_path(directory / f"invalid-{uuid.uuid4().hex[:16]}.json")
        report.write_text(canonical_json({
            "expected_identity": request.inputs.identity, "current_identity": validation.current_identity,
            "changed": validation.changed, "observed_at_ns": time.time_ns()}), encoding="utf-8")
        identity = validation.current_identity or content_identity({
            "invalid_inputs": validation.changed, "expected_identity": request.inputs.identity})
        self.ledger.check_input_identity(request.assignment_id,
            event_id=f"{event_id}:invalid-inputs:{uuid.uuid4().hex}",
            input_identity=identity, evidence_ref=str(report))
        raise PublicationError(f"Relevant inputs require re-verification: {validation.changed}")

    def _bound_effects(self, request: PublicationRequest, intent: Mapping[str, Any]) -> list[dict[str, Any]]:
        if (intent.get("request_digest") != request.request_digest or
                intent.get("publication_target") != request.publication_target):
            raise PublicationError("Recorded publication intent belongs to a different request or target")
        effects = self.ledger.publication_effects(request.assignment_id)
        for effect in effects:
            if (effect.get("request_digest") != request.request_digest or
                    effect.get("target") != request.publication_target or
                    effect.get("planned_commit") != intent.get("planned_commit")):
                raise PublicationError("Publication admission does not match its immutable intent")
        return sorted(effects, key=lambda effect: (effect["admitted_at"], effect["effect_id"]))

    def _admit(self, request: PublicationRequest, kind: str, planned: str,
               revision: int, event_id: str) -> dict[str, Any]:
        effect_id = content_identity({"request_digest": request.request_digest,
                                      "event_id": event_id, "kind": kind})
        return self.ledger.admit_publication_effect(request.assignment_id,
            effect_id=effect_id, kind=kind, request_digest=request.request_digest,
            target=request.publication_target, planned_commit=planned,
            authorization_revision=revision, event_id=f"{event_id}:admit:{kind}")

    def _observe_commit(self, request: PublicationRequest, effect: Mapping[str, Any],
                        observations: Path, event_id: str, *, crash: bool = False) -> tuple[str, bool]:
        fixture = request.fixture
        head = _text(fixture.repository, ["rev-parse", f"refs/heads/{fixture.branch}"], observations)
        ancestry = _git(fixture.repository,
            ["merge-base", "--is-ancestor", effect["planned_commit"], head], observations, check=False)
        if ancestry.returncode not in (0, 1):
            raise PublicationError("Cannot establish the actual admitted commit's ancestry")
        present = ancestry.returncode == 0
        if crash and present:
            raise InjectedCrash("Real commit observed; admitted outcome acknowledgment intentionally interrupted")
        record = {"local_head": head, "effect_observed": present,
                  "observation_ref": str(observations / "git-observations.jsonl")}
        if present:
            record["commit"] = effect["planned_commit"]
        self.ledger.observe_publication_effect(request.assignment_id, effect_id=effect["effect_id"],
            event_id=f"{event_id}:commit-observation:{uuid.uuid4().hex}", record=record)
        return head, present

    def _observe_push(self, request: PublicationRequest, effect: Mapping[str, Any],
                      observations: Path, event_id: str, *,
                      push_error: str | None = None) -> tuple[str | None, bool, str | None]:
        remote_head, pushed = self._remote_observation(request.fixture, effect["planned_commit"], observations)
        error = None if pushed else push_error
        self.ledger.observe_publication_effect(request.assignment_id, effect_id=effect["effect_id"],
            event_id=f"{event_id}:push-observation:{uuid.uuid4().hex}", record={
                "commit": effect["planned_commit"], "pushed": pushed,
                "remote_head": remote_head, "remote_contains_commit": pushed,
                "effect_observed": pushed, "push_error": error,
                "observation_ref": str(observations / "git-observations.jsonl")})
        return remote_head, pushed, error

    def recover(self, request: PublicationRequest, *, event_id: str) -> PublicationResult | None:
        """Observe previously admitted effects, including after STOP; never execute.

        Recovery intentionally does not revalidate current source bytes or current
        review status: it records historical Git outcomes, not new acceptance.
        None means no admitted commit is observable on either recorded ref.
        """
        request = PublicationRequest.from_dict(request.to_dict())
        self.scope.require_write()
        validate_fixture(self.scope, request.fixture)
        with _publication_lock(self.scope.check_path(self.scope.evaluation_root / "publication.lock")):
            intent = self.ledger.publication(request.assignment_id)
            if intent is None:
                return None
            effects = self._bound_effects(request, intent)
            commits = [effect for effect in effects if effect["kind"] == "commit"]
            pushes = [effect for effect in effects if effect["kind"] == "push"]
            if not commits:
                if pushes:
                    raise PublicationError("Push admission lacks its preceding admitted commit")
                return None
            observations = self.scope.check_path(Path(intent["observation_ref"]).parent)
            _, committed = self._observe_commit(request, commits[-1], observations, event_id)
            remote_head, pushed, error = None, False, None
            if pushes:
                remote_head, pushed, error = self._observe_push(
                    request, pushes[-1], observations, event_id, push_error=intent.get("push_error"))
            if not committed and not pushed:
                return None
            return PublicationResult(request.assignment_id, intent["planned_commit"], pushed,
                remote_head, True, str(observations / "git-observations.jsonl"), error)

    def publish(self, request: PublicationRequest, *, event_id: str, fault_at: str | None = None) -> PublicationResult:
        if fault_at not in {None, "after_commit", "after_push"}:
            raise PublicationError("Unknown exercise crash boundary")
        request = PublicationRequest.from_dict(request.to_dict())
        self.scope.require_write()
        fixture = request.fixture
        validate_fixture(self.scope, fixture)
        self.scope.check_path(self.evidence_dir)
        revision = self.ledger.authorization()["revision"]
        self._authorize(revision)
        self._approved(request)
        with _publication_lock(self.scope.check_path(self.scope.evaluation_root / "publication.lock")):
            self._authorize(revision)
            validate_fixture(self.scope, fixture)
            self._approved(request)
            previous = self.ledger.publication(request.assignment_id)
            if previous and previous.get("request_digest") != request.request_digest:
                raise PublicationError("An assignment cannot publish two different requests")
            self._validate_current_inputs(request, event_id)
            changes = request.to_dict()["changes"]
            for path, change in changes.items():
                if file_identity(input_path(fixture.repository, path)) != change["after"]:
                    raise PublicationError(f"Materialized postimage changed: {path}")
            observation_dir = self.scope.check_path(
                Path(previous["observation_ref"]).parent if previous and previous.get("observation_ref")
                else self.evidence_dir / request.request_digest)
            observation_dir.mkdir(parents=True, exist_ok=True)
            observation_ref = str(observation_dir / "git-observations.jsonl")
            ref = f"refs/heads/{fixture.branch}"
            head = _text(fixture.repository, ["rev-parse", ref], observation_dir)
            recovered = bool(previous)
            if previous and previous.get("planned_commit"):
                planned = previous["planned_commit"]
                expected_tree = previous["tree"]
                base = previous["base_head"]
                if _text(fixture.repository, ["rev-parse", f"{planned}^{{tree}}"], observation_dir) != expected_tree:
                    raise PublicationError("Recorded planned commit has an unexpected tree")
                if _text(fixture.repository, ["rev-parse", f"{planned}^"], observation_dir) != base:
                    raise PublicationError("Recorded planned commit has an unexpected parent")
            else:
                if previous and previous.get("commit"):
                    raise PublicationError("Committed publication lacks its durable recovery intent")
                base = head
                for path, change in changes.items():
                    if _entry(fixture, base, path) != change["before"]:
                        raise PublicationError(f"Committed owned-path preimage changed: {path}")
                    staged = _git(fixture.repository, ["ls-files", "--stage", "-z", "--", path], observation_dir).stdout
                    expected = change["before"]
                    expected_stage = (f"{expected['mode']} {expected['blob']} 0\t{path}\0".encode("utf-8") if expected else b"")
                    if staged != expected_stage:
                        raise PublicationError(f"Independently staged owned-path contents: {path}")
                index = observation_dir / f"index-{uuid.uuid4().hex}"
                private = {"GIT_INDEX_FILE": str(index)}
                _git(fixture.repository, ["read-tree", base], observation_dir, extra=private)
                expected_entries = []
                for path, change in changes.items():
                    raw = input_path(fixture.repository, path).read_bytes()
                    import hashlib
                    if {"sha256": hashlib.sha256(raw).hexdigest(), "size": len(raw)} != change["after"]:
                        raise PublicationError(f"Materialized file changed during publication: {path}")
                    blob = _text(fixture.repository, ["hash-object", "-w", "--no-filters", "--stdin"], observation_dir, data=raw)
                    _git(fixture.repository, ["update-index", "--add", "--cacheinfo", f"100644,{blob},{path}"], observation_dir, extra=private)
                    expected_entries.append(f"100644 {blob} 0\t{path}\0".encode("utf-8"))
                actual_entries = _git(fixture.repository,
                    ["ls-files", "--stage", "-z", "--", *sorted(changes)],
                    observation_dir, extra=private).stdout
                if actual_entries != b"".join(expected_entries):
                    raise PublicationError("Private index modes, stage-0 blobs or owned paths do not match approval")
                actual_paths = _git(fixture.repository, ["diff-index", "--cached", "--name-only", "--no-renames", "-z", base, "--"], observation_dir, extra=private).stdout
                if actual_paths != b"".join(path.encode("utf-8") + b"\0" for path in sorted(changes)):
                    raise PublicationError("Private index is not exactly one assignment's declared changes")
                expected_tree = _text(fixture.repository, ["write-tree"], observation_dir, extra=private)
                timestamp = int(time.time())
                message = (f"Publish evaluation assignment {request.assignment_id}\n\n"
                           f"OMP-Evaluation-Assignment: {request.assignment_id}\n"
                           f"OMP-Evaluation-Request: {request.request_digest}\n")
                dates = {"GIT_AUTHOR_DATE": f"{timestamp} +0000", "GIT_COMMITTER_DATE": f"{timestamp} +0000"}
                self._authorize(revision)
                planned = _text(fixture.repository, ["commit-tree", expected_tree, "-p", base, "-m", message], observation_dir, extra=dates)
                self._record(request, f"{event_id}:intent", base_head=base, tree=expected_tree,
                             commit_message=message, commit_timestamp=timestamp, planned_commit=planned,
                             private_index=str(index), private_index_entries=actual_entries.decode("utf-8"),
                             request=request.to_dict(), pushed=False, observation_ref=observation_ref)
            self._validate_current_inputs(request, event_id)
            intent = self.ledger.publication(request.assignment_id)
            effects = self._bound_effects(request, intent)
            commit_effects = [effect for effect in effects if effect["kind"] == "commit"]
            push_effects = [effect for effect in effects if effect["kind"] == "push"]
            present = _git(fixture.repository, ["merge-base", "--is-ancestor", planned, head], observation_dir, check=False)
            if present.returncode not in (0, 1):
                raise PublicationError("Cannot establish the actual publication ancestry")
            if present.returncode == 1:
                if head != base or intent.get("commit"):
                    raise PublicationError("Local branch moved away from the recorded publication; owner reconciliation is required")
                commit_effect = self._admit(request, "commit", planned, revision, event_id)
                if not commit_effect["execute"]:
                    self._observe_commit(request, commit_effect, observation_dir, event_id)
                    raise PublicationError("Recovered admission cannot execute again; a fresh authorized event is required")
                # Admission is the durable ordering point. STOP may now win
                # before this command, but this one admitted effect may finish.
                # Its observation must survive STOP; a later push needs its own
                # fresh admission. No ledger transaction spans native Git.
                try:
                    _git(fixture.repository, ["update-ref", ref, planned, base], observation_dir, check=False)
                except (OSError, subprocess.TimeoutExpired, PublicationError):
                    self._observe_commit(request, commit_effect, observation_dir, event_id)
                    raise
            else:
                if not commit_effects:
                    raise PublicationError("Visible commit has no durable publication admission")
                commit_effect = commit_effects[-1]
            _, committed = self._observe_commit(request, commit_effect, observation_dir, event_id,
                                                 crash=fault_at == "after_commit")
            if not committed:
                raise PublicationError("Git did not expose the admitted commit on the publication branch")
            remote_head, pushed = self._remote_observation(fixture, planned, observation_dir)
            push_error = intent.get("push_error")
            if pushed and push_effects:
                push_effect = push_effects[-1]
            else:
                self._validate_current_inputs(request, event_id)
                push_effect = self._admit(request, "push", planned, revision, event_id)
                if push_effect["execute"] and not pushed:
                    try:
                        pushed_process = _git(fixture.repository,
                            ["push", "--porcelain", str(fixture.remote), f"{planned}:{ref}"],
                            observation_dir, check=False)
                    except (OSError, subprocess.TimeoutExpired, PublicationError) as error:
                        self._observe_push(request, push_effect, observation_dir, event_id, push_error=str(error))
                        raise
                    if pushed_process.returncode:
                        push_error = pushed_process.stderr.decode("utf-8", "replace").strip() or "Git refused publication"
                    elif fault_at == "after_push":
                        raise InjectedCrash("Real push returned success; admitted outcome acknowledgment intentionally interrupted")
            remote_head, pushed, push_error = self._observe_push(
                request, push_effect, observation_dir, event_id, push_error=push_error)
            return PublicationResult(request.assignment_id, planned, pushed, remote_head, recovered, observation_ref, push_error)

    @staticmethod
    def _remote_observation(fixture: Fixture, commit: str, observations: Path) -> tuple[str | None, bool]:
        output = _text(fixture.repository, ["ls-remote", "--heads", str(fixture.remote), f"refs/heads/{fixture.branch}"], observations)
        if not output:
            return None, False
        lines = output.splitlines()
        if len(lines) != 1 or lines[0].split()[1] != f"refs/heads/{fixture.branch}":
            raise PublicationError("Ambiguous remote branch observation")
        remote_head = lines[0].split()[0]
        if remote_head == commit:
            return remote_head, True
        present = _git(fixture.remote, ["cat-file", "-e", f"{commit}^{{commit}}"], observations, bare=True, check=False)
        if present.returncode:
            return remote_head, False
        ancestry = _git(fixture.remote, ["merge-base", "--is-ancestor", commit, remote_head], observations, bare=True, check=False)
        if ancestry.returncode not in (0, 1):
            raise PublicationError("Could not verify actual remote ancestry")
        return remote_head, ancestry.returncode == 0
