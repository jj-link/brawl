#include <types.h>
#pragma force_active on

extern "C" void* fn_96_8F14(void* object, s16 deleting);
extern "C" void* fn_96_8E38(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_96_8F74(void* object, s16 deleting) {
    if (object != 0) {
        fn_96_8F14(static_cast<char*>(object) + 0xCFA0, -1);
        if (object != 0) {
            fn_96_8E38(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
