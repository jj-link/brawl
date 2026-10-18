#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3A60(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_1515C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_114_3A60(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
