#pragma force_active on
extern int fn_803A9BB4(int* p1, int p2, int p3);
extern void fn_803BC138(int* p1);
extern void fn_803C290C(void);
extern char lbl_8053B248[];

void fn_803C2E04(int arg0) {
    struct { int a; int b; int c; int d; int e; } local;
    int result = fn_803A9BB4(&local.a, arg0, 1);
    if (result == 0) {
        fn_803BC138(&local.a);
    } else {
        *(int*)(lbl_8053B248 + 0x1c) = result;
    }
    fn_803C290C();
}
