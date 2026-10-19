#include <types.h>
#pragma force_active on

extern "C" void fn_102_11898(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1183C(void* self, s32 arg) {
    if (self != 0) {
        s32 val = -1;
        fn_102_11898(self, (s16)val);
        if ((s16)arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
