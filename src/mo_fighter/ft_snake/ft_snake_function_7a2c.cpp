#include <types.h>
#pragma force_active on

extern "C" void* fn_122_7AA8(void* object, s16 deleting);
extern "C" void* fn_122_7DF8(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_122_7A2C(void* object, s16 deleting) {
    if (object != 0) {
        fn_122_7AA8(static_cast<char*>(object) + 0x8C78, -1);
        if (object != 0) {
            fn_122_7DF8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
