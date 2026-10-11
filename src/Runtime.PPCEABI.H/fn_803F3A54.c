// MSL decimal-record increment/round helper (0x803F3A54..0x803F3B40, 0xEC bytes).
// Reconstructed in C; matches the target object 236/236 code bytes, 1/1 functions.
// Rec layout: +0x00 u8 flag (cleared on entry); +0x02 s16 exp (written = n, ++ on
// carry-out); +0x04 u8 count (digit chars consumed, cap 36); +0x05..0x28 u8 dig[36]
// (rec->dig[i] == byte at rec+5+i).

struct dec {
    unsigned char flag;      // +0x00
    unsigned char pad0;      // +0x01
    short exp;               // +0x02
    unsigned char count;     // +0x04
    unsigned char dig[36];   // +0x05..0x28
};

void fn_803F3A54(struct dec* rec, const char* s, int n) {
    int i;
    signed char c;
    const char* t;
    unsigned char* d;
    unsigned char* dig;

    rec->flag = 0;
    rec->exp = n;
    i = 0;
    while (i < 0x24 && *s != 0) {
        rec->dig[i++] = *s++ - '0';
    }
    rec->count = i;
    c = *s;
    if (c == 0) {
        return;
    }
    if (c < 5) {
        return;
    }
    if (c > 5) {
        goto incr;
    }
    {
        t = s + 1;
        while (*t != 0) {
            if (*t != '0') {
                goto incr;
            }
            t++;
        }
        if ((rec->dig[i - 1] & 1) == 0) {
            return;
        }
    }
incr:
    dig = rec->dig;
    d = dig + rec->count - 1;
    for (;;) {
        if (*d < 9) {
            *d = *d + 1;
            return;
        }
        if (d == dig) {
            *d = 1;
            rec->exp += 1;
            return;
        }
        *d = 0;
        d--;
    }
}
