#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

u8 *fn_80397610(u8 *dst, u8 *src)
{
    u8 *out = dst;

    while ((s8)*src != 0) {
        *out++ = *src++;
    }
    *out = 0;

    return dst;
}
