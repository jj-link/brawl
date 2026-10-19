#include <types.h>
#pragma force_active on

extern "C" void* fn_111_10830(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_107D4(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_10830(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
