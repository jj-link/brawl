# Orchestration redesign plan

## Purpose and ownership

The deliverable is a complete redesign of the orchestration system, not merely a four-agent experiment. Maximize productive throughput and consistent agent/orchestrator behavior jointly. Review, integration, publication, and cleanup are first-class parts of the redesign.

This is this session's working plan for that redesign. The reconstruction coordinator's `PLAN.md` supplies the existing reconstruction rules and shared-resource boundaries; it does not replace this implementation plan. The four-Qwen trial is one validation step within the redesign.

This document was created on 2026-10-15 by recovering the original agreement and incorporating the user's scope correction. It is not a claim that the promised separate plan existed earlier. It belongs to the orchestration-design session in its private engineering workspace. The user has now approved the execution order and detailed checklist below. The existing reconstruction session retains its active MAIN checkout; the new controller owns its isolated trial lifecycle and publication target. A later explicit cutover transfers production authority.

Dashboard registration is part of this controller's authorized trial setup and lifecycle. This session/controller selects available observer ports, records exact assignment/root/process/journal bindings, and maintains only its own rows in the shared registry. Preserve unrelated rows and listeners; detect and resolve actual port or concurrent-file conflicts. A named assistant session, an old ownership message, or an unanswered coordination request is not an approval prerequisite. Use file-only coordination when a concrete shared-resource conflict needs resolution, not for routine registration, launch or refill.

## Recovered agreement

The native session record `01a0e6d5-6a3d-77e7-9eb7-fd2d5544a68a` contains the basis for this work:

- Assistant proposal `35ae75c2`, 2026-10-13: retain OMP and the existing models; evaluate Prefect for enforcing scheduling, handoff, stopping, recovery, and publication rules through durable state rather than conversational discretion. Address publication rework and worker tooling as well as scheduling.
- User authorization `04104f04`, 2026-10-15: proceed while the original orchestrator continues; coordinate ownership with it.
- User requirements `37eb2d56`, `02dd890e`, and `aa262222`: maximize both throughput and consistent behavior; specifically address review/integration/publication/cleanup; consider improvements across the process.
- User clarification `ec369753`: the project is a complete orchestration redesign. The four-Qwen trial is not the whole project.

The later authorized trial uses four concurrent Spark1 Qwen3.8-Flash-Next agents on eight real functions. There is no single-agent preliminary stage. Actual individual dashboard streams are required.

## Target design

Retain OMP as the native agent/session/tool runner and use the existing Prefect integration and durable ledger to implement the real workflow. Routine decisions and progression belong in software. The model performs reconstruction and specifically identified substantive judgments that fixed checks do not cover; it does not redefine scheduling, ownership, authorization, attempt limits, or acceptance rules. Reuse exercised components rather than restarting tool selection.

| Component | Responsibility |
|---|---|
| Assignment and lifecycle ledger | Persist exact assignment, owner/session, model stage, workspace, relevant input identities, measured attempts, best candidate, authorization, and lifecycle state. |
| Workflow executor | Advance eligible work from durable native/ledger events through verification, review, integration, publication, cleanup and independent refill; enforce the approved profile, duplicate protection and recovery rules. |
| Native OMP connection | Create genuine fresh owners, retain the same owner for its assignment, expose real tool/model events, and distinguish observing an owner from resuming it. |
| Workspace and verification path | Give each owner a usable native-Windows environment and exclusive mutable build state. Reuse verified evidence when relevant inputs are unchanged. |
| Review and publication path | Automatically consume own-only deliveries and execute fixed acceptance checks. Advance mechanically covered results without a model reviewer; dispatch focused review only for recorded unresolved judgments. Publish through the controller-owned target, preparing independently and serializing only conflicting Git mutations. |
| STOP and recovery | Revoke new work, terminate verified owned jobs within the shared shutdown bound, retain observed effects, and require exit evidence before releasing ownership. |
| Dashboard and measurements | Show genuine per-agent output and lifecycle state; distinguish accepted source from drafts, waiting, publication, and setup work. |

Prefect state alone is not proof of authorization, process termination, a matching reconstruction, or a successful push. A model's completion message is not proof of those outcomes either.

