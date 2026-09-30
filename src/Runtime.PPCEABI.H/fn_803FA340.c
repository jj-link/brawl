// Runtime.PPCEABI.H/fn_803FA340.c
char* strncpy(char* dst, const char* src, unsigned long n) {
    const unsigned char* srcp = (const unsigned char*)src - 1;
    unsigned char* dstp = (unsigned char*)dst - 1;
    int count = n + 1;

    while (--count != 0) {
        int c = *++srcp;
        *++dstp = c;
        if (c == 0) {
            while (--count != 0) {
                *++dstp = 0;
            }
            break;
        }
    }
    return dst;
}
