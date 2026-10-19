#include <types.h>
#pragma force_active on

extern "C" void* fn_27_14CD30(void* object, short deleting);

#pragma dont_inline on
extern "C" void* fn_111_2AD0(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_14CD30(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
