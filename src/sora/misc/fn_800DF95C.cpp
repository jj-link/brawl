#pragma force_active on
#include <types.h>
#include <gm/gm_global.h>
#include <internal/math_double.h>

extern "C" void fn_800DB71C(float*, void*);
extern float lbl_804088A0[4];
extern float lbl_804088B0[4];
extern const float lbl_805A23B0;

inline void setvec(float* o, float x, float z, float y) {
    o[0] = x; o[1] = y; o[2] = z;
}
inline float getangle(float x, float y) {
    return atan2(y, x);
}
extern "C" void fn_800DF95C(float* out, float* angle, void* arg2) {
    float dir[3];
    float pos[3];
    float* lim;
    u8* rec;

    rec = (u8*)g_GameGlobal->getGlobalRecordMenuDatap();
    lim = lbl_804088A0;
    if ((rec[0x28] >> 7) & 1) {
        lim = lbl_804088B0;
    }

    fn_800DB71C(pos, arg2);
    dir[0] = pos[0];
    dir[1] = pos[1];
    dir[2] = pos[2];

    if (dir[0] > lim[1]) {
        float l = lim[1];
        float x = dir[0];
        x = l / x;
        setvec(out, l, lbl_805A23B0, dir[1] * x);
    } else if (dir[0] < lim[0]) {
        float l = lim[0];
        float x = dir[0];
        x = l / x;
        setvec(out, l, lbl_805A23B0, dir[1] * x);
    } else {
        out[0] = dir[0];
        out[1] = dir[1];
        out[2] = dir[2];
    }

    if (out[1] > lim[2]) {
        out[0] = out[0] * (lim[2] / out[1]);
        out[1] = lim[2];
    } else if (out[1] < lim[3]) {
        out[0] = out[0] * (lim[3] / out[1]);
        out[1] = lim[3];
    }

    if (angle != 0) {
        float x = dir[0];
        float y = dir[1];
        *angle = atan2(y, x);
    }
}