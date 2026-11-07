#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardwareCP.h>
#include <revolution/GX/GXAttr.h>
#pragma force_active on

void fn_801EFB44(GXVtxFmt fmt, GXAttr attr, GXCompCnt compCnt,
                 GXCompType compType, u8 shift) {
    u32* vatA;
    u32* vatB;
    u32* vatC;

    vatA = &gxdt->vatA[fmt];
    vatB = &gxdt->vatB[fmt];
    vatC = &gxdt->vatC[fmt];

    switch (attr) {
    case GX_VA_POS:
        GX_CP_SET_VAT_GROUP0_POS_CNT(*vatA, compCnt);
        GX_CP_SET_VAT_GROUP0_POS_TYPE(*vatA, compType);
        GX_CP_SET_VAT_GROUP0_POS_SHIFT(*vatA, shift);
        break;
    case GX_VA_NRM:
    case GX_VA_NBT:
        GX_CP_SET_VAT_GROUP0_NRM_TYPE(*vatA, compType);
        if (compCnt == GX_NRM_NBT3) {
            // Probably because the compCnt can only be one bit?
            GX_CP_SET_VAT_GROUP0_NRM_CNT(*vatA, GX_NRM_NBT);
            GX_CP_SET_VAT_GROUP0_NORMALINDEX3(*vatA, TRUE);
        } else {
            GX_CP_SET_VAT_GROUP0_NRM_CNT(*vatA, compCnt);
            GX_CP_SET_VAT_GROUP0_NORMALINDEX3(*vatA, FALSE);
        }
        break;
    case GX_VA_CLR0:
        GX_CP_SET_VAT_GROUP0_COLORDIFF_CNT(*vatA, compCnt);
        GX_CP_SET_VAT_GROUP0_COLORDIFF_TYPE(*vatA, compType);
        break;
    case GX_VA_CLR1:
        GX_CP_SET_VAT_GROUP0_COLORSPEC_CNT(*vatA, compCnt);
        GX_CP_SET_VAT_GROUP0_COLORSPEC_TYPE(*vatA, compType);
        break;
    case GX_VA_TEX0:
        GX_CP_SET_VAT_GROUP0_TXC0_CNT(*vatA, compCnt);
        GX_CP_SET_VAT_GROUP0_TXC0_TYPE(*vatA, compType);
        GX_CP_SET_VAT_GROUP0_TXC0_SHIFT(*vatA, shift);
        break;
    case GX_VA_TEX1:
        GX_CP_SET_VAT_GROUP1_TXC1_CNT(*vatB, compCnt);
        GX_CP_SET_VAT_GROUP1_TXC1_TYPE(*vatB, compType);
        GX_CP_SET_VAT_GROUP1_TXC1_SHIFT(*vatB, shift);
        break;
    case GX_VA_TEX2:
        GX_CP_SET_VAT_GROUP1_TXC2_CNT(*vatB, compCnt);
        GX_CP_SET_VAT_GROUP1_TXC2_TYPE(*vatB, compType);
        GX_CP_SET_VAT_GROUP1_TXC2_SHIFT(*vatB, shift);
        break;
    case GX_VA_TEX3:
        GX_CP_SET_VAT_GROUP1_TXC3_CNT(*vatB, compCnt);
        GX_CP_SET_VAT_GROUP1_TXC3_TYPE(*vatB, compType);
        GX_CP_SET_VAT_GROUP1_TXC3_SHIFT(*vatB, shift);
        break;
    case GX_VA_TEX4:
        GX_CP_SET_VAT_GROUP1_TXC4_CNT(*vatB, compCnt);
        GX_CP_SET_VAT_GROUP1_TXC4_TYPE(*vatB, compType);
        GX_CP_SET_VAT_GROUP2_TXC4_SHIFT(*vatC, shift);
        break;
    case GX_VA_TEX5:
        GX_CP_SET_VAT_GROUP2_TXC5_CNT(*vatC, compCnt);
        GX_CP_SET_VAT_GROUP2_TXC5_TYPE(*vatC, compType);
        GX_CP_SET_VAT_GROUP2_TXC5_SHIFT(*vatC, shift);
        break;
    case GX_VA_TEX6:
        GX_CP_SET_VAT_GROUP2_TXC6_CNT(*vatC, compCnt);
        GX_CP_SET_VAT_GROUP2_TXC6_TYPE(*vatC, compType);
        GX_CP_SET_VAT_GROUP2_TXC6_SHIFT(*vatC, shift);
        break;
    case GX_VA_TEX7:
        GX_CP_SET_VAT_GROUP2_TXC7_CNT(*vatC, compCnt);
        GX_CP_SET_VAT_GROUP2_TXC7_TYPE(*vatC, compType);
        GX_CP_SET_VAT_GROUP2_TXC7_SHIFT(*vatC, shift);
        break;
    }

    gxdt->gxDirtyFlags |= GX_DIRTY_VAT;
    gxdt->vatDirtyFlags |= (u8)(1 << (u8)fmt);
}
