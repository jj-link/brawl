#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Vec4f {
    float x;
    float y;
    float z;
    float w;
};

struct Inner {
    char pad0[0x28];
    float unk28;
    Vec4f unk2C;
    Vec4f unk3C;
};

struct Self {
    char pad0[0x190];
    Inner* unk190;
    s32 unk194;
    u32 unk198;
    Vec3f unk19C;
    float unk1A8;
};

extern "C" void fn_8009EFCC(Inner* p);

extern "C" void fn_27_113D94(Self* self, Vec3f* v, u32 flags, float f1, float f2) {
    if (self->unk190 != 0 && f1 != self->unk190->unk28) {
        Vec4f a = self->unk190->unk2C;
        self->unk190->unk2C.x = -a.x;
        self->unk190->unk2C.y = -a.y;
        Vec4f b = self->unk190->unk3C;
        self->unk190->unk3C.x = -b.x;
        self->unk190->unk3C.y = -b.y;
        self->unk190->unk28 = f1;
        fn_8009EFCC(self->unk190);
    }
    float vz;
    float vy;
    float vx;
    vx = v->x;
    vy = v->y;
    vz = v->z;
    self->unk19C.x = vx;
    self->unk19C.y = vy;
    self->unk19C.z = vz;
    self->unk198 = flags;
    self->unk1A8 = f2;
    self->unk194 = -1;
}
