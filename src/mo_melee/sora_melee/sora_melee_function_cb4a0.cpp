#include <types.h>
#pragma force_active on

extern "C" void fn_27_B164C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CB4A0(void* self, int which) {
    if (self != 0) {
        __destroy_arr((u8*)self + 0xC, fn_27_B164C, 0x44, 1);
        if (which > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
