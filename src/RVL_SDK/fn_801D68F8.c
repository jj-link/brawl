#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern s64 fn_801E1B54(void);
extern void fn_801D66A8(OSAlarm*, s64, OSAlarmHandler);

void fn_801D68F8(OSAlarm* alarm, s64 tick, OSAlarmHandler handler) {
    BOOL enabled = OSDisableInterrupts();
    alarm->period = 0;
    fn_801D66A8(alarm, tick + fn_801E1B54(), handler);
    OSRestoreInterrupts(enabled);
}
