#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_46700(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_27_19E828(void* self, s32 flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_46700, 0x60, 9);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
