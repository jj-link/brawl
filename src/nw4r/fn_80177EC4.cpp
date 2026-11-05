#include <nw4r/math/math_types.h>
#pragma force_active on
extern "C" float fn_801622A0(float);
extern "C" const float lbl_805A2F9C;
extern "C" const float lbl_805A2F94;
extern "C" const float lbl_805A2F98;
using namespace nw4r::math;
struct Node { char pad[0xac]; VEC3 pos; };
struct Owner { char pad[0x98]; VEC3 defaultDir; VEC3 pos; };
inline float magnitude(float s) {
    if (s <= lbl_805A2F94) return lbl_805A2F94;
    return s * fn_801622A0(s);
}
inline VEC3& divBy(VEC3& v, f32 x) {
    return v *= (lbl_805A2F98 / x);
}
inline bool normalize(VEC3* v) {
    float s = VEC3Dot(v, v);
    if (s < lbl_805A2F9C) return false;
    divBy(*v, magnitude(s));
    return true;
}
extern "C" void fn_80177EC4(VEC3* out, Owner* owner, Node* node) {
    VEC3Sub(out, &node->pos, &owner->pos);
    if (!normalize(out)) {
        *out = owner->defaultDir;
    }
}