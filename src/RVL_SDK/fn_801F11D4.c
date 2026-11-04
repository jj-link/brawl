#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F11D4(void) {
    u32 i;
    u32 size = __GXData->SHORT_0x4 * __GXData->vlim;
    WGPIPE.uc = 0x98;
    WGPIPE.us = __GXData->SHORT_0x4;
    for (i = 0; i < size; i += 4) {
        WGPIPE.ui = 0;
    }
    __GXData->lastWriteWasXF = 1;
}
