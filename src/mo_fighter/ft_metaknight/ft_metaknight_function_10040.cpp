#include <types.h>
#pragma force_active on

extern "C" void* fn_111_1009C(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_10040(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_1009C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
