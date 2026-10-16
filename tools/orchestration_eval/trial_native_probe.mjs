/* Permanent native API infrastructure probe. No tools, children, observers or provider responses. */
import { readFileSync, writeFileSync, existsSync, renameSync, mkdirSync, rmdirSync } from 'node:fs';
import { resolve } from 'node:path';
import { createHash } from 'node:crypto';
import { loadLegacyPiModule } from '@oh-my-pi/pi-coding-agent/extensibility/plugins/legacy-pi-compat';
import { Database } from 'bun:sqlite';
import { Agent } from '@oh-my-pi/pi-agent-core';
import { AgentRegistry, MAIN_AGENT_ID } from '@oh-my-pi/pi-coding-agent/registry/agent-registry';
import { ExtensionRuntime, loadExtensionFromFactory } from '@oh-my-pi/pi-coding-agent/extensibility/extensions/loader';
import { ExtensionRunner } from '@oh-my-pi/pi-coding-agent/extensibility/extensions/runner';

const hash = data => createHash('sha256').update(data).digest('hex');
const specPath = process.env.OMP_NATIVE_API_PROBE_SPEC;
if (!specPath) throw new Error('Explicit native API probe specification required');
const specBytes = readFileSync(specPath);
if (hash(specBytes) !== process.env.OMP_NATIVE_API_PROBE_SHA256) throw new Error('Native API probe input changed');
const spec = JSON.parse(specBytes);
const order = [];
let deniedFetches = 0;
const deniedFetchRecords = [];
let activeFetchCase = null;
// A denial checkpoint only: no response, socket, provider implementation or relay.
const denyFetch = async (input, options) => {
  deniedFetches++;
  const url = typeof input === 'string' || input instanceof URL ? String(input) : input.url;
  const signal = options?.signal ?? input?.signal;
  deniedFetchRecords.push({ case: activeFetchCase, url, signal_aborted: signal?.aborted === true });
  order.push('unexpected-fetch-denied');
  throw new DOMException('NATIVE_API_PROBE_FORBIDS_NETWORK', 'AbortError');
};
globalThis.fetch = denyFetch;

async function lateBoundaryProbe(pi, ctx, runner, errors, dbPath, result) {
  // Genuine native root journal, privately stored; no hand-written header or child.
  await ctx.sessionManager.ensureOnDisk();
  await ctx.sessionManager.flush();
  result.journal_source = 'Actual native SessionManager.ensureOnDisk/flush';
  const writer = new Database(dbPath);
  const setAuthority = (mode, revision) => writer.query('UPDATE ledger SET data = ? WHERE id = 1').run(
    JSON.stringify({ authorization: { mode, revision }, trial: { manifest_digest: '0'.repeat(64) } }));
  // Test input only, never a registered model/child or a Spark1 request.
  const model = { ...ctx.model, api: 'openai-completions', baseUrl: 'http://127.0.0.1:1/native-denial-only' };
  try {
    for (const name of ['late_stop', 'late_revision', 'diagnostic_failure']) {
      setAuthority('RUN', 1);
      errors.length = 0;
      activeFetchCase = name;
      const beginning = deniedFetchRecords.length;
      let credentials = 0, payloads = 0, aborts = 0, timedOut = false;
      const caseOrder = [];
      const eventsPath = resolve(spec.root, 'native-events.jsonl');
      const preservedEvents = resolve(spec.root, 'native-events.before-diagnostic.jsonl');
      let diagnosticFault = false, movedEvents = false;
      const agent = new Agent({
        initialState: { model, systemPrompt: [], tools: [], messages: [] },
        getApiKey: requested => {
          credentials++;
          caseOrder.push('credential-resolved');
          if (requested.baseUrl !== model.baseUrl) throw new Error('Non-loopback probe model refused');
          return 'infrastructure-probe-not-a-real-credential';
        },
        onPayload: async (payload, requested) => {
          payloads++;
          caseOrder.push('native-onPayload');
          if (name === 'late_stop') setAuthority('STOPPING', 2);
          else if (name === 'late_revision') setAuthority('RUN', 2);
          else {
            if (existsSync(eventsPath)) { renameSync(eventsPath, preservedEvents); movedEvents = true; }
            mkdirSync(eventsPath);
            diagnosticFault = true;
          }
          caseOrder.push('late-boundary-changed');
          const returned = await runner.emitBeforeProviderRequest(payload, requested);
          caseOrder.push('native-runner-returned');
          return returned;
        },
      });
      // Use the genuine provider implementation, supplying only its documented
      // fail-only transport. The global denial is a second independent backstop.
      const nativeStream = agent.streamFn;
      agent.streamFn = (requested, context, options) => nativeStream(requested, context, { ...options, fetch: denyFetch });
      runner.initialize(pi, { ...ctx, getModel: () => model,
        abort: () => { aborts++; caseOrder.push('native-agent-abort'); agent.abort(); } });
      const timer = setTimeout(() => { timedOut = true; agent.abort(); }, 5000);
      let rejected = null;
      try { await agent.prompt('Native pre-fetch cancellation probe. No provider dispatch or response is permitted.'); }
      catch (error) { rejected = String(error); }
      finally {
        clearTimeout(timer);
        if (diagnosticFault) rmdirSync(eventsPath);
        if (movedEvents) renameSync(preservedEvents, eventsPath);
        setAuthority('RUN', 1);
      }
      result.cases[name] = { credentials, payloads, aborts, timed_out: timedOut, rejected, order: caseOrder,
        api: model.api, endpoint: model.baseUrl, errors: [...errors],
        denied_fetches: deniedFetchRecords.slice(beginning), diagnostic_fault_injected: diagnosticFault };
    }
  } finally {
    activeFetchCase = null;
    writer.close();
    runner.clearManagedTimers();
  }
}

