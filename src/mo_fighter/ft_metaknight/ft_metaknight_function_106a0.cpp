#include <types.h>
#pragma force_active on

extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_111_3F60(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_106A0(void* object, s16 deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<u8*>(object) + 0x18, -1);
        if (object != 0) {
            fn_111_3F60(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
