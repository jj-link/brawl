#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(void);
extern unsigned char lbl_805A11E0;

int fn_803A66F0(void) {
    int var_r31;

    var_r31 = 0;
    OSDisableInterrupts();
    switch ((int)lbl_805A11E0) {
        case 1:
        case 2:
            var_r31 = 1;
            break;
        default:
            break;
    }
    OSRestoreInterrupts();
    return var_r31;
}
