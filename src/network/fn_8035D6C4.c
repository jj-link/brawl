#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef struct { u8 pad[0x10]; u8 *xlat; } CTypeTab;
extern char lbl_804942B8[];

s8 *fn_8035D6C4(s8 *str)
{
    int c;
    s8 *ret = str;
    while (*str) {
        c = *str;
        *str = (c < 0 || c >= 0x100) ? c : (*(CTypeTab **)(lbl_804942B8 + 0x38))->xlat[c];
        str++;
    }
    return ret;
}