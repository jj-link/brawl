#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on
#pragma peephole off

extern u8 lbl_805A08C0;
extern u8 lbl_805A08B8;
extern void fn_801F0E10(BOOL);
extern void fn_801D50A0(void);
extern void fn_801E1790(void *);

void fn_801F0A30(void) {
    BOOL level = OSDisableInterrupts();

    WGPIPE.uc = 0x61;
    WGPIPE.ui = 0x45000002;

    if (__GXData->gxDirtyFlags != 0) {
        fn_801F0E10(level);
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
    lbl_805A08C0 = 0;
    OSRestoreInterrupts(level);

    {
        BOOL level2 = OSDisableInterrupts();
        while (lbl_805A08C0 == 0) {
            fn_801E1790(&lbl_805A08B8);
        }
        OSRestoreInterrupts(level2);
    }
}