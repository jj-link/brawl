// Aligned copy engines used by the memmove dispatcher.
void fn_803F619C(void* dst, const void* src, unsigned long n) {
    char* d = (char*)dst;
    const char* s = (const char*)src;
    unsigned int head;
    unsigned int words;
    unsigned int chunks;

    s = (const char*)src - 1;
    head = -(long)d & 3;
    d = (char*)dst - 1;
    if (head != 0) {
        n -= head;
        do {
            *++d = *++s;
        } while (--head != 0);
    }

    words = n >> 5;
    {
        char* d8;
        const char* s8;
        s8 = s - 3;
        d8 = d - 3;
        if (words != 0) {
            do {
                *(unsigned int*)(d8 + 0x04) = *(const unsigned int*)(s8 + 0x04);
                *(unsigned int*)(d8 + 0x08) = *(const unsigned int*)(s8 + 0x08);
                *(unsigned int*)(d8 + 0x0C) = *(const unsigned int*)(s8 + 0x0C);
                *(unsigned int*)(d8 + 0x10) = *(const unsigned int*)(s8 + 0x10);
                *(unsigned int*)(d8 + 0x14) = *(const unsigned int*)(s8 + 0x14);
                *(unsigned int*)(d8 + 0x18) = *(const unsigned int*)(s8 + 0x18);
                *(unsigned int*)(d8 + 0x1C) = *(const unsigned int*)(s8 + 0x1C);
                *(unsigned int*)(d8 + 0x20) = *(const unsigned int*)(s8 + 0x20);
                s8 += 0x20;
                d8 += 0x20;
            } while (--words != 0);
        }
        s = s8;
        d = d8;
    }

    chunks = (n >> 2) & 7;
    if (chunks != 0) {
        do {
            *(unsigned int*)(d + 4) = *(const unsigned int*)(s + 4);
            s += 4;
            d += 4;
        } while (--chunks != 0);
    }

    {
        char* tp;
        const char* sp;
        sp = s + 3;
        tp = d + 3;
        n &= 3;
        if (n != 0) {
            do {
                *++tp = *++sp;
            } while (--n != 0);
        }
    }
}

void fn_803F6258(void* dst, const void* src, unsigned long n) {
    unsigned int head;
    unsigned int chunks;
    char* d = (char*)dst + n;
    const char* s = (const char*)src + n;
    const char* s8;
    char* d8;

    head = (unsigned int)d & 3;
    if (head != 0) {
        n -= head;
        do {
            *--d = *--s;
        } while (--head != 0);
    }

    chunks = n >> 5;
    {
        s8 = s;
        d8 = d;
        if (chunks != 0) {
            do {
                *(unsigned int*)(d8 - 0x04) = *(const unsigned int*)(s8 - 0x04);
                *(unsigned int*)(d8 - 0x08) = *(const unsigned int*)(s8 - 0x08);
                *(unsigned int*)(d8 - 0x0C) = *(const unsigned int*)(s8 - 0x0C);
                *(unsigned int*)(d8 - 0x10) = *(const unsigned int*)(s8 - 0x10);
                *(unsigned int*)(d8 - 0x14) = *(const unsigned int*)(s8 - 0x14);
                *(unsigned int*)(d8 - 0x18) = *(const unsigned int*)(s8 - 0x18);
                *(unsigned int*)(d8 - 0x1C) = *(const unsigned int*)(s8 - 0x1C);
                *(unsigned int*)(d8 - 0x20) = *(const unsigned int*)(s8 - 0x20);
                s8 -= 0x20;
                d8 -= 0x20;
            } while (--chunks != 0);
        }
        s = s8;
        d = d8;
    }

    chunks = (n >> 2) & 7;
    if (chunks != 0) {
        do {
            *(unsigned int*)(d - 4) = *(const unsigned int*)(s - 4);
            s -= 4;
            d -= 4;
        } while (--chunks != 0);
    }

    n &= 3;
    if (n != 0) {
        do {
            *--d = *--s;
        } while (--n != 0);
    }
}
