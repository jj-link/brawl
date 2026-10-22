#include <nw4r/math/math_types.h>
#pragma force_active on

static inline float dotw(const nw4r::math::VEC3& a, const nw4r::math::VEC3& b)
{
    return nw4r::math::VEC3Dot(&a, &b);
}

extern "C" float fn_801794E0(const nw4r::math::VEC3* a, const nw4r::math::VEC3* b)
{
    return dotw(*a, *b);
}
