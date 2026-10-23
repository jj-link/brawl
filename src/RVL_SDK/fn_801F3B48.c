#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#pragma force_active on

void __GXSetIndirectMask(u32 mask) {
    GX_BP_SET_INDIMASK_IMASK(gxdt->ind_imask, mask);
    GX_BP_LOAD_REG(gxdt->ind_imask);
    gxdt->lastWriteWasXF = FALSE;
}
