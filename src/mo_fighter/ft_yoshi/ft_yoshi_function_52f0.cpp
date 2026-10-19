#include <types.h>
#pragma force_active on

extern "C" void* fn_95_536C(void* object, s16 deleting);
extern "C" void* fn_95_585C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_95_52F0(void* object, s16 deleting) {
    if (object != 0) {
        fn_95_536C(static_cast<char*>(object) + 0xBCAC, -1);
        if (object != 0) {
            fn_95_585C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
