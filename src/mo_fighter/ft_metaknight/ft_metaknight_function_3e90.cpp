#include <types.h>
#pragma force_active on

extern "C" void* __dt__19soPostureModuleImplFv(void* object, s16 flag);
extern "C" void* fn_27_19FFEC(void* object, s16 flag);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_3E90(u8* object, s16 flags) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(object + 0x3C, -1);
        if (object != 0) {
            fn_27_19FFEC(object, -1);
        }
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
