#pragma force_active on
#include <types.h>
#include <revolution/DSP/dsp_hardware.h>
extern int lbl_805A0630;
extern char lbl_80467268[];
extern u32 fn_801D713C(void);
extern void fn_801D71F4(int);
extern void* memcpy(void*, const void*, unsigned long);
extern void DCFlushRange(void*, u32);
extern s32 OSGetTick(void);
void fn_801D7414(void) {
    u16 cpuMboxHi;
    s32 start;
    u16 ctrl;
    if (!lbl_805A0630) fn_801D71F4(1);
    memcpy((void*)(fn_801D713C()-128), (void*)0x81000000,128);
    memcpy((void*)0x81000000,lbl_80467268,128);
    DCFlushRange((void*)0x81000000,128);
    DSP_HW_REGS[DSP_AR_SIZE]=0x43;
    DSP_HW_REGS[DSP_CSR]=0x8AC;
    DSP_HW_REGS[DSP_CSR]|=1;
    while (DSP_HW_REGS[DSP_CSR]&1) {}
    DSP_HW_REGS[DSP_DSPMBOX_H]=0;
    while (((DSP_HW_REGS[DSP_CPUMBOX_H]<<16)|DSP_HW_REGS[DSP_CPUMBOX_L])&0x80000000) {}
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_MMADDR_H]=0x01000000;
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_ARADDR_H]=0;
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_CNT_H]=32;
    for(ctrl=DSP_HW_REGS[DSP_CSR];!(ctrl&32);ctrl=DSP_HW_REGS[DSP_CSR]) {}
    DSP_HW_REGS[DSP_CSR]=ctrl;
    start=OSGetTick();
    do {} while(OSGetTick()-start<2194);
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_MMADDR_H]=0x01000000;
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_ARADDR_H]=0;
    *(u32*)&DSP_HW_REGS[DSP_AR_DMA_CNT_H]=32;
    for(ctrl=DSP_HW_REGS[DSP_CSR];!(ctrl&32);ctrl=DSP_HW_REGS[DSP_CSR]) {}
    DSP_HW_REGS[DSP_CSR]=ctrl;
    DSP_HW_REGS[DSP_CSR]&=~0x800;
    while(DSP_HW_REGS[DSP_CSR]&0x400) {}
    DSP_HW_REGS[DSP_CSR]&=~4;
    for(cpuMboxHi=DSP_HW_REGS[DSP_CPUMBOX_H];!(cpuMboxHi&0x8000);cpuMboxHi=DSP_HW_REGS[DSP_CPUMBOX_H]) {}
    DSP_HW_REGS[DSP_CPUMBOX_L];
    DSP_HW_REGS[DSP_CSR]|=4;
    DSP_HW_REGS[DSP_CSR]=0x8AC;
    DSP_HW_REGS[DSP_CSR]|=1;
    while(DSP_HW_REGS[DSP_CSR]&1) {}
    memcpy((void*)0x81000000,(void*)(fn_801D713C()-128),128);
}
