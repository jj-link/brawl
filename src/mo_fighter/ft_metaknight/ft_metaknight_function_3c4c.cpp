#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3CAC(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_3C4C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3CAC(static_cast<u8*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
