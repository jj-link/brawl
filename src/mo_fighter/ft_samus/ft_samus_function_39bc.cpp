#include <types.h>
#pragma force_active on

extern "C" void* fn_94_3A38(void* object, s16 deleting);
extern "C" void* fn_94_3AF8(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_39BC(void* object, s16 deleting) {
    if (object != 0) {
        fn_94_3A38(static_cast<char*>(object) + 0x10000 - 0x3e84, -1);
        if (object != 0) {
            fn_94_3AF8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