Production worker counts and model choices remain an explicit approved configuration, not a value inferred from an old conversation. The current four-Qwen trial is a separate profile. Production model/service changes or transfer of existing workers require the agreed cutover authority.

## End-to-end lifecycle

1. **Admit eligible work.** Bind the assignment to its authorized model/profile, actual inputs, workspace, evidence, and existing attempt rules. Retain uncertainty honestly without inventing another trial budget or an additional approval step.
2. **Create the fresh owner.** One new function gets one new native owner/session and exclusive workspace. A continuation belongs to that same assignment; it is not permission to reuse the owner for another function.
3. **Reconstruct and measure.** The owner performs its own implementation, registration, compile/compare loop, and integration. Preserve each measured attempt and the best candidate. Tool/setup failures are not reconstruction corrections.
4. **Verify against the fixed criteria.** Require the existing source-selection, object/data/relocation and native binary-hash evidence. An unrelated MAIN commit is not a reason to rebuild or redo the delivery.
5. **Accept mechanically or request focused review.** If passing fixed checks cover every acceptance criterion, record mechanical acceptance and advance without creating a reviewer. Otherwise bind each unresolved criterion and its concrete reason to the actual delivery/evidence and request only that judgment. Mechanical failures return to the same owner; a model decision cannot waive them.
6. **Reconcile and publish.** Prepare own-only patches and checked working-file materialization. Acquire the short exclusive shared-file/Git window only when needed. Preserve unrelated work; record each separate commit and successful push.
7. **Acknowledge publication.** Bind the actual published source and acceptance outcome to the assignment. Drafts, private matches, materialized files, commits, pushes, and accepted source remain distinct states.
8. **Clean up and close.** The same owner performs authorized evidence-preserving cleanup. Retain required source, inputs, measured/best candidates, packets, and receipts. Verify native job/session exit; do not treat a returned agent turn as closure.
9. **Refill independently.** When an assignment's slot is eligible for replacement under the approved lifecycle, start its next fresh owner without waiting for a wave of unrelated owners.
10. **Publish the dashboard checkpoint.** The retained dashboard publisher finishes its selected committed checkpoint. Unrelated MAIN advancement does not repeatedly restart that work.

Duplicate events must not duplicate an assignment, model dispatch, commit, or push. Recovery must not adopt a foreign session, reset a started stage, discard better work, or replay an uncertain external effect.

## Removing bottlenecks and opportunities for error

| Area | Required redesign behavior | Evidence to collect |
|---|---|---|
| Scheduling | Refill eligible slots from recorded completion/closure events rather than another conversational planning cycle. Keep independent work running. | Eligible idle-slot time; closure-to-refill latency; actual simultaneous active work. |
| Tooling and setup | Supply working native tools and precise workspace paths. Classify infrastructure failures separately from candidate failures. | Setup duration, tool failures, manual interventions, and time blocked by each cause. |
| Review | Use fixed acceptance criteria and relevant-input identities. Avoid a model call when passing mechanical checks cover the criteria; scope required review to recorded unresolved judgments and permit independent deliveries to continue. | Review reason, readiness-to-decision time, actual model calls, rejection reasons, repeated checks and changed-input justification. |
| Integration | Keep implementation, registration, verification, reconciliation, and cleanup with the assignment owner. Avoid a separate integration handoff. | Integration time, ownership changes, corrections caused by handoff errors. |
| Publication | Prepare independently; serialize only actual shared-file materialization and Git mutation. Reuse valid narrow deliveries across unrelated commits. | Ready-to-materialize/commit/push time, exclusive-window duration, publication queue time. |
| Cleanup | Use exact ownership and retention records rather than broad deletion or repeated exploratory cleanup. | Publication-ACK-to-close time, cleanup interventions, retained evidence, actual process exits. |
| Reporting | Preserve accepted work and its original verification/publication binding after closure; later observations must not erase historical throughput. | Accepted functions/bytes per hour, stable completed-run results, explicitly separated unaccepted/setup work. |
| Recovery and STOP | Enforce one bounded aggregate shutdown, preserve observed in-flight effects, and resume only authorized original assignments. | Real termination receipts, duplicate/replay prevention, violations and recovery outcomes. |

