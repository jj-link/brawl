// Forward and reverse bounded byte searches from the MSL memory family.
void* memchr(const void* s, int c, unsigned long n) {
    const unsigned char* p;
    c = (unsigned char)c;
    p = (const unsigned char*)s - 1;
    n++;
    while (--n != 0) {
        if (*++p == (unsigned char)c) {
            return (void*)p;
        }
    }
    return 0;
}

void* __memrchr(const void* s, int c, unsigned long n) {
    const unsigned char* p = (const unsigned char*)s + n;
    c = (unsigned char)c;
    n++;
    while (--n != 0) {
        if (*--p == (unsigned char)c) {
            return (void*)p;
        }
    }
    return 0;
}
