#include <types.h>
#pragma force_active on

extern "C" void* fn_27_19874C(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_308C(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_19874C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
