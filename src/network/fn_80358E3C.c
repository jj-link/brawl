#pragma force_active on
extern char lbl_80415790[];
extern int lbl_8048E680[];
extern void fn_80335638(int, const char *, ...);
extern int fn_80358F08(const char *, int *, int);

int fn_80358E3C(int arg0)
{
    int sp8 = 0;
    int valid;

    fn_80335638(4, lbl_80415790 + 0xC7);
    switch (lbl_8048E680[0]) {
    case 0:
    case 5:
        valid = 1;
        break;
    default:
        valid = 0;
        break;
    }
    if (valid == 0) {
        return 1;
    }
    if (fn_80358F08(lbl_80415790 + 0xE2, &sp8, 4) == 0) {
        return 2;
    }
    lbl_8048E680[0x14] = arg0;
    lbl_8048E680[0] = 3;
    lbl_8048E680[1] = 2;
    return 0;
}