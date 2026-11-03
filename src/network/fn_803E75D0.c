#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

s32 fn_803E75D0(u8 *dst, const u8 *src, s32 flags)
{
    s32 i;
    for (i = 0; i < 8 && (s8)*src != 0 && (s8)*src != '.'; ++i) {
        *dst++ = *src++;
    }
    if (i == 0) {
        for (i = 0; i < 2 && (s8)*src != 0; ++i) {
            *dst++ = *src++;
        }
    }
    if (!(flags & 8)) {
        for (; i < 8; ++i) {
            *dst++ = ' ';
        }
    }
    if ((s8)*src != 0) {
        if (!(flags & 8))
            ++src;
        while ((s8)*src != 0) {
            *dst++ = *src++;
            ++i;
        }
    }
    for (; i < 11; ++i) {
        *dst++ = ' ';
    }
    return 0;
}
