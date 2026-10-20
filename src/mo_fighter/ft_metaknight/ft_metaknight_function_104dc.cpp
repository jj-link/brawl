#include <types.h>
#pragma force_active on

extern "C" void* fn_27_B5324(void* object, s16 deleting);
extern "C" void* fn_111_10560(void* object, s16 deleting);
extern "C" void* fn_111_3DF4(void* object, s16 deleting);

extern "C" void* fn_111_104DC(void* object, s16 deleting) {
    if (object != 0) {
        u8* p = static_cast<u8*>(object);
        fn_27_B5324(p + 0x20, -1);
        fn_111_10560(p + 0x10, -1);
        if (object != 0) {
            fn_111_3DF4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma force_active off
