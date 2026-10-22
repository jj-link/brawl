#include <revolution/OS/OSFastCast.h>
#pragma force_active on

struct Sample {
    float value;
    float other;
    float delta;
    float otherDelta;
};

extern "C" {
extern const Sample lbl_804097C8[];
extern const float lbl_805A2C10;

float fn_8016232C(float x) {
    float f = __fabsf(x);
    while (f > lbl_805A2C10) {
        f -= lbl_805A2C10;
    }
    unsigned short idx = __OSf32tou16(f);
    float frac = f - __OSu16tof32(&idx);
    unsigned int i = idx & 255;
    return lbl_804097C8[i].other + frac * lbl_804097C8[i].otherDelta;
}
}
