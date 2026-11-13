#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_EAC;

struct Obj {
    u8 r, g, b, a;
    f32 f4, f8, fC, f10;
    f32 f14, f18, f1C, f20;
    f32 f24, f28, f2C, f30;
    u8 b34;
};

struct Color {
    u8 r, g, b, a;
};

extern "C" void fn_27_C1168(Obj* self, const f32* v) {
    f32 w, z, y, x;
    Color tmp2;
    Color tmp;
    x = v[0];
    y = v[1];
    z = v[2];
    w = v[3];
    self->b34 = 1;
    tmp.r = (u8)(s32)(x * self->f24);
    tmp.g = (u8)(s32)(y * self->f28);
    tmp.b = (u8)(s32)(z * self->f2C);
    tmp.a = (u8)(s32)(w * self->f30);
    *reinterpret_cast<u32*>(&tmp2) = *reinterpret_cast<u32*>(&tmp);
    self->f4 = x;
    self->f8 = y;
    self->fC = z;
    self->f10 = w;
    self->r = tmp2.r;
    self->g = tmp2.g;
    self->b = tmp2.b;
    self->a = tmp2.a;
    self->f14 = lbl_27_rodata_EAC;
    self->f18 = lbl_27_rodata_EAC;
    self->f1C = lbl_27_rodata_EAC;
    self->f20 = lbl_27_rodata_EAC;
}
