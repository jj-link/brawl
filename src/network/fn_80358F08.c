#pragma force_active on

extern int fn_803520B0(void);
extern void fn_803550F0(int, char *);
extern int fn_8035546C(int, int, int, int, int);
extern void fn_8033524C(int, int);
extern void fn_80335638(int, const char *, ...);
extern char lbl_80415790[];
extern int lbl_8048E680[];

int fn_80358F08(int arg0, int arg1, int arg2) {
    int temp_r3;
    int var_r3;

    temp_r3 = fn_803520B0();
    switch (temp_r3) {
    case 0:
        fn_803550F0(1, lbl_80415790 + 0x102);
        break;
    case 1:
        fn_803550F0(0, lbl_80415790 + 0x102);
        break;
    }
    var_r3 = fn_8035546C(arg0, lbl_8048E680[18], arg1, arg2, 0);
    switch (var_r3) {
    case 0:
        lbl_8048E680[0] = 3;
        return 1;
    case 1:
        fn_8033524C(9, (int)0xFFFE7D3F);
        return 0;
    case 2:
        fn_80335638(8, lbl_80415790 + 0x144);
        fn_8033524C(9, (int)0xFFFE7D47);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return 0;
    case 3:
        fn_8033524C(9, (int)0xFFFE7D3F);
        return 0;
    default:
        return var_r3;
    }
}
