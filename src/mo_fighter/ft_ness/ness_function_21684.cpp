#include <nw4r/math/math_types.h>
#include <mt/mt_common.h>

namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#pragma force_active on
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}

extern "C" void fn_101_21684(Vec* out, const Vec* in, float scale) {
    LocalScale(in, out, scale);
}
