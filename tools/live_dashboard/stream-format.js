/* Transcript presentation only. The parent retains the complete, live item in Raw. */
(() => {
  'use strict';

  const own = (value, key) => Object.prototype.hasOwnProperty.call(value, key);
  const object = value => value !== null && typeof value === 'object' && !Array.isArray(value);
  const json = value => JSON.stringify(value, null, 2);
  const remaining = (value, keys) => Object.fromEntries(
    Object.entries(value).filter(([key]) => !keys.includes(key)));
  const hasFields = value => Object.keys(value).length > 0;
  const raster = /^data:image\/(?:png|jpeg|gif|webp|bmp|avif);base64,[A-Za-z0-9+/]+={0,2}$/i;
  const measures = ['status', 'exitCode', 'durationMs', 'wallTimeMs', 'elapsedMs'];
  const argumentFields = ['command', 'script', 'code', 'path', 'patch', 'content'];
  const bookkeeping = ['id', 'agentId', 'at', 'sequence', 'kind', 'source', 'tool',
    'callId', 'role', 'channel', 'complete', 'isError', 'stopReason', 'sender', 'customType',
    'args', 'text', 'blocks', 'details', 'errorMessage', ...measures];

  function parsed(value) {
    if (typeof value !== 'string' || !value.trim()) return value;
    try { return JSON.parse(value); } catch (_) { return value; }
  }

  // Named execution tools and recognizable execution schemas authorize unwrapping.
  function cell(value) {
    return object(value) && typeof value.code === 'string' && own(value, 'output') &&
      measures.some(key => own(value, key));
  }

  function resultCell(value) {
    return object(value) && own(value, 'output') &&
      /^(?:py|python|js|javascript|ts|typescript|bash|sh|shell|powershell|pwsh)$/i.test(value.language) &&
      /^(?:complete|completed|success|succeeded|error|failed)$/i.test(value.status) &&
      own(value, 'exitCode') && (value.exitCode === null || Number.isInteger(value.exitCode)) &&
      typeof value.durationMs === 'number' && Number.isFinite(value.durationMs);
  }

  function describe(input) {
    const item = object(input) ? input : { text: input };
    const tool = String(item.tool || '').split('.').pop();
    const isTool = !!tool || ['tool', 'tool_call', 'tool_result'].includes(item.kind);
    const thinking = item.channel === 'thinking' || item.channel === 'reasoning';
    const title = isTool ? 'Tool · ' + (tool || 'output') : thinking ? 'Thinking' :
      item.role === 'peer' || item.customType === 'irc:incoming' ?
        'Peer' + (item.sender ? ' · ' + item.sender : '') :
      item.role === 'user' ? 'User' : item.kind === 'lifecycle' ? 'Lifecycle' : 'Assistant';
    const parts = [], statuses = [], seen = new Set(), argumentCode = new Set(), argumentDiff = new Set();
    const outputKind = ['read', 'bash', 'eval', 'grep', 'find', 'glob'].includes(tool) ? 'code' : 'prose';
    const signature = value => json(parsed(value));
    const remember = value => seen.add(signature(value));
    const duplicate = value => seen.has(signature(value));

    function executionCells(value) {
      if (!['eval', 'bash'].includes(tool)) return null;
      const recognized = entry => resultCell(entry) || (tool === 'eval' && cell(entry));
      if (recognized(value)) return [value];
      const entries = Array.isArray(value) ? value : object(value) ? value.cells : null;
      return Array.isArray(entries) && entries.length > 0 && entries.every(recognized) ? entries : null;
    }

    function add(key, value, label, kind, deduplicate = false) {
      if (value === undefined || (deduplicate && duplicate(value)) ||
          (kind === 'diff' && argumentDiff.has(value))) return;
      const data = kind ? value : parsed(value);
      if (kind === 'json') {
        parts.push({ key, kind: 'json', title: label, value: data });
      } else if (typeof data === 'string') {
        parts.push({ key, kind: kind || 'prose', title: label, text: data });
      } else {
        parts.push({ key, kind: 'json', title: label, value: data });
      }
      remember(value);
    }

    function metadata(value, prefix = '') {
      if (!object(value)) return;
      if (own(value, 'status') && value.status !== undefined) {
        const status = String(value.status);
        statuses.push(prefix + (/^(?:complete|completed|success|succeeded)$/i.test(status) ? 'complete' : status));
      }
      if (own(value, 'exitCode') && value.exitCode !== undefined) statuses.push(prefix + 'exit ' + String(value.exitCode));
      for (const key of ['durationMs', 'wallTimeMs', 'elapsedMs']) {
        if (own(value, key) && value[key] !== undefined) {
          const duration = value[key];
          const timing = typeof duration === 'number' && Number.isFinite(duration) ?
            (duration < 1000 ? Math.round(duration) + ' ms' :
              Number((duration / 1000).toFixed(2)) + ' s') : String(duration) + ' ms';
          statuses.push(prefix + timing);
          break;
        }
      }
    }

    function output(key, value, label = 'Output', deduplicate = true) {
      const data = parsed(value);
      if (typeof data === 'string' && data.length > 0 && argumentDiff.has(data)) return;
      if (executionCells(data)) {
        executionEnvelope(key, data);
        remember(value);
      } else {
        // Valid JSON is data, including false, zero and null. Partial JSON stays text.
        const diff = typeof data === 'string' &&
          /^(?:\*\*\* Begin Patch|diff --git |@@ |--- [^\n]+\n\+\+\+ )/m.test(data);
        add(key, data, label, typeof data === 'string' && data === value ?
          (diff ? 'diff' : outputKind) : 'json', deduplicate);
      }
    }

    function executionEnvelope(key, value) {
      const cells = executionCells(value);
      cells.forEach((entry, index) => {
        const base = key + ':cell:' + index;
        if (!argumentCode.has(entry.code)) add(base + ':code', entry.code, 'Code', 'code', true);
        output(base + ':output', entry.output);
        metadata(entry, cells.length > 1 ? 'cell ' + (index + 1) + ' ' : '');
        const extra = remaining(entry, ['index', 'code', 'output', 'language', ...measures]);
        if (hasFields(extra)) add(base + ':extra', extra, 'Cell details', undefined, true);
      });
      if (object(value) && Array.isArray(value.cells)) {
        metadata(value);
        const extra = remaining(value, ['cells', 'language', 'languages', ...measures]);
        if (hasFields(extra)) add(key + ':extra', extra, 'Details', undefined, true);
      }
    }

    if (own(item, 'args')) {
      const args = parsed(item.args);
      if (object(args)) {
        const fields = tool === 'edit' ? [...argumentFields, 'input'] : argumentFields;
        for (const name of fields) {
          if (own(args, name)) add('args:' + name, args[name],
            name.charAt(0).toUpperCase() + name.slice(1),
            name === 'patch' || (tool === 'edit' && name === 'input') ? 'diff' : 'code');
        }
        const extra = remaining(args, fields);
        if (hasFields(extra)) add('args:other', extra, 'Arguments');
      } else add('args', args, 'Arguments', typeof args === 'string' ?
        (tool === 'edit' ? 'diff' : 'code') : 'json');
    }
    for (const part of parts) {
      if (part.kind === 'code') argumentCode.add(part.text);
      if (part.kind === 'diff') argumentDiff.add(part.text);
    }
    seen.clear(); // Arguments and output are different roles, even when both are 0 or empty.

    const blocks = Array.isArray(item.blocks) ? item.blocks : [];
    const blockTexts = [];
    blocks.forEach((block, index) => {
      const key = 'block:' + index;
      if (!object(block)) { add(key, block, 'Content'); return; }
      const type = block.type;
      let used = ['type'];
      if (type === 'text' || type === 'thinking' || type === 'reasoning') {
        const field = type === 'thinking' && own(block, 'thinking') ? 'thinking' :
          type === 'reasoning' && own(block, 'reasoning') ? 'reasoning' : 'text';
        if (own(block, field)) {
          const value = block[field];
          const label = type !== 'text' || thinking ? 'Thinking' + (block.summary === true ? ' (summary)' : '') : '';
          if (label) add(key, value, label, 'prose');
          else if (isTool) output(key, value, '', false);
          else add(key, value, '', 'prose');
          if (typeof value === 'string') blockTexts.push(value);
        }
        used.push(field, 'summary');
      } else if (type === 'image') {
        const source = object(block.source) ? block.source : {};
        const mime = block.mimeType || source.media_type;
        const data = own(block, 'data') ? block.data : source.data;
        const url = typeof data === 'string' ? 'data:' + mime + ';base64,' + data :
          typeof block.url === 'string' ? block.url : object(block.image_url) ? block.image_url.url : block.image_url;
        if (typeof url === 'string' && raster.test(url)) {
          parts.push({ key, kind: 'image', title: 'Image', image: url });
          remember(block);
          used.push('data', 'mimeType', 'url', 'image_url');
          if (object(block.source)) {
            const extra = remaining(source, ['type', 'media_type', 'data']);
            if (hasFields(extra)) add(key + ':source', extra, 'Image source');
            used.push('source');
          }
        } else { add(key, block, 'Unsupported image'); return; }
      } else if (['code', 'source', 'diff', 'json'].includes(type)) {
        const field = own(block, 'text') ? 'text' : own(block, type) ? type : own(block, 'value') ? 'value' : 'content';
        if (own(block, field)) add(key, type === 'json' ? parsed(block[field]) : block[field],
          type === 'diff' ? 'Diff' : type === 'json' ? 'Data' : 'Code', type === 'diff' ? 'diff' : type === 'json' ? 'json' : 'code');
        used.push(field);
      } else { add(key, block, String(type || 'Content')); return; }
      const extra = remaining(block, used);
      if (hasFields(extra)) add(key + ':extra', extra, 'Block details');
    });
    // Observer text commonly mirrors all text blocks, rather than just one block.
    if (blockTexts.length) {
      remember(blockTexts.join(''));
      remember(blockTexts.join('\n'));
    }
    if (own(item, 'text') && !duplicate(item.text)) {
      if (isTool) output('text', item.text, blocks.length ? 'Additional output' : '');
      else add('text', item.text, thinking ? 'Thinking' : '', 'prose', true);
    }

    if (own(item, 'details') && !duplicate(item.details)) {
      const details = item.details;
      if (executionCells(details)) {
        executionEnvelope('details', details);
      } else if (isTool && object(details)) {
        metadata(details);
        const omitted = [...measures];
        if (tool === 'edit' && own(details, 'diff')) {
          add('details:diff', details.diff, 'Diff', 'diff', true);
          omitted.push('diff');
        }
        if (own(details, 'displayContent')) {
          const display = details.displayContent;
          const text = object(display) && own(display, 'text') ? display.text : display;
          // Read/grep presentation mirrors differ only in source line decoration.
          const undecorated = value => typeof value === 'string' ? value.split('\n')
            .filter(line => !/^\[(?:.*#[0-9A-F]{4}|Showing lines .*|Some lines .*|.*Use :.*)\]$/i.test(line))
            .map(line => line.replace(/^\s*\*?\d+[:|│]/, '')).join('\n').trim() : null;
          const normal = undecorated(text);
          const mirrored = ['read', 'grep'].includes(tool) && normal !== null && [item.text, ...blockTexts].some(value => {
            const candidate = undecorated(value);
            return candidate !== null && candidate === normal;
          });
          if (!mirrored) output('details:display', text, 'Source');
          if (object(display)) {
            const extra = remaining(display, ['text', 'startLine', 'lineNumbers']);
            if (hasFields(extra)) add('details:display:extra', extra, 'Display details');
          }
          omitted.push('displayContent');
        }
        // These fields describe the shown output; they remain available in full Raw.
        const rawFields = {
          read: ['truncation', 'totalLines', 'fileSize', 'meta'],
          grep: ['scopePath', 'searchPath', 'cwd', 'matchCount', 'fileCount', 'files', 'fileMatches', 'truncated'],
          bash: ['timeoutSeconds'],
          eval: ['language', 'languages']
        };
        const extra = remaining(details, omitted.concat(rawFields[tool] || []));
        if (hasFields(extra)) add('details', extra, 'Details', undefined, true);
      } else add('details', details, 'Details', undefined, true);
    }
    if (own(item, 'errorMessage')) add('error', item.errorMessage, 'Error', 'prose', true);
    const extra = remaining(item, bookkeeping);
    if (hasFields(extra)) add('extra', extra, 'Additional data');
    metadata(item);
    if (item.isError === true) statuses.push('failed');
    if (!own(item, 'status') && typeof item.complete === 'boolean') statuses.push(item.complete ? 'complete' : 'in progress');
    if (own(item, 'stopReason')) statuses.push(String(item.stopReason));
    return { title, status: [...new Set(statuses)].join(' · '), parts };
  }

  window.StreamFormat = { describe };
})();
