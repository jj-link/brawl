#include <stddef.h>
#pragma force_active on

extern "C" void* fn_94_4750(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_15310(void* object, short deleteFlag) {
    if (object != NULL) {
        fn_94_4750(object, 0);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
