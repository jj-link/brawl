#include <types.h>
#pragma force_active on

extern "C" void fn_27_1362C(void*, short);
void operator delete(void*);

extern "C" void* fn_114_20E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1362C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
