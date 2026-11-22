#include <types.h>
#pragma force_active on

extern f32 lbl_805A1D28;

struct V4 {
    f32 x, y, z, w;
};

struct Data {
    s32 a;
    s16 b, c, d, e;
    V4 m0 __attribute__((aligned(16)));
    V4 m1, m2, pos, m4;

    Data() {}

    Data(const Data& o) {
        a = o.a;
        b = o.b;
        c = o.c;
        d = o.d;
        e = o.e;
        m0.x = o.m0.x;
        m0.y = o.m0.y;
        m0.z = o.m0.z;
        m0.w = o.m0.w;
        m1.x = o.m1.x;
        m1.y = o.m1.y;
        m1.z = o.m1.z;
        m1.w = o.m1.w;
        m2.x = o.m2.x;
        m2.y = o.m2.y;
        m2.z = o.m2.z;
        m2.w = o.m2.w;
        pos.x = o.pos.x;
        pos.y = o.pos.y;
        pos.z = o.pos.z;
        pos.w = o.pos.w;
        m4.x = o.m4.x;
        m4.y = o.m4.y;
        m4.z = o.m4.z;
        m4.w = o.m4.w;
    }
};

struct Ent {
    char pad[0x10];
    Data data;
};

struct Owner {
    char pad[8];
    Ent** ents;
};

struct V3 {
    f32 x, y, z;
};

extern "C" void fn_80097E94(Owner* o, s32 i, const V3* p) {
    Ent* e = o->ents[i];
    f32 z = p->z, y = p->y, x = p->x;
    Data d(e->data);
    V4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = 0.0f;
    e->data.pos = v;
    d.pos = v;
    e->data.m4.z = d.m4.z;
    e->data.m4.w = d.m4.w;
}
