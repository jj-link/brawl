#include <nw4r/math/math_types.h>
#include <mt/mt_vector.h>
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

Vec3f operator*(const float c, const Vec3f& v) {
    Vec3f out;
    LocalScale(reinterpret_cast<const Vec*>(&v), reinterpret_cast<Vec*>(&out), c);
    return out;
}