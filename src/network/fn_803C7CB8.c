#include <types.h>
#pragma force_active on

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} LblEntry;

extern LblEntry lbl_80563590[];
extern s32 fn_803C43AC();

void fn_803C7CB8(void *arg0, s32 arg1) {
    u32 temp = fn_803C43AC();
    LblEntry *ptr;
    if (temp < 0x1A) {
        ptr = &lbl_80563590[temp];
    } else {
        ptr = NULL;
    }
    if (ptr != NULL) {
        ptr->unk0 = arg1;
    }
}
