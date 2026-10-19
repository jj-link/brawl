#include <types.h>

extern "C" void fn_125_32FC(void*, s16);
extern "C" void __dl__FPv(void*);

#pragma force_active on
extern "C" void* fn_125_32A0(void* self, s16 should_delete) {
    if (self != 0) {
        fn_125_32FC(self, -1);
        if (should_delete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
