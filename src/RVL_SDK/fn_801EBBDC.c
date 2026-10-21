#pragma force_active on
extern int lbl_805A0860;
extern char lbl_804754A8[];
extern void fn_801EBA48(char *p);

void fn_801EBBDC(void) {
    fn_801EBA48(lbl_804754A8 + lbl_805A0860 * 0x22);
}
