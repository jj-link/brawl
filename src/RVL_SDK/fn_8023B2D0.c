#pragma force_active on
extern char lbl_80529CF8[];

int fn_8023B2D0(void (*arg0)(void *, void *)) {
    if (arg0 != 0) {
        arg0(lbl_80529CF8 + 0x630, lbl_80529CF8);
    }
    return 0;
}
