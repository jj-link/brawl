#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), u32, u32);
void __dt__18soCollisionHitPartFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_19ADE4(void* self, int flag) {
    if (self) {
        __destroy_arr((u8*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 0xb);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
