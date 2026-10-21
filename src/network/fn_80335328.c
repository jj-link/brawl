#pragma force_active on

extern void fn_8034F020(int);
extern void fn_80350BBC(void);
extern void fn_8035C788(void *);
extern void fn_8035DFCC(void (*), void (*), void (*), void (*));

extern void fn_8033546C(void);
extern void fn_803355A4(void);
extern void fn_803354D4(void);
extern void fn_803355C8(void);

extern char lbl_8059F060;

void DWC_Shutdown(void) {
    fn_8035DFCC(fn_8033546C, fn_803355A4, fn_803354D4, fn_803355C8);
    fn_8035C788(&lbl_8059F060);
    fn_80350BBC();
    fn_8034F020(0);
}
