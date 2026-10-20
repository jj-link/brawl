#include <types.h>
#pragma force_active on

extern "C" void* fn_94_156DC(void* object, s16 deleting);
extern "C" void* fn_94_15C00(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_15668(void* object, s16 deleting) {
    if (object != 0) {
        fn_94_156DC(static_cast<char*>(object) + 0xAEE8, -1);
        fn_94_15C00(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
