#include <types.h>
#pragma force_active on

extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CC3D8(u8* self, s32 flags) {
    if (self != nullptr) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 10);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
