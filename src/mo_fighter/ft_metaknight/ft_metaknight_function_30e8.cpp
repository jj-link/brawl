#include <types.h>
#pragma force_active on

extern "C" void* fn_27_93100(void*, s16);
extern "C" void* fn_111_316C(void*, s16);
extern "C" void* fn_27_19F4C4(void*, s16);
extern "C" void* fn_27_1A55B0(void*, s16);

extern "C" void* fn_111_30E8(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<u8*>(object) + 0x213c, -1);
        fn_111_316C(static_cast<u8*>(object) + 0x7c, -1);
        fn_27_19F4C4(static_cast<u8*>(object) + 0x20, -1);
        fn_27_1A55B0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
