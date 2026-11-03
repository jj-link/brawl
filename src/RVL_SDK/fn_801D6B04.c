#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern OSAlarmQueue lbl_805A0678;
extern s64 fn_801E1B54(void);
extern void fn_801D5098(u32 val);
extern void fn_801D80B4(OSContext* ctx);
extern void fn_801D66A8(OSAlarm* alarm, s64 end, OSAlarmHandler handler);
extern void fn_801D81F4(OSContext* ctx);
extern void fn_801D7FCC(OSContext* ctx);
extern void fn_801E0760(void);
extern void fn_801E0CA8(void);

void fn_801D6B04(u8 type, OSContext* ctx) {
#pragma unused(type)

    OSAlarmHandler handler;
    OSContext tempCtx;
    OSAlarm* alarm;
    OSAlarm* next;
    OSAlarm* head;
    s64 timeLeft;
    s64 time;

    time = fn_801E1B54();
    alarm = lbl_805A0678.head;

    if (alarm == NULL) {
        fn_801D80B4(ctx);
    }

    if (time < alarm->end) {
        timeLeft = alarm->end - fn_801E1B54();
        if (timeLeft < 0) {
            fn_801D5098(0);
        } else if (timeLeft < 0x80000000) {
            fn_801D5098(timeLeft);
        } else {
            fn_801D5098(0x7FFFFFFF);
        }
        fn_801D80B4(ctx);
    }

    next = alarm->next;
    lbl_805A0678.head = next;
    if (next == NULL) {
        lbl_805A0678.tail = NULL;
    } else {
        next->prev = NULL;
    }

    handler = alarm->handler;
    alarm->handler = NULL;

    if (alarm->period > 0) {
        fn_801D66A8(alarm, 0, handler);
    }

    head = lbl_805A0678.head;
    if (head != NULL) {
        timeLeft = head->end - fn_801E1B54();
        if (timeLeft < 0) {
            fn_801D5098(0);
        } else if (timeLeft < 0x80000000) {
            fn_801D5098(timeLeft);
        } else {
            fn_801D5098(0x7FFFFFFF);
        }
    }

    fn_801E0760();
    fn_801D81F4(&tempCtx);
    fn_801D7FCC(&tempCtx);
    handler(alarm, ctx);
    fn_801D81F4(&tempCtx);
    fn_801D7FCC(ctx);
    OSEnableScheduler();

    fn_801E0CA8();
    fn_801D80B4(ctx);
}
