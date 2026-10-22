#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" void fn_801ED008(const nw4r::math::VEC3*, nw4r::math::VEC3*);
extern "C" float fn_80162540(float, float);
extern "C" float mtSqrtf__Ff(float);

extern float lbl_805A1D78;
extern float lbl_805A1D7C;
extern float lbl_805A1D88;
extern float lbl_805A1D8C;

extern "C" float fn_8009BAFC(nw4r::math::VEC3* a, nw4r::math::VEC3* b) {
    fn_801ED008(a, a);
    fn_801ED008(b, b);

    float dot = nw4r::math::VEC3Dot(a, b);
    if ((float)__fabs(dot) < lbl_805A1D78) {
        float s = mtSqrtf__Ff(lbl_805A1D78 - dot * dot);
        return lbl_805A1D88 * fn_80162540(s, dot);
    }
    float r = lbl_805A1D7C;
    if (dot < r) {
        r = lbl_805A1D8C;
    }
    return r;
}
