#include <types.h>
#pragma force_active on

extern "C" void fn_27_1374C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_C9D44(void* self, int arg) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xC, fn_27_1374C, 0x48, 1);
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
