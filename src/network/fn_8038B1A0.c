#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

static inline s32 length(const u8 *p, s32 n) {
    s32 i = 0;
    while (i < n) {
        if ((s8)*p == 0)
            return i + 1;
        i++;
        p++;
    }
    return -1;
}

s32 fn_8038B1A0(const u8 *p, s32 n) {
    s32 size;
    while (n > 0 && (s8)*p != 0) {
        size = length(p, n);
        if (size < 0)
            return 0;
        p += size;
        n -= size;
        size = length(p, n);
        if (size < 0)
            return 0;
        p += size;
        n -= size;
    }
    if (n == 0)
        return 0;
    return (s8)*p == 0;
}