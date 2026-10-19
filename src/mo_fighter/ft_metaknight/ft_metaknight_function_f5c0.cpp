#include <types.h>
#pragma force_active on

extern "C" void* fn_111_F630(void* object, s16 deleting);
extern "C" void* fn_111_F95C(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

#pragma dont_inline on
extern "C" void* fn_111_F5C0(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_F630(static_cast<u8*>(object) + 0x197C, -1);
        fn_111_F95C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
