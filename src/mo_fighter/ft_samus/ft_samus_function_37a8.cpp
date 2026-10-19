#include <types.h>
#pragma force_active on

extern "C" void* fn_94_3824(void* object, s16 deleting);
extern "C" void* fn_94_39BC(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_37A8(void* object, s16 deleting) {
    if (object != 0) {
        fn_94_3824(static_cast<char*>(object) + 0xDA7C, -1);
        if (object != 0) {
            fn_94_39BC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
