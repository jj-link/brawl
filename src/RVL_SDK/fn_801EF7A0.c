#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardwareCP.h>
#include <revolution/GX/GXTypes.h>
#include <types.h>
#pragma force_active on

extern u8 lbl_8059EA70[4];
extern u8 lbl_8059EA74[4];
extern u8 lbl_8059EA78[4];

void fn_801EF7A0(void) {
    u32 vlim;
    u32 vcdLo;
    u32 vcdHi;
    s32 compCnt;

    if (__GXData->SHORT_0x4 == 0) {
        return;
    }

    vcdLo = __GXData->vcdLoReg;
    vcdHi = __GXData->vcdHiReg;

    compCnt = __GXData->vatA[GX_VTXFMT0];
    compCnt = (compCnt & 0x200) >> 9;

    vlim = GX_CP_GET_VCD_LO_POSMATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX0MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX1MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX2MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX3MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX4MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX5MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX6MATIDX(vcdLo);
    vlim += GX_CP_GET_VCD_LO_TEX7MATIDX(vcdLo);

    vlim += lbl_8059EA78[GX_CP_GET_VCD_LO_POSITION(vcdLo)];
    vlim +=
        lbl_8059EA78[GX_CP_GET_VCD_LO_NORMAL(vcdLo)] * (compCnt == GX_NRM_NBT ? 3 : 1);
    vlim += lbl_8059EA70[GX_CP_GET_VCD_LO_COLORDIFFUSED(vcdLo)];
    vlim += lbl_8059EA70[GX_CP_GET_VCD_LO_COLORSPECULAR(vcdLo)];

    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX0COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX1COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX2COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX3COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX4COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX5COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX6COORD(vcdHi)];
    vlim += lbl_8059EA74[GX_CP_GET_VCD_HI_TEX7COORD(vcdHi)];

    __GXData->vlim = vlim;
}
