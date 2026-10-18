#include <types.h>
#pragma force_active on

extern "C" void fn_108_32A4(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_3248(void* self, s32 p2) {
    if (self != 0) {
        fn_108_32A4(self, -1);
        if ((s16)p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
