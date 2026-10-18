#include <types.h>
#pragma force_active on

extern "C" void* fn_111_DCCC(void* object, s16 deleting) {
    if (object && deleting > 0) {
        operator delete(object);
    }
    return object;
}
