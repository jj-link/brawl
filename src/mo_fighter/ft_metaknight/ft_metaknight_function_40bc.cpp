#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3A2C(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

#pragma dont_inline on
extern "C" void* fn_111_40BC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3A2C(static_cast<u8*>(object) + 0x1C0, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
