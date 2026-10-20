#include <types.h>
#pragma force_active on

extern "C" {
void fn_124_A1A0(void* self, s16 flag);
void __dl__FPv(void* p);

void* fn_124_A218(void* self, s16 flag) {
    if (self != 0) {
        fn_124_A1A0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
