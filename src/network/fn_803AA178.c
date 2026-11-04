#pragma force_active on
extern int fn_803AFD48(void *, int, char **);
extern int fn_803AD47C(int, int, int, int, unsigned short, int *);
extern int fn_803ADD34(int);
extern void fn_803AFE4C(void *, void *);
extern int fn_803AD1A4(int, int);
extern int fn_803AB2FC(int, int *);
extern int fn_803AB090(int, unsigned int *);
extern char lbl_8053B248[];

int fn_803AA178(char *self) {
    unsigned int info[2];
    char *buf;
    int count;
    int valid;
    int r;
    int result;
    r = fn_803AFD48(self, -1, &buf);
    if (r != 0) return r;
    r = fn_803AD47C(*(int *)(self + 0x188c), *(int *)(buf + 4), *(unsigned short *)(self + 0x14), 1, *(unsigned short *)self, &count);
    if (r != 0) {
        if (r == 21) {
            int t = fn_803ADD34(*(int *)(self + 0x188c));
            result = 0x1000;
            *(int *)(lbl_8053B248 + 0x20) = t;
            *(int *)(self + 0x1870) = t;
        } else {
            result = -1;
        }
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188c), 1);
        return result;
    }
    if (fn_803AB2FC(*(int *)(buf + 4), &valid) != 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188c), 1);
        return -1;
    }
    if (valid == 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188c), 1);
        return 7;
    }
    if (fn_803AB090(*(int *)(buf + 4), info) != 0) {
        r = 7;
    } else {
        if (info[0] >= 2 && info[0] < *(unsigned int *)(self + 0x34) + 2)
            *(unsigned int *)(self + 0x38) = info[0];
        if (info[1] >= 2 && info[1] < *(unsigned int *)(self + 0x34) + 2)
            *(unsigned int *)(self + 0x3c) = info[1];
        r = 0;
    }
    if (r != 0) {
        fn_803AFE4C(self, buf);
        fn_803AD1A4(*(int *)(self + 0x188c), 1);
        return -1;
    }
    fn_803AFE4C(self, buf);
    return 0;
}