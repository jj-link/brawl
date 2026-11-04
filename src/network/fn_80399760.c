#pragma force_active on
extern int lbl_805A1170;
extern int lbl_805A116C;
extern unsigned int *lbl_805A1168;
extern int fn_803997D8(void);
extern void fn_801D7718(void *, unsigned int);

int fn_80399760(void)
{
    int result;
    lbl_805A116C = 0;
    lbl_805A1168 = (unsigned int *)(lbl_805A1170 + 0x1300);
    result = fn_803997D8();
    if (result != -20 && result == 0) {
        *(unsigned long long *)0x800031C0 = *(unsigned long long *)(lbl_805A1168 + 2);
        fn_801D7718((void *)0x800031C0, 0x20);
    }
    return result;
}
