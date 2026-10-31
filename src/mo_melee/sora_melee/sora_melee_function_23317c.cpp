#pragma force_active on
extern "C" {
extern char* lbl_27_bss_5668;
void fn_40_64F4(void);

void fn_27_23317C(void) {
    char* p = lbl_27_bss_5668;
    if (p == 0) return;
    if (*(int*)(p + 0x44) == 0x3d) fn_40_64F4();
}
}
