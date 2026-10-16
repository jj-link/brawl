"""Four retained native owners and automatic independently owned trial workflow."""
from __future__ import annotations

from concurrent.futures import ThreadPoolExecutor
import hashlib
import http.client
import json
from pathlib import Path
import sys
import threading
import time
import uuid

from .runtime import EvaluationRuntime
from .safety import ACTIVE, SafetyError, confined, digest, now, save_json
from .trial_rpc import launch_root, validate_runtime_identity
from .trial_authority import validate_approval, require_fresh_workspace
from .processes import owned_listener
from .trial_identity import validate_child, native_process_identity
from .trial_registration import RegistrationAdapter
from .evidence import file_identity, input_path


def observation(refs, **values):
    return {"observed_at": now(), "timestamp_provenance": {"source": "bounded-native-runtime", "clock_id": "host-utc"},
            "evidence_refs": [str(ref) for ref in refs], **values}


def owner_reporting_argv(run_id):
    return [sys.executable, "-P", "-B", "-m", "tools.orchestration_eval.trial", "report",
            "--run-id", run_id, "--authorize-owner-observation", "--envelope"]


def delivery_bytes(envelope: dict) -> bytes:
    return (json.dumps(envelope, sort_keys=True, allow_nan=False) + "\n").encode("utf-8")


def consume_delivery(ledger, envelope, raw=None):
    identifier = envelope["event_id"]
    admitted = ledger.trial_delivery(identifier)
    return ledger.consume_trial_delivery(event_id=identifier, role=admitted["role"], envelope=envelope,
        content_sha256=hashlib.sha256(raw if raw is not None else delivery_bytes(envelope)).hexdigest())


