#include <types.h>
#pragma force_active on

extern "C" void fn_104_3414(void* object, s16 deleting);
extern "C" void fn_104_4C4C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_104_3398(void* object, s16 deleting) {
    if (object != 0) {
        fn_104_3414(static_cast<char*>(object) + 0x9BD8, -1);
        if (object != 0) {
            fn_104_4C4C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
