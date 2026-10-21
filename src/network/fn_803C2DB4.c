#pragma force_active on
extern char lbl_8053B248[];
extern int fn_803A9BB4(int*, int, int);
extern void fn_803B1E20(int*);
extern void fn_803C290C(void);

void fn_803C2DB4(int arg0) {
    int local[6];
    int result = fn_803A9BB4(local, arg0, 1);
    if (result == 0) {
        fn_803B1E20(local);
    } else {
        *(int*)(lbl_8053B248 + 0x1c) = result;
    }
    fn_803C290C();
}
