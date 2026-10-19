#include <types.h>
#pragma force_active on

extern "C" void fn_27_2F00C(u8* p, u32 bit, u32 flag) {
    u16* field = (u16*)(p + 0x36);
    if (flag == 1) {
        *field = *field | (1 << bit);
    } else {
        *field = *field & ~(1 << bit);
    }
}
