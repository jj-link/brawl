#include <types.h>
#pragma force_active on
struct Tmp { u32 a,b,c,d,e,f,g,h,i; };
struct E { u8 v; u8 pad[15]; };
struct R { E e[64]; u8 pad[4]; };
struct P { u8 pad[0xfbc]; R r[1]; u8 pad2[0x3f8]; u32 a, row, x0, x1, b, x2,x3,x4, d,e,f,g; };
extern "C" Tmp fn_9_23A4(P* p) {
    Tmp t;
    t.a = p->a;
    t.b = p->b;
    t.c = (p->row == 0) ? 1 : 2;
    t.h = p->r[p->row].e[t.a].v;
    t.d = p->d;
    t.e = p->e;
    t.f = p->f;
    t.g = p->g;
    return t;
}
