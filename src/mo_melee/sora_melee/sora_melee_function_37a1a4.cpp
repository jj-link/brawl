#include <types.h>
#pragma force_active on

extern "C" void fn_27_37A2D0(void*, int);

extern "C" {
void* fn_27_37A1A4(u8* self, int flag) {
    if (self) {
        if ((u32)self + 4 != 0) {
            if ((u32)self + 0xc != 0) {
                fn_27_37A2D0(self + 0x10, -1);
            }
        }
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
