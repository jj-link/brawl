#include <types.h>
#pragma force_active on

extern "C" void* __dt__22soControllerModuleImplFv(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_4380(void* object, short deleting) {
    if (object != 0) {
        void* sub = static_cast<char*>(object) + 4;
        if (sub != 0) {
            __dt__22soControllerModuleImplFv(sub, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
