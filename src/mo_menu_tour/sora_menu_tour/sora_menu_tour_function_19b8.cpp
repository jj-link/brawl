#pragma force_active on
struct Obj { char pad[0x3c]; float x, y, z; };
struct Vec3f { float x, y, z; };
extern "C" void fn_800B6838(Obj*, const Vec3f*);

struct T {
    char pad0[0xb90];
    unsigned count;
    char pad1[0xf14 - 0xb94];
    unsigned idx[4];
    unsigned cur;
    unsigned padx;
    float start[4];
    float end[4];
    unsigned total;
    char pad2[0xfd0 - 0xf50];
    Obj* objs[1];
};

extern "C" int fn_3_19B8(T* self) {
    Vec3f v2;
    Vec3f v1;
    unsigned tot = self->total;
    float f = (float)(tot * tot * tot);
    self->cur++;
    if (self->cur >= tot) {
        for (unsigned i = 0; i < self->count; i++) {
            Obj* o = self->objs[self->idx[i]];
            v1.x = o->x; v1.y = o->y; v1.z = o->z;
            v1.x = self->end[i];
            fn_800B6838(self->objs[self->idx[i]], &v1);
        }
        self->cur = self->total;
        return 1;
    }
    for (unsigned i = 0; i < self->count; i++) {
        float d = (self->end[i] - self->start[i]) / f;
        unsigned c = self->cur;
        float t = (float)(c * c * c);
        Obj* o = self->objs[self->idx[i]];
        v2.x = o->x; v2.y = o->y; v2.z = o->z;
        v2.x = d * t + self->start[i];
        fn_800B6838(self->objs[self->idx[i]], &v2);
    }
    return 0;
}
