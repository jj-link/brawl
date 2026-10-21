#pragma force_active on
extern int fn_80396810(void);
extern int lbl_805A0FF8;

int fn_80358454(void) {
    if (lbl_805A0FF8 == 0) {
        return 0;
    }
    return fn_80396810() == 0;
}
