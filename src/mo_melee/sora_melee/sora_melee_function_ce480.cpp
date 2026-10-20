#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_25290(void* ptr, int count);

extern "C" void* fn_27_CE480(void* ptr, int flags) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0xE);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
