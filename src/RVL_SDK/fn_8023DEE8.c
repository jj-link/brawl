#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S { u16 f0, f2, f4, f6; u8 f8; } S;
extern char lbl_80529CF8[];
extern void *fn_8023DCCC(S *, S *, S *);
u8 fn_8023DEE8(u32 a, S *b, S *c, S *d) {
    S *p = 0;
    char *q;
    S *cur;
    int i;
    if (c && (c->f8 & 0x10)) {
        *d = *c;
        d->f8 &= ~0x10;
        return d->f8;
    }
    cur = b;
    q = lbl_80529CF8;
    for (i = 0; i < 2; i++, q += 8, cur++) {
        if (q[0x558] & 1) {
            if (!cur->f8) return 0;
            if (!fn_8023DCCC(p, cur, d)) return 0;
            p = d;
        }
    }
    if (!p) {
        if (c) *d = *c;
        else return 0;
    } else if (a == 0x80 && !fn_8023DCCC(c, p, d)) {
        return 0;
    }
    return d->f8;
}