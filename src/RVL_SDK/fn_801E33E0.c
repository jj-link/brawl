#include <types.h>
#include <revolution/OS/OSError.h>

extern void fn_801D5300(void *);
extern s32 fn_803A5CB0(void);
extern s32 fn_803A072C(void);
extern s32 fn_803A2708(s32);
extern int lbl_805A0630;

#pragma force_active on
void fn_801E33E0(void)
{
    u8 state[8];
    s32 r1, r2, r3;

    fn_801D5300(state);
    if (state[1] <= 4 || state[1] == 9) {
        return;
    }
    r1 = fn_803A5CB0();
    if (r1 != 0) {
        if (r1 < 0) {
            OSReport("Failed to register network shutdown function. %d\n", r1);
        }
        r2 = fn_803A072C();
        if (r2 < 0) {
            OSReport("Failed to suspend the WiiConnect24 scheduler. %d\n", r2);
        }
    }
    if (lbl_805A0630 == 0) {
        r3 = fn_803A2708(0);
        if (r3 != 0) {
            OSReport("Failed to synchronize time with network resource managers. %d\n\0\0"
                     "NWC24iPrepareShutdown\0\0\0"
                     "/dev/net/kd/request\0"
                     "NWC24SuspendScheduler\0\0\0"
                     "NWC24ResumeScheduler\0\0\0\0"
                     "NWC24iRequestShutdown\0\0\0"
                     "NWC24Shutdown_: Give up!\n\0\0\0"
                     "NWC24iSetRtcCounter_\0\0\0\0"
                     "/dev/net/kd/time\0\0\0\0\0\0\0", r3);
        }
    }
}