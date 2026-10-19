#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C21DC(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_2E40(void* object, short deleting) {
    if (object != 0) {
        fn_27_C21DC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
