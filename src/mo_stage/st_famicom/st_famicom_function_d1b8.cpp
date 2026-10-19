#include <types.h>
#pragma force_active on

extern "C" void* fn_68_5E20(void* p, int n);
extern "C" void __destroy_arr(void* ptr, void* (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_68_D1B8(void* ptr, int n) {
    if (ptr) {
        __destroy_arr((void*)((u8*)ptr + 0xc), fn_68_5E20, 8, 7);
        if (n > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}