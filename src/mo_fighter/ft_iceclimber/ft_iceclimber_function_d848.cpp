#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_105_1950(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_105_D848(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x1FE38, -1);
        fn_105_1950(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
