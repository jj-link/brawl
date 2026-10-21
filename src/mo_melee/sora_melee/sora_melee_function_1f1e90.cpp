#pragma force_active on
#include <types.h>

extern "C" s32 fn_27_1F1E90(void* mgr, s8* fighterId) {
    s8 val = *fighterId;
    s32 flag = 0;
    if (val >= 0 && val < 14) {
        flag = 1;
    }
    if (flag == 0) goto ret0;
    s32 q;
    if (val >= 0 && val < 14) {
        q = val / 7;
    } else {
        q = 0;
    }
    if (q != 0) goto ret0;
    s32 off;
    if (val >= 0 && val < 14) {
        off = val % 7;
    } else {
        off = val;
    }
    if (*(u32*)((u8*)mgr + 0x348) == 0 || *(s8*)((u8*)mgr + off + 0x84) <= 0) return 1;
    goto ret0;
ret0:
    return 0;
}
