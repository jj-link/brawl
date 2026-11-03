#include <revolution/OS/OSAlarm.h>
#pragma force_active on
extern OSAlarmQueue lbl_805A0678;
extern s64 fn_801E1B54(void);
extern s64 fn_803F1470(s64, s64);
extern void fn_801D5098(u32);
static void SetTimer(const OSAlarm* alarm) {
    s64 timeLeft = alarm->end - fn_801E1B54();
    if (timeLeft < 0) fn_801D5098(0);
    else if (timeLeft < 0x80000000) fn_801D5098(timeLeft);
    else fn_801D5098(0x7FFFFFFF);
}
void fn_801D66A8(OSAlarm* alarm, s64 end, OSAlarmHandler handler) {
    OSAlarm* iter;
    OSAlarm* prev;
    if (alarm->period > 0) {
        s64 time = fn_801E1B54();
        end = alarm->start;
        if (alarm->start < time) {
            s64 period = alarm->period;
            s64 periodLeft = fn_803F1470(time - alarm->start, period);
            end += period * (periodLeft + 1);
        }
    }
    alarm->handler = handler;
    alarm->end = end;
    for (iter = lbl_805A0678.head; iter != NULL; iter = iter->next) {
        if (iter->end <= end) continue;
        alarm->prev = iter->prev;
        iter->prev = alarm;
        alarm->next = iter;
        prev = alarm->prev;
        if (prev != NULL) prev->next = alarm;
        else {
            lbl_805A0678.head = alarm;
            SetTimer(alarm);
        }
        return;
    }
    alarm->next = NULL;
    prev = lbl_805A0678.tail;
    lbl_805A0678.tail = alarm;
    alarm->prev = prev;
    if (prev != NULL) prev->next = alarm;
    else {
        lbl_805A0678.tail = alarm;
        lbl_805A0678.head = alarm;
        SetTimer(alarm);
    }
}