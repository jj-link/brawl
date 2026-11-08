#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern "C" void fn_8019DE54(void) {
    GX_CP_LOAD_REG(0x30, 0x3CF3CF00);
    GX_CP_LOAD_REG(0x40, 0x00F3CF3C);
    WGPIPE.c = 0x10;
    WGPIPE.us = 1;
    WGPIPE.us = 0x1018;
    WGPIPE.ui = 0x3CF3CF00;
    WGPIPE.ui = 0x00F3CF3C;
}