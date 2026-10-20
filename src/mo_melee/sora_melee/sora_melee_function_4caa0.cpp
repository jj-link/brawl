#include <types.h>
#pragma force_active on

extern "C" {
extern void* fn_27_37D3C(void*, s32);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_4CAA0(void* self, short deleting) {
    if (self) {
        __destroy_arr((char*)self + 0xc, (void(*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (deleting > 0)
            __dl__FPv(self);
    }
    return self;
}
