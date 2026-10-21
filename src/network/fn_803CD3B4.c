#pragma force_active on
extern int lbl_805A1250;

int fn_803CD3B4(int arg0) {
    if (lbl_805A1250 == 0) {
        return 0;
    }
    return lbl_805A1250 + (arg0 * 0x1E0) + 0x1B50;
}
