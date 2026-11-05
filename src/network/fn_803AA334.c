#pragma force_active on
extern int fn_803AFD48(void *, int, char **);
extern int fn_803AD47C(int, int, int, int, unsigned short, unsigned int *);
extern int fn_803AD644(int, int, int, int, unsigned short, unsigned int *);
extern int fn_803ADD34(int);
extern void fn_803AFE4C(void *, void *);
extern char lbl_8053B248[];

int fn_803AA334(char *self) {
    char *buf;
    unsigned int sp8;
    int a8;
    unsigned short n14;
    int r;
    int r30;
    int t;

    r = fn_803AFD48(self, -1, &buf);
    if (r != 0) {
        return r;
    }
    a8 = *(int *)(buf + 8);
    n14 = *(unsigned short *)(self + 0x14);
    if (self == 0) {
        r30 = 10;
    } else {
        r = fn_803AD47C(*(int *)(self + 0x188C), a8, n14, 1, *(unsigned short *)self, &sp8);
        if (r != 0) {
            if (r == 0x15) {
                t = fn_803ADD34(*(int *)(self + 0x188C));
                r30 = 0x1000;
                *(int *)(lbl_8053B248 + 0x20) = t;
                *(int *)(self + 0x1870) = t;
            } else {
                r30 = -1;
            }
        } else {
            r30 = 0;
        }
    }
    if (r30 != 0 || sp8 != 1) {
        r30 = 0x11;
    }
    if (r30 == 0) {
        *(char *)(*(char **)(buf + 8) + 0x1E8) = (char)*(int *)(self + 0x38);
        *(char *)(*(char **)(buf + 8) + 0x1E9) = (char)(((unsigned int)*(int *)(self + 0x38) >> 8) & 0xFF);
        *(char *)(*(char **)(buf + 8) + 0x1EA) = (char)(((unsigned int)*(int *)(self + 0x38) >> 16) & 0xFF);
        *(char *)(*(char **)(buf + 8) + 0x1EB) = (char)((unsigned int)*(int *)(self + 0x38) >> 24);
        a8 = *(int *)(buf + 8);
        n14 = *(unsigned short *)(self + 0x14);
        if (self == 0) {
            r30 = 10;
        } else {
            r = fn_803AD644(*(int *)(self + 0x188C), a8, n14, 1, *(unsigned short *)self, &sp8);
            if (r != 0) {
                if (r == 0x15) {
                    t = fn_803ADD34(*(int *)(self + 0x188C));
                    r30 = 0x1000;
                    *(int *)(lbl_8053B248 + 0x20) = t;
                    *(int *)(self + 0x1870) = t;
                } else {
                    r30 = -1;
                }
            } else {
                r30 = 0;
            }
        }
        if (r30 != 0 || sp8 != 1) {
            r30 = 0x11;
        }
    }
    fn_803AFE4C(self, buf);
    return r30;
}
