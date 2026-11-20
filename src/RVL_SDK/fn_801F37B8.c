#include <revolution/GX.h>
#pragma force_active on

void fn_801F37B8(GXIndTexMtxID id, const f32 offset[2][3], s8 scaleExp) {
    u32 index;
    u32 cmd;

    switch (id) {
    case GX_ITM_0:
    case GX_ITM_1:
    case GX_ITM_2:
        index = id - GX_ITM_0;
        break;
    case GX_ITM_S0:
    case GX_ITM_S1:
    case GX_ITM_S2:
        index = id - GX_ITM_S0;
        break;
    case GX_ITM_T0:
    case GX_ITM_T1:
    case GX_ITM_T2:
        index = id - GX_ITM_T0;
        break;
    case 4:
    case 8:
    default:
        index = 0;
    }

    scaleExp += 17;

    cmd = 0;
    GX_BP_SET_INDMTXA_M00(cmd, 1024.0f * offset[0][0]);
    GX_BP_SET_INDMTXA_M10(cmd, 1024.0f * offset[1][0]);
    GX_BP_SET_INDMTXA_EXP(cmd, scaleExp);
    GX_BP_SET_OPCODE(cmd, index * 3 + GX_BP_REG_INDMTX0A);
    GX_BP_LOAD_REG(cmd);

    cmd = 0;
    GX_BP_SET_INDMTXB_M01(cmd, 1024.0f * offset[0][1]);
    GX_BP_SET_INDMTXB_M11(cmd, 1024.0f * offset[1][1]);
    cmd = __rlwimi(cmd, scaleExp, 20, 8, 9);
    GX_BP_SET_OPCODE(cmd, index * 3 + GX_BP_REG_INDMTX0B);
    GX_BP_LOAD_REG(cmd);

    cmd = 0;
    GX_BP_SET_INDMTXC_M02(cmd, 1024.0f * offset[0][2]);
    GX_BP_SET_INDMTXC_M12(cmd, 1024.0f * offset[1][2]);
    cmd = __rlwimi(cmd, scaleExp, 18, 8, 9);
    GX_BP_SET_OPCODE(cmd, index * 3 + GX_BP_REG_INDMTX0C);
    GX_BP_LOAD_REG(cmd);

    gxdt->lastWriteWasXF = FALSE;
}
