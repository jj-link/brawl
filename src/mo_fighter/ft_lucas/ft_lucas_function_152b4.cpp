#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_152B4(void* self, s16 flag) {
    if (self != 0 && flag > 0) {
        __dl__FPv(self);
    }
    return self;
}
