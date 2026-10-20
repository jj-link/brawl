#include <types.h>
#pragma force_active on

extern "C" void fn_27_AB18C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_384EEC(void* array, s32 flag) {
    if (array) {
        __destroy_arr((char*)array + 0xC, fn_27_AB18C, 0x14, 2);
        if (flag > 0)
            __dl__FPv(array);
    }
    return array;
}
