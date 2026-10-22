#include <types.h>
#pragma force_active on

struct AiInput {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ u8 unk40;
    /* 0x041 */ s8 unk41;
    /* 0x042 */ s8 fighterId;
    /* 0x043 */ u8 unk43;
    /* 0x044 */ char pad44[4];
    /* 0x048 */ s32 mode;
    /* 0x04C */ char pad4C[0xC];
    /* 0x058 */ s16 unk58;
    /* 0x05A */ s16 unk5A;
    /* 0x05C */ char pad5C[4];
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 unk61;
    /* 0x062 */ u8 unk62;
    /* 0x063 */ u8 unk63;
    /* 0x064 */ u8 unk64;
    /* 0x065 */ u8 unk65;
    /* 0x066 */ s8 counter66;
    /* 0x067 */ s8 unk67;
    /* 0x068 */ u16 unk68;
    /* 0x06A */ s16 unk6A;
    /* 0x06C */ char pad6C[8];
    /* 0x074 */ u8 unk74;
    /* 0x075 */ char pad75[1];
    /* 0x076 */ u8 unk76;
    /* 0x077 */ u8 unk77;
    /* 0x078 */ f32 unk78;
    /* 0x07C */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ char pad84[4];
    /* 0x088 */ s16 unk88;
    /* 0x08A */ char pad8A[2];
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ char pad90[0x80];
    /* 0x110 */ s8 targetId;
};

extern "C" {
void fn_27_1F9FBC(AiInput* self, s32 mode, s8* fighterId, u32 script, s32 argument);
extern const f32 lbl_27_rodata_2CF0[34];

void fn_27_1FAD54(AiInput* self) {
    s8 sp8;
    s32 minus1 = -1;
    sp8 = (s8)minus1;
    fn_27_1F9FBC(self, 0, &sp8, 0, 0);
    self->mode = 0;
    self->targetId = self->fighterId;
    self->unk58 = 0;
    self->unk5A = 0;
    self->unk6A = 0;
    self->unk74 = 0;
    self->unk60 = 0;
    self->unk61 = 0;
    self->unk62 = 0;
    self->unk63 = 0;
    self->unk64 = 0;
    self->unk65 = 0;
    self->counter66 = 0;
    self->unk68 = 0;
    self->unk67 = minus1;
    self->unk88 = 0;
    self->unk41 = minus1;
    self->unk40 = 0;
    self->unk8C = lbl_27_rodata_2CF0[0];
    self->unk78 = lbl_27_rodata_2CF0[0];
    self->unk7C = lbl_27_rodata_2CF0[0];
    self->unk80 = lbl_27_rodata_2CF0[0];
    self->unk77 = 0;
    self->unk76 = 0;
}
}
