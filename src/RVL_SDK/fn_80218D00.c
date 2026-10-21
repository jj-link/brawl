#pragma force_active on
extern void OSRegisterShutdownFunction(void* info);
extern void fn_80218AF0(void);
extern int fn_8022B7C4(void);
extern char lbl_8047C6E0[16];
extern unsigned char lbl_805A0C50;
extern int lbl_805A0C60;

void fn_80218D00(void) {
    if (lbl_805A0C50 == 0) {
        OSRegisterShutdownFunction(lbl_8047C6E0);
        lbl_805A0C50 = 1;
    }
    if (fn_8022B7C4() != 0) {
        lbl_805A0C60 = 0;
        fn_80218AF0();
    }
}
