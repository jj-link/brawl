#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1FCC(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_1F70(void* object, short deleting) {
    if (object != 0) {
        fn_114_1FCC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
