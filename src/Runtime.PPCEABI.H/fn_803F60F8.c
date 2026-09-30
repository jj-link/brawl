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


// Compare bytes lexicographically, returning the sign of the first difference.
int fn_803F6150(const void* lhs, const void* rhs, unsigned long n) {
    unsigned long cnt;
    const unsigned char* p1;
    const unsigned char* p2;
    p2 = (const unsigned char*)rhs - 1;
    p1 = (const unsigned char*)lhs - 1;
    cnt = n + 1;
    while (--cnt != 0) {
        if (*++p1 != *++p2) {
            if (*p1 < *p2) {
                return -1;
            }
            return 1;
        }
    }
    return 0;
}