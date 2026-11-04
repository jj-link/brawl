#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>

#pragma force_active on

void fn_801F5500(u32 x, u32 y, u32 w, u32 h) {
    u32 reg, y1, x1, y2, x2;

    y1 = y + 342;
    x1 = x + 342;
    y2 = y1 + h - 1;

    reg = __GXData->scissorTL;
    GX_BP_SET_SCISSORTL_TOP(reg, y1);
    GX_BP_SET_SCISSORTL_LEFT(reg, x1);
    __GXData->scissorTL = reg;

    x2 = x1 + w - 1;
    reg = __GXData->scissorBR;
    GX_BP_SET_SCISSORBR_BOT(reg, y2);
    GX_BP_SET_SCISSORBR_RIGHT(reg, x2);
    __GXData->scissorBR = reg;

    GX_BP_LOAD_REG(__GXData->scissorTL);
    GX_BP_LOAD_REG(__GXData->scissorBR);
    __GXData->lastWriteWasXF = FALSE;
}
