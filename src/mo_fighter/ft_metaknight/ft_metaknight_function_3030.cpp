#include <types.h>
#pragma force_active on

extern "C" void* fn_27_198CB8(void* p, s16 n);

#pragma dont_inline on
extern "C" void* fn_111_3030(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_198CB8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
