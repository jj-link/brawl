#include <ef/ef_screen.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern GXColor lbl_27_rodata_4270;
extern GXColor lbl_27_rodata_4274;
}

struct Fn27_25C530_Self {
    char pad[0x48];
    u32 unk48;
    u32 unk4C;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    char pad53[9];
    f32 f5c;
    char pad60[8];
    u32 unk68;
};

inline u8 fill(f32 time, int kind, u8 r, u8 g, u8 b, u8 a, GXColor &color) {
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    GXColor copy = color;
    return (u32)g_efScreen->requestFill(time, kind, 0, &copy) >> 24;
}

extern "C" void fn_27_25C530(Fn27_25C530_Self* self) {
    GXColor colorA = lbl_27_rodata_4270;
    GXColor colorB = lbl_27_rodata_4274;
    GXColor temp;
    if (self->unk51 != 0) {
        self->unk52 = fill((f32)self->unk68 / self->f5c, 8, colorA.r, colorA.g, colorA.b, colorA.a, temp);
    } else {
        self->unk52 = fill((f32)self->unk68, 7, colorB.r, colorB.g, colorB.b, colorB.a, temp);
    }
    self->unk4C = 0;
    self->unk48 = 12;
}