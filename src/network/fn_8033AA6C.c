#pragma force_active on
typedef unsigned char u8;

extern void *lbl_805A0F88;

int fn_8033AA6C(void) {
    u8 *p = (u8 *)lbl_805A0F88;
    u8 var;

    if (p == 0) {
        return 0;
    }
    if (p == 0 || *(int *)(p + 0x514) == 0 || *(int *)(p + 0x514) == 9 || *(int *)(p + 0x514) == 0xA || *(int *)(p + 0x514) == 0xB || p[0x36F] == 0 || p[0x377] == 0) {
        var = 0xFF;
    } else {
        var = p[0x648];
    }
    if (var == 0xFF) {
        return 0;
    }
    return (p[0x377] - 2) == 0;
}
