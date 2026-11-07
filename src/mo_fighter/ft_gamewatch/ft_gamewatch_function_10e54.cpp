#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma pool_data on

static inline float ClampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" float fn_107_10E54(float a, float b, float c) {
    return ClampRange(a, b, c);
}
