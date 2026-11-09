#include <revolution/OS/OS.h>
#include <revolution/AI/ai_hardware.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern void fn_801DCF5C(int, void*);
extern void fn_801DD320(u32);
extern void fn_801FEF74(void);
extern void fn_801FEE68(void);
extern const char* lbl_8059EB08;
extern int lbl_805A09E0;
extern s64 lbl_805A09E8, lbl_805A09F0, lbl_805A09F8, lbl_805A0A00, lbl_805A0A08;
extern int lbl_805A0A14;
extern u32 lbl_805A0A18;
void fn_801FECE8(int arg0) {
    u32 t;
    BOOL saved;
    if (lbl_805A09E0 != 1) {
        OSRegisterVersion(lbl_8059EB08);
        t = (*(u32*)0x800000F8 / 4) / 125000;
        lbl_805A0A08 = (t * 0x7B24) / 8000;
        lbl_805A0A00 = (t * 0xA428) / 8000;
        lbl_805A09F8 = (t * 0xA410) / 8000;
        lbl_805A09F0 = (t * 0xF618) / 8000;
        lbl_805A09E8 = (t * 0xBB8) / 8000;
        AI_HW_REGS[AI_AICR] &= ~0x15;
        AI_HW_REGS[AI_AIVR] = 0;
        AI_HW_REGS[AI_AIIT] = 0;
        AI_HW_REGS[AI_AICR] = (AI_HW_REGS[AI_AICR] & 0xFFFFFFDF) | 0x20;
        if ((((AI_HW_REGS[AI_AICR] >> 6) & 1) ^ 1) != 0) {
            AI_HW_REGS[AI_AICR] &= 0xFFFFFFBF;
            saved = OSDisableInterrupts();
            fn_801FEF74();
            AI_HW_REGS[AI_AICR] |= 0x40;
            OSRestoreInterrupts(saved);
        }
        lbl_805A0A18 = 0;
        lbl_805A0A14 = arg0;
        fn_801DCF5C(5, (void*)fn_801FEE68);
        fn_801DD320(0x04000000);
        lbl_805A09E0 = 1;
    }
}