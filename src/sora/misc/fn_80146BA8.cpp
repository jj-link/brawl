#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_8045F3E0[];

extern "C" int fn_80146BA8(void) {
    netReport__FPCce(lbl_8045F3E0);
    return 1;
}
