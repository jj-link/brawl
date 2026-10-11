/* Brawl Decomp — Live Dashboard
 * Standalone frontend. No frameworks, no build step, no external assets.
 * GET /api/state and /api/units preserve project progress; /api/events carries
 * state snapshots, /api/live relays real runner text, /api/streams is opt-in history.
 * All dynamic content is rendered via textContent — agent names, paths and event text are never trusted as HTML.
 */
'use strict';

(function () {
  // ------------------------------------------------------------------ helpers

  const $ = (id) => document.getElementById(id);

  function el(tag, opts, ...children) {
    const node = document.createElement(tag);
    const o = opts || {};
    if (o.class) node.className = o.class;
    if (o.id) node.id = o.id;
    if (o.type) node.type = String(o.type);
    if (o.hidden) node.hidden = true;
    if (o.attrs) {
      for (const [k, v] of Object.entries(o.attrs)) {
        if (v == null) continue;
        node.setAttribute(k, String(v));
      }
    }
    if (o.text != null) node.textContent = String(o.text);
    for (const c of children.flat(Infinity)) {
      if (c == null) continue;
      node.append(c.nodeType ? c : document.createTextNode(String(c)));
    }
    return node;
  }

  function setText(id, v) {
    const n = $(id);
    if (n) n.textContent = v;
  }

  function fmtBytes(n) {
    if (n == null || !isFinite(n)) return '—';
    const neg = n < 0;
    let v = Math.abs(n);
    const u = ['B', 'KB', 'MB', 'GB', 'TB'];
    let i = 0;
    while (v >= 1024 && i < u.length - 1) { v /= 1024; i++; }
    const s = i === 0 ? String(Math.round(v)) : v >= 100 ? v.toFixed(0) : v >= 10 ? v.toFixed(1) : v.toFixed(2);
    return (neg ? '-' : '') + s + ' ' + u[i];
  }

  function fmtAge(sec) {
    if (sec == null || !isFinite(sec)) return '—';
    sec = Math.max(0, Math.floor(sec));
    if (sec < 5) return 'now';
    if (sec < 60) return sec + 's';
    const m = Math.floor(sec / 60);
    if (m < 60) return m + 'm';
    const h = Math.floor(m / 60);
    if (h < 24) return h + 'h';
    return Math.floor(h / 24) + 'd';
  }

  function relShort(iso) {
    if (!iso) return '';
    const t = Date.parse(iso);
    if (!isFinite(t)) return '';
    return fmtAge((Date.now() - t) / 1000);
  }

  function tsOf(iso) {
    const t = iso ? Date.parse(iso) : NaN;
    return isFinite(t) ? t : 0;
  }

  function trunc(s, n) {
    s = String(s);
    return s.length > n ? s.slice(0, n - 1) + '…' : s;
  }

  function hash01(s) {
    let h = 2166136261;
    for (let i = 0; i < s.length; i++) { h ^= s.charCodeAt(i); h = Math.imul(h, 16777619); }
    return ((h >>> 0) % 1000) / 1000;
  }

  const easeOut = (k) => 1 - Math.pow(1 - k, 3);

  const MONO = 'ui-monospace, Menlo, Consolas, monospace';
  const SANS = '-apple-system, "Segoe UI", system-ui, Roboto, Arial, sans-serif';

  // live-updating relative-time labels
  const timeEls = new Map(); // element -> {iso, prefix}
  function registerTime(node, iso, prefix) {
    timeEls.set(node, { iso: iso || null, prefix: prefix || '' });
    node.textContent = (prefix || '') + (iso ? relShort(iso) : '—');
  }

  // surface swallowed renderer errors (throttled) instead of dying silently
  let lastErrSig = '', lastErrAt = 0;
  function logErr(context, e) {
    const msg = (e && e.message) || String(e);
    const sig = context + ':' + msg;
    const now = Date.now();
    if (sig !== lastErrSig || now - lastErrAt > 30000) {
      lastErrSig = sig; lastErrAt = now;
      console.error('[dashboard] ' + context + ': ' + msg, e instanceof Error ? (e.stack || e) : e);
    }
  }

  // run an independent UI section: a failure logs and skips, never cascades
  function safe(context, fn) {
    try { fn(); } catch (e) { logErr(context, e); }
  }

  // ------------------------------------------------------------------ store

  const S = {
    state: null,
    pendingState: null,
    pendingUnits: null,
    lastStateAt: 0,
    everConnected: false,
    sseOpen: false,
    paused: false,
    motion: true,
    agents: [],
    units: [],
    unitsRevision: null,
    unitsById: new Map(),
    acceptedSnapshot: new Map(),
  };
  let unitCardOpen = null;

  const STATE_STALE_S = 30;

  // ------------------------------------------------------------------ network

  async function fetchJSON(url) {
    const r = await fetch(url, { cache: 'no-store' });
    if (!r.ok) throw new Error('HTTP ' + r.status);
    return r.json();
  }

  async function refreshState() {
    try {
      const s = await fetchJSON('/api/state');
      S.everConnected = true;
      ingest(s);
    } catch (e) {
      logErr('state refresh', e);
      if (!S.everConnected) setTimeout(refreshState, 5000); // keep retrying boot until server appears
    }
    tickStatus();
  }

  let unitsBusy = false;
  let unitsDirty = false;
  let unitsRetryTimer = null;

  async function refreshUnits() {
    if (unitsBusy) { unitsDirty = true; return; }
    unitsBusy = true;
    try {
      const j = await fetchJSON('/api/units');
      if (S.paused) { S.pendingUnits = j; }
      else applyUnits(j);
    } catch (e) {
      logErr('units refresh', e);
      const want = S.state && S.state.unitsRevision;
      if (want && want !== S.unitsRevision && !unitsRetryTimer) {
        unitsRetryTimer = setTimeout(() => { unitsRetryTimer = null; refreshUnits(); }, 8000);
      }
    } finally {
      unitsBusy = false;
      if (unitsDirty) { unitsDirty = false; refreshUnits(); }
    }
  }

  function connectSSE() {
    if (typeof EventSource === 'undefined') return; // fallback polling covers us
    let es;
    try { es = new EventSource('/api/events'); } catch (e) { return; }
    es.addEventListener('open', () => {
      S.sseOpen = true;
      tickStatus();
      refreshState();          // reconnect => refetch to close any gap
      if (!S.paused) refreshUnits();
    });
    es.addEventListener('state', (ev) => {
      S.sseOpen = true;
      try { ingest(JSON.parse(ev.data)); } catch (e) { logErr('sse state frame', e); }
    });
    es.addEventListener('error', () => {
      S.sseOpen = false;
      tickStatus(); // displayed data is retained; status flips to reconnecting/stale
    });
  }

  function ingest(s) {
    if (!s || typeof s !== 'object') return;
    if (S.paused) { S.pendingState = s; tickStatus(); return; }
    applyState(s);
  }

  function applyState(s) {
    S.state = s;
    S.lastStateAt = Date.now();
    S.agents = Array.isArray(s.agents) ? s.agents : [];
    safe('renderHeader', () => renderHeader());
    safe('renderHero', () => renderHero());
    safe('renderStreams', () => Streams.update());
    safe('renderProvenance', () => renderProvenance());
    safe('renderWarnings', () => renderWarnings(s));
    safe('sparkline', () => Sparkline.update(s));
    if (s.unitsRevision && s.unitsRevision !== S.unitsRevision) refreshUnits();
    tickStatus();
  }

  function applyUnits(j) {
    if (!j || !Array.isArray(j.units)) return;
    const prev = S.acceptedSnapshot;
    const next = new Map();
    const newly = [];
    for (const u of j.units) {
      const id = String(u.id);
      const acc = !!u.accepted;
      next.set(id, acc);
      if (acc && prev.get(id) === false) newly.push(id);
    }
    const firstLoad = prev.size === 0;
    S.units = j.units;
    S.unitsRevision = String(j.revision ?? '');
    S.unitsById = new Map(j.units.map((u) => [String(u.id), u]));
    S.acceptedSnapshot = next;
    safe('treemap', () => Treemap.setData(j.units));
    safe('unitCardRefresh', () => {
      if (unitCardOpen) {
        const nu = S.unitsById.get(String(unitCardOpen.id));
        if (nu) openUnitCard(nu); else closeUnitCard();
      }
    });
    updateUnitsCounter();
    safe('renderProvenance', () => renderProvenance());
    if (!firstLoad && newly.length) {
      safe('pulse', () => { Treemap.pulse(newly); RecentStrip.show(newly); });
    }
  }

  // ------------------------------------------------------------------ status / header

  function renderHeader() {
    const s = S.state || {};
    const sess = s.session;
    const pill = $('pill-session');
    if (sess) {
      pill.hidden = false;
      const t = String(sess);
      pill.textContent = t.length > 30 ? t.slice(0, 12) + '…' + t.slice(-10) : t;
      pill.title = 'session: ' + t;
    }
    setText('foot-meta', s.updatedAt ? 'server state: ' + new Date(s.updatedAt).toLocaleString() : '');
  }

  function tickStatus() {
    const now = Date.now();
    const ageS = S.lastStateAt ? Math.floor((now - S.lastStateAt) / 1000) : null;

    const conn = $('pill-conn');
    let cls, txt;
    if (S.paused) { cls = 'is-warn'; txt = 'paused'; }
    else if (S.sseOpen && (ageS == null || ageS <= 15)) { cls = 'is-live'; txt = 'live'; }
    else if (S.sseOpen) { cls = 'is-warn'; txt = 'lagging · ' + fmtAge(ageS); }
    else if (ageS == null) { cls = 'is-down'; txt = 'connecting…'; }
    else { cls = 'is-down'; txt = 'stale · ' + fmtAge(ageS) + ' old'; }
    conn.className = 'pill ' + cls;
    setText('conn-text', txt);

    const rep = $('pill-report');
    const rAt = S.state && S.state.reportUpdatedAt ? Date.parse(S.state.reportUpdatedAt) : NaN;
    if (isFinite(rAt)) {
      const a = Math.max(0, Math.floor((now - rAt) / 1000));
      setText('report-age', fmtAge(a));
      rep.classList.toggle('is-old', a > 30 * 60);
      rep.title = 'Unit-map build report updated ' + new Date(rAt).toLocaleString() + '; accepted totals use ' +
        ((S.state && S.state.progress && S.state.progress.source) || 'report') + '.';
    } else {
      setText('report-age', 'age unknown');
      rep.classList.add('is-old');
      rep.title = 'report timestamp unavailable';
    }

    setText('sync-age', ageS == null ? '—' : fmtAge(ageS) + ' ago');
    $('pill-sync').title = 'last successful sync: ' + (S.lastStateAt ? new Date(S.lastStateAt).toLocaleString() : 'never');

    const stale = ageS != null && (ageS > STATE_STALE_S || !S.sseOpen);
    document.body.classList.toggle('is-stale', stale);
    document.body.classList.toggle('is-paused', S.paused);
    $('treemap-wrap').dataset.flag = stale && S.paused ? 'stale · paused' : stale ? 'stale data' : S.paused ? 'paused' : '';

    for (const [node, rec] of timeEls) {
      if (!node.isConnected) { timeEls.delete(node); continue; }
      node.textContent = rec.prefix + (rec.iso ? relShort(rec.iso) : '—');
    }
    RecentStrip.tick();
  }

  // ------------------------------------------------------------------ hero

  function countTo(node, target, fmt) {
    const prev = typeof node.__v === 'number' ? node.__v : null;
    node.__v = target;
    if (prev === null || !S.motion || S.paused || prev === target) {
      if (node.__raf) cancelAnimationFrame(node.__raf);
      node.textContent = fmt(target);
      return;
    }
    if (node.__raf) cancelAnimationFrame(node.__raf);
    const t0 = performance.now();
    const dur = 650;
    const step = (t) => {
      const k = Math.min(1, (t - t0) / dur);
      node.textContent = fmt(prev + (target - prev) * easeOut(k));
      node.__raf = k < 1 ? requestAnimationFrame(step) : 0;
    };
    node.__raf = requestAnimationFrame(step);
  }

  function renderHero() {
    const p = (S.state && S.state.progress) || {};
    const note = $('hero-note');
    if (!p.available) {
      for (const id of ['big-pct', 'c-accepted', 'c-total', 'c-remaining']) setText(id, '—');
      $('meter-fill').style.width = '0%';
      $('meter').setAttribute('aria-valuenow', '0');
      setText('hero-total-label', '—');
      note.hidden = false;
      note.textContent = 'progress unavailable' + (p.error ? ': ' + p.error : '');
      updateUnitsCounter();
      return;
    }
    note.hidden = true;
    countTo($('big-pct'), Number(p.percent) || 0, (v) => v.toFixed(p.precision === 6 ? 6 : 3));
    countTo($('c-accepted'), Number(p.acceptedBytes) || 0, fmtBytes);
    countTo($('c-total'), Number(p.totalBytes) || 0, fmtBytes);
    countTo($('c-remaining'), Number(p.remainingBytes) || 0, fmtBytes);
    setText('hero-total-label', fmtBytes(Number(p.totalBytes) || 0));
    for (const [id, value] of [['c-accepted', p.acceptedBytes], ['c-total', p.totalBytes], ['c-remaining', p.remainingBytes]]) {
      $(id).title = Number(value).toLocaleString() + ' bytes';
    }
    const pct = Math.max(0, Math.min(100, Number(p.percent) || 0));
    $('meter-fill').style.width = pct.toFixed(2) + '%';
    $('meter').setAttribute('aria-valuenow', pct.toFixed(1));
    updateUnitsCounter();
  }

  function updateUnitsCounter() {
    const p = S.state && S.state.progress;
    if (!p || !p.available) { setText('c-units', '—'); return; }
    const acc = p.acceptedUnits != null ? p.acceptedUnits : '—';
    const tot = p.source !== 'changelog' && S.units.length ? S.units.length : null;
    setText('c-units', String(acc) + (tot != null ? ' / ' + tot : ' accepted'));
  }

  function renderProvenance() {
    const s = S.state || {};
    const p = s.progress || {};
    const host = $('progress-provenance');
    if (!p.available) { host.replaceChildren(); return; }
    const source = p.source === 'changelog' ? 'Accepted checkpoint · CHANGELOG.md' : 'Build report progress';
    const at = p.updatedAt ? new Date(p.updatedAt).toLocaleString() : 'timestamp unknown';
    const exact = Number(p.acceptedBytes).toLocaleString() + ' / ' + Number(p.totalBytes).toLocaleString() +
      ' bytes · ' + Number(p.percent).toFixed(p.precision === 6 ? 6 : 3) + '% · ' +
      Number(p.remainingBytes).toLocaleString() + ' bytes remaining';
    host.replaceChildren(
      el('strong', { text: source }),
      document.createTextNode(' · ' + at + (p.lastGood ? ' · last good checkpoint (see warnings)' : '')),
      el('span', { class: 'checkpoint', text: exact }),
      el('span', { class: 'checkpoint', text: [p.checkpointTitle, p.commit ? 'commit ' + p.commit : null].filter(Boolean).join(' · ') })
    );
    const u = s.unitsProvenance || {};
    const reportAt = u.updatedAt || s.reportUpdatedAt;
    const text = 'Unit map · ' + (u.source || 'build report') + ' · ' +
      (reportAt ? new Date(reportAt).toLocaleString() : 'timestamp unknown') +
      (u.acceptedUnits != null ? ' · ' + u.acceptedUnits + ' report-accepted units' : '') +
      (u.acceptedBytes != null ? ' · ' + Number(u.acceptedBytes).toLocaleString() + ' report-accepted bytes' : '') +
      (u.reason ? ' · ' + u.reason : '') +
      (p.source === 'changelog' ? ' · Map is report-backed, not a per-unit view of the changelog checkpoint.' : '');
    setText('map-provenance', text);
    $('map-provenance').classList.toggle('is-old', !!u.stale);
    $('pill-report').title = 'Unit-map report only; accepted totals use ' + (p.source || 'report') + '. ' + (reportAt || 'Timestamp unknown');
  }

  // ------------------------------------------------------------------ sparkline

  const Sparkline = (() => {
    const canvas = $('sparkline');
    const ctx = canvas.getContext('2d');
    let data = [];
    let sig = null;
    let hoverX = null;

    function update(s) {
      const h = s && Array.isArray(s.history) ? s.history : [];
      const last = h[h.length - 1];
      const nsig = h.length + ':' + (last ? last.at + '|' + last.acceptedBytes : '');
      if (nsig === sig) return;
      sig = nsig;
      data = h
        .map((p) => ({ t: tsOf(p.at), v: Number(p.acceptedBytes) || 0 }))
        .filter((p) => p.t > 0)
        .sort((a, b) => a.t - b.t);
      rangeLabel();
      draw();
    }

    function rangeLabel() {
      let txt = '';
      if (data.length) {
        const vs = data.map((p) => p.v);
        const mn = Math.min(...vs), mx = Math.max(...vs);
        const d = data[data.length - 1].v - data[0].v;
        const span = data.length > 1 ? fmtAge((data[data.length - 1].t - data[0].t) / 1000) : null;
        txt = fmtBytes(mn) + ' – ' + fmtBytes(mx) +
          (data.length > 1 ? ' · ' + (d >= 0 ? '+' : '−') + fmtBytes(Math.abs(d)) + (span ? ' over ' + span : '') : '');
      }
      setText('spark-range', txt);
    }

    function size() {
      const dpr = Math.min(2, window.devicePixelRatio || 1);
      const w = canvas.clientWidth || 300;
      const h = canvas.clientHeight || 90;
      if (canvas.width !== Math.floor(w * dpr) || canvas.height !== Math.floor(h * dpr)) {
        canvas.width = Math.floor(w * dpr);
        canvas.height = Math.floor(h * dpr);
      }
      ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
      return { w, h };
    }

    function draw() {
      const { w, h } = size();
      ctx.clearRect(0, 0, w, h);
      const padL = 46, padR = 14, padT = 10, padB = 14;
      const iw = w - padL - padR, ih = h - padT - padB;
      if (iw <= 10 || ih <= 10) return;

      if (!data.length) {
        ctx.fillStyle = 'rgba(111, 101, 85, 0.8)';
        ctx.font = '12px ' + SANS;
        ctx.textAlign = 'center';
        ctx.fillText('no history yet', w / 2, h / 2);
        ctx.textAlign = 'left';
        return;
      }

      const vs = data.map((p) => p.v);
      let mn = Math.min(...vs), mx = Math.max(...vs);
      if (mx - mn < 1) { mx = mn + 1; }
      const t0 = data[0].t, t1 = data[data.length - 1].t || t0 + 1;
      const X = (t) => padL + (t1 === t0 ? 0 : ((t - t0) / (t1 - t0)) * iw);
      const Y = (v) => padT + (1 - (v - mn) / (mx - mn)) * ih;

      // grid + labels
      ctx.font = '9.5px ' + MONO;
      ctx.textBaseline = 'middle';
      for (let i = 0; i <= 2; i++) {
        const v = mn + ((mx - mn) * i) / 2;
        const y = Y(v);
        ctx.strokeStyle = 'rgba(44, 38, 29, 0.9)';
        ctx.lineWidth = 1;
        ctx.beginPath(); ctx.moveTo(padL, y); ctx.lineTo(w - padR, y); ctx.stroke();
        ctx.fillStyle = 'rgba(111, 101, 85, 0.9)';
        ctx.textAlign = 'right';
        ctx.fillText(fmtBytes(v), padL - 6, y);
      }
      ctx.textAlign = 'left';

      if (data.length === 1) {
        const x = padL + iw / 2, y = Y(data[0].v);
        ctx.fillStyle = '#ffc464';
        ctx.beginPath(); ctx.arc(x, y, 2.5, 0, Math.PI * 2); ctx.fill();
        return;
      }

      // area fill
      const grad = ctx.createLinearGradient(0, padT, 0, h - padB);
      grad.addColorStop(0, 'rgba(242, 163, 60, 0.30)');
      grad.addColorStop(1, 'rgba(242, 163, 60, 0)');
      ctx.beginPath();
      ctx.moveTo(X(data[0].t), h - padB);
      for (const p of data) ctx.lineTo(X(p.t), Y(p.v));
      ctx.lineTo(X(data[data.length - 1].t), h - padB);
      ctx.closePath();
      ctx.fillStyle = grad;
      ctx.fill();

      // line
      ctx.beginPath();
      data.forEach((p, i) => (i ? ctx.lineTo(X(p.t), Y(p.v)) : ctx.moveTo(X(p.t), Y(p.v))));
      ctx.strokeStyle = '#f2a33c';
      ctx.lineWidth = 1.5;
      ctx.lineJoin = 'round';
      ctx.stroke();

      // last point
      const lp = data[data.length - 1];
      ctx.fillStyle = '#ffc464';
      ctx.beginPath(); ctx.arc(X(lp.t), Y(lp.v), 2.5, 0, Math.PI * 2); ctx.fill();

      // hover
      if (hoverX != null) {
        let best = 0, bd = Infinity;
        for (let i = 0; i < data.length; i++) {
          const d = Math.abs(X(data[i].t) - hoverX);
          if (d < bd) { bd = d; best = i; }
        }
        const p = data[best];
        const x = X(p.t), y = Y(p.v);
        ctx.strokeStyle = 'rgba(237, 230, 216, 0.25)';
        ctx.beginPath(); ctx.moveTo(x, padT); ctx.lineTo(x, h - padB); ctx.stroke();
        ctx.fillStyle = '#ede6d8';
        ctx.beginPath(); ctx.arc(x, y, 3, 0, Math.PI * 2); ctx.fill();
        const label = fmtBytes(p.v) + ' · ' + relShort(new Date(p.t).toISOString()) + ' ago';
        ctx.font = '10px ' + MONO;
        const tw = ctx.measureText(label).width;
        let lx = x + 8; if (lx + tw > w - padR) lx = x - tw - 8;
        ctx.fillStyle = 'rgba(12, 10, 8, 0.9)';
        ctx.fillRect(lx - 3, y - 16, tw + 6, 13);
        ctx.fillStyle = '#ede6d8';
        ctx.fillText(label, lx, y - 9);
      }
    }

    canvas.addEventListener('pointermove', (e) => {
      const b = canvas.getBoundingClientRect();
      hoverX = e.clientX - b.left;
      draw();
    });
    canvas.addEventListener('pointerleave', () => { hoverX = null; draw(); });

    return { update, init: () => new ResizeObserver(() => draw()).observe(canvas), draw };
  })();

  // ------------------------------------------------------------------ treemap

  const Treemap = (() => {
    const wrap = $('treemap-wrap');
    const canvas = $('treemap');
    const tt = $('tt');
    const emptyEl = $('map-empty');
    const ctx = canvas.getContext('2d');
    const scene = document.createElement('canvas');
    const sctx = scene.getContext('2d');
    const PULSE_MS = 1600;
    const TRANS_MS = 280;

    let W = 0, H = 0, dpr = 1;
    let units = [];
    let mode = 'root';
    let moduleId = null;
    let rects = [];
    let byId = new Map();
    let hover = null;
    let focusI = -1;
    let rafPending = false;
    let prevScene = null;
    let trans = null;
    let pulses = new Map();
    let labelBudget = 900;

    function sizeCanvas() {
      const r = wrap.getBoundingClientRect();
      W = Math.max(10, Math.floor(r.width));
      H = Math.max(10, Math.floor(r.height));
      dpr = Math.min(2, window.devicePixelRatio || 1);
      for (const c of [canvas, scene]) {
        c.width = Math.floor(W * dpr);
        c.height = Math.floor(H * dpr);
      }
      for (const c of [ctx, sctx]) c.setTransform(dpr, 0, 0, dpr, 0, 0);
      trans = null; prevScene = null;
    }

    // ---- data shaping

    function moduleList() {
      const m = new Map();
      for (const u of units) {
        const key = u.module || '(unassigned)';
        let g = m.get(key);
        if (!g) { g = { module: key, bytes: 0, accepted: 0, count: 0 }; m.set(key, g); }
        const b = typeof u.bytes === 'number' && isFinite(u.bytes) ? u.bytes : 0;
        g.count++; g.bytes += b;
        if (u.accepted) { g.accepted += b; }
      }
      return [...m.values()].sort((a, b) => b.bytes - a.bytes);
    }

    function unitsOf(modName) {
      return units
        .filter((u) => (u.module || '(unassigned)') === modName)
        .sort((a, b) => (b.bytes || 0) - (a.bytes || 0));
    }

    // ---- squarified treemap

    function squarify(entries, x, y, w, h, minArea) {
      const out = [];
      let dropped = 0;
      const total = entries.reduce((s, e) => s + e.value, 0);
      if (!(total > 0) || w < 2 || h < 2) return out;
      const scale = (w * h) / total;
      let items = entries
        .map((e) => ({ key: e.key, ref: e.ref, area: Math.max(0, e.value * scale) }))
        .filter((e) => e.area > 0);
      if (!items.length) return out;
      if (minArea) for (const it of items) if (it.area < minArea) it.area = minArea;
      let sum = items.reduce((s, i) => s + i.area, 0);
      if (sum > w * h) {
        items.sort((a, b) => b.area - a.area);
        const keep = [];
        let acc = 0;
        for (const it of items) {
          if (acc + it.area <= w * h * 0.998) { keep.push(it); acc += it.area; }
          else dropped++;
        }
        if (keep.length) {
          const k = (w * h) / acc;
          for (const it of keep) it.area *= k;
        }
        items = keep;
      }

      let cx = x, cy = y, cw = w, ch = h, row = [], i = 0;
      const lay = (rowArr) => {
        const s = rowArr.reduce((a, b) => a + b.area, 0);
        if (s <= 0) return;
        if (cw < ch) {
          const rh = s / cw;
          let px = cx;
          for (const it of rowArr) { const rw = it.area / rh; out.push({ x: px, y: cy, w: rw, h: rh, ref: it.ref }); px += rw; }
          cy += rh; ch -= rh;
        } else {
          const rw = s / ch;
          let py = cy;
          for (const it of rowArr) { const rh = it.area / rw; out.push({ x: cx, y: py, w: rw, h: rh, ref: it.ref }); py += rh; }
          cx += rw; cw -= rw;
        }
      };
      const worst = (rowArr, len) => {
        let s = 0, mx = 0, mn = Infinity;
        for (const r of rowArr) { s += r.area; if (r.area > mx) mx = r.area; if (r.area < mn) mn = r.area; }
        const s2 = s * s, l2 = len * len;
        return Math.max((l2 * mx) / s2, s2 / (l2 * mn));
      };
      while (i < items.length) {
        const len = Math.max(0.5, Math.min(cw, ch));
        const cand = row.concat([items[i]]);
        if (!row.length || worst(cand, len) <= worst(row, len)) { row = cand; i++; }
        else { lay(row); row = []; }
        if (cw <= 1 || ch <= 1) { dropped += row.length + (items.length - i); row = []; break; }
      }
      if (row.length) lay(row);
      if (dropped > 0) {
        const bh = Math.min(16, Math.max(10, H * 0.03));
        out.push({ x: x, y: y + h - bh, w: w, h: bh, ref: { type: 'overflow', n: dropped } });
      }
      return out;
    }

    // ---- painting

    function fitText(c, text, maxW) {
      if (c.measureText(text).width <= maxW) return text;
      let t = text;
      while (t.length > 1 && c.measureText(t + '…').width > maxW) t = t.slice(0, -1);
      return t + '…';
    }

    function paintUnit(c, r, rx, ry, rw, rh) {
      const u = r.ref.unit;
      let fill, stroke = 'rgba(0, 0, 0, 0.38)';
      if (u.accepted) {
        const a = 0.78 + 0.17 * hash01(String(u.id));
        fill = 'rgba(242, 163, 60, ' + a.toFixed(3) + ')';
      } else if (u.matchPercent != null && u.matchPercent > 0) {
        const a = 0.08 + 0.34 * Math.min(1, u.matchPercent / 100);
        fill = 'rgba(63, 198, 220, ' + a.toFixed(3) + ')';
        stroke = 'rgba(63, 198, 220, 0.28)';
      } else {
        fill = 'rgba(150, 140, 120, 0.08)';
        stroke = 'rgba(150, 140, 120, 0.18)';
      }
      c.fillStyle = fill;
      c.fillRect(rx, ry, rw, rh);
      c.strokeStyle = stroke;
      c.lineWidth = 1;
      c.strokeRect(rx + 0.5, ry + 0.5, Math.max(0, rw - 1), Math.max(0, rh - 1));
      if (rw >= 46 && rh >= 15 && labelBudget-- > 0) {
        c.fillStyle = u.accepted ? 'rgba(32, 21, 6, 0.85)' : 'rgba(238, 229, 214, 0.72)';
        c.font = '9.5px ' + MONO;
        c.textBaseline = 'middle';
        c.fillText(fitText(c, String(u.name || u.id || ''), rw - 8), rx + 4, ry + rh / 2 + 0.5);
        c.textBaseline = 'alphabetic';
      }
    }

    function paintModule(c, r, rx, ry, rw, rh) {
      const g = r.ref.mod;
      const ratio = g.bytes > 0 ? Math.min(1, g.accepted / g.bytes) : 0;
      c.fillStyle = 'rgba(150, 138, 116, 0.10)';
      c.fillRect(rx, ry, rw, rh);
      if (ratio > 0) {
        c.fillStyle = 'rgba(242, 163, 60, ' + (0.10 + 0.76 * ratio).toFixed(3) + ')';
        c.fillRect(rx, ry, rw, rh);
      }
      c.strokeStyle = 'rgba(0, 0, 0, 0.4)';
      c.lineWidth = 1;
      c.strokeRect(rx + 0.5, ry + 0.5, Math.max(0, rw - 1), Math.max(0, rh - 1));
      if (rw >= 70 && rh >= 24) {
        const bright = ratio > 0.55;
        c.fillStyle = bright ? 'rgba(35, 24, 8, 0.92)' : 'rgba(238, 229, 214, 0.92)';
        c.font = '600 12px ' + SANS;
        c.fillText(fitText(c, String(g.module), rw - 10), rx + 5, ry + 15);
        if (rh >= 40) {
          const pct = g.bytes > 0 ? Math.round(ratio * 100) : 0;
          c.fillStyle = bright ? 'rgba(35, 24, 8, 0.65)' : 'rgba(238, 229, 214, 0.55)';
          c.font = '10px ' + SANS;
          c.fillText(g.count + ' units · ' + pct + '%', rx + 5, ry + 29);
        }
      }
    }

    function paintScene() {
      labelBudget = 900;
      sctx.clearRect(0, 0, W, H);
      for (const r of rects) {
        const rx = r.x + 0.5, ry = r.y + 0.5;
        const rw = Math.max(0.5, r.w - 1), rh = Math.max(0.5, r.h - 1);
        if (rw < 0.5 || rh < 0.5) continue;
        if (r.ref.type === 'module') paintModule(sctx, r, rx, ry, rw, rh);
        else if (r.ref.type === 'unit') paintUnit(sctx, r, rx, ry, rw, rh);
        else {
          sctx.fillStyle = 'rgba(10, 8, 6, 0.92)';
          sctx.fillRect(rx, ry, rw, rh);
          sctx.fillStyle = 'rgba(168, 158, 139, 0.85)';
          sctx.font = '10px ' + MONO;
          sctx.textBaseline = 'middle';
          sctx.fillText('+' + r.ref.n + ' tiny units', rx + 6, ry + rh / 2);
          sctx.textBaseline = 'alphabetic';
        }
      }
    }

    function draw(now) {
      ctx.clearRect(0, 0, W, H);
      if (!rects.length) return;
      if (trans && prevScene) {
        const k = Math.min(1, (now - trans.t0) / TRANS_MS);
        const e = easeOut(k);
        const s1 = 1 + 0.05 * e;
        ctx.globalAlpha = 1 - e;
        ctx.drawImage(prevScene, (W - W * s1) / 2, (H - H * s1) / 2, W * s1, H * s1);
        const s2 = 0.95 + 0.05 * e;
        ctx.globalAlpha = e;
        ctx.drawImage(scene, (W - W * s2) / 2, (H - H * s2) / 2, W * s2, H * s2);
        ctx.globalAlpha = 1;
        if (k >= 1) trans = null;
      } else {
        ctx.drawImage(scene, 0, 0, W, H);
      }
      if (hover) {
        const r = hover;
        ctx.fillStyle = 'rgba(255, 255, 255, 0.06)';
        ctx.fillRect(r.x, r.y, r.w, r.h);
        ctx.strokeStyle = 'rgba(255, 255, 255, 0.85)';
        ctx.lineWidth = 1.25;
        ctx.strokeRect(r.x + 0.5, r.y + 0.5, Math.max(0, r.w - 1), Math.max(0, r.h - 1));
      }
      for (const [id, t0] of pulses) {
        const r = byId.get(id);
        if (!r) continue;
        const k = Math.min(1, (now - t0) / PULSE_MS);
        const a = 1 - k;
        const inf = 2.5 * (1 - easeOut(k));
        ctx.fillStyle = 'rgba(255, 205, 110, ' + (0.4 * a).toFixed(3) + ')';
        ctx.fillRect(r.x - inf, r.y - inf, r.w + inf * 2, r.h + inf * 2);
        ctx.strokeStyle = 'rgba(255, 220, 150, ' + (0.9 * a).toFixed(3) + ')';
        ctx.lineWidth = 1.5;
        ctx.strokeRect(r.x + 0.5, r.y + 0.5, Math.max(0, r.w - 1), Math.max(0, r.h - 1));
      }
      if (focusI >= 0 && rects[focusI]) {
        const r = rects[focusI];
        ctx.setLineDash([4, 3]);
        ctx.strokeStyle = 'rgba(255, 255, 255, 0.9)';
        ctx.lineWidth = 1.5;
        ctx.strokeRect(r.x + 1.5, r.y + 1.5, Math.max(0, r.w - 3), Math.max(0, r.h - 3));
        ctx.setLineDash([]);
      }
    }

    function requestDraw() {
      // paint synchronously as well: correct first paint and correct output
      // even when rAF is throttled (hidden/background tabs)
      draw(performance.now());
      if (!rafPending) {
        rafPending = true;
        requestAnimationFrame(frame);
      }
    }

    function frame() {
      rafPending = false;
      const now = performance.now();
      for (const [id, t0] of pulses) if (now - t0 > PULSE_MS) pulses.delete(id);
      draw(now);
      if (trans || pulses.size) requestDraw();
    }

    // ---- layout / navigation

    function relayout() {
      hover = null;
      tt.hidden = true;
      if (!units.length) {
        emptyEl.hidden = false;
        rects = []; byId.clear();
        paintScene(); requestDraw();
        return;
      }
      emptyEl.hidden = true;
      if (mode === 'root') {
        rects = squarify(
          moduleList().map((g) => ({ key: g.module, value: Math.max(g.bytes, 1), ref: { type: 'module', mod: g } })),
          0, 0, W, H, 2
        );
      } else {
        rects = squarify(
          unitsOf(moduleId).map((u) => ({ key: u.id, value: Math.max(u.bytes || 0, 1), ref: { type: 'unit', unit: u } })),
          0, 0, W, H, 2
        );
      }
      byId.clear();
      for (const r of rects) if (r.ref.type === 'unit') byId.set(r.ref.unit.id, r);
      paintScene();
      requestDraw();
    }

    function snapshot() {
      const c = document.createElement('canvas');
      c.width = scene.width; c.height = scene.height;
      c.getContext('2d').drawImage(scene, 0, 0);
      return c;
    }

    function renderCrumbs() {
      const c = $('crumbs');
      if (mode === 'root') {
        c.replaceChildren(el('span', { class: 'crumb is-current', text: 'all modules' }));
        canvas.setAttribute('aria-label', 'Byte-weighted treemap of all decompilation modules. Arrow keys move between blocks, Enter zooms in, Escape does nothing here.');
      } else {
        const root = el('button', { class: 'crumb', type: 'button', text: 'all modules' });
        root.addEventListener('click', toRoot);
        c.replaceChildren(root, el('span', { class: 'crumb-sep', text: '▸' }), el('span', { class: 'crumb is-current', text: String(moduleId) }));
        canvas.setAttribute('aria-label', 'Treemap of units in module ' + moduleId + '. Arrow keys move between blocks, Enter inspects a block, Escape zooms out.');
      }
    }

    function drill(m) {
      if (mode === 'module' && moduleId === m) return;
      if (S.motion) { prevScene = snapshot(); trans = { t0: performance.now(), dur: TRANS_MS }; }
      mode = 'module'; moduleId = m; focusI = -1;
      renderCrumbs(); relayout();
    }

    function toRoot() {
      if (mode === 'root') return;
      if (S.motion) { prevScene = snapshot(); trans = { t0: performance.now(), dur: TRANS_MS }; }
      mode = 'root'; moduleId = null; focusI = -1;
      renderCrumbs(); relayout();
    }

    // ---- interaction

    function rectAt(px, py) {
      for (let i = rects.length - 1; i >= 0; i--) {
        const r = rects[i];
        if (px >= r.x && px <= r.x + r.w && py >= r.y && py <= r.y + r.h) return r;
      }
      return null;
    }

    function tooltipNodes(r) {
      const nodes = [];
      const hint = (t) => el('div', { class: 'tt-hint', text: t });
      if (r.ref.type === 'unit') {
        const u = r.ref.unit;
        nodes.push(el('div', { class: 'tt-name', text: String(u.name || u.id || 'unit') }));
        nodes.push(el('div', { class: 'tt-row', text: 'module: ' + (u.module || '—') }));
        nodes.push(el('div', { class: 'tt-row' }, document.createTextNode(fmtBytes(u.bytes) + ' '), el('span', { class: 'dim', text: '(' + Number(u.bytes || 0).toLocaleString('en-US') + ' B)' })));
        let st, cls;
        if (u.accepted) { st = 'accepted'; cls = 'tt-status-accepted'; }
        else if (u.matchPercent != null && u.matchPercent > 0) { st = 'matched ' + u.matchPercent + '% · not accepted'; cls = 'tt-status-matched'; }
        else if (u.matchPercent === 0) { st = 'matched 0% · not accepted'; cls = 'tt-status-matched'; }
        else { st = 'no match'; cls = 'tt-status-none'; }
        nodes.push(el('div', { class: 'tt-row' }, el('span', { class: cls, text: st })));
        if (u.accepted && u.matchPercent != null) {
          nodes.push(el('div', { class: 'tt-row', text: 'match: ' + u.matchPercent + '%' }));
        }
        if (u.source) nodes.push(el('div', { class: 'tt-row' }, el('span', { class: 'mono dim', text: String(u.source) })));
        nodes.push(hint('click to inspect'));
      } else if (r.ref.type === 'module') {
        const g = r.ref.mod;
        const pct = g.bytes > 0 ? Math.round((g.accepted / g.bytes) * 100) : 0;
        nodes.push(el('div', { class: 'tt-name', text: String(g.module) }));
        nodes.push(el('div', { class: 'tt-row', text: g.count + ' units · ' + fmtBytes(g.bytes) }));
        nodes.push(el('div', { class: 'tt-row' }, el('span', { class: 'tt-status-accepted', text: 'accepted ' + fmtBytes(g.accepted) + ' · ' + pct + '%' })));
        nodes.push(hint('click to zoom in'));
      } else {
        nodes.push(el('div', { class: 'tt-name', text: '+' + r.ref.n + ' tiny units' }));
        nodes.push(el('div', { class: 'tt-row', text: 'too small to display individually' }));
      }
      return nodes;
    }

    function setHover(r, px, py) {
      hover = r;
      if (r && px != null) {
        tt.replaceChildren(...tooltipNodes(r));
        tt.hidden = false;
        const tw = tt.offsetWidth, th = tt.offsetHeight;
        let x = px + 14, y = py + 14;
        if (x + tw > W - 8) x = px - tw - 12;
        if (x < 8) x = 8;
        if (y + th > H - 8) y = py - th - 12;
        if (y < 8) y = 8;
        tt.style.left = x + 'px';
        tt.style.top = y + 'px';
      } else {
        tt.hidden = true;
      }
      requestDraw();
    }

    function activate(r) {
      if (!r) return;
      if (r.ref.type === 'module') drill(r.ref.mod.module);
      else if (r.ref.type === 'unit') openUnitCard(r.ref.unit);
    }

    let downPt = null;
    canvas.addEventListener('pointermove', (e) => {
      const b = canvas.getBoundingClientRect();
      setHover(rectAt(e.clientX - b.left, e.clientY - b.top), e.clientX - b.left, e.clientY - b.top);
    });
    canvas.addEventListener('pointerdown', (e) => { downPt = { x: e.clientX, y: e.clientY }; });
    canvas.addEventListener('pointerup', (e) => {
      if (!downPt) return;
      const moved = Math.hypot(e.clientX - downPt.x, e.clientY - downPt.y);
      downPt = null;
      if (moved > 6) return;
      const b = canvas.getBoundingClientRect();
      const r = rectAt(e.clientX - b.left, e.clientY - b.top);
      if (!r) { closeUnitCard(); return; }
      activate(r);
    });
    canvas.addEventListener('pointerleave', () => setHover(null, null, null));

    function moveFocus(dx, dy) {
      if (!rects.length) return;
      if (focusI < 0 || !rects[focusI]) {
        focusI = 0;
        for (let i = 0; i < rects.length; i++) {
          if (rects[i].ref.type === 'overflow') continue;
          focusI = i; break;
        }
        syncFocus();
        return;
      }
      const cur = rects[focusI];
      const cx = cur.x + cur.w / 2, cy = cur.y + cur.h / 2;
      let best = -1, bestScore = Infinity;
      for (let i = 0; i < rects.length; i++) {
        if (i === focusI || rects[i].ref.type === 'overflow') continue;
        const r = rects[i];
        const ddx = r.x + r.w / 2 - cx, ddy = r.y + r.h / 2 - cy;
        const dot = ddx * dx + ddy * dy;
        if (dot <= 1) continue;
        const along = Math.abs(dx) ? Math.abs(ddx) : Math.abs(ddy);
        const perp = Math.abs(dx) ? Math.abs(ddy) : Math.abs(ddx);
        const score = along + perp * 2.5;
        if (score < bestScore) { bestScore = score; best = i; }
      }
      if (best >= 0) { focusI = best; syncFocus(); }
    }

    function syncFocus() {
      const r = rects[focusI];
      if (!r) return;
      setHover(r, r.x + r.w / 2, Math.max(8, r.y));
    }

    canvas.addEventListener('keydown', (e) => {
      const map = { ArrowLeft: [-1, 0], ArrowRight: [1, 0], ArrowUp: [0, -1], ArrowDown: [0, 1] };
      if (map[e.key]) { e.preventDefault(); moveFocus(map[e.key][0], map[e.key][1]); return; }
      if (e.key === 'Home') { e.preventDefault(); focusI = 0; syncFocus(); return; }
      if (e.key === 'End') { e.preventDefault(); focusI = rects.length - 1; syncFocus(); return; }
      if (e.key === 'Enter') { e.preventDefault(); if (focusI >= 0) activate(rects[focusI]); return; }
      if (e.key === 'Escape') { e.preventDefault(); toRoot(); }
    });
    canvas.addEventListener('focus', () => { if (focusI < 0 && rects.length) moveFocus(0, 0); });
    canvas.addEventListener('blur', () => { focusI = -1; setHover(null, null, null); });

    // ---- public

    function setData(us) {
      units = Array.isArray(us) ? us : [];
      relayout();
    }

    function pulse(ids) {
      if (!S.motion || !ids.length) return;
      const t = performance.now();
      for (const id of ids) pulses.set(String(id), t);
      requestDraw();
    }

    function reveal(id) {
      const u = units.find((x) => String(x.id) === String(id));
      if (!u) return;
      drill(u.module || '(unassigned)');
      if (S.motion) { pulses.set(String(id), performance.now()); requestDraw(); }
      openUnitCard(u);
    }

    function init() {
      sizeCanvas();
      renderCrumbs();
      new ResizeObserver(() => { sizeCanvas(); relayout(); }).observe(wrap);
      // hidden/background tabs never deliver ResizeObserver callbacks
      // (frame-loop-aligned); resync cheaply so backing stores stay correct
      setInterval(() => {
        const w = Math.max(10, Math.floor(wrap.clientWidth));
        const h = Math.max(10, Math.floor(wrap.clientHeight));
        const nd = Math.min(2, window.devicePixelRatio || 1);
        if (w !== W || h !== H || nd !== dpr) { sizeCanvas(); relayout(); }
      }, 2000);
      requestDraw();
    }

    return { init, setData, pulse, reveal, toRoot, motionChanged: () => { pulses.clear(); requestDraw(); } };
  })();

  // ------------------------------------------------------------------ unit card

  function openUnitCard(u) {
    unitCardOpen = u;
    const card = $('unit-card');
    card.hidden = false;
    const close = el('button', { class: 'unit-card-close', type: 'button', text: '×', attrs: { title: 'Close (Esc)', 'aria-label': 'Close unit details' } });
    close.addEventListener('click', closeUnitCard);
    const dl = el('dl');
    const row = (dt, dd) => dl.append(el('dt', { text: dt }), dd);
    row('module', el('dd', { text: String(u.module || '—') }));
    row('bytes', el('dd', {}, document.createTextNode(fmtBytes(u.bytes) + ' '), el('span', { class: 'dim', text: '(' + Number(u.bytes || 0).toLocaleString('en-US') + ' B)' })));
    let st, cls;
    if (u.accepted) { st = 'accepted'; cls = 'uc-accepted'; }
    else if (u.matchPercent != null && u.matchPercent > 0) { st = 'matched ' + u.matchPercent + '% · not accepted'; cls = 'uc-matched'; }
    else if (u.matchPercent === 0) { st = 'matched 0% · not accepted'; cls = 'uc-matched'; }
    else { st = 'no match'; cls = 'uc-none'; }
    row('status', el('dd', { class: cls, text: st }));
    if (u.accepted && u.matchPercent != null) row('match', el('dd', { text: u.matchPercent + '%' }));
    row('source', el('dd', { class: 'uc-path', text: u.source ? String(u.source) : '—' }));
    card.replaceChildren(
      el('div', { class: 'unit-card-head' }, el('div', { class: 'unit-card-title', text: String(u.name || u.id || 'unit') }), close),
      dl
    );
  }

  function closeUnitCard() {
    unitCardOpen = null;
    $('unit-card').hidden = true;
  }

  // ------------------------------------------------------------------ recent strip

  const RecentStrip = (() => {
    const strip = $('recent-strip');
    const agoEl = el('span', { class: 'recent-ago' });
    let t0 = 0;

    function show(ids) {
      const us = ids.map((id) => S.unitsById.get(String(id))).filter(Boolean);
      if (!us.length) return;
      t0 = Date.now();
      const chips = us.slice(0, 8).map((u) => {
        const b = el('button', { class: 'chip', type: 'button', text: trunc(u.name || u.id, 28) });
        b.title = (u.module || '') + ' · ' + (u.name || u.id);
        b.addEventListener('click', () => Treemap.reveal(u.id));
        return b;
      });
      strip.replaceChildren(
        el('span', { class: 'recent-label', text: ids.length === 1 ? 'just accepted' : 'just accepted ×' + ids.length }),
        ...chips,
        us.length > 8 ? el('span', { class: 'dim', text: '+' + (us.length - 8) + ' more' }) : null,
        agoEl
      );
      strip.hidden = false;
      tick();
    }

    function tick() {
      if (strip.hidden) return;
      const s = Math.floor((Date.now() - t0) / 1000);
      if (s > 90) { strip.hidden = true; return; }
      agoEl.textContent = '· ' + fmtAge(s) + ' ago';
    }

    return { show, tick };
  })();

  // ------------------------------------------------------------------ agents

  function stateOf(raw) {
    if (raw == null || raw === '') return 'unknown';
    return String(raw).toLowerCase();
  }

  function groupOf(raw) {
    const s = stateOf(raw);
    if (s === 'working' || s === 'blocked') return 'active';
    if (s === 'waiting') return 'waiting';
    return 'historical';
  }

  const keyOf = (a) => String(a.id ?? a.name ?? '');

  // One simultaneously visible terminal per worker. Only the observer's
  // allowlisted text updates are live; journal backfill is explicitly opted
  // into and labeled. Retained DOM nodes keep selection and reading stable.
  const Streams = (() => {
    const panels = new Map();
    const liveAgents = new Map();
    const liveItems = new Map();
    const historyItems = new Map();
    let connected = false, source = null, historyRevision = null;
    let historyBusy = false, pendingSnapshot = null, showHistory = false, retryTimer = null;
    try { showHistory = localStorage.getItem('brawldash.streamHistory') === '1'; } catch (_) {}

    function status() {
      setText('streams-status', S.paused ? 'Paused — Resume reconnects to retained observer output.' :
        connected ? 'Live observer connected · visible generated text, not journal polling' :
          'Live observer disconnected — owning omp must load the bridge. No live text is being received.');
      $('streams-status').classList.toggle('is-error', !connected && !S.paused);
    }

    function createPanel(a) {
      const key = keyOf(a);
      const name = el('span', { class: 'stream-heading' });
      const state = el('span', { class: 'stream-state' });
      const identity = el('div', { class: 'stream-identity' });
      const count = el('span', { class: 'stream-count' });
      const log = el('div', { class: 'stream-log', attrs: {
        role: 'log', 'aria-live': 'off', tabindex: '0',
        'aria-label': String(a.name || a.id) + ' terminal output'
      } });
      const jump = el('button', { class: 'btn btn-small', type: 'button', text: 'Latest' });
      jump.addEventListener('click', () => { log.scrollTop = log.scrollHeight; });
      const node = el('section', { class: 'stream-panel', attrs: { 'data-agent': key } },
        el('div', { class: 'stream-panel-head' }, name, state), identity,
        el('div', { class: 'stream-toolbar' }, count, jump), log);
      return { key, node, name, state, identity, count, log, rows: new Map(), agent: a };
    }

    function row(item, historical) {
      const label = el('span');
      const text = el('pre', { class: 'stream-text' });
      const node = el('article', { class: 'stream-entry' + (historical ? ' stream-history' : ''),
        attrs: { 'data-source': historical ? 'history' : 'live', 'data-item': String(item.id) } },
        el('div', { class: 'stream-entry-head' }, label), text);
      return { node, label, text };
    }

    function renderPanel(panel) {
      const a = panel.agent;
      panel.name.textContent = String(a.name || a.id);
      panel.state.textContent = stateOf(a.state) + (a.observed && !connected ? ' · last observed' : '');
      panel.identity.textContent = [a.model, a.definition, a.target,
        a.correction != null ? 'corrections: ' + a.correction : null].filter(Boolean).join(' · ');
      panel.identity.title = panel.key;
      const live = Array.from(liveItems.values()).filter(x => String(x.agentId) === panel.key)
        .sort((a, b) => tsOf(a.at) - tsOf(b.at) || Number(a.sequence) - Number(b.sequence));
      const historical = showHistory ? (historyItems.get(panel.key) || []) : [];
      const list = [...historical.map(item => ({ item, historical: true })),
        ...live.map(item => ({ item, historical: false }))];
      const log = panel.log;
      const follow = log.scrollHeight - log.scrollTop - log.clientHeight < 35;
      const oldTop = log.scrollTop;
      const anchor = Array.from(log.children).find(n => n.offsetTop + n.offsetHeight > oldTop);
      const anchorOffset = anchor ? anchor.offsetTop - oldTop : 0;
      const keys = new Set();
      let cursor = log.firstElementChild;
      for (const { item, historical } of list) {
        const key = (historical ? 'history:' : 'live:') + item.id;
        keys.add(key);
        let entry = panel.rows.get(key);
        if (!entry) { entry = row(item, historical); panel.rows.set(key, entry); }
        const label = historical ? 'Recorded history · completed message · ' + (item.at || '') :
          'Live generated text · ' + (item.complete ? 'message complete' : 'generating…') +
          (item.truncated ? ' · retained text limit reached' : '');
        if (entry.label.textContent !== label) entry.label.textContent = label;
        const text = String(item.text || '');
        const oldText = entry.text.textContent;
        if (oldText !== text) {
          // Append to the existing text node whenever possible so a reader's
          // selection is not replaced as a generating message grows.
          if (entry.text.firstChild && text.startsWith(oldText)) entry.text.firstChild.appendData(text.slice(oldText.length));
          else entry.text.textContent = text;
        }
        entry.node.dataset.complete = String(!!item.complete);
        if (entry.node === cursor) cursor = cursor.nextElementSibling;
        else log.insertBefore(entry.node, cursor);
      }
      for (const [key, entry] of panel.rows) {
        if (!keys.has(key)) { entry.node.remove(); panel.rows.delete(key); }
      }
      if (!list.length) {
        if (!panel.empty) panel.empty = el('div', { class: 'stream-empty' });
        panel.empty.textContent = connected ? 'No visible generated text observed for this worker yet.' :
          'Waiting for the owning runner observer. Recorded history is available only through Show history.';
        if (!panel.empty.isConnected) log.append(panel.empty);
      } else panel.empty?.remove();
      panel.count.textContent = live.length + ' live messages' +
        (showHistory ? ' · ' + historical.length + ' recorded' : '');
      if (follow) log.scrollTop = log.scrollHeight;
      else log.scrollTop = anchor?.isConnected ? anchor.offsetTop - anchorOffset : oldTop;
    }

    function render() {
      const merged = new Map(S.agents.filter(a => a.name !== 'main').map(a => [keyOf(a), a]));
      for (const [key, a] of liveAgents) merged.set(key, { ...(merged.get(key) || {}), ...a });
      const all = Array.from(merged.values());
      const current = all.filter(a => groupOf(a.state) !== 'historical');
      const visible = showHistory ? all : current;
      // Identity ordering is stable when status/lastSeen changes.
      visible.sort((a, b) => String(a.name || a.id).localeCompare(String(b.name || b.id)));
      const keys = new Set(visible.map(keyOf));
      for (const [key, panel] of panels) {
        if (!keys.has(key)) { panel.node.remove(); panels.delete(key); }
      }
      for (const a of visible) {
        const key = keyOf(a);
        let panel = panels.get(key);
        if (!panel) { panel = createPanel(a); panels.set(key, panel); $('streams-grid').append(panel.node); }
        panel.agent = a;
        renderPanel(panel);
      }
      setText('streams-count', '· ' + visible.length);
      $('streams-history').setAttribute('aria-pressed', String(showHistory));
      $('streams-history').textContent = showHistory ? 'Hide history' : 'Show history';
      setText('streams-note', current.length + ' current workers · ' + (all.length - current.length) +
        ' historical agents ' + (showHistory ? 'included. Recorded backfill is labeled separately; it is not live output.' :
          'hidden. Show history explicitly opts into historical agents and completed-record backfill.') +
        ' Each pane follows new text only while at its bottom; Latest resumes following. Prompts, hidden reasoning, tool payloads and provider metadata are not transported.');
      status();
    }

    function applySnapshot(data) {
      if (S.paused) { pendingSnapshot = data; return; }
      liveAgents.clear();
      liveItems.clear();
      for (const a of data.agents || []) liveAgents.set(String(a.id), a);
      for (const item of data.items || []) liveItems.set(String(item.id), item);
      render();
    }

    function connect() {
      if (source || retryTimer || S.paused) return;
      source = new EventSource('/api/live');
      source.addEventListener('snapshot', event => {
        try { connected = true; applySnapshot(JSON.parse(event.data)); status(); }
        catch (e) { logErr('live snapshot', e); }
      });
      source.addEventListener('agent', event => {
        if (S.paused) return;
        try {
          const a = JSON.parse(event.data);
          liveAgents.set(String(a.id), a);
          render();
        } catch (e) { logErr('live agent', e); }
      });
      source.addEventListener('text', event => {
        if (S.paused) return;
        try {
          const item = JSON.parse(event.data);
          liveItems.set(String(item.id), item);
          const panel = panels.get(String(item.agentId));
          if (panel) renderPanel(panel);
          else render();
        } catch (e) { logErr('live text', e); }
      });
      source.addEventListener('evict', event => {
        try {
          const data = JSON.parse(event.data);
          if (data.itemId) liveItems.delete(String(data.itemId));
          else {
            liveAgents.delete(String(data.agentId));
            for (const [id, item] of liveItems) if (String(item.agentId) === String(data.agentId)) liveItems.delete(id);
          }
          render();
        } catch (e) { logErr('live retention', e); }
      });
      source.addEventListener('error', () => {
        connected = false;
        status();
        // HTTP 503 (bridge not loaded) closes EventSource permanently. Retry
        // that case ourselves; established SSE reconnects use native retry.
        if (source?.readyState === EventSource.CLOSED) {
          source.close(); source = null;
          retryTimer = setTimeout(() => { retryTimer = null; connect(); }, 3000);
        }
      });
    }

    async function loadHistory() {
      if (!showHistory || historyBusy || S.paused || historyRevision === S.state?.streamRevision) return;
      historyBusy = true;
      const revision = S.state?.streamRevision;
      try {
        // Per-agent requests avoid a global limit starving less recent workers.
        // Bounded batches, not hundreds of concurrent browser connections.
        const agents = Array.from(panels.keys());
        for (let i = 0; i < agents.length && showHistory && !S.paused; i += 4) {
          await Promise.all(agents.slice(i, i + 4).map(async key => {
            const result = await fetchJSON('/api/streams?agent=' + encodeURIComponent(key) + '&limit=200');
            if (!showHistory || S.paused) return;
            historyItems.set(key, (result.items || []).sort((a, b) => tsOf(a.at) - tsOf(b.at) || a.sequence - b.sequence));
            const panel = panels.get(key);
            if (panel) renderPanel(panel);
          }));
        }
        if (showHistory && !S.paused) historyRevision = revision;
      } catch (e) { logErr('recorded history', e); setText('streams-status', 'Recorded history unavailable: ' + e.message); }
      finally { historyBusy = false; }
    }

    function update() {
      if (S.paused) {
        source?.close(); source = null; connected = false;
        clearTimeout(retryTimer); retryTimer = null;
      } else {
        if (pendingSnapshot) { applySnapshot(pendingSnapshot); pendingSnapshot = null; }
        connect();
      }
      render();
      loadHistory();
    }

    $('streams-history').addEventListener('click', () => {
      showHistory = !showHistory;
      historyRevision = null;
      try { localStorage.setItem('brawldash.streamHistory', showHistory ? '1' : '0'); } catch (_) {}
      update();
    });
    return { update };
  })();

  // ------------------------------------------------------------------ warnings

  function renderWarnings(s) {
    const list = Array.isArray(s.warnings) ? s.warnings.filter((x) => x != null).map(String) : [];
    const box = $('warnings');
    if (!list.length) { box.hidden = true; return; }
    box.hidden = false;
    const toggle = $('warnings-toggle');
    const ul = $('warnings-list');
    setText('warnings-label', list.length === 1 ? list[0] : list.length + ' warnings');
    ul.replaceChildren(...list.map((x) => el('li', { text: x })));
    if (list.length === 1) { ul.hidden = true; toggle.setAttribute('aria-expanded', 'false'); }
  }

  // ------------------------------------------------------------------ controls

  function setPaused(on) {
    S.paused = on;
    const b = $('btn-pause');
    b.textContent = on ? 'Resume' : 'Pause';
    b.setAttribute('aria-pressed', String(on));
    if (!on) {
      const ps = S.pendingState;
      S.pendingState = null;
      if (ps) applyState(ps);
      const pu = S.pendingUnits;
      S.pendingUnits = null;
      if (pu) applyUnits(pu);
    }
    tickStatus();
    Streams.update();
  }

  function setMotion(on) {
    S.motion = on;
    document.body.classList.toggle('no-motion', !on);
    const b = $('btn-motion');
    b.textContent = 'Motion: ' + (on ? 'on' : 'off');
    b.setAttribute('aria-pressed', String(on));
    try { localStorage.setItem('brawldash.motion', on ? '1' : '0'); } catch (e) { /* private mode */ }
    Treemap.motionChanged();
  }

  function bindControls() {
    $('btn-pause').addEventListener('click', () => setPaused(!S.paused));
    $('btn-motion').addEventListener('click', () => setMotion(!S.motion));
    $('warnings-toggle').addEventListener('click', () => {
      const ul = $('warnings-list');
      ul.hidden = !ul.hidden;
      $('warnings-toggle').setAttribute('aria-expanded', String(!ul.hidden));
    });
    document.addEventListener('keydown', (e) => {
      if (e.key !== 'Escape') return;
      if (!$('unit-card').hidden) { closeUnitCard(); return; }
      Treemap.toRoot();
    });
  }

  // ------------------------------------------------------------------ boot

  function init() {
    let stored = null;
    try { stored = localStorage.getItem('brawldash.motion'); } catch (e) { /* ignore */ }
    setMotion(stored == null ? !window.matchMedia('(prefers-reduced-motion: reduce)').matches : stored === '1');

    bindControls();
    Treemap.init();
    Sparkline.init();
    Streams.update();
    connectSSE();
    refreshState();
    setInterval(() => { if (!S.sseOpen) refreshState(); }, 15000);
    setInterval(tickStatus, 1000);
    document.addEventListener('visibilitychange', () => {
      if (!document.hidden) { refreshState(); }
    });
    tickStatus();
  }

  init();
})();
