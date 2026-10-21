#pragma force_active on
typedef unsigned short u16;

u16 *fn_803D6528(u16 *arg0, const u16 *arg1)
{
    u16 *dst = arg0;

    goto check;
loop:
    arg1++;
    dst++;
check:
    if ((*dst = *arg1) != 0) {
        goto loop;
    }

    return arg0;
}
