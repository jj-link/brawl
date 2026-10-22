#pragma force_active on
extern float lbl_805A31F4;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    unsigned int flags;
    float x;
    float y;
    float z;
};

extern "C" void fn_8019597C(Obj* self, const Vec3* src) {
    unsigned int f;
    if (lbl_805A31F4 == src->x && lbl_805A31F4 == src->y && lbl_805A31F4 == src->z) {
        f = self->flags | 0x18;
        self->flags = f;
        if (f & 4) {
            self->flags = f | 2;
        }
    } else {
        f = self->flags & ~0x1A;
        self->flags = f;
        if (src->x == src->y) {
            if (src->y == src->z) {
                self->flags = f | 0x10;
            }
        }
    }
    self->x = src->x;
    self->y = src->y;
    self->z = src->z;
}
