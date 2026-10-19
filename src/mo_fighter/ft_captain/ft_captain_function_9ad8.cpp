#pragma force_active on
struct Vec3I {
    int x, y, z;
};

struct Holder {
    int pad;
    Vec3I v;
};

extern "C" {
void fn_100_9B2C(void* out, void* a, int b);

Vec3I* fn_100_9AD8(Holder* self, int b) {
    Vec3I tmp;
    fn_100_9B2C(&tmp, self, b);
    self->v = tmp;
    return &self->v;
}
}
