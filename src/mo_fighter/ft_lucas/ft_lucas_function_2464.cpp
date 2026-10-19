#include <types.h>
#pragma force_active on

extern "C" void* fn_114_24D0(void* object, short deleting);
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void __dl__FPv(void* block);

extern "C" void* fn_114_2464(void* object, short deleting) {
    if (object != 0) {
        fn_114_24D0((char*)object + 0x50, -1);
        fn_114_232C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
