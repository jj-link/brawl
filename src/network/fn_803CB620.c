#pragma force_active on
extern void OSReport(const char *, ...);
extern void *fn_8021379C(int, int);
extern void fn_802137A8(int, void *);
extern int fn_80212C08(int, int, void *, int, void *, int, void (*)(void), void *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803CB004(void);
extern char lbl_804927E0[];
extern int lbl_8059FE98;
extern int *lbl_805A123C;

int fn_803CB620(int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5,
                int arg6, int arg7, int arg8, int *arg9, int arg10, int arg11)
{
    char *base;
    int result;
    int *block1;
    int *block2;

    base = lbl_804927E0;
    block1 = (int *)fn_8021379C(lbl_8059FE98, 0x40);
    if (block1 == 0) {
        OSReport(base + 0x15C, 0x40);
        result = -0x16;
    } else {
        block1[0] = arg1;
        block1[1] = arg2;
        block1[2] = arg3;
        block1[3] = arg4;
        block1[6] = arg5;
        block1[4] = arg6;
        block1[5] = arg7;
        block1[7] = arg8;
        if (arg9 != 0) {
            if (arg10 != 0) {
                block2 = (int *)fn_8021379C(lbl_8059FE98, 0x1C);
                if (block2 == 0) {
                    OSReport(base + 0x188);
                    result = -0x16;
                } else {
                    block2[0] = arg10;
                    block2[1] = arg11;
                    block2[5] = (int)arg9;
                    block2[3] = arg1;
                    block2[4] = 1;
                    block2[6] = (int)block1;
                    result = fn_80212C08(arg0, 7, (void *)block1, 0x24, (void *)lbl_805A123C,
                                         0x10, fn_803CB004, (void *)block2);
                    if (result != 0) {
                        OSReport(base + 0x1C4, result);
                        result = 0xC1000000;
                    }
                }
            } else {
                result = fn_80212D40(arg0, 7, (void *)block1, 0x24, (void *)lbl_805A123C, 0x10);
                if (result != 0) {
                    if (arg1 == 7) {
                        result = 0;
                    } else {
                        OSReport(base + 0x1E8, result, result, (void *)block1);
                    }
                } else {
                    arg9[0] = lbl_805A123C[0];
                    arg9[1] = lbl_805A123C[1];
                    arg9[2] = lbl_805A123C[2];
                    arg9[3] = lbl_805A123C[3];
                }
            }
        } else {
            OSReport(base + 0x218);
            result = 0xC1000000;
        }
    }
    if (((arg9 == 0) || (arg10 == 0) || (result != 0)) && (block1 != 0)) {
        fn_802137A8(lbl_8059FE98, (void *)block1);
    }
    return result;
}
