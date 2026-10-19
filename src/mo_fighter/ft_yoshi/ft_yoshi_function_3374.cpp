#include <types.h>
#pragma force_active on

extern "C" void fn_95_33D0(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_3374(void* self, s16 flags) {
    if (self != 0) {
        fn_95_33D0(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
