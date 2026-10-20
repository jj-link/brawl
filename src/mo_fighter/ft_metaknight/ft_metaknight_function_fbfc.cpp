#include <types.h>
#pragma force_active on

extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);
extern "C" void* fn_111_FC88(void*, s16);
extern "C" void* fn_27_CBF58(void*, short);
extern "C" void __dl__FPv(void*);

#pragma dont_inline on
extern "C" void* fn_111_FBFC(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_97968(static_cast<u8*>(object) + 0x58, -1);
        fn_27_1CCCC(static_cast<u8*>(object) + 0x48, -1);
        fn_111_FC88(static_cast<u8*>(object) + 0x3C, -1);
        if (object != 0) {
            fn_27_CBF58(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
