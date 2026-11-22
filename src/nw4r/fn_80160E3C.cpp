#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" const float lbl_805A2BDC;
extern "C" void fn_801607B4(void*, float*, int*, int);

extern "C" void fn_80160E3C(void* arg0, float* arg1, int arg2, int arg3) {
    int idx = arg2;
    float zero = lbl_805A2BDC;
    int end = arg2 + arg3 * 2;
    arg1[0] = zero;
    arg1[2] = zero;
    arg1[1] = zero;
    arg1[3] = zero;
    ((float*)arg0)[11] = zero;
    ((float*)arg0)[12] = zero;
    do {
        float v[4] = { zero, zero, zero, zero };
        fn_801607B4(arg0, v, &idx, arg3);
        arg3 = (end - idx) / 2;
        float a = v[0];
        arg1[0] = nw4r::ut::Min(arg1[0], a);
        arg1[1] = nw4r::ut::Min(arg1[1], v[1]);
        arg1[2] = nw4r::ut::Max(arg1[2], v[2]);
        arg1[3] = nw4r::ut::Max(arg1[3], v[3]);
    } while (arg3 > 0);
}
