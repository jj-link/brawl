#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S { u16 a; char pad[6]; struct T *b; char c[4]; } S;
struct T { char pad[0x34]; void *p34; char pad2[0x230]; u16 *p268; };
extern int fn_803B9CE4(u16 *, void *, int, u32, u32 *);
extern int fn_803B9F7C(u16 *, void *, int, u32, u32 *);
extern int fn_803BA154(u16 *, void *, int, u32, u32 *);

int fn_803BA3D0(S *s, int a1, u32 n, u32 *out) {
    u32 sp;
    int r;
    u16 *q;
    s->b->p34 = s->c;
    *out = 0;
    if (s == 0) q = 0; else q = s->b->p268;
    r = fn_803B9CE4(q, s, a1, n, &sp);
    *out += sp;
    if (r != 0) return r;
    if (sp >= n) return 0;
    n -= sp;
    while (n >= *q) {
        r = fn_803B9F7C(q, s, a1 + *out, n, &sp);
        *out += sp;
        if (r != 0) return r;
        if (sp == 0) break;
        n -= sp;
    }
    r = fn_803BA154(q, s, a1 + *out, n, &sp);
    *out += sp;
    if (r != 0) return r;
    return 0;
}
