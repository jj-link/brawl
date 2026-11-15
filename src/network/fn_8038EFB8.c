#include <types.h>
#pragma force_active on

static inline s32 scan(s32 value) {
    s32 i = 0;
    s32 mask = 1;
    for (; i < 32; i++) {
        if (value & mask)
            return i;
        mask <<= 1;
    }
    return -1;
}

s32 fn_8038EFB8(s32 arg0, s32 arg1, s32 arg2) {
    s32 result = 99;
    if (arg0 != 0) {
        if (arg1 == 0 && arg2 == 0)
            result = scan(arg0) + 20;
    } else if (arg1 != 0) {
        if (arg2 == 0)
            result = scan(arg1) + 30;
    } else if (arg2 != 0) {
        result = scan(arg2) + 40;
    }
    return result;
}
