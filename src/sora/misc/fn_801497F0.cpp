#pragma force_active on
extern int g_NtMatchingStatus;
extern unsigned char lbl_8059E745;
extern char lbl_80460264[];
extern char lbl_8046029C[];
extern "C" void netReport__FPCce(const char*, ...);
extern "C" int fn_801497F0(char* self, int arg1, signed char arg2) {
    int valid = (g_NtMatchingStatus >= 7 && g_NtMatchingStatus <= 9);
    if (!valid)
        return 0;
    if (arg1)
        *(unsigned char*)(self + 0x34a8) = lbl_8059E745;
    *(signed char*)(self + 0x34a9) = arg2;
    *(signed char*)(self + 0x33f6) = arg1;
    *(unsigned char*)(self + 0x33f5) = 1;
    if (arg1) {
        int state = *(int*)(self + 0x34a4);
        if (state) {
            netReport__FPCce(lbl_80460264, state);
            *(int*)(self + 0x34a4) = 2;
        } else {
            *(int*)(self + 0x34a4) = 2;
            netReport__FPCce(lbl_8046029C);
        }
    }
    return 1;
}