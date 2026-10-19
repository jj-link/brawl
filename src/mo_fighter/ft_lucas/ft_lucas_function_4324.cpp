#include <types.h>
#pragma force_active on

extern "C" void* fn_27_A1E80(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_4324(void* object, short deleting) {
    if (object != 0) {
        fn_27_A1E80(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
