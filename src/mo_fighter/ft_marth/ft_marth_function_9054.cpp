#include <types.h>
#pragma force_active on

extern "C" void fn_106_8FF4(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_9054(void* object, s32 deleting) {
    if (object != 0) {
        fn_106_8FF4(static_cast<u8*>(object) + 4, -1);
        if (static_cast<s16>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
