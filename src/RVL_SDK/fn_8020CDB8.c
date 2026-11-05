#include <revolution/OS/OS.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSReset.h>
#include <revolution/OS/OSError.h>
#include <string.h>
#pragma force_active on

extern int fn_8020CAEC(int);
extern int fn_80211080(void);
extern int fn_802110D4(void);
extern int fn_80211688(u64, char *);
extern int fn_80211720(u64 *);
extern int fn_80213B58(void);
extern char lbl_8047C0C0[];
extern char lbl_804ED040[];
extern const char *lbl_8059EB48;
extern int lbl_805A0BA8;

int fn_8020CDB8(void)
{
    char *base = lbl_8047C0C0;
    int initial;
    int result;
    u64 tid;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (lbl_805A0BA8 == 1) {
        OSRestoreInterrupts(enabled);
        return -3;
    }
    if (lbl_805A0BA8 == 2) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    lbl_805A0BA8 = 1;
    OSRestoreInterrupts(enabled);
    initial = fn_80213B58();
    if (initial == 0) {
        result = fn_80211080();
        if (result == 0) {
            result = fn_80211720(&tid);
        }
        if (result == 0) {
            result = fn_80211688(tid, lbl_804ED040);
        }
        if (result == 0) {
            strcpy(base + 0x60, lbl_804ED040);
        }
        fn_802110D4();
        if (result != 0) {
            OSReport(base + 0x130);
        }
        OSRegisterShutdownFunction((OSShutdownFunctionInfo *)(base + 0xA0));
        enabled = OSDisableInterrupts();
        lbl_805A0BA8 = 2;
        OSRestoreInterrupts(enabled);
        OSRegisterVersion(lbl_8059EB48);
        return 0;
    }
    enabled = OSDisableInterrupts();
    lbl_805A0BA8 = 0;
    OSRestoreInterrupts(enabled);
    return fn_8020CAEC(initial);
}
