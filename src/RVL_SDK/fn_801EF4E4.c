#include <revolution/GX.h>
#pragma force_active on

static DECOMP_INLINE void SETVCDATTR(GXAttr name, GXAttrType type) {
    switch (name) {
    case GX_VA_PNMTXIDX:
        GX_CP_SET_VCD_LO_POSMATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX0MTXIDX:
        GX_CP_SET_VCD_LO_TEX0MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX1MTXIDX:
        GX_CP_SET_VCD_LO_TEX1MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX2MTXIDX:
        GX_CP_SET_VCD_LO_TEX2MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX3MTXIDX:
        GX_CP_SET_VCD_LO_TEX3MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX4MTXIDX:
        GX_CP_SET_VCD_LO_TEX4MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX5MTXIDX:
        GX_CP_SET_VCD_LO_TEX5MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX6MTXIDX:
        GX_CP_SET_VCD_LO_TEX6MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX7MTXIDX:
        GX_CP_SET_VCD_LO_TEX7MATIDX(gxdt->vcdLoReg, type);
        break;
    case GX_VA_POS:
        GX_CP_SET_VCD_LO_POSITION(gxdt->vcdLoReg, type);
        break;
    case GX_VA_NRM:
        if (type != GX_NONE) {
            gxdt->normal = TRUE;
            // GX_VA_NRM and GX_VA_NBT should not be enabled at the same time
            gxdt->binormal = FALSE;
            gxdt->normalType = type;
        } else {
            gxdt->normal = FALSE;
        }
        break;
    case GX_VA_NBT:
        if (type != GX_NONE) {
            gxdt->binormal = TRUE;
            // GX_VA_NRM and GX_VA_NBT should not be enabled at the same time
            gxdt->normal = FALSE;
            gxdt->normalType = type;
        } else {
            gxdt->binormal = FALSE;
        }
        break;
    case GX_VA_CLR0:
        GX_CP_SET_VCD_LO_COLORDIFFUSED(gxdt->vcdLoReg, type);
        break;
    case GX_VA_CLR1:
        GX_CP_SET_VCD_LO_COLORSPECULAR(gxdt->vcdLoReg, type);
        break;
    case GX_VA_TEX0:
        GX_CP_SET_VCD_HI_TEX0COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX1:
        GX_CP_SET_VCD_HI_TEX1COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX2:
        GX_CP_SET_VCD_HI_TEX2COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX3:
        GX_CP_SET_VCD_HI_TEX3COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX4:
        GX_CP_SET_VCD_HI_TEX4COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX5:
        GX_CP_SET_VCD_HI_TEX5COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX6:
        GX_CP_SET_VCD_HI_TEX6COORD(gxdt->vcdHiReg, type);
        break;
    case GX_VA_TEX7:
        GX_CP_SET_VCD_HI_TEX7COORD(gxdt->vcdHiReg, type);
        break;
    default:
        break;
    }
}

void fn_801EF4E4(const GXVtxDescList* list) {
    for (; list->attr != GX_VA_NULL; list++) {
        SETVCDATTR(list->attr, list->type);
    }

    if (gxdt->normal || gxdt->binormal) {
        GX_CP_SET_VCD_LO_NORMAL(gxdt->vcdLoReg, gxdt->normalType);
    } else {
        GX_CP_SET_VCD_LO_NORMAL(gxdt->vcdLoReg, GX_NONE);
    }

    gxdt->gxDirtyFlags |= GX_DIRTY_VCD;
}
