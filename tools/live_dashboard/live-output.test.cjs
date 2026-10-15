'use strict';

const assert = require('node:assert/strict');
const { test } = require('node:test');
const { readFileSync } = require('node:fs');
const { resolve } = require('node:path');
const { fileURLToPath, pathToFileURL } = require('node:url');
const { randomUUID } = require('node:crypto');
const { EventEmitter } = require('node:events');
const { createContext, runInContext } = require('node:vm');

const ROOT = '00000000-0000-4000-8000-000000000001';
const CHILD = '00000000-0000-4000-8000-000000000002';
const OTHER = '00000000-0000-4000-8000-000000000003';
const filename = resolve(__dirname, '../../.omp/extensions/live-output.js');
const project = resolve(__dirname, '../..');
// Existing dashboard tests evaluate browser modules in a VM. Here only imports
// are supplied by fixtures; handlers and the SSE serializer are the real source.
const source = readFileSync(filename, 'utf8')
  .replace(/^import .*;\r?$/gm, '')
  .replaceAll('import.meta.url', JSON.stringify(pathToFileURL(filename).href))
  .replace('export default function liveOutput', 'function liveOutput');

function harness(entries = []) {
  const servers = [], timers = new Map(), changes = new Set(), lifecycle = new Set();
  let config = { sessions: entries };
  const headers = new Map();
  const rootManager = { id: ROOT, file: resolve(project, 'sessions/root.jsonl'),
    getSessionId() { return this.id; }, getSessionFile() { return this.file; } };
  headers.set(rootManager.file, { type: 'session', id: ROOT, cwd: project });
  const refs = new Map([['main', { id: 'main', kind: 'main', session: { sessionManager: rootManager } }]]);
  const registry = { get: id => refs.get(id), list: () => [...refs.values()], isRunning: () => true,
    onChange(callback) { changes.add(callback); return () => changes.delete(callback); } };
  const errors = [];
  const context = createContext({ Buffer, URL, resolve, fileURLToPath, randomUUID, MAIN_AGENT_ID: 'main',
    AgentRegistry: { global: () => registry }, process: { pid: 123 },
    console: { error: value => errors.push(value) },
    openSync: file => { if (!headers.has(file)) throw new Error('unknown journal'); return file; },
    readSync: (file, buffer) => buffer.write(JSON.stringify(headers.get(file)) + '\n'),
    closeSync() {},
    readFileSync: () => JSON.stringify(config),
    setInterval(callback) { const timer = {}; timers.set(timer, callback); return timer; },
    clearInterval(timer) { timers.delete(timer); },
    createServer(handler) {
      const server = new EventEmitter();
      server.handler = handler;
      server.listen = (port, host) => { server.port = port; server.host = host; };
      server.close = () => { server.closed = true; };
      servers.push(server);
      return server;
    },
  });
  const load = () => runInContext(`(function () { ${source}\nreturn liveOutput; })()`, context);
  function binding(factory, kind = 'main', id = 'main', manager = rootManager) {
    const handlers = new Map();
    const ctx = { agent: { id, kind, name: kind }, sessionManager: manager,
      model: { id: 'gpt-6.1-sol' }, cwd: project,
      setInterval(callback) { const timer = {}; timers.set(timer, callback); return timer; },
      clearTimer(timer) { timers.delete(timer); } };
    factory({ on: (name, callback) => handlers.set(name, callback),
      events: { on(name, callback) {
        assert.equal(name, 'task:subagent:lifecycle');
        lifecycle.add(callback); return () => lifecycle.delete(callback);
      } } });
    return { ctx, emit(name, event = {}) { handlers.get(name)?.(event, ctx); }, handlers };
  }
  function connect(server = servers.at(-1)) {
    const response = new EventEmitter();
    response.writableLength = 0;
    response.frames = [];
    response.writeHead = status => { response.status = status; };
    response.flushHeaders = () => {};
    response.write = value => { response.frames.push(value); };
    response.end = () => { response.ended = true; response.emit('close'); };
    response.destroy = response.end;
    server.handler({ method: 'GET', url: '/events', headers: { host: `127.0.0.1:${server.port}` } }, response);
    return response;
  }
  function decoded(response, type) {
    return response.frames.flatMap(value => value.split('\n\n')).filter(value => value.includes(`event: ${type}\n`))
      .map(value => JSON.parse(value.split('\ndata: ')[1]));
  }
  return { servers, timers, changes, lifecycle, rootManager, headers, refs, errors, load, binding, connect, decoded,
    configure(entries) { config = { sessions: entries }; },
    tick() { for (const callback of [...timers.values()]) callback(); } };
}

const entry = (id = ROOT, observerPort = 18766) => ({ id, label: 'Independent Sol', observerPort });
const update = (text = 'immediate', type = 'text_delta') => ({
  message: { role: 'assistant', timestamp: 1791936000000, content: [{ type: 'text', text }] },
  assistantMessageEvent: { type, contentIndex: 0, delta: text },
});

