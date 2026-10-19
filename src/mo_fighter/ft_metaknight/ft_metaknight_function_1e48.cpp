#include <types.h>
#pragma force_active on

extern "C" void fn_27_7700(void*, short);

#pragma dont_inline on
extern "C" void* fn_111_1E48(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_7700(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
