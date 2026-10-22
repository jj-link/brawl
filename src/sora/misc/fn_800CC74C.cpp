#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800CCF30(int, int, int, int, int);
extern "C" char lbl_80457DF8[];

extern "C" void fn_800CC74C(int arg0, int arg1) {
    netReport__FPCce(lbl_80457DF8);
    fn_800CCF30(arg0, 4, 0, 3, arg1);
}
