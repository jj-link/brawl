/* Read-only omp session-output observer.
 * Native discovery/rebinding loads factories for main and child sessions.
 * Default: loopback 8766, observing children only. Explicit same-project roots
 * opt in via build/live-dashboard/independent-roots.json:
 * {"sessions":[{"id":"<root UUID>","label":"Independent Sol","observerPort":18766}]}
 * A dedicated observerPort (1..65535, excluding 8765/8766) includes that main's
 * native message/tool updates; no provider hooks, credentials or journal replay.
 * Config/root changes close old SSE clients before rebinding. Module/factory
 * replacement releases listeners, registry subscriptions and managed timers.
 * Independent-process classification survives module replacement and shutdown:
 * removing its registration never authorizes borrowing the default 8766 port.
 * Source edits require actual extension reload/rebinding, not settings toggles;
 * Windows Bun's same-path module cache may prevent reload from rereading code.
 */
import { createServer } from 'node:http';
import { randomUUID } from 'node:crypto';
import { openSync, readSync, closeSync, readFileSync } from 'node:fs';
import { resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { AgentRegistry, MAIN_AGENT_ID } from '@oh-my-pi/pi-coding-agent/registry/agent-registry';

const DEFAULT_PORT = 8766;
const PROJECT_ROOT = resolve(fileURLToPath(new URL('../../', import.meta.url)));
const REGISTRATION_FILE = resolve(PROJECT_ROOT, 'build/live-dashboard/independent-roots.json');
const OWNER_KEY = Symbol.for(`brawl.live-output:${PROJECT_ROOT.toLowerCase()}`);
const PROCESS_SCOPE_KEY = Symbol.for(`brawl.live-output:process:${PROJECT_ROOT.toLowerCase()}`);
// This process-wide classification deliberately outlives listener ownership.
const processScope = globalThis[PROCESS_SCOPE_KEY] ||= { independent: false };
const moduleToken = {};
const bindingCleanups = new Set();
let moduleActive = true;
let port = null;
let independent = null;
const DASHBOARD_PORT = 8765;
const MAX_ENTRIES = 200;
const MAX_AGENTS = 512;
const MAX_CLIENT_QUEUE = 8 * 1024 * 1024;
const MAX_TOTAL_ENTRIES = 2000;
let epoch = randomUUID();
const agents = new Map();
const clients = new Set();
const retained = new Map();
let server;
let sequence = 0;
let failure = null;
let rootSessionId = null;
let rootSessionFile = null;
let membership = null;
const memberActivity = new Map();
const runMembership = new WeakMap();
let registryUnsubscribe;
const registry = AgentRegistry.global();
const identities = new WeakMap();
const headerBuffer = Buffer.alloc(65536);

function scopedFile(file) {
  if (!rootSessionFile || typeof file !== 'string') return false;
  const root = resolve(rootSessionFile).toLowerCase();
  const candidate = resolve(file).toLowerCase();
  return candidate === root || candidate.startsWith(root.slice(0, -6) + '\\') ||
    candidate.startsWith(root.slice(0, -6) + '/');
}

function sessionFile(ref) {
  // Registration stores a snapshot. A live manager can subsequently relocate
  // or switch its journal without updating that snapshot.
  return ref.session?.sessionManager.getSessionFile() || ref.sessionFile;
}

function journalHeader(file) {
  let handle;
  try {
    handle = openSync(file, 'r');
    const bytes = readSync(handle, headerBuffer, 0, headerBuffer.length, 0);
    const lines = headerBuffer.toString('utf8', 0, bytes).split('\n', 2);
    let header = JSON.parse(lines[0]);
    if (header.type === 'title') header = JSON.parse(lines[1]);
    return header.type === 'session' ? header : null;
  } catch {
    return null;
  } finally {
    if (handle !== undefined) closeSync(handle);
  }
}

function rootRegistration(ctx) {
  let config;
  try {
    config = JSON.parse(readFileSync(REGISTRATION_FILE, 'utf8'));
  } catch (error) {
    if (error.code === 'ENOENT') return null;
    throw error;
  }
  if (!config || !Array.isArray(config.sessions)) throw new Error('expected a sessions array');
  const ids = new Set(), ports = new Set();
  let selected = null;
  for (const entry of config.sessions) {
    if (!entry || typeof entry.id !== 'string' ||
        !/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$/i.test(entry.id) ||
        typeof entry.label !== 'string' || !entry.label.trim() ||
        entry.label.trim().toLowerCase() === 'main') throw new Error('invalid independent root identity');
    const id = entry.id.toLowerCase();
    if (ids.has(id)) throw new Error('duplicate independent root identity');
    ids.add(id);
    if (Object.hasOwn(entry, 'observerPort')) {
      if (!Number.isInteger(entry.observerPort) || entry.observerPort < 1 ||
          entry.observerPort > 65535 || [DASHBOARD_PORT, DEFAULT_PORT].includes(entry.observerPort) ||
          ports.has(entry.observerPort)) throw new Error('invalid or duplicate observerPort');
      ports.add(entry.observerPort);
    }
    if (id === ctx.sessionManager.getSessionId()?.toLowerCase()) {
      const header = journalHeader(ctx.sessionManager.getSessionFile());
      if (!header || header.id?.toLowerCase() !== id || typeof header.cwd !== 'string' ||
          resolve(header.cwd).toLowerCase() !== PROJECT_ROOT.toLowerCase()) {
        throw new Error('independent root journal does not belong to this project');
      }
      selected = { id, label: entry.label.trim(), observerPort: entry.observerPort };
    }
  }
  return selected;
}

function sessionId(ref, file = sessionFile(ref)) {
  const live = ref.session?.sessionManager.getSessionId();
  if (live) {
    identities.set(ref, { file, id: live });
    return live;
  }
  const cached = identities.get(ref);
  if (cached && cached.file === file) return cached.id;
  if (!file) return null;
  // Read only the identity prefix, never recorded task/output content.
  const header = journalHeader(file);
  if (typeof header?.id !== 'string') return null;
  identities.set(ref, { file, id: header.id });
  return header.id;
}

function assignmentActive(ref) {
  if (ref.status === 'aborted' || ref.status === 'parked') return false;
  // Running includes real long tools/waits and wake turns. Idle alone is not
  // an assignment boundary: an intermediate turn can settle before its
  // executor resumes it. Accepted results are run-scoped and cleared on wake.
  if (ref.status === 'running') {
    return !(ref.lifecycle?.acceptedAt !== undefined && !registry.isRunning(ref));
  }
  if (ref.lifecycle?.acceptedAt !== undefined) return false;
  return runMembership.get(ref);
}

function refreshMembership() {
  const main = registry.get(MAIN_AGENT_ID);
  if (!rootSessionId || !rootSessionFile?.endsWith('.jsonl') || !main?.session ||
      main.session.sessionManager.getSessionId() !== rootSessionId) return;
  rootSessionFile = main.session.sessionManager.getSessionFile() || rootSessionFile;
  const members = [];
  if (independent) members.push({ id: rootSessionId });
  let complete = true;
  for (const ref of registry.list()) {
    if (ref.kind !== 'sub') continue;
    const file = sessionFile(ref);
    if (!file) { complete = false; continue; }
    if (!scopedFile(file)) continue;
    const id = sessionId(ref, file);
    if (!id) { complete = false; continue; }
    const active = assignmentActive(ref);
    members.push({ id, ...(typeof active === 'boolean' ? { active } : {}) });
  }
  members.sort((a, b) => a.id.localeCompare(b.id));
  const signature = JSON.stringify({ complete, agents: members });
  if (membership?.signature === signature) return;
  membership = { source: 'runner-registry', complete,
    revision: (membership?.revision || 0) + 1, updatedAt: new Date().toISOString(),
    agents: members, signature };
  memberActivity.clear();
  for (const member of members) memberActivity.set(member.id, member.active);
  broadcast('membership', { epoch, rootSessionId, membership: publicMembership() });
  for (const agent of agents.values()) publishAgent(agent);
}

function publicMembership() {
  if (!membership) return undefined;
  const { signature, ...result } = membership;
  return result;
}

function stopServer() {
  for (const client of clients) client.response.end();
  clients.clear();
  server?.close();
  server = undefined;
  failure = null;
}

function bindRoot(ctx) {
  // Reconcile only from the owning main binding, never a child or cwd.
  const id = ctx.sessionManager.getSessionId();
  let registration, nextPort;
  try {
    registration = rootRegistration(ctx);
    if (registration) processScope.independent = true;
    nextPort = registration?.observerPort ??
      (processScope.independent ? null : DEFAULT_PORT);
  } catch (error) {
    nextPort = null; // Invalid opt-in must never bind the default runner's port.
    console.error(`[live-output] independent registration unavailable: ${error.message}`);
  }
  const nextIndependent = registration || null;
  const changed = rootSessionId !== id || port !== nextPort ||
    JSON.stringify(independent) !== JSON.stringify(nextIndependent);
  if (!changed) {
    rootSessionFile = ctx.sessionManager.getSessionFile() || null;
    refreshMembership();
    return;
  }
  // End old sockets before selecting a new root/port; no delta can cross roots.
  stopServer();
  epoch = randomUUID();
  sequence = 0;
  agents.clear();
  retained.clear();
  membership = null;
  memberActivity.clear();
  rootSessionId = id;
  rootSessionFile = ctx.sessionManager.getSessionFile() || null;
  independent = nextIndependent;
  port = nextPort;
  refreshMembership();
  if (independent && port) touch(ctx, 'waiting');
  ensureServer();
}

// Select documented user-visible block fields, not provider replay signatures,
// encrypted reasoning, request payloads or authentication metadata. Session
// text itself is unchanged: no path gates, regex suppression or word buffering.
function contentBlock(block) {
  if (!block || typeof block !== 'object') return null;
  if (block.type === 'text' && typeof block.text === 'string') {
    return { type: 'text', text: block.text };
  }
  if (block.type === 'thinking' && typeof block.thinking === 'string') {
    return { type: 'thinking', thinking: block.thinking,
      ...(typeof block.summary === 'boolean' ? { summary: block.summary } : {}) };
  }
  if (block.type === 'image' && typeof block.data === 'string' && typeof block.mimeType === 'string') {
    return { type: 'image', data: block.data, mimeType: block.mimeType };
  }
  return null;
}

function contentBlocks(content) {
  if (typeof content === 'string') return [{ type: 'text', text: content }];
  return Array.isArray(content) ? content.map(contentBlock).filter(Boolean) : [];
}

function blocksText(blocks) {
  return blocks.map(block => block.type === 'text' ? block.text :
    block.type === 'thinking' ? block.thinking : '').filter(text => text !== '').join('\n');
}

function argString(args, key) {
  return args && typeof args === 'object' && typeof args[key] === 'string' ? args[key] : '';
}


function toolCallId(event) {
  return typeof event.toolCallId === 'string' ? event.toolCallId : '';
}

function toolText(tool, intent, target) {
  return `${tool}${intent ? `: ${intent}` : ''}${target ? `\nTarget: ${target}` : ''}`;
}

// One item per actual call. Arguments stay separate from the textual
// compatibility projection; end events can create an item even without start.
function toolItem(agent, event) {
  const callId = toolCallId(event);
  const tool = String(event.toolName ?? 'tool');
  return { id: `${agent.id}:${callId}`, agentId: agent.id, callId,
    at: new Date().toISOString(), kind: 'tool', tool,
    ...(event.args !== undefined ? { args: event.args } : {}),
    text: toolText(tool, String(event.intent ?? argString(event.args, 'i')), argString(event.args, 'path')),
    complete: false, isError: false, status: 'running', sequence: 0 };
}

function toolResult(item, result, complete = false) {
  // AgentToolResult supports text/images and optional UI details. A supplied
  // empty final content array replaces partial output instead of retaining it.
  const content = typeof result === 'string' ? result : result?.content;
  if (typeof content === 'string' || Array.isArray(content)) {
    item.blocks = contentBlocks(content);
    item.text = blocksText(item.blocks);
  }
  if (complete) delete item.details;
  if (result && typeof result === 'object' && Object.hasOwn(result, 'details')) {
    item.details = result.details;
  }
}

function frame(type, data) {
  return `event: ${type}\ndata: ${JSON.stringify(data)}\n\n`;
}

function send(client, value) {
  // Bound already-backlogged consumers without cutting any incoming frame.
  // Even an individual image/result larger than the queue budget is sent whole.
  if (client.response.writableLength > MAX_CLIENT_QUEUE) {
    client.response.destroy();
    clients.delete(client);
    return;
  }
  client.response.write(value);
}

function broadcast(type, data) {
  const value = frame(type, data);
  for (const client of clients) send(client, value);
}

function publicAgent(agent) {
  const active = memberActivity.has(agent.id) ? memberActivity.get(agent.id) :
    membership?.complete ? false : undefined;
  return { id: agent.id, name: agent.name, definition: agent.definition,
    model: agent.model, state: agent.state, lastSeen: agent.lastSeen, observed: true,
    ...(independent && agent.id === rootSessionId ? {
      name: independent.label, scope: 'independent-root', rootSessionId,
      streamSource: 'live-observer',
    } : {}),
    ...(typeof active === 'boolean' ? { active } : {}) };
}

function publishAgent(agent) {
  const data = publicAgent(agent);
  const { lastSeen, ...metadata } = data;
  const signature = JSON.stringify(metadata);
  const now = Date.now();
  // Prose/tool deltas remain immediate. Repeating identical identity/status
  // metadata for every delta only makes clients re-render unchanged panes.
  if (signature === agent.metadata && now - agent.metadataAt < 1000) return;
  agent.metadata = signature; agent.metadataAt = now;
  broadcast('agent', data);
}

function publicItem(item) {
  const result = { id: item.id, agentId: item.agentId, at: item.at, sequence: item.sequence,
    kind: item.kind || 'message', text: item.text, complete: item.complete, source: 'live' };
  const fields = item.kind === 'tool' ?
    ['tool', 'callId', 'args', 'blocks', 'details', 'isError', 'status'] :
    ['role', 'channel', 'blocks', 'details', 'customType', 'sender', 'stopReason', 'errorMessage', 'isError'];
  for (const key of fields) {
    if (item[key] !== undefined) result[key] = item[key];
  }
  return result;
}

function snapshot() {
  return { epoch, rootSessionId, sequence, connected: true, membership: publicMembership(),
    agents: [...agents.values()].map(publicAgent),
    items: [...agents.values()].flatMap(a => [...a.items.values()].map(publicItem)) };
}

function touch(ctx, state) {
  // Session UUID matches journal identity. Registry id supplies the worker's
  // display name; ctx.agent.name is only its lowercased agent definition.
  const id = ctx.sessionManager.getSessionId();
  let agent = agents.get(id);
  if (!agent) {
    agent = { id, name: String(ctx.agent.id),
      definition: String(ctx.agent.name), items: new Map() };
    agents.set(id, agent);
    if (agents.size > MAX_AGENTS) {
      const evicted = agents.keys().next().value;
      for (const item of agents.get(evicted).items.values()) {
        retained.delete(item.id);
      }
      agents.delete(evicted);
      broadcast('evict', { agentId: evicted });
    }
  }
  agent.model = ctx.model ? String(ctx.model.id) : null;
  agent.lastSeen = new Date().toISOString();
  if (state) agent.state = state;
  agent.state ||= 'waiting';
  publishAgent(agent);
  return agent;
}

function evict(agent, item) {
  agent.items.delete(item.id);
  retained.delete(item.id);
  broadcast('evict', { agentId: agent.id, itemId: item.id });
}

function trim(agent) {
  // Retention removes whole old entries by count, never bytes from an item.
  while (agent.items.size > MAX_ENTRIES) {
    evict(agent, agent.items.values().next().value);
  }
  while (retained.size > MAX_TOTAL_ENTRIES) {
    const oldest = retained.values().next().value;
    evict(agents.get(oldest.agentId), oldest);
  }
}

function publish(agent, item) {
  retained.set(item.id, item);
  item.sequence = ++sequence;
  broadcast('text', publicItem(item));
  trim(agent);
}

function ensureServer() {
  if (server || failure || !port || !moduleActive) return;
  const listeningPort = port;
  const listener = createServer((request, response) => {
    // A switch may precede its extension event. Never serve stale-root data.
    if (registry.get(MAIN_AGENT_ID)?.session?.sessionManager.getSessionId() !== rootSessionId) {
      response.writeHead(503); response.end(); return;
    }
    const host = request.headers.host;
    const origin = request.headers.origin;
    const allowed = host === `127.0.0.1:${listeningPort}` || host === `localhost:${listeningPort}`;
    const originOK = !origin || origin === `http://127.0.0.1:${DASHBOARD_PORT}` || origin === `http://localhost:${DASHBOARD_PORT}`;
    if (!allowed || !originOK) { response.writeHead(403); response.end(); return; }
    if (request.method !== 'GET') { response.writeHead(405, { Allow: 'GET' }); response.end(); return; }
    if (request.url === '/status') {
      response.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' });
      refreshMembership();
      response.end(JSON.stringify({ connected: true, epoch, rootSessionId, sequence, pid: process.pid,
        agents: agents.size, membership: publicMembership(), contract: 'omp-v18.9.2-extension-session-output' }));
      return;
    }
    if (request.url !== '/events') { response.writeHead(404); response.end(); return; }
    response.writeHead(200, { 'Content-Type': 'text/event-stream', 'Cache-Control': 'no-store', 'Connection': 'keep-alive' });
    response.flushHeaders();
    const client = { response };
    clients.add(client);
    send(client, 'retry: 3000\n\n' + frame('snapshot', snapshot()));
    const heartbeat = setInterval(() => send(client, ': observer alive\n\n'), 10000);
    response.on('close', () => { clearInterval(heartbeat); clients.delete(client); });
    response.on('error', () => { clearInterval(heartbeat); clients.delete(client); });
  });
  server = listener;
  listener.on('error', error => {
    if (server !== listener) return; // A retired listener cannot poison its replacement.
    failure = error.code || error.message;
    // Fail visibly rather than attach to another process or fabricate a feed.
    console.error(`[live-output] observer listener failed: ${failure}`);
    for (const client of clients) client.response.destroy();
    clients.clear();
  });
  listener.listen(listeningPort, '127.0.0.1');
}

/** @param {import('@oh-my-pi/pi-coding-agent').ExtensionAPI} pi */
export default function liveOutput(pi) {
  const completedMessages = new Set();
  const completedCalls = new Set();
  let stopped = false;
  let releaseRoot;
  // Journal ancestry, not cwd: isolated worktrees still belong to this root.
  const owningRoot = ctx => ctx.agent.kind === 'main' && ctx.agent.id === MAIN_AGENT_ID;
  const eligible = ctx => !stopped && moduleActive && port && rootSessionId &&
    registry.get(MAIN_AGENT_ID)?.session?.sessionManager.getSessionId() === rootSessionId &&
    ((owningRoot(ctx) && independent && ctx.sessionManager.getSessionId() === rootSessionId) ||
     (ctx.agent.kind === 'sub' &&
      scopedFile(ctx.sessionManager.getSessionFile() || registry.get(ctx.agent.id)?.sessionFile)));
  const messageKey = (ctx, message) => `${ctx.sessionManager.getSessionId()}:${message.timestamp}` +
    (message.role === 'assistant' ? '' : `:${message.role}${message.details?.id ? `:${message.details.id}` : ''}`);
  const observe = (ctx, state) => {
    if (!eligible(ctx)) return null;
    ensureServer();
    return touch(ctx, state);
  };
  const remember = (set, id) => {
    set.add(id);
    if (set.size > MAX_TOTAL_ENTRIES) set.delete(set.values().next().value);
  };
  const messageItem = (agent, key, message, index) => {
    const id = `${key}:${index}`;
    let item = agent.items.get(id);
    if (!item) {
      item = { id, agentId: agent.id, at: new Date(message.timestamp).toISOString(),
        kind: 'message', role: message.role, text: '', complete: false, sequence: 0 };
      agent.items.set(id, item);
    }
    return item;
  };
  const captureCall = (agent, call, message) => {
    if (typeof call.id !== 'string' || !call.id) return;
    const event = { toolCallId: call.id, toolName: call.name, args: call.arguments, intent: call.intent };
    const fresh = toolItem(agent, event);
    let item = agent.items.get(fresh.id);
    if (!item) {
      if (completedCalls.has(fresh.id)) return;
      item = fresh;
      item.at = new Date(message.timestamp).toISOString();
      item.status = 'pending';
      agent.items.set(item.id, item);
    } else if (item.args === undefined) {
      item.args = call.arguments;
    } else {
      return;
    }
    publish(agent, item);
  };
  const finishTool = (event, ctx) => {
    if (!eligible(ctx) || !toolCallId(event)) return;
    const id = `${ctx.sessionManager.getSessionId()}:${toolCallId(event)}`;
    if (completedCalls.has(id)) return;
    const agent = observe(ctx, null);
    const item = agent.items.get(id) || toolItem(agent, event);
    agent.items.set(id, item);
    remember(completedCalls, id);
    toolResult(item, event.result, true);
    item.complete = true;
    item.isError = event.isError === true;
    item.status = item.isError ? 'error' : 'completed';
    publish(agent, item);
  };
  const relayMessage = (message, ctx, complete) => {
    if (!eligible(ctx)) return;
    if (message.role === 'toolResult') {
      if (complete) finishTool({ toolCallId: message.toolCallId, toolName: message.toolName,
        result: message, isError: message.isError }, ctx);
      return;
    }
    // Displayable custom messages include injected peer/async-result records.
    // The SDK has no irc_message extension hook: immediate receipt and
    // nonpersisted relay observations are not exposed by these subscriptions.
    if (message.role !== 'assistant' && message.role !== 'user' &&
        !(['custom', 'hookMessage'].includes(message.role) && message.display === true)) return;
    const key = messageKey(ctx, message);
    if (completedMessages.has(key)) return;
    const agent = observe(ctx, null);
    if (complete) remember(completedMessages, key);
    if (message.role !== 'assistant') {
      const item = messageItem(agent, key, message, 'message');
      item.blocks = contentBlocks(message.content);
      item.text = blocksText(item.blocks);
      item.complete = complete;
      if (message.details !== undefined) item.details = message.details;
      if (message.customType !== undefined) item.customType = message.customType;
      if (typeof message.details?.from === 'string') item.sender = message.details.from;
      publish(agent, item);
      return;
    }
    const content = Array.isArray(message.content) ? message.content : [];
    const published = new Set();
    for (let index = 0; index < content.length; ++index) {
      const block = content[index];
      if (block.type === 'toolCall') { captureCall(agent, block, message); continue; }
      const visibleBlock = contentBlock(block);
      if (!visibleBlock) continue;
      const item = messageItem(agent, key, message, index);
      item.blocks = [visibleBlock];
      item.text = blocksText(item.blocks);
      if (visibleBlock.type === 'thinking') item.channel = 'thinking';
      else delete item.channel;
      item.complete = complete;
      if (complete) {
        item.stopReason = message.stopReason;
        item.errorMessage = message.errorMessage;
        item.isError = message.stopReason === 'error';
      }
      // First observations keep the original content-index ordering, even
      // when the final snapshot also introduces a previously missed tool call.
      publish(agent, item);
      published.add(item.id);
    }
    if (!complete) return;
    const prefix = `${key}:`;
    let items = [...agent.items.values()].filter(item => item.kind === 'message' && item.id.startsWith(prefix));
    if (!items.length && (message.stopReason === 'error' || message.stopReason === 'aborted' || message.errorMessage)) {
      items = [messageItem(agent, key, message, 'outcome')];
    }
    for (const item of items) {
      if (published.has(item.id)) continue;
      item.complete = true;
      item.stopReason = message.stopReason;
      item.errorMessage = message.errorMessage;
      item.isError = message.stopReason === 'error';
      publish(agent, item);
    }
  };
  const unsubscribeLifecycle = pi.events.on('task:subagent:lifecycle', payload => {
    // Executor settlement, unlike agent_end, is an assignment boundary.
    if (stopped || !moduleActive) return;
    if (!payload || typeof payload !== 'object' || !scopedFile(payload.sessionFile)) return;
    const ref = registry.get(payload.id);
    if (!ref || ref.kind !== 'sub' ||
        sessionFile(ref) !== payload.sessionFile) return;
    if (!['started', 'completed', 'failed', 'aborted'].includes(payload.status)) return;
    runMembership.set(ref, payload.status === 'started');
    refreshMembership();
  });
  const releaseBinding = () => {
    if (!bindingCleanups.delete(releaseBinding)) return;
    stopped = true;
    unsubscribeLifecycle();
  };
  bindingCleanups.add(releaseBinding);

  // Main owns one listener and one managed registry poll. Factory rebinding or
  // fresh module evaluation retires the previous owner without touching runners.
  pi.on('session_start', (_event, ctx) => {
    if (owningRoot(ctx)) {
      if (releaseRoot && !stopped) { bindRoot(ctx); return; }
      globalThis[OWNER_KEY]?.dispose(moduleToken);
      stopped = false;
      moduleActive = true;
      bindRoot(ctx);
      registryUnsubscribe = registry.onChange(refreshMembership);
      const timer = ctx.setInterval(() => bindRoot(ctx), 1000);
      const owner = { dispose(nextToken) {
        if (stopped) return;
        stopped = true;
        if (nextToken && nextToken !== moduleToken) {
          moduleActive = false;
          for (const cleanup of [...bindingCleanups]) cleanup();
        }
        ctx.clearTimer(timer);
        registryUnsubscribe?.(); registryUnsubscribe = undefined;
        stopServer();
        rootSessionId = null;
        rootSessionFile = null;
        port = null;
        agents.clear(); retained.clear(); membership = null; memberActivity.clear();
        releaseBinding();
        if (globalThis[OWNER_KEY] === owner) delete globalThis[OWNER_KEY];
      } };
      globalThis[OWNER_KEY] = owner;
      releaseRoot = () => owner.dispose();
    } else if (eligible(ctx)) {
      touch(ctx, 'waiting');
    }
  });
  pi.on('session_switch', (_event, ctx) => {
    if (!stopped && moduleActive && owningRoot(ctx)) bindRoot(ctx);
  });
  pi.on('agent_start', (_event, ctx) => observe(ctx, 'working'));
  pi.on('agent_end', (event, ctx) => observe(ctx, event.willContinue ? 'working' : 'waiting'));
  pi.on('session_shutdown', (_event, ctx) => {
    if (stopped) return;
    if (eligible(ctx)) observe(ctx, 'stopped');
    if (owningRoot(ctx)) releaseRoot?.();
    else releaseBinding();
  });
  pi.on('message_start', (event, ctx) => relayMessage(event.message, ctx, false));
  pi.on('message_end', (event, ctx) => relayMessage(event.message, ctx, true));
  pi.on('message_update', (event, ctx) => {
    if (!eligible(ctx) || event.message.role !== 'assistant') return;
    const key = messageKey(ctx, event.message);
    // Detached message_end wins over every queued, late streaming update.
    if (completedMessages.has(key)) return;
    const delta = event.assistantMessageEvent;
    if (!['text_start', 'text_delta', 'text_end', 'thinking_start', 'thinking_delta',
      'thinking_end', 'image_end', 'toolcall_end'].includes(delta.type)) return;
    const agent = observe(ctx, 'working');
    if (delta.type === 'toolcall_end') { captureCall(agent, delta.toolCall, event.message); return; }
    const item = messageItem(agent, key, event.message, delta.contentIndex);
    if (item.complete) return;
    const thinking = delta.type.startsWith('thinking_');
    const partialBlock = contentBlock(event.message.content?.[delta.contentIndex]);
    if (thinking) item.channel = 'thinking';
    if (delta.type === 'image_end') {
      const image = contentBlock(delta.content);
      item.blocks = image ? [image] : [];
      item.text = '';
    } else {
      if (delta.type.endsWith('_delta')) {
        // The SDK partial is cumulative; it recovers a stream bound mid-word.
        item.text = partialBlock ? blocksText([partialBlock]) : item.text + delta.delta;
      } else if (delta.type.endsWith('_end')) {
        item.text = delta.content;
      } else if (partialBlock) {
        item.text = blocksText([partialBlock]);
      }
      item.blocks = [thinking ? { ...partialBlock, type: 'thinking', thinking: item.text } :
        { type: 'text', text: item.text }];
    }
    // Block-end closes streaming content, not the encompassing message.
    publish(agent, item);
  });

  // Execution starts may reopen a repeated call. Updates never regress a
  // completed result; missing starts do not suppress actual updates or ends.
  pi.on('tool_execution_start', (event, ctx) => {
    if (!toolCallId(event)) return;
    const agent = observe(ctx, 'working');
    if (!agent) return;
    const fresh = toolItem(agent, event);
    completedCalls.delete(fresh.id);
    const item = agent.items.get(fresh.id) || fresh;
    item.tool = fresh.tool; item.args = event.args; item.text = fresh.text;
    item.complete = false; item.isError = false; item.status = 'running';
    delete item.blocks; delete item.details;
    agent.items.set(item.id, item);
    publish(agent, item);
  });
  pi.on('tool_execution_update', (event, ctx) => {
    if (!eligible(ctx) || !toolCallId(event)) return;
    const id = `${ctx.sessionManager.getSessionId()}:${toolCallId(event)}`;
    if (completedCalls.has(id)) return;
    const agent = observe(ctx, 'working');
    const item = agent.items.get(id) || toolItem(agent, event);
    if (item.complete) return;
    if (event.args !== undefined) item.args = event.args;
    item.status = 'running';
    toolResult(item, event.partialResult);
    if (typeof event.partialResult?.isError === 'boolean') item.isError = event.partialResult.isError;
    agent.items.set(id, item);
    publish(agent, item);
  });
  pi.on('tool_execution_end', finishTool);
}
