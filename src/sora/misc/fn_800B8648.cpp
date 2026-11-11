#include <types.h>
#pragma force_active on
extern "C" s32 fn_8006C7D4(s32);
extern "C" s32 fn_8006C870(s32);
extern "C" s32 fn_8006C950(s32);
extern "C" u8 fn_800B8648(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((u32)((*(u8*)(arg0 + 0x10) >> 7) & 1) == 1U) return 0;
    u32 orval;
    s32 flag;
    flag = arg1;
    if (arg1 & 4) flag = arg1 & ~1;
    orval = 0;
    for (s32 i = 0; i < 16; i++) orval |= arg0[i];
    if ((flag & 1) && !(orval & 1)) {
        s32 val = arg2;
        if (arg2 == 0xFF) val = 0x2F;
        if (arg3 == 0) fn_8006C7D4(val);
        else fn_8006C870(val);
    }
    if ((flag & 4) && !(orval & 4)) {
        s32 val2 = arg2;
        if (arg2 == 0xFF) val2 = 0x31;
        fn_8006C950(val2);
    }
    s32 idx;
    for (idx = 0; idx < 16; idx++) {
        if (arg0[idx] == 0) break;
    }
    *(u8*)(arg0 + idx) = (u8)arg1;
    return (u8)idx;
}