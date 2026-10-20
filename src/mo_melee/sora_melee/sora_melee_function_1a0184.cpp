#include <types.h>
#pragma force_active on

extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1A0184(void* self, s32 flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 2);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
