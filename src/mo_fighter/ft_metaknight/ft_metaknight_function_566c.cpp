#include <types.h>
#pragma force_active on

extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_111_56E4(void* object, s16 deleting);
extern "C" void* fn_111_5744(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_566C(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<u8*>(object) + 0x30, -1);
        fn_111_56E4(static_cast<u8*>(object) + 0x18, -1);
        fn_111_5744(static_cast<u8*>(object) + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
