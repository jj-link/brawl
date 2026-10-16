"""Read-only trial observations; never production progress or an acceptance engine.

Ledger timestamps describe ingestion/admission, not inferred native work. Explicit
phase intervals require a shared clock identity. Missing ends, mixed clocks and
unobserved phases remain visible rather than being filled with model assertions.
"""

from datetime import datetime, timezone

from .policy import TRIAL_PHASES
from .state import StateError


def _time(value):
    try:
        result = datetime.fromisoformat(value)
        if result.utcoffset() is None:
            raise ValueError("Missing timezone")
        return result
    except (TypeError, ValueError) as exc:
        raise StateError("Metrics need timezone-aware observed timestamps") from exc


def _interval(left, right):
    """Only compare clocks explicitly identified as the same observation clock."""
    if left["timestamp_provenance"]["clock_id"] != right["timestamp_provenance"]["clock_id"]:
        return None
    seconds = (_time(right["observed_at"]) - _time(left["observed_at"])).total_seconds()
    return seconds if seconds >= 0 else None


def _terminal_cutoff(snapshot, trial):
    """Last canonical closure ingestion, only with all eight native exits proven."""
    reserved = {item["assignment_id"] for item in trial["manifest"]["reservations"]}
    if len(reserved) != 8 or set(trial["claims"]) != reserved:
        return None
    cutoffs = []
    for key in reserved:
        claim = trial["claims"][key]
        assignment = snapshot["assignments"].get(key, {})
        closures = assignment.get("external_receipts", {}).get("closed", [])
        process = snapshot.get("processes", {}).get(claim.get("process_id"))
        if (assignment.get("status") != "closed" or not claim.get("closed_at") or not closures
            or not assignment.get("cleanup") or not assignment.get("publication_acknowledgment")
            or process is None or process.get("active") is not False):
            return None
        proof = process.get("exit_proof")
        receipt = closures[-1]["receipt"]
        if (not proof or proof.get("observed_exit") is not True
            or process.get("session_id") != claim.get("session_id")
            or receipt.get("assignment_id") != key or receipt.get("owner_id") != claim["owner_id"]
            or receipt.get("session_id") != claim.get("session_id")
            or receipt.get("process_id") != claim.get("process_id")
            or receipt.get("exit_evidence_ref") != proof.get("evidence_ref")):
            return None
        cutoffs.append(_time(claim["closed_at"]))
    return max(cutoffs)


