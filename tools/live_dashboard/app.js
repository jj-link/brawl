/* Brawl Decomp — Live Dashboard
 * Standalone frontend. No frameworks, no build step, no external assets.
 * GET /api/state and /api/units preserve project progress; /api/events carries
 * state snapshots, /api/live relays session output, /api/streams is opt-in history.
 * The sticky banner shows the same completion percentage and precision as the hero.
 * Updates always run live; the banner reports connection and build-report age.
 * Text is never trusted as HTML; image blocks use only session-provided raster data.
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
    lastStateAt: 0,
    everConnected: false,
    sseOpen: false,
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
      applyUnits(j);
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
      refreshUnits();
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
    setText('foot-meta', s.updatedAt ? 'server state: ' + new Date(s.updatedAt).toLocaleString() : '');
  }

  function tickStatus() {
    const now = Date.now();
    const ageS = S.lastStateAt ? Math.floor((now - S.lastStateAt) / 1000) : null;

    const conn = $('pill-conn');
    let cls, txt;
    if (S.sseOpen && (ageS == null || ageS <= 15)) { cls = 'is-live'; txt = 'Connected'; }
    else if (S.sseOpen) { cls = 'is-warn'; txt = 'lagging · ' + fmtAge(ageS); }
    else if (ageS == null) { cls = 'is-down'; txt = 'connecting…'; }
    else { cls = 'is-down'; txt = 'stale · ' + fmtAge(ageS) + ' old'; }
    conn.className = 'pill ' + cls;
    setText('conn-text', txt);

    const rep = $('pill-report');
    const rAt = S.state && S.state.reportUpdatedAt ? Date.parse(S.state.reportUpdatedAt) : NaN;
    if (isFinite(rAt)) {
      const a = Math.max(0, Math.floor((now - rAt) / 1000));
      setText('report-age', a < 5 ? 'just now' : fmtAge(a) + ' ago');
      rep.classList.toggle('is-old', a > 30 * 60);
      rep.title = 'Build report generated ' + new Date(rAt).toLocaleString();
    } else {
      setText('report-age', 'age unknown');
      rep.classList.add('is-old');
      rep.title = 'report timestamp unavailable';
    }

    const stale = ageS != null && (ageS > STATE_STALE_S || !S.sseOpen);
    document.body.classList.toggle('is-stale', stale);
    $('treemap-wrap').dataset.flag = stale ? 'stale data' : '';

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
    if (prev === null || !S.motion || prev === target) {
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
    setText('banner-pct', p.available ?
      (Number(p.percent) || 0).toFixed(p.precision === 6 ? 6 : 3) + '%' : '—');
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
      (u.acceptedBytes != null ? ' · ' + Number(u.acceptedBytes).toLocaleString() + ' report-accepted bytes' : '');
    setText('map-provenance', text);
    $('map-provenance').classList.toggle('is-old', !!u.stale);
    $('pill-report').title = 'Unit-map report only; accepted totals use ' + (p.source || 'report') + '. ' + (reportAt || 'Timestamp unknown');
  }

  // ------------------------------------------------------------------ sparkline

  const Sparkline = (() => {
    const canvas = $('sparkline');
    const ctx = canvas.getContext('2d');
    let data = [];
    let history = [];
    let rangeHours = 0;
    let windowStart = 0, windowEnd = 0;
    let sig = null;
    let hoverX = null;

    function update(s) {
      const h = s && Array.isArray(s.history) ? s.history : [];
      const nsig = h.map(p => p.at + '|' + p.acceptedBytes).join(';');
      if (nsig !== sig) {
        sig = nsig;
        history = h
          .map((p) => ({ t: tsOf(p.at), v: Number(p.acceptedBytes) || 0 }))
          .filter((p) => p.t > 0)
          .sort((a, b) => a.t - b.t);
      } else if (!rangeHours) return;
      selectRange();
    }

    function selectRange() {
      // Fixed ranges use the current clock; All preserves the full supplied history.
      windowEnd = Date.now();
      windowStart = windowEnd - rangeHours * 60 * 60 * 1000;
      data = rangeHours ? history.filter(p => p.t >= windowStart && p.t <= windowEnd) : history;
      if (rangeHours) {
        // Carry known values to the display boundaries, never invent observations.
        const before = history.findLast(p => p.t <= windowStart);
        if (before && data[0]?.t !== windowStart) {
          data.unshift({ t: windowStart, v: before.v, observedAt: before.t });
        }
        const last = data.at(-1);
        if (last && last.t < windowEnd) {
          data.push({ t: windowEnd, v: last.v, observedAt: last.observedAt ?? last.t });
        }
      }
      canvas.setAttribute('aria-label', 'Accepted bytes history — ' + (rangeHours ? rangeHours + 'h' : 'All'));
      rangeLabel();
      draw();
    }

    for (const button of document.querySelectorAll('.spark-timescales button')) {
      button.addEventListener('click', () => {
        rangeHours = Number(button.dataset.hours);
        hoverX = null;
        for (const option of document.querySelectorAll('.spark-timescales button')) {
          option.setAttribute('aria-pressed', String(option === button));
        }
        selectRange();
      });
    }

    function rangeLabel() {
      let txt = '';
      if (data.length) {
        const vs = data.map((p) => p.v);
        const mn = Math.min(...vs), mx = Math.max(...vs);
        const d = data[data.length - 1].v - data[0].v;
        const span = !rangeHours && data.length > 1 ? fmtAge((data[data.length - 1].t - data[0].t) / 1000) : null;
        txt = fmtBytes(mn) + ' – ' + fmtBytes(mx) +
          (data.length > 1 ? ' · ' + (d >= 0 ? '+' : '−') + fmtBytes(Math.abs(d)) + (span ? ' over ' + span : '') : '');
      }
      // Fixed windows describe the selected period, not the spacing of samples.
      if (rangeHours) txt += (txt ? ' · ' : '') + 'last ' + rangeHours + 'h';
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
        ctx.fillText(rangeHours ? 'no history in this range' : 'no history yet', w / 2, h / 2);
        ctx.textAlign = 'left';
        return;
      }

      const vs = data.map((p) => p.v);
      let mn = Math.min(...vs), mx = Math.max(...vs);
      if (mx - mn < 1) { mx = mn + 1; }
      const t0 = rangeHours ? windowStart : data[0].t;
      const t1 = rangeHours ? windowEnd : data[data.length - 1].t;
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
        const x = rangeHours ? X(data[0].t) : padL + iw / 2, y = Y(data[0].v);
        ctx.fillStyle = '#ffc464';
        ctx.beginPath(); ctx.arc(x, y, 2.5, 0, Math.PI * 2); ctx.fill();
        return;
      }

      // Hold each recorded total until the next checkpoint; never interpolate.
      const firstX = X(data[0].t), firstY = Y(data[0].v);
      let previousY = firstY;
      // area fill
      const grad = ctx.createLinearGradient(0, padT, 0, h - padB);
      grad.addColorStop(0, 'rgba(242, 163, 60, 0.30)');
      grad.addColorStop(1, 'rgba(242, 163, 60, 0)');
      ctx.beginPath();
      ctx.moveTo(firstX, h - padB);
      ctx.lineTo(firstX, firstY);
      for (let i = 1; i < data.length; i++) {
        const x = X(data[i].t), y = Y(data[i].v);
        ctx.lineTo(x, previousY);
        ctx.lineTo(x, y);
        previousY = y;
      }
      ctx.lineTo(X(data[data.length - 1].t), h - padB);
      ctx.closePath();
      ctx.fillStyle = grad;
      ctx.fill();

      // line
      ctx.beginPath();
      ctx.moveTo(firstX, firstY);
      previousY = firstY;
      for (let i = 1; i < data.length; i++) {
        const x = X(data[i].t), y = Y(data[i].v);
        ctx.lineTo(x, previousY);
        ctx.lineTo(x, y);
        previousY = y;
      }
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
        // Follow cursor time, holding the last known total until a checkpoint.
        const x = Math.max(padL, Math.min(w - padR, hoverX));
        const t = t0 + ((x - padL) / iw) * (t1 - t0);
        let best = data.length - 1;
        while (best >= 0 && data[best].t > t) best--;
        if (best < 0) return; // no recorded total before this time
        const p = data[best], y = Y(p.v);
        ctx.strokeStyle = 'rgba(237, 230, 216, 0.25)';
        ctx.beginPath(); ctx.moveTo(x, padT); ctx.lineTo(x, h - padB); ctx.stroke();
        ctx.fillStyle = '#ede6d8';
        ctx.beginPath(); ctx.arc(x, y, 3, 0, Math.PI * 2); ctx.fill();
        const age = fmtAge((Date.now() - t) / 1000);
        const label = fmtBytes(p.v) + ' · ' + (age === 'now' ? age : age + ' ago');
        ctx.font = '10px ' + MONO;
        const tw = ctx.measureText(label).width;
        let lx = x + 8; if (lx + tw > w - padR) lx = x - tw - 8;
        // Place high-point labels below the point, inside the canvas.
        const ly = y >= 18 ? y - 16 : y + 8;
        ctx.fillStyle = 'rgba(12, 10, 8, 0.9)';
        ctx.fillRect(lx - 3, ly, tw + 6, 13);
        ctx.fillStyle = '#ede6d8';
        ctx.fillText(label, lx, ly + 7);
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

    return { init, setData, pulse, reveal, toRoot };
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
    if (s === 'completed' || s === 'stopped') return 'historical';
    if (s === 'waiting') return 'waiting';
    return 'active';
  }

  const keyOf = (a) => String(a.id ?? a.name ?? '');

  // One simultaneously visible terminal per worker. Live and recorded session
  // output share text/thinking/tool/block rendering. Retained DOM and text nodes
  // keep selection and reading stable; retention removes entries, not their text.
  // Group the configured OpenAI and Spark model routes without rebuilding panes.
  const Streams = (() => {
    const grid = $('streams-grid');
    // Local model sections lead; OpenAI stays last, including when Other is visible.
    const sections = ['Spark 1 · Qwen', 'Spark 2 + 3 · GLM', 'Other', 'OpenAI'].map((title, i) => {
      const count = el('span', { class: 'count' });
      const heading = el('h3', { class: 'stream-group-title', attrs: { id: 'stream-group-' + i } },
        document.createTextNode(title + ' '), count);
      const body = el('div', { class: 'streams-grid' });
      const node = el('section', { class: 'stream-group', attrs: { 'aria-labelledby': heading.id } }, heading, body);
      node.hidden = true;
      grid.append(node);
      return { node, body, count };
    });

    function sectionOf(a) {
      const model = String(a.model || '').toLowerCase();
      if (model.includes('qwen')) return 0;
      if (model.includes('glm')) return 1;
      if (model.includes('gpt-') || model.startsWith('openai')) return 3;
      if (!model) {
        if (a.definition === 'spark1-qwen') return 0;
        if (a.definition === 'glm-reconstruction') return 1;
        if (a.definition === 'sol61-reconstruction' || a.definition === 'astra-reconstruction') return 3;
      }
      return 2;
    }
    const panels = new Map();
    const recordedAgents = new Map();
    const liveAgents = new Map();
    const liveItems = new Map();
    const itemsByAgent = new Map();
    const historyItems = new Map();
    const historyLoaded = new Map();
    const dirtyAgents = new Set();
    const dirtyPanels = new Map();
    const agentFields = ['name', 'state', 'model', 'definition', 'target', 'correction', 'observed', 'active'];
    let connected = false, source = null, retryTimer = null, frame = 0;
    let flushing = false, gridReady = false;
    let connectionError = 'Connecting to the owning runner observer…';
    let showHistory = false, historyBusy = false, historyAgain = false;
    let historyGeneration = 0, historyWanted = false;
    let historyStateRevision;
    try { showHistory = localStorage.getItem('brawldash.streamHistory') === '1'; } catch (_) {}

    function writeText(node, text) {
      if (node.textContent !== text) node.textContent = text;
    }

    function status() {
      writeText($('streams-status'), connected ? 'Connected' : 'Disconnected — ' + connectionError);
      $('streams-status').classList.toggle('is-error', !connected);
    }

    function requestFlush() {
      if (!frame && !flushing) frame = requestAnimationFrame(flush);
    }

    function dirtyPanel(key, full = false, itemId = null) {
      let job = dirtyPanels.get(key);
      if (!job) {
        job = { full: false, header: false, empty: false, items: new Set() };
        dirtyPanels.set(key, job);
      }
      job.full ||= full;
      if (itemId != null) job.items.add(itemId);
      requestFlush();
      return job;
    }

    function dirtyAgent(key) {
      dirtyAgents.add(key);
      requestFlush();
    }

    function sameAgent(a, b) {
      return !!a && !!b && agentFields.every(field => a[field] === b[field]);
    }

    function syncRecordedAgents() {
      const keys = new Set();
      for (const a of S.agents) {
        if (a.name === 'main') continue;
        const key = keyOf(a);
        keys.add(key);
        if (!sameAgent(recordedAgents.get(key), a)) dirtyAgent(key);
        recordedAgents.set(key, a);
      }
      for (const key of recordedAgents.keys()) {
        if (!keys.has(key)) { recordedAgents.delete(key); dirtyAgent(key); }
      }
    }

    function mergedAgent(key) {
      const recorded = recordedAgents.get(key), live = liveAgents.get(key);
      if (!recorded && !live) return null;
      // Runner turn states are not assignment outcomes. Reliable current
      // membership from /api/state also takes precedence over retained metadata.
      return { ...recorded, ...live, state: recorded?.state ?? live?.state,
        active: typeof recorded?.active === 'boolean' ? recorded.active : live?.active };
    }

    function isVisible(a) {
      return showHistory || a.active === true;
    }

    function setConnected(on) {
      if (connected === on) return;
      connected = on;
      for (const [key, panel] of panels) {
        if (!panel.visible) continue;
        const job = dirtyPanel(key);
        job.header = job.empty = true;
      }
    }

    async function diagnoseConnection(failedSource) {
      let message;
      try {
        const response = await fetch('/api/live-status', { cache: 'no-store' });
        const data = await response.json();
        message = data.error || 'Observer is available; reconnecting to its output stream.';
      } catch (error) {
        message = 'Cannot read observer status: ' + error.message;
      }
      if (connected || (source && source !== failedSource)) return;
      connectionError = message;
      status();
    }

    function createPanel(a) {
      const key = keyOf(a);
      const name = el('span', { class: 'stream-heading' });
      const state = el('span', { class: 'stream-state' });
      const identity = el('div', { class: 'stream-identity' });
      identity.title = key;
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
      return { key, node, name, state, identity, count, log, rows: new Map(),
        agent: a, visible: true, position: null };
    }

    function row(item, historical) {
      const label = el('span');
      const body = el('div', { class: 'stream-body' });
      const node = el('article', { class: 'stream-entry' + (historical ? ' stream-history' : ''),
        attrs: { 'data-source': historical ? 'history' : 'live', 'data-item': String(item.id) } },
        el('div', { class: 'stream-entry-head' }, label), body);
      return { node, label, body, parts: new Map(), complete: null };
    }

    function updateText(part, text) {
      const oldText = part.renderedText;
      if (oldText === text) return;
      // Append deltas to the existing node; edits replace only the changed span.
      if (text.startsWith(oldText)) part.textNode.appendData(text.slice(oldText.length));
      else {
        let start = 0, oldEnd = oldText.length, newEnd = text.length;
        while (start < oldEnd && start < newEnd && oldText[start] === text[start]) start++;
        while (oldEnd > start && newEnd > start && oldText[oldEnd - 1] === text[newEnd - 1]) {
          oldEnd--; newEnd--;
        }
        part.textNode.replaceData(start, oldEnd - start, text.slice(start, newEnd));
      }
      part.renderedText = text;
    }

    function structuredText(value) {
      return typeof value === 'string' ? value : JSON.stringify(value, null, 2) ?? '';
    }

    function contentParts(item) {
      const parts = [], texts = [];
      if (item.args !== undefined) {
        parts.push({ key: 'args', title: 'Arguments', text: structuredText(item.args) });
      }
      if (Array.isArray(item.blocks) && item.blocks.length) {
        item.blocks.forEach((block, index) => {
          const part = { key: 'block:' + index, title: '' };
          if (block?.type === 'text') part.text = String(block.text ?? '');
          else if (block?.type === 'thinking' || block?.type === 'reasoning') {
            part.title = item.channel === 'thinking' ? '' : 'Thinking';
            part.text = String(block.thinking ?? block.reasoning ?? block.text ?? '');
          } else if (block?.type === 'image' && typeof block.data === 'string' &&
            /^image\/(?:png|jpeg|gif|webp|bmp|avif)$/i.test(block.mimeType || '')) {
            part.title = 'Image · ' + block.mimeType;
            part.image = 'data:' + block.mimeType + ';base64,' + block.data;
          } else {
            // Keep unsupported visible content readable, rather than drop it.
            part.title = String(block?.type || 'Content');
            part.text = structuredText(block);
          }
          if (part.text !== undefined) texts.push(part.text);
          parts.push(part);
        });
      } else {
        const text = String(item.text ?? '');
        texts.push(text);
        if (text) parts.push({ key: 'block:0', title: '', text });
      }
      if (item.details !== undefined) {
        const details = structuredText(item.details);
        const duplicate = texts.some(text => {
          if (text === details) return true;
          try { return JSON.stringify(JSON.parse(text)) === JSON.stringify(item.details); }
          catch (_) { return false; }
        });
        if (!duplicate) parts.push({ key: 'details', title: 'Details', text: details });
      }
      if (item.errorMessage && !texts.includes(String(item.errorMessage))) {
        parts.push({ key: 'error', title: 'Error', text: String(item.errorMessage) });
      }
      return parts;
    }

    function renderContent(entry, item) {
      const parts = contentParts(item), keys = new Set(parts.map(part => part.key));
      for (const [key, part] of entry.parts) {
        if (!keys.has(key)) { part.node.remove(); entry.parts.delete(key); }
      }
      let cursor = entry.body.firstElementChild;
      for (const spec of parts) {
        const kind = spec.image ? 'image' : 'text';
        let part = entry.parts.get(spec.key);
        if (part && part.kind !== kind) {
          if (part.node === cursor) cursor = cursor.nextElementSibling;
          part.node.remove(); entry.parts.delete(spec.key); part = null;
        }
        if (!part) {
          const title = el('div', { class: 'stream-part-label' });
          const node = el('div', { class: 'stream-part' }, title);
          part = { node, title, kind, renderedText: '' };
          if (kind === 'image') {
            part.image = el('img', { class: 'stream-image', attrs: { alt: 'Session output image' } });
            node.append(part.image);
          } else {
            part.textNode = document.createTextNode('');
            node.append(el('pre', { class: 'stream-text' }, part.textNode));
          }
          entry.parts.set(spec.key, part);
        }
        writeText(part.title, spec.title);
        part.title.hidden = !spec.title;
        if (kind === 'image') {
          if (part.source !== spec.image) { part.image.src = spec.image; part.source = spec.image; }
        } else updateText(part, spec.text);
        if (part.node === cursor) cursor = cursor.nextElementSibling;
        else entry.body.insertBefore(part.node, cursor);
      }
    }

    function renderHeader(panel) {
      const a = panel.agent, state = stateOf(a.state);
      writeText(panel.name, String(a.name || a.id));
      writeText(panel.state, (state === 'completed' ? 'Completed' : state) +
        (a.observed && !connected ? ' · last observed' : ''));
      writeText(panel.identity, [a.model, a.definition, a.target,
        a.correction != null ? 'corrections: ' + a.correction : null].filter(Boolean).join(' · '));
      const label = String(a.name || a.id) + ' terminal output';
      if (panel.log.getAttribute('aria-label') !== label) panel.log.setAttribute('aria-label', label);
    }

    function renderRow(entry, item, historical) {
      const source = historical ? 'Recorded history' : 'Live';
      const tool = item.kind === 'tool' || item.kind === 'tool_call' || item.kind === 'tool_result';
      const category = tool ? 'tool · ' + (item.tool || 'output') :
        item.channel === 'thinking' ?
          (item.blocks?.some(block => block?.summary === true) ? 'thinking (summary)' : 'thinking') :
        (item.role === 'peer' || item.customType === 'irc:incoming') ?
          'peer text' + (item.sender ? ' · ' + item.sender : '') :
        item.role === 'user' ? 'user text' :
        item.kind === 'lifecycle' ? 'lifecycle' : 'text';
      const outcome = tool ? (historical && !item.complete ? 'arguments' :
        item.status || (item.complete ? (item.isError ? 'failed' : 'complete') : 'running')) :
        (item.isError ? 'failed' : item.complete ? 'complete' : 'generating');
      writeText(entry.label, source + ' · ' + category + ' · ' + outcome +
        (item.stopReason ? ' · ' + item.stopReason : '') +
        (historical && item.at ? ' · ' + item.at : ''));
      entry.node.dataset.channel = item.channel || (tool ? 'tool' : 'text');
      renderContent(entry, item);
      const complete = !!item.complete;
      if (entry.complete !== complete) {
        entry.node.dataset.complete = String(complete);
        entry.complete = complete;
      }
    }

    function renderEmpty(panel) {
      if (panel.rows.size) { panel.empty?.remove(); return; }
      if (!panel.empty) panel.empty = el('div', { class: 'stream-empty' });
      writeText(panel.empty, connected ? 'Waiting for worker output.' :
        'Live observer disconnected. No retained worker output; Show history loads recorded output.');
      if (panel.empty.parentNode !== panel.log) panel.log.append(panel.empty);
    }

    function prepareRows(panel, job) {
      if (!job.full) return;
      const live = Array.from(itemsByAgent.get(panel.key)?.values() || [])
        .filter(record => record.visible)
        .sort((a, b) => a.time - b.time || a.sequence - b.sequence);
      const historical = showHistory ? (historyItems.get(panel.key) || []) : [];
      job.list = [
        ...historical.map(item => ({ key: 'history:' + item.id, item, historical: true })),
        ...live.map(record => ({ key: 'live:' + record.item.id, item: record.item, historical: false }))
      ];
      job.keys = new Set(job.list.map(entry => entry.key));
      job.count = live.length + ' retained live entries' +
        (showHistory ? ' · ' + historical.length + ' recorded' : '');
    }

    function renderRows(panel, job) {
      if (job.full) {
        for (const [key, entry] of panel.rows) {
          if (!job.keys.has(key)) { entry.node.remove(); panel.rows.delete(key); }
        }
        let cursor = panel.log.firstElementChild;
        for (const { key, item, historical } of job.list) {
          let entry = panel.rows.get(key);
          if (!entry) { entry = row(item, historical); panel.rows.set(key, entry); }
          renderRow(entry, item, historical);
          if (entry.node === cursor) cursor = cursor.nextElementSibling;
          else panel.log.insertBefore(entry.node, cursor);
        }
        writeText(panel.count, job.count);
      } else {
        for (const id of job.items) {
          const entry = panel.rows.get('live:' + id), record = liveItems.get(id);
          if (entry && record) renderRow(entry, record.item, false);
        }
      }
      if (job.full || job.empty) renderEmpty(panel);
    }

    function readPosition(panel, job) {
      if (!panel.node.isConnected) return panel.position || { follow: true, top: 0 };
      const log = panel.log, top = log.scrollTop;
      if (log.scrollHeight - top - log.clientHeight < 35) return { follow: true, top };
      // Rows are ordered vertically. Locate the viewport anchor without
      // measuring every retained row on each text delta.
      const children = log.children;
      let lo = 0, hi = children.length;
      while (lo < hi) {
        const mid = (lo + hi) >>> 1, node = children[mid];
        if (node.offsetTop + node.offsetHeight > top) hi = mid;
        else lo = mid + 1;
      }
      let anchor = children[lo];
      if (job?.keys) {
        const survives = node => job.keys.has(node.dataset.source + ':' + node.dataset.item);
        while (anchor && !survives(anchor)) anchor = anchor.nextElementSibling;
        if (!anchor) {
          anchor = children[Math.min(lo, children.length - 1)];
          while (anchor && !survives(anchor)) anchor = anchor.previousElementSibling;
        }
      }
      return { follow: false, top, anchor, offset: anchor ? anchor.offsetTop - top : 0 };
    }

    function flush() {
      frame = 0;
      flushPending();
    }

    function flushPending() {
      flushing = true;
      try { renderPending(); }
      finally { flushing = false; }
    }

    function renderPending() {
      let gridChanged = !gridReady;
      gridReady = true;
      const visibilityChanges = new Set(), removed = [];
      for (const key of dirtyAgents) {
        const a = mergedAgent(key);
        let panel = panels.get(key);
        if (!a) {
          if (panel) {
            visibilityChanges.add(panel);
            panel.visible = false;
            removed.push(panel);
            panels.delete(key);
            dirtyPanels.delete(key);
            gridChanged = true;
          }
          continue;
        }
        const visible = isVisible(a);
        if (!panel) {
          if (!visible) continue;
          panel = createPanel(a);
          panels.set(key, panel);
          dirtyPanel(key, true).header = true;
          visibilityChanges.add(panel);
          gridChanged = historyWanted = true;
        } else {
          if (panel.visible !== visible) {
            panel.visible = visible;
            visibilityChanges.add(panel);
            gridChanged = true;
            if (visible) { dirtyPanel(key, true); historyWanted = true; }
          }
          if (visible && (String(panel.agent.name || panel.agent.id) !== String(a.name || a.id) ||
              sectionOf(panel.agent) !== sectionOf(a))) {
            gridChanged = true;
            visibilityChanges.add(panel);
          }
          panel.agent = a;
          if (visible) dirtyPanel(key).header = true;
        }
      }
      dirtyAgents.clear();
      const jobs = new Map();
      for (const [key, job] of dirtyPanels) {
        const panel = panels.get(key);
        if (!panel) continue;
        prepareRows(panel, job);
        jobs.set(panel, job);
      }
      dirtyPanels.clear();
      // All viewport reads precede DOM writes, and all post-write layout reads
      // precede scroll writes. Only panes whose contents change need anchoring.
      const positions = new Map();
      for (const panel of visibilityChanges) positions.set(panel, readPosition(panel, jobs.get(panel)));
      for (const [panel, job] of jobs) {
        if (panel.visible && (job.full || job.items.size || job.empty) && !positions.has(panel)) {
          positions.set(panel, readPosition(panel, job));
        }
      }
      for (const [panel, position] of positions) panel.position = position;
      if (gridChanged) {
        for (const panel of removed) panel.node.remove();
        const visible = [];
        for (const panel of panels.values()) {
          if (panel.visible) visible.push(panel);
          else panel.node.remove();
        }
        visible.sort((a, b) => String(a.agent.name || a.agent.id).localeCompare(String(b.agent.name || b.agent.id)));
        for (let i = 0; i < sections.length; i++) {
          const section = sections[i];
          let cursor = section.body.firstElementChild, count = 0;
          for (const panel of visible) {
            if (sectionOf(panel.agent) !== i) continue;
            count++;
            if (panel.node === cursor) cursor = cursor.nextElementSibling;
            else section.body.insertBefore(panel.node, cursor);
          }
          section.node.hidden = count === 0;
          writeText(section.count, '· ' + count);
        }
        writeText($('streams-count'), '· ' + visible.length);
      }
      for (const [panel, job] of jobs) {
        if (job.header) renderHeader(panel);
        renderRows(panel, job);
      }
      const scrolls = [];
      for (const [panel, position] of positions) {
        if (!panel.visible || !panel.node.isConnected) continue;
        const top = position.follow ? panel.log.scrollHeight :
          position.anchor?.parentNode === panel.log ? position.anchor.offsetTop - position.offset : position.top;
        scrolls.push([panel.log, top]);
      }
      for (const [log, top] of scrolls) log.scrollTop = top;
      if (historyWanted) { historyWanted = false; loadHistory(); }
    }

    function putItem(item) {
      const id = String(item.id), key = String(item.agentId), old = liveItems.get(id);
      const record = { item, visible: !!String(item.text || '') ||
        !!item.blocks?.length || item.args !== undefined || item.details !== undefined ||
        item.kind === 'tool' || !!item.errorMessage || !!item.stopReason,
        time: tsOf(item.at), sequence: Number(item.sequence) || 0 };
      if (old && String(old.item.agentId) !== key) {
        const oldKey = String(old.item.agentId), items = itemsByAgent.get(oldKey);
        items?.delete(id);
        if (!items?.size) itemsByAgent.delete(oldKey);
        dirtyPanel(oldKey, true);
      }
      let items = itemsByAgent.get(key);
      if (!items) { items = new Map(); itemsByAgent.set(key, items); }
      items.set(id, record);
      liveItems.set(id, record);
      const structural = !old || String(old.item.agentId) !== key ||
        old.visible !== record.visible || old.time !== record.time || old.sequence !== record.sequence;
      if (structural) dirtyPanel(key, true);
      else if (record.visible && ['text', 'blocks', 'args', 'details', 'channel', 'role',
        'sender', 'customType', 'kind', 'tool', 'complete', 'isError', 'status', 'stopReason', 'errorMessage']
        .some(field => old.item[field] !== item[field])) dirtyPanel(key, false, id);
    }

    function removeItem(id) {
      const record = liveItems.get(id);
      if (!record) return;
      const key = String(record.item.agentId), items = itemsByAgent.get(key);
      liveItems.delete(id);
      items?.delete(id);
      if (!items?.size) itemsByAgent.delete(key);
      if (record.visible) dirtyPanel(key, true);
    }

    function applySnapshot(data) {
      for (const key of liveAgents.keys()) dirtyAgent(key);
      for (const key of itemsByAgent.keys()) dirtyPanel(key, true);
      liveAgents.clear();
      liveItems.clear();
      itemsByAgent.clear();
      for (const a of data.agents || []) { liveAgents.set(keyOf(a), a); dirtyAgent(keyOf(a)); }
      for (const item of data.items || []) putItem(item);
    }

    function connect() {
      if (source || retryTimer) return;
      const liveSource = new EventSource('/api/live');
      source = liveSource;
      const current = () => source === liveSource;
      liveSource.addEventListener('snapshot', event => {
        if (!current()) return;
        try {
          const data = JSON.parse(event.data);
          setConnected(true);
          connectionError = '';
          applySnapshot(data);
          status();
        } catch (e) { logErr('live snapshot', e); }
      });
      liveSource.addEventListener('agent', event => {
        if (!current()) return;
        try {
          const a = JSON.parse(event.data), key = keyOf(a);
          if (!sameAgent(liveAgents.get(key), a)) dirtyAgent(key);
          liveAgents.set(key, a);
        } catch (e) { logErr('live agent', e); }
      });
      liveSource.addEventListener('text', event => {
        if (!current()) return;
        try { putItem(JSON.parse(event.data)); }
        catch (e) { logErr('live text', e); }
      });
      liveSource.addEventListener('evict', event => {
        if (!current()) return;
        try {
          const data = JSON.parse(event.data);
          if (data.itemId != null) removeItem(String(data.itemId));
          else {
            const key = String(data.agentId), items = itemsByAgent.get(key);
            liveAgents.delete(key);
            if (items) for (const id of items.keys()) liveItems.delete(id);
            itemsByAgent.delete(key);
            dirtyAgent(key);
            dirtyPanel(key, true);
          }
        } catch (e) { logErr('live retention', e); }
      });
      liveSource.addEventListener('error', () => {
        if (!current()) return;
        setConnected(false);
        connectionError = 'Connection lost; checking observer status…';
        diagnoseConnection(liveSource);
        status();
        // Closed HTTP 503 streams need an explicit retry; established SSE
        // streams use EventSource's native reconnect and authoritative snapshot.
        if (liveSource.readyState === EventSource.CLOSED) {
          liveSource.close(); source = null;
          retryTimer = setTimeout(() => { retryTimer = null; connect(); }, 3000);
        }
      });
    }

    async function loadHistory() {
      if (!showHistory) return;
      const revision = S.state?.streamRevision;
      const agents = Array.from(panels.values()).filter(panel => panel.visible &&
        (!historyLoaded.has(panel.key) || historyLoaded.get(panel.key) !== revision)).map(panel => panel.key);
      if (!agents.length) return;
      if (historyBusy) { historyAgain = true; return; }
      historyBusy = true;
      const generation = historyGeneration;
      try {
        // Bounded per-agent batches avoid starving less recent workers.
        for (let i = 0; i < agents.length && showHistory && generation === historyGeneration; i += 4) {
          await Promise.all(agents.slice(i, i + 4).map(async key => {
            const result = await fetchJSON('/api/streams?agent=' + encodeURIComponent(key) + '&limit=200');
            if (!showHistory || generation !== historyGeneration) return;
            historyItems.set(key, (result.items || []).sort((a, b) => tsOf(a.at) - tsOf(b.at) || a.sequence - b.sequence));
            historyLoaded.set(key, revision);
            dirtyPanel(key, true);
          }));
        }
      } catch (e) {
        if (showHistory && generation === historyGeneration) {
          logErr('recorded history', e);
          writeText($('streams-status'), 'Recorded history unavailable: ' + e.message);
        }
      } finally {
        historyBusy = false;
        if (historyAgain) { historyAgain = false; loadHistory(); }
      }
    }

    function update() {
      syncRecordedAgents();
      const revision = S.state?.streamRevision;
      if (revision !== historyStateRevision) {
        historyStateRevision = revision;
        historyGeneration++;
      }
      connect();
      historyWanted = true;
      requestFlush();
      const historyButton = $('streams-history'), pressed = String(showHistory);
      if (historyButton.getAttribute('aria-pressed') !== pressed) historyButton.setAttribute('aria-pressed', pressed);
      writeText(historyButton, showHistory ? 'Hide history' : 'Show history');
      status();
    }

    $('streams-history').addEventListener('click', () => {
      showHistory = !showHistory;
      historyGeneration++;
      historyLoaded.clear();
      for (const key of new Set([...recordedAgents.keys(), ...liveAgents.keys()])) dirtyAgent(key);
      for (const key of panels.keys()) dirtyPanel(key, true);
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

  function bindControls() {
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
    S.motion = !window.matchMedia('(prefers-reduced-motion: reduce)').matches;
    document.body.classList.toggle('no-motion', !S.motion);

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
