#pragma force_active on
extern int lbl_805A0A34;
extern unsigned char lbl_804E5B60[];

void fn_801FF9CC(void** out) {
    *out = lbl_804E5B60 + lbl_805A0A34 * 0x600 + 0x180;
}
