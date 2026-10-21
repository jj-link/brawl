#pragma force_active on
extern int lbl_805A1120;
extern int fn_8035AFF0(int);
extern void fn_8035AF74(int);

void fn_803885E8(void)
{
    if (lbl_805A1120 != 0 && fn_8035AFF0(lbl_805A1120) == 0) {
        fn_8035AF74(lbl_805A1120);
        lbl_805A1120 = 0;
    }
}
