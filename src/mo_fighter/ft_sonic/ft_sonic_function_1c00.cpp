#include <stddef.h>
#pragma force_active on

extern "C" void* fn_123_1A8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_1C00(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = 0;
        fn_123_1A8C(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
