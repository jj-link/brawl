/*
 * Classic browser script; stream HTML is never interpreted.
 * StreamContent.create() -> { node: HTMLElement, update(parts): void }.
 * Parts have unique stable keys and kind prose/code/diff/json/image/meta, optional
 * title, and text/value/image payloads. The caller owns scroll anchoring and Raw.
 * JSON is presented as labeled fields and decoded values, with nested objects and
 * arrays expandable in place. Raw remains the caller's unchanged original item.
 */
(function () {
  'use strict';

  const rasterURL = /^data:image\/(?:png|jpeg|gif|webp|bmp|avif);base64,[A-Za-z0-9+/]+={0,2}$/i;
  const text = value => ({ tag: '', text: String(value) });
  const element = (tag, children, className, attrs) => ({ tag, children,
    className: className || '', attrs: attrs || {} });

  function patchText(node, value) {
    const old = node.data;
    if (old === value) return;
    if (value.startsWith(old)) { node.appendData(value.slice(old.length)); return; }
    let start = 0, end = old.length, nextEnd = value.length;
    while (start < end && start < nextEnd && old[start] === value[start]) start++;
    while (end > start && nextEnd > start && old[end - 1] === value[nextEnd - 1]) {
      end--; nextEnd--;
    }
    node.replaceData(start, end - start, value.slice(start, nextEnd));
  }

  function same(a, b) {
    if (a === b) return true;
    if (a.tag !== b.tag) return false;
    if (!a.tag) return a.text === b.text;
    return a.className === b.className &&
      JSON.stringify(a.attrs) === JSON.stringify(b.attrs) &&
      a.children.length === b.children.length && a.children.every((child, i) => same(child, b.children[i]));
  }

  function patch(record, spec) {
    if (record.spec === spec) return record;
    if (record.spec.tag !== spec.tag) {
      const replacement = mount(spec);
      record.node.replaceWith(replacement.node);
      return replacement;
    }
    if (!spec.tag) patchText(record.node, spec.text);
    else {
      if (record.spec.className !== spec.className) record.node.className = spec.className;
      for (const key of Object.keys(record.spec.attrs)) {
        if (!(key in spec.attrs)) record.node.removeAttribute(key);
      }
      for (const [key, value] of Object.entries(spec.attrs)) {
        if (record.spec.attrs[key] !== value) record.node.setAttribute(key, value);
      }
      record.children = reconcile(record.node, record.children, spec.children);
    }
    record.spec = spec;
    return record;
  }

  function mount(spec) {
    const node = spec.tag ? document.createElement(spec.tag) : document.createTextNode(spec.text);
    const record = { node, spec, children: [] };
    if (spec.tag) {
      node.className = spec.className;
      for (const [key, value] of Object.entries(spec.attrs)) node.setAttribute(key, value);
      record.children = reconcile(node, [], spec.children);
    }
    return record;
  }

  // Preserve identical prefixes AND suffixes, including when lines are inserted in the middle.
  // Within the changed range, patch compatible nodes rather than replacing their container.
  function reconcile(parent, old, specs) {
    let first = 0, oldEnd = old.length, newEnd = specs.length;
    while (first < oldEnd && first < newEnd && same(old[first].spec, specs[first])) first++;
    while (oldEnd > first && newEnd > first && same(old[oldEnd - 1].spec, specs[newEnd - 1])) {
      oldEnd--; newEnd--;
    }
    const result = old.slice(0, first);
    const commonEnd = Math.min(oldEnd, newEnd);
    for (let i = first; i < commonEnd; i++) result.push(patch(old[i], specs[i]));
    for (let i = commonEnd; i < oldEnd; i++) old[i].node.remove();
    const before = old[oldEnd] ? old[oldEnd].node : null;
    for (let i = commonEnd; i < newEnd; i++) {
      const record = mount(specs[i]);
      parent.insertBefore(record.node, before);
      result.push(record);
    }
    result.push(...old.slice(oldEnd));
    return result;
  }

  function safeLink(value) {
    if (!value || /[\u0000-\u0020\u007f\\]/.test(value)) return null;
    try {
      const url = new URL(value, document.baseURI);
      return /^(?:https?:|mailto:)$/.test(url.protocol) ? url.href : null;
    } catch (_) { return null; }
  }

  // Deliberately small Markdown vocabulary. HTML, images, unsupported constructs and
  // incomplete delimiters remain ordinary text. No source text is assigned to innerHTML.
  function inline(source, depth) {
    if (depth > 32) return [text(source)];
    const out = [];
    let literal = '', pos = 0;
    const flush = () => { if (literal) { out.push(text(literal)); literal = ''; } };
    while (pos < source.length) {
      const rest = source.slice(pos);
      let match;
      if (rest[0] === '`') {
        const delimiter = /^`+/.exec(rest)[0];
        const end = source.indexOf(delimiter, pos + delimiter.length);
        if (end > pos + delimiter.length && source[end + delimiter.length] !== '`') {
          flush();
          out.push(element('code', [text(source.slice(pos + delimiter.length, end))], 'sc-inline-code'));
          pos = end + delimiter.length;
          continue;
        }
        literal += delimiter; pos += delimiter.length; continue;
      }
      if (rest[0] === '[' && source[pos - 1] !== '!' &&
          (match = /^\[([^\]\n]+)\]\(([^\s()]+)\)/.exec(rest))) {
        const href = safeLink(match[2]);
        if (href) {
          flush();
          out.push(element('a', inline(match[1], depth + 1), '',
            { href, target: '_blank', rel: 'noopener noreferrer', referrerpolicy: 'no-referrer' }));
          pos += match[0].length; continue;
        }
      }
      if ((rest[0] === '*' || rest[0] === '_') &&
          !(rest[0] === '_' && /[\p{L}\p{N}]/u.test(source[pos - 1] || ''))) {
        const delimiter = rest.startsWith(rest[0] + rest[0]) ? rest.slice(0, 2) : rest[0];
        const end = source.indexOf(delimiter, pos + delimiter.length);
        const body = end < 0 ? '' : source.slice(pos + delimiter.length, end);
        if (body && !/^\s|\s$/.test(body) && !body.includes('\n') &&
            source[end + delimiter.length] !== delimiter[0]) {
          flush();
          out.push(element(delimiter.length === 2 ? 'strong' : 'em', inline(body, depth + 1)));
          pos = end + delimiter.length; continue;
        }
        literal += delimiter; pos += delimiter.length; continue;
      }
      literal += source[pos++];
    }
    flush();
    return out;
  }

  function structured(value, nested = false) {
    if (value === null || typeof value !== 'object') {
      const kind = value === null ? 'null' : typeof value;
      const display = typeof value === 'string' ? (value === '' ? '""' : value) : String(value);
      return element('span', [text(display)], 'sc-value sc-json-' + kind);
    }
    const array = Array.isArray(value);
    const entries = Object.entries(value);
    if (!entries.length) return element('span', [text(array ? '[]' : '{}')], 'sc-value');
    const body = array ?
      element('ol', entries.map(([, entry]) => element('li', [structured(entry, true)])), 'sc-items') :
      element('dl', entries.map(([key, entry]) => element('div', [
        element('dt', [text(key)], 'sc-json-key'),
        element('dd', [structured(entry, true)])
      ], 'sc-field')), 'sc-fields');
    if (!nested) return body;
    const count = entries.length;
    const label = count + (array ? (count === 1 ? ' item' : ' items') : (count === 1 ? ' field' : ' fields'));
    // No open attribute: user expansion survives incremental updates to this node.
    return element('details', [element('summary', [text(label)]), body], 'sc-structure');
  }

  function lineView(source, kind, previous) {
    const cache = new Map(), lines = source.split('\n');
    const children = lines.map((line, index) => {
      const raw = line + (index < lines.length - 1 ? '\n' : '');
      let spec = previous && previous.get(raw);
      if (!spec) {
        const diff = kind !== 'diff' ? '' : line.startsWith('@@') ? ' sc-diff-hunk' :
          /^(?:diff |index |--- |\+\+\+ )/.test(line) ? ' sc-diff-header' :
          line.startsWith('+') ? ' sc-diff-add' : line.startsWith('-') ? ' sc-diff-remove' : '';
        spec = element('span', [text(raw)], 'sc-line' + diff);
      }
      cache.set(raw, spec);
      return spec;
    });
    return { spec: element('pre', children, 'sc-code sc-' + kind), cache };
  }

  function marker(line) {
    if (/^ {0,3}(?:`{3,}|~{3,})/.test(line)) return 'fence';
    if (/^ {0,3}#{1,6} +\S/.test(line)) return 'heading';
    if (/^ {0,3}> ?/.test(line)) return 'quote';
    if (/^ {0,3}[-+*] +\S/.test(line)) return 'ul';
    if (/^ {0,3}\d+[.)] +\S/.test(line)) return 'ol';
    return line.trim() ? 'p' : 'blank';
  }

  function blockView(block, previous) {
    if (previous && previous.raw === block.raw && previous.kind === block.kind) {
      return { ...block, spec: previous.spec, cache: previous.cache };
    }
    if (previous && previous.kind !== block.kind) previous = null;
    const cache = new Map();
    function proseLine(source) {
      let spec = previous && previous.cache && previous.cache.get(source);
      if (!spec) spec = element('span', inline(source, 0), 'sc-prose-line');
      cache.set(source, spec);
      return spec;
    }
    let spec;
    const lines = block.raw.split('\n');
    // Block ranges include their terminating newline; it separates blocks, not an empty item.
    if (lines[lines.length - 1] === '') lines.pop();
    if (block.kind === 'code') {
      const view = lineView(block.code, 'code', previous && previous.cache);
      spec = view.spec;
      return { ...block, spec, cache: view.cache };
    }
    if (block.kind === 'heading') {
      const match = /^ {0,3}(#{1,6}) +(.*?)(?: +#+ *)?$/.exec(lines[0]);
      spec = element('h' + match[1].length, [proseLine(match[2])]);
    } else if (block.kind === 'ul' || block.kind === 'ol') {
      const ordered = block.kind === 'ol';
      const attrs = ordered ? { start: /^ {0,3}(\d+)/.exec(lines[0])[1] } : {};
      spec = element(block.kind, lines.map(line => element('li',
        [proseLine(line.replace(/^ {0,3}(?:[-+*]|\d+[.)]) +/, ''))])), '', attrs);
    } else if (block.kind === 'quote') {
      spec = element('blockquote', [element('p', lines.map((line, i) =>
        proseLine(line.replace(/^ {0,3}> ?/, '') + (i < lines.length - 1 ? '\n' : ''))))]);
    } else {
      spec = element('p', lines.map((line, i) =>
        block.kind === 'literal' ? text(line + (i < lines.length - 1 ? '\n' : '')) :
          proseLine(line + (i < lines.length - 1 ? '\n' : ''))), block.kind === 'literal' ? 'sc-literal' : '');
    }
    return { ...block, spec, cache };
  }

  function markdown(source, oldSource, previous) {
    // Appends revisit only the final (possibly incomplete) block, never the completed prefix.
    const append = source.startsWith(oldSource);
    const blocks = append ? previous.slice(0, -1) : [];
    const priorByRaw = append ? null : new Map(previous.map(block => [block.raw, block]));
    const start = blocks.length ? blocks[blocks.length - 1].end : 0;
    const lines = source.slice(start).match(/[^\n]*\n|[^\n]+$/g) || [];
    let i = 0, offset = start;
    while (i < lines.length) {
      const begin = i, blockStart = offset;
      const first = lines[i].replace(/\n$/, '');
      let kind = marker(first), code;
      if (kind === 'fence') {
        const open = /^ {0,3}(`{3,}|~{3,})([^\n]*)$/.exec(first);
        const delimiter = open[1][0], size = open[1].length;
        const closing = new RegExp('^ {0,3}' + delimiter + '{' + size + ',} *\\n?$');
        let end = i + 1;
        while (end < lines.length && !closing.test(lines[end])) end++;
        if (end < lines.length && !(delimiter === '`' && open[2].includes('`'))) {
          kind = 'code'; code = lines.slice(i + 1, end).join(''); i = end + 1;
        } else { kind = 'literal'; i = lines.length; }
      } else if (kind === 'heading') i++;
      else {
        i++;
        while (i < lines.length && marker(lines[i].replace(/\n$/, '')) === kind) i++;
      }
      const raw = lines.slice(begin, i).join('');
      offset += raw.length;
      const block = { kind, raw, start: blockStart, end: offset, code };
      const prior = priorByRaw?.get(raw) || previous[blocks.length];
      blocks.push(kind === 'blank' ? { ...block, spec: null } : blockView(block, prior));
    }
    return blocks;
  }

  function contentText(part) {
    if (part.kind !== 'json') return String(part.text ?? '');
    if (Object.prototype.hasOwnProperty.call(part, 'value')) return JSON.stringify(part.value, null, 2) ?? '';
    const source = String(part.text ?? '');
    try { return JSON.stringify(JSON.parse(source), null, 2); }
    catch (_) { return source; }
  }

  function makePart() {
    const node = document.createElement('section');
    node.className = 'sc-part';
    const title = document.createElement('div');
    title.className = 'sc-part-title';
    const titleText = document.createTextNode('');
    title.append(titleText);
    const body = document.createElement('div');
    body.className = 'sc-part-body';
    node.append(title, body);
    return { node, title, titleText, body, records: [], blocks: [], source: '', kind: null, cache: null };
  }

  function updatePart(record, part) {
    const title = String(part.title ?? '');
    patchText(record.titleText, title);
    record.title.hidden = !title;
    const kind = part.kind || 'prose';
    const source = kind === 'image' ? String(part.image ?? '') : contentText(part).replace(/\r\n/g, '\n');
    if (record.kind === kind && record.source === source) {
      if (kind === 'image' && record.records[0]?.node.tagName === 'IMG') {
        const alt = title || 'Session output image';
        const image = record.records[0];
        if (image.node.alt !== alt) {
          image.node.alt = alt;
          image.spec = { ...image.spec, attrs: { ...image.spec.attrs, alt } };
        }
      }
      return;
    }
    if (record.kind !== kind) { record.blocks = []; record.cache = null; }
    let specs;
    if (kind === 'image') {
      specs = rasterURL.test(source) ? [element('img', [], 'sc-image',
        { src: source, alt: title || 'Session output image', decoding: 'async', width: '180', height: '180' })] :
        [element('p', [text(source ? 'Unsupported image source: ' + source : 'Image data unavailable.')], 'sc-meta')];
    } else if (kind === 'prose') {
      record.blocks = markdown(source, record.kind === kind ? record.source : '', record.blocks);
      specs = record.blocks.filter(block => block.spec).map(block => block.spec);
    } else if (kind === 'json') {
      try { specs = [structured(JSON.parse(source))]; }
      catch (_) { specs = [lineView(source, 'code', record.cache).spec]; }
    } else if (kind === 'code' || kind === 'diff') {
      const view = lineView(source, kind, record.cache);
      record.cache = view.cache;
      specs = [view.spec];
    } else {
      specs = [element('div', [text(source)], 'sc-meta')];
    }
    record.records = reconcile(record.body, record.records, specs);
    record.source = source;
    record.kind = kind;
  }

  function create() {
    const node = document.createElement('div');
    node.className = 'stream-content';
    const parts = new Map();
    return {
      node,
      update(specs) {
        const keys = new Set(specs.map(part => part.key));
        for (const [key, record] of parts) {
          if (!keys.has(key)) { record.node.remove(); parts.delete(key); }
        }
        let cursor = node.firstChild;
        for (const part of specs) {
          let record = parts.get(part.key);
          if (!record) { record = makePart(); parts.set(part.key, record); }
          updatePart(record, part);
          if (record.node === cursor) cursor = cursor.nextSibling;
          else node.insertBefore(record.node, cursor);
        }
      }
    };
  }

  window.StreamContent = Object.freeze({ create });
}());
