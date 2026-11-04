#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" {
extern const float lbl_80465138[][2];
extern const float lbl_805A2C14;
extern const float lbl_805A2C18;
extern const float lbl_805A2C1C;
extern const float lbl_805A2C20;
extern const float lbl_805A2C24;
extern const float lbl_805A2C28;
}

static inline float SampleAtan(float x) {
    x *= lbl_805A2C1C;
    u16 idx = __OSf32tou16(x);
    float frac = x - __OSu16tof32(&idx);
    return lbl_80465138[idx][0] + frac * lbl_80465138[idx][1];
}

extern "C" float fn_801623F0(float x) {
    if (x >= lbl_805A2C14) {
        if (x > lbl_805A2C18) {
            return lbl_805A2C20 - SampleAtan(lbl_805A2C18 / x);
        } else {
            return SampleAtan(x);
        }
    } else {
        if (x < lbl_805A2C24) {
            return lbl_805A2C28 + SampleAtan(lbl_805A2C24 / x);
        } else {
            return -SampleAtan(-x);
        }
    }
}
