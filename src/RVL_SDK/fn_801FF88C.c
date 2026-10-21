#pragma force_active on
extern int lbl_805A0A68;
extern int lbl_805A0A38;
extern char lbl_804E4960[];

void fn_801FF88C(char **out) {
    if (lbl_805A0A68) {
        *out = lbl_804E4960 + lbl_805A0A38 * 0x600;
    } else {
        *out = 0;
    }
}
