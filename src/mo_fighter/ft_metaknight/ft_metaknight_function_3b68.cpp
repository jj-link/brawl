#include <types.h>
#pragma force_active on

extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void* fn_111_1E48(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_3B68(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_75E0C(static_cast<u8*>(object) + 0x4C, -1);
        if (static_cast<u8*>(object) + 0x20 != 0) {
            fn_27_64930(static_cast<u8*>(object) + 0x20, 0);
        }
        fn_111_1E48(static_cast<u8*>(object) + 0x14, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
