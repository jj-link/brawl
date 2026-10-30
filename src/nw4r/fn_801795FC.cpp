#include <nw4r/math/math_types.h>
#pragma force_active on

struct S {
    char pad[0xAC];
    nw4r::math::VEC3 a;
    nw4r::math::VEC3 b;
};

extern "C" nw4r::math::VEC3* fn_801795FC(S* s, nw4r::math::VEC3* out)
{
    *out = s->a - s->b;
    return out;
}
