#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_4B53C(void* self, s16 arg);
extern "C" void fn_27_19C45C(void* self, s16 arg);

extern "C" void* fn_114_7FE0(void* self, s16 flag) {
    if (self != 0) {
        s16 minusOne = -1;
        fn_27_4B53C(reinterpret_cast<u8*>(self) + 0x17c, minusOne);
        fn_27_19C45C(self, minusOne);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
