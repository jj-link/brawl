#include <revolution/GX.h>
#pragma force_active on

void GXSetBlendMode(GXBlendMode mode, GXBlendFactor src, GXBlendFactor dst,
                    GXLogicOp op) {
    u32 blendModeReg = gxdt->blendMode;
    GX_BP_SET_BLENDMODE_SUBTRACT(blendModeReg, mode == GX_BM_SUBTRACT);
    GX_BP_SET_BLENDMODE_BLEND_ENABLE(blendModeReg, mode);
    GX_BP_SET_BLENDMODE_LOGIC_OP_ENABLE(blendModeReg, mode == GX_BM_LOGIC);
    GX_BP_SET_BLENDMODE_LOGIC_MODE(blendModeReg, op);
    GX_BP_SET_BLENDMODE_SRC_FACTOR(blendModeReg, src);
    GX_BP_SET_BLENDMODE_DST_FACTOR(blendModeReg, dst);

    GX_BP_LOAD_REG(blendModeReg);
    gxdt->blendMode = blendModeReg;

    gxdt->lastWriteWasXF = FALSE;
}
