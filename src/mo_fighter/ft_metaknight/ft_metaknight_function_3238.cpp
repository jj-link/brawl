#include <types.h>
#pragma force_active on

extern "C" void* fn_111_32FC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_3238(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_111_32FC(static_cast<u8*>(object) + 4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
