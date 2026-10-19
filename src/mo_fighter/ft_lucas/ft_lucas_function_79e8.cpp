#include <types.h>
#pragma force_active on

extern "C" void fn_114_7A54(void* object, s16 value);
extern "C" void fn_114_42B8(void* object, s16 value);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_79E8(void* object, s16 deleteFlag) {
    if (object != 0) {
        s16 invalid = -1;
        fn_114_7A54((u8*)object + 0x24, invalid);
        fn_114_42B8(object, invalid);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