A faster graph is not sufficient evidence of better orchestration. Measure productive throughput together with instruction/ownership violations, intervention count, and recovery behavior. Compare equivalent workloads and acceptance criteria. A successful fixture or eight tiny functions does not establish sustained production performance.

## Approved execution order

1. **Finish the complete controller workflow.** Implement automatic delivery validation, mechanical acceptance and selective review for explicit unresolved judgments, then connect integration, publication, cleanup and independent refill. Core lifecycle automation is required before the trial, not deferred until after it.
2. **Verify the connected system.** Exercise actual native processes and Git operations, including STOP, recovery, duplicate events and interrupted publication. Reuse unchanged valid evidence.
3. **Run the four-Qwen, eight-function trial.** The controller advances the entire lifecycle; real native dashboard streams and independent refill are required.
4. **Measure and improve both objectives.** Use accepted-work throughput, waiting, interventions, violations and recovery to identify and remove the largest avoidable bottlenecks.
5. **Validate the approved production profile and perform explicit cutover.** Demonstrate production operation before declaring the redesign complete.

Updating this file and recording baseline measurements happen alongside implementation. They are not another planning or tool-selection gate.

## Approved selective-review policy

The user approved replacing mandatory per-function model review with these rules:

1. Execute the existing deterministic acceptance checks for every delivery: actual compilation, required code/data/relocation comparisons, source and link selection, binary hashes, relevant-input identities and permitted change scope. Preserve the existing acceptance criteria.
2. Advance automatically only when controller-verified evidence covers every applicable criterion and all required checks pass. Record mechanical acceptance as such, bound to the delivery, source, inputs and policy. A worker's claim, function size or matching label is not coverage proof; no reviewer session or fabricated model-approval receipt is needed for this path.
3. Request model review only for a recorded unresolved judgment. Name the criterion, concrete reason and relevant evidence; give the reviewer that scope. Missing or unknown coverage is not an automatic pass. Changed relevant inputs invalidate the corresponding acceptance or judgment.
4. Return failed mechanical checks to the same assignment owner under the existing correction/attempt rules. A model approval cannot override failed or invalidated evidence. Preserve the separate exhausted-final-attempt publication policy and its distinction from accepted matching work.

Each delivery receives fresh identity, ownership and criterion-coverage assessment. Preserve the existing reuse of native check results when their exact source, relevant inputs, artifacts, check semantics and retained evidence identities are unchanged. Reusing those results is not permission to reuse an old acceptance decision or omit a newly required judgment; unrelated repository advancement does not force a rebuild.

Routine shared-registration insertions may receive mechanical ownership coverage only when a bounded checker proves the authorized transformation against actual preimages and the fixed module/source/range, preserving unrelated content. Merely naming allowed configure/splits paths is insufficient. Unrecognized transformations retain a concrete ownership judgment; the real routine registration path must be exercised rather than demonstrating automatic acceptance only with source-only fixtures.

This policy changes review eligibility, not OMP defaults, model profiles or credential-store authority. The six unpublished Sol-review/authentication edits remain retained and excluded from the approved candidate. The implementation and its verification start from the published controller at `e2dfb9f84900b08d2cd46f1e3b7b7c476f2ce15b`; the original engineering/reconstruction baseline remains `d0d182fcfc11d69fcf72c2e8fcc6dd709a93658f`.


## Implementation ownership and interfaces

- Parent: orchestration, this plan, scope decisions and file-only peer coordination. The parent does not write implementation code.
- Retained `QwenTrialLedgerOwner`: durable lifecycle policy, action admission/completion/recovery, assignment state and metrics, with its existing ledger/policy/metrics tests.
- Retained `QwenTrialRuntimeOwner`: integration owner for native execution, automatic workflow decisions/execution, required review routing, isolated publication, cleanup/refill and runtime/CLI tests.
- Engineering and review subagents must use Sol 6.1 or Astra. The retained engineering owners use Astra. `ControllerNativeReview61` and `ControllerDeliveryReview61` use explicit Sol 6.1 routing for subsequent focused reviews; the earlier Sol 5.6 reviewers remain parked and their completed reports remain retained evidence.
- Ledger/runtime contract: a runtime action is bound to the exact run, assignment, owner, relevant inputs and effect identity. The ledger admits an eligible action once, preserves its outcome or uncertainty, orders STOP against admission, and exposes durable readiness. Runtime executes admitted actions through owned native/Git jobs and records actual evidence. An external chat message is not a routine progression prerequisite.
- Owners agree concrete method/data names directly and keep source-file ownership disjoint. RuntimeOwner integrates the interfaces. Independent work proceeds concurrently; only real shared-file or Git conflicts serialize.
- Original packets, before/after/native evidence and the 193-test snapshot remain immutable historical evidence. New source changes receive new evidence. Do not rebuild old packets for unrelated MAIN commits.
- Skip builds, lint, tests and formatters during implementation. After the related changes integrate, run focused regressions and the necessary native/Git smoke once, followed by the integrated verification. Actual trial provider dispatch remains behind its execution/visibility checks.

