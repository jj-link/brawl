#pragma force_active on
extern void fn_8039272C(void *, const void *, int);
extern int fn_803925B8(int *s, int a1, char *a2, int a3, int a4);

int fn_80393270(int *s, char *buf, int a2, int *pos, const char *src, int n) {
    int chunk;
    int rem = n;
    int r;
    while (rem > 0) {
        if (*s != 0)
            return -1;
        chunk = rem;
        if (chunk > 0x100 - *pos)
            chunk = 0x100 - *pos;
        fn_8039272C(buf + *pos, src, chunk);
        src += chunk;
        rem -= chunk;
        *pos += chunk;
        if (*pos == 0x100) {
            r = fn_803925B8(s, a2, buf, 0x100, 0);
            if (r <= 0)
                return r;
            *pos -= r;
        }
    }
    return n;
}
