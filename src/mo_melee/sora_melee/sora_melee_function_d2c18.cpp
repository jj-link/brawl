#include <types.h>
#pragma force_active on

extern "C" void fn_27_C940C(void);
extern "C" void __destroy_arr(void*, void (*)(void*), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D2C18(void* self, s32 flag) {
    if (self) {
        __destroy_arr((u8*)self + 0xc, (void (*)(void*))fn_27_C940C, 0x10, 7);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
