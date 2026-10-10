/* Locale-sensitive string comparison (fn_803FCAA8) and the itoa entry
 * that tail-branches into fn_803F5B48. */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x10];
    u8* xlat;
} CTypeTab;

extern char lbl_804942B8[];
extern char* fn_803F5B48(int value, char* buffer, unsigned long radix);

int fn_803FCAA8(const char* a, const char* b)
{
    s8 d;
    s8 c1, c2;
    u32 loc = *(u32*)(lbl_804942B8 + 0x38);

    for (;;) {
        d = (s8)*a++;
        d = (d < 0 || d >= 0x100) ? d : ((CTypeTab*)loc)->xlat[d];
        c1 = d;
        d = (s8)*b++;
        d = (d < 0 || d >= 0x100) ? d : ((CTypeTab*)loc)->xlat[d];
        c2 = d;

        if (c1 < c2) {
            return -1;
        }
        if (c1 > c2) {
            return 1;
        }
        if (c1 == 0) {
            return 0;
        }
    }
}

char* itoa(int value, char* buffer, int base)
{
    return fn_803F5B48(value, buffer, (unsigned long)base);
}
