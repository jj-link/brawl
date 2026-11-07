#pragma force_active on

extern int fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern char lbl_80489678[];
extern void *lbl_805A0F70;

int fn_80337BBC(int arg0) {
    int var_r31;
    int var_r3;
    unsigned char *p;
    int type;

    if (arg0 == 0) {
        return 0;
    }

    var_r3 = fn_80335638(2, lbl_80489678, arg0);
    switch (arg0) {
    case 1:
        var_r31 = 9;
        var_r3 = -1;
        break;
    case 2:
        var_r31 = 9;
        var_r3 = -2;
        break;
    case 3:
        var_r31 = 6;
        var_r3 = -10;
        break;
    case 4:
        var_r31 = 6;
        var_r3 = -20;
        break;
    }

    if (lbl_805A0F70 != 0 && var_r31 != 0) {
        fn_8033524C(var_r31, var_r3 - 0x11558);
        p = (unsigned char *)lbl_805A0F70;
        type = *(int *)p;

        if (type != 0 && type != 2) {
            ((void (*)(int, int, int))(*(int *)(p + 0x30)))(
                var_r31, p[0x21], *(int *)(p + 0x34));
        }

        if (lbl_805A0F70 != 0) {
            *(int *)lbl_805A0F70 = 0;
            *((unsigned char *)lbl_805A0F70 + 0x22) = 0;
            *((unsigned char *)lbl_805A0F70 + 0x23) = 0;
        }
    }

    return arg0;
}
