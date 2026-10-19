#include <types.h>
#pragma force_active on

extern "C" void* fn_114_2408(void*, short);
extern "C" void* fn_114_232C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_3AFC(void* object, short count) {
    if (object != 0) {
        fn_114_2408((char*)object + 0x50, -1);
        fn_114_232C(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
