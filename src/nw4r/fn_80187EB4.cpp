#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
extern const float lbl_805A311C, lbl_805A3110, lbl_805A3120;
extern "C" void fn_801F37B8(void *, const float *, s8);
extern "C" void fn_80187EB4(void *out, const float *in) {
    float v0 = in[0], v1 = in[1], v2 = in[2], v3 = in[3], v4 = in[4], v5 = in[5];
    float a = nw4r::ut::Abs(v0), b = nw4r::ut::Abs(v1), c = nw4r::ut::Abs(v2);
    float d = nw4r::ut::Abs(v3), e = nw4r::ut::Abs(v4), f = nw4r::ut::Abs(v5);
    s8 n = 0;
    if (a >= lbl_805A311C || b >= lbl_805A311C || c >= lbl_805A311C || d >= lbl_805A311C || e >= lbl_805A311C || f >= lbl_805A311C) {
        scale_down:
        if (n < 46) {
            a *= lbl_805A3110;
            v0 *= lbl_805A3110; v1 *= lbl_805A3110; v2 *= lbl_805A3110; v3 *= lbl_805A3110; v4 *= lbl_805A3110; v5 *= lbl_805A3110;
            b *= lbl_805A3110; c *= lbl_805A3110; d *= lbl_805A3110; e *= lbl_805A3110; f *= lbl_805A3110;
            ++n;
            if (a >= lbl_805A311C) goto scale_down;
            if (b >= lbl_805A311C) goto scale_down;
            if (c >= lbl_805A311C) goto scale_down;
            if (d >= lbl_805A311C) goto scale_down;
            if (e >= lbl_805A311C) goto scale_down;
            if (f >= lbl_805A311C) goto scale_down;
        }
    } else if (a < lbl_805A3110 && b < lbl_805A3110 && c < lbl_805A3110 && d < lbl_805A3110 && e < lbl_805A3110 && f < lbl_805A3110) {
        do {
            a *= lbl_805A3120;
            --n;
            v0 *= lbl_805A3120; v1 *= lbl_805A3120; v2 *= lbl_805A3120; v3 *= lbl_805A3120; v4 *= lbl_805A3120; v5 *= lbl_805A3120;
            b *= lbl_805A3120; c *= lbl_805A3120; d *= lbl_805A3120; e *= lbl_805A3120; f *= lbl_805A3120;
        } while (a < lbl_805A3110 && b < lbl_805A3110 && c < lbl_805A3110 && d < lbl_805A3110 && e < lbl_805A3110 && f < lbl_805A3110 && n > -17);
    }
    float values[6];
    values[0] = v0; values[1] = v1; values[2] = v2;
    values[3] = v3; values[4] = v4; values[5] = v5;
    fn_801F37B8(out, values, n);
}