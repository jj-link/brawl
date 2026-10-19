#include <types.h>
#pragma force_active on

extern "C" void fn_27_66114(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_7EB4(void* object, short deleting) {
    if (object != 0) {
        fn_27_66114(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
