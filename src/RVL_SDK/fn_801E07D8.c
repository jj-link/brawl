#include <types.h>
#pragma force_active on

extern s32 lbl_805A06F8;

typedef struct Obj {
    struct Obj *unk0;
    struct Obj *unk4;
    u8 pad8[0x2D0 - 8];
    s32 unk2D0;
    s32 pad2D4;
    s32 pad2D8;
    struct Obj *unk2DC;
    struct Obj *unk2E0;
    struct Obj *unk2E4;
} Obj;

void fn_801E07D8(Obj *arg0) {
    Obj *temp_r4;
    Obj *temp_r5;
    Obj *temp_r6;

    temp_r5 = arg0->unk2E0;
    temp_r4 = arg0->unk2DC;
    temp_r6 = arg0->unk2E4;
    if (temp_r5 == NULL) {
        temp_r4->unk4 = temp_r6;
    } else {
        temp_r5->unk2E4 = temp_r6;
    }
    if (temp_r6 == NULL) {
        temp_r4->unk0 = temp_r5;
    } else {
        temp_r6->unk2E0 = temp_r5;
    }
    if (temp_r4->unk0 == NULL) {
        lbl_805A06F8 &= ~(1 << (0x1F - arg0->unk2D0));
    }
    arg0->unk2DC = NULL;
}
