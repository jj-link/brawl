#include <types.h>
#pragma force_active on

extern "C" void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);

extern "C" void fn_14_1C80(void* s, int val) {
    u8 alpha = 0xc6;
    if (val != 0) {
        alpha = 0xff;
    }
    for (int i = 0; i < 3; i++) {
        setFontColor__5MuMsgFUlUcUcUcUc(
            *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(s) + 0x24cc),
            i + 0x18,
            alpha,
            alpha,
            alpha,
            0xff);
    }
}
