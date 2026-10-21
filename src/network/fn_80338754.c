#pragma force_active on
extern int fn_80338D90(void);
extern void *lbl_805A0F80;

int fn_80338754(void) {
    if (fn_80338D90()) {
        ((int *)lbl_805A0F80)[1] = 1;
        ((int *)lbl_805A0F80)[12] = 0;
        return 1;
    }
    return 0;
}
