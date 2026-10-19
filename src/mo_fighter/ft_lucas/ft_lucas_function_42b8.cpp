#include <types.h>
#pragma force_active on

extern "C" void fn_114_208C(void*, short);
extern "C" void fn_114_20E8(void*, short);

extern "C" void* fn_114_42B8(void* object, short deleting) {
    if (object != 0) {
        fn_114_208C((char*)object + 0x14, 0);
        fn_114_20E8((char*)object + 0x08, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
