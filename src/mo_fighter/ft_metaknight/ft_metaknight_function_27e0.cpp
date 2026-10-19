#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A62E4(void* p, s16 n);

#pragma dont_inline on
extern "C" void* fn_111_27E0(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A62E4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
