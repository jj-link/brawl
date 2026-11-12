#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {

extern const float lbl_805A2204;

static inline float clamp(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

float fn_800B458C(float c, float b, float a) {
    return clamp(a, c, b - lbl_805A2204);
}

}