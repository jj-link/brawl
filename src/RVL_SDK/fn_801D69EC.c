#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern OSAlarmQueue lbl_805A0678;
extern s64 fn_801E1B54(void);
extern void fn_801D5098(u32 val);

void OSCancelAlarm(OSAlarm* alarm) {
    OSAlarm* next;
    OSAlarm* prev;
    s64 timeLeft;
    BOOL enabled = OSDisableInterrupts();

    if (alarm->handler == NULL) {
        OSRestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == NULL) {
        lbl_805A0678.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }

    prev = alarm->prev;
    if (prev != NULL) {
        prev->next = next;
    } else {
        lbl_805A0678.head = next;
        if (next != NULL) {
            timeLeft = next->end - fn_801E1B54();
            if (timeLeft < 0) {
                fn_801D5098(0);
            } else if (timeLeft < 0x80000000) {
                fn_801D5098(timeLeft);
            } else {
                fn_801D5098(0x7FFFFFFF);
            }
        }
    }

    alarm->handler = NULL;
    OSRestoreInterrupts(enabled);
}
