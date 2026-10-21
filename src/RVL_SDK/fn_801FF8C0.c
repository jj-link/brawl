#pragma force_active on
extern int lbl_805A0A34;
extern char lbl_804E4960[];

void fn_801FF8C0(void** out) {
    *out = lbl_804E4960 + lbl_805A0A34 * 0x600;
}
