#pragma force_active on
extern char lbl_805287A0[];
extern void fn_80231C24(void);
extern void fn_801D8194(void*, void*);

void fn_80231A8C(void) {
    fn_801D8194(fn_80231C24, lbl_805287A0 + 0x1000);
}
