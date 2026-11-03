#pragma force_active on
extern int fn_803ACFC0(int);
extern int fn_803AD330(int, int);
extern int fn_803AD1A4(int, int);
extern int fn_803ADD34(int);
extern char lbl_8053B248[];

int fn_803AA858(char *self, int arg1) {
    int r;
    if (self == 0) return 10;
    if (!(*(unsigned short *)(self + 0x1878) & 2)) {
        r = fn_803ACFC0(*(int *)(self + 0x188c));
        if (r != 0) {
            if (r == 0x15) {
                int t = fn_803ADD34(*(int *)(self + 0x188c));
                *(int *)(lbl_8053B248 + 0x20) = t;
                *(int *)(self + 0x1870) = t;
                return 0x1000;
            }
            return -1;
        }
    }
    r = fn_803AD330(*(int *)(self + 0x188c), arg1);
    if (r != 0) {
        if (r == 0x15) {
            int t = fn_803ADD34(*(int *)(self + 0x188c));
            *(int *)(lbl_8053B248 + 0x20) = t;
            *(int *)(self + 0x1870) = t;
            return 0x1000;
        }
        return -1;
    }
    if (!(*(unsigned short *)(self + 0x1878) & 2)) {
        r = fn_803AD1A4(*(int *)(self + 0x188c), 1);
        if (r != 0) {
            if (r == 0x15) {
                int t = fn_803ADD34(*(int *)(self + 0x188c));
                *(int *)(lbl_8053B248 + 0x20) = t;
                *(int *)(self + 0x1870) = t;
                return 0x1000;
            }
            return -1;
        }
    }
    return 0;
}