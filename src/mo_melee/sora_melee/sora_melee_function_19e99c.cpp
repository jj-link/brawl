#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_AB18C(void* self, short flag);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);

void* fn_27_19E99C(void* self, short flag) {
    if (self) {
        __destroy_arr((u8*)self + 0xC, (void (*)(void*, int))fn_27_AB18C, 0x14, 0x14);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
