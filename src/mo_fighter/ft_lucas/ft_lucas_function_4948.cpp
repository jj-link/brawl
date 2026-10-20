#include <types.h>
#pragma force_active on

extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_114_49C0(void* object, s16 flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_4948(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_114_49C0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
