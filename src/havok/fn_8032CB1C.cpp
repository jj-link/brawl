#pragma force_active on
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

struct Dst {
    char pad[0x30];
    Vec4 v;
};

extern "C" void fn_8032CB1C(Dst* dst, const Vec4* src) {
    dst->v = *src;
}
