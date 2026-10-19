#include <types.h>
#pragma force_active on

extern "C" void fn_27_69684(void*, short);
void operator delete(void*);

extern "C" void* fn_114_7DFC(void* object, short deleting) {
    if (object != 0) {
        fn_27_69684(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
