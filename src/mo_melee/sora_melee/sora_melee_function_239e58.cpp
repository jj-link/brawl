#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_3930[];
float fn_801622C4(float);
float fn_8016232C(float);

void fn_27_239E58(void*, float* out, int mode,
                  float start, float end, float t) {
    const float* data = lbl_27_rodata_3930;
    if (out != 0) {
        if (t < data[0]) t = data[0];
        if (t > data[1]) t = data[1];

        float delta = end - start;
        switch (mode) {
        case 1: {
            t = data[13] * t;
            unsigned short angle = __OSf32tou16(t);
            t = fn_801622C4(data[14] * __OSu16tof32(&angle));
            break;
        }
        case 2: {
            unsigned short angle = __OSf32tou16(data[13] * t);
            t = fn_8016232C(data[14] * __OSu16tof32(&angle));
            break;
        }
        }
        *out = start + delta * t;
    }
}
}
