#include <types.h>
#pragma force_active on

extern "C" void* fn_27_5BFA0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_2D88(void* object, short deleting) {
    if (object != 0) {
        fn_27_5BFA0(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
