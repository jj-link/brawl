#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern float lbl_805A3640, lbl_805A3644, lbl_805A3648, lbl_805A364C, lbl_805A3650, lbl_805A3654, lbl_805A3658, lbl_805A365C, lbl_805A3660, lbl_805A3664;
extern "C" void fn_801D1E0C(int unused, float x, float y, float* out1, float* out2)
{
    float d = y - lbl_805A3640;
    float ad = nw4r::math::FAbs(d);
    if (nw4r::math::FAbs(x) <= ad) {
        if (d <= lbl_805A3644) {
            float b;
            float a = x;
            b = lbl_805A3648 + lbl_805A364C * d;
            *out1 = a; *out2 = b;
        } else {
            float b;
            float a = lbl_805A3650 * x;
            b = lbl_805A3648 + lbl_805A3654 * d;
            *out1 = a; *out2 = b;
        }
    } else if (x >= lbl_805A3644) {
        if (d <= lbl_805A3644) {
            float b;
            float a = (lbl_805A3658 + lbl_805A365C * (-d / x)) * nw4r::math::FAbs(x);
            b = lbl_805A3648 + (lbl_805A3660 * d + lbl_805A364C * x);
            *out1 = a; *out2 = b;
        } else {
            float b;
            float a = lbl_805A3658 + lbl_805A3664 * (-d / x);
            b = lbl_805A3648 + lbl_805A3654 * x;
            *out1 = a * nw4r::math::FAbs(x); *out2 = b;
        }
    } else if (d <= lbl_805A3644) {
        float b;
            float a = (lbl_805A365C * (-d / x) - lbl_805A3658) * nw4r::math::FAbs(x);
        b = lbl_805A3648 + (lbl_805A3660 * d - lbl_805A3654 * x);
        *out1 = a; *out2 = b;
    } else {
        float b;
            float a = (lbl_805A3664 * (-d / x) - lbl_805A3658) * nw4r::math::FAbs(x);
        b = lbl_805A3648 + lbl_805A3654 * (-x);
        *out1 = a; *out2 = b;
    }
    *out2 += lbl_805A3640;
}