#include <types.h>
#pragma force_active on

extern "C" void fn_27_3AD97C(void*, s32);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_27_3ADD30(void* self, s32 flags) {
    if (self) {
        if (reinterpret_cast<u8*>(self) + 8 != 0) {
            fn_27_3AD97C(reinterpret_cast<u8*>(self) + 0xc, -1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
