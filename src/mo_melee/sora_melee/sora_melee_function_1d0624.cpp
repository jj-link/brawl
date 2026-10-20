#include <types.h>
#pragma force_active on

extern "C" void fn_27_1D0624(void* p) {
    u32* ptr = (u32*)((u8*)p + 8);
    *ptr |= 0x02000000;
}
