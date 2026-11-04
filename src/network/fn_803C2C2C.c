#pragma force_active on
extern int fn_803A9BB4(int*, int, int);
extern int fn_803B1B34(int*, int, int);
extern int fn_803C290C(int);
extern char lbl_8053B248[];

int fn_803C2C2C(int arg0, int arg1, int arg2) {
    int local[4];
    int result = fn_803A9BB4(local, arg0, 1);
    if (result == 0) {
        result = fn_803B1B34(local, arg1, arg2);
    } else {
        *(int*)(lbl_8053B248 + 0x1C) = result;
    }
    return fn_803C290C(result);
}
