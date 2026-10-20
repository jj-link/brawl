#include <types.h>
#pragma force_active on

extern "C" void* fn_27_25290(void* ptr, int count);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D15E8(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x5c);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
