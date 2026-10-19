#include <types.h>
#pragma force_active on

extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
void operator delete(void*);

extern "C" void* fn_114_4A40(void* object, short deleting) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
