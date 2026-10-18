#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1FE4(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

#pragma dont_inline on
extern "C" void* fn_111_5B14(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A1FE4(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
