#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1966BC(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_2DE4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1966BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
