#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1CA4(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1D08(void* object, short deleting) {
    if (object != 0) {
        fn_114_1CA4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
