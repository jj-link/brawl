#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_88118(void*, s8);

extern "C" u32 fn_27_2B9A08(void* self, s8 c) {
    u32 result = 0;
    if (fn_27_88118(self, c) != 0 || c == 0x66) {
        result = 1;
    }
    return result;
}
