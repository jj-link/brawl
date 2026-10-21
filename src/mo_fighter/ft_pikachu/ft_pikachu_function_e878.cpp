#include <math.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma scheduling off
#pragma peephole off
#pragma opt_propagation off
#pragma opt_lifetimes off
extern "C" const float lbl_98_rodata_10[];
inline float clampValue(float value, float lower, float upper) {
    float t = value - lower;
    lower = nw4r::math::FSelect(t, value, lower);
    t = lower - upper;
    lower = nw4r::math::FSelect(t, upper, lower);
    return lower;
}
extern "C" float fn_98_E878(float value, float low, float high) {
    const float* constants = lbl_98_rodata_10;
    float sign;
    if (value >= constants[0]) { sign = constants[1]; }
    else { sign = constants[2]; double d = fabs(value); value = d; }
    value = (value - low) / (high - low);
    return sign * clampValue(value, constants[0], constants[1]);
}
