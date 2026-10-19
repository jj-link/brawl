#include <types.h>
#pragma force_active on

extern "C" void* fn_111_1EA4(void* object, s16 deleting);
extern "C" void* fn_111_3B08(void* object, s16 deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_111_4204(void* object, s16 deleting) {
    if (object != 0) {
        s16 zero = 0;
        fn_111_1EA4(static_cast<u8*>(object) + 0x20, zero);
        fn_111_3B08(object, zero);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
