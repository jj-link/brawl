#include <types.h>
#pragma force_active on

extern "C" void* fn_111_10D04(void* object, s16 deleting) {
    if (object && deleting > 0) {
        operator delete(object);
    }
    return object;
}
