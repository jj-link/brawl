#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSError.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern int fn_80211080(void);
extern void fn_802110D4(void);
extern int fn_802113E0(int, void *);
extern int fn_801E3E20(void *, int *, unsigned int *);
extern void fn_801D8690(const char *, int, const char *, ...);
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);
extern void fn_801E3D04(OSAlarm *, OSContext *);

extern char lbl_80474DDC[];
extern char lbl_80474DEC[];
extern char lbl_8059EA08[8];
extern OSAlarm lbl_804DE240;
extern int lbl_805A0754;
extern int lbl_805A0758;
extern unsigned long long lbl_805A0760;

void fn_801E3FE8(void)
{
    unsigned char buffer[0xD8] __attribute__((aligned(32)));
    unsigned int seconds;
    unsigned long long ticks;
    unsigned long long speed;
    unsigned long long one;
    unsigned long long sec64;
    int type;
    int result;

    lbl_805A0760 = 0;
    lbl_805A0758 = 0;
    lbl_805A0754 = 1;

    switch (fn_80211080()) {
    case 0:
        result = fn_802113E0(0, buffer);
        if (result == -1017) {
        } else {
            switch (result) {
            case 0:
                result = fn_801E3E20(buffer, &type, &seconds);
                break;
            default:
                break;
            }
        }

        if (result != 0) {
            switch (result) {
            case -1017:
                break;
            default:
                break;
            }
        } else {
            if (type != 0 && type == 1) {
                if (seconds == 0)
                    fn_801D8690(lbl_80474DDC, 0x307, lbl_8059EA08);

                OSCreateAlarm(&lbl_804DE240);
                sec64 = seconds;
                one = 1;
                sec64 = sec64 + one;
                speed = OS_TIME_SPEED;
                ticks = sec64 * speed;
                fn_801D68F8(&lbl_804DE240, ticks, fn_801E3D04);
                lbl_805A0760 = lbl_804DE240.end;
                OSReport(lbl_80474DEC, seconds);
            }
        }
        break;
    default:
        break;
    }

    fn_802110D4();
}
