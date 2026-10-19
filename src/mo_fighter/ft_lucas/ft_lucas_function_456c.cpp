#include <types.h>
#pragma force_active on

extern "C" void* __dt__16soStopModuleImplFv(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_456C(void* object, short deleting) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
