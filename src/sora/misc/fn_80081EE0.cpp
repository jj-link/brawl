#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" void fn_801EC1B8(void*, void*, void*);
extern "C" f32 fn_801ED04C(void*);

struct Obj {
    char pad0[0x1C];
    nw4r::math::VEC3 pos1;
    nw4r::math::VEC3 pos2;
    char pad1[0x80 - 0x34];
    f32 unk80;
    f32 unk84;
};

extern "C" void fn_80081EE0(Obj* self, void* arg1) {
    nw4r::math::MTX34 m[2] = {
        nw4r::math::MTX34(1.0f, 0.0f, 0.0f, self->unk80, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f),
        nw4r::math::MTX34(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f),
    };
    nw4r::math::VEC3 d;

    fn_801EC1B8(arg1, &m[0], &m[0]);
    fn_801EC1B8(arg1, &m[1], &m[1]);

    self->pos1.x = m[0]._03;
    self->pos1.y = m[0]._13;
    self->pos1.z = m[0]._23;
    self->pos2.x = m[1]._03;
    self->pos2.y = m[1]._13;
    self->pos2.z = m[1]._23;

    nw4r::math::VEC3Sub(&d, &self->pos1, &self->pos2);
    self->unk84 = fn_801ED04C(&d);
}
