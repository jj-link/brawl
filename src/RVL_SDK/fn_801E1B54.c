#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

s64 fn_801E1B54(void) {
    BOOL enabled = OSDisableInterrupts();
    s64 time = OSGetTime() + *(s64 *)0x800030D8;
    OSRestoreInterrupts(enabled);
    return time;
}
