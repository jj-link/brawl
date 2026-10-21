#pragma force_active on
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

struct Mtx2 {
    Vec4 a;
    Vec4 b;
};

extern "C" void fn_80324998(Mtx2* dst, const Mtx2* src) {
    dst->a = src->a;
    dst->b = src->b;
}
