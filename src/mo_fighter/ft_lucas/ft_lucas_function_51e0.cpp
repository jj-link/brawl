#include <types.h>
#pragma force_active on

extern "C" void* fn_114_525C(void* object, s16 deleting);
extern "C" void* fn_114_5C2C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_51E0(void* object, short deleting) {
    if (object != 0) {
        fn_114_525C(static_cast<char*>(object) + 0x1E298, -1);
        if (object != 0) {
            fn_114_5C2C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
