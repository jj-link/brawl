#include <types.h>
#pragma force_active on

extern "C" void fn_114_18218(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_181BC(void* object, short deleting) {
    if (object != 0) {
        fn_114_18218(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
