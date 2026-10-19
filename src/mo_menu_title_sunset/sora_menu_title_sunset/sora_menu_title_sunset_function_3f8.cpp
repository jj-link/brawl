#include <types.h>
#pragma force_active on

struct Fn25Unk {
    u8 pad0[0x2c];
    u8 unk2C;
    u8 pad2D[0x60 - 0x2D];
    s32 unk60;
    s32 unk64;
    s32 pad68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 unk7C;
    u8 pad7D[0x84 - 0x7D];
    s32 unk84;
};

extern "C" void fn_25_3F8(Fn25Unk* self) {
    u8 flags = self->unk2C;
    s32 zero = 0;
    self->unk60 = zero;
    flags &= ~2;
    self->unk2C = flags;
    self->unk64 = zero;
    self->unk6C = zero;
    self->unk70 = zero;
    self->unk74 = 2;
    self->unk78 = zero;
    self->unk7C = 0;
    self->unk84 = zero;
}
