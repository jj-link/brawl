/* Bounded local commands over native OMP RPC. No provider or tool implementation.
 * Pinned to OMP 18.11.1's AgentSession.getToolForEvalBridge and native registry.
 */
import { createHash } from 'node:crypto';
import { readFileSync, writeFileSync, appendFileSync, realpathSync, lstatSync, openSync, fsyncSync, closeSync } from 'node:fs';
import { resolve, dirname, sep } from 'node:path';
import { loadLegacyPiModule } from '@oh-my-pi/pi-coding-agent/extensibility/plugins/legacy-pi-compat';
import { installAdmissionGuard } from './trial_gate.mjs';
import { AgentRegistry, MAIN_AGENT_ID } from '@oh-my-pi/pi-coding-agent/registry/agent-registry';
import { discoverAgents } from '@oh-my-pi/pi-coding-agent/task/discovery';
import { Database } from 'bun:sqlite';

const specPath = process.env.OMP_BOUNDED_TRIAL_SPEC;
if (!specPath) throw new Error('Missing exact-run bounded trial specification');
const specBytes = readFileSync(specPath);
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
if (hash(specBytes) !== process.env.OMP_BOUNDED_TRIAL_SPEC_SHA256) throw new Error('Trial specification changed');
const spec = JSON.parse(specBytes);
const root = realpathSync(dirname(specPath));
const registry = AgentRegistry.global();
const ledger = new Database(spec.ledger_path, { readonly: true, strict: true });
// Connection-local bounded waiting for concurrent durable ledger commits.
ledger.exec('PRAGMA busy_timeout = 250');
let owner = null, launched = false, rootContext = null, rootStartEvent = null, observerFactory = null;
let internalCall = false;
const pending = new Set();
let providerReleased = false;
const gateWaiters = new Set();
let ownerDispatch = null, reviewer = null;
const reviewWaiters = new Set();
let cleanupCommand = null;
const dispatchStarts = new Map();
const modelSpans = new Map(), toolSpans = new Map();
const guarded = new WeakSet();
const readyChildren = new WeakSet();
let registryWatching = false;
let lifecycleUnsubscribe = null;
const dispatchCommands = new Map(), commandResults = new Map();
const terminalTurns = new Map(), finalizedRuns = new Map(), completedDispatches = new Set();
let workerDefinition = null, reviewerDefinition = null;
const workerTools = ['read', 'bash', 'edit', 'write', 'grep', 'glob'];

export async function restrictReconstructionTools(pi) {
  // These unstructured native tasks complete with a final message, not a yield tool.
  await pi.setActiveTools(workerTools);
  const active = pi.getActiveTools();
  if (active.length !== workerTools.length || workerTools.some(name => !active.includes(name))) {
    throw new Error(`Installed reconstruction definition lacks the bounded native tool set: ${JSON.stringify(active)}`);
  }
  return active;
}

export async function resolveTrialAgent(binding, execution, cwd) {
  if (!binding?.path || !binding.sha256) throw new Error('Native agent definition lacks its input binding');
  const path = realpathSync(binding.path);
  if (hash(readFileSync(path)) !== binding.sha256) throw new Error('Bound native agent definition changed');
  const canonical = value => process.platform === 'win32' ? value.toLowerCase() : value;
  const discovered = await discoverAgents(cwd);
  const matches = discovered.agents.filter(agent => ['project', 'user'].includes(agent.source) &&
    agent.filePath && canonical(realpathSync(agent.filePath)) === canonical(path));
  if (matches.length !== 1) throw new Error(`Bound native definition is not uniquely discoverable: ${path}`);
  const agent = matches[0];
  const models = Array.isArray(agent.model) ? agent.model : [agent.model];
  const expected = `${execution.provider}/${execution.model}`;
  if ((binding.name && agent.name !== binding.name) || models.length !== 1 || models[0] !== expected) {
    throw new Error('Discovered native agent name/model differs from its approved input');
  }
  return { name: agent.name, path, sha256: binding.sha256, source: agent.source,
    model: expected, declared_tools: agent.tools ?? null };
}

function fatalBoundary(error) {
  try { event('native_boundary_fatal', { error: String(error?.stack || error) }); }
  finally { process.exit(70); }
}

