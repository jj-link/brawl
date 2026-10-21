#pragma force_active on
typedef void (*FnPtr)(void);
extern FnPtr lbl_805A0230;

extern "C" int fn_801DCF24(void);
extern "C" void fn_80207CF8(void);
extern "C" void fn_8007DDA0(void);
extern "C" void OSRestoreInterrupts(int level);

extern "C" void fn_8007F5F0(void) {
    if (lbl_805A0230 != 0) {
        lbl_805A0230();
    }
    int level = fn_801DCF24();
    fn_80207CF8();
    fn_8007DDA0();
    OSRestoreInterrupts(level);
}
