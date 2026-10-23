#pragma force_active on

char *fn_803D645C(char *dst, char *src)
{
    char c;
    char *d;

    d = dst;
    goto check;

loop:
    src++;
    d++;

check:
    c = *src;
    *d = c;
    if ((signed char)c != 0) {
        goto loop;
    }
    return dst;
}
