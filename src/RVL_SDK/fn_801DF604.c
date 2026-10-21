#pragma force_active on
extern void fn_801DF504(int argument);
extern void fn_801D8690(const char *, int, const char *, ...);
extern char lbl_804689E0[];
extern char lbl_80468A18[];

void OSReturnToMenu(void) {
    fn_801DF504(0);
    fn_801D8690(lbl_804689E0, 0x342, lbl_80468A18);
}
