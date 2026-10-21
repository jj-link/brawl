#pragma force_active on
struct Vec4 {
    float x, y, z, w;
};

struct Dst {
    char pad[0xF0];
    Vec4 v;
};

extern "C" void fn_802E4480(Dst* dst, const Vec4* src) {
    dst->v = *src;
}
