#include <types.h>
#pragma force_active on

extern "C" void fn_121_173D4(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_17378(void* self, s16 param) {
    if (self != nullptr) {
        fn_121_173D4(self, -1);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
