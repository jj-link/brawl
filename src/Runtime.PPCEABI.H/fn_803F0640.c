#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

u32 strlen(const char* s) {
    u8 c;
    const char* p = s - 1;
    int n = -1;
    do {
        c = *++p;
        n++;
    } while (c != 0);
    return n;
}