test('default listener preserves child-only eligibility and immediate native updates', () => {
  const h = harness();
  const factory = h.load(), main = h.binding(factory);
  main.emit('session_start');
  assert.equal(h.servers[0].port, 8766);
  const response = h.connect();
  main.emit('message_update', update('not opted in'));
  assert.equal(h.decoded(response, 'text').length, 0);
  const manager = { getSessionId: () => CHILD,
    getSessionFile: () => resolve(project, 'sessions/root/child.jsonl') };
  h.refs.set('child', { id: 'child', kind: 'sub', status: 'running', session: { sessionManager: manager } });
  const child = h.binding(factory, 'sub', 'child', manager);
  child.emit('session_start');
  child.emit('message_update', update());
  assert.equal(h.decoded(response, 'text').at(-1).text, 'immediate');
  assert.equal(h.decoded(response, 'text').at(-1).complete, false);
  child.emit('session_shutdown');
  main.emit('session_shutdown');
  assert.equal(h.timers.size, 0);
});

test('opted-in root uses configured port and emits native message/tool deltas immediately', () => {
  const h = harness([entry()]), main = h.binding(h.load());
  main.emit('session_start');
  assert.equal(h.servers[0].port, 18766);
  assert.equal(h.servers[0].host, '127.0.0.1');
  const response = h.connect();
  const agent = h.decoded(response, 'snapshot')[0].agents[0];
  assert.equal(agent.id, ROOT);
  assert.equal(agent.name, 'Independent Sol');
  assert.equal(agent.scope, 'independent-root');
  assert.equal(agent.streamSource, 'live-observer');
  main.emit('message_update', update());
  assert.equal(h.decoded(response, 'text').at(-1).text, 'immediate');
  main.emit('tool_execution_update', { toolCallId: 'tool1', toolName: 'read',
    partialResult: { content: [{ type: 'text', text: 'native partial output' }] } });
  assert.equal(h.decoded(response, 'text').at(-1).text, 'native partial output');
  assert.equal(h.decoded(response, 'text').at(-1).complete, false);
  main.emit('tool_execution_end', { toolCallId: 'tool1', toolName: 'read',
    result: { content: [{ type: 'text', text: 'finished' }] } });
  assert.equal(h.decoded(response, 'text').at(-1).complete, true);
  const count = h.decoded(response, 'text').length;
  main.emit('tool_execution_update', { toolCallId: 'tool1', partialResult: 'late' });
  assert.equal(h.decoded(response, 'text').length, count);
  assert.equal([...main.handlers.keys()].some(name => /provider|credential/.test(name)), false);
  main.emit('session_shutdown');
});

test('wrong-project registration and invalid ports fail closed without default binding', () => {
  for (const port of [8765, 8766, 0, 65536, true, '18766']) {
    const h = harness([entry(ROOT, port)]), main = h.binding(h.load());
    main.emit('session_start');
    assert.equal(h.servers.length, 0);
    main.emit('session_shutdown');
  }
  const h = harness([entry()]);
  h.headers.set(h.rootManager.file, { type: 'session', id: ROOT, cwd: resolve(project, '../foreign') });
  const main = h.binding(h.load());
  main.emit('session_start');
  assert.equal(h.servers.length, 0);
  main.emit('session_shutdown');
});

test('root switch closes old feed, never borrows default port, and clears retained items', () => {
  const h = harness([entry(), entry(OTHER, 18767)]), main = h.binding(h.load());
  main.emit('session_start');
  const old = h.connect();
  main.emit('message_update', update('old root output'));
  h.rootManager.id = OTHER;
  h.rootManager.file = resolve(project, 'sessions/other.jsonl');
  h.headers.set(h.rootManager.file, { type: 'session', id: OTHER, cwd: project });
  // No event from the old root may be captured before session_switch arrives.
  main.emit('message_update', update('must not cross roots'));
  main.emit('session_switch');
  assert.equal(old.ended, true);
  assert.equal(h.servers[0].closed, true);
  assert.equal(h.servers[1].port, 18767);
  const current = h.connect();
  assert.deepEqual(h.decoded(current, 'snapshot')[0].items, []);
  assert.equal(h.decoded(current, 'snapshot')[0].rootSessionId, OTHER);
  h.configure([]);
  h.tick();
  assert.equal(current.ended, true);
  assert.equal(h.servers.length, 2);
  main.emit('message_update', update('unregistered root'));
  assert.equal(h.servers.length, 2);
  main.emit('session_shutdown');
});

test('factory/module rebinding is idempotent and releases old listeners and timers', () => {
  const h = harness([entry()]);
  const first = h.binding(h.load());
  first.emit('session_start');
  first.emit('session_start');
  assert.equal(h.servers.length, 1);
  assert.equal(h.changes.size, 1);
  const old = h.connect();
  const second = h.binding(h.load());
  second.emit('session_start');
  assert.equal(old.ended, true);
  assert.equal(h.servers[0].closed, true);
  assert.equal(h.changes.size, 1);
  assert.equal(h.lifecycle.size, 1);
  const current = h.connect();
  first.emit('message_update', update('stale factory'));
  assert.equal(h.decoded(current, 'text').length, 0);
  second.emit('message_update', update('new factory'));
  assert.equal(h.decoded(current, 'text').at(-1).text, 'new factory');
  first.emit('session_shutdown'); // Cannot tear down the new owner's feed.
  assert.notEqual(h.servers[1].closed, true);
  second.emit('session_shutdown');
  second.emit('session_shutdown');
  assert.equal(h.changes.size, 0);
  assert.equal(h.lifecycle.size, 0);
  assert.equal(h.timers.size, 0);
});

