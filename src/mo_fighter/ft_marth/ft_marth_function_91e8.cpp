#include <types.h>
#pragma force_active on

extern "C" void fn_106_918C(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_91E8(void* ptr, s32 flag) {
    if (ptr != 0) {
        fn_106_918C((u8*)ptr + 4, -1);
        if ((s16)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
