#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_14CC4C(u32 p1, u32 p2, u32 p3) {
    u32 a = p1 - 0x30000;
    a += p2 * 0x5c;
    a += p3 * 4;
    return *(u32*)(a + 0x649c);
}
