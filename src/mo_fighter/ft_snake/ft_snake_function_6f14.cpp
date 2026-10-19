#include <types.h>
#pragma force_active on

extern "C" void* fn_122_6F90(void* object, s16 deleting);
extern "C" void* fn_122_76DC(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_122_6F14(void* object, s16 deleting) {
    if (object != 0) {
        fn_122_6F90(static_cast<char*>(object) + 0xCB10, -1);
        if (object != 0) {
            fn_122_76DC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
