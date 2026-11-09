#pragma force_active on
#include <types.h>
#include <revolution/DSP/dsp_hardware.h>

s32 OSGetTick(void);

void fn_801D75DC(void) {
    s32 temp_r31;
    u16 v;

    DSP_HW_REGS[DSP_CSR] = 0x804;
    DSP_HW_REGS[DSP_AI_DMA_CSR] &= 0x7FFF;
    v = DSP_HW_REGS[DSP_CSR];
    while (v & 0x400) {
        v = DSP_HW_REGS[DSP_CSR];
    }
    v = DSP_HW_REGS[DSP_CSR];
    while (v & 0x200) {
        v = DSP_HW_REGS[DSP_CSR];
    }
    DSP_HW_REGS[DSP_CSR] = 0x8AC;
    DSP_HW_REGS[DSP_DSPMBOX_H] = 0;
    do {
    } while (((DSP_HW_REGS[DSP_CPUMBOX_H] << 16) | DSP_HW_REGS[DSP_CPUMBOX_L]) & 0x80000000);
    temp_r31 = OSGetTick();
    do {
    } while ((OSGetTick() - temp_r31) < 0x2C);
    DSP_HW_REGS[DSP_CSR] |= 1;
    v = DSP_HW_REGS[DSP_CSR];
    while (v & 1) {
        v = DSP_HW_REGS[DSP_CSR];
    }
}
