#pragma force_active on
#include <types.h>

extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_84398(void* ptr, int size);

extern "C" void* fn_27_DB95C(void* ptr, int other) {
    if (ptr != 0) {
        __destroy_arr((u8*)ptr + 0xc, (void (*)(void*, int))fn_27_84398, 0xc, 0xc);
        if (other > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
