#include <types.h>
#pragma force_active on

extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_2B978(void* this_ptr, short param) {
    if (this_ptr != nullptr) {
        __dt__24soCollisionHitModuleImplFv(this_ptr, 0);
        if (param > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}
