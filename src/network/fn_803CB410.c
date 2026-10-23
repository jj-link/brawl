#pragma force_active on
extern void OSReport(const char *fmt, ...);
extern int fn_8021379C(int a, int b);
extern int fn_80212FAC(int a, int b, int c, int d, int *e, void *f, int *g);
extern int fn_80213090(int a, int b, int c, int d, int *e);
extern void fn_802137A8(int a, int *b);
extern void fn_803CB004(void);
extern char lbl_804927E0[];
extern int lbl_8059FE98;
extern int *lbl_805A123C;
extern int *lbl_805A1248;

int fn_803CB410(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                int flag, int *out, int a10, int a11)
{
    char *base;
    int r30;
    int r29;
    int *p;
    int *q;

    base = lbl_804927E0;
    if (flag != 0) {
        r30 = 2;
        r29 = 1;
    } else {
        r30 = 1;
        r29 = 2;
    }

    p = (int *)fn_8021379C(lbl_8059FE98, 0x40);
    if (p == 0) {
        OSReport(base + 0x15C, 0x40);
        a0 = -0x16;
    } else {
        p[0] = a1;
        p[1] = a2;
        p[2] = a3;
        p[3] = a4;
        p[6] = a5;
        p[4] = a6;
        p[5] = a7;
        p[7] = 1;
        lbl_805A1248[0] = (int)p;
        lbl_805A1248[1] = 0x24;
        lbl_805A1248[2] = a5;
        lbl_805A1248[3] = a6 * a7;
        lbl_805A1248[4] = (int)lbl_805A123C;
        lbl_805A1248[5] = 0x10;

        if (a10 != 0) {
            q = (int *)fn_8021379C(lbl_8059FE98, 0x1C);
            if (q == 0) {
                OSReport(base + 0x188);
                a0 = -0x16;
            } else {
                q[0] = a10;
                q[1] = a11;
                q[5] = (int)out;
                q[3] = a1;
                q[6] = (int)p;
                a0 = fn_80212FAC(a0, 7, r30, r29, lbl_805A1248, (void *)fn_803CB004, q);
                if (a0 != 0) {
                    OSReport(base + 0x19C, a0);
                }
            }
        } else {
            a0 = fn_80213090(a0, 7, r30, r29, lbl_805A1248);
            if (a0 != 0) {
                OSReport(base + 0x19C, a0);
            } else if (out != 0) {
                *out = *lbl_805A123C;
            }
        }
    }

    if ((a10 == 0 || a0 != 0) && p != 0) {
        fn_802137A8(lbl_8059FE98, p);
    }
    return a0;
}
