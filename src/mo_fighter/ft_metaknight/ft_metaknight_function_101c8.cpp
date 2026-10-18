#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A262C(void*, s16);
extern "C" void operator delete(void*);

extern "C" void* fn_111_101C8(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A262C(static_cast<u8*>(object) + 0x10, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
