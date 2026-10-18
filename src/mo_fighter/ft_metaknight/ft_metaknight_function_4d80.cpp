#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3A2C(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_4D80(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3A2C(static_cast<u8*>(object) + 0xB0, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
