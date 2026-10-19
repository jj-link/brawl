#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1CA4(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_1E1C(void* object, short deleting) {
    if (object != 0) {
        fn_114_1CA4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
