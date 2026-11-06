#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern char lbl_804893BC[];

int fn_80336138(int arg0) {
    int r31 = (int)0xFFFE8130;
    int r30 = 7;
    if (arg0 == 0) return 0;
    fn_80335638(2, lbl_804893BC, arg0);
    switch (arg0) {
    case -8: r31 -= 0x320; break;
    case -7: r31 -= 0x32a; break;
    case -6: r31 -= 0x348; break;
    case -5: case -4: case -3: r31 -= 0x334; break;
    case -2: r31 -= 0x33e; break;
    case 1: case 20: r30 = 9; r31 -= 1; break;
    case 2: r31 -= 0x348; break;
    case 3: r31 -= 0x352; break;
    case 4: r31 -= 0x1e; break;
    case 5: r31 -= 0x32; break;
    case 6: case 11: case 12: r31 -= 0x14; break;
    case 7: r31 -= 0x35c; break;
    case 8: case 9: case 10: r31 -= 0x366; break;
    case 13: case 14: r31 -= 0x370; break;
    case 15: r31 -= 0x37a; break;
    case 16: r31 -= 0x384; break;
    case 17: r31 -= 0x38e; break;
    }
    fn_8033524C(r30, r31);
    return arg0;
}