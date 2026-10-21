#pragma force_active on
// main/fn_801EA078.c
// Clears the global flag at 0x805A0834 and returns 1.

extern int lbl_805A0834;

int fn_801EA078() {
    lbl_805A0834 = 0;
    return 1;
}
