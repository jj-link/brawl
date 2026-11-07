#include <revolution/OS/OSFastCast.h>
#pragma force_active on
extern "C" {
extern const float lbl_80465138[][2];
extern const float lbl_805A2C14, lbl_805A2C1C, lbl_805A2C20, lbl_805A2C28, lbl_805A2C2C, lbl_805A2C30;
}
static inline float SampleAtan(float x) {
    x *= lbl_805A2C1C;
    u16 idx = __OSf32tou16(x);
    float frac = x - __OSu16tof32(&idx);
    return lbl_80465138[idx][0] + frac * lbl_80465138[idx][1];
}
extern "C" float fn_80162540(float y, float x) {
    if (lbl_805A2C14 == x && lbl_805A2C14 == y) return lbl_805A2C14;
    float big = x;
    float base = lbl_805A2C14;
    int neg;
    if (x >= base) {
        if (y >= base) {
            if (x >= y) { big = x; neg = 0; }
            else { big = y; base = lbl_805A2C20; y = x; neg = 1; }
        } else {
            y = -y;
            if (x >= y) { big = x; neg = 1; }
            else { big = y; base = lbl_805A2C28; y = x; neg = 0; }
        }
    } else {
        if (y >= base) {
            if (-x >= y) { big = -x; base = lbl_805A2C2C; neg = 1; }
            else { big = y; base = lbl_805A2C20; y = -x; neg = 0; }
        } else {
            if (-x >= -y) { big = -x; y = -y; base = lbl_805A2C30; neg = 0; }
            else { big = -y; base = lbl_805A2C28; y = -x; neg = 1; }
        }
    }
    if (neg) return base - SampleAtan(y / big);
    return base + SampleAtan(y / big);
}