// Runtime.PPCEABI.H/fn_803FA518.c
int strncmp(const char* lhs, const char* rhs, unsigned long n) {
    const unsigned char* l = (const unsigned char*)lhs - 1;
    const unsigned char* r = (const unsigned char*)rhs - 1;
    unsigned int c1;
    unsigned int c2;
    unsigned long count = n + 1;

    while (--count != 0) {
        c1 = *++l;
        c2 = *++r;
        if (c1 != c2) {
            return c1 - c2;
        }
        if (c1 == 0) {
            break;
        }
    }
    return 0;
}
