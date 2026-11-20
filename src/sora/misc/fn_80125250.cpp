#include <types.h>
#pragma force_active on

struct Src { int a,b,c; unsigned char d,e; };
struct Rec { unsigned char idx; float val; Src d; };
struct Ent { char pad[0x34]; Rec r; };
struct Obj { char pad0[0xc]; unsigned char f,mask; char pad1[0xf4-0xe]; Rec r; };

extern "C" void fn_80125250(Obj* o, int i, const Src* s, float v) {
    int a;
    Ent* e = (Ent*)((char*)o + i * 0x18);
    if (e->r.val >= v) {
        e->r.idx = i;
        a = s->a;
        e->r.val = v;
        int b = s->b;
        e->r.d.a = a;
        int c = s->c;
        e->r.d.b = b;
        unsigned char x = s->d;
        e->r.d.c = c;
        unsigned char y = s->e;
        e->r.d.d = x;
        e->r.d.e = y;
        o->mask |= 1 << (unsigned char)i;
        if (o->r.val >= v) o->r = e->r;
        if (i > 3) o->f |= 8;
    }
}
