#pragma force_active on
extern "C" {
void netReport__FPCce(const char*, ...);
void fn_801498B0(int);
extern int gUnk805a03d8;
extern char lbl_8045F230[];
}

extern "C" void fn_8014652C(char* arg0) {
    netReport__FPCce(lbl_8045F230);
    gUnk805a03d8 = 7;
    fn_801498B0(*(int*)(arg0 + 0x30));
}
