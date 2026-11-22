#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
extern "C" float rsqrtf__Ff(float);
extern "C" const float lbl_805A29C0;
extern "C" const float lbl_805A29F0;
extern "C" const float lbl_805A29FC;
struct Self {
    char pad[0x378];
    nw4r::math::VEC2 a[4];
    char pad2[0x1c];
    nw4r::math::VEC2 b[4];
    char pad3[0x86];
    unsigned short flags;
};
inline Vec2f diff(const nw4r::math::VEC2& a, const nw4r::math::VEC2& b) {
    return *(const Vec2f*)&a - *(const Vec2f*)&b;
}
inline float length(Vec2f v, Vec2f& t) {
    t = v;
    float s = t.m_x*t.m_x + t.m_y*t.m_y;
    if ((float)(double)nw4r::ut::Abs(s) <= lbl_805A29FC) return lbl_805A29F0;
    return s * rsqrtf__Ff(s);
}
inline float lengthFirst(Vec2f v, Vec2f& t) {
    Vec2f::copy(t, v);
    float s = t.m_x*t.m_x + t.m_y*t.m_y;
    if ((float)(double)nw4r::ut::Abs(s) <= lbl_805A29FC) return lbl_805A29F0;
    return s * rsqrtf__Ff(s);
}
extern "C" void fn_8012C32C(Self* self) {
    Vec2f t;
    if (lengthFirst(diff(self->b[0], self->a[0]), t) < lbl_805A29C0) self->b[0] = self->a[0];
    if (length(diff(self->b[1], self->a[1]), t) < lbl_805A29C0) self->b[1] = self->a[1];
    if (length(diff(self->b[2], self->a[2]), t) < lbl_805A29C0) self->b[2] = self->a[2];
    if (length(diff(self->b[3], self->a[3]), t) < lbl_805A29C0) self->b[3] = self->a[3];
    self->flags = 0;
    if (self->a[0] == self->b[0]) self->flags |= 1;
    if (self->a[1] == self->b[1]) self->flags |= 2;
    if (self->a[3] == self->b[3]) self->flags |= 4;
    if (self->a[2] == self->b[2]) self->flags |= 8;
}
