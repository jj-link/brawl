#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" float fn_102_8330(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
