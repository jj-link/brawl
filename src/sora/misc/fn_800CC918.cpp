#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern const char lbl_80457F24[];

extern "C" void fn_800CC918(int arg0, int arg1) {
    netReport__FPCce(lbl_80457F24);
    fn_800CCF30(arg0, arg1, 3, 2, -1);
}
