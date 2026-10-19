#include <types.h>
#pragma force_active on

extern "C" void fn_121_7908(void* object, s16 deleting);
extern "C" void fn_121_7664(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_121_7974(void* object, s16 deleting) {
    if (object != 0) {
        fn_121_7908(static_cast<char*>(object) + 0x8770, -1);
        if (object != 0) {
            fn_121_7664(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
