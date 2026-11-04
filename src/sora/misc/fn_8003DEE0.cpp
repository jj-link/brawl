#include <nw4r/math/math_types.h>
#include <mt/mt_common.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern "C" void fn_8003DEE0(nw4r::math::VEC3* out, const nw4r::math::VEC3* in) {
    float scale = rsqrtf(in->z * in->z + (in->x * in->x + in->y * in->y));
    LocalScale((const Vec*)in, (Vec*)out, scale);
}
