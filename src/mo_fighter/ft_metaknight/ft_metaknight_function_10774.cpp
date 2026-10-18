#include <types.h>
#pragma force_active on

extern "C" void fn_111_10830(void* object, s16 mode);
extern "C" void* __dl__FPv(void* object);

extern "C" void* fn_111_10774(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_111_10830(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