def _workflow_report(snapshot, trial, end_text):
    workflow = trial.get("workflow")
    if workflow is None:
        return None
    end = _time(end_text)
    actions, totals, owner_turns = [], {}, []
    for action in workflow["actions"].values():
        final = action["observations"][-1]["record"] if action["observations"] else None
        seconds, dispatch_delay, recovery_seconds = None, None, None
        recovered = bool((action.get("result") or {}).get("recovered_from_remote")
                         or (action.get("result") or {}).get("recovered_from_git")
                         or (action.get("result") or {}).get("recovered_restoration"))
        if final is not None and action["status"] not in {"admitted", "uncertain"}:
            seconds = _interval(dict(final, observed_at=final["started_at"]), final)
            if final["timestamp_provenance"]["clock_id"] == "ledger_utc":
                dispatch_delay = (_time(final["started_at"]) - _time(action["admitted_at"])).total_seconds()
                if dispatch_delay < 0:
                    dispatch_delay = None
        if recovered:
            recovery_seconds, seconds, dispatch_delay = seconds, None, None
        if seconds is not None:
            totals[action["kind"]] = totals.get(action["kind"], 0.0) + seconds
        actions.append({
            "effect_id": action["effect_id"], "assignment_id": action["assignment_id"], "kind": action["kind"],
            "status": action["status"], "binding": action["binding"], "admitted_at": action["admitted_at"],
            "observed_action_seconds": seconds, "admission_to_observed_start_seconds": dispatch_delay,
            "recovery_query_seconds": recovery_seconds,
            "timestamp_provenance": final["timestamp_provenance"] if final else None,
            "evidence_refs": final["evidence_refs"] if final else [],
            "superseded": action.get("superseded", False),
            "recovery_required": action.get("recovery_required", False), "restored_by": action.get("restored_by"),
            "verification_reused_from": (action.get("result") or {}).get("reused_from"),
            "coverage": (action.get("result") or {}).get("coverage") if action["kind"] == "validate_delivery" else None,
            "reviewed_criteria": (action.get("result") or {}).get("reviewed_criteria") if action["kind"] == "review" else None,
            "qualification": ("Actual read-only recovery query; original Git execution time/exit is unobserved." if recovered else
                              "Observed action interval, including local tool/transport waits; not inferred model compute."),
        })
    for key, state in workflow["assignments"].items():
        for effect_id, completion in state["owner_completions"].items():
            record = completion["record"]
            owner_turns.append({
                "assignment_id": key, "effect_id": effect_id,
                "seconds": _interval(dict(record, observed_at=record["started_at"]), record),
                "timestamp_provenance": record["timestamp_provenance"],
                "evidence_refs": record["evidence_refs"],
            })
    intervals, reported_intervals = [], []
    interval_totals = {}
    for event in trial["events"]:
        if event["kind"] != "interval":
            continue
        record = event["record"]
        if event.get("measurement_origin") != "native_host":
            reported_intervals.append(event)
            continue
        seconds = _interval(dict(record, observed_at=record["started_at"]), record)
        intervals.append(dict(assignment_id=event["assignment_id"], event_id=event["event_id"],
                              phase=record["phase"], seconds=seconds,
                              timestamp_provenance=record["timestamp_provenance"],
                              qualification=record.get("qualification"),
                              evidence_refs=record["evidence_refs"], native_evidence=record["native_evidence"],
                              native_actor_id=record["native_actor_id"], native_session_id=record["native_session_id"]))
        if seconds is not None:
            interval_totals[record["phase"]] = interval_totals.get(record["phase"], 0.0) + seconds
    waits, ready_waits, model_slots = {}, {}, {}
    samples = trial["capacity_history"]
    for index, sample in enumerate(samples):
        left = _time(sample["at"])
        if left >= end:
            break
        right = min(_time(samples[index + 1]["at"]), end) if index + 1 < len(samples) else end
        duration = (right - left).total_seconds()
        if duration < 0:
            raise StateError("Controller readiness clock moved backwards")
        for key, state in sample.get("workflow", {}).items():
            if state["reason"] != "closed":
                by_reason = waits.setdefault(key, {})
                by_reason[state["reason"]] = by_reason.get(state["reason"], 0.0) + duration
            if state["ready"]:
                ready_waits[state["kind"]] = ready_waits.get(state["kind"], 0.0) + duration
        for lease in sample.get("model_leases", []):
            identity = (lease["provider"], lease["model"])
            row = model_slots.setdefault(identity, dict(provider=lease["provider"], model=lease["model"],
                capacity=lease["capacity"], reserved_slot_seconds=0.0, unreserved_slot_seconds=0.0))
            row["reserved_slot_seconds"] += lease["held"] * duration
            row["unreserved_slot_seconds"] += (lease["capacity"] - lease["held"]) * duration
    criterion_acceptance = {}
    for key, state in workflow["assignments"].items():
        assignment = snapshot["assignments"][key]
        validation = state.get("validation")
        acceptance = assignment.get("acceptance")
        verification = assignment.get("verification")
        criterion_acceptance[key] = {
            "mode": acceptance.get("mode") if acceptance else None,
            "policy_identity": acceptance.get("policy_identity") if acceptance else None,
            "validation_action_id": validation["action_id"] if validation else None,
            "coverage_identity": validation.get("coverage_identity") if validation else None,
            "coverage_current": bool(validation and verification and verification.get("valid")
                                     and verification["input_identity"] == assignment["current_input_identity"]
                                     and validation["delivery_id"] == state["current_delivery_id"]),
            "unresolved_criteria": validation["result"].get("coverage", {}).get("unresolved") if validation else None,
            "actual_model_review_action_id": assignment["review"].get("controller_action_id") if assignment["review"] else None,
        }
    separated = ("model_execution", "review_execution", "model_queue", "tool_execution", "tool_queue",
                 "parent_review_wait", "instrumentation")
    return {
        "run_id": workflow["config"]["run_id"], "config_digest": workflow["config_digest"],
        "profile": workflow["config"]["profile"], "publication_target": workflow["config"]["publication_target"],
        "acceptance_policy": workflow["config"].get("acceptance_policy"), "criterion_acceptance": criterion_acceptance,
        "actions": actions, "observed_action_seconds_by_kind": totals, "native_owner_turn_intervals": owner_turns,
        "explicit_execution_intervals": intervals,
        "untrusted_reported_intervals": reported_intervals,
        "explicit_interval_seconds_by_phase": {phase: interval_totals.get(phase) for phase in separated},
        "unobserved_execution_categories": [phase for phase in separated if phase not in interval_totals],
        "controller_eligible_action_wait_seconds": ready_waits,
        "assignment_readiness_seconds_by_reason": waits, "model_lease_slot_seconds": list(model_slots.values()),
        "uncertain_effect_ids": [action["effect_id"] for action in actions if action["status"] == "uncertain"],
        "failed_effect_ids": [action["effect_id"] for action in actions if action["status"] == "failed"],
        "rejected_effect_ids": [action["effect_id"] for action in actions if action["status"] == "rejected"],
        "target_recovery_effect_ids": [action["effect_id"] for action in actions if action["recovery_required"]],
        "qualification": (
            "Readiness is ledger-observed eligibility, not inferred inactivity. Inference reservations include whole native turns, "
            "not measured GPU utilization. Explicit nested spans may overlap; they are not additive to lifecycle wall time. "
            "Criterion acceptance permits publication work, not reconstructed credit; mechanical coverage is neither a model decision nor exercised runtime. "
            "No comparable historical four-Qwen baseline, speedup, or unobserved instrumentation cost is inferred."
        ),
    }


