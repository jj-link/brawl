#pragma force_active on
#include <revolution/OS/OSInterrupt.h>
typedef struct Fifo {
    u32 base, end, size, hiWatermark, loWatermark;
    s32 readPtr, writePtr, count;
    u8 wrap, pad[3];
} Fifo;
extern u8 lbl_805A0898, lbl_805A0899, lbl_805A08B0;
extern u32* __piReg;
extern u16* __cpReg;
extern Fifo lbl_804DED84, lbl_804DED60;
void fn_801EEE74(void)
{
    u32 enabled;
    u32 reg;
    enabled = OSDisableInterrupts();
    if (lbl_805A0898) {
        reg = __piReg[5];
        lbl_804DED84.writePtr = (reg & 0x1FFFFFE0) + 0x80000000;
        lbl_804DED84.wrap = (reg >> 29) & 1;
    }
    if ((s32)lbl_805A0899 != 0) {
        const u16* cpReg = __cpReg;
        u32 tmp;
        lbl_804DED60.readPtr = (cpReg[0x1C] | (cpReg[0x1D] << 16)) + 0x80000000;
        tmp = cpReg[0x19] << 16;
        tmp |= cpReg[0x18];
        lbl_804DED60.count = tmp;
    }
    if (lbl_805A08B0) {
        lbl_804DED84.readPtr = lbl_804DED60.readPtr;
        lbl_804DED84.count = lbl_804DED60.count;
        lbl_804DED60.writePtr = lbl_804DED84.writePtr;
        lbl_804DED60.wrap = lbl_804DED84.wrap;
    } else if (lbl_805A0898) {
        lbl_804DED84.count = lbl_804DED84.writePtr - lbl_804DED84.readPtr;
        if (lbl_804DED84.count < 0) {
            lbl_804DED84.count += lbl_804DED84.size;
        }
    }
    OSRestoreInterrupts(enabled);
}