#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_114_3ED8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_6D9C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<char*>(object) + 0x10, -1);
        fn_114_3ED8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
