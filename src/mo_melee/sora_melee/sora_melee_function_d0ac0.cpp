#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_25290(void*, int);

extern "C" {
void* fn_27_D0AC0(void* self, s32 flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_25290, 0x30, 0x34);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
