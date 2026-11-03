#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern char *lbl_805A0E98;
extern void fn_8027B2C8(void);
extern void fn_8027B1A4(OSAlarm *, OSContext *);
extern void fn_8021AEC4(int, int, void (*)(void));
extern void fn_801D6E14(OSAlarm *, int);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);

void fn_8027B1D4(int arg0, int arg1) {
    OSAlarm *alarm;
    if (lbl_805A0E98 != 0) {
        switch (arg1) {
        case 0:
            *(lbl_805A0E98 + arg0 * 0x68 + 0x5c) = 1;
            fn_8021AEC4(arg0, 4, fn_8027B2C8);
            break;
        case -2:
            alarm = (OSAlarm *)(lbl_805A0E98 + arg0 * 0x68);
            fn_801D6E14(alarm, arg0);
            OSCancelAlarm(alarm);
            fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 50, fn_8027B1A4);
            break;
        }
    }
}