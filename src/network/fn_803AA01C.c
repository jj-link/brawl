#pragma force_active on
typedef unsigned short u16;

u16 *fn_803AA01C(u16 *dst, const u16 *src)
{
    u16 *d = dst;

    goto check;
loop:
    src++;
    d++;
check:
    if ((*d = *src) != 0) {
        goto loop;
    }

    return dst;
}
