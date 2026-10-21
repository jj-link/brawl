#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    unsigned char pad[0x10];
    Vec3 v;
};

extern "C" void fn_8009EF8C(Obj* dst, const Vec3* src) {
    dst->v = *src;
}
