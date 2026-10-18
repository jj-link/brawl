#include <types.h>
#pragma force_active on

extern "C" void fn_114_208C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_3F84(void* object, short deleting) {
    if (object != 0) {
        fn_114_208C(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
