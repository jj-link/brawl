#pragma force_active on
extern int lbl_805A0A34;
extern char lbl_804E6D60[];

void fn_801FFA60(int* out) {
    *out = (int)lbl_804E6D60 + lbl_805A0A34 * 0x480;
}
