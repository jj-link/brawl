#include <types.h>
#pragma force_active on

extern "C" {
void fn_80010F20();

void fn_27_A756C(int* p) {
    u8* inner = (u8*)p[1];
    u32 flag = (inner[0x1c] >> 4) & 1;
    if (flag != 1) {
        return;
    }
    fn_80010F20();
}
}
