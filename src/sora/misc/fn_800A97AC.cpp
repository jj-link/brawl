#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
double fn_8040012C(double);
extern const float lbl_805A20F0;
extern const float lbl_805A20F4;
extern const float lbl_805A20F8;
extern const float lbl_805A20FC;
extern const float lbl_805A2100;
extern const float lbl_805A2104;
extern const float lbl_805A2108;
extern const float lbl_805A210C;
extern const float lbl_805A2110;
extern const float lbl_805A2114;
extern const float lbl_805A2118;
}

inline float clampValue(float value, float lo, float hi) {
    float v = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(v - hi, hi, v);
}

extern "C" void fn_800A97AC(float* self, float value) {
    self[2] = lbl_805A20FC;
    self[3] = lbl_805A2100;
    self[4] = lbl_805A2104;
    float initial = -self[3] / self[4];
    float min = lbl_805A20F4;
    float clamped = clampValue(value, lbl_805A20F0, lbl_805A20F8);
    self[5] = (float)fn_8040012C(initial);
    self[6] = lbl_805A20FC;
    float angle = (float)fn_8040012C((clamped / lbl_805A2108) / (self[4] - clamped * lbl_805A210C));
    self[9] = angle;
    self[8] = -angle;
    angle = (float)fn_8040012C((clamped * lbl_805A2110) / (self[4] - clamped * lbl_805A210C));
    self[11] = self[5] + angle;
    self[10] = self[5] - angle;
    self[13] = lbl_805A2114 * (float)fn_8040012C((clamped * lbl_805A210C) / self[4]);
    if (self[13] < min)
        self[13] = min;
    self[12] = min;
    self[14] = value;
    self[7] = min + lbl_805A2118 * (self[13] - min);
}