function workflowAction(doc, effectId, kinds) {
  const workflow = doc.trial.workflow;
  const action = workflow?.actions?.[effectId];
  if (!workflow || workflow.config_digest !== spec.workflow_config_digest || !action ||
      action.status !== 'admitted' || !kinds.includes(action.kind) ||
      action.authorization_revision !== spec.authorization_revision ||
      action.assignment_id !== spec.assignment_id || action.binding.owner_id !== owner ||
      action.binding.manifest_digest !== spec.manifest_digest) {
    throw new Error('Native operation lacks its exact admitted workflow action');
  }
  return action;
}

function authorizeModel(ref, model, forwarding) {
  const doc = admission();
  if (!ref || ref.kind !== 'sub' || !launched || !readyChildren.has(ref.session.agent)) {
    throw new Error('Root, foreign, or incompletely initialized actor inference is forbidden');
  }
  const isReview = reviewer && ref.id === reviewer.owner_id;
  if (!isReview && ref.id !== owner) throw new Error('Unassigned native actor');
  const execution = isReview ? doc.trial.workflow.config.profile.review : spec.execution;
  if (model?.provider !== execution.provider || model?.id !== execution.model ||
      model?.baseUrl !== execution.endpoint) throw new Error('Actual requested model identity changed');
  if (ownChild(ref.id) !== ref) throw new Error('Native actor registry generation changed');
  const claim = doc.trial.claims[spec.assignment_id];
  if (!claim || claim.owner_id !== owner || claim.root_session_id !== rootContext.sessionManager.getSessionId()) {
    throw new Error('Native model call lacks its exact durable owner claim');
  }
  if (isReview) {
    const action = workflowAction(doc, reviewer.dispatch_effect_id || reviewer.prepare_effect_id,
                                 reviewer.dispatch_effect_id ? ['review'] : ['prepare_review']);
    if (action.reviewer?.owner_id !== ref.id ||
        (forwarding && (!reviewer.released || action.kind !== 'review' ||
         action.reviewer.session_id !== identity(ref).session_id))) {
      throw new Error('Reviewer cannot forward before exact native attachment and review admission');
    }
    return;
  }
  if (forwarding && (!providerReleased || !doc.trial.activation ||
      !doc.trial.effects[spec.assignment_id + '-initial'] ||
      doc.assignments[spec.assignment_id].session_id !== identity(ref).session_id)) {
    throw new Error('Native provider forwarding is not authorized for this exact session');
  }
  if (doc.trial.workflow && forwarding) {
    const activity = doc.trial.workflow.assignments[spec.assignment_id]?.owner_activity;
    if (!activity?.busy || activity.effect_id !== ownerDispatch) throw new Error('Owner has no active inference lease');
    if (ownerDispatch !== spec.assignment_id + '-initial') workflowAction(doc, ownerDispatch, ['reconcile', 'cleanup']);
  }
}

function guardSession(ref) {
  const agent = ref?.session?.agent;
  if (!agent || guarded.has(agent)) return;
  if (typeof agent.addBeforeModelCall !== 'function') fatalBoundary(new Error('Native enforceable gate unavailable'));
  installAdmissionGuard(agent, {
    authorize: (model, forwarding) => authorizeModel(ref, model, forwarding),
    wait: signal => ref.id === owner ? holdBeforeModelCall(signal) : holdReviewModelCall(ref, signal),
    onFailure: error => event('provider_refused', { owner: ref.id, error: String(error) }),
  });
  guarded.add(agent);
}

function holdBeforeModelCall(signal) {
  if (providerReleased) return;
  event('provider_gate_wait', { owner });
  return new Promise((resolveGate, reject) => {
    const release = () => { signal?.removeEventListener('abort', abort); resolveGate(); };
    const abort = () => { gateWaiters.delete(release); reject(new Error('Native preparation gate aborted')); };
    gateWaiters.add(release);
    signal?.addEventListener('abort', abort, { once: true });
    if (signal?.aborted) abort();
  });
}

