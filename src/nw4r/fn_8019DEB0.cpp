#include <types.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

inline void WriteXF2(u16 addr, u32 a, u32 b) {
    WGPIPE.uc = 0x10;
    WGPIPE.us = 1;
    WGPIPE.us = addr;
    WGPIPE.ui = a;
    WGPIPE.ui = b;
}

extern "C" void fn_8019DEB0(const u32 *p) {
    u32 a = (p[3] << 24) | ((p[2] << 18) | ((p[0] << 6) | (p[1] << 12)));
    u32 b = (p[7] << 18) | ((p[6] << 12) | (p[4] | (p[5] << 6)));
    WriteXF2(0x1018, a, b);
}
