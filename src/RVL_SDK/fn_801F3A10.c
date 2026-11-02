#pragma force_active on
#include <revolution/GX.h>

void fn_801F3A10(GXIndTexStageID stage, GXTexCoordID coord, GXTexMapID map) {
    if (map == GX_TEXMAP_NULL) {
        map = GX_TEXMAP0;
    }

    if (coord == GX_TEXCOORD_NULL) {
        coord = GX_TEXCOORD0;
    }

    switch (stage) {
    case GX_INDTEXSTAGE0:
        GX_BP_SET_RAS1_IREF_MAP0(gxdt->ras1_iref, map);
        GX_BP_SET_RAS1_IREF_TXC0(gxdt->ras1_iref, coord);
        break;
    case GX_INDTEXSTAGE1:
        GX_BP_SET_RAS1_IREF_MAP1(gxdt->ras1_iref, map);
        GX_BP_SET_RAS1_IREF_TXC1(gxdt->ras1_iref, coord);
        break;
    case GX_INDTEXSTAGE2:
        GX_BP_SET_RAS1_IREF_MAP2(gxdt->ras1_iref, map);
        GX_BP_SET_RAS1_IREF_TXC2(gxdt->ras1_iref, coord);
        break;
    case GX_INDTEXSTAGE3:
        GX_BP_SET_RAS1_IREF_MAP3(gxdt->ras1_iref, map);
        GX_BP_SET_RAS1_IREF_TXC3(gxdt->ras1_iref, coord);
        break;
    }

    GX_BP_LOAD_REG(gxdt->ras1_iref);
    gxdt->gxDirtyFlags |= GX_DIRTY_SU_TEX;
    gxdt->gxDirtyFlags |= GX_DIRTY_BP_MASK;
    gxdt->lastWriteWasXF = FALSE;
}
