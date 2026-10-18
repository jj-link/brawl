#include <types.h>
#pragma force_active on

extern "C" void fn_114_4D10(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_4CB0(void* object, short deleting) {
    if (object != 0) {
        fn_114_4D10(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
