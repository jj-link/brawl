#include <types.h>
#pragma force_active on

extern "C" void* fn_27_5AE44(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_43E4(void* object, short deleting) {
    if (object != 0) {
        fn_27_5AE44(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
