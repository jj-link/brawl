#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern char lbl_80457EA0[];

extern "C" void fn_800CC860(int arg0, int arg1) {
    netReport__FPCce(lbl_80457EA0);
    fn_800CCF30(arg0, arg1, 2, 2, -1);
}
