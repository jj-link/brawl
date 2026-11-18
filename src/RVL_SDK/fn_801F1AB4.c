#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F1AB4(GXColor c, u32 z) {
    u32 r0, r1, r2;
    u8* fifo;
    r0 = __rlwimi(0, c.r, 0, 24, 31);
    fifo = (u8*)0xCC008000;
    r0 = __rlwimi(r0, c.a, 8, 16, 23);
    r0 = __rlwimi(r0, 0x4F, 24, 0, 7);
    GX_BP_LOAD_REG(r0);
    r1 = __rlwimi(0, c.b, 0, 24, 31);
    r1 = __rlwimi(r1, c.g, 8, 16, 23);
    r1 = __rlwimi(r1, 0x50, 24, 0, 7);
    *fifo = 0x61;
    *(u32*)fifo = r1;
    r2 = __rlwimi(0, z, 0, 8, 31);
    r2 = __rlwimi(r2, 0x51, 24, 0, 7);
    *fifo = 0x61;
    *(u32*)fifo = r2;
    __GXData->lastWriteWasXF = 0;
}
