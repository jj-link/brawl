#include <types.h>
#pragma force_active on

extern "C" void* fn_111_39EC(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

#pragma dont_inline on
extern "C" void* fn_111_F564(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_39EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
