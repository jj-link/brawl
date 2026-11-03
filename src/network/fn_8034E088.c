#include <types.h>
#pragma force_active on

u8 fn_8034E088(s8 arg0, s8 arg1)
{
    u8 hi = 0;
    u8 lo = 0;

    if ((arg0 >= 0x30) && (arg0 <= 0x39)) {
        hi = arg0 - 0x30;
    } else if ((arg0 >= 0x61) && (arg0 <= 0x66)) {
        hi = arg0 - 0x57;
    } else if ((arg0 >= 0x41) && (arg0 <= 0x46)) {
        hi = arg0 - 0x37;
    }
    if ((arg1 >= 0x30) && (arg1 <= 0x39)) {
        lo = arg1 - 0x30;
    } else if ((arg1 >= 0x61) && (arg1 <= 0x66)) {
        lo = arg1 - 0x57;
    } else if ((arg1 >= 0x41) && (arg1 <= 0x46)) {
        lo = arg1 - 0x37;
    }
    return (u8)((hi << 4) | lo);
}
