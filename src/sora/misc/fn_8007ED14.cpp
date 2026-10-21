#pragma force_active on
extern int lbl_805A0214;
extern unsigned char lbl_805A024A;

extern "C" int fn_8007ED14(void) {
    return lbl_805A0214 ? lbl_805A024A : 0;
}
