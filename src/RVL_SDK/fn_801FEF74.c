#include <revolution/OS/OSTime.h>
#include <revolution/AI/ai_hardware.h>

#pragma force_active on

extern s64 lbl_805A09E8;
extern s64 lbl_805A0A08;
extern s64 lbl_805A09F0;
extern s64 lbl_805A09F8;
extern s64 lbl_805A0A00;

void fn_801FEF74(void)
{
    s64 t2 = 0;
    int done = 0;
    s64 delay = 0;
    s64 t1;

    while (!done) {
        s64 diff;
        u32 sample;

        AI_HW_REGS[AI_AICR] =
            (AI_HW_REGS[AI_AICR] & ~0x20) | 0x20;
        AI_HW_REGS[AI_AICR] &= ~2;
        AI_HW_REGS[AI_AICR] =
            (AI_HW_REGS[AI_AICR] & ~1) | 1;

        sample = AI_HW_REGS[AI_AISCNT] & 0x7FFFFFFF;
        while (sample == (AI_HW_REGS[AI_AISCNT] & 0x7FFFFFFF)) {
        }

        t1 = OSGetTime();

        AI_HW_REGS[AI_AICR] =
            (AI_HW_REGS[AI_AICR] & ~2) | 2;
        AI_HW_REGS[AI_AICR] =
            (AI_HW_REGS[AI_AICR] & ~1) | 1;

        sample = AI_HW_REGS[AI_AISCNT] & 0x7FFFFFFF;
        while (sample == (AI_HW_REGS[AI_AISCNT] & 0x7FFFFFFF)) {
        }

        t2 = OSGetTime();
        diff = t2 - t1;

        AI_HW_REGS[AI_AICR] &= ~2;
        AI_HW_REGS[AI_AICR] &= ~1;

        if (diff < lbl_805A0A08 - lbl_805A09E8) {
            delay = lbl_805A09F8;
            done = 1;
        } else if (!(diff < lbl_805A0A08 + lbl_805A09E8) &&
                   diff < lbl_805A0A00 - lbl_805A09E8) {
            delay = lbl_805A09F0;
            done = 1;
        } else {
            done = 0;
        }
    }

    {
        s64 end = t2 + delay;
        while (OSGetTime() < end) {
        }
    }
}