Implementation milestone: `build/orchestration-eval/controller-integrated-final-002/source-identities.json` freezes 38 reviewed source/test files. Sol 6.1 reviewers accepted the corrected automatic registration, native completion/decision handling and credential-authority boundaries. Actual local Git publication/recovery, changed-path regressions and native root/process-identity startup were exercised; receipts remain in that packet's `verification.json`.

Verification qualification: the earlier full run remains 253 passed, five obsolete-consumer failures and three gated skips; those five changed cases subsequently passed. Later focused correction passes do not relabel it as an all-passing full run. Real assignment/reviewer execution, four-child dashboard streams and independent refill still require their actual execution evidence.

## Independent trial ownership

The approved trial design uses an independently owned publication repository and branch. Its Git index, refs, object writes and working files must not mutate the other session's MAIN repository. The new controller performs actual separate commits and pushes within that target; the old orchestrator is not the trial's routine reviewer, publisher or transition driver.

Reserve and record the exact target before remote publication. Production-MAIN integration and transfer are later explicit steps. An isolated branch run proves its exercised lifecycle, not production-MAIN contention or sustained production performance. Preserve the concurrently running reconstruction session's assignments, services, workers and files.

Selected target: `build/orchestration-eval/controller-publication` within this workspace; remote `https://github.com/jj-link/brawl.git`; branch `orchestration-redesign-trial`. The exact target was absent locally and `git ls-remote --heads` returned no matching remote ref at selection. `build/orchestration-eval/controller-target-001/target.json` records the actual commands and scope. RuntimeOwner owns guarded initialization; fresh checks precede writes.

Publication checkpoint: 39 reviewed code/documentation paths were committed and separately pushed in 13 units to `orchestration-redesign-trial`, ending at local/remote HEAD `1e708b513cd3ebf1ac19f2d3d9bc857c05f6e81f`. `build/orchestration-eval/controller-engineering-publication-001/engineering-publication.json` retains the exact unit sequence and source identities; `complete.json` records STOPPED/all owned processes exited. Parent read all 13 owned push exit proofs. The original engineering baseline and published packets remain unchanged.

## Complete execution checklist

Unchecked means implementation or end-to-end proof is still required; it does not imply every underlying component is absent.

### 1. Objective, rules and evidence

- [x] Replace conflicting old-orchestrator workflow dependencies with the approved controller ownership.
- [x] Make the complete routine lifecycle a pre-trial implementation requirement.
- [x] Separate exercised component evidence from full-workflow proof.
- [x] Define accepted-work throughput, eligible idle time, blocked time, interventions, violations and recovery measurements.
- [x] Establish a comparison baseline from usable retained evidence and record its limitations.
  - Retained baseline evidence and limits: `build/orchestration-eval/controller-baseline-001/baseline-evidence-and-limits.json`. Three GLM publication examples and two concrete consistency failures are recorded; comparable full-lifecycle throughput/idle/intervention rates are not established by those receipts.
- [x] Map approved operating rules to enforcement points and observable verification.
  - `build/orchestration-eval/parent-launch-preflight-001/rule-enforcement-map.json` maps 17 operating rules to inspected implementation points and observable checks, with separate exercised-receipt references and remaining end-to-end qualifications. This is evidence mapping, not another launch prerequisite.
- [x] Track implementation owners, interfaces, dependencies and completion evidence.

### 2. Independent ownership

