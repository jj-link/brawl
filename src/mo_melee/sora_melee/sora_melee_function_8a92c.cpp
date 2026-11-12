#include <types.h>
#include <nw4r/math/math_types.h>
#include <mt/mt_vector.h>
#include <orch_helpers.h>
#pragma force_active off
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

extern const f32 lbl_27_rodata_BC8;

struct Obj {
    u8 pad[0x14];
    Vec3f v;
};

inline Vec3f mul(const Vec3f& a, const f32 s) {
    Vec3f r;
    LocalScale((const Vec*)&a, (Vec*)&r, s);
    return r;
}

inline void subTo(Vec3f& out, const Vec3f& a, const Vec3f& b) {
    Vec3fSub_v905145(&out, &a, &b);
}

inline void subTo2(Vec3f& out, const Vec3f& a, const Vec3f& b) {
    subTo(out, a, b);
}

inline f32 dot(const Vec3f& a, const Vec3f& b) {
    return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

inline void reflect(Vec3f& v, const Vec3f& n, f32 k) {
    Vec3f r;
    subTo2(r, v, mul(mul(n, k), dot(n, v)));
    v = r;
}

extern "C" void fn_27_8A92C(Obj* self, const Vec3f* a) {
    f32 two = lbl_27_rodata_BC8;
    reflect(self->v, *a, two);
}
