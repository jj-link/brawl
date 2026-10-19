#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_112_19B0(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_112_A524(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x2979C, -1);
        fn_112_19B0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
