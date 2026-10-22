#include <types.h>
#pragma force_active on

extern "C" void fn_802987AC(void*, u32, u32, u32, u32);
extern f32 lbl_805A4310;

struct Fn802E0D84Obj {
    u8 pad0[0x4];
    void* unk4;
    u8 pad8[0x4];
    u32 unkC;
    u8 pad10[0xC];
    u32 unk1C;
    u8 pad20[0x4];
    u32 unk24;
    u8 pad28[0x4];
    u32 unk2C;
    u8 pad30[0x4];
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u8 pad40[0x4];
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    f32* unk54;
    f32* unk58;
};

extern "C" void fn_802E0D84(Fn802E0D84Obj* self, s32 arg1) {
    f32* p;
    f32* end;
    f32 val;

    if (arg1 == 0) {
        self->unk38 = self->unk2C;
        self->unk48 = self->unk3C;
    }
    p = self->unk58;
    val = lbl_805A4310;
    while (p < (end = self->unk54)) {
        *p = val;
        p++;
    }
    self->unk58 = end;
    if (self->unk38 != self->unk34) {
        fn_802987AC(self->unk4, self->unk38, self->unkC, self->unk1C, self->unk24);
    }
    if (self->unk48 != self->unk44) {
        fn_802987AC(self->unk4, self->unk48, self->unkC, self->unk1C, self->unk24);
    }
    self->unk38 = self->unk34;
    self->unk48 = self->unk44;
}
