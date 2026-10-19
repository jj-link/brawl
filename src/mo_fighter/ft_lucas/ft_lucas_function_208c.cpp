#include <types.h>
#pragma force_active on

extern "C" void fn_27_7700(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_208C(void* object, short deleting) {
    if (object != 0) {
        fn_27_7700(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
