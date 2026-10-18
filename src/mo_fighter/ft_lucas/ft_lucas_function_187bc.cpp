#include <types.h>
#pragma force_active on

extern "C" void* fn_114_57E0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_187BC(void* object, short deleting) {
    if (object != 0) {
        fn_114_57E0(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
