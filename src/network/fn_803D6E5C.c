#pragma force_active on
extern int fn_803D8A50(int);
extern int fn_803D899C(int);
extern int fn_803D89A4(int, int *);
extern int fn_803D8D2C(int, int);
extern int fn_803DA454(void *, int, char **, int *);
extern int fn_803D8B64(int, int, unsigned int, unsigned int, unsigned int, int *);
extern void fn_803DA55C(void *, void *);
extern int fn_803D7418(void *, int);
extern int fn_803D7734(void *, int, int *, int *);
extern char lbl_805644C0[];

int fn_803D6E5C(char *self) {
    int info[5];
    int unused;
    char *buf;
    int count;
    int r;
    int result;

    r = fn_803D8A50(*(int *)(self + 0x1FBC));
    if (r != 0) {
        if (r == 21) {
            int t = fn_803D899C(*(int *)(self + 0x1FBC));
            *(int *)(lbl_805644C0 + 0x44) = t;
            *(int *)(self + 0x1F84) = t;
            return 0x1000;
        }
        return -1;
    }
    if (fn_803D89A4(*(int *)(self + 0x1FBC), info) != 0) {
        fn_803D8D2C(*(int *)(self + 0x1FBC), 0);
        return -1;
    }
    if (info[3] & 1) {
        *(unsigned short *)(self + 0x1F8C) |= 2;
    } else {
        *(unsigned short *)(self + 0x1F8C) &= ~2;
    }
    if (info[3] & 2) {
        int t = info[4];
        *(unsigned short *)(self + 0x1F8C) |= 0x40;
        *(int *)(self + 0x1FC4) = t;
    }
    if (info[3] & 8) {
        *(unsigned short *)(self + 0x1F8C) |= 0x80;
    }
    fn_803DA454(self, -1, &buf, &unused);
    r = fn_803D8B64(*(int *)(self + 0x1FBC), *(int *)(buf + 4), 0, 1, 0x200, &count);
    if (r != 0) {
        if (r == 21) {
            int t = fn_803D899C(*(int *)(self + 0x1FBC));
            result = 0x1000;
            *(int *)(lbl_805644C0 + 0x44) = t;
            *(int *)(self + 0x1F84) = t;
        } else {
            result = -1;
        }
        fn_803DA55C(self, buf);
        fn_803D8D2C(*(int *)(self + 0x1FBC), 0);
        return result;
    }
    if (fn_803D7418(self, *(int *)(buf + 4)) != 0) {
        fn_803DA55C(self, buf);
        fn_803D8D2C(*(int *)(self + 0x1FBC), 0);
        return 7;
    }
    *(int *)(self + 0x38) = -1;
    *(int *)(self + 0x3C) = -1;
    if (*(int *)(self + 0x1C) == 2) {
        r = fn_803D8B64(*(int *)(self + 0x1FBC), *(int *)(buf + 4), *(unsigned short *)(self + 0x14), 1, 0x200, &count);
        if (r != 0) {
            if (r == 21) {
                int t = fn_803D899C(*(int *)(self + 0x1FBC));
                result = 0x1000;
                *(int *)(lbl_805644C0 + 0x44) = t;
                *(int *)(self + 0x1F84) = t;
            } else {
                result = -1;
            }
            fn_803DA55C(self, buf);
            fn_803D8D2C(*(int *)(self + 0x1FBC), 0);
            return result;
        }
        if (fn_803D7734(self, *(int *)(buf + 4), (int *)(self + 0x38), (int *)(self + 0x3C)) != 0) {
            fn_803DA55C(self, buf);
            fn_803D8D2C(*(int *)(self + 0x1FBC), 0);
            return -1;
        }
    }
    fn_803DA55C(self, buf);
    return 0;
}
