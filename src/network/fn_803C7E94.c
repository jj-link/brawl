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
extern s32 fn_803C43AC(void);

void fn_803C7E94(s32 arg0, s32 arg1) {
    LblEntry *ptr;
    u32 index = fn_803C43AC();
    if (index < 0x1A) {
        ptr = &lbl_80563590[index];
    } else {
        ptr = 0;
    }
    if (ptr != 0) {
        ptr->unkC = arg1;
    }
}
