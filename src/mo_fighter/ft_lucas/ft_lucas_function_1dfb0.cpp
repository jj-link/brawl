#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A220C(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_1DFB0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A220C(static_cast<char*>(object) + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
