#include <types.h>
#pragma force_active on

extern "C" void fn_27_8AA38(void*, s16);
extern "C" void fn_27_1DBB60(void*, s16);
extern "C" void fn_27_13F86C(void*, s16);
extern "C" void fn_27_1D81C8(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E2EDC(void* self, s32 deleting) {
    if (self) {
        fn_27_8AA38(static_cast<u8*>(self) + 0x958, -1);
        fn_27_1DBB60(static_cast<u8*>(self) + 0x920, -1);
        fn_27_13F86C(static_cast<u8*>(self) + 0xCC, -1);
        fn_27_1D81C8(self, 0);
        if (deleting > 0)
            __dl__FPv(self);
    }
    return self;
}
