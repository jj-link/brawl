#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_1991BC(u32 *self) {
    u32 val = *(u32 *)((u8 *)self + 0x8);
    return (val >> 22) & 1;
}
