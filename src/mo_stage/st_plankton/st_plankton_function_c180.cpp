#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
extern "C" const float lbl_74_rodata_160[];

extern "C" int fn_74_C180(void* self, float* a, float* b, float* c,
                          float* d, float* out) {
    const float* tbl = lbl_74_rodata_160;
    float det = (c[0] - d[0]) * (a[1] - b[1]) - (a[0] - b[0]) * (c[1] - d[1]);
    float num = (a[0] - b[0]) * (d[1] - b[1]) - (d[0] - b[0]) * (a[1] - b[1]);
    if (nw4r::ut::Abs(det) < tbl[11]) {
        return 0;
    }
    float t = num / det;
    if (t < tbl[0] || t > tbl[12]) {
        return 0;
    }
    float v;
    float u;
    if (a[0] != b[0]) {
        u = (t * (c[0] - d[0]) + (d[0] - b[0])) / (a[0] - b[0]);
    } else {
        u = (t * (c[1] - d[1]) + (d[1] - b[1])) / (a[1] - b[1]);
    }
    if (u < tbl[0] || u > tbl[12]) {
        return 0;
    }
    v = tbl[12] - u;
    out[0] = a[0] * u + b[0] * v;
    out[1] = a[1] * u + b[1] * v;
    return 1;
}
