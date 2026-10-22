#pragma force_active on
extern int fn_803AD47C(int, int, int, int, unsigned short, int);
extern int fn_803ADD34(int);
extern char lbl_8053B248[];

int fn_803AA980(char *self, int a2, int a3, int a4, int a5) {
    int r;

    if (self == 0) {
        return 0xA;
    }
    r = fn_803AD47C(*(int *)(self + 0x188C), a2, a3, a4, *(unsigned short *)self, a5);
    if (r == 0) {
        goto zero;
    }
    if (r == 0x15) {
        int t = fn_803ADD34(*(int *)(self + 0x188C));
        *(int *)(lbl_8053B248 + 0x20) = t;
        *(int *)(self + 0x1870) = t;
        return 0x1000;
    }
    return -1;
zero:
    return 0;
}
