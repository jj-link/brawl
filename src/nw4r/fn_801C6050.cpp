#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    unsigned char pad[0xB8];
    Vec3 v;
};

extern "C" void fn_801C6050(Obj* self, const Vec3* src) {
    self->v = *src;
}
