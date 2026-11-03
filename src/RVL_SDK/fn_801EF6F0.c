#include <revolution/GX.h>
#pragma force_active on

static void __GXXfVtxSpecs(void) {
    unsigned int cmd;
    u32 nrm;
    u32 clr;
    u32 txc;

    nrm = gxdt->binormal ? 2 : (gxdt->normal ? 1 : 0);
    clr = 32 - __cntlzw(GX_BITGET(gxdt->vcdLoReg, GX_CP_VCD_LO_COLORSPECULAR_B,
                                 GX_CP_VCD_LO_COLORSPECULAR_SZ + GX_CP_VCD_LO_COLORDIFFUSED_SZ)) + 1;
    txc = 32 - __cntlzw(GX_BITGET(gxdt->vcdHiReg, GX_CP_VCD_HI_TEX7COORD_B,
                                  GX_CP_VCD_HI_TEX7COORD_SZ * 8)) + 1;

    GX_XF_LOAD_REG_HDR(GX_XF_REG_INVERTEXSPEC);
    cmd = 0;
    cmd = cmd | clr >> 1;
    cmd = (txc << 3) & ~0xF | cmd;
    WGPIPE.i = cmd | nrm << 2;
    gxdt->lastWriteWasXF = TRUE;
}

void fn_801EF6F0(void) {
    GX_CP_LOAD_REG(GX_CP_REG_VCD_LO, gxdt->vcdLoReg);
    GX_CP_LOAD_REG(GX_CP_REG_VCD_HI, gxdt->vcdHiReg);
    __GXXfVtxSpecs();
}