#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma pool_data on

static inline float ClampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" float fn_118_8F8C(float value, float lower, float upper) {
    return ClampRange(value, lower, upper);
}
