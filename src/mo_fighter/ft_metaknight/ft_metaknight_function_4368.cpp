#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3C4C(void* object, s16 deleting);
extern "C" void* fn_111_43E0(void* object, s16 deleting);
extern "C" void* fn_27_19E99C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_4368(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3C4C(static_cast<u8*>(object) + 0x85C, -1);
        fn_111_43E0(static_cast<u8*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
