#include <types.h>
#pragma force_active on

extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37B3E0(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0xAC, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