- [x] Establish the exact controller-owned publication repository/branch and bounded authority.
- [ ] Give the controller responsibility for the reserved assignments' complete lifecycle.
- [ ] Preserve all eight reservations and exclude other sessions' assignments.
- [ ] Isolate mutable source, build outputs, Git indexes/refs/objects and publication state.
- [ ] Preserve unrelated MAIN work, services and model allocations.
- [ ] Use file coordination for actual ownership/resource boundaries rather than routine progression.

### 3. Real workflow controller

- [ ] Implement the real-assignment workflow using existing Prefect/native OMP components.
- [ ] Derive each next eligible action from durable assignment state.
- [ ] Replace conversationally supplied routine transitions with controller decisions.
- [ ] Connect deliveries, verification, review, Git results and exit observations to transitions.
- [ ] Enforce action prerequisites in code.
- [ ] Prevent duplicate assignments, provider requests, commits and pushes on repeated events.
- [ ] Persist recovery state without guessing uncertain outcomes.
- [ ] Keep operator commands for inspection, STOP, authorized recovery and genuine exceptions.
- [ ] Record a concrete reason for every blocked assignment.

### 4. Scheduling and model allocation

- [ ] Represent the approved worker/model profile explicitly rather than hardcoding the system to this trial.
- [ ] Enforce capacity across reconstruction and required substantive review.
- [ ] Route eligible smaller assignments to local models under the approved policy.
- [ ] Improve selection using measured outcomes rather than function size alone.
- [ ] Refill eligible slots independently.
- [ ] Keep unrelated eligible assignments progressing when one is blocked.
- [ ] Distinguish unavailable model capacity from controller-created idle time.
- [ ] Apply existing stage/attempt rules without additional allowances or resets.

### 5. Native owners and workspaces

- [ ] Create a fresh native owner/session for each new function.
- [ ] Retain the same owner through its continuations, integration and cleanup.
- [ ] Bind assignment, workspace, model, session UUID, journal and process creation identity.
- [ ] Supply usable native tools and verified inputs before dispatch.
- [ ] Track all owned subprocesses, including setup and Git processes.
- [ ] Admit child creation and provider dispatch through the STOP boundary.
- [ ] Distinguish response completion from actual owner/process closure.
- [ ] Preserve native Windows execution, hidden subprocesses and project-owned file locations.

### 6. Reconstruction and verification

- [ ] Reuse existing target descriptors, inputs and completed recovery evidence.
- [ ] Provide exact source scope and acceptance criteria.
- [ ] Collect actual compiler, object/comparison, relocation and required binary-hash evidence.
- [ ] Distinguish infrastructure/tool failures from measured reconstruction attempts.
- [ ] Preserve measured attempts and the best candidate.
- [ ] Bind verification to exact source and relevant inputs.
- [ ] Reuse verification across unrelated repository changes.
- [ ] Enforce the existing final-attempt commit/push rule and identify unmatched results honestly.

### 7. Review and integration

The checked selective-review items below record exercised controller, evidence-producer and publication-consumer behavior. Actual function compilation and native reviewer/provider execution remain separate trial requirements; the Git fixtures use synthetic compiler and native-owner admissions.

- [x] Determine review readiness from actual verification and specific unresolved criteria.
- [x] Execute mechanical acceptance checks in code.
- [x] Advance fully mechanically covered deliveries without allocating a model reviewer.
- [x] Route only the recorded unresolved substantive judgments to an appropriately scoped reviewer.
- [ ] Review independent deliveries concurrently within approved capacity.
- [ ] Bind rejections to failed criteria or changed relevant inputs.
- [x] Return corrections to the same assignment owner.
- [x] Prevent model decisions from waiving failed or invalidated mechanical evidence.
- [ ] Keep source/registration reconciliation with that owner.
- [ ] Re-review affected changes without restarting unchanged review.
- [x] Advance deliveries to publication readiness through explicit mechanical acceptance or the required real model judgment, preserving the distinction.

### 8. Publication

- [ ] Generate own-only delivery packets from recorded source/evidence.
- [ ] Bind authority to exact repository, remote, branch, paths and source identities.
- [ ] Validate actual modes, attributes, line endings, working-file hashes and Git blobs.
- [ ] Prepare independent publications concurrently.
- [ ] Serialize only conflicting repository mutations.
- [ ] Reconcile unrelated advancement without unnecessary reconstruction or packet rebuilding.
- [ ] Commit and push each agreed logical unit separately.
- [ ] Verify actual commits and remote publication.
- [ ] Derive publication acknowledgment from Git evidence.
- [ ] Observe interrupted publication effects before admitting another mutation.

