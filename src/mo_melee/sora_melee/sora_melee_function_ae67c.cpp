#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_AE67C(u8* self) {
    u32 val = *(u32*)(self + 8);
    return (val >> 25) & 1;
}
