#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXTev.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern u32 lbl_80476508[];

void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color)
{
    u32 *order;
    u32 texmap;
    u32 val;
    u32 chan;
    u32 enable;

    order = (u32 *)__GXData + stage / 2;
    *(u32 *)((u8 *)__GXData + 0x5a4 + stage * 4) = map;
    texmap = map & ~0x100;
    texmap &= ~-(texmap >= 8);

    if ((s32)coord >= 8) {
        *(u32 *)((u8 *)__GXData + 0x5e8) &= ~(1 << stage);
        coord = 0;
    } else {
        *(u32 *)((u8 *)__GXData + 0x5e8) |= 1 << stage;
    }

    if (stage & 1) {
        val = GX_BITSET(order[0x54], 17, 3, texmap);
        val = GX_BITSET(val, 14, 3, coord);
        order[0x54] = val;
        chan = (color == 0xff) ? 7 : lbl_80476508[color];
        val = GX_BITSET(val, 10, 3, chan);
        order[0x54] = val;
        enable = 0;
        if (map != 0xff && !(map & 0x100)) {
            enable = 1;
        }
        val = GX_BITSET(val, 13, 1, enable);
        order[0x54] = val;
    } else {
        val = GX_BITSET(order[0x54], 29, 3, texmap);
        val = GX_BITSET(val, 26, 3, coord);
        order[0x54] = val;
        chan = (color == 0xff) ? 7 : lbl_80476508[color];
        val = GX_BITSET(val, 22, 3, chan);
        order[0x54] = val;
        enable = 0;
        if (map != 0xff && !(map & 0x100)) {
            enable = 1;
        }
        val = GX_BITSET(val, 25, 1, enable);
        order[0x54] = val;
    }

    {
        u8 *fifo = (u8 *)0xCC008000;
        *fifo++ = 0x61;
        *(u32 *)(fifo - 1) = order[0x54];
    }
    __GXData->lastWriteWasXF = 0;
    __GXData->gxDirtyFlags |= 1;
}
