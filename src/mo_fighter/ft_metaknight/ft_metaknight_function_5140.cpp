#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_5140(void* object, s16 deleting) {
    if (object && deleting > 0) {
        __dl__FPv(object);
    }
    return object;
}
