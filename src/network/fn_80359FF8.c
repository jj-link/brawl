#pragma force_active on
extern int fn_8035A2B8(int, int *);
extern void fn_8035A1E4(int, void *, int, ...);
extern void fn_8033524C(int, int);
extern char lbl_80415D08[];

int fn_80359FF8(int arg0, int arg1) {
    int sp8;
    int temp_r31;
    int temp_r5;

    temp_r31 = fn_8035A2B8(arg1, &sp8);
    if (temp_r31 != 0) {
        fn_8035A1E4(0x45, lbl_80415D08, temp_r31);
        temp_r5 = arg0 * 0x64;
        fn_8033524C(sp8, 0xFFFF63C0 - (temp_r31 + temp_r5));
    }
    return temp_r31;
}
