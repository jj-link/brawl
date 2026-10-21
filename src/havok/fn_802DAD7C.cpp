#pragma force_active on
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" void fn_802DAD7C(Vec4* dst, const Vec4* src) {
    *dst = *src;
}
