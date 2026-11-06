#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

u8 *fn_8025B020(u8 *dst, u16 *src, u16 count)
{
    u8 *out;
    u16 size;
    u16 i;

    if (src != 0) {
        size = count * 3;
    } else {
        size = 5;
    }
    if (size > 0xFF) {
        dst[0] = 0x36;
        dst[1] = size >> 8;
        dst[2] = size;
        out = dst + 3;
    } else {
        dst[0] = 0x35;
        dst[1] = size;
        out = dst + 2;
    }
    if (src == 0) {
        out[0] = 0x0A;
        out[1] = 0;
        out[2] = 0;
        out[3] = 0xFF;
        out[4] = 0xFF;
        out += 5;
    } else {
        for (i = 0; i < count; i++) {
            out[0] = 9;
            out[1] = *src >> 8;
            out[2] = *src++;
            out += 3;
        }
    }
    return out;
}
