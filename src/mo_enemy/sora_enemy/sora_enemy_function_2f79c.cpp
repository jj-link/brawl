#include <types.h>
#pragma force_active on

extern "C" void fn_27_689B0(void* p, s16 v);
extern "C" void fn_27_C9A14(void* p, s16 v);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_2F79C(void* self, s16 flag) {
    if (self != nullptr) {
        fn_27_689B0(static_cast<u8*>(self) + 0x28, -1);
        if (self != nullptr) {
            fn_27_C9A14(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
