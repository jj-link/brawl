#include <types.h>
#pragma force_active on

extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_41_2EFA4(void* object, short deleteFlag);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F000(void* object, short deleteFlag) {
    if (object != nullptr) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x158, -1);
        fn_41_2EFA4(static_cast<char*>(object) + 0x110, -1);
        fn_27_CBDE8(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
