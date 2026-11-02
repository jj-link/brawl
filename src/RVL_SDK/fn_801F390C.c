#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareBP.h>
#pragma force_active on

void fn_801F390C(int stage, int scaleS, int scaleT)
{
    switch (stage) {
    case 0:
        GX_BP_SET_RAS1_SS0_S0(gxdt->ras1_ss0, scaleS);
        GX_BP_SET_RAS1_SS0_T0(gxdt->ras1_ss0, scaleT);
        GX_BP_SET_OPCODE(gxdt->ras1_ss0, GX_BP_REG_RAS1_SS0);
        GX_BP_LOAD_REG(gxdt->ras1_ss0);
        break;
    case 1:
        GX_BP_SET_RAS1_SS0_S1(gxdt->ras1_ss0, scaleS);
        GX_BP_SET_RAS1_SS0_T1(gxdt->ras1_ss0, scaleT);
        GX_BP_SET_OPCODE(gxdt->ras1_ss0, GX_BP_REG_RAS1_SS0);
        GX_BP_LOAD_REG(gxdt->ras1_ss0);
        break;
    case 2:
        GX_BP_SET_RAS1_SS1_S2(gxdt->ras1_ss1, scaleS);
        GX_BP_SET_RAS1_SS1_T2(gxdt->ras1_ss1, scaleT);
        GX_BP_SET_OPCODE(gxdt->ras1_ss1, GX_BP_REG_RAS1_SS1);
        GX_BP_LOAD_REG(gxdt->ras1_ss1);
        break;
    case 3:
        GX_BP_SET_RAS1_SS1_S3(gxdt->ras1_ss1, scaleS);
        GX_BP_SET_RAS1_SS1_T3(gxdt->ras1_ss1, scaleT);
        GX_BP_SET_OPCODE(gxdt->ras1_ss1, GX_BP_REG_RAS1_SS1);
        GX_BP_LOAD_REG(gxdt->ras1_ss1);
        break;
    }

    gxdt->lastWriteWasXF = FALSE;
}
