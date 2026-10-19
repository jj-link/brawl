#include <types.h>
#pragma force_active on

extern "C" void fn_27_64D9C(void*, short);

#pragma dont_inline on
extern "C" void* fn_111_5308(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_64D9C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
