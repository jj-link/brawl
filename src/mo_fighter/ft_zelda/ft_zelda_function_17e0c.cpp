#include <types.h>
#pragma force_active on

extern "C" void* fn_104_17E88(void* object, s16 deleting);
extern "C" void* fn_104_1885C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_104_17E0C(void* object, s16 deleting) {
    if (object != 0) {
        fn_104_17E88(static_cast<char*>(object) + 0x96F4, -1);
        if (object != 0) {
            fn_104_1885C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
