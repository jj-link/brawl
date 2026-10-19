#include <types.h>
#pragma force_active on

extern "C" void* fn_114_20E8(void* object, short deleting);
extern "C" void* fn_114_3F84(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_6E0C(void* object, short flag) {
    if (object) {
        fn_114_20E8((char*)object + 0x20, 0);
        fn_114_3F84(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
