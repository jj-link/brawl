#pragma force_active on
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" void fn_8031AAA0(Vec4* dst, const Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
}
