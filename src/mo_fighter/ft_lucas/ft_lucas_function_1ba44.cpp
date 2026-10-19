#include <types.h>
#pragma force_active on

extern "C" void fn_114_5680(void*, short);
extern "C" void* fn_114_1BAB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1BA44(void* object, short deleting) {
    if (object != 0) {
        fn_114_5680(static_cast<char*>(object) + 0x1854, -1);
        fn_114_1BAB4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
