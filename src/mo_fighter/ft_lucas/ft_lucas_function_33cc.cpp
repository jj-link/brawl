#include <types.h>
#pragma force_active on

extern "C" void fn_114_3428(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_33CC(void* object, short deleting) {
    if (object != 0) {
        fn_114_3428(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
