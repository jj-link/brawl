#include <types.h>
#pragma force_active on

extern "C" void* fn_27_63EBC(void*, short);
void operator delete(void*);

extern "C" void* fn_114_3BC4(void* object, short deleting) {
    if (object != 0) {
        fn_27_63EBC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