### 9. Cleanup, closure and refill

- [ ] Trigger cleanup from actual publication and retention policy.
- [ ] Keep cleanup with the same assignment owner.
- [ ] Produce exact disposable-file manifests with tracked/ownership/input/link checks.
- [ ] Retain required source, attempts, best candidates, journals, packets, receipts and reusable inputs.
- [ ] Verify process/session exits and registration closure.
- [ ] Require closure evidence before marking the assignment closed.
- [ ] Make the released slot available immediately to the next eligible fresh owner.

### 10. STOP and recovery

- [ ] Order STOP against model, tool, setup, verification and Git admissions.
- [ ] Enforce one bounded aggregate shutdown interval.
- [ ] Prevent unresponsive controls from delaying other owned-job termination.
- [ ] Preserve observed admitted or completed effects at STOP.
- [ ] Distinguish local exit from separately observable remote provider activity.
- [ ] Recover from durable records and actual process/Git observations.
- [ ] Resume only authorized identifiable work; retain ambiguous outcomes for explicit resolution.
- [ ] Preserve closed accepted-work/throughput history.
- [ ] Exercise crashes, duplicate deliveries, interrupted publication and meaningful cancellation boundaries.

### 11. Dashboard and measurements

- [ ] Integrate the existing dashboard interface using genuine native identities.
- [ ] Verify real roots, child membership, journals and streams.
- [ ] Show assignment/model/stage/blocked reason and honest live/parked/closed state.
- [ ] Separate useful execution, model queues, controller waits, review, publication and cleanup timings.
- [ ] Measure eligible idle-slot time and closure-to-refill latency.
- [ ] Record manual interventions and their causes.
- [ ] Separate accepted published work from drafts, unmatched final attempts and engineering work.
- [ ] Distinguish violations, prevented invalid actions and recovery outcomes.
- [ ] Measure instrumentation overhead.

### 12. Connected-system verification

- [ ] Connect scheduling, workers, verification, review, publication, cleanup and recovery.
- [x] Replace obsolete routine manual paths and update affected callers/documentation.
- [x] Retain focused regressions for consumer-visible defects.
- [ ] Exercise changed native and Git paths with actual runtime evidence.
- [ ] Run integrated verification after related changes are combined.
- [x] Reuse unchanged valid evidence.
- [ ] Prove routine progression no longer requires either conversational orchestrator to supply the next command.

### 13. Four-Qwen real-function trial

- [ ] Prepare four genuine native roots and four genuine Qwen children with zero root inference.
- [ ] Register the trial roots through the controller using available ports and exact native root/journal/process identities; preserve unrelated registry entries, handle actual writer/port conflicts, and verify each owned listener before child preparation. Manage eligible replacement roots automatically without another session's approval.
- [ ] Hold all four children at the abort-aware native pre-model gate; prove actual cards, registry/journals, zero provider dispatch and cancellation behavior.
- [ ] Release all four first requests together after the agreed checks pass.
- [ ] Capture actual successive same-item model updates from every child.
- [ ] Run initial functions E228, E230, E238 and E240.
- [ ] Refill eligible slots independently with fresh owners for E248, E250, E258 and E260.
- [ ] Let the controller drive all eight through review, integration, real publication, cleanup and closure.
- [ ] Record every manual intervention and its cause.
- [ ] Verify terminal outcomes, source/publication receipts, retained evidence and owner exits.

### 14. Measured improvement

- [ ] Rank bottlenecks by lost accepted-work throughput.
- [ ] Separate model/tool limits from avoidable orchestration delays.
- [ ] Remove unnecessary serial review, repeated checks, packet rebuilding and manual transitions.
- [ ] Reduce setup/workspace overhead where measurements justify the change.
- [ ] Improve local-model selection from observed success/completion data.
- [ ] Exercise changes and compare equivalent workloads/configurations.
- [ ] Reject apparent speed gains that weaken correctness, ownership, STOP or publication rules.
- [ ] Report remaining bottlenecks and evidence limits.

