#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), u32, u32);
void fn_27_CDA70(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_19EFFC(void* self, s32 flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_CDA70, 0x10, 2);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
