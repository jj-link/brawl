#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" double fn_804008E4(double, double*);
extern float lbl_805A31BC;
extern float lbl_805A31C0;

static inline float split(float value, float* integral) {
    double d;
    float fraction = (float)fn_804008E4(value, &d);
    *integral = (float)d;
    return fraction;
}

extern "C" u32 fn_801931AC(const u32* table, float value) {
    float integral;
    float fraction = split(value, &integral);
    int index = (int)integral;

    if (lbl_805A31BC == fraction)
        return table[index];

    u32 a = table[index];
    u32 b = table[index + 1];
    u32 result;
    s16 weight = __OSf32tos16(lbl_805A31C0 * fraction);

    u8* p = (u8*)&a;
    u8* q = (u8*)&b;
    u8* r = (u8*)&result;

    int green = p[1];
    int blue = p[2];
    int alpha = p[3];
    int red = p[0];

    r[0] = red + ((weight * (q[0] - red)) >> 15);
    r[1] = green + ((weight * (q[1] - green)) >> 15);
    r[2] = blue + ((weight * (q[2] - blue)) >> 15);
    r[3] = alpha + ((weight * (q[3] - alpha)) >> 15);

    return result;
}
