#include <types.h>
#pragma force_active on

extern "C" void* __dt__20soResourceModuleImplFv(void* object, short deleting);
extern "C" void* fn_114_49C0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_88D0(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<char*>(object) + 0xC, -1);
        if (object != 0) {
            fn_114_49C0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
