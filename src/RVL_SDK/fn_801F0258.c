#include <revolution/GX.h>
#pragma force_active on

void GXSetTexCoordGen2(GXTexCoordID id, GXTexGenType type, GXTexGenSrc src,
                       u32 texMtxIdx, GXBool normalize, u32 dualTexMtxIdx) {
    u32 reg;
    u32 inputRow;
    GXXfTexForm inputForm;

    reg = 0;
    inputForm = GX_XF_TEX_FORM_AB11;
    inputRow = 5;

    switch (src) {
    case GX_TG_POS:
        inputRow = 0;
        inputForm = GX_XF_TEX_FORM_ABC1;
        break;
    case GX_TG_NRM:
        inputRow = 1;
        inputForm = GX_XF_TEX_FORM_ABC1;
        break;
    case GX_TG_BINRM:
        inputRow = 3;
        inputForm = GX_XF_TEX_FORM_ABC1;
        break;
    case GX_TG_TANGENT:
        inputRow = 4;
        inputForm = GX_XF_TEX_FORM_ABC1;
        break;
    case GX_TG_COLOR0:
        inputRow = 2;
        break;
    case GX_TG_COLOR1:
        inputRow = 2;
        break;
    case GX_TG_TEX0:
        inputRow = 5;
        break;
    case GX_TG_TEX1:
        inputRow = 6;
        break;
    case GX_TG_TEX2:
        inputRow = 7;
        break;
    case GX_TG_TEX3:
        inputRow = 8;
        break;
    case GX_TG_TEX4:
        inputRow = 9;
        break;
    case GX_TG_TEX5:
        inputRow = 10;
        break;
    case GX_TG_TEX6:
        inputRow = 11;
        break;
    case GX_TG_TEX7:
        inputRow = 12;
        break;
    default:
        break;
    }

    switch (type) {
    case GX_TG_MTX2x4:
        reg = 0;
        GX_XF_SET_TEX_PROJTYPE(reg, GX_XF_TEX_PROJ_ST);
        GX_XF_SET_TEX_INPUTFORM(reg, inputForm);
        GX_XF_SET_TEX_SRCROW(reg, inputRow);
        break;
    case GX_TG_MTX3x4:
        reg = 0;
        GX_XF_SET_TEX_PROJTYPE(reg, GX_XF_TEX_PROJ_STQ);
        GX_XF_SET_TEX_INPUTFORM(reg, inputForm);
        GX_XF_SET_TEX_SRCROW(reg, inputRow);
        break;
    case GX_TG_BUMP0:
    case GX_TG_BUMP1:
    case GX_TG_BUMP2:
    case GX_TG_BUMP3:
    case GX_TG_BUMP4:
    case GX_TG_BUMP5:
    case GX_TG_BUMP6:
    case GX_TG_BUMP7:
        reg = 0;
        GX_XF_SET_TEX_INPUTFORM(reg, inputForm);
        GX_XF_SET_TEX_TEXGENTYPE(reg, GX_XF_TG_BUMP);
        GX_XF_SET_TEX_SRCROW(reg, inputRow);
        GX_XF_SET_TEX_BUMPSRCTEX(reg, src - GX_TG_TEXCOORD0);
        GX_XF_SET_TEX_BUMPSRCLIGHT(reg, type - GX_TG_BUMP0);
        break;
    case GX_TG_SRTG:
        reg = 0;
        GX_XF_SET_TEX_INPUTFORM(reg, inputForm);
        if (src == GX_TG_COLOR0) {
            GX_XF_SET_TEX_TEXGENTYPE(reg, GX_XF_TG_CLR0);
        } else {
            GX_XF_SET_TEX_TEXGENTYPE(reg, GX_XF_TG_CLR1);
        }
        GX_XF_SET_TEX_SRCROW(reg, 2);
        break;
    default:
        break;
    }

    gxdt->texRegs[id] = reg;
    gxdt->gxDirtyFlags |= GX_DIRTY_TEX0 << id;

    reg = 0;
    GX_XF_SET_DUALTEX_BASEROW(reg, dualTexMtxIdx - GX_DUALMTX0);
    GX_XF_SET_DUALTEX_NORMALIZE(reg, normalize);
    gxdt->dualTexRegs[id] = reg;

    switch (id) {
    case GX_TEXCOORD0:
        GX_XF_SET_MATRIXINDEX0_TEX0(gxdt->matrixIndex0, texMtxIdx);
        break;
    case GX_TEXCOORD1:
        GX_XF_SET_MATRIXINDEX0_TEX1(gxdt->matrixIndex0, texMtxIdx);
        break;
    case GX_TEXCOORD2:
        GX_XF_SET_MATRIXINDEX0_TEX2(gxdt->matrixIndex0, texMtxIdx);
        break;
    case GX_TEXCOORD3:
        GX_XF_SET_MATRIXINDEX0_TEX3(gxdt->matrixIndex0, texMtxIdx);
        break;
    case GX_TEXCOORD4:
        GX_XF_SET_MATRIXINDEX1_TEX4(gxdt->matrixIndex1, texMtxIdx);
        break;
    case GX_TEXCOORD5:
        GX_XF_SET_MATRIXINDEX1_TEX5(gxdt->matrixIndex1, texMtxIdx);
        break;
    case GX_TEXCOORD6:
        GX_XF_SET_MATRIXINDEX1_TEX6(gxdt->matrixIndex1, texMtxIdx);
        break;
    default:
        GX_XF_SET_MATRIXINDEX1_TEX7(gxdt->matrixIndex1, texMtxIdx);
        break;
    }

    gxdt->gxDirtyFlags |= GX_DIRTY_MTX_IDX;
}
