#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_8045F7A8[];

extern "C" void fn_8014BF68(char* arg0, int arg1) {
    char* base = lbl_8045F7A8;
    int temp_r0;
    if (arg1 != 0) {
        temp_r0 = *(int*)(arg0 + 0x34A4);
        if (temp_r0 != 0) {
            netReport__FPCce(base + 0xABC, temp_r0);
            *(int*)(arg0 + 0x34A4) = arg1;
            return;
        }
    } else {
        temp_r0 = *(int*)(arg0 + 0x34A4);
        if (temp_r0 == 0) {
            return;
        }
    }
    *(int*)(arg0 + 0x34A4) = arg1;
    if (arg1 != 0) {
        netReport__FPCce(base + 0xAF4);
        return;
    }
    netReport__FPCce(base + 0x7AC);
}
