#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void*, s16);
extern "C" void* fn_104_1994(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_A530(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x18660, -1);
        fn_104_1994(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
