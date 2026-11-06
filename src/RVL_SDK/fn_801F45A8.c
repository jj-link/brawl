#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXPixel.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#pragma force_active on

void fn_801F45A8(GXBool enable, u16 center, const GXFogAdjTable *table)
{
    u32 fogRangeReg;
    u32 fogRangeRegK;
    int i;

    if (enable) {
        for (i = 0; i < 10; i += 2) {
            fogRangeRegK = 0;
            GX_BP_SET_FOGRANGEK_HI(fogRangeRegK, table->r[i]);
            GX_BP_SET_FOGRANGEK_LO(fogRangeRegK, table->r[i + 1]);
            GX_BP_SET_OPCODE(fogRangeRegK, GX_BP_REG_FOGRANGEK0 + (i / 2));
            GX_BP_LOAD_REG(fogRangeRegK);
        }
    }

    fogRangeReg = 0;
    GX_BP_SET_FOGRANGE_CENTER(fogRangeReg, center + 342);
    GX_BP_SET_FOGRANGE_ENABLED(fogRangeReg, enable);
    GX_BP_SET_OPCODE(fogRangeReg, GX_BP_REG_FOGRANGE);
    GX_BP_LOAD_REG(fogRangeReg);
    gxdt->lastWriteWasXF = 0;
}