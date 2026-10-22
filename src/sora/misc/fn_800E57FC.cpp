#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    unsigned char pad[0x540];
    Vec3 v;
};

extern "C" void fn_800E57FC(Obj* self, const Vec3* src) {
    int r;
    r = 0;
    if (self->v.x != src->x) {
        goto set;
    }
    if (self->v.y != src->y) {
        goto set;
    }
    if (self->v.z == src->z) {
        goto end;
    }
set:
    r = 1;
end:
    if (r) {
        self->v = *src;
    }
}
