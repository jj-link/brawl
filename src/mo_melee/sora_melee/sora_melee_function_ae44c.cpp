#include <types.h>
#pragma force_active on

extern "C" void* fn_27_ACEE4(void* ptr, s32 size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_AE44C(void* ptr, s32 size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_ACEE4, 0xc, 1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
