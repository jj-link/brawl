#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void __dt__18soCollisionHitPartFv(void*, int);

extern "C" void* fn_27_19B704(u8* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 0x14);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
