#include <revolution/types.h>
#include <revolution/NHTTP/d_nhttp.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern void fn_80335638(int, const char *, ...);
extern void fn_803962D4(void *);
extern int fn_803967D0(int);
extern void fn_803540BC(void);
extern char lbl_8048D580[];
extern void *lbl_805A0FD4;
extern int lbl_805A0FD8;
extern int lbl_80534030[];

void fn_803522DC(void) {
    if (lbl_805A0FD8 == 0x14) {
        fn_803967D0(*(int *)((char *)lbl_805A0FD4 + 0x59e0));
        for (;;) {
            if (lbl_80534030[0] != 0) {
                break;
            }
            OSSleepTicks((s64)((*(u32 *)0x800000F8 / 4) / 1000));
        }
    }
    if (lbl_80534030[0x1c8 / 4] != 0) {
        fn_80335638(0x01000000, lbl_8048D580);
        NHTTPDestroyResponse((NHTTPResponseHandle)lbl_80534030[0x1c8 / 4]);
        lbl_80534030[0x1c8 / 4] = 0;
    }
    if (lbl_805A0FD8 != 0 && lbl_805A0FD8 != 0x18 && lbl_805A0FD8 != 0x19 && lbl_805A0FD8 != 0x1a) {
        lbl_805A0FD8 = 0x18;
        fn_803962D4((void *)fn_803540BC);
        for (;;) {
            if (lbl_805A0FD8 == 0x19) {
                break;
            }
            OSSleepTicks((s64)((*(u32 *)0x800000F8 / 4) / 1000));
        }
    }
    lbl_805A0FD8 = 0x1a;
    lbl_80534030[0] = -0x4e84;
}
