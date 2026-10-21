#include <types.h>
#pragma force_active on

extern "C" void fn_801911B0(u8** arg0, s32 arg1, s32* arg2, u8* arg3) {
    u8* base = *arg0;
    if (base != 0 && arg1 >= 1 && arg1 <= 3) {
        if (arg2 != 0) {
            *arg2 = (s32)((u8*)(arg1 + (s32)base))[3];
        }
        if (arg3 != 0) {
            *arg3 = (u8)((u8*)(arg1 + (s32)base))[7];
        }
    }
}