### 15. Production validation and cutover

- [ ] Validate the complete workflow against the approved production profile.
- [ ] Exercise a representative concurrent workload before claiming sustained performance.
- [ ] Integrate real trial results into MAIN with intended commit boundaries and relevant verification.
- [ ] Transfer production publication authority explicitly.
- [ ] Preserve in-flight owners and prevent duplicate assignments during transition.
- [ ] Exercise production startup, status, STOP and recovery procedures.
- [ ] Verify the new controller makes routine lifecycle decisions in production.
- [ ] Update this plan and operating instructions to match deployed behavior.
- [ ] Remove obsolete orchestration paths after the replacement is verified.
- [ ] Deliver measured throughput, consistency, intervention and recovery results.

## Existing evidence and execution checkpoint

The original bounded evaluation is published and closed. The retained real-trial component snapshot passed 193 tests with two explicitly gated native skips; the verification run stopped with all owned processes exited. Its frozen 21-source packet and exact-command addendum remain historical evidence, not a claim that the full automatic workflow exists.

Selective-review implementation and focused verification are complete and published, based on `e2dfb9f84900b08d2cd46f1e3b7b7c476f2ce15b`. Its frozen 16-source manifest is `build/orchestration-eval/deterministic-policy-candidate-001/build/orchestration-eval/selective-review-delta-001/source-identities-006.json`, SHA256 `06079f5ce576583748360eef166f86eb66749d61a063955ca3c3811f17980caa`. Both retained Sol 6.1 reviewers accepted the affected source; unchanged reviews were carried forward.

The four logical units were separately pushed to `orchestration-redesign-trial`: acceptance/evidence/ownership `4d01ac004489d90fbaa2d32d17754bfdd84a542d`, scoped review `7b77d4e53eb348cef623dea4fb7e421fa40dfe85`, candidate confinement/Git fixtures `d878042563ee1ccc9e56f1e182426d52dc114662`, and policy/proof documentation `d1bceea5ae1db4fc80e5436dbc678dd0ee0cb75d`. Parent read all four actual successful push commands and remote responses. The adjacent `publication-handoff-001.json` records matching local/remote HEAD, the preserved 20-commit sequence and STOPPED/all owned exits; its `p3/engineering-publication.json` receipt is under the candidate's `build/orchestration-eval`. The first unit's failed push and existing local commit were retained and reconciled without repeating materialization or commit. This is the accepted implementation checkpoint for the remaining native trial steps, not a claim that those steps have run.

The adjacent `verification-evidence-001.json` retains the actual runs. Initial integration produced 61 passes and three Git-fixture failures. Two intended before-correction failures demonstrated rejected canonical insertion proof and rejected native-evidence reuse. The corrected policy run passed 12 ledger/producer/ownership cases while four Git fixtures failed; the final fixture correction then passed all four actual Git cases in 145.18 seconds. These are distinct receipts, not a new all-passing full-suite claim. Managed runs ended STOPPED with all owned processes exited.

The routine registration smoke used actual published configure/splits preimages and the fixed E228 recipe. The controller proved the bounded insertions, accepted the delivery mechanically, materialized it, made two separate commits and two pushes to the owned local bare remote, and derived acknowledgment with matching local/remote HEAD `30f85e5d179fb8a40589368ea16afdb7f4fd5e60`, without a reviewer. Compiler, reconstruction and native-owner admissions in that fixture are explicitly synthetic. This proves the ownership/publication path, not a new real-function compile, provider request, four-child stream or production-throughput result.

Identity-checked native receipt reuse now retains fresh per-delivery coverage and acceptance. Configured judgment reasons remain exact, with automatic context separate; the actual reviewer definition, task and parser agree on unresolved-only scope. Failed or invalidated mechanical evidence cannot be waived. Canonical application data paths remain unchanged; Windows fixture fixes affect only owned fixture locations and their repository-local Git settings. All prior failure evidence, the original 16 published commits and original `d0d182fcfc11d69fcf72c2e8fcc6dd709a93658f` baseline remain retained. The six unrequested Sol-review/authentication edits remain excluded and preserved; this policy grants no additional model/default/credential authority.