function holdReviewModelCall(ref, signal) {
  if (!reviewer || ref.id !== reviewer.owner_id) throw new Error('No prepared reviewer');
  if (reviewer.released) return;
  event('review_gate_wait', { ...identity(ref), root_session_id: rootContext.sessionManager.getSessionId(),
    request_id: reviewer.prepare_effect_id });
  return new Promise((resolveGate, reject) => {
    const release = () => { signal?.removeEventListener('abort', abort); resolveGate(); };
    const abort = () => { reviewWaiters.delete(release); reject(new Error('Native review preparation aborted')); };
    reviewWaiters.add(release);
    signal?.addEventListener('abort', abort, { once: true });
    if (signal?.aborted) abort();
  });
}

function owned(path) {
  const result = resolve(path);
  if (!result.startsWith(root + sep)) throw new Error('Unowned trial evidence path');
  for (let current = result; current !== root; current = dirname(current)) {
    try { if (lstatSync(current).isSymbolicLink()) throw new Error('Linked evidence path'); }
    catch (error) { if (error.code !== 'ENOENT') throw error; }
  }
  return result;
}
function record(name, value) {
  const path = owned(resolve(root, name));
  const fd = openSync(path, 'wx');
  try {
    writeFileSync(fd, JSON.stringify({ observed_at: new Date().toISOString(), ...value }) + '\n');
    fsyncSync(fd);
  } finally { closeSync(fd); }
  writeFileSync(path + '.complete', '', { flag: 'wx' });
  return path;
}
function event(kind, data) {
  appendFileSync(owned(resolve(root, 'native-events.jsonl')),
    JSON.stringify({ kind, observed_at: new Date().toISOString(), ...data }) + '\n');
}
function identity(ref) {
  const file = ref.session?.sessionManager.getSessionFile() || ref.sessionFile;
  const sessionId = ref.session?.sessionManager.getSessionId() || null;
  return { registry_id: ref.id, native_kind: ref.kind, parent_id: ref.parentId,
    session_id: sessionId, journal_ref: file, status: ref.status,
    model: ref.session?.model ? { provider: ref.session.model.provider, id: ref.session.model.id,
      baseUrl: ref.session.model.baseUrl } : null };
}
function ownChild(id = owner) {
  const ref = id && registry.get(id);
  if (!ref || ref.kind !== 'sub' || ref.parentId !== MAIN_AGENT_ID) throw new Error('Native owner is not registered under this root');
  const value = identity(ref);
  const rootFile = rootContext.sessionManager.getSessionFile();
  if (!value.journal_ref || !resolve(value.journal_ref).startsWith(resolve(rootFile.slice(0, -6)) + sep)) {
    throw new Error('Native child journal ancestry does not match root');
  }
  return ref;
}
function stopped() {
  try { readFileSync(owned(resolve(root, 'STOP'))); return true; }
  catch (error) { if (error.code === 'ENOENT') return false; throw error; }
}
export function admission() {
  if (stopped()) throw new Error('Exact-run STOP takes precedence');
  const row = ledger.query('SELECT data FROM ledger WHERE id=1').get();
  if (stopped()) throw new Error('Exact-run STOP takes precedence');
  const doc = JSON.parse(row.data);
  if (doc.authorization.mode !== 'RUN' || doc.authorization.revision !== spec.authorization_revision ||
      doc.trial.manifest_digest !== spec.manifest_digest) throw new Error('Durable native admission is stale or stopped');
  return doc;
}
async function nativeTool(name, args, id) {
  const session = registry.get(MAIN_AGENT_ID)?.session;
  if (!session || session.sessionManager.getSessionId() !== rootContext.sessionManager.getSessionId()) {
    throw new Error('Root session changed; adoption forbidden');
  }
  const tool = session.getToolForEvalBridge(name);
  if (!tool) throw new Error(`Native permission-gated ${name} tool is unavailable`);
  internalCall = true;
  try { return await tool.execute(id, args, new AbortController().signal); }
  finally { internalCall = false; }
}
function settleDispatch(effectId) {
  if (!effectId || completedDispatches.has(effectId)) return;
  const turn = terminalTurns.get(effectId), lifecycle = finalizedRuns.get(effectId);
  const commandId = dispatchCommands.get(effectId), command = commandResults.get(commandId);
  if (!turn || !lifecycle || !command) return;
  if (lifecycle.payload.id !== turn.value.registry_id ||
      resolve(lifecycle.payload.sessionFile) !== resolve(turn.value.journal_ref)) {
    throw new Error('Finalized native task does not belong to its actual completed session');
  }
  const success = lifecycle.payload.status === 'completed' && command.success === true;
  event(turn.kind, { ...turn.value, native_completion: {
    source: 'native-task-finalization', success, command_id: commandId,
    command_result_ref: command.path, command_result_sha256: hash(readFileSync(command.path)),
    lifecycle_ref: lifecycle.path, lifecycle_sha256: hash(readFileSync(lifecycle.path)),
  } });
  completedDispatches.add(effectId);
  terminalTurns.delete(effectId);
  finalizedRuns.delete(effectId);
  dispatchCommands.delete(effectId);
  commandResults.delete(commandId);
  if (reviewer?.dispatch_effect_id === effectId) reviewer.released = false;
}

