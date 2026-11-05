#include <revolution/GX/GXInit.h>
#pragma force_active on

extern void fn_801F2830(GXTexFmt, u16, u16, u32 *, u32 *, u32 *);

#define COPY_CONTROL (*(u32 *)((u8 *)__GXData + 0x24C))
#define COPY_STRIDE (*(u32 *)((u8 *)__GXData + 0x248))
#define COPY_DEPTH (*(u8 *)((u8 *)__GXData + 0x250))

void fn_801F15C8(u16 width, u16 height, GXTexFmt format, GXBool mipmap)
{
    u32 xTiles;
    u32 yTiles;
    u32 tileCount;
    u32 fmt = format & 0xF;

    COPY_DEPTH = 0;
    if (format == 0x13) {
        fmt = 0xB;
    }

    switch (format) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0x26:
        COPY_CONTROL = __rlwimi(COPY_CONTROL, 3, 15, 15, 16);
        break;
    default:
        COPY_CONTROL = __rlwimi(COPY_CONTROL, 2, 15, 15, 16);
        break;
    }

    COPY_DEPTH = ((u32)format >> 4) & 1;
    COPY_CONTROL = __rlwimi(COPY_CONTROL, fmt, 0, 28, 28);
    fn_801F2830(format, width, height, &xTiles, &yTiles, &tileCount);
    COPY_STRIDE = 0;
    COPY_STRIDE = __rlwimi(COPY_STRIDE, xTiles * tileCount, 0, 22, 31);
    COPY_STRIDE = __rlwimi(COPY_STRIDE, 0x4D, 24, 0, 7);
    COPY_CONTROL = __rlwimi(COPY_CONTROL, mipmap, 9, 22, 22);
    COPY_CONTROL = __rlwimi(COPY_CONTROL, fmt, 4, 25, 27);
}
