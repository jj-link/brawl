#include <types.h>
#pragma force_active on

extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void fn_27_CC984(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_19B704(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_5564(void* object, short flag) {
    if (object != NULL) {
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(object) + 0x8F4, -1);
        fn_27_CC984(static_cast<char*>(object) + 0x8B0, -1);
        fn_27_4CAA0(static_cast<char*>(object) + 0x82C, -1);
        fn_27_19B704(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