def trial_report(snapshot: dict, *, as_of: str | None = None) -> dict:
    """Report retained observations, with no mutation and no production credit.

    ``as_of`` is the reporting clock, not a fabricated worker end time. A fully
    closed eight-assignment run uses its observed terminal ledger-UTC cutoff;
    unfinished or incompletely observed runs retain the live reporting window.
    Rates include setup/wait/cleanup, not just productive time, and do not
    establish sustained production performance.
    """
    end_text = as_of or datetime.now(timezone.utc).isoformat()
    end = _time(end_text)
    trial = snapshot.get("trial")
    if trial is None:
        return {"scope": "control_or_fixture", "accepted_matching_functions": 0,
                "accepted_original_bytes": 0, "production_progress_credit": 0,
                "elapsed_seconds": None, "functions_per_hour": None, "bytes_per_hour": None,
                "qualification": "Fixture success has zero reconstructed credit."}
    start = _time(trial["created_at"])
    if end < start or end < _time(snapshot.get("updated_at", trial["created_at"])):
        raise StateError("Report cutoff cannot precede the retained ledger snapshot")
    requested_as_of = end_text
    terminal = _terminal_cutoff(snapshot, trial)
    if terminal is not None:
        if terminal < start or terminal > end:
            raise StateError("Observed terminal cutoff is outside the reporting window")
        end = terminal
        end_text = terminal.isoformat()
    elapsed = (end - start).total_seconds()
    capacity = trial["capacity_history"]
    idle_seconds = 0.0
    idle_by_reason = {}
    queue_wait_seconds = {}
    for index, sample in enumerate(capacity):
        left = _time(sample["at"])
        if left >= end:
            break
        right = min(_time(capacity[index + 1]["at"]), end) if index + 1 < len(capacity) else end
        duration = (right - left).total_seconds()
        if duration < 0:
            raise StateError("Ledger clock moved backwards; capacity duration is unobserved")
        idle_seconds += sample["eligible_idle_slots"] * duration
        eligible_slots = sample["eligible_idle_slots"]
        if eligible_slots:
            idle_by_reason["eligible"] = idle_by_reason.get("eligible", 0.0) + eligible_slots * duration
        remaining = sample["free_slots"] - eligible_slots
        if remaining:
            reason = "no_eligible_work" if sample["reason"] == "eligible" else sample["reason"]
            idle_by_reason[reason] = idle_by_reason.get(reason, 0.0) + remaining * duration
        for queued_reason in sample["queued_reasons"].values():
            queue_wait_seconds[queued_reason] = queue_wait_seconds.get(queued_reason, 0.0) + duration
    assignments, accepted, exhausted, unfinished, closed = {}, [], [], [], []
    totals = {phase: 0.0 for phase in sorted(TRIAL_PHASES)}
    for key, claim in trial["claims"].items():
        assignment = snapshot["assignments"][key]
        events = [event for event in trial["events"] if event["assignment_id"] == key and event["kind"] == "phase"]
        durations = {phase: 0.0 for phase in sorted(TRIAL_PHASES)}
        unobserved = []
        for index, event in enumerate(events):
            left = event["record"]
            right = events[index + 1]["record"] if index + 1 < len(events) else None
            if right is None:
                # A native-clock open interval is not silently closed with a
                # wall-clock report timestamp. A closed receipt may supply it.
                closes = assignment.get("external_receipts", {}).get("closed", [])
                right = closes[-1]["receipt"] if closes else None
                if right is None and left["timestamp_provenance"]["clock_id"] == "ledger_utc":
                    right = {"observed_at": end_text, "timestamp_provenance": {"clock_id": "ledger_utc"}}
            seconds = _interval(left, right) if right is not None else None
            if seconds is None:
                unobserved.append({"from_event": event["event_id"], "phase": left["phase"],
                                   "reason": "missing end, mixed clock identities, or reversed timestamps"})
            else:
                durations[left["phase"]] += seconds
        if not events:
            unobserved.append({"reason": "No native phase observations; assignment state is not work timing."})
        receipts = assignment.get("external_receipts", {})
        ack = assignment.get("publication_acknowledgment")
        verification = assignment.get("verification")
        credited = bool(ack and ack.get("accepted_matching") is True and verification
                        and verification["valid"] and verification["input_identity"] == ack["input_identity"]
                        and verification["evidence"]["scope"] == "reconstruction"
                        and assignment.get("selection") is None)
        if credited:
            accepted.append(key)
        if assignment.get("selection") is not None or assignment["stages"][-1]["exhausted"]:
            exhausted.append(key)
        if assignment["status"] == "closed":
            closed.append(key)
        else:
            unfinished.append(key)
        latency = None
        if receipts.get("cleanup") and receipts.get("closed"):
            latency = _interval(receipts["cleanup"][-1]["receipt"], receipts["closed"][-1]["receipt"])
        receipt_timings = {}
        for kind, entries in receipts.items():
            receipt_timings[kind] = [{
                "event_id": entry["event_id"],
                "seconds": _interval(dict(entry["receipt"], observed_at=entry["receipt"]["started_at"]),
                                     entry["receipt"]),
                "timestamp_provenance": entry["receipt"]["timestamp_provenance"],
                "timing_scope": entry["receipt"].get("timing_scope", "observed_receipt_interval"),
            } for entry in entries]
        # These are ingestion waits, deliberately separate from native work
        # intervals. Delayed delivery is visible rather than charged to an owner.
        points = {kind: entries[-1]["recorded_at"] for kind, entries in receipts.items() if entries}
        review_ready = [item["at"] for item in assignment["history"] if item.get("to") == "review_wait"]
        if review_ready:
            points["review_ready"] = review_ready[-1]
        ingestion_waits = {}
        for label, left, right in (
            ("parent_review_wait", "review_ready", "review"),
            ("owner_reconciliation", "review", "materialization"),
            ("publication_wait", "materialization", "commit"),
            ("commit_to_push", "commit", "push"), ("publication_ack_wait", "push", "ack"),
            ("cleanup_wait", "ack", "cleanup"), ("cleanup_to_close", "cleanup", "closed"),
        ):
            seconds = (_time(points[right]) - _time(points[left])).total_seconds() if left in points and right in points else None
            ingestion_waits[label] = seconds if seconds is not None and seconds >= 0 else None
        if trial.get("workflow") is not None:
            ingestion_waits["substantive_review_turnaround"] = ingestion_waits["parent_review_wait"]
            ingestion_waits["review_to_materialization"] = ingestion_waits["owner_reconciliation"]
            ingestion_waits["parent_review_wait"] = None
            ingestion_waits["owner_reconciliation"] = None
        for phase, seconds in durations.items():
            totals[phase] += seconds
        inherited_history = (assignment.get("admitted_history")
                             or assignment["identity"].get("history", assignment["identity"]["reservation"]["history"]))
        assignments[key] = {"status": assignment["status"], "slot": claim["slot"],
                            "owner_id": claim["owner_id"], "accepted_matching": credited,
                            "criterion_acceptance_mode": (assignment.get("acceptance") or {}).get("mode"),
                            "observed_phase_seconds": durations, "unobserved_intervals": unobserved,
                            "cleanup_to_native_close_seconds": latency,
                            "receipt_elapsed_seconds": receipt_timings,
                            "ledger_ingestion_wait_seconds": ingestion_waits,
                            "ingestion_wait_qualification": "Receipt-delivery intervals, not inferred native work or parent decision time.",
                            "inherited_history": inherited_history,
                            "original_reserved_history": assignment["identity"]["reservation"]["history"],
                            "attempt_count_scope": inherited_history.get("count_scope", "known_history" if inherited_history["status"] == "known" else "unresolved"),
                            "lifetime_history_totals": inherited_history.get("lifetime_totals", "known" if inherited_history["status"] == "known" else "unknown"),
                            "history_resolution": assignment.get("history_admission", assignment["identity"].get("history_resolution")),
                            "post_closure_input_observations": assignment.get("post_closure_input_observations", []),
                            "post_ack_input_observations": assignment.get("post_ack_input_observations", []),
                            "measured_counts": {stage["stage"]: {"initial": stage["initial_count"],
                                                                 "corrections": stage["corrections"]}
                                                for stage in assignment["stages"]}}
    refills = []
    for slot in range(4):
        claims = sorted((claim for claim in trial["claims"].values() if claim["slot"] == slot), key=lambda item: item["claimed_at"])
        for previous, current in zip(claims, claims[1:]):
            seconds = (_time(current["claimed_at"]) - _time(previous["closed_at"])).total_seconds()
            refills.append({"slot": slot, "previous": previous["assignment_id"],
                            "next": current["assignment_id"], "seconds": seconds,
                            "timestamp_provenance": "ledger UTC closure receipt to independent claim admission"})
    observations = {kind: [event for event in trial["events"] if event["kind"] == kind]
                    for kind in ("intervention", "violation", "recovery")}
    accepted_bytes = sum(snapshot["assignments"][key]["function"]["size"] for key in accepted)
    return {"scope": "bounded_real_function_trial", "trial_id": trial["manifest"]["trial_id"],
            "manifest_digest": trial["manifest_digest"], "as_of": requested_as_of, "elapsed_seconds": elapsed,
            "measurement_cutoff": end_text, "terminal_cutoff_observed": terminal is not None,
            "terminal_cutoff_basis": "Last ledger-UTC canonical closure with all eight native exits proven" if terminal is not None else
                                     "No complete observed terminal cutoff; live as_of window",
            "timestamp_provenance": "ledger UTC ingestion window; explicit phase events use their stated clocks",
            "accepted_matching_functions": len(accepted), "accepted_assignment_ids": accepted,
            "accepted_original_bytes": accepted_bytes, "production_progress_credit": 0,
            "functions_per_hour": len(accepted) * 3600 / elapsed if elapsed else None,
            "bytes_per_hour": accepted_bytes * 3600 / elapsed if elapsed else None,
            "eligible_idle_slot_seconds": idle_seconds, "idle_slot_seconds_by_reason": idle_by_reason,
            "queued_assignment_seconds_by_reason": queue_wait_seconds,
            "automatic_workflow": _workflow_report(snapshot, trial, end_text),
            "observed_phase_seconds": totals, "assignments": assignments, "independent_refills": refills,
            "unfinished_assignment_ids": unfinished, "exhausted_assignment_ids": exhausted,
            "closed_assignment_ids": closed,
            "unclaimed_assignment_ids": [r["assignment_id"] for r in trial["manifest"]["reservations"] if r["assignment_id"] not in trial["claims"]],
            "observed_interventions": observations["intervention"], "observed_violations": observations["violation"],
            "observed_recoveries": observations["recovery"],
            "qualification": "Evidence receipts are attestations, not model assertions. Missing intervals remain unobserved. Eight small functions do not establish sustained production throughput."}
