#include <types.h>
#pragma force_active on

extern "C" void fn_106_8820(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8880(void* object, s32 shouldDelete) {
    if (object != 0) {
        fn_106_8820(static_cast<u8*>(object) + 8, -1);
        if (static_cast<s16>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