Engineering dashboard root/child evidence remains valid for its exercised path. Actual four-trial-child proof remains required. Original evaluation files and immutable packets remain preserved. Production service/model changes and MAIN cutover are not inferred from permission to implement the private controller.

Native preparation checkpoint: `controller-four-qwen-live-003` accepted the preserved 21 publication units, then failed a canonical-path check while resolving one not-yet-created native directory during concurrent startup. Three genuine zero-provider roots completed handshakes; all 159 owned process exits were observed and the run reached STOPPED. Those three root identities are closed, not available for dashboard registration. Original inputs, publication history and failure evidence remain immutable in `build/orchestration-eval/controller-native-parent-race-001/live003-failing-before.json` and the original run directory.

The narrow correction creates the strictly confined shared `native` parent before submitting the four preparation futures; native root preparation remains concurrent and `safety.py` is unchanged. The two-file frozen manifest `build/orchestration-eval/controller-native-parent-race-001/source-identities.json` has SHA256 `59bbf5cb34702337f7bfb08dab6f58bbd57a6911bf4c47fbd5dca3fe1e5034a1`. Retained Sol 6.1 native review accepted only this delta. Parent read the actual `runs/realtrial-native-parent-after-001/behavioral-tests.json` receipt: both Windows filesystem ordering/junction regressions passed in 0.73 seconds, exit 0, STOPPED/all owned exits. This is changed-path proof; successful post-correction four-root startup and the held-child/dashboard/provider checks still require their actual receipts.

Parent parallel preflight independently verified the rendered public dashboard and RuntimeOwner's live card, plus Spark1's service-reported Qwen model identity and idle healthy status. `build/orchestration-eval/parent-launch-preflight-001/receipt.json`, its screenshot and browser-exit receipt retain that observation. Four authorized trial slots remain unchanged despite the service advertising five maximum streams; release-time capacity remains a separate current observation. This is point-in-time evidence, not a reservation or a requirement for another session to approve registration.

Subsequent actual native smoke resolves the startup qualification above: `controller-four-qwen-live-004` prepared all four genuine RPC roots, verified their standard-store MAIN journals and live creation-bound membership in owned Windows jobs, and retained zero-message/non-streaming handshakes. The exact `build/orchestration-eval/controller-four-qwen-inputs-004/native-root-identities.json` packet has SHA256 `99ba55dec2bb93d38102c4f413dc89109d4f17c03f02fa12d21c4106d065c2da`, independently checked by parent. On the user's STOP instruction, the exact-run stop command returned exit 0 and STOPPED revision 2 at `2026-10-16T14:30:24.775417+00:00`, event `trial-recovery-stop-b099ffaf2ea04493b06b971dcaeb46ea`. The recorded root identities are historical proof, not permission to reuse stopped processes. Confirm actual controller/job closure before fresh preparation. The user has now directed correction of this plan/checklist and resumption. The prior named-session registration wait is withdrawn; registration belongs to the controller under the rule above. The separate authorized production Qwen owner remains separate and is accounted for in the release-time capacity check.


## Coordination channel

The user's `RoutingFileOnly-01` directive replaces reconstruction-terminal messaging. Read `C:/Users/josep/Projects/personal/games/brawl-decomp/build/coordination/reconstruction-to-trial.md`; append updates and acknowledgments to `C:/Users/josep/Projects/personal/games/brawl-decomp/build/coordination/trial-to-reconstruction.md`, preserving earlier entries. Do not inject terminal input, including through `orca terminal send`.

Historical terminal identifiers in retained packets are provenance, not permission to use those routes. Mailbox notice `msg_b4907120d66c` was acknowledged in `TrialRoutingAck-01`. This channel change grants no additional engineering, MAIN, provider, process-control, or reconstruction-plan authority.

## Keeping this plan authoritative for this session

Re-read this file when resuming work, before changing phase, and when the user changes the scope. Keep the current checkpoint accurate. Preserve existing owners and evidence across interruptions.

A proposed extra prerequisite must be justified by an actual approved requirement or a concrete defect. Do not turn uncertainty, implementation choices, or an unrelated MAIN update into a new routine condition. Do not replace this plan with a task list, a trial contract, or the reconstruction coordinator's plan.
