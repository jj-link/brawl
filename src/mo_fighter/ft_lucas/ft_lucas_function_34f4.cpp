#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3570(void* object, s16 deleting);
extern "C" void* fn_114_4BC8(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_34F4(void* object, s16 deleting) {
    if (object != 0) {
        fn_114_3570(static_cast<char*>(object) + 0x3E6F0, -1);
        if (object != 0) {
            fn_114_4BC8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
