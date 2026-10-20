#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3AFC(void*, short);
extern "C" void* fn_114_14948(void*, short);
extern "C" void* fn_114_149D4(void*, short);
extern "C" void* fn_114_14A60(void*, short);
extern "C" void* fn_114_14AEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_148B8(void* object, short deleting) {
    if (object != 0) {
        fn_114_3AFC((char*)object + 0x4B0, -1);
        fn_114_14948((char*)object + 0x384, -1);
        fn_114_149D4((char*)object + 0x258, -1);
        fn_114_14A60((char*)object + 0x12C, -1);
        fn_114_14AEC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
