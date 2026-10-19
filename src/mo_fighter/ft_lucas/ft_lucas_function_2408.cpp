#include <types.h>
#pragma force_active on

extern "C" void* fn_27_A0C74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_2408(void* object, short deleting) {
    if (object != 0) {
        fn_27_A0C74(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
