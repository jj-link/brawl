#include <types.h>
#pragma force_active on

struct Fn801B8818Unk {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u8 unkC;
    u8 padD[0xE - 0xD];
    u16 unkE;
    u32 unk10;
    u8 pad14[0x1C - 0x14];
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[0x38 - 0x1E];
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
};

extern "C" void fn_801B8818(Fn801B8818Unk* self) {
    self->unk0 = 0;
    self->unk8 = 0x8000;
    self->unk4 = 0;
    self->unkC = 0;
    self->unkE = 0x8000;
    self->unkA = 0;
    self->unk10 = 0;
    self->unk1C = 0;
    self->unk1D = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk40 = 0;
    self->unk44 = 0;
}
