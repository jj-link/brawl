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
extern const float lbl_805A2C14;

float fn_801622C4(float x) {
    float f = __fabsf(x);
    while (f > lbl_805A2C10) {
        f -= lbl_805A2C10;
    }

    unsigned short idx = __OSf32tou16(f);
    float frac = f - __OSu16tof32(&idx);
    unsigned int i = idx & 255;
    float a = lbl_804097C8[i].value + frac * lbl_804097C8[i].delta;

    if (x < lbl_805A2C14) {
        a = -a;
    }
    return a;
}
}
