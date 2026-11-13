#pragma force_active on
#include <types.h>
extern "C" u32 fn_8015C4C8(u8** p)
{
    s32 flag = 0;
    u32 c;
    u8* s = *p;
    c = *s;
    if ((c >= 0x81 && c < 0xA0) || c >= 0xE0)
        flag = 1;
    u32 result;
    if (flag) {
        result = (s[1] & ~0xFF00) | ((c << 8) & 0xFF00);
        *p += 2;
    } else {
        result = c;
        *p += 1;
    }
    return result;
}
