#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1511C(void* ptr, short size);
void operator delete(void* object);

extern "C" void* fn_114_150C0(void* object, short deleting) {
    if (object != 0) {
        fn_114_1511C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
