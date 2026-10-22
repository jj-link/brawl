#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    unsigned char pad[0x2F0];
    Vec3 v1;
    unsigned char pad2[0x3C];
    Vec3 v2;
};

extern "C" void fn_800E4E1C(Obj* self, const Vec3* src) {
    int r;

    r = 0;
    if (self->v1.x != src->x || self->v1.y != src->y || self->v1.z != src->z) {
        r = 1;
    }
    if (r != 0) {
        self->v1.x = src->x;
        self->v1.y = src->y;
        self->v1.z = src->z;
    }
    r = 0;
    if (self->v2.x != src->x || self->v2.y != src->y || self->v2.z != src->z) {
        r = 1;
    }
    if (r != 0) {
        self->v2.x = src->x;
        self->v2.y = src->y;
        self->v2.z = src->z;
    }
}
