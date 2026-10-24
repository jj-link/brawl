#include <revolution/GX.h>
#pragma force_active on

void fn_801F4010(GXZTexOp op, GXTexFmt fmt, u32 z) {
    u32 ztex1 = 0;
    u32 type;
    u32 ztex2;

    ztex1 = GX_BITSET(ztex1, 8, 24, z);
    ztex1 = GX_BITSET(ztex1, 0, 8, GX_BP_REG_ZTEXTURE0);

    switch (fmt) {
    case GX_TF_Z8:    type = 0; break;
    case GX_TF_Z16:   type = 1; break;
    case GX_TF_Z24X8: type = 2; break;
    default:          type = 2; break;
    }

    ztex2 = 0;
    ztex2 = GX_BITSET(ztex2, 30, 2, type);
    ztex2 = GX_BITSET(ztex2, 28, 2, op);
    ztex2 = GX_BITSET(ztex2, 0, 8, GX_BP_REG_ZTEXTURE1);

    GX_BP_LOAD_REG(ztex1);
    GX_BP_LOAD_REG(ztex2);

    gxdt->lastWriteWasXF = FALSE;
}
