#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F1FB8(void) {
    GX_BP_LOAD_REG(0x550003FF);
    GX_BP_LOAD_REG(0x560003FF);
    gxdt->lastWriteWasXF = FALSE;
}
