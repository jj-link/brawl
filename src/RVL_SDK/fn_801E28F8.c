#pragma force_active on
extern int lbl_805A0718;
extern int lbl_805A070C;
extern int lbl_805A0710;
extern int lbl_804DDFA0[8];
extern char lbl_804DDFC0[32];
extern int fn_80212D40(int, int, void *, int, void *, int);

int fn_801E28F8(void) {
    int result;
    if (lbl_805A0718 == 0) return 0;
    if (lbl_805A070C == 0) return -6;
    result = fn_80212D40(lbl_805A0710, 0x3002, lbl_804DDFA0, 0x20, lbl_804DDFC0, 0x20);
    if (result == 0) lbl_805A0718 = 0;
    return result;
}