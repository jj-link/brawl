#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F0208(int attr, const void* base, u32 stride) {
    int index;

    if (attr == 25) {
        attr = 10;
    }
    index = attr - 9;
    WGPIPE.uc = 8;
    WGPIPE.uc = index | 0xA0;
    WGPIPE.ui = (u32)base & 0x3FFFFFFF;
    WGPIPE.uc = 8;
    WGPIPE.uc = index | 0xB0;
    WGPIPE.ui = stride;
}
