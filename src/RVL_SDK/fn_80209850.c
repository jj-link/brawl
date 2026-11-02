#include <types.h>
#include <revolution/DSP/dsp_hardware.h>
#pragma force_active on

void fn_80209850(u32 arg0) {
    DSP_HW_REGS[DSP_DSPMBOX_H] = (u16)(arg0 >> 16);
    DSP_HW_REGS[DSP_DSPMBOX_L] = (u16)arg0;
}
