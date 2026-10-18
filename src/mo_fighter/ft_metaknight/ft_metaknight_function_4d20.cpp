#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_4D20(void* object, s16 deleting) {
    if (object) {
        if (object) {
            fn_27_1A15B8(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
