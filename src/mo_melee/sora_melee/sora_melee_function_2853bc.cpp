#include <types.h>
#pragma force_active on

extern "C" {
    extern u32 fn_27_625C(void*, s8);

    u32 fn_27_2853BC(void* p, s8 c) {
        u32 result = 0;
        if (fn_27_625C(p, c) != 0 || c == 0x65) {
            result = 1;
        }
        return result;
    }
}
