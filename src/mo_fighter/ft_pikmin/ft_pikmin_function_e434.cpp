#include <stddef.h>
#pragma force_active on

extern "C" void* fn_113_E3D4(void* object, short deleting);
extern "C" void* fn_113_E2B4(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_113_E434(void* object, short deleting) {
    if (object != 0) {
        fn_113_E3D4(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_113_E2B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
