#include <types.h>
#pragma force_active on

extern "C" void fn_27_689B0(void* p, s16 v);
extern "C" void fn_27_1985B4(void* p, s16 v);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_106_44E0(void* self, s16 flag) {
    if (self != nullptr) {
        fn_27_689B0(static_cast<u8*>(self) + 0x7C, -1);
        if (self != nullptr) {
            fn_27_1985B4(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
