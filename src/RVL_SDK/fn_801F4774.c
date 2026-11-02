#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void GXSetZMode(GXBool enableTest, GXCompare func, GXBool enableUpdate) {
    union {
        u32 word;
        struct {
            u32 pad: 27;
            u32 update: 1;
            u32 func: 3;
            u32 enable: 1;
        } bits;
    } z;
    z.word = gxdt->zMode;
    z.bits.enable = enableTest;
    z.bits.func = func;
    z.bits.update = enableUpdate;
    WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
    WGPIPE.i = z.word;
    gxdt->zMode = z.word;
    gxdt->lastWriteWasXF = FALSE;
}
