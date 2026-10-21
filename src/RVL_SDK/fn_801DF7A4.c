#pragma force_active on
extern void fn_801E25C0(void);
extern void fn_801E2750(void);
extern char lbl_804689E0[];
extern char lbl_804689EC[];
extern void fn_801D8690(const char *, int, const char *, ...);
extern int lbl_805A0634;
extern int lbl_805A06A4;

void fn_801DF7A4(void)
{
    if (lbl_805A0634 || lbl_805A06A4)
        fn_801E25C0();

    fn_801E2750();
    fn_801D8690(lbl_804689E0, 0x3CD, lbl_804689EC);
}
