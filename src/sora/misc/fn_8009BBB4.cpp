#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" void fn_801ED008(const nw4r::math::VEC3*, nw4r::math::VEC3*);
extern "C" double fn_80400B30(double);

extern float lbl_805A1D78;
extern float lbl_805A1D7C;

extern "C" float fn_8009BBB4(nw4r::math::VEC3* a, nw4r::math::VEC3* b) {
    fn_801ED008(a, a);
    fn_801ED008(b, b);

    float dot = nw4r::math::VEC3Dot(a, b);
    if (dot < lbl_805A1D78) {
        return (float)fn_80400B30(dot);
    }
    return lbl_805A1D7C;
}
