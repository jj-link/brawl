#include <types.h>
#pragma force_active on

extern "C" void* fn_111_FDBC(void*, s16);
extern "C" void* fn_111_FDFC(void*, s16);
extern "C" void* fn_111_FE5C(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_FD44(void* object, s16 deleting) {
    if (object != 0) {
        s16 memberDeleting = -1;
        u8* members = static_cast<u8*>(object);
        fn_111_FDBC(members + 0xB0, memberDeleting);
        fn_111_FDFC(members + 0x30, memberDeleting);
        fn_111_FE5C(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
