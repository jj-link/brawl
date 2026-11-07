#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern char *lbl_805A0E98;
extern void fn_801D6E14(OSAlarm *, int);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);
extern void fn_8027B298(OSAlarm *, OSContext *);

void fn_8027B2C8(int arg0, int arg1) {
    OSAlarm *alarm;
    if (lbl_805A0E98 != 0) {
        switch (arg1) {
        case 0:
            *(lbl_805A0E98 + arg0 * 0x68 + 0x62) = 1;
            break;
        case -1:
            *(lbl_805A0E98 + arg0 * 0x68 + 0x62) = 0;
            break;
        case -2:
            alarm = (OSAlarm *)(lbl_805A0E98 + arg0 * 0x68);
            fn_801D6E14(alarm, arg0);
            OSCancelAlarm(alarm);
            fn_801D68F8(alarm, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 50, fn_8027B298);
            break;
        }
    }
}
