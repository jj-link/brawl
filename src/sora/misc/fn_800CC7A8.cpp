#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern char lbl_80457E30[];

extern "C" void fn_800CC7A8(int arg0, int arg1) {
    netReport__FPCce(lbl_80457E30, arg1);
    fn_800CCF30(arg0, arg1, 1, 2, -1);
}
