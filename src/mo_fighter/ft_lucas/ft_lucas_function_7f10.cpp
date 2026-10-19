#include <types.h>
#pragma force_active on

extern "C" void fn_27_64D9C(void*, short);
void operator delete(void*);

extern "C" void* fn_114_7F10(void* object, short deleting) {
    if (object != 0) {
        fn_27_64D9C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
