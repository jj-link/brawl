#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_95_F17C(void* self, short flag) {
    if (self != NULL && flag > 0) {
        __dl__FPv(self);
    }
    return self;
}
