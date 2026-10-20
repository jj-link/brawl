#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_114_7390(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_7318(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x2fc, -1);
        if (object != 0) {
            fn_114_7390(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
