"""Explicit bounded real-function trial commands. Status is non-executing.

serve retains four native roots and the same owners; submit delivers immutable
coordinator/owner envelopes. A crashed serve is never resumed: recover proves
exact-run exits, preserves unknown effects, and does not replay provider work.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import sqlite3
import sys
import time
import uuid

from .__main__ import configure, drain_prefect_clients, run_root, run_tests
from .policy import SlotPolicy
from .safety import ACTIVE, BUILD, WORKTREE, SafetyError, check_worktree, confined, digest, now, save_json
from .state import Ledger, read_snapshot
from .trial_runtime import TrialRuntime, immutable_json, delivery_bytes, consume_delivery
from .trial_rpc import validate_runtime_identity
from .trial_authority import validate_approval, require_fresh_workspace
from .trial_registration import registration_scope

OBSERVED_SESSION_DIRECTORY = Path("C:/Users/josep/.omp/agent/sessions/-Projects-personal-games-brawl-decomp")
OBSERVED_EXECUTION = {"provider": "spark1", "model": "Qwen3.8-Flash-Next", "endpoint": "http://100.86.3.45:8000/v1"}
OPERATIONS = frozenset({"activate", "event", "eligibility", "attempt", "exhaust", "inputs", "history"})


def canonical_digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(",", ":"), allow_nan=False).encode()).hexdigest()


def inspect_model(execution=None):
    """Read the existing registration/cache only. No discovery or model request."""
    execution = OBSERVED_EXECUTION if execution is None else execution
    model_path = Path("C:/Users/josep/.omp/agent/models.yml")
    cache = Path("C:/Users/josep/.omp/agent/models.db")
    with sqlite3.connect(cache.as_uri() + "?mode=ro", uri=True) as connection:
        rows = connection.execute("SELECT models FROM model_cache WHERE provider_id LIKE ?",
                                  (execution["provider"] + ":%",)).fetchall()
    models = [model for row in rows for model in json.loads(row[0]) if model["id"] == execution["model"]]
    # Retained cache generations may repeat one complete model definition.
    if len({canonical_digest(model) for model in models}) != 1:
        raise SafetyError("Existing native cache does not identify exactly one approved model definition")
    model = models[0]
    if (model["provider"] != execution["provider"] or model["baseUrl"] != execution["endpoint"] or
            model["api"] != "openai-completions"):
        raise SafetyError("Observed registration changed; coordinator review required")
    # The existing environment already includes YAML through pinned Prefect.
    import yaml
    provider = yaml.safe_load(model_path.read_text(encoding="utf-8"))["providers"][execution["provider"]]
    if provider.get("baseUrl") != model["baseUrl"] or provider.get("api") != model["api"] or provider.get("auth") != "none":
        raise SafetyError("Native registration/cache disagree or credentials would be required")
    return {"observed_at": now(), "execution": execution, "model_definition": model,
            "configuration_path": str(model_path), "configuration_sha256": digest(model_path),
            "cache_path": str(cache), "requests_sent": 0}


def validate_launch_contract(manifest, contract):
    validate_approval(manifest, contract)
    if any(manifest["execution"].get(key) != value for key, value in OBSERVED_EXECUTION.items()):
        raise SafetyError("Trial supports only the observed coordinator-authorized Spark1 Qwen identity")
    if (contract.get("manifest_digest") != canonical_digest(manifest) or
            contract.get("confirmed_by") != manifest["coordinator_id"] or not contract.get("preparation_grant_ref")):
        raise SafetyError("Launch contract must bind the immutable coordinator-confirmed manifest and preparation grant")
    directory = Path(contract["session_directory"])
    if directory != OBSERVED_SESSION_DIRECTORY or not contract.get("session_store_grant_ref"):
        raise SafetyError("Only explicitly granted new standard-store trial journals are supported")
    confined(directory, OBSERVED_SESSION_DIRECTORY)
    observer = contract["observer"]
    if (Path(observer["path"]) != ACTIVE / ".omp/extensions/live-output.js" or
            Path(observer["registration"]) != ACTIVE / "build/live-dashboard/independent-roots.json" or
            digest(Path(observer["path"])) != observer["sha256"]):
        raise SafetyError("Observer must be the exact unchanged MAIN module; no copied/guessed observer")
    if contract.get("registration") != registration_scope(manifest, observer["registration"]):
        raise SafetyError("Launch approval must bind automatic controller registration and four held owners")
    publication = observer.get("publication_ref")
    if (observer.get("mode") != "independent-required" or not isinstance(publication, dict) or
            not publication.get("path") or not publication.get("sha256") or
            digest(confined(Path(publication["path"]), ACTIVE)) != publication["sha256"]):
        raise SafetyError("Published observer identity receipt must be pinned by the coordinator approval packet")
    definition = contract["agent_definition"]
    if (Path(definition["path"]) != ACTIVE / ".omp/agents/spark1-qwen.md" or
            digest(Path(definition["path"])) != definition["sha256"]):
        raise SafetyError("Native reconstruction instructions must bind the coordinator's existing agent definition")
    observed = inspect_model()
    if (contract.get("model_definition") != observed["model_definition"] or
            contract.get("configuration_sha256") != observed["configuration_sha256"]):
        raise SafetyError("Launch model identity must equal current read-only native registration evidence")
    review = inspect_model(contract["workflow_config"]["profile"]["review"])
    if contract["review_model_definition"] != review["model_definition"]:
        raise SafetyError("Reviewer registration must equal actual current read-only native configuration")
    for reservation in manifest["reservations"]:
        require_fresh_workspace(reservation)
    return observed


def submit(root, envelope, *, role="coordinator"):
    if not (root / "ledger.sqlite3").is_file():
        raise SafetyError("No exact-run ledger exists")
    identifier = envelope.get("event_id")
    if not isinstance(identifier, str) or not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9-]{0,99}", identifier):
        raise SafetyError("Event identity must be one portable component")
    if envelope.get("operation") not in OPERATIONS or not isinstance(envelope.get("payload"), dict):
        raise SafetyError("Unsupported bounded envelope")
    snapshot = read_snapshot(root / "ledger.sqlite3")
    if envelope.get("manifest_digest") != snapshot.get("trial", {}).get("manifest_digest"):
        raise SafetyError("Envelope manifest differs from exact-run reservation")
    if (snapshot["trial"].get("workflow") is not None and envelope["operation"] == "event"
            and envelope["payload"].get("kind") == "interval"):
        raise SafetyError("Native timing is collected from owned host journals, never an envelope")
    ledger = Ledger(root / "ledger.sqlite3")
    raw = delivery_bytes(envelope)
    try:
        ledger.admit_trial_delivery(event_id=identifier, role=role, envelope=envelope,
            content_sha256=hashlib.sha256(raw).hexdigest(), authorization_revision=snapshot["authorization"]["revision"])
    except ValueError as exc:
        raise SafetyError(f"Delivery admission refused: {exc}") from exc
    path = root / "inbox" / (identifier + ".json")
    if path.exists():
        if path.read_bytes() != raw:
            raise SafetyError("An event identity cannot be rebound")
        return {"path": str(path), "duplicate": True, "executed": False}
    if snapshot["authorization"]["mode"] != "RUN":
        raise SafetyError("STOPped/crashed trial accepts no new live execution; use record for observations")
    # Atomic publication prevents the retained consumer seeing a partial JSON.
    pending = root / "submissions" / (identifier + "-" + uuid.uuid4().hex + ".json")
    immutable_json(pending, envelope)
    path.parent.mkdir(parents=True, exist_ok=True)
    # Native Windows rename refuses an occupied destination (never replace).
    try:
        pending.rename(path)
    except FileExistsError:
        if path.read_bytes() != raw:
            raise SafetyError("Concurrent delivery attempted to rebind an event identity")
        return {"path": str(path), "duplicate": True, "executed": False}
    return {"path": str(path), "duplicate": False, "executed": False}


def recover(root, reason, *, observe_effects=True):
    ledger = Ledger(root / "ledger.sqlite3")
    snapshot = ledger.snapshot()
    if "trial" not in snapshot:
        raise SafetyError("Not a real-trial run; use original control-only exact-run stop")
    from .runtime import EvaluationRuntime
    ledger.request_stop(event_id="trial-recovery-stop-" + uuid.uuid4().hex, reason=reason)
    runtime = EvaluationRuntime(root, ledger, recovery_only=True)
    result = runtime.stop(event_id="trial-native-recovery-" + uuid.uuid4().hex, reason=reason)
    from .trial_registration import RegistrationAdapter
    registration_cleanup = RegistrationAdapter(runtime).close_exited()
    recovery = None
    if observe_effects and "workflow" in snapshot["trial"]:
        from .safety import isolated_environment
        from .trial_recovery import recover_workflow
        pending = []
        for path in sorted((root / "inbox").glob("*.json")):
            confined(path, root)
            envelope = json.loads(path.read_text(encoding="utf-8"))
            if envelope["operation"] not in {"history", "event", "attempt", "exhaust", "inputs", "eligibility"}:
                continue
            try:
                role = ledger.trial_delivery(envelope["event_id"])["role"]
                pending.append({"event_id": envelope["event_id"],
                                "result": record_after_stop(root, envelope, role=role)})
            except (OSError, ValueError, RuntimeError) as error:
                pending.append({"event_id": envelope["event_id"], "error": repr(error)})
        runtime.environment = isolated_environment(root / "recovery-observation-environment")
        recovery = recover_workflow(runtime)
        recovery["pending_observations"] = pending
        result = ledger.snapshot()
        result["process_registry"] = runtime.manager.records()
        result["workflow_recovery"] = recovery
        result["registration_cleanup"] = registration_cleanup
        save_json(root / "status.json", result)
    save_json(root / "recovery.json", {"result": result, "observed_at": now(), "provider_effects_replayed": 0,
                                     "session_adoption": False, "processes": runtime.manager.records(),
                                     "registration_cleanup": registration_cleanup})
    return result


def record_after_stop(root, envelope, *, role="coordinator"):
    if not (confined(root) / "ledger.sqlite3").is_file():
        raise SafetyError("Observation recovery requires an existing exact-run ledger")
    ledger = Ledger(root / "ledger.sqlite3")
    trial = ledger.snapshot().get("trial")
    if trial is None or envelope.get("manifest_digest") != trial["manifest_digest"]:
        raise SafetyError("Observation does not identify the exact trial")
    data, identifier = envelope["payload"], envelope["event_id"]
    key = envelope.get("assignment_id")
    if envelope["operation"] not in {"history", "event", "attempt", "exhaust", "inputs", "eligibility"}:
        raise SafetyError("Late delivery may only record observations, never executable work")
    if trial.get("workflow") is not None and envelope["operation"] == "event" and data.get("kind") == "interval":
        raise SafetyError("Recovery cannot promote a model or coordinator timing claim to native evidence")
    ledger.admit_trial_delivery(event_id=identifier, role=role, envelope=envelope,
        content_sha256=hashlib.sha256(delivery_bytes(envelope)).hexdigest())
    consumed = consume_delivery(ledger, envelope)
    if not consumed["execute"] and not consumed.get("replay_observation"):
        return {"duplicate": True, "executed": False}
    if envelope["operation"] == "history":
        return ledger.resolve_trial_history(key, history=data["history"], record=data["record"], event_id=identifier)
    if envelope["operation"] == "event":
        return ledger.trial_event(key, kind=data["kind"], record=data["record"], event_id=identifier)
    if envelope["operation"] == "eligibility":
        return ledger.set_trial_eligibility(key, reason=data["reason"], record=data["record"], event_id=identifier)
    if envelope["operation"] in {"attempt", "exhaust"}:
        observation = data.get("observation")
        if not isinstance(observation, dict):
            raise SafetyError("Late measurements require the actual identity-bound historical execution interval")
        operation = {"attempt": ledger.record_attempt, "exhaust": ledger.exhaust_stage}[envelope["operation"]]
        return operation(key, event_id=identifier, authorization_revision=observation["authorization_revision"], **data)
    if envelope["operation"] == "inputs":
        return ledger.check_input_identity(key, event_id=identifier, **data)
    raise SafetyError("Observation recovery cannot authorize, wake, adopt or replay a worker")


def report(root, envelope):
    if not (confined(root) / "ledger.sqlite3").is_file():
        raise SafetyError("Owner observation requires an existing exact-run ledger")
    snapshot = read_snapshot(root / "ledger.sqlite3")
    assignment = snapshot["assignments"].get(envelope.get("assignment_id"))
    if (not assignment or not assignment.get("session_id") or
            envelope.get("owner_id") != assignment["owner_id"] or
            envelope.get("session_id") != assignment["session_id"] or
            envelope.get("manifest_digest") != snapshot["trial"]["manifest_digest"]):
        raise SafetyError("Owner report does not bind its retained actual native session")
    operation, data = envelope["operation"], envelope["payload"]
    if operation not in {"attempt", "exhaust", "inputs", "event"}:
        raise SafetyError("Owner observations cannot authorize lifecycle progression or publication")
    if operation == "event" and data.get("record", {}).get("owner_id") != assignment["owner_id"]:
        raise SafetyError("Owner event must preserve its actual owner identity")
    if snapshot["authorization"]["mode"] != "RUN":
        return record_after_stop(root, envelope, role="owner")
    return submit(root, envelope, role="owner")


def serve(root, executable, manifest, contract):
    validate_runtime_identity(executable, contract["runtime"])
    approval = validate_approval(manifest, contract)
    observed = validate_launch_contract(manifest, contract)
    if root.exists():
        raise SafetyError("Run already exists; no adoption or provider replay. Use status/recover/record")
    root.mkdir(parents=True)
    immutable_json(root / "manifest.json", manifest)
    immutable_json(root / "launch-contract.json", contract)
    immutable_json(root / "model-observation.json", observed)
    immutable_json(root / "approval-observation.json", approval)
    configure(root)
    ledger = Ledger(root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
    ledger.register_trial(manifest=manifest, event_id="coordinator-confirmed-manifest")
    revision = ledger.authorize("RUN", event_id="explicit-real-trial-preparation", expected_revision=0,
        reason="Explicit bounded native preparation only; provider work requires separate activation gates")["revision"]
    if contract["workflow_config"]["run_id"] != root.name:
        raise SafetyError("Workflow configuration does not identify this exact run")
    immutable_json(root / "workflow-config.json", contract["workflow_config"])
    ledger.configure_trial_workflow(config=contract["workflow_config"], event_id="approved-controller-workflow",
                                    authorization_revision=revision)
    runtime = TrialRuntime(root, ledger, executable, contract)
    api_url, flow_id, result = None, None, None
    try:
        api_url = runtime.start_prefect(revision)
        from prefect import flow
        from prefect.context import get_run_context

        @flow(name="bounded-four-qwen-real-functions", retries=0)
        def bounded_trial():
            nonlocal flow_id
            flow_id = str(get_run_context().flow_run.id)
            while not ledger.snapshot()["trial"]["workflow"]["target_prepared"]:
                if ledger.authorization()["mode"] != "RUN":
                    raise SafetyError("Independent target preparation was stopped before native root creation")
                runtime.workflow.tick()
                actions = ledger.snapshot()["trial"]["workflow"]["actions"].values()
                if any(action["kind"] == "prepare_target" and action["status"] in {
                        "failed", "rejected", "uncertain"} for action in actions):
                    raise SafetyError("Independent target preparation did not complete; retained effects require recovery")
                time.sleep(0.05)
            runtime.prepare_initial()
            runtime.prepare_observers_and_children()
            return runtime.serve()

        result = bounded_trial()
        return result
    finally:
        try:
            runtime.stop(event_id="trial-work-stop", reason="Bounded serve ended; preserve all evidence", include_server=False)
            if api_url:
                # Flow error evidence is retained even when no completed log exists.
                drain_prefect_clients(root, api_url, flow_id if result is not None else None)
        finally:
            runtime.stop(event_id="trial-final-stop", reason="Verify all exact-run native jobs exited")


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", nargs="?", default="status",
                        choices=("status", "inspect-model", "serve", "submit", "report", "stop", "recover", "record", "test"))
    parser.add_argument("--run-id")
    parser.add_argument("--authorize-real-trial-preparation", action="store_true")
    parser.add_argument("--authorize-coordinator-delivery", action="store_true")
    parser.add_argument("--authorize-owner-observation", action="store_true")
    parser.add_argument("--authorize-exact-run-stop", action="store_true")
    parser.add_argument("--authorize-integrated-verification", action="store_true")
    parser.add_argument("--authorize-native-api-probe", action="store_true")
    parser.add_argument("--manifest", type=Path)
    parser.add_argument("--launch-contract", type=Path)
    parser.add_argument("--envelope", type=Path)
    parser.add_argument("--omp", type=Path)
    parser.add_argument("--test-target", action="append", help="Owned package test file, optionally ::Class::method")
    args = parser.parse_args(argv)
    check_worktree(real_trial=True, engineering_candidate=args.command in {"test", "status", "stop", "recover"})
    if args.command == "inspect-model":
        result = inspect_model()
    elif args.command == "status":
        if not args.run_id:
            result = {"executing": False, "message": "Supply exact --run-id; no latest-run adoption"}
        else:
            root = run_root(args.run_id)
            if not (root / "ledger.sqlite3").is_file():
                result = {"executing": False, "state": "not_initialized"}
            else:
                from .trial_metrics import trial_report
                result = read_snapshot(root / "ledger.sqlite3")
                result["metrics"] = trial_report(result)
    else:
        if not args.run_id:
            parser.error("Every mutation requires exact --run-id")
        root = run_root(args.run_id)
        if args.command == "serve":
            if not args.authorize_real_trial_preparation or not args.manifest or not args.launch_contract or not args.omp:
                parser.error("serve requires preparation authorization, manifest, launch-contract and native --omp")
            executable = args.omp.resolve(strict=True)
            if executable.name.lower() != "omp.exe":
                parser.error("Native OMP executable required")
            result = serve(root, executable, json.loads(args.manifest.read_text(encoding="utf-8")),
                           json.loads(args.launch_contract.read_text(encoding="utf-8")))
        elif args.command in {"stop", "recover"}:
            if not args.authorize_exact_run_stop or not (root / "ledger.sqlite3").is_file():
                parser.error("Exact-run STOP authorization and existing ledger required")
            result = recover(root, "Explicit coordinator exact-run STOP/recovery", observe_effects=args.command == "recover")
        elif args.command == "test":
            if not args.authorize_integrated_verification or root.exists():
                parser.error("Fresh run plus explicit integrated verification authorization required")
            root.mkdir(parents=True)
            configure(root)
            result = run_tests(root, targets=args.test_target, native_api_probe=args.authorize_native_api_probe,
                               timeout_seconds=600 if args.test_target is None else 300)
        elif args.command == "report":
            if not args.authorize_owner_observation or not args.envelope:
                parser.error("Explicit owner observation and exact envelope required")
            result = report(root, json.loads(args.envelope.read_text(encoding="utf-8")))
        else:
            if not args.authorize_coordinator_delivery or not args.envelope:
                parser.error("Explicit coordinator delivery and exact envelope required")
            envelope = json.loads(args.envelope.read_text(encoding="utf-8"))
            result = submit(root, envelope) if args.command == "submit" else record_after_stop(root, envelope)
    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (SafetyError, RuntimeError, OSError, ValueError) as error:
        print(str(error), file=sys.stderr)
        raise SystemExit(1)
