#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXLight.h>
#pragma force_active on

void fn_801F256C(GXChannelID chan, GXColor color) {
    u32 matColor;
    u32 colorId;

    switch (chan) {
    case GX_COLOR0:
        matColor = GX_BITSET_TRUNC(*(u32*)&gxdt->matColors[0], 0, 24, *(u32*)&color);
        colorId = 0;
        break;
    case GX_COLOR1:
        matColor = GX_BITSET_TRUNC(*(u32*)&gxdt->matColors[1], 0, 24, *(u32*)&color);
        colorId = 1;
        break;
    case GX_ALPHA0:
        matColor = GX_BITSET_TRUNC(*(u32*)&gxdt->matColors[0], 24, 8, color.a);
        colorId = 0;
        break;
    case GX_ALPHA1:
        matColor = GX_BITSET_TRUNC(*(u32*)&gxdt->matColors[1], 24, 8, color.a);
        colorId = 1;
        break;
    case GX_COLOR0A0:
        matColor = *(u32*)&color;
        colorId = 0;
        break;
    case GX_COLOR1A1:
        matColor = *(u32*)&color;
        colorId = 1;
        break;
    default:
        return;
    }

    gxdt->gxDirtyFlags |= GX_DIRTY_MAT_COLOR0 << colorId;
    *(u32*)&gxdt->matColors[colorId] = matColor;
}