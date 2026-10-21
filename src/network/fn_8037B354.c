#pragma force_active on
extern int lbl_804901F0[];

void fn_8037B354(int arg0, int arg1) {
    if (arg0 < 0x32 || arg0 > 0xFE) {
        return;
    }
    lbl_804901F0[arg0] = arg1;
}
