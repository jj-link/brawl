#include <types.h>
#pragma force_active on

extern "C" void fn_123_3264(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3208(void* self, s16 arg) {
    if (self) {
        fn_123_3264(self, -1);
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
