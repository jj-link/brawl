#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" float fn_801622A0(float);
extern "C" const float lbl_805A2FC0;
extern "C" const float lbl_805A2FC4;
extern "C" const float lbl_805A2FC8;

inline float magnitude(float s) {
    if (s <= lbl_805A2FC4) {
        return lbl_805A2FC4;
    }
    return s * fn_801622A0(s);
}

extern "C" int fn_8017943C(nw4r::math::VEC3* v) {
    float s = nw4r::math::VEC3Dot(v, v);
    if (s < lbl_805A2FC0) {
        return 0;
    }
    float k = lbl_805A2FC8 / magnitude(s);
    nw4r::math::VEC3Scale(v, v, k);
    return 1;
}
