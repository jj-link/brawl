#include <types.h>
#pragma force_active on

extern "C" void* fn_97_47F8(void* object, s16 deleting);
extern "C" void* fn_97_5278(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_97_477C(void* object, s16 deleting) {
    if (object != 0) {
        fn_97_47F8(static_cast<char*>(object) + 0x8700, -1);
        if (object != 0) {
            fn_97_5278(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
