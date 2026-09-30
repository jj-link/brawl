// Runtime.PPCEABI.H/fn_803F602C.c
// MSL memmove dispatcher with inline short-copy paths.

typedef unsigned long u32;

extern int __cntlzw(unsigned int);
extern void fn_803F619C(void*, const void*, u32);
extern void fn_803F6258(void*, const void*, u32);
extern void fn_803F6300(void*, const void*, u32);
extern void fn_803F63C0(void*, const void*, u32);

void* fn_803F602C(void* dest, const void* src, u32 count)
{
    u32 diff = (u32)dest ^ (u32)src;
    u32 backward = ((u32)dest << __cntlzw(diff)) >> 31;
    char* d;
    const char* s;
    u32 n;

    if (count >= 0x20) {
        if ((diff & 3) != 0) {
            if (backward == 0) {
                fn_803F6300(dest, src, count);
            } else {
                fn_803F63C0(dest, src, count);
            }
        } else {
            if (backward == 0) {
                fn_803F619C(dest, src, count);
            } else {
                fn_803F6258(dest, src, count);
            }
        }
        return dest;
    }
    if (backward == 0) {
        s = (const char*)src - 1;
        d = (char*)dest - 1;
        n = count + 1;
        while (--n != 0) {
            *++d = *++s;
        }
    } else {
        s = (const char*)src + count;
        d = (char*)dest + count;
        n = count + 1;
        while (--n != 0) {
            *--d = *--s;
        }
    }
    return dest;
}
