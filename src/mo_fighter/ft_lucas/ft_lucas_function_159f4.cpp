#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5B0C(void* p, s16 n);
void operator delete(void* object);

extern "C" void* fn_114_159F4(void* object, short deleting) {
    if (object != 0) {
        fn_114_5B0C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
