#pragma force_active on
#include <types.h>

extern "C" s32 fn_8018C140(u8* p) {
    s32 ret = 0;
    if (*(u16*)(p + 0x4) == 0xFEFF) {
        if (*(u16*)(p + 0x6) == 8) {
            ret = 1;
        }
    }
    return ret;
}
