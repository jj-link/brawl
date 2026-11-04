#pragma force_active on
extern char lbl_80415790[];
extern int lbl_8048E680[];
extern void fn_80335638(int, const char *, ...);
extern int fn_80358F08(const char *, int *, int);

int fn_80358A0C(int arg0, int arg1, int arg2, int arg3)
{
    int sp8;
    int valid;

    fn_80335638(4, lbl_80415790 + 0x3D);
    switch (lbl_8048E680[0]) {
    case 0:
    case 5:
        valid = 1;
        break;
    default:
        valid = 0;
        break;
    }
    if (valid == 0)
        return 1;

    lbl_8048E680[7] = arg0;
    lbl_8048E680[8] = arg1;
    lbl_8048E680[9] = arg2;
    lbl_8048E680[11] = arg3;
    lbl_8048E680[1] = 2;
    fn_80335638(4, lbl_80415790 + 0x54);
    switch (lbl_8048E680[7]) {
    case 0:
        sp8 = 0x01000000;
        break;
    case 1:
    case 2:
    case 3:
        sp8 = 0x02000000;
        break;
    case 4:
        sp8 = 0x03000000;
        break;
    }
    if (fn_80358F08(lbl_80415790 + 0x6B, &sp8, 4) == 0) {
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
    } else {
        lbl_8048E680[0] = 3;
    }
    return 0;
}