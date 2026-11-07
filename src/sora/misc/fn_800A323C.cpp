#include "nw4r/math/math_arithmetic.h"
#pragma force_active on

extern "C" double fn_80400AB8(double);
extern "C" const float lbl_805A1F3C;
extern "C" const float lbl_805A1F40;
extern "C" const float lbl_805A1F50;

struct Cam {
    char pad0[0x94];
    float unk94;
    float unk98;
};

extern "C" Cam* getInstance__16CameraControllerFv();

struct Src {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    char pad10[4];
    float unk14;
};

struct Dst {
    char pad0[0x34];
    float fov;
};

extern "C" void fn_800A323C(Dst* dst, Src* src, float farg0) {
    float prod = lbl_805A1F40 * (lbl_805A1F3C * dst->fov);
    float tanf = (float)fn_80400AB8(prod);
    float a = (src->unkC - src->unk4) / (lbl_805A1F50 * tanf);
    float tanf2 = (float)fn_80400AB8(prod);
    float b = (src->unk8 - src->unk0) / (farg0 * (lbl_805A1F50 * tanf2));
    float m = b > a ? b : a;
    Cam* cam = getInstance__16CameraControllerFv();
    float d = m - cam->unk94;
    float t = nw4r::math::FSelect(d, m, cam->unk94);
    t = nw4r::math::FSelect(t - cam->unk98, cam->unk98, t);
    src->unk14 = t;
}