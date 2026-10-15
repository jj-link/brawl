"""Durable readiness drives real native/repository actions, not routine envelopes."""
from __future__ import annotations

from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import shlex
import sys
import uuid

from .evidence import content_identity, file_identity, input_path
from .safety import SafetyError, confined, digest, now, save_json
from .trial_cleanup import delivery_plan
from .trial_completion import completion, review_decision
from .trial_delivery import DeliveryError, WorkerDelivery, observe_delivery
from .trial_execution import OwnedCommands
from .trial_identity import validate_child
from .trial_repository import IndependentRepository, ReconciliationRequired
from .state import StateError
from .policy import PolicyError
from .trial_verification import VerificationRejected, verify_delivery


class TrialWorkflow:
    def __init__(self, runtime):
        self.runtime = runtime
        self.ledger = runtime.ledger
        self.pool = ThreadPoolExecutor(max_workers=8, thread_name_prefix="trial-workflow")
        self.futures = {}
        self.events = []
        self.stopping = False

    def shutdown(self):
        self.stopping = True
        self.pool.shutdown(wait=False, cancel_futures=True)

    def native_event(self, key, event, path, *, raw=None):
        if event["kind"] == "local_result" and event.get("operation") in {"prepare-review", "review", "owner-action"}:
            if event.get("success") is False:
                self.events.append((key, event, str(path)))
            return True
        if event["kind"] == "native_interval":
            if not isinstance(raw, bytes) or not raw.endswith(b"\n") or json.loads(raw) != event:
                raise SafetyError("Native timing requires the actual complete host journal bytes")
            archive = confined(self.runtime.root / "native-observations" / (hashlib.sha256(raw).hexdigest() + ".jsonl"),
                               self.runtime.root)
            archive.parent.mkdir(parents=True, exist_ok=True)
            archive = input_path(archive.parent, archive.name, must_exist=False)
            try:
                with archive.open("xb") as stream:
                    stream.write(raw)
                    stream.flush()
                    os.fsync(stream.fileno())
            except FileExistsError:
                if archive.read_bytes() != raw:
                    raise SafetyError("Retained native timing bytes changed")
            path = archive
        if event["kind"] in {"owner_turn_end", "review_gate_wait", "reviewer_turn_end", "native_interval"}:
            self.events.append((key, event, str(path)))
            return True
        if event["kind"] in {"registry", "reviewer_gate_installed"}:
            state = self.ledger.snapshot()["trial"].get("workflow", {}).get("assignments", {}).get(key, {})
            expected = state.get("reviewer")
            if expected and event.get("registry_id") == expected["owner_id"]:
                return True
            actions = self.ledger.snapshot()["trial"].get("workflow", {}).get("actions", {})
            return any(action["assignment_id"] == key and action["kind"] == "prepare_review"
                       and action["reviewer"]["owner_id"] == event.get("registry_id") for action in actions.values())
        return False

    def directory(self, effect_id):
        path = confined(self.runtime.root / "workflow" / effect_id, self.runtime.root)
        path.mkdir(parents=True, exist_ok=True)
        return path

    def complete(self, action, result, *, outcome="succeeded", refs=()):
        directory = self.directory(action["effect_id"])
        path = directory / ("observation-" + uuid.uuid4().hex + ".json")
        record = {"binding": action["binding"], "authorization_revision": action["authorization_revision"],
                  "started_at": result.get("query_started_at", action["admitted_at"]), "observed_at": now(),
                  "timestamp_provenance": {"source": "owned-workflow-results", "clock_id": "ledger_utc"},
                  "evidence_refs": [str(path), *map(str, refs)], "outcome": outcome, "result": result}
        save_json(path, record)
        return self.ledger.observe_trial_action(effect_id=action["effect_id"], record=record,
                                                event_id="observed-" + content_identity(record))

    def review_paths(self, key, delivery_id):
        directory = confined(self.runtime.roots[key].directory / "reviews" / delivery_id, self.runtime.root)
        directory.mkdir(parents=True, exist_ok=True)
        return directory, directory / "decision.json", directory / "review-identity.json"

    def review_task(self, action, delivery):
        key = action["assignment_id"]
        directory, decision, identity = self.review_paths(key, delivery.delivery_id)
        packet = directory / "delivery.json"
        if not packet.exists():
            save_json(packet, delivery.payload)
        assignment = self.ledger.assignment(key)
        state = self.ledger.snapshot()["trial"]["workflow"]["assignments"][key]
        verification = directory / "verification.json"
        if not verification.exists():
            save_json(verification, state["validation"])
        task = (f"Independently review this exact delivery {packet} and actual controller verification {verification}. "
                f"Candidate workspace: {assignment['identity']['reservation']['workspace']}. "
                f"Before reviewing read your genuine native/action identity at {identity}. "
                "Inspect actual source, original assembly/caller ABI and fixed evidence. Do not trust worker claims. "
                "Write one JSON object with keys delivery_id, effect_id, reviewer_id, session_id, decision, findings. "
                "Identity values come from that identity record. decision is approve or reject; approval findings is []; "
                "rejection findings each has criterion,path,reason. Fixed criteria: compile,object_compare,data_relocations,"
                "source_link,binary_hashes,progress,abi,edge_semantics,ownership,attempt_rules,relevant_inputs. "
                "A path is a concrete delivery input/artifact relative path, or empty for a global criterion. "
                "Do not edit code, invoke another model, publish or manufacture evidence. "
                f"Your sole output file is {decision}.")
        return task, decision, identity

    def dispatch(self, action):
        kind, key = action["kind"], action["assignment_id"]
        if kind == "prepare_target":
            return IndependentRepository(self.runtime).prepare_target(action)
        snapshot = self.ledger.snapshot()
        assignment = snapshot["assignments"][key]
        state = snapshot["trial"]["workflow"]["assignments"][key]
        if kind == "reconcile":
            record = self.directory(action["effect_id"]) / "reconciliation.json"
            save_json(record, {"action": action, "correction": state.get("correction"),
                               "publication_target": snapshot["trial"]["workflow"]["config"]["publication_target"]})
            message = (f"Continue your SAME assignment and native session. Read concrete correction {record}. "
                       "Reconcile only failed fixed criteria or changed relevant inputs against the controller target, "
                       "without modifying that target. Preserve every attempt/count and best source; no additional budget. "
                       "Keep verified function bytes unchanged for unrelated registration reconciliation. Record actual "
                       f"measurements with observation.dispatch_effect_id={action['effect_id']}. "
                       "For delivery-format repair, reuse the already measured candidate and evidence; do not count "
                       "a reporting repair as a new reconstruction attempt or change verified function bytes. "
                       "Update evidence/controller-delivery.json with actual new preimages/postimages and relevant inputs, "
                       "then end this turn. Do not publish or send a conversational approval request.")
            self.runtime.native_command(key, "owner-action", effect_id=action["effect_id"], message=message)
            return None
        if kind == "restore_materialization":
            original = snapshot["trial"]["workflow"]["actions"][action["binding"]["recovery_action_id"]]
            previous = state["deliveries"][original["binding"]["delivery_id"]]
            return IndependentRepository(self.runtime).restore_materialization(
                action, original, WorkerDelivery.from_dict(previous["delivery"]))
        entry = state["deliveries"][action["binding"]["delivery_id"]]
        delivery = WorkerDelivery.from_dict(entry["delivery"])
        workspace = Path(assignment["identity"]["reservation"]["workspace"])
        if kind == "validate_delivery":
            return verify_delivery(self.runtime, action, delivery)
        if kind in {"prepare_review", "review"}:
            task, decision, identity = self.review_task(action, delivery)
            if kind == "prepare_review":
                self.runtime.native_command(key, "prepare-review", effect_id=action["effect_id"],
                    decision_path=str(decision), task=task, context="Independent concrete reconstruction acceptance review")
            else:
                self.runtime.verify_observer(key, require_child=True,
                                             reviewer_session=action["reviewer"]["session_id"])
                save_json(identity, {"delivery_id": delivery.delivery_id, "effect_id": action["effect_id"],
                    "reviewer_id": action["reviewer"]["owner_id"], "session_id": action["reviewer"]["session_id"],
                    "reviewer": action["reviewer"], "binding": action["binding"]})
                self.runtime.native_command(key, "release-review", effect_id=action["effect_id"],
                                            decision_path=str(decision), task=task)
            return None  # Actual native gate/turn-end, not RPC success, completes these actions.
        repository = IndependentRepository(self.runtime)
        if kind == "materialize":
            result = repository.materialize(action, delivery, workspace)
            expected = {name: dict(change["after"], raw=change["raw"]) for name, change in delivery.payload["changes"].items()}
            actual = {row["path"]: {"mode": "100644", "blob": row["blob"], "raw": row["raw"]} for row in result["postimages"]}
            evidence = self.directory(action["effect_id"]) / "materialization.json"
            return dict(result, base_head=result["head"], expected_postimages=expected, actual_postimages=actual,
                        scope_verified=True, source_binding_verified=True, preservation_ref=str(evidence),
                        private_index_ref=str(evidence), grant_ref=str(self.runtime.root / "workflow-config.json"))
        if kind == "commit":
            unit_index = int(action["binding"]["logical_unit_id"].removeprefix("unit-"))
            if unit_index:
                parent = state["units"][f"unit-{unit_index - 1}"]["commit"]
            else:
                parent = state["materialization"]["record"]["result"]["head"]
            result = repository.commit(action, delivery, parent)
            paths = delivery.payload["logical_units"][unit_index]["paths"]
            return dict(result, local_head=result["commit"], changed_paths=paths, command_refs=result["evidence_refs"],
                        postimages={name: state["materialization"]["postimages"][name] for name in paths})
        if kind == "push":
            commit = action["binding"]["commit"]
            previous = [other for other in snapshot["trial"]["workflow"]["actions"].values()
                        if other["kind"] == "push" and other["status"] == "succeeded"]
            expected = previous[-1]["result"]["commit"] if previous else None
            result = repository.push(action, commit, expected)
            return dict(result, logical_unit_id=action["binding"]["logical_unit_id"],
                        pushed=True, remote_contains_commit=True, command_refs=result["evidence_refs"])
        if kind == "acknowledge":
            commit = state["units"][f"unit-{len(delivery.payload['logical_units']) - 1}"]["commit"]
            return repository.acknowledge(action, delivery, commit)
        if kind == "cleanup":
            commands = OwnedCommands(self.runtime)
            tracked_result = commands.run(action, ["git", "-C", str(workspace), "ls-files", "-z"], cwd=workspace)
            tracked = {name: file_identity(input_path(workspace, name))
                       for name in tracked_result.stdout.decode().split("\0") if name}
            specification = snapshot["trial"]["workflow"]["config"]["verification"][key]
            plan = delivery_plan(workspace, assignment, state["deliveries"], specification, delivery, tracked)
            plan.update(ledger_path=str(self.ledger.path), effect_id=action["effect_id"],
                        binding=action["binding"], authorization_revision=action["authorization_revision"])
            path = self.directory(action["effect_id"]) / "cleanup-plan.json"
            save_json(path, plan)
            command = " ".join(shlex.quote(value) for value in [Path(sys.executable).as_posix(), "-P", "-B", "-m",
                "tools.orchestration_eval.trial_cleanup", path.as_posix(), digest(path)])
            self.runtime.native_command(key, "owner-action", effect_id=action["effect_id"], cleanup_command=command,
                message=f"Publication is actually acknowledged. Remain this same owner. Read {path}, then run exactly "
                        f"this safe native cleanup command once from your workspace: {command}\n"
                        "Do not delete/prune anything manually or change retained evidence. End your turn after the actual result.")
            return None
        if kind == "close":
            proof = self.runtime.close_owner(key)
            return {"process_id": proof["process_id"], "exit_evidence_ref": proof["evidence_ref"]}
        raise SafetyError("Unsupported durable workflow action")

    def process_native(self, key, native, reference):
        doc = self.ledger.snapshot()
        workflow = doc["trial"]["workflow"]
        if native["kind"] == "local_result":
            effect_id = native.get("workflow_effect_id")
            action = workflow["actions"].get(effect_id)
            if not action or action["assignment_id"] != key:
                raise SafetyError("Native failure does not identify an owned admitted workflow effect")
            result_path = confined(Path(native["result_ref"]), Path(reference).parent)
            result = json.loads(result_path.read_bytes())
            if (result.get("id") != native["id"] or result.get("operation") != native["operation"]
                    or result.get("workflow_effect_id") != effect_id or result.get("success") is not False):
                raise SafetyError("Native failure event differs from its retained result")
            if action["status"] in {"admitted", "uncertain"}:
                self.complete(action, {"native_failure_ref": str(result_path), "native_failure_event": native,
                                      "error": result.get("error", "Native task/write returned an unsuccessful result")},
                              outcome="uncertain", refs=[reference, str(result_path)])
            return
        if native["kind"] == "native_interval":
            assignment = doc["assignments"][key]
            reviewer = workflow["assignments"].get(key, {}).get("reviewer") or {}
            actors = {(assignment["owner_id"], assignment["session_id"]),
                      (reviewer.get("owner_id"), reviewer.get("session_id"))}
            if (native.get("owner"), native.get("session_id")) not in actors:
                raise SafetyError("Native interval belongs to an unassigned actor")
            raw = confined(Path(reference), self.runtime.root / "native-observations").read_bytes()
            if not raw.endswith(b"\n") or json.loads(raw) != native:
                raise SafetyError("Native interval differs from its immutable host-collected bytes")
            self.ledger.observe_trial_interval(key, event_id="interval-" + content_identity(native),
                record={"owner_id": assignment["owner_id"], "native_actor_id": native["owner"],
                        "native_session_id": native["session_id"], "phase": native["phase"],
                        "started_at": native["started_at"], "observed_at": native["observed_at"],
                        "qualification": native.get("qualification", "Actual native tool execution interval"),
                        "timestamp_provenance": {"source": "native-extension-events", "clock_id": "host-utc"},
                        "native_event": native,
                        "native_evidence": {"path": str(reference), "sha256": hashlib.sha256(raw).hexdigest()},
                        "evidence_refs": [reference]})
            return
        effect_id = native.get("request_id")
        action = workflow["actions"].get(effect_id)
        if native["kind"] == "review_gate_wait":
            if not action or action["kind"] != "prepare_review":
                raise SafetyError("Genuine reviewer gate lacks its exact prepared effect")
            validate_child(self.runtime.ready[key], native, action["reviewer"]["owner_id"])
            reviewer = dict(action["reviewer"], session_id=native["session_id"], journal_ref=native["journal_ref"],
                            registry_ref=reference)
            self.complete(action, {"reviewer": reviewer, "native_event": native}, refs=[reference])
            return
        if native.get("will_continue") is not False:
            return
        assignment = doc["assignments"][key]
        succeeded = completion(native, reference)
        if native["kind"] == "reviewer_turn_end":
            if not action or action["kind"] != "review":
                raise SafetyError("Reviewer completion lacks its original admitted request")
            if not succeeded:
                raise SafetyError("Actual reviewer executor or native command failed")
            _, decision, _ = self.review_paths(key, action["binding"]["delivery_id"])
            result = review_decision(decision, action)
            self.complete(action, dict(result, native_event=native), refs=[reference, decision])
            return
        effect = action or doc["trial"]["effects"].get(effect_id)
        if effect is None:
            return  # A held preparation aborted before any provider admission.
        if not native.get("started_at"):
            raise SafetyError("Native owner completion lacks its observed first request boundary")
        record = {"observed_at": native["observed_at"], "started_at": native["started_at"],
                  "authorization_revision": effect["authorization_revision"],
                  "timestamp_provenance": {"source": "native-request-through-owner-end", "clock_id": "host-utc"},
                  "evidence_refs": [reference], "dispatch_effect_id": effect_id, "native_event": native}
        self.ledger.observe_trial_owner(key, record=record, event_id="owner-end-" + content_identity(native))
        if not succeeded:
            if action:
                self.complete(action, {"error": "Actual owner executor or native command failed",
                                      "native_event": native}, outcome="failed", refs=[reference])
            return
        if action and action["kind"] == "cleanup":
            path = self.directory(effect_id) / "cleanup-result.json"
            result = json.loads(path.read_text(encoding="utf-8"))
            if result["binding"] != action["binding"] or result["effect_id"] != effect_id:
                raise SafetyError("Cleanup result belongs to another retained owner action")
            for row in result["removed_paths"]:
                if Path(row["path"]).exists():
                    raise SafetyError("Cleanup receipt claims a file that is still present")
            self.complete(action, dict(result, native_event=native), refs=[reference, path])
            return
        if action and action["kind"] == "reconcile":
            self.complete(action, {"native_event": native}, refs=[reference])
        self.capture_delivery(key, native, record)

    def capture_delivery(self, key, native, record):
        doc = self.ledger.snapshot()
        assignment = doc["assignments"][key]
        effect_id = record["dispatch_effect_id"]
        workspace = Path(assignment["identity"]["reservation"]["workspace"])
        captured = None
        try:
            delivery, captured = observe_delivery(workspace, "evidence/controller-delivery.json",
                assignment=assignment, manifest_digest=doc["trial"]["manifest_digest"], native_event=native,
                archive_directory=self.runtime.root / "deliveries" / "raw")
            captured.update(record)
            captured["native_event"] = native
            self.ledger.record_trial_delivery(key, delivery=delivery.payload, record=captured,
                                              event_id="delivery-" + content_identity({
                                                  "dispatch": effect_id, "delivery": delivery.delivery_id}))
            path = self.runtime.root / "deliveries" / (content_identity({
                "dispatch": effect_id, "delivery": delivery.delivery_id}) + ".json")
            if not path.exists():
                save_json(path, {"delivery": delivery.payload, "capture": captured})
        except (OSError, ValueError, DeliveryError, StateError) as error:
            path = self.runtime.root / "delivery-errors" / (content_identity(native) + ".json")
            capture = getattr(error, "capture", None) or captured
            archive = {name: capture[name] for name in ("path", "sha256", "size")} if capture else None
            issue = {"reason": str(error), "original_path": str(workspace / "evidence/controller-delivery.json"),
                     "archive": archive}
            save_json(path, {"native_event": native, "error": issue, "observed_at": now()})
            self.ledger.record_trial_delivery_error(key, error=issue,
                record=dict(record, evidence_refs=[*record["evidence_refs"], str(path)]),
                event_id="delivery-error-" + content_identity({"native": native, "error": issue}))

    def tick(self):
        for effect_id, (action, future) in list(self.futures.items()):
            if not future.done():
                continue
            del self.futures[effect_id]
            try:
                result = future.result()
                if result is not None:
                    self.complete(action, result, refs=result.get("evidence_refs", []))
            except VerificationRejected as error:
                self.complete(action, {"findings": error.findings, "effect_absent": True}, outcome="rejected")
            except ReconciliationRequired as error:
                self.complete(action, {"findings": [{"criterion": "ownership", "path": "", "reason": str(error)}],
                                       "effect_absent": True}, outcome="rejected")
            except BaseException as error:
                self.complete(action, {"error": repr(error)}, outcome="uncertain")
        while self.events:
            key, event, path = self.events.pop(0)
            try:
                self.process_native(key, event, path)
            except (OSError, ValueError, SafetyError, StateError) as error:
                action = self.ledger.snapshot()["trial"]["workflow"]["actions"].get(event.get("request_id"))
                if action and action["status"] in {"admitted", "uncertain"}:
                    final = False
                    if event.get("will_continue") is False and event["kind"] in {"reviewer_turn_end", "owner_turn_end"}:
                        try:
                            completion(event, path)
                            final = True
                        except (OSError, ValueError, SafetyError):
                            pass  # An early turn/error is not native finalization.
                    result = {"error": repr(error),
                              "native_event" if final else "unsettled_native_event": event}
                    self.complete(action, result, outcome="failed" if final else "uncertain", refs=[path])
                else:
                    raise
        if self.stopping:
            return
        keys = [None, *self.ledger.snapshot()["trial"]["claims"]]
        for key in keys:
            readiness = self.ledger.trial_readiness()
            row = readiness["target"] if key is None else readiness["assignments"][key]
            if not row["ready"]:
                continue
            effect_id = "wf-" + content_identity({"kind": row["kind"], "binding": row["binding"]})[:48]
            try:
                action = self.ledger.admit_trial_action(key, kind=row["kind"], effect_id=effect_id,
                    binding=row["binding"], authorization_revision=readiness["authorization"]["revision"],
                    event_id=effect_id + "-admit")
            except (PolicyError, StateError):
                fresh = self.ledger.trial_readiness()
                current = fresh["target"] if key is None else fresh["assignments"][key]
                if current["ready"] and fresh["authorization"] == readiness["authorization"]:
                    raise
                continue
            if action.pop("execute"):
                self.futures[effect_id] = (action, self.pool.submit(self.dispatch, action))
