#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3FE4(void* object, short deleting);
extern "C" void* fn_114_4068(void* object, short deleting);
extern "C" void* fn_114_5A38(void* object, short deleting);
extern "C" void* fn_114_40C8(void* object, short deleting);
extern "C" void* fn_114_1BCD0(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_1BC34(void* object, short deleting) {
    if (object != NULL) {
        short destroying = -1;
        fn_114_3FE4((char*)object + 0x118, destroying);
        fn_114_4068((char*)object + 0x104, destroying);
        fn_114_5A38((char*)object + 0xf4, destroying);
        fn_114_40C8((char*)object + 0x50, destroying);
        fn_114_1BCD0((char*)object + 0x10, destroying);
        fn_27_C74E8(object, destroying);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
