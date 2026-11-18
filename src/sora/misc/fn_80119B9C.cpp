#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

struct Vec2 {
    f32 x, y;
};

struct Seg {
    Vec2 a, b;
    f32 extra;
};

extern "C" {
void fn_80111968(void* owner, Seg* seg, void* node, int zero);
void fn_800407A0(Seg* seg, f32* pt, Vec2* out);
f32 rsqrtf__Ff(f32 x);
extern f32 lbl_805A2960;
extern f32 lbl_805A298C;
}

static inline void minmax(register f32 a, register f32 b, f32& lo, f32& hi) {
    register f32 y, x;
    asm { ps_sub x, a, b }
    asm { ps_sub y, a, b }
    asm { ps_sel x, x, a, b }
    asm { ps_sel y, y, b, a }
    hi = x;
    lo = y;
}

extern "C" s32 fn_80119B9C(void* arg0, f32* arg1, void* arg2) {
    u8* self = (u8*)arg0;
    u8* a2 = (u8*)arg2;
    Seg seg;
    Vec2 t;
    Vec2 d;
    s32 ret = 0;
    f32 len;
    f32 f4;
    f32 f5;
    f32 f0, f2, f3;

    fn_80111968(*(void**)(a2 + 8), &seg, *(void**)a2, 0);
    fn_800407A0(&seg, arg1, &t);
    d.x = seg.b.x - seg.a.x;
    d.y = seg.b.y - seg.a.y;
    Vec2 e = d;
    f32 lenSq = e.x * e.x + e.y * e.y;
    if ((f32)(double)nw4r::math::FAbs(lenSq) <= lbl_805A298C) {
        len = lbl_805A2960;
    } else {
        len = lenSq * rsqrtf__Ff(lenSq);
    }
    f32 dxv = seg.b.x - seg.a.x;
    f5 = *(f32*)(self + 0x10C);
    f4 = dxv / len;
    *(f32*)(self + 0x2D8) = f4;
    minmax(seg.a.x, seg.b.x, f3, f2);

    {
        u8* inner = *(u8**)(self + 0x18);
        f5 = ((inner[0x73] >> 5) & 1) ? f5 : f5 * f4;
    }

    if (self[0x0E] & 2) {
        f0 = *arg1 + f5;
        *(f32*)(self + 0x2D4) = f0;
        if (f0 > f2) {
            *(f32*)(self + 0x2D4) = f2;
            ret = 1;
        }
    } else {
        f0 = *arg1 - f5;
        *(f32*)(self + 0x2D4) = f0;
        if ((self[0x0E] & 1) && f0 < f3) {
            ret = 1;
            *(f32*)(self + 0x2D4) = f3;
        }
    }
    return ret;
}
