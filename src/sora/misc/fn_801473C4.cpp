#pragma force_active on
extern "C" int fn_8014B2E4();
extern "C" void netReport__FPCce(const char*, ...);
extern int lbl_805A03E8;
extern char lbl_8045F778[];

extern "C" void fn_801473C4(void) {
    if (lbl_805A03E8 != 0 && lbl_805A03E8 > 7) {
        if (fn_8014B2E4() == 0) {
            lbl_805A03E8 = 0;
            netReport__FPCce(lbl_8045F778);
        }
    }
}