function track(id, promise, operation, effectId = null, taskResult = operation === 'launch') {
  pending.add(id);
  const finish = value => {
    const activeEffect = operation === 'prepare-review' && reviewer?.prepare_effect_id === effectId
      ? (reviewer.dispatch_effect_id || effectId) : effectId;
    const resultRef = record(`result-${id}.json`, {
      id, operation, workflow_effect_id: activeEffect, task_result_required: taskResult, ...value,
    });
    commandResults.set(id, { path: resultRef, success: value.success });
    event('local_result', { id, operation, workflow_effect_id: activeEffect, success: value.success, result_ref: resultRef });
    for (const [dispatch, command] of dispatchCommands) if (command === id) settleDispatch(dispatch);
  };
  promise.then(result => {
    const rows = result?.details?.results;
    const success = !result?.isError && (!taskResult ||
      (Array.isArray(rows) && rows.length === 1 && rows[0].exitCode === 0 && !rows[0].aborted));
    finish({ success, result });
  }, error => finish({ success: false, error: String(error?.stack || error) }))
    .catch(error => { event('record_failure', { id, error: String(error) }); })
    .finally(() => { pending.delete(id); });
}

export default function boundedTrial(pi) {
  if (!registryWatching) {
    registryWatching = true;
    registry.onChange(change => {
      try {
        guardSession(change.ref);
        if (change.ref.kind === 'sub') event('registry', identity(change.ref));
      } catch (error) { fatalBoundary(error); }
    });
    for (const ref of registry.list()) guardSession(ref);
  }
  if (!lifecycleUnsubscribe) {
    lifecycleUnsubscribe = pi.events.on('task:subagent:lifecycle', payload => {
      try {
        if (!payload || typeof payload !== 'object' || !['completed', 'failed', 'aborted'].includes(payload.status)) return;
        const isReview = reviewer && payload.id === reviewer.owner_id;
        if (!isReview && payload.id !== owner) return;
        const effectId = isReview ? reviewer.dispatch_effect_id || reviewer.prepare_effect_id : ownerDispatch;
        if (!effectId || completedDispatches.has(effectId)) return;
        const path = record(`lifecycle-${effectId}.json`, { request_id: effectId, payload });
        finalizedRuns.set(effectId, { path, payload });
        settleDispatch(effectId);
      } catch (error) { fatalBoundary(error); }
    });
  }
  pi.on('session_shutdown', (_event, ctx) => {
    if (ctx.agent.kind === 'main') {
      lifecycleUnsubscribe?.();
      lifecycleUnsubscribe = null;
    }
  });
  pi.on('before_provider_request', (_event, ctx) => {
    // Native notification exceptions are swallowed. Abort the already-created
    // request signal before diagnostics, including stale admission and I/O failures.
    try {
      const ref = registry.get(ctx.agent.id);
      authorizeModel(ref, ctx.model, true);
      const model = ctx.model;
      const effect = ctx.agent.id === owner ? ownerDispatch : reviewer.dispatch_effect_id;
      if (!dispatchStarts.has(effect)) dispatchStarts.set(effect, new Date().toISOString());
      modelSpans.set(ctx.sessionManager.getSessionId(), new Date().toISOString());
      event('provider_request_admitted', { owner: ctx.agent.id, session_id: ctx.sessionManager.getSessionId(),
        workflow_effect_id: ctx.agent.id === owner ? ownerDispatch : reviewer.dispatch_effect_id,
        provider: model.provider, model: model.id, endpoint: model.baseUrl });
    } catch (error) {
      ctx.abort();
      event('provider_refused', { agent: ctx.agent, error: String(error) });
      throw error;
    }
  });
  pi.on('after_provider_response', (response, ctx) => {
    event('provider_response', { owner: ctx.agent.id, session_id: ctx.sessionManager.getSessionId(),
      provider: ctx.model?.provider, model: ctx.model?.id, endpoint: ctx.model?.baseUrl,
      status: response.status, request_id: response.requestId ?? null });
  });
  pi.on('message_end', (message, ctx) => {
    if (ctx.agent.kind !== 'sub' || message.message?.role !== 'assistant') return;
    const session = ctx.sessionManager.getSessionId(), started = modelSpans.get(session);
    if (!started) return;
    modelSpans.delete(session);
    event('native_interval', { owner: ctx.agent.id, session_id: session, started_at: started,
      phase: ctx.agent.id === owner ? 'model_execution' : 'review_execution',
      qualification: 'Native request-wall interval; endpoint queue and compute are not separately observed' });
  });
  pi.on('tool_execution_start', (tool, ctx) => {
    if (ctx.agent.kind === 'sub' && typeof tool.toolCallId === 'string') {
      toolSpans.set(`${ctx.sessionManager.getSessionId()}:${tool.toolCallId}`, new Date().toISOString());
    }
  });
  pi.on('tool_execution_end', (tool, ctx) => {
    const key = `${ctx.sessionManager.getSessionId()}:${tool.toolCallId}`, started = toolSpans.get(key);
    if (ctx.agent.kind !== 'sub' || !started) return;
    toolSpans.delete(key);
    event('native_interval', { owner: ctx.agent.id, session_id: ctx.sessionManager.getSessionId(),
      started_at: started, phase: 'tool_execution', tool_call_id: tool.toolCallId,
      tool_name: tool.toolName, is_error: tool.isError });
  });
  pi.on('agent_end', (ended, ctx) => {
    if (ctx.agent.kind !== 'sub') return;
    const isReview = reviewer && ctx.agent.id === reviewer.owner_id;
    if (!isReview && ctx.agent.id !== owner) return;
    const ref = ownChild(ctx.agent.id);
    if (identity(ref).session_id !== ctx.sessionManager.getSessionId()) {
      fatalBoundary(new Error('Completed actor turn belongs to a different native session'));
    }
    const effectId = isReview ? reviewer.dispatch_effect_id : ownerDispatch;
    const value = { ...identity(ref), root_session_id: rootContext.sessionManager.getSessionId(),
      request_id: effectId, started_at: dispatchStarts.get(effectId) ?? null,
      will_continue: ended.willContinue === true };
    event(isReview ? 'reviewer_agent_end' : 'owner_agent_end', value);
    if (effectId && !ended.willContinue) {
      terminalTurns.set(effectId, { kind: isReview ? 'reviewer_turn_end' : 'owner_turn_end', value });
      try { settleDispatch(effectId); } catch (error) { fatalBoundary(error); }
    }
  });
  pi.on('before_subagent_spawn', (_event, ctx) => {
    if (stopped() || ctx.agent.kind !== 'main' || !internalCall || !owner || !launched) {
      return { block: true, reason: 'Only the single manifest assignment may spawn' };
    }
    return {};
  });
  pi.on('input', (input, ctx) => {
    if (ctx.agent.kind === 'main' && !input.text.startsWith('/bounded-trial ')) {
      event('root_input_refused', {});
      return { action: 'handled' };
    }
  });
  pi.on('session_before_switch', () => ({ cancel: true }));
  pi.on('session_before_branch', () => ({ cancel: true }));
  pi.on('tool_call', (call, ctx) => {
    if (stopped()) return { block: true, reason: 'Exact-run STOP' };
    if (ctx.agent.kind === 'main' && !internalCall) return { block: true, reason: 'Control root has no autonomous tools' };
    if (ctx.agent.id === owner && cleanupCommand !== null) {
      if (['read', 'grep', 'glob', 'yield'].includes(call.toolName)) return;
      if (call.toolName === 'bash' && call.input?.command === cleanupCommand) return;
      return { block: true, reason: 'Cleanup permits only inspection and the exact handle-safe owned cleanup command' };
    }
    if (reviewer && ctx.agent.id === reviewer.owner_id) {
      if (['read', 'grep', 'glob', 'yield'].includes(call.toolName)) return;
      if (call.toolName === 'write' && typeof call.input?.path === 'string' &&
          resolve(call.input.path) === reviewer.decision_path) return;
      return { block: true, reason: 'Scoped reviewer may only inspect evidence and write its exact decision file' };
    }
    if (ctx.agent.kind === 'sub' && ['task', 'generate_image', 'web_search'].includes(call.toolName)) {
      return { block: true, reason: 'No additional model work or children in bounded trial' };
    }
  });
  pi.on('session_start', async (evt, ctx) => {
    try {
      const ref = registry.get(ctx.agent.id);
      guardSession(ref);
      if (!ref?.session?.agent || !guarded.has(ref.session.agent)) {
        throw new Error('Session cannot become ready without its native Agent guard');
      }
      if (ctx.agent.kind === 'main') {
        rootContext = ctx;
        rootStartEvent = evt;
        const auxiliaryModels = ['tiny', 'commit', 'smol'].filter(role => ctx.models.resolve(`@${role}`));
        if (auxiliaryModels.length) throw new Error(`Auxiliary model roles remain enabled: ${auxiliaryModels}`);
        workerDefinition = await resolveTrialAgent(spec.agent_definition, spec.execution, ctx.cwd);
        if (spec.review) {
          reviewerDefinition = await resolveTrialAgent(spec.review.agent_definition, spec.review.execution, ctx.cwd);
        }
        pi.appendEntry('brawl.bounded-trial.root', {
          assignment_id: spec.assignment_id, manifest_digest: spec.manifest_digest,
        });
        const tools = ['task', 'write'].map(name => ({ name, available: !!ref.session.getToolForEvalBridge(name) }));
        if (tools.some(tool => !tool.available)) throw new Error('Required native tool unavailable');
        await ctx.sessionManager.ensureOnDisk();
        await ctx.sessionManager.flush();
        record('native-ready.json', { root_session_id: ctx.sessionManager.getSessionId(),
          root_journal: ctx.sessionManager.getSessionFile(), cwd: ctx.cwd, tools, pid: process.pid,
          spec_sha256: hash(specBytes), protocol: 'bounded-native-commands-v2', enforceable_guard: true,
          agent_definitions: { worker: workerDefinition, reviewer: reviewerDefinition } });
      } else {
        if ((ctx.agent.id !== owner && ctx.agent.id !== reviewer?.owner_id) || !observerFactory) {
          throw new Error('Unexpected or unobserved native child');
        }
        ownChild(ctx.agent.id);
        if (ctx.agent.id === owner) {
          const active = await restrictReconstructionTools(pi);
          event('worker_tools_selected', { ...identity(ref), active_tools: active });
        }
        const starts = [];
        const adapter = new Proxy(pi, { get(target, property) {
          if (property === 'on') return (name, handler) => name === 'session_start' ? starts.push(handler) : target.on(name, handler);
          return Reflect.get(target, property);
        } });
        observerFactory(adapter, { independent: true });
        for (const start of starts) await start(evt, ctx);
        readyChildren.add(ref.session.agent);
        event(ctx.agent.id === owner ? 'child_gate_installed' : 'reviewer_gate_installed',
              { ...identity(ref), root_session_id: rootContext.sessionManager.getSessionId(),
                agent_definition: ctx.agent.id === owner ? workerDefinition : reviewerDefinition,
                active_tools: pi.getActiveTools() });
      }
    } catch (error) {
      // session_start exceptions are also isolated by OMP. Terminate this
      // owned native host synchronously rather than allowing a failed setup
      // to continue toward a model request or publish a readiness marker.
      fatalBoundary(error);
    }
  });
  pi.registerCommand('bounded-trial', {
    description: 'Exact-run local native assignment control; never a root provider prompt',
    handler: async (argument, ctx) => {
      if (ctx.agent.kind !== 'main' || ctx.sessionManager.getSessionId() !== rootContext?.sessionManager.getSessionId()) {
        throw new Error('Only the retained control root accepts commands');
      }
      const requestPath = owned(argument.trim());
      const request = JSON.parse(readFileSync(requestPath, 'utf8'));
      if (!/^[a-f0-9]{32}$/.test(request.id) || request.manifest_digest !== spec.manifest_digest ||
          request.root_session_id !== ctx.sessionManager.getSessionId() || request.assignment_id !== spec.assignment_id) {
        throw new Error('Command does not bind this immutable root/assignment');
      }
      admission();
      // Native crash or lost transport ACK never permits replaying a command.
      record(`consumed-${request.id}.json`, { request, request_sha256: hash(readFileSync(requestPath)) });
      if (request.operation === 'observe') {
        if (observerFactory) throw new Error('Observer already enabled');
        const observer = spec.observer;
        if (hash(readFileSync(observer.path)) !== observer.sha256) throw new Error('Observer source identity changed');
        if (observer.mode !== 'independent-required' || !observer.publication_ref?.path ||
            hash(readFileSync(observer.publication_ref.path)) !== observer.publication_ref.sha256) {
          throw new Error('Published explicit-independent observer identity is required');
        }
        const registration = JSON.parse(readFileSync(observer.registration, 'utf8'));
        const ids = new Set(), ports = new Set();
        if (!Array.isArray(registration.sessions)) throw new Error('Malformed observer registration');
        for (const row of registration.sessions) {
          if (typeof row.id !== 'string' || !/^[a-f0-9-]{36}$/i.test(row.id) || ids.has(row.id) ||
              !Number.isInteger(row.observerPort) || row.observerPort < 1 || row.observerPort > 65535 ||
              [8765, 8766].includes(row.observerPort) || ports.has(row.observerPort) ||
              typeof row.label !== 'string' || !row.label.trim() || row.label.toLowerCase() === 'main') {
            throw new Error('Malformed or duplicate observer registration row');
          }
          ids.add(row.id); ports.add(row.observerPort);
        }
        const selected = registration.sessions.filter(row => row.id === ctx.sessionManager.getSessionId());
        if (selected.length !== 1 || selected[0].observerPort !== request.port ||
            !Number.isInteger(request.port) || [8765, 8766].includes(request.port)) throw new Error('Exact observer registration missing');
        const starts = [];
        observerFactory = (await loadLegacyPiModule(observer.path)).default;
        const adapter = new Proxy(pi, { get(target, property) {
          if (property === 'on') return (name, handler) => name === 'session_start' ? starts.push(handler) : target.on(name, handler);
          return Reflect.get(target, property);
        } });
        observerFactory(adapter, { independent: true });
        for (const start of starts) await start(rootStartEvent, rootContext);
        record(`result-${request.id}.json`, { id: request.id, success: true, observer_port: request.port,
          ready: false, requires_owned_listener_evidence: true, pid: process.pid,
          root_session_id: ctx.sessionManager.getSessionId() });
      } else if (request.operation === 'launch') {
        const doc = admission();
        const claim = doc.trial.claims[spec.assignment_id];
        if (!claim || claim.owner_id !== request.owner_id || claim.root_session_id !== request.root_session_id ||
            !doc.trial.effects[spec.assignment_id + '-launch']) throw new Error('No exact durable native-child admission');
        if (launched || owner || pending.size) throw new Error('Assignment was already dispatched');
        if (!/^[A-Za-z][A-Za-z0-9]{0,31}$/.test(request.owner_id)) throw new Error('Invalid native owner name');
        owner = request.owner_id;
        launched = true;
        ownerDispatch = spec.assignment_id + '-initial';
        dispatchCommands.set(ownerDispatch, request.id);
        const definition = await resolveTrialAgent(spec.agent_definition, spec.execution, ctx.cwd);
        if (definition.name !== workerDefinition.name) throw new Error('Prepared worker definition changed');
        track(request.id, nativeTool('task', { context: request.context, tasks: [{ name: owner,
          agent: definition.name, task: request.task, solutionSpace: 'Matching reconstruction; exact cause and implementation open' }] }, request.id), 'launch', ownerDispatch);
      } else if (request.operation === 'release') {
        const doc = admission();
        if (!doc.trial.activation || !doc.trial.effects[spec.assignment_id + '-initial']) {
          throw new Error('No durable original-prompt provider admission');
        }
        const ref = ownChild();
        if (providerReleased || request.session_id !== identity(ref).session_id || !gateWaiters.size) {
          throw new Error('Only the prepared original child prompt can be released once');
        }
        providerReleased = true;
        event('provider_gate_released', { owner, session_id: request.session_id });
        for (const release of gateWaiters) release();
        gateWaiters.clear();
        record(`result-${request.id}.json`, { id: request.id, success: true, session_id: request.session_id });
      } else if (request.operation === 'prepare-review') {
        const action = workflowAction(admission(), request.effect_id, ['prepare_review']);
        const id = action.reviewer?.owner_id;
        if (!/^[A-Za-z][A-Za-z0-9]{0,31}$/.test(id || '') || id === owner) throw new Error('Invalid independent reviewer');
        if (reviewer && reviewer.owner_id !== id) throw new Error('Reviewer identity cannot be replaced');
        const existing = reviewer && ownChild(id);
        reviewer = { owner_id: id, prepare_effect_id: request.effect_id, dispatch_effect_id: null,
                     released: false, decision_path: owned(request.decision_path), command_id: request.id };
        record(`action-${request.effect_id}.json`, { command_id: request.id, kind: action.kind });
        const task = request.task + `\nWrite your concrete decision only to ${reviewer.decision_path}.`;
        const definition = await resolveTrialAgent(spec.review?.agent_definition, spec.review?.execution, ctx.cwd);
        if (definition.name !== reviewerDefinition?.name) throw new Error('Prepared reviewer definition changed');
        const work = existing
          ? nativeTool('write', { path: `agent://${id}`, content: task }, request.id)
          : nativeTool('task', { context: request.context, tasks: [{ name: id, agent: definition.name,
              task, solutionSpace: 'Independent substantive review of concrete source and fixed acceptance evidence' }] }, request.id);
        track(request.id, work, 'prepare-review', request.effect_id, !existing);
      } else if (request.operation === 'release-review') {
        const action = workflowAction(admission(), request.effect_id, ['review']);
        const ref = reviewer && ownChild(reviewer.owner_id);
        if (!ref || reviewer.released ||
            action.reviewer?.session_id !== identity(ref).session_id ||
            action.reviewer.owner_id !== reviewer.owner_id) throw new Error('Exact retained reviewer is not attached');
        record(`action-${request.effect_id}.json`, { command_id: request.id, kind: action.kind });
        reviewer.dispatch_effect_id = request.effect_id;
        dispatchCommands.set(request.effect_id, reviewer.command_id);
        reviewer.decision_path = owned(request.decision_path);
        reviewer.released = true;
        if (reviewWaiters.size) {
          for (const release of reviewWaiters) release();
          reviewWaiters.clear();
          record(`result-${request.id}.json`, { id: request.id, success: true, reviewer: identity(ref) });
        } else {
          dispatchCommands.set(request.effect_id, request.id);
          track(request.id, nativeTool('write', { path: `agent://${reviewer.owner_id}`, content: request.task }, request.id),
            'review', request.effect_id);
        }
      } else if (request.operation === 'owner-action') {
        const action = workflowAction(admission(), request.effect_id, ['reconcile', 'cleanup']);
        const ref = ownChild();
        if (action.binding.session_id !== identity(ref).session_id) throw new Error('Retained owner session changed');
        record(`action-${request.effect_id}.json`, { command_id: request.id, kind: action.kind });
        ownerDispatch = request.effect_id;
        dispatchCommands.set(request.effect_id, request.id);
        cleanupCommand = action.kind === 'cleanup' ? request.cleanup_command : null;
        if (action.kind === 'cleanup' && (typeof cleanupCommand !== 'string' || !cleanupCommand)) {
          throw new Error('Cleanup requires its exact safe executable command');
        }
        track(request.id, nativeTool('write', { path: `agent://${owner}`, content: request.message }, request.id),
          'owner-action', request.effect_id);
      } else if (request.operation === 'inspect') {
        record(`result-${request.id}.json`, { id: request.id, success: true,
          root_session_id: ctx.sessionManager.getSessionId(), child: owner ? identity(ownChild()) : null,
          pending: [...pending] });
      } else throw new Error('Unsupported bounded native operation');
    },
  });
}
