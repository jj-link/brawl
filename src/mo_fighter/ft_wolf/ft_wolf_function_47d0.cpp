#include <types.h>
#pragma force_active on

extern "C" void* fn_125_484C(void* object, s16 deleting);
extern "C" void* fn_125_51A0(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_125_47D0(void* object, s16 deleting) {
    if (object == 0) {
    } else {
        fn_125_484C(static_cast<char*>(object) + 0x8700, -1);
        if (object != 0) {
            fn_125_51A0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
