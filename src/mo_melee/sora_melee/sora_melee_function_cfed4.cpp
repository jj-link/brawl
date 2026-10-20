#include <types.h>
#pragma force_active on

extern "C" int fn_27_CFED4(void* p) {
    u32 val = *(u32*)((u8*)p + 8);
    return (val >> 10) & 1;
}
