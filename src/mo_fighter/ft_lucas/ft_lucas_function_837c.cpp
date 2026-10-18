#include <types.h>
#pragma force_active on

extern "C" void* fn_114_46D8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_837C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_114_46D8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
