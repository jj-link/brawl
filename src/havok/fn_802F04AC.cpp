#pragma force_active on
extern char lbl_804885E8[];

struct Sub {
    void *h; int i, j, k; int l; int x;
};

struct S {
    void *vtbl;
    unsigned short a;
    signed short b;
    int c, d, e, f;
    short g;
    Sub sub;
    char m;
    char n;
    int o, p, q, r, s, t, u, v;
};

static inline void initSub(Sub *s, S *q) {
    s->h = q;
    s->j = 0;
    s->k = 0;
    s->i = -1;
    s->x = 0;
}

extern "C" S *fn_802F04AC(S *p, S *q, char r) {
    Sub *s = &p->sub;
    p->b = 1;
    p->vtbl = lbl_804885E8;
    s->l = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = -0x2f;
    p->g = 0;
    initSub(s, q);
    p->m = r;
    p->o = 0;
    p->n = (char *)s - (char *)&s->x;
    p->q = 0;
    p->r = 0;
    p->s = 0x80000000;
    p->t = 0;
    p->u = 0;
    p->v = 0x80000000;
    s->l = (char *)p - (char *)s;
    if (q && q->a) q->b = q->b + 1;
    return p;
}
