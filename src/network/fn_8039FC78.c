#pragma force_active on
extern int lbl_805A1170;
extern int lbl_8059FDD0;
extern int lbl_805A1190;

extern void fn_80397694(int, int, int);
extern void fn_80397748(int, int, int);
extern int fn_80398BD8(int, int, int);
extern int fn_8039DAF0(int, int, int*, int, int, int*);

int fn_8039FC78(int arg0, int arg1, int* arg2) {
    int buf = lbl_805A1170;
    int var_r30 = arg0;
    int var_r29 = arg1;
    int* var_r27 = arg2;
    int var_r28 = 0;
    int result = 0;
    int length;
    int buf2;

    while (var_r29 > 0) {
        if (var_r28 > 0) {
            fn_80397694(buf, (int)&lbl_8059FDD0, 3);
            result = fn_80398BD8(buf, 3, lbl_805A1190);
            if (result != 0)
                break;
            var_r28 += 3;
        }
        fn_80397748(buf, 0, 0x400);
        result = fn_8039DAF0(buf, 0x400, &buf2, var_r30, var_r29, &length);
        if (result != 0 && result != -8)
            break;
        result = fn_80398BD8(buf, buf2, lbl_805A1190);
        if (result != 0)
            break;
        var_r30 += length;
        var_r29 -= length;
        var_r28 += buf2;
    }
    *var_r27 = var_r28;
    return result;
}