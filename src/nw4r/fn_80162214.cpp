#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" {

struct Entry {
    float a, b;
};

extern Entry lbl_80464930[];
extern float lbl_805A2BF4;
extern float lbl_805A2BFC;
extern float lbl_805A2C00;

union FloatBits {
    float f;
    unsigned int u;
};

float fn_80162214(float x) {
    FloatBits a, c, b;
    short exponent;
    unsigned short idx;

    a.f = x;
    b.f = x;
    exponent = ((a.u >> 23) & 255) - 127;
    c.u = (b.u & 0x807FFFFF) | 0x3F800000;

    float mantissa = c.f;
    float ef = __OSs16tof32(&exponent);
    float t = lbl_805A2BFC * (mantissa - lbl_805A2C00);
    idx = __OSf32tou16(t);
    float fi = __OSu16tof32(&idx);
    float frac = t - fi;
    float result = lbl_80464930[idx].a + frac * lbl_80464930[idx].b;
    return result + lbl_805A2BF4 * ef;
}

}
