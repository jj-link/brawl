#include <types.h>
#pragma force_active on

s32 fn_8027B4C4(u8* arg0, s32 arg1, s32 arg2) {
    u8* p = arg0 + arg1 * 0x68;
    if (*(s32*)(p + 0x50) != 0 && arg2 == *(s32*)(p + 0x58)) {
        return 1;
    }
    return 0;
}
