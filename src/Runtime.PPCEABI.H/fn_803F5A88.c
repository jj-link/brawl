typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x10];
    u8* xlat;
} CTypeTab;

extern char lbl_804942B8[];

int fn_803F5A88(char* a, char* b, int n)
{
    int i;
    s8 d;
    s8 c1, c2;
    u32 loc = *(u32*)(lbl_804942B8 + 0x38);

    for (i = 0; i < n; i++) {
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
    return 0;
}
