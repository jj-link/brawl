#include <types.h>
#pragma force_active on

extern "C" void* fn_27_840D8(void* ptr, int size);
extern "C" void __dl__FPv(void* ptr);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

extern "C" void* fn_27_1B2118(void* ptr, int size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_840D8, 0xc, 4);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
