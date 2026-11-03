#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern u32 lbl_80476530[];

void fn_801F47D8(GXPixelFmt pixelFmt, GXZFmt16 zFmt) {
    u32 zControlRegOld = gxdt->zControl;

    GX_BP_SET_ZCONTROL_PIXEL_FMT(gxdt->zControl, lbl_80476530[pixelFmt]);
    GX_BP_SET_ZCONTROL_Z_FMT(gxdt->zControl, zFmt);

    if (zControlRegOld != gxdt->zControl) {
        GX_BP_LOAD_REG(gxdt->zControl);
        gxdt->genMode = __rlwimi(gxdt->genMode, __cntlzw((u32)(pixelFmt - 2)), 4, 22, 22);
        gxdt->gxDirtyFlags |= GX_DIRTY_GEN_MODE;
    }

    if (lbl_80476530[pixelFmt] == GX_PF_Y8) {
        GX_BP_SET_DSTALPHA_YUV_FMT(gxdt->dstAlpha, pixelFmt - GX_PF_Y8);
        GX_BP_SET_OPCODE(gxdt->dstAlpha, GX_BP_REG_DSTALPHA);
        GX_BP_LOAD_REG(gxdt->dstAlpha);
    }

    gxdt->lastWriteWasXF = FALSE;
}
