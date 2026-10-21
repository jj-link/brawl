#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#include <revolution/GX/GXGeometry.h>
#pragma force_active on

void GXSetPointSize(u8 size, u32 offset) {
    GX_BP_SET_LINEPTWIDTH_POINTSZ(gxdt->linePtWidth, size);
    GX_BP_SET_LINEPTWIDTH_POINTOFS(gxdt->linePtWidth, offset);
    GX_BP_LOAD_REG(gxdt->linePtWidth);
    gxdt->lastWriteWasXF = FALSE;
}
