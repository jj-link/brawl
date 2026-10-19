#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_625C(void*, s8);

extern "C" s32 fn_41_7060(void* p, s32 c) {
    s32 result = 0;
    if (fn_27_625C(p, (s8)c) == 1 || (s8)c == 0x65) {
        result = 1;
    }
    return result;
}
