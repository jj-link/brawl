#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_114_78B8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_7840(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x88, -1);
        if (object != 0) {
            fn_114_78B8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
