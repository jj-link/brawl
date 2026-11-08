#include <revolution/OS/OSFastCast.h>
#pragma force_active on
extern "C" {
struct Entry { float a; float b; };
union FloatBits { float f; s32 u; };
extern Entry lbl_80464828[];
extern float lbl_805A2BF4;
extern float lbl_805A2BF8;
inline float compose(float f, int a) {
    FloatBits result;
    result.f = f;
    result.u = ((a << 23) + result.u) & 0x7FFFFFFF;
    return result.f;
}
float fn_80162188(float x) {
    short a;
    unsigned short idx;
    float fa;
    float t;
    float fb;
    float scaled = 1.4426950216293335f * x;
    a = __OSf32tos16(scaled);
    fa = __OSs16tof32(&a);
    t = lbl_805A2BF8 * (lbl_805A2BF4 + (x - lbl_805A2BF4 * fa));
    idx = __OSf32tou16(t);
    fb = __OSu16tof32(&idx);
    return compose(lbl_80464828[idx].a + (t - fb) * lbl_80464828[idx].b, a);
}
}