#pragma force_active on
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>

void fn_801F48AC(GXBool enable, u8 alpha) {
    u32 dstAlphaReg = gxdt->dstAlpha;
    GX_BP_SET_DSTALPHA_ALPHA(dstAlphaReg, alpha);
    GX_BP_SET_DSTALPHA_ENABLE(dstAlphaReg, enable);

    GX_BP_LOAD_REG(dstAlphaReg);
    gxdt->dstAlpha = dstAlphaReg;

    gxdt->lastWriteWasXF = FALSE;
}
