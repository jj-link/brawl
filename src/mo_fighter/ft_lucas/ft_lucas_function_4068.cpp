#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A2B08(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_4068(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2B08(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
