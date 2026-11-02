#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareCP.h>
#pragma force_active on

void fn_801EFEA8(void) {
    int i = 0;
    u32 flags = gxdt->vatDirtyFlags;

    do {
        if (flags & 1) {
            GX_CP_LOAD_REG(GX_CP_REG_VAT_GROUP0 | i, gxdt->vatA[i]);
            GX_CP_LOAD_REG(GX_CP_REG_VAT_GROUP1 | i, gxdt->vatB[i]);
            GX_CP_LOAD_REG(GX_CP_REG_VAT_GROUP2 | i, gxdt->vatC[i]);
        }

        i++;
        flags >>= 1;
    } while (flags != 0);

    WGPIPE.c = GX_FIFO_CMD_NOOP;
    gxdt->vatDirtyFlags = 0;
}
