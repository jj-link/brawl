#include <types.h>
#pragma force_active on

extern f32 lbl_805A1D28;

struct V4 {
    f32 x, y, z, w;

    void storeTail(f32* p) const {
        p[0] = y;
        p[1] = z;
        p[2] = w;
    }
} __attribute__((aligned(16)));

struct S {
    int a;
    short b, c, d, e;
    f32 f0 __attribute__((aligned(16)));
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9;
    f32 f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;

    S() {}
    S(const S& o) { *this = o; }

    S& operator=(const S& o) {
        a = o.a;
        b = o.b;
        c = o.c;
        d = o.d;
        e = o.e;
        f0 = o.f0;
        f1 = o.f1;
        f2 = o.f2;
        f3 = o.f3;
        f4 = o.f4;
        f5 = o.f5;
        f6 = o.f6;
        f7 = o.f7;
        f8 = o.f8;
        f9 = o.f9;
        f10 = o.f10;
        f11 = o.f11;
        f12 = o.f12;
        f13 = o.f13;
        f14 = o.f14;
        f15 = o.f15;
        f16 = o.f16;
        f17 = o.f17;
        f18 = o.f18;
        f19 = o.f19;
        return *this;
    }
};

struct O {
    char pad[0x10];
    S s;
};

struct M {
    char pad[8];
    O** objs;
};

struct V3 {
    f32 x, y, z;
};

extern "C" void fn_80097C94(M* m, int i, const V3* p) {
    O* o = m->objs[i];
    f32 z = p->z, y = p->y, x = p->x;
    S copy = o->s;
    V4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    o->s.f8 = x;
    v.w = 0.0f;
    v.storeTail(&o->s.f9);
    copy.f8 = v.x;
    copy.f9 = v.y;
    copy.f10 = v.z;
    copy.f11 = v.w;
    o->s.f18 = copy.f18;
    o->s.f19 = copy.f19;
}
