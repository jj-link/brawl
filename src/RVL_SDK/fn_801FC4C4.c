#pragma force_active on
extern void (*lbl_805A09A8)(void);

void fn_801FC4C4(void) {
    if (lbl_805A09A8 != 0) {
        lbl_805A09A8();
    }
}
