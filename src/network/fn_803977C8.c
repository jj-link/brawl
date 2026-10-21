#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

u8 *fn_803977C8(u8 *arg0, u8 *arg1)
{
    s32 length;
    u8 *src;
    u8 *dst;
    u8 *scan;

    src = arg1;
    scan = arg0;
    length = 0;
    goto check1;

loop_2:
    scan += 1;
    length += 1;

check1:
    if ((s8)*scan != 0) {
        goto loop_2;
    }

    dst = (u8 *)((s32)arg0 + length);
    while ((s8)*src != 0) {
        *dst++ = *src++;
    }
    *dst = 0;
    return arg0;
}
