#include <types.h>
#pragma force_active on

extern "C" void fn_80282FE4(void *, void *, void *, void *, f32, f32, f32);

struct Vec4 {
    f32 v[4];
};

struct Obj {
    char pad0[0x10];
    Vec4 m[3];
    char pad1[0x90];
    f32 vx;
    f32 vy;
    f32 vz;
};

extern "C" void fn_802E4A20(Obj *arg0, void *arg1) {
    Vec4 p[3] __attribute__((aligned(16)));
    Vec4 s[3];
    Vec4 *m = arg0->m;
    f32 x = arg0->vx;
    f32 y = arg0->vy;
    f32 z = arg0->vz;

    s[2].v[0] = x;
    p[0].v[0] = x * arg0->m[0].v[0];
    s[2].v[1] = x;
    p[0].v[1] = x * arg0->m[0].v[1];
    s[2].v[2] = x;
    p[0].v[2] = x * arg0->m[0].v[2];
    s[2].v[3] = x;
    p[0].v[3] = x * arg0->m[0].v[3];

    s[1].v[0] = y;
    p[1].v[0] = y * arg0->m[1].v[0];
    s[1].v[1] = y;
    p[1].v[1] = y * arg0->m[1].v[1];
    s[1].v[2] = y;
    p[1].v[2] = y * arg0->m[1].v[2];
    s[1].v[3] = y;
    p[1].v[3] = y * arg0->m[1].v[3];

    s[0].v[0] = z;
    s[0].v[1] = z;
    s[0].v[2] = z;
    s[0].v[3] = z;
    p[2].v[0] = z * arg0->m[2].v[0];
    p[2].v[1] = z * arg0->m[2].v[1];
    p[2].v[2] = z * arg0->m[2].v[2];
    p[2].v[3] = z * arg0->m[2].v[3];

    fn_80282FE4(arg1, p, m, arg0, x, y, z);
}
