#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern void fn_801D8690(const char *, int, const char *, ...);
extern char lbl_8048E3D0[];

void fn_803571F4(unsigned int arg0, int arg1) {
    char *base = lbl_8048E3D0;
    switch (arg0) {
    case 0:
        break;
    case 1:
        fn_80335638(2, base + 0xC);
        fn_8033524C(9, -0x7919);
        break;
    case 3:
        fn_80335638(2, base + 0x28);
        fn_8033524C(15, -0x792C);
        break;
    case 4:
        fn_80335638(2, base + 0x40);
        fn_8033524C(9, -0x7921);
        fn_801D8690(base + 0x7C, 0x246, base + 0x88);
        break;
    case 7:
        fn_80335638(2, base + 0xB4, arg1);
        fn_8033524C(14, -0x7918 - arg1);
        break;
    case 6:
        fn_80335638(2, base + 0xD8);
        fn_8033524C(14, -0x7940);
        break;
    case 5:
        fn_80335638(2, base + 0x104);
        fn_8033524C(14, -0x7936);
        break;
    case 8:
        fn_80335638(2, base + 0x144);
        fn_8033524C(9, -0x7921);
        break;
    case 2:
        fn_80335638(2, base + 0x160);
        fn_8033524C(14, -0x7922);
        break;
    default:
        fn_801D8690(base + 0x7C, 0x25D, base + 0x170);
        break;
    }
}
