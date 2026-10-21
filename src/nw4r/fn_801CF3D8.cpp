#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_80466C78[];
}

struct Fn801CF3D8 {
    void* unk0;
    u32 unk4;
    u32 unk8;
    u8 unkc;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1c;
    u32 unk20;
    s32 unk24;
    u8 unk28;
    u32 unk2c;
    u32 unk30;
};

extern "C" void fn_801CF3D8(Fn801CF3D8* self) {
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkc = 0;
    self->unk0 = &lbl_80466C78;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1c = 0;
    self->unk20 = 0;
    self->unk24 = -1;
    self->unk28 = 0;
    self->unk2c = 0;
    self->unk30 = 0;
}
