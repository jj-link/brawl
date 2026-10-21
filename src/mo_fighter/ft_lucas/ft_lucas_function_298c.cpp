#include <types.h>
#pragma force_active on

extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* object, short deleting);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_114_2A24(void* object, short deleting);
extern "C" void* fn_27_1A62E4(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_298C(void* object, short deleting) {
    if (object != 0) {
        char* bytes = (char*)object;
        fn_114_232C(bytes + 0x9F4, -1);
        fn_114_23C8(bytes + 0x9D8, -1);
        fn_114_2408(bytes + 0x92C, -1);
        fn_114_2A24(bytes + 0x494, -1);
        if (object != 0) {
            fn_27_1A62E4(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
