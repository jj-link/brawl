#include <types.h>
#pragma force_active on

extern "C" {
void fn_94_14058(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_13FFC(void* self, short flags) {
    if (self != nullptr) {
        fn_94_14058(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
