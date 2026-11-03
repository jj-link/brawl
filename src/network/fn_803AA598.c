#pragma force_active on
extern int fn_803AA08C(int, void *);
extern int fn_803AA178(void *);
extern int fn_803AB1B4(int, int *);
extern int fn_803ACFC0(int);
extern int fn_803AD1A4(int, int);
extern int fn_803AD47C(int, int, int, int, unsigned short, int *);
extern int fn_803AD80C(int, int *);
extern int fn_803ADD34(int);
extern int fn_803AFD48(void *, int, char **);
extern void fn_803AFE4C(void *, void *);
extern char lbl_8053B248[];

int fn_803AA598(char *self) {
    int info[5];
    char *buf;
    int count;
    int valid;
    int r;
    int result;
    if (self == 0) {
        return 10;
    }
    r = fn_803ACFC0(*(int *)(self + 0x188C));
    if (r != 0) {
        if (r == 21) {
            int t = fn_803ADD34(*(int *)(self + 0x188C));
            *(int *)(lbl_8053B248 + 0x20) = t;
            *(int *)(self + 0x1870) = t;
            return 0x1000;
        }
        return -1;
    }
    if (fn_803AD80C(*(int *)(self + 0x188C), info) != 0) {
        fn_803AD1A4(*(int *)(self + 0x188C), 1);
        return -1;
    }
    if (info[3] & 2) {
        int t = info[4];
        *(unsigned short *)(self + 0x1878) |= 0x10;
        *(int *)(self + 0x1894) = t;
    }
    if (info[3] & 8) {
        *(unsigned short *)(self + 0x1878) |= 0x20;
    }
    fn_803AFD48(self, -1, &buf);
    r = fn_803AD47C(*(int *)(self + 0x188C), *(int *)(buf + 4), 0, 1, 0x200, &count);
    if (r != 0) {
        if (r == 21) {
            int t = fn_803ADD34(*(int *)(self + 0x188C));
            result = 0x1000;
            *(int *)(lbl_8053B248 + 0x20) = t;
            *(int *)(self + 0x1870) = t;
        } else {
            result = -1;
        }
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188C), 1);
        return result;
    }
    if (fn_803AB1B4(*(int *)(buf + 4), &valid) != 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188C), 1);
        return -1;
    }
    if (valid == 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188C), 1);
        return 7;
    }
    result = fn_803AA08C(*(int *)(buf + 4), self);
    if (result != 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188C), 1);
        return result;
    }
    fn_803AFE4C(self, buf);
    *(int *)(self + 0x38) = -1;
    *(int *)(self + 0x3C) = -1;
    if (*(int *)(self + 0x1C) == 2) {
        result = fn_803AA178(self);
    }
    return result;
}
