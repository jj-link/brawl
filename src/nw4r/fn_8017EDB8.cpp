#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" void fn_8017EDB8(nw4r::math::VEC3* pOut, const nw4r::math::VEC3* pA,
                            const nw4r::math::VEC3* pB) {
    nw4r::math::VEC3Add(pOut, pA, pB);
}
