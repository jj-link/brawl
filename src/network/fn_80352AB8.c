#pragma force_active on
extern int lbl_805A0FD8;

int fn_80352AB8(void) {
    if (lbl_805A0FD8 == 25) {
        lbl_805A0FD8 = 26;
        return 1;
    }
    if (lbl_805A0FD8 == 0 || lbl_805A0FD8 == 26) {
        return 1;
    }
    return 0;
}
