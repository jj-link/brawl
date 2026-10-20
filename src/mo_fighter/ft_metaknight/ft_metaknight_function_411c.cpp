#include <types.h>
#pragma force_active on

extern "C" void* fn_111_8D30(void* object, s16 deleting);
extern "C" void* fn_111_4194(void* object, s16 deleting);
extern "C" void* fn_111_4204(void* object, s16 deleting);

extern "C" void* fn_111_411C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_8D30(static_cast<u8*>(object) + 0xE0, -1);
        fn_111_4194(static_cast<u8*>(object) + 0x30, -1);
        fn_111_4204(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
