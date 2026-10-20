#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1CBE4(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1CC24(void* self, s32 n) {
    if (self) {
        __destroy_arr((void*)((u8*)self + 0xc), (void (*)(void*, int))fn_27_1CBE4, 0xc, 0x14);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
