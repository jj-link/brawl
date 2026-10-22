#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#pragma force_active on

void fn_801F471C(GXBool enable) {
    u32 v = gxdt->blendMode;
    GX_BP_SET_BLENDMODE_COLOR_UPDATE(v, enable);
    GX_BP_LOAD_REG(v);
    gxdt->blendMode = v;
    gxdt->lastWriteWasXF = FALSE;
}
