#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#include <revolution/GX/GXGeometry.h>
#pragma force_active on

void GXSetLineWidth(u8 width, u32 offset) {
    GX_BP_SET_LINEPTWIDTH_LINESZ(gxdt->linePtWidth, width);
    GX_BP_SET_LINEPTWIDTH_LINEOFS(gxdt->linePtWidth, offset);
    GX_BP_LOAD_REG(gxdt->linePtWidth);
    gxdt->lastWriteWasXF = FALSE;
}
