#include <math.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern const float lbl_118_rodata_30;
extern const float lbl_118_rodata_78;
union Pair {
    struct { float x, y; } v;
    unsigned long long bits;
};
extern "C" unsigned long long fn_118_100CC(float angle, float scale) {
    Pair p;
    p.v.x = (float)cos(angle);
    p.v.y = (float)sin(angle);
    if ((float)(double)nw4r::math::FAbs(p.v.y) <= lbl_118_rodata_78)
        p.v.y = lbl_118_rodata_30;
    Pair out;
    out.v.x = p.v.x * scale;
    out.v.y = p.v.y * scale;
    return out.bits;
}