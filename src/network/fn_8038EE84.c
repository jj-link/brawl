#include <types.h>
#pragma force_active on

extern u32 lbl_80415DA0[];

u32 NETCalcCRC32(u8 *p, u32 size)
{
    u32 crc = ~0U;
    while (size--) {
        u8 byte = *p++;
        crc = (crc >> 4) ^ lbl_80415DA0[(crc ^ byte) & 15];
        crc = (crc >> 4) ^ lbl_80415DA0[(crc ^ ((u32)byte >> 4)) & 15];
    }
    return ~crc;
}