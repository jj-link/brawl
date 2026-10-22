#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_803C2734(u32 value, s32 type)
{
    u8 c = value;

    switch (type) {
    case 1:
        return (c >= 0x81U && c <= 0x9FU) ||
               (c >= 0xE0U && c <= 0xFCU);
    case 2:
        return (c >= 0x40U && c <= 0x7EU) ||
               (c >= 0x80U && c <= 0xFCU);
    default:
        return 0;
    }
}
