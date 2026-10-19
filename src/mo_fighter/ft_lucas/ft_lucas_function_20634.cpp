#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A4D90(void* ptr, short count);
void operator delete(void* object);

extern "C" void* fn_114_20634(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A4D90(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
