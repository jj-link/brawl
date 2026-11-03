#include <types.h>
#pragma force_active on
#pragma fp_contract on
struct V { f32 x, y, z, w; };
extern "C" void fn_802D9900(f32* a, const f32* b, s32 u1, s32 u2, s32 u3, V* c) {
    f32 n[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    n[0] = a[4];
    n[1] = a[5];
    n[2] = a[6];
    n[3] = a[7];
    f32 d = n[2] * b[6] + (n[0] * b[4] + n[1] * b[5]);
    s[0] = d * n[0];
    s[1] = d * n[1];
    s[2] = d * n[2];
    s[3] = d * n[3];
    n[0] -= s[0];
    n[1] -= s[1];
    n[2] -= s[2];
    n[3] -= s[3];
    c->x -= n[0];
    c->y -= n[1];
    c->z -= n[2];
    c->w -= n[3];
}