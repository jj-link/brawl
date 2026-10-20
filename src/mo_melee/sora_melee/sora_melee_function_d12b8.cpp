#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_25290(void* ptr, int count);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_D12B8(void* ptr, int count) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x4c);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
