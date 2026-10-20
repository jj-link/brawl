#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_20FE4(u8* p);
}

extern "C" u32 fn_27_16AB8(u8* self) {
    u8* inner = (u8*)fn_27_20FE4(self + 0x34);
    return *(u32*)(inner + 4);
}
