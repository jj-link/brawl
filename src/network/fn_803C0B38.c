#pragma force_active on
extern char lbl_8053B248[];
extern void *fn_803A976C(void *, int, unsigned int);
extern void fn_803C2E7C(void);
extern unsigned int fn_803C22DC(unsigned int, int *);
extern unsigned int fn_803C2498(void *, unsigned int *);
extern short fn_803C2700(void);
extern int fn_803C2734(unsigned int, int);
extern short fn_803C27B0(void *);
extern int fn_803C27E4(void);

int fn_803C0B38(int arg0, int arg1)
{
    int flag;
    char *it;
    int i;
    if (arg0 & 0xFFFCFFFF) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    if ((arg0 & 0x30000) == 0x30000) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    flag = arg0 & 0x10000;
    if (flag) {
        *(int *)(lbl_8053B248 + 0x14) |= 0x10000;
    } else {
        *(int *)(lbl_8053B248 + 0x14) &= 0xFFFEFFFF;
    }
    *(int *)(lbl_8053B248 + 0x08) = (int)(lbl_8053B248 + 0x48);
    *(int *)(lbl_8053B248 + 0x00) |= 1;
    *(int *)(lbl_8053B248 + 0x0C) = 0;
    *(int *)(lbl_8053B248 + 0x10) = 0;
    if (flag) {
        *(int *)(lbl_8053B248 + 0x14) |= 0x10000;
    } else {
        *(int *)(lbl_8053B248 + 0x14) &= 0xFFFEFFFF;
    }
    *(int *)(lbl_8053B248 + 0x18) = arg1;
    *(int *)(lbl_8053B248 + 0x1C) = 0;
    *(int *)(lbl_8053B248 + 0x20) = 0;
    *(int *)(lbl_8053B248 + 0x3C) = 1;
    *(int *)(lbl_8053B248 + 0x24) = (int)&fn_803C22DC;
    *(int *)(lbl_8053B248 + 0x28) = (int)&fn_803C2498;
    *(int *)(lbl_8053B248 + 0x2C) = (int)&fn_803C2700;
    *(int *)(lbl_8053B248 + 0x30) = (int)&fn_803C2734;
    *(int *)(lbl_8053B248 + 0x34) = (int)&fn_803C27B0;
    *(int *)(lbl_8053B248 + 0x38) = (int)&fn_803C27E4;
    it = lbl_8053B248 + 0x48;
    for (i = 0; i < 0x1A; i++) {
        fn_803A976C(it, 0, 0x1898);
        it += 0x1898;
    }
    fn_803C2E7C();
    return 0;
}