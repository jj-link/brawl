#include <types.h>
#pragma force_active on

extern "C" void fn_111_335C(void* object, s16 deleting);
extern void operator delete(void*);

extern "C" void* fn_111_32FC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_335C(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
