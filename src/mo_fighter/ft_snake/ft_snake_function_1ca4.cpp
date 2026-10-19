#include <types.h>
#pragma force_active on

extern "C" {
void fn_122_1AD0(void* self, s16 flag);
void __dl__FPv(void*);
}

extern "C" void* fn_122_1CA4(void* self, s16 flag) {
    if (self != 0) {
        fn_122_1AD0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
