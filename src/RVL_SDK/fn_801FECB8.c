#include <revolution/DSP/dsp_hardware.h>
#pragma force_active on

u32 fn_801FECB8(void) {
    u16 a = DSP_HW_REGS[DSP_AI_DMA_START_H];
    u16 b = DSP_HW_REGS[DSP_AI_DMA_START_L];
    return ((a & 0x1FFF) << 16) | (b & 0xFFE0);
}
