#include <types.h>
#pragma force_active on

extern "C" void* fn_114_49C0(void* object, s16 flag);
void operator delete(void* object);

extern "C" void* fn_114_15064(void* object, short deleting) {
    if (object != 0) {
        fn_114_49C0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
