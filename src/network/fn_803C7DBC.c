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

void fn_803C7DBC(s32 arg0, s32 arg1) {
    if (arg0 < 0) {
        return;
    }
    if (arg0 >= 0x1A) {
        return;
    }
    lbl_80563590[arg0].unk4 = arg1;
}
