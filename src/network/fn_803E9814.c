#pragma force_active on
extern void fn_803D634C(void *, int, int);
extern int fn_803EBA40(void *);
extern void fn_803EBB4C(void);
extern void fn_803EAEAC(void);
extern void fn_803EB068(void);
extern void fn_803EB2D0(void);
extern void fn_803EB304(void);
extern void fn_803EB380(void);
extern void fn_803EB3B4(void);
extern char lbl_805644C0[];

int fn_803E9814(int arg0, int arg1)
{
    int flag = arg0 & 0x10000;

    if (flag != 0) {
        *(int *)(lbl_805644C0 + 0x38) |= 0x10000;
    } else {
        *(int *)(lbl_805644C0 + 0x38) &= 0xFFFEFFFF;
    }

    *(int *)(lbl_805644C0 + 0x08) = (int)(lbl_805644C0 + 0xA0);
    *(int *)(lbl_805644C0 + 0x14) = (int)(lbl_805644C0 + 0xA0);
    *(int *)(lbl_805644C0 + 0x20) = (int)(lbl_805644C0 + 0xA0);
    *(int *)(lbl_805644C0 + 0x2C) = (int)(lbl_805644C0 + 0xA0);
    *(int *)(lbl_805644C0 + 0x00) |= 1;
    *(int *)(lbl_805644C0 + 0x30) = 0;
    *(int *)(lbl_805644C0 + 0x34) = 0;

    if (flag != 0) {
        *(int *)(lbl_805644C0 + 0x38) |= 0x10000;
    } else {
        *(int *)(lbl_805644C0 + 0x38) &= 0xFFFEFFFF;
    }

    *(int *)(lbl_805644C0 + 0x3C) = arg1;
    *(int *)(lbl_805644C0 + 0x40) = 0;
    *(int *)(lbl_805644C0 + 0x44) = 0;
    *(int *)(lbl_805644C0 + 0x60) = 1;
    *(int *)(lbl_805644C0 + 0x48) = (int)&fn_803EAEAC;
    *(int *)(lbl_805644C0 + 0x4C) = (int)&fn_803EB068;
    *(int *)(lbl_805644C0 + 0x50) = (int)&fn_803EB2D0;
    *(int *)(lbl_805644C0 + 0x54) = (int)&fn_803EB304;
    *(int *)(lbl_805644C0 + 0x58) = (int)&fn_803EB380;
    *(int *)(lbl_805644C0 + 0x5C) = (int)&fn_803EB3B4;

    {
        char *it = lbl_805644C0 + 0xA0;
        int i;
        for (i = 0; i < 0x1A; i++) {
            fn_803D634C(it, 0, 0x1FC8);
            it += 0x1FC8;
        }
    }

    fn_803EBA40(lbl_805644C0 + 0x64);
    fn_803EBB4C();
    return 0;
}
