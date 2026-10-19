#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1966BC(void*, short);

#pragma dont_inline on
extern "C" void* fn_111_2B88(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1966BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
