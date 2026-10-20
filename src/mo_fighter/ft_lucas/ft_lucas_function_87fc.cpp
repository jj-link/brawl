#include <types.h>
#pragma force_active on

extern "C" void* __dt__17soModelModuleImplFv(void* object, short deleting);
extern "C" void* fn_114_8874(void* object, short deleting);
extern "C" void* fn_27_19A83C(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_87FC(void* object, short deleteFlag) {
    if (object != 0) {
        char* base = static_cast<char*>(object);
        __dt__17soModelModuleImplFv(base + 0x1f4, -1);
        fn_114_8874(base + 0x1ac, -1);
        fn_27_19A83C(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
