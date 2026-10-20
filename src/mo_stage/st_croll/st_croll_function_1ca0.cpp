#include <nw4r/math/math_types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* getManager__15gfCameraManagerFv();
void fn_801ED008(const Vec3f*, Vec3f*);
void fn_801ED0B0(const Vec3f*, const Vec3f*, Vec3f*);

extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_C;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_40;
extern const float lbl_90_rodata_44;
extern const float lbl_90_rodata_48;
}

static inline float dot(const Vec3f& a, const Vec3f& b) {
    return nw4r::math::VEC3Dot(
        (const nw4r::math::VEC3*)&a,
        (const nw4r::math::VEC3*)&b);
}

static inline float lengthSq(const Vec3f& a) {
    return nw4r::math::VEC3LenSq((const nw4r::math::VEC3*)&a);
}

extern "C" void fn_90_1CA0(float* out) {
    Vec3f camera;
    Vec3f initial;
    Vec3f scaled;
    Vec3f alternate;
    Vec3f cross;
    Vec3f axis;
    Vec3f b;
    Vec3f a;

    camera = *(Vec3f*)((char*)getManager__15gfCameraManagerFv() + 0x78);
    initial.m_x = lbl_90_rodata_0;
    initial.m_y = lbl_90_rodata_0;
    initial.m_z = lbl_90_rodata_40;

    fn_801ED008(&initial, &a);
    fn_801ED008(&camera, &b);

    float t = lbl_90_rodata_44 + lbl_90_rodata_44 * dot(a, b);
    if (t <= lbl_90_rodata_0) {
        axis.m_x = lbl_90_rodata_10;
        axis.m_y = lbl_90_rodata_0;
        axis.m_z = lbl_90_rodata_0;
        fn_801ED0B0(&a, &axis, &axis);

        if (lengthSq(axis) <= lbl_90_rodata_48) {
            alternate.m_x = lbl_90_rodata_0;
            alternate.m_y = lbl_90_rodata_10;
            alternate.m_z = lbl_90_rodata_0;
            axis = alternate;
            fn_801ED0B0(&a, &axis, &axis);
        }

        out[0] = axis.m_x;
        out[1] = axis.m_y;
        out[2] = axis.m_z;
        out[3] = lbl_90_rodata_0;
    }

    float s = rsqrtf(t);
    fn_801ED0B0(&a, &b, &cross);
    nw4r::math::VEC3Scale(
        (nw4r::math::VEC3*)&scaled,
        (const nw4r::math::VEC3*)&cross,
        s);
    cross = scaled;

    out[0] = cross.m_x;
    out[1] = cross.m_y;
    out[2] = cross.m_z;
    out[3] = lbl_90_rodata_C * (s * t);
}
