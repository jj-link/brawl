#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1CFC(void* member, short deleteFlag);
extern "C" void* fn_114_70C0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_7048(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_114_70C0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
