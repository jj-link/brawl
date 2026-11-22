#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#include <types.h>
#pragma force_active on

extern void fn_801E1790(OSThreadQueue *);
extern OSThreadQueue lbl_805A0828;
extern u32 lbl_805A084C;

#pragma optimization_level 1
void VIWaitForRetrace(void) {
    BOOL level;
    u32 before;

    level = OSDisableInterrupts();
    before = lbl_805A084C;
    do {
        fn_801E1790(&lbl_805A0828);
    } while (before == lbl_805A084C);
    OSRestoreInterrupts(level);
}
