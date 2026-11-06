#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern void fn_801E187C(OSThreadQueue *);

int fn_801E039C(int *arg0) {
    BOOL level = OSDisableInterrupts();
    int count = *arg0;
    *arg0 = count + 1;
    fn_801E187C((OSThreadQueue *)(arg0 + 1));
    OSRestoreInterrupts(level);
    return count;
}
