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
s32 fn_803C43AC(void);

s32 fn_803C7EEC(void) {
    u32 idx = fn_803C43AC();
    LblEntry *p;
    if (idx < 0x1A)
        p = &lbl_80563590[idx];
    else
        p = NULL;
    if (p != NULL)
        return p->unk10;
    return 0;
}
