#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3238(void* object, s16 deleting);
extern "C" void* fn_111_3FFC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_31C8(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3238(static_cast<u8*>(object) + 8, -1);
        fn_111_3FFC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
