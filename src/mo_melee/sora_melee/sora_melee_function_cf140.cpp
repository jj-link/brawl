#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_25290(void* ptr, int count);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CF140(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x19);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
