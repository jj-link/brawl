#include <types.h>
#pragma force_active on

struct Vec4 { f32 x, y, z, w; };
struct Marker { u32 tag; u8 kind; u8 pad[3]; };
struct Buffer { u32 x0; u32 x4; struct Marker *cursor; };
struct A { char pad0[2]; u8 flag; u8 idx; f32 t; };
struct B { char pad[0x44]; void *ptr; };
struct C { char pad[0x30]; struct Vec4 v; };
struct Local { struct Vec4 a; struct Vec4 b; f32 s; void *p; };

extern f32 lbl_805A3D90;
extern void fn_8028E080(struct Local *loc, struct B *b, struct Buffer *e);

void fn_8028A91C(struct A *a, struct B *b, struct C *c, struct Vec4 *d, struct Buffer *e) {
    f32 d3, d2, d1, d0, c3, c2, c1, c0, t;
    if (a->flag != 0 && (t = a->t) > lbl_805A3D90) {
        struct Local loc __attribute__((aligned(16)));
        struct Vec4 *v = d + a->idx;
        void *p;
        c0 = c->v.x;
        c1 = c->v.y;
        c2 = c->v.z;
        c3 = c->v.w;
        d0 = v->x;
        d1 = v->y;
        d2 = v->z;
        d3 = v->w;
        p = b->ptr;
        loc.a.x = c0;
        loc.a.y = c1;
        loc.a.z = c2;
        loc.a.w = c3;
        loc.b.x = d0;
        loc.b.y = d1;
        loc.b.z = d2;
        loc.b.w = d3;
        loc.s = t;
        loc.p = p;
        fn_8028E080(&loc, b, e);
        return;
    }
    {
        struct Marker *m = e->cursor;
        m->tag = 0x13020008;
        m->kind = 1;
        e->cursor = m + 1;
    }
}