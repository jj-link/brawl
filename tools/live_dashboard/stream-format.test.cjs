'use strict';

const assert = require('node:assert/strict');
const { test } = require('node:test');
const { readFileSync } = require('node:fs');
const { join } = require('node:path');
const { runInNewContext } = require('node:vm');
const context = { window: {} };
runInNewContext(readFileSync(join(__dirname, 'stream-format.js'), 'utf8'), context);
const describe = item => JSON.parse(JSON.stringify(context.window.StreamFormat.describe(item)));

// These assertions protect displayed content, not the transport's bookkeeping layout.
test('domain JSON containing output is not mistaken for a tool envelope', () => {
  const data = { output: 'domain value', ready: false, accepted: 0, error: null };
  const view = describe({ kind: 'tool', tool: 'eval', text: JSON.stringify(data) });
  assert.deepEqual(view.parts.find(part => part.kind === 'json').value, data);
});

test('false, zero, null and empty output survive independently of arguments', () => {
  for (const value of [false, 0, null, '']) {
    const view = describe({ kind: 'tool', tool: 'custom', args: value, text: value });
    const argumentsPart = view.parts.find(part => part.key === 'args');
    const outputPart = view.parts.find(part => part.key === 'text');
    assert.deepEqual(argumentsPart.value ?? argumentsPart.text ?? null, value);
    assert.deepEqual(outputPart.value ?? outputPart.text ?? null, value);
  }
});

test('eval cells expose output once while preserving distinct cell data and honest status', () => {
  const item = {
    kind: 'tool', tool: 'eval', args: { language: 'py', code: 'print("first\\nsecond")' },
    text: 'first\nsecond', blocks: [{ type: 'text', text: 'first\nsecond' }],
    details: { cells: [{ code: 'print("first\\nsecond")', output: 'first\nsecond',
      status: 'complete', exitCode: 0, durationMs: 220, receipt: 'unique receipt' }] },
    complete: true
  };
  const before = JSON.stringify(item);
  const view = describe(item);
  assert.equal(view.parts.filter(part => part.text === 'first\nsecond').length, 1);
  assert.equal(view.parts.filter(part => part.text === item.args.code).length, 1);
  assert.ok(view.parts.some(part => part.value?.receipt === 'unique receipt'));
  assert.match(view.status, /exit 0/);
  assert.match(view.status, /220/);
  assert.equal(JSON.stringify(item), before);
});


test('recognized execution records render decoded lines rather than a JSON wrapper', () => {
  const record = { language: 'python', output: 'line one\nline two', status: 'complete', exitCode: 0, durationMs: 1250 };
  const view = describe({ kind: 'tool', tool: 'eval', text: JSON.stringify([record]) });
  assert.ok(view.parts.some(part => part.kind === 'code' && part.text === record.output));
  assert.equal(view.parts.some(part => Array.isArray(part.value)), false);
  assert.match(view.status, /exit 0/);
});
test('edit input and returned diffs are shown as diffs rather than escaped JSON', () => {
  const input = '*** Begin Patch\n*** Update File: a.cpp\n@@\n-old\n+new\n*** End Patch';
  const diff = '--- a/a.cpp\n+++ b/a.cpp\n@@ -1 +1 @@\n-old\n+new';
  const view = describe({ kind: 'tool', tool: 'edit', args: { input }, details: { diff } });
  assert.ok(view.parts.some(part => part.kind === 'diff' && part.text === input));
  assert.ok(view.parts.some(part => part.kind === 'diff' && part.text === diff));
});

test('thinking, errors and unknown block content remain visible', () => {
  const view = describe({ channel: 'thinking', blocks: [
    { type: 'thinking', thinking: 'Check the branch target', summary: true },
    { type: 'custom', content: { proof: 'unknown block retained' } }
  ], errorMessage: 'Connection failed' });
  assert.ok(view.parts.some(part => part.text === 'Check the branch target' && /Thinking/.test(part.title)));
  assert.ok(view.parts.some(part => part.value?.content?.proof === 'unknown block retained'));
  assert.ok(view.parts.some(part => part.text === 'Connection failed'));
});

test('partial structured output remains readable and unsupported images remain data', () => {
  const partial = '{"accepted":';
  const view = describe({ kind: 'tool', tool: 'read', text: partial,
    blocks: [{ type: 'image', url: 'https://example.invalid/tracking.png' }] });
  assert.ok(view.parts.some(part => part.text === partial));
  assert.ok(view.parts.some(part => part.kind === 'json' && part.value?.url === 'https://example.invalid/tracking.png'));
  assert.equal(view.parts.some(part => part.kind === 'image'), false);
});
