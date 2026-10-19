#include <types.h>
#pragma force_active on

extern "C" void fn_114_5680(void* object, short deleting);
extern "C" void fn_114_17F80(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_17F0C(void* object, short deleting) {
    if (object != 0) {
        fn_114_5680(static_cast<char*>(object) + 0xD6D8, -1);
        fn_114_17F80(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
