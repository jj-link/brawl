#include <types.h>
#pragma force_active on

typedef struct FnObj {
    void *unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
    void *unk14;
    s32 pad18[3];
    s32 unk24;
    s32 pad28[8];
    s32 unk48;
} FnObj;

extern void *fn_8035DFE8(s32);
extern void *memset(void *, s32, u32);

void *fn_8038D77C(FnObj *arg0, void *arg1, s32 arg2, void *arg3, void *arg4) {
    FnObj *temp_r31;

    arg0->unk48 = 0;
    if (arg2 == 0) {
        arg0->unk48 = 3;
        return NULL;
    }
    if (arg0->unk0 == NULL || arg0->unk24 == 0) {
        arg0->unk48 = 1;
        return NULL;
    }
    temp_r31 = fn_8035DFE8(0x24);
    if (temp_r31 == NULL) {
        arg0->unk48 = 2;
        return NULL;
    }
    memset(temp_r31, 0, 0x24);
    temp_r31->unk0 = arg0;
    temp_r31->unk4 = arg1;
    temp_r31->unk8 = arg2;
    temp_r31->unk10 = arg3;
    temp_r31->unk14 = arg4;
    return temp_r31;
}
