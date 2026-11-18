#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

#define GXW(off) (*(u32 *)((u8 *)__GXData + (off)))

void fn_801F1D24(u32 dest, s32 clear) {
    u32 reg;
    u32 tmp;
    s32 changePeCtrl;
    if (clear) {
        reg = GXW(0x228);
        reg = GX_BITSET(reg, 31, 1, 1);
        reg = GX_BITSET(reg, 28, 3, 7);
        GX_BP_LOAD_REG(reg);
        reg = GXW(0x220);
        reg = GX_BITSET(reg, 31, 1, 0);
        reg = GX_BITSET(reg, 30, 1, 0);
        GX_BP_LOAD_REG(reg);
    }
    changePeCtrl = 0;
    if (clear || (GXW(0x22C) & 7) == 3) {
        if (((GXW(0x22C) >> 6) & 1) == 1) {
            changePeCtrl = 1;
            tmp = GXW(0x22C);
            tmp &= ~0x40;
            GX_BP_LOAD_REG(tmp);
        }
    }
    GX_BP_LOAD_REG(GXW(0x230));
    GX_BP_LOAD_REG(GXW(0x234));
    GX_BP_LOAD_REG(GXW(0x238));
    reg = 0;
    reg = __rlwimi(reg, dest, 27, 8, 31);
    reg = __rlwimi(reg, 0x4B, 24, 0, 7);
    GX_BP_LOAD_REG(reg);
    GXW(0x23C) = __rlwimi(GXW(0x23C), clear, 11, 20, 20);
    GXW(0x23C) |= 0x4000;
    GXW(0x23C) = __rlwimi(GXW(0x23C), 0x52, 24, 0, 7);
    GX_BP_LOAD_REG(GXW(0x23C));
    if (clear) {
        GX_BP_LOAD_REG(GXW(0x228));
        GX_BP_LOAD_REG(GXW(0x220));
    }
    if (changePeCtrl) {
        GX_BP_LOAD_REG(GXW(0x22C));
    }
    __GXData->lastWriteWasXF = 0;
}
