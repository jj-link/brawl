#include <types.h>
#pragma force_active on
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct T { char pad[0x30]; float c[4]; };
inline void calc(float* out, const T* in, V& v, const float* arg0, float arg3) {
    float a = in->c[0], b = in->c[1];
    float sum = arg3 + arg0[3];
    v.x = sum;
    v.y = sum;
    v.z = sum;
    v.w = sum;
    float x = v.x, y = v.y;
    float c = in->c[2], d = in->c[3];
    out[0] = a - x;
    out[1] = b - y;
    out[2] = c - sum;
    out[3] = d - sum;
    out[4] = a + x;
    out[5] = b + y;
    out[6] = c + sum;
    out[7] = d + sum;
}
extern "C" void fn_802D5F28(float* arg0, const T* arg1, float* arg2, float arg3) {
    V v;
    calc(arg2, arg1, v, arg0, arg3);
}
