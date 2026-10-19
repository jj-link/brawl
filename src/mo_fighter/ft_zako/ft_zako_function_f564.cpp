#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void fn_126_F004(void* object, s16 arg);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_126_F564(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x812C, -1);
        fn_126_F004(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
