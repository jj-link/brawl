#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_60E0(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_6070(void* object, short deleting) {
    if (object) {
        fn_114_5D0C(static_cast<char*>(object) + 0x18958, -1);
        fn_114_60E0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
