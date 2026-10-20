#include <types.h>
#pragma force_active on

extern "C" void fn_27_25290(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D0F88(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, fn_27_25290, 0x30, 0x40);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
