#pragma force_active on
extern int fn_803A9BB4(int* p1, int p2, int p3);
extern void fn_803B1D30(int* p1, int p2);
extern void fn_803C290C(void);
extern char lbl_8053B248[];

void fn_803C2CC4(int arg0, int arg1) {
    int local[4];
    int result = fn_803A9BB4(local, arg0, 1);
    if (result == 0) {
        fn_803B1D30(local, arg1);
    } else {
        *(int*)(lbl_8053B248 + 0x1c) = result;
    }
    fn_803C290C();
}
