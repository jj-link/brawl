#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_114_7318(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_72A0(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<char*>(object) + 0x318, -1);
        if (object != 0) {
            fn_114_7318(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
