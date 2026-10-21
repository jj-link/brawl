#pragma force_active on
extern int lbl_805A0A38;
extern unsigned char lbl_804E5B60[];

void fn_801FF9AC(void** out) {
    *out = lbl_804E5B60 + lbl_805A0A38 * 0x600 + 0x480;
}
