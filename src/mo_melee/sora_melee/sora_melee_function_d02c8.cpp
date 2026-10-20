#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_25290(void* ptr, int count);

extern "C" void* fn_27_D02C8(u8* self, int flags) {
    if (self) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x25);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
