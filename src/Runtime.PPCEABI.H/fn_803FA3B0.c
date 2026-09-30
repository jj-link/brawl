// Runtime.PPCEABI.H/fn_803FA3B0.c
char* strncat(char* dst, const char* src, unsigned long n) {
    const unsigned char* srcp = (const unsigned char*)src - 1;
    unsigned char* dstp = (unsigned char*)dst - 1;

    while (*++dstp != 0) {
    }
    dstp--;
    n += 1;
    while (--n != 0) {
        int c = *++srcp;
        *++dstp = c;
        if (c == 0) {
            dstp--;
            break;
        }
    }
    *++dstp = 0;
    return dst;
}
