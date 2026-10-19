#include <stddef.h>
#pragma force_active on

extern "C" {
void* __dt__22soControllerModuleImplFv(void*, short);
void __dl__FPv(void*);

void* fn_122_6B18(void* self, short flag) {
    if (self != NULL) {
        __dt__22soControllerModuleImplFv(self, static_cast<short>(0));
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
