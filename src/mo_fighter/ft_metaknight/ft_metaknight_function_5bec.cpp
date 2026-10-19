#include <types.h>
#pragma force_active on

extern "C" void* fn_27_CC7EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_5BEC(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_CC7EC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
