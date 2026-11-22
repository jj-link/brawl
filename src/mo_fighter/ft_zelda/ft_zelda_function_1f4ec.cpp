#pragma always_inline on
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
#include <types.h>
#pragma force_active on
#pragma optimize_for_size on
struct NessTransitionVector { f32 x; f32 y; };
extern "C" {
extern const f32 lbl_104_rodata_158[5];
f32 fn_104_1F5A8(const NessTransitionVector*);
double fn_80400B30(double);
}
static inline f32 ClampRange(f32 value, f32 lo, f32 hi) {
    f32 t = value - lo;
    lo = nw4r::math::FSelect(t, value, lo);
    t = lo - hi;
    return nw4r::math::FSelect(t, hi, lo);
}
extern "C" f32 fn_104_1F4EC(const NessTransitionVector* a, const NessTransitionVector* b) {
    const f32* c = lbl_104_rodata_158;
    f32 bLength = fn_104_1F5A8(b);
    f32 aLength = fn_104_1F5A8(a);
    f32 product = aLength * bLength;
    if (c[3] == product) return c[3];
    f32 dot = a->x * b->x + a->y * b->y;
    f32 value = dot * rsqrtf(product);
    return (f32)fn_80400B30(ClampRange(value, c[4], c[0]));
}