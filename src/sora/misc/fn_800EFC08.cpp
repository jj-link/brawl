#include <types.h>
#pragma force_active on

struct Fn800EFC08 {
    u32 unk0[18];
    u8 unk48;
    u32 unk4c;
    u32 unk50;
    u32 unk54; u32 unk58; u32 unk5c; u32 unk60;
    u8 unk64;
    u8 pad65[3];
    u32 unk68; u32 unk6c; u32 unk70;
};

extern "C" void fn_800EFC08(Fn800EFC08* self) {
    int i;
    for (i = 0; i < 18; i++) self->unk0[i] = 0;
    self->unk48 = 0;
    self->unk4c = 0;
    self->unk50 = 2;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5c = 0;
    self->unk70 = 0;
    self->unk60 = 0;
    self->unk64 = 1;
    self->unk68 = 0;
    self->unk6c = 0;
}