test('independent membership and native child output stay within the selected journal ancestry', () => {
  const h = harness([entry()]), factory = h.load(), main = h.binding(factory);
  main.emit('session_start');
  const localManager = { getSessionId: () => CHILD,
    getSessionFile: () => resolve(project, 'sessions/root/local.jsonl') };
  const foreignManager = { getSessionId: () => OTHER,
    getSessionFile: () => resolve(project, 'sessions/foreign/other.jsonl') };
  for (const [id, manager] of [['local', localManager], ['foreign', foreignManager]]) {
    h.refs.set(id, { id, kind: 'sub', status: 'running', session: { sessionManager: manager } });
  }
  for (const callback of h.changes) callback();
  const response = h.connect();
  const members = h.decoded(response, 'snapshot')[0].membership.agents.map(member => member.id);
  assert.deepEqual(members.sort(), [ROOT, CHILD].sort());
  const local = h.binding(factory, 'sub', 'local', localManager);
  const foreign = h.binding(factory, 'sub', 'foreign', foreignManager);
  local.emit('message_update', update('local output'));
  foreign.emit('message_update', update('foreign output'));
  assert.equal(h.decoded(response, 'text').length, 1);
  assert.equal(h.decoded(response, 'text')[0].agentId, CHILD);
  assert.equal(h.decoded(response, 'agent').at(-1).name, 'local');
  local.emit('session_shutdown');
  foreign.emit('session_shutdown');
  main.emit('session_shutdown');
});

test('same-root port configuration changes close old clients before rebinding', () => {
  const h = harness([entry()]), main = h.binding(h.load());
  main.emit('session_start');
  const old = h.connect();
  h.configure([entry(ROOT, 18768)]);
  h.tick();
  assert.equal(old.ended, true);
  assert.equal(h.servers[0].closed, true);
  assert.equal(h.servers[1].port, 18768);
  const response = h.connect();
  main.emit('message_update', {
    message: { role: 'assistant', timestamp: 1791936000001,
      content: [{ type: 'thinking', thinking: 'native reasoning' }] },
    assistantMessageEvent: { type: 'thinking_delta', contentIndex: 0, delta: 'native reasoning' },
  });
  assert.equal(h.decoded(response, 'text').at(-1).text, 'native reasoning');
  assert.equal(h.decoded(response, 'text').at(-1).channel, 'thinking');
  main.emit('session_shutdown');
});

test('deregistered independent process never attempts default port after fresh module evaluation', () => {
  for (const shutdownBeforeReplacement of [false, true]) {
    const h = harness([entry()]), first = h.binding(h.load());
    first.emit('session_start');
    assert.deepEqual(h.servers.map(server => server.port), [18766]);
    const old = h.connect();
    h.configure([]);
    h.tick();
    assert.equal(old.ended, true);
    assert.equal(h.servers[0].closed, true);
    if (shutdownBeforeReplacement) first.emit('session_shutdown');
    const replacement = h.binding(h.load()); // Same process, genuinely fresh module state.
    try {
      replacement.emit('session_start');
      replacement.emit('message_update', update('deregistered main must remain unobserved'));
      assert.equal(h.servers.some(server => server.port === 8766), false,
        `must not borrow default port after deregistration; prior shutdown=${shutdownBeforeReplacement}`);
      assert.deepEqual(h.servers.map(server => server.port), [18766]);
    } finally {
      first.emit('session_shutdown');
      replacement.emit('session_shutdown');
    }
    assert.equal(h.changes.size, 0);
    assert.equal(h.lifecycle.size, 0);
    assert.equal(h.timers.size, 0);
  }
});

test('explicit independent factories never borrow the default port across registration races', () => {
  for (const entries of [[], [entry(OTHER)], [entry(), { id: 'invalid' }],
    [entry(ROOT, 8766)]]) {
    const h = harness(entries), factory = h.load();
    const main = h.binding(pi => factory(pi, { independent: true }));
    main.emit('session_start');
    assert.equal(h.servers.length, 0, 'missing or invalid registration must not bind');
    h.configure([]);
    h.tick();
    main.emit('session_shutdown');
    const replacement = h.binding(h.load());
    replacement.emit('session_start');
    assert.equal(h.servers.length, 0, 'independent classification must survive replacement');
    h.configure([entry()]);
    h.tick();
    assert.deepEqual(h.servers.map(server => server.port), [18766]);
    const response = h.connect();
    replacement.emit('message_update', update('native independent output'));
    assert.equal(h.decoded(response, 'text').at(-1).text, 'native independent output');
    h.configure([entry(OTHER)]);
    h.tick();
    assert.equal(response.ended, true, 'changed root registration must close its old feed');
    assert.equal(h.servers.some(server => server.port === 8766), false);
    replacement.emit('session_shutdown');
  }
});
