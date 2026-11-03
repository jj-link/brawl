#include <types.h>
#include <revolution/DSP/dsp_hardware.h>
#pragma force_active on

extern void fn_80209A98(...);
extern void fn_80209AE8(void);
extern void fn_801DCF5C(int, void (*)(void));
extern void fn_801DD320(unsigned int);
extern void OSRegisterVersion(const char *ver);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern u8 lbl_8047BE70[];
extern const char *lbl_8059EB28;
extern int lbl_805A0B78;
extern int lbl_805A0B88;
extern int lbl_805A0B8C;
extern int lbl_805A0B90;
extern int lbl_805A0B94;

void fn_80209864(void) {
    int enabled;

    fn_80209A98(lbl_8047BE70 + 0x48, lbl_8047BE70 + 0x68, lbl_8047BE70 + 0x74);
    if (lbl_805A0B78 != 1) {
        OSRegisterVersion(lbl_8059EB28);
        enabled = OSDisableInterrupts();
        fn_801DCF5C(7, fn_80209AE8);
        fn_801DD320(0x01000000);
        DSP_HW_REGS[DSP_CSR] =
            (DSP_HW_REGS[DSP_CSR] & ~(DSP_CSR_AIDINT | DSP_CSR_ARINT | DSP_CSR_DSPINT)) |
            DSP_CSR_RES;
        DSP_HW_REGS[DSP_CSR] &=
            ~(DSP_CSR_HALT | DSP_CSR_AIDINT | DSP_CSR_ARINT | DSP_CSR_DSPINT);
        lbl_805A0B88 = 0;
        lbl_805A0B94 = 0;
        lbl_805A0B8C = 0;
        lbl_805A0B90 = 0;
        lbl_805A0B78 = 1;
        OSRestoreInterrupts(enabled);
    }
}
