#include <types.h>
#pragma force_active on

extern "C" void fn_116_339C(void* object, s16 arg);
extern "C" void fn_116_450C(void* object, s16 arg);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_116_3320(void* object, s16 deleting) {
    if (object != 0) {
        fn_116_339C(static_cast<char*>(object) + 0x8D84, -1);
        if (object != 0) {
            fn_116_450C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
