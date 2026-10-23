#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#pragma force_active on

void fn_801F4880(GXBool enable) {
    u32 blendModeReg = gxdt->blendMode;
    GX_BP_SET_BLENDMODE_DITHER(blendModeReg, enable);
    GX_BP_LOAD_REG(blendModeReg);
    gxdt->blendMode = blendModeReg;
    gxdt->lastWriteWasXF = FALSE;
}
