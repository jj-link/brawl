// Runtime.PPCEABI.H/fn_803FA384.c
char* strcat(char* dst, const char* src) {
    const unsigned char* srcp = (const unsigned char*)src - 1;
    unsigned char* dstp = (unsigned char*)dst - 1;

    while (*++dstp != 0) {
    }
    dstp--;
    while ((*++dstp = *++srcp) != 0) {
    }
    return dst;
}
