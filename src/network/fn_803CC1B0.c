#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSError.h>
#include <string.h>
#pragma force_active on

extern int fn_80211AE8(void);
extern int fn_80211AE0(void);
extern void fn_80211AF0(unsigned int);
extern int fn_80213468(int, int);
extern void *fn_8021379C(int, int);
extern char lbl_804927E0[];
extern OSMutex lbl_80563940;
extern char lbl_80563960[];
extern int lbl_8059FE98;
extern int lbl_805A1234;
extern void *lbl_805A1238, *lbl_805A123C, *lbl_805A1240, *lbl_805A1244, *lbl_805A1248;
extern int lbl_805A124C;

int fn_803CC1B0(void)
{
    char *base = lbl_804927E0;
    int result = 0;
    BOOL enabled = OSDisableInterrupts();
    if (lbl_8059FE98 >= 0) {
        OSRestoreInterrupts(enabled);
        goto done;
    }
    OSRestoreInterrupts(enabled);
    lbl_805A1234 = 0;
    OSInitMutex(&lbl_80563940);
    lbl_805A124C = fn_80211AE8();
    fn_80211AE0();
    lbl_8059FE98 = fn_80213468(lbl_805A124C, 0x800);
    if (lbl_8059FE98 < 0) {
        result = -22;
        goto done;
    }
    lbl_805A1238 = fn_8021379C(lbl_8059FE98, 0x20);
    if (!lbl_805A1238) {
        OSReport(base + 0x4f8);
        result = -22;
        goto done;
    }
    lbl_805A123C = fn_8021379C(lbl_8059FE98, 0x20);
    if (!lbl_805A123C) {
        OSReport(base + 0x510);
        result = -22;
        goto done;
    }
    lbl_805A1240 = fn_8021379C(lbl_8059FE98, 0x20);
    if (!lbl_805A1240) {
        OSReport(base + 0x528);
        result = -22;
        goto done;
    }
    lbl_805A1244 = fn_8021379C(lbl_8059FE98, 0x20);
    if (!lbl_805A1244) {
        OSReport(base + 0x540);
        result = -22;
        goto done;
    }
    lbl_805A1248 = fn_8021379C(lbl_8059FE98, 0x60);
    if (!lbl_805A1248) {
        OSReport(base + 0x558);
        result = -22;
        goto done;
    }
    fn_80211AF0(lbl_805A124C + 0x800);
    strcpy(lbl_80563960, base + 0x570);
    strcpy(lbl_80563960 + 0x20, base + 0x580);
    strcpy(lbl_80563960 + 0x40, base + 0x590);
done:
    return result;
}