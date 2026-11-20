#pragma force_active on
#include <types.h>

extern int fn_80257BC8(u32 handle, u16 id, u8 type, u32 len, u8 *data);

void fn_80258038(u32 handle, u16 count, u16 *src)
{
    u8 buf[0xA8];
    u16 i;
    u8 *out = buf;

    for (i = 0; i < count; i++) {
        *out++ = 0x19;
        *out++ = (u8)(*src >> 8);
        *out++ = (u8)*src++;
    }
    fn_80257BC8(handle, 1, 6, out - buf, buf);
}
