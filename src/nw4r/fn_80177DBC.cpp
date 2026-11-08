#include <nw4r/math/math_types.h>
#pragma force_active on
extern "C" float fn_801622A0(float);
extern "C" const float lbl_805A2F94;
extern "C" const float lbl_805A2F98;
extern "C" const float lbl_805A2F9C;
using namespace nw4r::math;
struct Source { char pad[0x98]; VEC3 fallback; char pad2[8]; VEC3 a; VEC3 b; };
inline float squareRoot(float square) {
    if (square <= lbl_805A2F94) return lbl_805A2F94;
    return square * fn_801622A0(square);
}
inline VEC3& divBy(VEC3& v, f32 x) {
    return v *= (lbl_805A2F98 / x);
}
inline bool normalize(VEC3* v) {
    float square = VEC3Dot(v, v);
    if (square < lbl_805A2F9C) return false;
    divBy(*v, squareRoot(square));
    return true;
}
extern "C" void fn_80177DBC(VEC3* out, Source* fallback, Source* src) {
    VEC3 tmp;
    VEC3Sub(&tmp, &src->a, &src->b);
    *out = tmp;
    if (!normalize(out)) *out = fallback->fallback;
}