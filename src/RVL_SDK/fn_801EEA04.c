#include <revolution/GX/GXFifo.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on
typedef union { u32 word; struct { u32 pad:3; u32 ptr:24; u32 low:5; } bits; } FifoReg;
typedef struct CpuFifo {
void* base; void* end; u32 size; void* hiWatermark; void* loWatermark;
void* readPtr; void* writePtr; u32 count; u8 wrap; u8 unk21; u8 unk22;
} CpuFifo;
extern CpuFifo lbl_804DED84;
extern u8 lbl_805A0898, lbl_805A08B0;
extern u32* __piReg;
extern s16* __cpReg;
extern u8 fn_801EE90C(void);
extern void fn_801D50A0(void);
void GXSetCPUFifo(GXFifoObj* fifo) {
u32 status; u32 v; u32 temp_r6; FifoReg reg;
status = OSDisableInterrupts();
if (fifo == 0) {
lbl_805A0898 = 0; lbl_805A08B0 = 0;
lbl_804DED84.unk22 = 0; lbl_804DED84.unk21 = 0;
OSRestoreInterrupts(status); return;
}
lbl_804DED84 = *(CpuFifo*)fifo;
lbl_805A0898 = 1; lbl_804DED84.unk21 = 1;
if ((u8)fn_801EE90C() != 0) {
lbl_805A08B0 = 1; lbl_804DED84.unk22 = 1;
reg.word = 0;
__piReg[3] = (u32)lbl_804DED84.base & 0x3FFFFFFF;
__piReg[4] = (u32)lbl_804DED84.end & 0x3FFFFFFF;
reg.bits.ptr = (u32)lbl_804DED84.writePtr >> 5;
__piReg[5] = reg.word;
v = *(u32*)((u8*)__GXData + 0x10) | 3;
*(u32*)((u8*)__GXData + 0x10) = v; __cpReg[2] = (s16)v;
v = (__GXData->cpCtrlReg | 4) & 0xFFFFFFF7;
__GXData->cpCtrlReg = v; __cpReg[1] = (s16)v;
v = __GXData->cpCtrlReg | 0x10;
__GXData->cpCtrlReg = v; __cpReg[1] = (s16)v;
} else {
lbl_804DED84.unk22 = 0;
if (lbl_805A08B0 != 0) {
v = __GXData->cpCtrlReg & 0xFFFFFFEF;
__GXData->cpCtrlReg = v; __cpReg[1] = (s16)v;
lbl_805A08B0 = 0;
}
__GXData->cpCtrlReg &= 0xFFFFFFF3;
__cpReg[1] = (s16)__GXData->cpCtrlReg;
reg.word = 0;
__piReg[3] = (u32)lbl_804DED84.base & 0x3FFFFFFF;
__piReg[4] = (u32)lbl_804DED84.end & 0x3FFFFFFF;
reg.bits.ptr = (u32)lbl_804DED84.writePtr >> 5;
__piReg[5] = reg.word;
}
fn_801D50A0(); OSRestoreInterrupts(status);
}