#include <types.h>
#pragma force_active on

extern "C" void* fn_115_33C8(void* object, s16 deleting);
extern "C" void* fn_115_3E90(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_115_334C(void* object, s16 deleting) {
    if (object != 0) {
        fn_115_33C8(static_cast<char*>(object) + 0x1A8F8, -1);
        if (object != 0) {
            fn_115_3E90(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
