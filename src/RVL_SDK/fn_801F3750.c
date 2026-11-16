#include <types.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXInit.h>

#pragma force_active on

void fn_801F3750(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u8 a8, u32 a9) {
    u32 reg;

    reg = __rlwimi(0, a1, 0, 30, 31);
    reg = __rlwimi(reg, a2, 2, 28, 29);
    WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
    reg = __rlwimi(reg, a3, 4, 25, 27);
    reg = __rlwimi(reg, a9, 7, 23, 24);
    reg = __rlwimi(reg, a4, 9, 19, 22);
    reg = __rlwimi(reg, a5, 13, 16, 18);
    reg = __rlwimi(reg, a6, 16, 13, 15);
    reg = __rlwimi(reg, a8, 19, 12, 12);
    reg = __rlwimi(reg, a7, 20, 11, 11);
    reg = __rlwimi(reg, a0 + 0x10, 24, 0, 7);
    WGPIPE.i = reg;
    __GXData->lastWriteWasXF = 0;
}