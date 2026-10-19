#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A3B48(void* ptr, short count);
extern "C" void __dl__FPv(void*);

#pragma dont_inline on
extern "C" void* fn_111_430C(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A3B48(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
