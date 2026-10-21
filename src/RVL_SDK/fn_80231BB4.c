#pragma force_active on
extern void (*lbl_805A0D24)(int);

void fn_80231BB4(signed char c) {
    if (lbl_805A0D24 == 0) {
        return;
    }
    if (c >= 0) {
        lbl_805A0D24(0);
    } else {
        lbl_805A0D24(1);
    }
}
