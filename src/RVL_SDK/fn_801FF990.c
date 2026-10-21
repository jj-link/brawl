#pragma force_active on
extern int lbl_805A0A34;
extern char lbl_804E5B60[];

void fn_801FF990(char** out) {
    *out = lbl_804E5B60 + lbl_805A0A34 * 0x600;
}
