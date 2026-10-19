#include <types.h>
#pragma force_active on

extern "C" void* fn_27_BED74(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_2E9C(void* object, short deleting) {
    if (object != 0) {
        fn_27_BED74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
