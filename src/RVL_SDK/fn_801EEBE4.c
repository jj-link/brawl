#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Fifo {
    u32 base;
    u32 end;
    u32 size;
    u32 hiWatermark;
    u32 loWatermark;
    s32 readPtr;
    s32 writePtr;
    s32 count;
    u8 wrap;
    u8 pad[3];
} Fifo;

extern u16* __cpReg;
extern Fifo lbl_804DED60;
extern u8 lbl_805A0899;
extern u8 lbl_805A08B0;
extern void fn_801D50A0(void);
extern u8 fn_801EE90C(void);

void GXSetGPFifo(GXFifoObj* fifo) {
    GXData* gx;
    GXData* gx2;
    u32 value;
    u32 enabled;

    enabled = OSDisableInterrupts();
    gx = __GXData;

    gx->cpCtrlReg &= ~1;
    __cpReg[1] = (u16)gx->cpCtrlReg;
    gx->cpCtrlReg &= ~0xC;
    __cpReg[1] = (u16)gx->cpCtrlReg;

    if (fifo == 0) {
        lbl_805A0899 = 0;
        lbl_805A08B0 = 0;
        gx->cpCtrlReg &= ~0x10;
        __cpReg[1] = (u16)gx->cpCtrlReg;
        ((u8*)&lbl_804DED60)[0x21] = 0;
        ((u8*)&lbl_804DED60)[0x22] = 0;
        OSRestoreInterrupts(enabled);
        return;
    }

    lbl_804DED60 = *(Fifo*)fifo;
    lbl_805A0899 = 1;
    ((u8*)&lbl_804DED60)[0x22] = 1;

    __cpReg[0x10] = (u16)lbl_804DED60.base;
    __cpReg[0x12] = (u16)lbl_804DED60.end;
    __cpReg[0x18] = (u16)lbl_804DED60.count;
    __cpReg[0x1A] = (u16)lbl_804DED60.writePtr;
    __cpReg[0x1C] = (u16)lbl_804DED60.readPtr;
    __cpReg[0x14] = (u16)lbl_804DED60.hiWatermark;
    __cpReg[0x16] = (u16)lbl_804DED60.loWatermark;
    __cpReg[0x11] = (u16)((lbl_804DED60.base >> 16) & 0x3FFF);
    __cpReg[0x13] = (u16)((lbl_804DED60.end >> 16) & 0x3FFF);
    __cpReg[0x19] = (u16)(lbl_804DED60.count >> 16);
    __cpReg[0x1B] = (u16)((lbl_804DED60.writePtr >> 16) & 0x3FFF);
    __cpReg[0x1D] = (u16)((lbl_804DED60.readPtr >> 16) & 0x3FFF);
    __cpReg[0x15] = (u16)(lbl_804DED60.hiWatermark >> 16);
    __cpReg[0x17] = (u16)(lbl_804DED60.loWatermark >> 16);

    fn_801D50A0();
    if (fn_801EE90C() != 0) {
        lbl_805A08B0 = 1;
        ((u8*)&lbl_804DED60)[0x21] = 1;
        value = (gx->cpCtrlReg | 4) & ~8;
        gx->cpCtrlReg = value;
        __cpReg[1] = (u16)value;
        gx->cpCtrlReg |= 0x10;
        __cpReg[1] = (u16)gx->cpCtrlReg;
    } else {
        lbl_805A08B0 = 0;
        ((u8*)&lbl_804DED60)[0x21] = 0;
        gx->cpCtrlReg &= ~0xC;
        __cpReg[1] = (u16)gx->cpCtrlReg;
        gx->cpCtrlReg &= ~0x10;
        __cpReg[1] = (u16)gx->cpCtrlReg;
    }

    value = gx->cpCtrlReg & ~2;
    gx2 = *(GXData**)&__GXData;
    __cpReg[1] = (u16)(value & ~0x20);
    __cpReg[1] = (u16)gx->cpCtrlReg;
    value = *(u32*)((u8*)gx2 + 0x10) | 3;
    *(u32*)((u8*)gx2 + 0x10) = value;
    __cpReg[2] = (u16)value;
    gx->cpCtrlReg |= 1;
    __cpReg[1] = (u16)gx->cpCtrlReg;
    OSRestoreInterrupts(enabled);
}
