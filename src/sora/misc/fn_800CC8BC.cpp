#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern char lbl_80457EE0[];

extern "C" void fn_800CC8BC(int arg0, int arg1) {
    netReport__FPCce(lbl_80457EE0);
    fn_800CCF30(arg0, 4, 2, 3, arg1);
}
