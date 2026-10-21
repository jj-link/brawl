#pragma force_active on
extern int lbl_805A0A34;
extern unsigned char lbl_804E5B60[0x1200];

void fn_801FFA0C(unsigned char** out) {
    *out = lbl_804E5B60 + lbl_805A0A34 * 0x600 + 0x480;
}
