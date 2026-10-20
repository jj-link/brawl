#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_238DD8(u8* self, u32 val) {
    *(u32*)(self + 0x1b4) = val;
    *(u32*)(self + 0x1b8) = val;
    *(u32*)(self + 0x1bc) = val;
    *(u32*)(self + 0x1c0) = val;
}
}
