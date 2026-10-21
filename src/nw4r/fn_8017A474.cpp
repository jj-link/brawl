#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Src {
    unsigned char pad[0xB0];
    Vec3 v;
};

extern "C" {
void fn_8017A474(Vec3* dst, const Src* src) {
    Vec3 tmp;
    tmp = src->v;
    *dst = tmp;
}
}
