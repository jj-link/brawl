#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXLight.h>
#pragma force_active on

void fn_801F2494(GXChannelID chan, GXColor color) {
    u32 ambColor;
    u32 colorId;

    switch (chan) {
    case GX_COLOR0:
        ambColor =
            GX_BITSET_TRUNC(*(u32*)&gxdt->ambColors[0], 0, 24, *(u32*)&color);
        colorId = 0;
        break;
    case GX_COLOR1:
        ambColor =
            GX_BITSET_TRUNC(*(u32*)&gxdt->ambColors[1], 0, 24, *(u32*)&color);
        colorId = 1;
        break;
    case GX_ALPHA0:
        ambColor = GX_BITSET_TRUNC(*(u32*)&gxdt->ambColors[0], 24, 8, color.a);
        colorId = 0;
        break;
    case GX_ALPHA1:
        ambColor = GX_BITSET_TRUNC(*(u32*)&gxdt->ambColors[1], 24, 8, color.a);
        colorId = 1;
        break;
    case GX_COLOR0A0:
        ambColor = *(u32*)&color;
        colorId = 0;
        break;
    case GX_COLOR1A1:
        ambColor = *(u32*)&color;
        colorId = 1;
        break;
    default:
        return;
    }

    gxdt->gxDirtyFlags |= GX_DIRTY_AMB_COLOR0 << colorId;
    *(u32*)&gxdt->ambColors[colorId] = ambColor;
}