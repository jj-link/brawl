#pragma force_active on
int fn_803BE914(char *dst, const unsigned char *src, int flags) {
    int i;
    int last = -1;
    int end;
    char *p;
    for (i = 0; i < 8; i++) {
        dst[i] = src[i];
        if (dst[i] != ' ') last = i;
    }
    p = dst + ++last;
    if (last == 0) return 10;
    end = 7;
    for (i = 8; i < 11; i++) {
        if (src[i] != ' ') end = i;
    }
    if (end > 7) {
        if (!(flags & 8)) *p++ = '.';
        for (i = 8; i <= end; i++) *p++ = src[i];
    }
    *p = 0;
    return 0;
}