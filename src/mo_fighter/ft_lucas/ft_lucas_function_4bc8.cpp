#include <types.h>
#pragma force_active on

extern "C" void fn_114_4C44(void* object, short deleting);
extern "C" void fn_114_51E0(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_4BC8(void* object, short deleting) {
    if (object != 0) {
        fn_114_4C44(static_cast<char*>(object) + 0x39ecc, -1);
        if (object != 0) {
            fn_114_51E0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
