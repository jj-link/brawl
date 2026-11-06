#pragma global_optimizer off
#include <revolution/OS/OSError.h>
#include <string.h>
#pragma force_active on
extern int fn_80211F28(void);
extern unsigned int fn_80211AE8(void);
extern unsigned int fn_80211AE0(void);
extern void fn_80211AF0(unsigned int);
extern int fn_802123A8(char *, int);
extern char lbl_80477190[];
extern unsigned char lbl_805A09C5, lbl_805A09C4;
extern char *lbl_805A09D0;
extern unsigned int lbl_805A09D4;
extern int lbl_805A09C0, lbl_8059EAF8;
extern char lbl_8059EB00[8];
typedef struct { int a, b; unsigned char c; unsigned int magic, id; char pad[12]; } Context;
extern Context lbl_804E46A0[4];

int fn_801FC938(void) {
    int result, ok;
    char *base = lbl_80477190;
    unsigned int lo, hi;
    if (!lbl_805A09C5) {
        lbl_805A09C5 = 1;
        result = fn_80211F28();
        if (result != 0) {
            OSReport(base + 0x88, result);
            return 0;
        }
        lo = fn_80211AE8();
        hi = fn_80211AE0();
        if (lo & 31) lo = (lo + 31) & 31;
        if (lo + 0x80 > hi) OSReport(base + 0xa8, 0x80);
        fn_80211AF0(lo + 0x80);
        lbl_805A09D4 = lo;
        if (!lo) {
            OSReport(base + 0xe4);
            ok = 0;
        } else {
            lo = fn_80211AE8();
            hi = fn_80211AE0();
            if (lo & 31) lo = (lo + 31) & 31;
            if (lo + 0x20 > hi) OSReport(base + 0xa8, 0x20);
            fn_80211AF0(lo + 0x20);
            lbl_805A09D0 = (char *)lo;
            if (!lo) {
                OSReport(base + 0x10c);
                ok = 0;
            } else ok = 1;
        }
        if (!ok) return 0;
        if (!lbl_805A09C4) {
            int i;
            for (i = 0; i < 4; i++) {
                lbl_804E46A0[i].a = 0;
                lbl_804E46A0[i].b = 0;
                lbl_804E46A0[i].c = 0;
                lbl_804E46A0[i].magic = 0xFEEBDAED;
                lbl_804E46A0[i].id = i;
            }
            lbl_805A09C0 = 0;
            lbl_805A09C4 = 1;
        }
    }
    strncpy(lbl_805A09D0, lbl_8059EB00, 32);
    result = fn_802123A8(lbl_805A09D0, 0);
    lbl_8059EAF8 = result;
    if (result >= 0) return 1;
    switch (result) {
    case -6: OSReport(base + 0x12c); return 0;
    case -1: OSReport(base + 0x178); return 0;
    case -5: OSReport(base + 0x1c0); return 0;
    default: OSReport(base + 0x20c, result); return 0;
    }
}