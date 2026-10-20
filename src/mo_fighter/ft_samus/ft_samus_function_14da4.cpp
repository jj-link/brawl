#include <types.h>
#pragma force_active on

extern "C" void* fn_94_14E20(void* object, s16 deleting);
extern "C" void* fn_94_15668(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_14DA4(void* object, s16 deleting) {
    if (object != 0) {
        fn_94_14E20(static_cast<char*>(object) + 0xCC44, -1);
        if (object != 0) {
            fn_94_15668(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
