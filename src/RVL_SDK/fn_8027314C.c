#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern void *lbl_805A0E80;
extern u32 fn_801D6E1C(void);
extern int fn_8021AE80(u32);
extern int fn_8027AB94(void *);
extern void fn_801D6E14(void *, u32, void *);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);
extern void fn_8027A858(void *, void *, u32);
void fn_8027314C(OSAlarm *arg, OSContext *ctx) {
    void *base;
    void *alarm;
    u32 high;
    u32 low;
    u32 data;
    data = fn_801D6E1C();
    high = data >> 16;
    base = lbl_805A0E80;
    low = data & 0xFFFF;
    if (fn_8021AE80(high) == 0 ||
        fn_8027AB94(*(void **)((char *)base + high * 4 + 0x25C)) == 0) {
        base = (char *)base + high * 0x30;
        alarm = (char *)base + 0x4D8;
        fn_801D6E14(alarm, (high << 16) | (high + 2), base);
        OSCancelAlarm(alarm);
        fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 50, fn_8027314C);
    } else {
        fn_8027A858(*(void **)((char *)base + high * 4 + 0x25C),
                    *(void **)((char *)base + 0x5D0), low);
    }
}
