#include <types.h>
#pragma force_active on

extern "C" void* fn_114_41B0(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_4150(void* object, short deleting) {
    if (object != 0) {
        fn_114_41B0(static_cast<char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
