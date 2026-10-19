#include <stddef.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_47_49F4(void* ptr, int size);
}

extern "C" void* fn_47_3EE8(void* ptr, int size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_47_49F4, 0xa0, 1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
