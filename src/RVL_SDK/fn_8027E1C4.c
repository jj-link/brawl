#include <types.h>
#pragma force_active on

extern u8 lbl_804862F0[];

typedef struct Fn27Obj {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Fn27Obj;

void fn_8027E1C4(Fn27Obj *self) {
    self->unk0 = lbl_804862F0;
    self->unkC = 1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk4 = 0;
    self->unk8 = 0x7FFFFFFF;
}
