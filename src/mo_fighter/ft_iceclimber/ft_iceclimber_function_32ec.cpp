#include <cstddef>
#pragma force_active on

extern "C" void* fn_105_3348(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_32EC(void* object, short arg) {
    if (object != 0) {
        fn_105_3348(object, 0);
        if (arg > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
