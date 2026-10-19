#include <types.h>
#pragma force_active on

extern "C" void fn_27_689B0(void* self, s16 arg);
extern "C" void fn_27_1985B4(void* self, s16 arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_111_5180(void* self, s16 flags) {
    if (self != 0) {
        fn_27_689B0(static_cast<u8*>(self) + 0x7C, -1);
        if (self != 0) {
            fn_27_1985B4(self, -1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
