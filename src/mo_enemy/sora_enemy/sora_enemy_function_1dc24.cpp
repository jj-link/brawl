#include <nw4r/math/math_types.h>
#include <revolution/MTX/vec.h>

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

extern "C" void fn_41_1DC24(Vec* v, f32 scale) {
    LocalScale(v, v, scale);
}
