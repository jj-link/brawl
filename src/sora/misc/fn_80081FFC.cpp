#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" void fn_801EC1B8(int, void*, void*);
extern "C" f32 fn_801ED04C(void*);

struct Obj {
    char pad0[0x80];
    f32 unk80;
    f32 unk84;
};

extern "C" void fn_80081FFC(Obj* self, int arg1, nw4r::math::VEC3* pos1, nw4r::math::VEC3* pos2) {
    nw4r::math::MTX34 m0(1.0f, 0.0f, 0.0f, self->unk80,
                         0.0f, 1.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f);
    nw4r::math::MTX34 m1(1.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f);
    nw4r::math::VEC3 d;

    fn_801EC1B8(arg1, &m0, &m0);
    fn_801EC1B8(arg1, &m1, &m1);

    pos1->x = m0._03;
    pos1->y = m0._13;
    pos1->z = m0._23;
    pos2->x = m1._03;
    pos2->y = m1._13;
    pos2->z = m1._23;

    nw4r::math::VEC3Sub(&d, pos1, pos2);
    self->unk84 = fn_801ED04C(&d);
}
