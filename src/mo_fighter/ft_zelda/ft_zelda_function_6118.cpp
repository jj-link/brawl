#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_104_6190(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_104_6118(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, -1);
        if (object != 0) {
            fn_104_6190(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
