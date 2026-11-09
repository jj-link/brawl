#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

extern void fn_801D50A0(void);
extern void fn_801F0E10(void);

void fn_801F08D8(u32 token) {
    BOOL level;
    u32 reg;

    level = OSDisableInterrupts();
    WGPIPE.uc = 0x61;
    reg = (u32)token | 0x48000000;
    WGPIPE.ui = reg;
    reg = __rlwimi(reg, token, 0, 16, 31);
    reg = __rlwimi(reg, 0x47, 24, 0, 7);
    WGPIPE.uc = 0x61;
    WGPIPE.ui = reg;

    if (__GXData->gxDirtyFlags != 0) {
        fn_801F0E10();
    }

    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;
    WGPIPE.ui = 0;

    fn_801D50A0();
    OSRestoreInterrupts(level);
    __GXData->lastWriteWasXF = 0;
}