def immutable_json(path: Path, value: dict):
    path = confined(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("x", encoding="utf-8", newline="\n") as stream:
        json.dump(value, stream, sort_keys=True)
        stream.write("\n")
        stream.flush()
        import os
        os.fsync(stream.fileno())


class TrialRuntime(EvaluationRuntime):
    def __init__(self, root, ledger, executable, launch_contract):
        super().__init__(root, ledger)
        trial = ledger.snapshot()["trial"]
        self.manifest, self.manifest_digest = trial["manifest"], trial["manifest_digest"]
        self.executable, self.launch_contract = executable, launch_contract
        self.roots, self.ready, self.offsets, self.observed = {}, {}, {}, set()
        self.observer_initialized = {}
        self.slots, self.prepared, self.handled = {}, set(), set()
        self.held = set()
        self.refill_pool = ThreadPoolExecutor(max_workers=4, thread_name_prefix="trial-refill")
        self.refill_jobs, self.refill_slots, self.refill_failures = {}, {}, {}
        self.refill_visible = set()
        from .trial_workflow import TrialWorkflow
        self.workflow = TrialWorkflow(self)
        self.registrations = RegistrationAdapter(self)

    def snapshot(self, label):
        from .trial_metrics import trial_report
        value = self.ledger.snapshot()
        value.update(observed_at=now(), label=label, process_registry=self.manager.records(),
                     runtime_roots=self.ready, metrics=trial_report(value),
                     reconstruction_semantics="Credit requires verified source, independent review, actual controller Git publication and native exit")
        save_json(self.root / "status.json", value)
        save_json(self.root / "snapshots" / (label + ".json"), value)
        return value

    def prepare(self, reservation, slot):
        validate_approval(self.manifest, self.launch_contract)
        validate_runtime_identity(self.executable, self.launch_contract["runtime"])
        key = reservation["assignment_id"]
        if key in self.prepared:
            raise SafetyError("Native assignment preparation cannot be repeated")
        self.prepared.add(key)
        directory = self.root / "native" / uuid.uuid4().hex
        revision = self.ledger.authorization()["revision"]
        spec = {"assignment_id": key, "manifest_digest": self.manifest_digest,
                "execution": self.manifest["execution"], "observer": self.launch_contract["observer"],
                "session_directory": self.launch_contract["session_directory"],
                "agent_definition": self.launch_contract["agent_definition"],
                "runtime": self.launch_contract["runtime"],
                "ledger_path": str(self.ledger.path), "authorization_revision": revision}
        workflow = self.ledger.snapshot()["trial"]["workflow"]
        spec["workflow_config_digest"] = workflow["config_digest"]
        spec["review"] = {"execution": workflow["config"]["profile"]["review"],
                          "model_definition": self.launch_contract["review_model_definition"]}
        rpc, ready = launch_root(self.manager, self.executable, directory, spec,
                                 self.launch_contract["model_definition"], revision)
        self.register_process(rpc.owned, revision)
        child_path = Path(rpc.owned.record["record_path"]).parent / "child.json"
        child = json.loads(child_path.read_text(encoding="utf-8"))
        if child["pid"] != ready["pid"]:
            raise SafetyError("Native root readiness and owned child PID disagree")
        child.update(native_process_identity(rpc.owned, ready["pid"], self.executable))
        native_path = directory / "native-process.json"
        immutable_json(native_path, child)
        ready.update(native_process=child, wrapper_process=rpc.owned.record,
                     native_process_ref=str(native_path), wrapper_child_ref=str(child_path))
        self.roots[key], self.ready[key], self.slots[key] = rpc, ready, slot
        self.offsets[key] = 0
        immutable_json(directory / "reservation.json", reservation)
        return ready

    def prepare_initial(self):
        # A missing parent becoming present during Windows realpath can retain
        # its extended prefix. Establish it before the four guarded resolutions.
        confined(self.root / "native", self.root).mkdir()
        # All four prompt-free root handshakes are independent. No provider work.
        with ThreadPoolExecutor(max_workers=4, thread_name_prefix="trial-prepare") as pool:
            futures = [pool.submit(self.prepare, row, slot)
                       for slot, row in enumerate(self.manifest["reservations"][:4])]
            for future in futures:
                future.result()
        return self.snapshot("four-native-roots-prepared")

    def prepare_observers_and_children(self):
        self.registrations.authority()
        keys = [row["assignment_id"] for row in self.manifest["reservations"][:4]]
        with ThreadPoolExecutor(max_workers=4, thread_name_prefix="trial-observe") as pool:
            futures = {key: pool.submit(self.register_observe, key) for key in keys}
            listeners = {key: future.result() for key, future in futures.items()}
        path = self.root / "automatic-initial-listeners.json"
        immutable_json(path, {"manifest_digest": self.manifest_digest, "listeners": listeners,
                             "observed_at": now(), "provider_requests_released": False})
        return self.prepare_children({
            "manifest_digest": self.manifest_digest, "confirmed_by": self.manifest["coordinator_id"],
            "coordinator_ref": self.launch_contract["approval_packet"]["path"],
            "execution_ref": str(self.root / "launch-contract.json"), "dashboard_ref": str(path),
            "evidence_refs": [str(path), str(self.registrations.root / "authority.json")],
        })

    def native_command(self, key, operation, **values):
        rpc = self.roots[key]
        self.ledger.require_operation("launch", authorization_revision=self.ledger.authorization()["revision"])
        identifier = uuid.uuid4().hex
        request = {"id": identifier, "operation": operation, "assignment_id": key,
                   "manifest_digest": self.manifest_digest,
                   "root_session_id": self.ready[key]["root_session_id"], **values}
        path = rpc.directory / ("command-" + identifier + ".json")
        immutable_json(path, request)
        rpc.local_command(path)
        return identifier, path

    def await_native_result(self, key, identifier, *, timeout=30):
        rpc = self.roots[key]
        path = rpc.directory / ("result-" + identifier + ".json")
        deadline = time.monotonic() + timeout
        while not path.with_name(path.name + ".complete").exists():
            if rpc.failure:
                raise rpc.failure
            if rpc.owned.process.poll() is not None:
                raise SafetyError("Native root exited before its command outcome")
            if time.monotonic() >= deadline:
                raise TimeoutError("Native command outcome unknown; never replay")
            time.sleep(0.05)
        result = json.loads(path.read_text(encoding="utf-8"))
        if result.get("id") != identifier or result.get("success") is not True:
            raise SafetyError(f"Native local command failed: {result}")
        return result, path

    def observe(self, key, port):
        if key not in self.observer_initialized:
            identifier, _ = self.native_command(key, "observe", port=port)
            result, path = self.await_native_result(key, identifier)
            # A successful native import is never replayed. The original observer's
            # own timer observes an exact owned-row port change after a real race.
            self.observer_initialized[key] = result
            self.ready[key]["observer_evidence"] = str(path)
        self.ready[key]["observer_port"] = port
        proof = self.verify_observer(key)
        self.observed.add(key)
        return {"native_command": self.observer_initialized[key], "owned_listener": proof, "ready": True}

    def verify_observer(self, key, *, require_child=False, reviewer_session=None):
        rpc = self.roots[key]
        port = self.ready[key]["observer_port"]
        if not isinstance(port, int) or port < 1 or port > 65535 or port in {8765, 8766}:
            raise SafetyError("Protected or invalid observer port")
        deadline = time.monotonic() + 5
        while not owned_listener(rpc.owned, port):
            if rpc.owned.process.poll() is not None or time.monotonic() >= deadline:
                raise SafetyError("Observer factory returned without an owned listener")
            time.sleep(0.05)
        connection = http.client.HTTPConnection("127.0.0.1", port, timeout=1)
        try:
            connection.request("GET", "/status")
            response = connection.getresponse()
            raw = response.read(65537)
            if response.status != 200 or len(raw) > 65536:
                raise SafetyError("Owned observer did not return a bounded successful identity response")
            status = json.loads(raw)
        finally:
            connection.close()
        child = json.loads((Path(rpc.owned.record["record_path"]).parent / "child.json").read_text(encoding="utf-8"))
        if (not owned_listener(rpc.owned, port) or status.get("connected") is not True or
                status.get("pid") != child["pid"] or status.get("rootSessionId") != self.ready[key]["root_session_id"]):
            raise SafetyError("Observer listener/root/native PID identity changed")
        if require_child:
            membership = status.get("membership") or {}
            session = self.ledger.assignment(key)["session_id"]
            expected = {session, self.ready[key]["root_session_id"]}
            if reviewer_session is not None:
                if not isinstance(reviewer_session, str) or not reviewer_session or reviewer_session in expected:
                    raise SafetyError("Reviewer visibility requires its distinct attached native session")
                expected.add(reviewer_session)
            if (membership.get("source") != "runner-registry" or membership.get("complete") is not True or
                    {row["id"] for row in membership.get("agents", [])} != expected):
                raise SafetyError("Owned listener lacks the exact genuine held child membership")
        proof = {"port": port, "observed_at": now(), "status": status, "native_job": rpc.owned.process_id,
                 "qualification": "Owned listener/root identity, not proof of SSE model deltas"}
        immutable_json(self.root / "observer-proofs" / (uuid.uuid4().hex + ".json"), proof)
        return proof

    def _claim(self, key):
        return {"assignment_id": key, "owner_id": "QwenTrial" + uuid.uuid4().hex[:20],
                "root_session_id": self.ready[key]["root_session_id"], "slot": self.slots[key]}

    def prepare_children(self, gates):
        if self.ledger.snapshot()["trial"]["workflow"]["target_prepared"] is None:
            raise SafetyError("Independent target setup must complete before any owner claim")
        keys = [row["assignment_id"] for row in self.manifest["reservations"][:4]]
        if set(keys) - self.observed:
            raise SafetyError("All four actual native roots need registered observers before activation")
        for key in keys:
            self.verify_observer(key)
        revision = self.ledger.authorization()["revision"]
        self.ledger.prepare_trial(gates=gates, event_id="trial-child-preparation", authorization_revision=revision)
        self.ledger.claim_trial_initial(claims=[self._claim(key) for key in keys],
                                        event_id="four-initial-claims", authorization_revision=revision)
        barrier = threading.Barrier(4)
        with ThreadPoolExecutor(max_workers=4, thread_name_prefix="trial-initial") as pool:
            futures = [pool.submit(self.start_assignment, key, barrier) for key in keys]
            for future in futures:
                future.result()
        return self.snapshot("four-native-children-preparing")

    def activate(self, gates):
        keys = [row["assignment_id"] for row in self.manifest["reservations"][:4]]
        if set(keys) - self.held:
            raise SafetyError("All four genuine children must be held before their first native provider call")
        revision = self.ledger.authorization()["revision"]
        self.ledger.activate_trial(gates=gates, event_id="trial-provider-activation", authorization_revision=revision)
        admitted = self.ledger.admit_trial_prompts(effect_ids={key: key + "-initial" for key in keys},
            event_id="four-initial-provider-admissions", authorization_revision=revision)
        if not admitted["execute"]:
            raise SafetyError("Initial provider admissions already consumed; never replay")
        barrier = threading.Barrier(4)
        with ThreadPoolExecutor(max_workers=4, thread_name_prefix="trial-release") as pool:
            futures = [pool.submit(self.release_provider, key, barrier) for key in keys]
            for future in futures:
                future.result()
        return self.snapshot("four-original-prompts-released")

    def release_provider(self, key, barrier=None):
        snapshot = self.ledger.snapshot()
        assignment = snapshot["assignments"][key]
        if key not in self.held or not assignment["session_id"]:
            raise SafetyError("Native child has not reached its premodel gate")
        trial = snapshot["trial"]
        resolution = trial.get("history_resolutions", {}).get(key)
        history = resolution["history"] if resolution else assignment["identity"]["reservation"]["history"]
        if history["status"] not in {"known", "recorded"}:
            raise SafetyError("Provider release requires coordinator-resolved history, never inferred counts")
        revision = snapshot["authorization"]["revision"]
        self.ledger.require_operation("reconstruct", authorization_revision=revision)
        effect = trial["effects"].get(key + "-initial")
        if not effect or effect["assignment_id"] != key or effect["kind"] != "prompt" or effect["authorization_revision"] != revision:
            raise SafetyError("Canonical dispatch history requires this owner's admitted original prompt")
        self.verify_observer(key, require_child=True)
        immutable_json(self.roots[key].directory / "dispatch-history.json", {
            "assignment_id": key, "owner_id": assignment["owner_id"], "session_id": assignment["session_id"],
            "root_session_id": trial["claims"][key]["root_session_id"],
            "manifest_digest": trial["manifest_digest"], "authorization_revision": revision,
            "original_reservation_ref": str(self.roots[key].directory / "reservation.json"),
            "effective_history": history, "history_resolution": resolution, "provider_admission": effect,
        })
        if barrier:
            barrier.wait(timeout=30)
        identifier, path = self.native_command(key, "release", session_id=assignment["session_id"])
        result, receipt = self.await_native_result(key, identifier)
        self.ledger.observe_trial_effect(effect_id=key + "-initial", event_id=identifier + "-released",
            record=observation([path, receipt], effect_observed=True, outcome="original_native_prompt_released"))
        self.ledger.trial_event(key, kind="phase", event_id=identifier + "-phase",
            record=observation([receipt], owner_id=assignment["owner_id"], phase="reconstruction"))
        self.held.remove(key)
        return result

    def workspace_command(self, argv, revision, *, allowed=(0,)):
        if argv[0] == "git":
            argv = ["git", "-c", "core.longpaths=true", *argv[1:]]
        owned = self.manager.launch(argv, kind="assignment-workspace-setup", cwd=self.root,
                                    authorization_revision=revision)
        try:
            self.register_process(owned, revision)
            code = owned.process.wait(timeout=60)
        finally:
            proof = owned.stop(grace=0)
            if proof["process_id"] in self.ledger.snapshot()["processes"]:
                self.ledger.record_process_exit(proof["process_id"], event_id="exit-" + proof["process_id"], proof=proof)
        logs = Path(owned.record["record_path"]).parent
        if code not in allowed:
            raise SafetyError(f"Native workspace setup failed; preserve {logs}")
        return (logs / "stdout.log").read_text(encoding="utf-8").strip()

    def create_workspace(self, key, reservation, revision):
        workspace = require_fresh_workspace(reservation)
        workflow = self.ledger.snapshot()["trial"]["workflow"]
        if workflow["target_prepared"] is None:
            raise SafetyError("Independent target must be prepared before owner workspace creation")
        repository = Path(workflow["config"]["publication_target"]["repository"])
        workspace.mkdir()
        directory_identity = workspace.stat().st_ino
        immutable_json(self.roots[key].directory / "workspace-reservation.json",
                       {"path": str(workspace), "directory_identity": directory_identity,
                        "baseline": reservation["baseline_commit"], "manifest_digest": self.manifest_digest})
        self.workspace_command(["git", "-c", "core.autocrlf=false", "-c", "core.eol=lf", "clone",
                                "--no-local", "--no-hardlinks", "--no-checkout", "--no-tags",
                                str(repository), str(workspace)], revision)
        self.workspace_command(["git", "-C", str(workspace), "remote", "remove", "origin"], revision)
        self.workspace_command(["git", "-C", str(workspace), "-c", "core.autocrlf=false", "-c", "core.eol=lf",
                                "checkout", "--detach", reservation["baseline_commit"]], revision)
        for item in workflow["config"]["verification"][key]["workspace_inputs"]:
            source = Path(item["source"])
            if file_identity(source) != item["identity"]:
                raise SafetyError("Approved read-only setup input changed")
            destination = input_path(workspace, item["destination"], must_exist=False)
            if destination.exists():
                if file_identity(destination) != item["identity"]:
                    raise SafetyError("Setup cannot overwrite an existing different workspace input")
                continue
            destination.parent.mkdir(parents=True, exist_ok=True)
            with source.open("rb") as reader, destination.open("xb") as writer:
                import shutil
                shutil.copyfileobj(reader, writer)
            if file_identity(destination) != item["identity"] or file_identity(source) != item["identity"]:
                raise SafetyError("Read-only input changed during private byte copy")
        values = self.workspace_identity(reservation, revision)
        if values["directory_identity"] != directory_identity:
            raise SafetyError("New workspace directory was replaced during creation")
        immutable_json(self.roots[key].directory / "workspace-identity.json", values)
        return values

    def workspace_identity(self, reservation, revision):
        workspace = confined(Path(reservation["workspace"]), ACTIVE / "build/isolated-workers")
        values = {}
        for label, arguments in (
            ("head", ["rev-parse", "HEAD"]),
            ("common", ["rev-parse", "--path-format=absolute", "--git-common-dir"]),
            ("index", ["rev-parse", "--path-format=absolute", "--git-path", "index"]),
            ("gitdir", ["rev-parse", "--absolute-git-dir"]),
            ("toplevel", ["rev-parse", "--show-toplevel"]),
        ):
            values[label] = self.workspace_command(["git", "-C", str(workspace), *arguments], revision)
        values["branch"] = self.workspace_command(
            ["git", "-C", str(workspace), "symbolic-ref", "--quiet", "HEAD"], revision, allowed=(1,))
        gitdir = confined(workspace / ".git", workspace)
        private_index = confined(Path(values["index"]), gitdir)
        if (values["head"] != reservation["baseline_commit"] or values["branch"] or not gitdir.is_dir() or
                Path(values["common"]).resolve() != gitdir or Path(values["gitdir"]).resolve() != gitdir or
                Path(values["toplevel"]).resolve() != workspace or private_index != gitdir / "index" or
                not private_index.is_file() or any((gitdir / name).exists() for name in
                    ("commondir", "gitdir", "objects/info/alternates", "objects/info/http-alternates"))):
            raise SafetyError("Workspace failed exact independent Git/index/object-store checks")
        values.update(directory_identity=workspace.stat().st_ino,
                      config_sha256=digest(gitdir / "config"), index_sha256=digest(private_index))
        return values

    def start_assignment(self, key, barrier=None):
        revision = self.ledger.authorization()["revision"]
        assignment = self.ledger.snapshot()["assignments"][key]
        reservation = assignment["identity"]["reservation"]
        require_fresh_workspace(reservation)
        validate_approval(self.manifest, self.launch_contract)
        validate_runtime_identity(self.executable, self.launch_contract["runtime"])
        launch = self.ledger.admit_trial_effect(key, effect_id=key + "-launch", kind="launch",
                                               event_id=key + "-launch-admission", authorization_revision=revision)
        if not launch["execute"]:
            raise SafetyError("Assignment admission was already consumed; no replay")
        if barrier:
            barrier.wait(timeout=30)
        self.ledger.require_operation("reconstruct", authorization_revision=revision)
        workspace_identity = self.create_workspace(key, reservation, revision)
        task = ("Complete this one reserved matching reconstruction assignment. Read canonical "
                f"{ACTIVE / 'PLAN.md'} before work, including Common execution, Git isolation, and Reconstruction agent. "
                "Carry forward all preserved per-model initial/correction counts. One initial continuation and at most ten "
                "total measured corrections in this Qwen stage; never reset inherited counts. Preserve every measured draft, "
                "recipe, target/best objects and comparison. Tool failures are blocked, not exhausted. Perform the canonical "
                "registered-object, data-relocation/source-link, all 127 binary hash checks and progress calculation privately. "
                "Do not commit/push or modify MAIN or the controller publication repository. The controller performs "
                "fixed verification, genuine independent review and separate real commit/push units automatically. "
                "Remain the same owner for concrete reconciliation and exact evidence-preserving cleanup. "
                "At the inherited correction bound retain the best NonMatching draft, original-code fallback and zero "
                "accepted credit; do not hand off to another model. Do not message agent://Main: it is this process's "
                "zero-inference control root. Use the exact durable delivery channel and native yield instead. "
                "No other model/child, no fabricated history or verification. Use absolute workspace paths for tools and explicit "
                "workspace cwd for every shell. The native root cwd is not your workspace. The runtime created your "
                "fresh independently owned repository and verified its Git identity; confirm that identity "
                "before edits, and never adopt a replaced workspace. Read your native identity/reporting contract from "
                f"{self.roots[key].directory / 'owner-identity.json'} after activation. "
                "Before reconstruction, read the canonical dispatch history written before your provider gate opens at "
                f"{self.roots[key].directory / 'dispatch-history.json'}. It binds your same owner/session and original prompt "
                "to the coordinator's append-only history resolution. Apply its recorded count scope exactly; inventory-scoped "
                "counts do not make lifetime totals known or create a fresh attempt allowance. The immutable original reservation "
                f"is retained at {self.roots[key].directory / 'reservation.json'}; its pending history is not the dispatch resolution. "
                "Record real attempt/verification/phase evidence as it occurs; missing timestamps remain missing.\n"
                "Before ending your turn, write evidence/controller-delivery.json in your workspace using the exact "
                "WorkerDelivery schema in tools/orchestration_eval/trial_delivery.py under the engineering workspace. "
                "It must name your actual measured candidate, complete InputManifest, raw/Git pre/postimages, all six "
                "retained artifacts, separate logical commit units covering every changed path exactly once, and an "
                "exact disposable-file list (possibly empty). This file is a delivery, not acceptance. "
                f"Schema source: {Path(__file__).with_name('trial_delivery.py')}. "
                + json.dumps({"assignment": {name: value for name, value in reservation.items() if name != "history"},
                              "original_reservation_ref": str(self.roots[key].directory / "reservation.json"),
                              "workspace_identity": workspace_identity}, indent=2))
        if self.workspace_identity(reservation, revision) != workspace_identity:
            raise SafetyError("Recorded Git/workspace identity changed before native dispatch")
        self.ledger.require_operation("reconstruct", authorization_revision=revision)
        identifier, path = self.native_command(key, "launch", owner_id=assignment["owner_id"],
            context=f"Bounded trial {self.manifest['trial_id']}; coordinator {self.manifest['coordinator_id']}. "
                    f"Manifest {self.manifest_digest}. Evidence inbox {self.root / 'inbox'}. "
                    "Return actual candidate/verification/phase receipts; agent success is not acceptance.", task=task)
        self.ledger.observe_trial_effect(effect_id=key + "-launch", event_id=identifier + "-sent",
            record=observation([path], effect_observed=True, outcome="native_child_preparation_command_accepted"))
        return {"command_id": identifier, "request_ref": str(path)}


    def collect_native(self):
        for key, rpc in list(self.roots.items()):
            if rpc.owned.record.get("exit_proof"):
                continue
            if rpc.failure:
                raise rpc.failure
            record_path = rpc.directory / "native-events.jsonl"
            if not record_path.exists():
                continue
            with record_path.open("rb") as stream:
                stream.seek(self.offsets[key])
                while True:
                    position = stream.tell()
                    raw = stream.readline()
                    if not raw or not raw.endswith(b"\n"):
                        self.offsets[key] = position
                        break
                    event = json.loads(raw)
                    self.offsets[key] = stream.tell()
                    if event["kind"] in {"provider_refused", "registry_error", "record_failure"}:
                        raise SafetyError(f"Native execution boundary failure: {event}")
                    if self.workflow.native_event(key, event, record_path, raw=raw):
                        continue
                    if event["kind"] == "local_result" and event["operation"] == "launch" and not event["success"]:
                        result_ref = confined(Path(event["result_ref"]), rpc.directory)
                        result = json.loads(result_ref.read_bytes())
                        if (result.get("id") != event["id"] or result.get("operation") != "launch"
                                or result.get("workflow_effect_id") != key + "-initial"
                                or event.get("workflow_effect_id") != key + "-initial"
                                or result.get("success") is not False):
                            raise SafetyError("Native launch failure differs from its retained admitted result")
                        self.ledger.observe_trial_effect(effect_id=key + "-launch",
                            event_id=event["id"] + "-native-failure",
                            record=observation([record_path, result_ref], effect_observed=True,
                                outcome="native_child_launch_failed", native_event=event, native_result=result))
                        raise SafetyError(f"Native child launch failed; retained result {result_ref}: "
                                          f"{result.get('error') or result.get('result')}")
                    if event["kind"] == "provider_gate_wait":
                        assignment = self.ledger.assignment(key)
                        if event.get("owner") != assignment["owner_id"] or assignment["session_id"] is None:
                            raise SafetyError("Premodel wait lacks an attached genuine native owner")
                        self.held.add(key)
                        self.ledger.trial_event(key, kind="phase", event_id=key + "-held-phase",
                            record={"observed_at": event["observed_at"], "owner_id": assignment["owner_id"],
                                    "timestamp_provenance": {"source": "native-premodel-gate", "clock_id": "host-utc"},
                                    "evidence_refs": [str(record_path)], "phase": "explicit_pause"})
                        continue
                    if event["kind"] not in {"registry", "child_gate_installed"} or event.get("native_kind") != "sub":
                        continue
                    snapshot = self.ledger.snapshot()
                    assignment = snapshot["assignments"].get(key)
                    if assignment is None:
                        raise SafetyError("Native child appeared before assignment admission")
                    if event["kind"] == "registry" and assignment["session_id"] is None:
                        if event.get("registry_id") != assignment["owner_id"]:
                            raise SafetyError("Unexpected native owner appeared during preparation")
                        continue
                    if event.get("registry_id") != assignment["owner_id"] or not event.get("session_id"):
                        raise SafetyError("Unexpected native child identity")
                    if assignment["session_id"] is None:
                        # Registration precedes session_init persistence; attach
                        # only at genuine child session_start with the gate installed.
                        if event["kind"] != "child_gate_installed":
                            continue
                        validate_child(self.ready[key], event, assignment["owner_id"])
                        self.ledger.attach_trial_session(key, session_id=event["session_id"],
                            root_session_id=self.ready[key]["root_session_id"], process_id=rpc.owned.process_id,
                            journal_ref=event["journal_ref"], registry_ref=str(record_path), event_id=key + "-native-child")
                        immutable_json(rpc.directory / "owner-identity.json", {
                            "assignment_id": key, "owner_id": assignment["owner_id"], "session_id": event["session_id"],
                            "root_session_id": self.ready[key]["root_session_id"], "manifest_digest": self.manifest_digest,
                            "authorization_revision": self.ledger.authorization()["revision"],
                            "original_dispatch_effect_id": key + "-initial",
                            "run_id": self.root.name, "reporting_module": "tools.orchestration_eval.trial",
                            "python": sys.executable,
                            "reporting_argv_prefix": owner_reporting_argv(self.root.name),
                            "module_source": str(Path(__file__).with_name("trial.py")),
                            "ledger_contract": str(Path(__file__).with_name("state.py")),
                            "submission": "Write an envelope outside inbox, then use reporting_argv_prefix with its "
                                          "absolute filename appended, retaining the inherited PYTHONPATH and your "
                                          "workspace cwd. Never write partial files into inbox.",
                            "allowed_owner_observations": ["attempt", "event", "inputs", "exhaust"],
                            "envelope_fields": ["event_id", "manifest_digest", "assignment_id", "owner_id", "session_id",
                                                "operation", "payload"],
                            "measurement_observation_fields": ["assignment_id", "owner_id", "session_id", "manifest_digest",
                                "authorization_revision", "dispatch_effect_id", "started_at", "observed_at",
                                "timestamp_provenance", "evidence_refs"],
                            "authority": "The automatic controller owns fixed review/publication/cleanup admission; no owner receipt grants MAIN authority",
                        })
                    elif assignment["session_id"] != event["session_id"]:
                        raise SafetyError("Native owner session changed")
            if rpc.owned.process.poll() is not None and not rpc.owned.record.get("exit_proof"):
                raise SafetyError("Retained native owner unexpectedly exited; recovery required")

    def close_owner(self, key):
        assignment = self.ledger.snapshot()["assignments"][key]
        if assignment["status"] != "cleanup":
            raise SafetyError("Only the cleaned and publication-acknowledged retained owner can close")
        proof = self.roots[key].close()
        self.ledger.record_process_exit(proof["process_id"], event_id="exit-" + proof["process_id"], proof=proof)
        self.registrations.close(key, proof)
        return proof

    def register_observe(self, key):
        for attempt in range(4):
            port = self.registrations.register(key, replace_port=attempt > 0)
            self.registrations.release_reservation(key)
            try:
                return self.observe(key, port)
            except SafetyError as error:
                if (attempt == 3 or key not in self.observer_initialized
                        or owned_listener(self.roots[key].owned, port)
                        or not self.registrations.port_conflict(key)):
                    raise
                immutable_json(self.root / "observer-conflicts" / (uuid.uuid4().hex + ".json"),
                               {"assignment_id": key, "port": port, "error": str(error),
                                "observed_at": now(), "native_observe_replayed": False})

    def prepare_refill(self):
        snapshot = self.ledger.snapshot()
        if snapshot["trial"]["activation"] is None or snapshot["authorization"]["mode"] != "RUN":
            return
        for key, (phase, future) in list(self.refill_jobs.items()):
            if not future.done():
                continue
            del self.refill_jobs[key]
            try:
                future.result()
                if phase == "visibility":
                    self.refill_visible.add(key)
                self.snapshot("refill-" + phase + "-" + key)
            except BaseException as error:
                self.refill_failures[key] = {"phase": phase, "error": repr(error), "observed_at": now()}
                save_json(self.root / "refill-errors" / (key + ".json"), self.refill_failures[key])
        snapshot = self.ledger.snapshot()
        used = {claim["slot"] for key, claim in snapshot["trial"]["claims"].items()
                if snapshot["assignments"][key]["status"] != "closed"}
        used.update(slot for key, slot in self.refill_slots.items() if key not in snapshot["trial"]["claims"])
        available = [slot for slot in range(4) if slot not in used]
        queued = [row for row in self.manifest["reservations"][4:]
                  if row["assignment_id"] not in self.prepared and row["assignment_id"] not in self.refill_slots
                  and snapshot["trial"]["eligibility"].get(row["assignment_id"], {}).get("reason", "eligible") == "eligible"]
        for slot, row in zip(available, queued):
            key = row["assignment_id"]
            self.refill_slots[key] = slot
            self.refill_jobs[key] = ("root", self.refill_pool.submit(self.prepare, row, slot))
        for row in self.manifest["reservations"][4:]:
            key = row["assignment_id"]
            if key not in self.ready or key in self.refill_jobs or key in self.refill_failures:
                continue
            if key not in self.observed:
                self.refill_jobs[key] = ("observe", self.refill_pool.submit(self.register_observe, key))
            elif key not in snapshot["trial"]["claims"]:
                self.refill_jobs[key] = ("child", self.refill_pool.submit(self.start_refill, key))
            elif key in self.held and key + "-initial" not in snapshot["trial"]["effects"]:
                if key not in self.refill_visible:
                    self.refill_jobs[key] = ("visibility", self.refill_pool.submit(
                        self.verify_observer, key, require_child=True))
                elif self.ledger.trial_prompt_readiness(key)["ready"]:
                    self.admit_refill(key)
                    self.refill_jobs[key] = ("release", self.refill_pool.submit(self.release_provider, key))

    def start_refill(self, key):
        snapshot = self.ledger.snapshot()
        if key not in self.observed or key not in self.slots or key in snapshot["trial"]["claims"]:
            raise SafetyError("Refill requires its fresh positively observed native root")
        self.verify_observer(key)
        revision = self.ledger.authorization()["revision"]
        self.ledger.claim_trial_refill(claim=self._claim(key), event_id=key + "-claim", authorization_revision=revision)
        return self.start_assignment(key)

    def admit_refill(self, key):
        if key not in self.held or key not in self.refill_visible:
            raise SafetyError("Refill provider admission requires the positively observed held native child")
        revision = self.ledger.authorization()["revision"]
        admitted = self.ledger.admit_trial_effect(key, effect_id=key + "-initial", kind="prompt",
            event_id=key + "-provider-admission", authorization_revision=revision)
        if not admitted["execute"]:
            raise SafetyError("Refill provider admission already consumed")
        return admitted

    def handle(self, envelope, *, raw=None):
        consumed = consume_delivery(self.ledger, envelope, raw)
        if not consumed["execute"] and not consumed.get("replay_observation"):
            return {"duplicate": True, "executed": False}
        event_id, operation, data = envelope["event_id"], envelope["operation"], envelope["payload"]
        key = envelope.get("assignment_id")
        if envelope.get("manifest_digest") != self.manifest_digest:
            raise SafetyError("Envelope belongs to another immutable manifest")
        if operation == "history":
            return self.ledger.resolve_trial_history(key, history=data["history"], record=data["record"], event_id=event_id)
        if operation == "activate":
            return self.activate(data)
        if operation == "event":
            return self.ledger.trial_event(key, kind=data["kind"], record=data["record"], event_id=event_id)
        if operation == "eligibility":
            return self.ledger.set_trial_eligibility(key, reason=data["reason"], record=data["record"], event_id=event_id)
        if operation == "inputs":
            return self.ledger.check_input_identity(key, event_id=event_id, **data)
        revision = (data.get("observation") or {}).get("authorization_revision",
                                                       consumed["authorization_revision"])
        if operation == "attempt":
            return self.ledger.record_attempt(key, event_id=event_id, authorization_revision=revision, **data)
        if operation == "exhaust":
            return self.ledger.exhaust_stage(key, event_id=event_id, authorization_revision=revision, **data)
        raise SafetyError("Unsupported bounded trial envelope")

    def serve(self):
        inbox = self.root / "inbox"
        inbox.mkdir(exist_ok=True)
        while self.ledger.authorization()["mode"] in {"RUN", "PUBLISH_EXISTING"}:
            self.collect_native()
            for path in sorted(inbox.glob("*.json")):
                confined(path, inbox)
                if path.name in self.handled:
                    continue
                raw = path.read_bytes()
                envelope = json.loads(raw)
                identifier = envelope.get("event_id")
                if not isinstance(identifier, str) or not identifier.isascii() or not identifier.replace("-", "").isalnum():
                    raise SafetyError("Invalid trial event identity")
                claim = self.root / "inbox-claims" / (identifier + ".json")
                immutable_json(claim, {"envelope_sha256": hashlib.sha256(raw).hexdigest(),
                                       "path": str(path), "claimed_at": now()})
                try:
                    result = self.handle(envelope, raw=raw)
                    immutable_json(self.root / "outbox" / (identifier + ".json"), {"success": True, "result": result})
                except BaseException as exc:
                    immutable_json(self.root / "outbox" / (identifier + ".json"), {"success": False, "error": repr(exc)})
                    raise
                self.handled.add(path.name)
                self.snapshot("event-" + identifier)
            self.workflow.tick()
            self.prepare_refill()
            snapshot = self.ledger.snapshot()
            if len(snapshot["assignments"]) == 8 and all(a["status"] == "closed" for a in snapshot["assignments"].values()):
                return self.snapshot("eight-assignments-closed")
            time.sleep(0.1)

    def stop(self, *, event_id, reason, include_server=True):
        self.ledger.request_stop(event_id=event_id, reason=reason)
        self.workflow.shutdown()
        self.refill_pool.shutdown(wait=False, cancel_futures=True)
        for rpc in self.roots.values():
            rpc.closing = True
        result = super().stop(event_id=event_id + "-native", reason=reason, include_server=include_server)
        self.registrations.close_exited()
        return result