export default function nativeApiProbe(pi) {
  pi.on('session_start', async (startEvent, ctx) => {
    const result = { scope: 'native-api-infrastructure-only', observed_at: new Date().toISOString(),
      external_requests_forwarded: 0, observer_imports: 0, children_dispatched: 0, order, cases: {} };
    try {
      const root = AgentRegistry.global().get(MAIN_AGENT_ID);
      if (!root?.session || root.session.sessionManager.getSessionId() !== ctx.sessionManager.getSessionId()) {
        throw new Error('Infrastructure root lacks actual native registry identity');
      }
      result.root = { id: root.id, kind: root.kind, uuid: ctx.sessionManager.getSessionId(),
        journal: ctx.sessionManager.getSessionFile(), pid: process.pid, cwd: ctx.cwd };
      if (resolve(ctx.cwd) !== resolve(spec.root)) throw new Error('Infrastructure cwd changed');
      if (!ctx.model) throw new Error('Native catalog model required for cancellation-only Agent probes');
      // The fixture contains no assignments/history/ownership and is never a trial ledger.
      const dbPath = resolve(spec.root, 'api-only.sqlite3');
      const db = new Database(dbPath);
      db.exec('CREATE TABLE ledger (id INTEGER PRIMARY KEY, data TEXT NOT NULL)');
      db.query('INSERT INTO ledger VALUES (1, ?)').run(JSON.stringify({ authorization: { mode: 'RUN', revision: 1 },
        trial: { manifest_digest: '0'.repeat(64) } }));
      db.close();
      const boundedSpec = { infrastructure_probe: true, assignment_id: 'APIProbeNotAssignment', ledger_path: dbPath,
        authorization_revision: 1, manifest_digest: '0'.repeat(64), execution: { provider: 'none', model: 'none', endpoint: 'none' } };
      const boundedPath = resolve(spec.root, 'bounded-api-fixture.json');
      const boundedBytes = JSON.stringify(boundedSpec);
      writeFileSync(boundedPath, boundedBytes, { flag: 'wx' });
      process.env.OMP_BOUNDED_TRIAL_SPEC = boundedPath;
      process.env.OMP_BOUNDED_TRIAL_SPEC_SHA256 = hash(boundedBytes);
      if (hash(readFileSync(spec.adapter)) !== spec.adapter_sha256) throw new Error('Reviewed adapter input changed');
      let rootCredentialCheckpoints = 0;
      root.session.agent.getApiKey = () => {
        rootCredentialCheckpoints++;
        throw new Error('INFRASTRUCTURE_ROOT_CREDENTIAL_DENIAL');
      };
      const bounded = (await loadLegacyPiModule(spec.adapter)).default;
      const runtime = new ExtensionRuntime();
      const extension = await loadExtensionFromFactory(bounded, ctx.cwd, pi.events, runtime, spec.adapter);
      if (spec.mode === 'original') {
        let rootDenied = false;
        try { await root.session.agent.getApiKey(ctx.model); }
        catch { rootDenied = true; }
        result.cases.production_root_auth_denial = { rejected: rootDenied, credential_checkpoints: rootCredentialCheckpoints };
      }
      const runner = new ExtensionRunner([extension], runtime, ctx.cwd, ctx.sessionManager,
        ctx.modelRegistry, undefined, root.session.settings);
      const errors = [];
      runner.onError(error => { errors.push(error); order.push('bounded-before-provider-error-isolated'); });
      if (spec.mode === 'workflow-startup' || spec.mode === 'registered-model-startup') {
        // Forward the actual captured native root context/start event. No child
        // context, task dispatch, observer, provider response or model is invented.
        runner.initialize(pi, ctx);
        await runner.emit(startEvent);
        if (errors.length) throw new Error('Production adapter startup reported an extension error');
        const ready = JSON.parse(readFileSync(resolve(spec.root, 'native-ready.json'), 'utf8'));
        if (ready.root_session_id !== result.root.uuid || ready.pid !== process.pid ||
            !ready.enforceable_guard || ready.tools.some(tool => !tool.available)) {
          throw new Error('Production workflow adapter did not establish genuine root/tool readiness');
        }
        if (AgentRegistry.global().list().some(ref => ref.kind === 'sub')) {
          throw new Error('Infrastructure startup unexpectedly dispatched a native child');
        }
        await ctx.sessionManager.flush();
        result.cases.production_workflow_startup = { ready, root_credential_checkpoints: rootCredentialCheckpoints,
          qualification: 'Actual production adapter startup and tool availability only; no task/write execution or reviewer/child proof' };
        runner.clearManagedTimers();
        result.success = true;
        return;
      }
      if (spec.mode === 'late-boundaries') {
        await lateBoundaryProbe(pi, ctx, runner, errors, dbPath, result);
        result.success = true;
        return;
      }
      const payload = { infrastructure_probe: 'no provider invocation' };
      const forwarded = await runner.emitBeforeProviderRequest(payload, ctx.model);
      result.cases.production_before_provider_root_refusal = {
        returned_unchanged_payload: forwarded === payload, errors, adapter_sha256: spec.adapter_sha256,
        qualification: 'Actual production hook through native runner; no provider send invoked' };
      runner.clearManagedTimers();
      const startupRuntime = new ExtensionRuntime();
      const startupExtension = await loadExtensionFromFactory(api => {
        api.on('session_start', () => { throw new Error('EXPECTED_STARTUP_PROBE_FAILURE'); });
      }, ctx.cwd, pi.events, startupRuntime, 'native-startup-error-probe');
      const startupRunner = new ExtensionRunner([startupExtension], startupRuntime, ctx.cwd,
        ctx.sessionManager, ctx.modelRegistry, undefined, root.session.settings);
      const startupErrors = [];
      startupRunner.onError(error => { startupErrors.push(error); order.push('session-start-error-isolated'); });
      await startupRunner.emit(startEvent);
      result.cases.session_start_failure = { returned_normally: true, errors: startupErrors };
      startupRunner.clearManagedTimers();

      async function probeAgent(name, install, drive = async () => {}) {
        let credentialCheckpoints = 0;
        const events = [];
        const agent = new Agent({ initialState: { model: ctx.model, systemPrompt: [], tools: [], messages: [] },
          getApiKey: () => {
            credentialCheckpoints++;
            order.push(name + ':credential-denied');
            throw new Error('NATIVE_API_PROBE_CREDENTIAL_DENIAL');
          } });
        agent.subscribe(event => events.push({ type: event.type,
          error: event.error?.message || event.message?.errorMessage || null }));
        install(agent);
        const task = agent.prompt('Infrastructure cancellation API probe; no provider request is permitted.');
        await drive(agent);
        let rejection = null;
        try { await task; } catch (error) { rejection = String(error); }
        return { credential_checkpoints: credentialCheckpoints, rejection, events };
      }
      result.cases.premodel_stop = await probeAgent('stop', agent => agent.addBeforeModelCall(() => {
        order.push('premodel-stop'); return { stop: true };
      }));
      result.cases.premodel_throw = await probeAgent('throw', agent => agent.addBeforeModelCall(() => {
        order.push('premodel-throw'); throw new Error('EXPECTED_PREMODEL_DENIAL');
      }));
      let entered, release;
      let allowed = true;
      const reached = new Promise(resolveEntered => { entered = resolveEntered; });
      result.cases.wait_without_revalidation = await probeAgent('stale-wait', agent => agent.addBeforeModelCall(async () => {
        if (!allowed) return { stop: true };
        order.push('wait-authorized-before-await');
        entered();
        await new Promise(resolveWait => { release = resolveWait; });
        order.push('wait-returned-without-recheck');
      }), async () => {
        await reached;
        allowed = false;
        order.push('authorization-revoked-while-held');
        release();
      });
      let enteredAbort;
      const held = new Promise(resolveEntered => { enteredAbort = resolveEntered; });
      result.cases.held_abort = await probeAgent('abort', agent => agent.addBeforeModelCall((_context, signal) => {
        enteredAbort();
        return new Promise((_, reject) => {
          const abort = () => reject(new Error('EXPECTED_HELD_ABORT'));
          signal.addEventListener('abort', abort, { once: true });
          if (signal.aborted) abort();
        });
      }), async agent => { await held; agent.abort(); });
      if (hash(readFileSync(spec.gate)) !== spec.gate_sha256) throw new Error('Production gate input changed');
      const { installAdmissionGuard } = await loadLegacyPiModule(spec.gate);
      result.cases.production_guard_unready = await probeAgent('guard-unready', agent => installAdmissionGuard(agent, {
        authorize: () => { throw new Error('Owner startup not ready'); },
        onFailure: error => order.push('guard-unready:' + String(error)),
      }));
      result.cases.production_guard_foreign_model = await probeAgent('guard-model', agent => installAdmissionGuard(agent, {
        authorize: model => {
          if (model.id !== 'deliberately-not-the-native-model') throw new Error('Actual model not approved');
        },
        onFailure: error => order.push('guard-model:' + String(error)),
      }));
      let permit = true, enteredGuard, releaseGuard;
      const guardEntered = new Promise(done => { enteredGuard = done; });
      result.cases.production_guard_revoked_after_wait = await probeAgent('guard-revoked', agent => installAdmissionGuard(agent, {
        authorize: () => { if (!permit) throw new Error('Durable authorization revoked while held'); },
        wait: () => new Promise(done => { releaseGuard = done; enteredGuard(); }),
        onFailure: error => order.push('guard-revoked:' + String(error)),
      }), async () => { await guardEntered; permit = false; releaseGuard(); });
      let enabled = true;
      result.cases.production_guard_auth_recheck = await probeAgent('guard-auth', agent => {
        installAdmissionGuard(agent, {
          authorize: () => { if (!enabled) throw new Error('Authorization revoked after premodel callback'); },
          onFailure: error => order.push('guard-auth:' + String(error)),
        });
        agent.addBeforeModelCall(() => { enabled = false; });
      });
      result.cases.production_guard_admitted_checkpoint = await probeAgent('guard-control', agent => installAdmissionGuard(agent, {
        authorize: model => { if (model.id !== ctx.model.id) throw new Error('Unexpected native model'); },
        onFailure: error => order.push('guard-control:' + String(error)),
      }));
      result.success = true;
    } catch (error) {
      result.success = false;
      result.error = String(error?.stack || error);
    } finally {
      result.denied_fetch_entries = deniedFetches;
      result.denied_fetch_records = deniedFetchRecords;
      result.finished_at = new Date().toISOString();
      writeFileSync(resolve(spec.root, 'native-api-result.json'), JSON.stringify(result, null, 2) + '\n', { flag: 'wx' });
      writeFileSync(resolve(spec.root, 'native-api-result.complete'), '', { flag: 'wx' });
    }
  });
}
