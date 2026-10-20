#include <types.h>
#pragma force_active on

extern "C" void* fn_111_F564(void* object, s16 deleting);
extern "C" void* fn_27_1DBB60(void* object, s16 deleting);
extern "C" void* fn_111_F5C0(void* object, s16 deleting);
extern "C" void* fn_27_1D81C8(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_F4DC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_F564(static_cast<u8*>(object) + 0x2030, -1);
        fn_27_1DBB60(static_cast<u8*>(object) + 0x1ff8, -1);
        fn_111_F5C0(static_cast<u8*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
