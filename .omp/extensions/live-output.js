/* Read-only omp v18.8.9 observer. Native project extension discovery loads this
 * at startup and rebinds the factory to existing/revived child sessions.
 * No tools, prompts, provider hooks, session mutation or model calls.
 */
import { createServer } from 'node:http';
import { randomUUID } from 'node:crypto';
import { dirname, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const PORT = 8766;
const DASHBOARD_PORT = 8765;
const MAX_TEXT = 16000;
const MAX_ENTRIES = 200;
const MAX_AGENT_CHARS = 128 * 1024;
const MAX_AGENTS = 512;
const MAX_CLIENT_QUEUE = 8 * 1024 * 1024;
const MAX_TOTAL_CHARS = 2 * 1024 * 1024;
const MAX_TOTAL_ENTRIES = 2000;
const project = resolve(dirname(fileURLToPath(import.meta.url)), '../..');
const epoch = randomUUID();
const agents = new Map();
const clients = new Set();
const retained = new Map();
let retainedChars = 0;
let server;
let sequence = 0;
let failure = null;
let rootSessionId = null;

// Sanitize BEFORE transport. Retain the unfinished whitespace-delimited token:
// otherwise a credential split between provider deltas could leak its prefix.
// Sensitive labels suppress the rest of that line, including spaced/quoted
// values. Private tags/keys suppress even unterminated blocks. False positives
// deliberately favor privacy. There is no raw-event or tool-result transport.
function visible(raw, flush) {
  let text = raw;
  if (!flush) {
    const end = Math.max(text.lastIndexOf(' '), text.lastIndexOf('\n'), text.lastIndexOf('\t'), text.lastIndexOf('\r'));
    text = end < 0 ? '' : text.slice(0, end + 1);
  }
  text = text.replace(/<(system(?:-reminder|-notice)?|developer|thinking|analysis|contextSnapshot)\b[^>]*(?:>[\s\S]*?(?:<\/\1\s*>|$)|$)/gi, '[private context omitted]');
  // Withhold an unfinished tag, even when its name itself is split.
  text = text.replace(/<[^>]*$/, '');
  text = text.replace(/-----BEGIN [^\n]*PRIVATE KEY-----[\s\S]*?(?:-----END [^\n]*PRIVATE KEY-----|$)/g, '[credential redacted]');
  text = text.replace(/\b(?:api[_-]?key|access[_-]?token|refresh[_-]?token|client[_-]?secret|password|passwd|authorization|credential|Bearer|Basic)\b[^\n]*/gi, '[credential redacted]');
  text = text.replace(/\b(?:sk-[A-Za-z0-9_-]*|gh[pousr]_[A-Za-z0-9_]*|github_pat_[A-Za-z0-9_]*|AKIA[A-Z0-9]*)/g, '[credential redacted]');
  text = text.replace(/(https?:\/\/)[^/\s:@]+:[^/\s@]*(?:@|$)/g, '$1[redacted]@');
  return text.replace(/[\x00-\x08\x0b\x0c\x0e-\x1f\x7f]/g, '');
}

function frame(type, data) {
  return `event: ${type}\ndata: ${JSON.stringify(data)}\n\n`;
}

function send(client, value) {
  // Bound slow consumers without blocking generation. A reconnect receives a
  // fresh retained snapshot, never a duplicated append or invented missed text.
  if (client.response.writableLength + Buffer.byteLength(value) > MAX_CLIENT_QUEUE) {
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
  return { id: agent.id, name: agent.name, definition: agent.definition,
    model: agent.model, state: agent.state, lastSeen: agent.lastSeen, observed: true };
}

function publicItem(item) {
  return { id: item.id, agentId: item.agentId, at: item.at, sequence: item.sequence,
    kind: 'message', role: 'assistant', text: item.text, complete: item.complete,
    truncated: item.truncated, source: 'live' };
}

function snapshot() {
  return { epoch, rootSessionId, sequence, connected: true, agents: [...agents.values()].map(publicAgent),
    items: [...agents.values()].flatMap(a => [...a.items.values()].map(publicItem)) };
}

function touch(ctx, state) {
  // Session UUID matches journal identity. Registry id supplies the worker's
  // display name; ctx.agent.name is only its lowercased agent definition.
  const id = ctx.sessionManager.getSessionId();
  let agent = agents.get(id);
  if (!agent) {
    agent = { id, name: visible(String(ctx.agent.id), true).slice(0, 120),
      definition: visible(String(ctx.agent.name), true).slice(0, 80), items: new Map() };
    agents.set(id, agent);
    if (agents.size > MAX_AGENTS) {
      const evicted = agents.keys().next().value;
      for (const item of agents.get(evicted).items.values()) {
        retainedChars -= item.size || 0;
        retained.delete(item.id);
      }
      agents.delete(evicted);
      broadcast('evict', { agentId: evicted });
    }
  }
  agent.model = ctx.model ? visible(String(ctx.model.id), true).slice(0, 120) : null;
  agent.lastSeen = new Date().toISOString();
  if (state) agent.state = state;
  agent.state ||= 'waiting';
  broadcast('agent', publicAgent(agent));
  return agent;
}

function evict(agent, item) {
  agent.items.delete(item.id);
  retained.delete(item.id);
  retainedChars -= item.size || 0;
  broadcast('evict', { agentId: agent.id, itemId: item.id });
}

function trim(agent) {
  let chars = 0;
  const entries = [...agent.items.values()];
  for (let i = entries.length - 1; i >= 0; --i) {
    chars += entries[i].raw.length + entries[i].text.length;
    if (i < entries.length - MAX_ENTRIES || chars > MAX_AGENT_CHARS) {
      evict(agent, entries[i]);
    }
  }
  while (retainedChars > MAX_TOTAL_CHARS || retained.size > MAX_TOTAL_ENTRIES) {
    const oldest = retained.values().next().value;
    evict(agents.get(oldest.agentId), oldest);
  }
}

function publish(agent, item, flush = false) {
  const text = visible(item.raw, flush);
  retainedChars -= item.size || 0;
  item.size = item.raw.length + text.length;
  retainedChars += item.size;
  retained.set(item.id, item);
  if (text === item.text && !flush) { trim(agent); return; }
  item.text = text;
  item.sequence = ++sequence;
  broadcast('text', publicItem(item));
  trim(agent);
}

function ensureServer() {
  if (server || failure) return;
  server = createServer((request, response) => {
    const host = request.headers.host;
    const origin = request.headers.origin;
    const allowed = host === `127.0.0.1:${PORT}` || host === `localhost:${PORT}`;
    const originOK = !origin || origin === `http://127.0.0.1:${DASHBOARD_PORT}` || origin === `http://localhost:${DASHBOARD_PORT}`;
    if (!allowed || !originOK) { response.writeHead(403); response.end(); return; }
    if (request.method !== 'GET') { response.writeHead(405, { Allow: 'GET' }); response.end(); return; }
    if (request.url === '/status') {
      response.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' });
      response.end(JSON.stringify({ connected: true, epoch, rootSessionId, sequence, pid: process.pid,
        agents: agents.size, contract: 'omp-v18.8.9-extension-text-delta' }));
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
  server.on('error', error => {
    failure = error.code || error.message;
    // Fail visibly rather than attach to another process or fabricate a feed.
    console.error(`[live-output] observer listener failed: ${failure}`);
    for (const client of clients) client.response.destroy();
    clients.clear();
  });
  server.listen(PORT, '127.0.0.1');
}

/** @param {import('@oh-my-pi/pi-coding-agent').ExtensionAPI} pi */
export default function liveOutput(pi) {
  const completedMessages = new Set();
  const eligible = ctx => resolve(ctx.cwd).toLowerCase() === project.toLowerCase() && ctx.agent.kind === 'sub';
  const messageKey = (ctx, message) => `${ctx.sessionManager.getSessionId()}:${message.timestamp}`;
  const observe = (ctx, state) => {
    if (!eligible(ctx)) return null;
    ensureServer();
    return touch(ctx, state);
  };

  // Root binding starts the one shared listener; child bindings observe their
  // own events concurrently. No assumption about task:subagent:event wrappers.
  pi.on('session_start', (_event, ctx) => {
    if (resolve(ctx.cwd).toLowerCase() !== project.toLowerCase()) return;
    if (ctx.agent.kind === 'main') rootSessionId = ctx.sessionManager.getSessionId();
    ensureServer();
    if (eligible(ctx)) touch(ctx, 'waiting');
  });
  pi.on('agent_start', (_event, ctx) => observe(ctx, 'working'));
  pi.on('agent_end', (event, ctx) => observe(ctx, event.willContinue ? 'working' : 'waiting'));
  pi.on('session_shutdown', (_event, ctx) => {
    if (eligible(ctx)) { observe(ctx, 'stopped'); return; }
    if (resolve(ctx.cwd).toLowerCase() !== project.toLowerCase()) return;
    for (const client of clients) client.response.end();
    clients.clear();
    server?.close();
    server = undefined;
  });
  pi.on('message_update', (event, ctx) => {
    if (!eligible(ctx) || event.message.role !== 'assistant') return;
    const delta = event.assistantMessageEvent;
    if (delta.type !== 'text_delta' && delta.type !== 'text_end') return;
    const key = messageKey(ctx, event.message);
    const agent = observe(ctx, completedMessages.has(key) ? null : 'working');
    // message_end is detached from the serialized update queue. Completion
    // evidence must survive late updates, including a first text_end.
    const id = `${key}:${delta.contentIndex}`;
    let item = agent.items.get(id);
    if (!item) {
      item = { id, agentId: agent.id, at: new Date(event.message.timestamp).toISOString(),
        raw: '', text: '', complete: completedMessages.has(key), truncated: false, sequence: 0 };
      agent.items.set(id, item);
    }
    if (delta.type === 'text_delta') {
      const next = item.raw + delta.delta;
      item.truncated ||= next.length > MAX_TEXT;
      item.raw = next.slice(0, MAX_TEXT);
      publish(agent, item, item.complete);
    } else {
      // text_end is not message completion. Flushing here preserves an
      // unfinished last word, while complete stays false until message_end.
      item.raw = delta.content.slice(0, MAX_TEXT);
      item.truncated ||= delta.content.length > MAX_TEXT;
      publish(agent, item, true);
    }
  });
  pi.on('message_end', (event, ctx) => {
    if (!eligible(ctx) || event.message.role !== 'assistant') return;
    const key = messageKey(ctx, event.message);
    completedMessages.add(key);
    if (completedMessages.size > MAX_ENTRIES) completedMessages.delete(completedMessages.values().next().value);
    const agent = agents.get(ctx.sessionManager.getSessionId());
    if (!agent) return;
    const prefix = `${key}:`;
    for (const item of agent.items.values()) {
      if (item.id.startsWith(prefix)) { item.complete = true; publish(agent, item, true); }
    }
  });
}
