#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern char lbl_80457E64[];

extern "C" void fn_800CC804(int arg0, int arg1) {
    netReport__FPCce(lbl_80457E64);
    fn_800CCF30(arg0, 4, 1, 3, arg1);
}
