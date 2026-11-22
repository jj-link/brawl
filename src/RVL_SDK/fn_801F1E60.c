#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
void fn_801F1E60(u32 addr, s32 clear) {
    u32 z;
    u32 zc;
    int changed;
    if (clear) {
        z = gxdt->zMode | 15;
        GX_BP_LOAD_REG(z);
        z = gxdt->blendMode;
        GX_BP_LOAD_REG(z & ~3);
    }
    changed = 0;
    zc = gxdt->zControl;
    if (*(u8*)&gxdt->UNK_0x230[0x20] && (zc & 7) != 3) {
        changed = 1;
        zc = __rlwimi(zc, 3, 0, 29, 31);
    }
    if ((clear || (zc & 7) == 3) && ((zc & 0x40) >> 6) == 1) {
        changed = 1;
        zc &= 0xFFFFFFBF;
    }
    if (changed) { GX_BP_LOAD_REG(zc); }
    GX_BP_LOAD_REG(*(u32*)((u8*)gxdt + 0x240));
    GX_BP_LOAD_REG(*(u32*)((u8*)gxdt + 0x244));
    GX_BP_LOAD_REG(*(u32*)((u8*)gxdt + 0x248));
    GX_BP_LOAD_REG(__rlwimi(__rlwimi(0, addr, 27, 8, 31), 0x4B, 24, 0, 7));
    *(u32*)&gxdt->UNK_0x230[0x1c] = __rlwimi(*(u32*)&gxdt->UNK_0x230[0x1c], clear, 11, 20, 20);
    *(u32*)&gxdt->UNK_0x230[0x1c] &= ~0x4000;
    *(u32*)&gxdt->UNK_0x230[0x1c] = __rlwimi(*(u32*)&gxdt->UNK_0x230[0x1c], 0x52, 24, 0, 7);
    GX_BP_LOAD_REG(*(u32*)&gxdt->UNK_0x230[0x1c]);
    if (clear) {
        GX_BP_LOAD_REG(gxdt->zMode);
        GX_BP_LOAD_REG(gxdt->blendMode);
    }
    if (changed) { GX_BP_LOAD_REG(gxdt->zControl); }
    gxdt->lastWriteWasXF = 0;
}
