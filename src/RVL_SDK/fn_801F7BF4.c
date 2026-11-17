#include <types.h>
#include <string.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvdidutils.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

extern char lbl_804DF740[];
extern DVDErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern int lbl_805A0918, lbl_805A0934, lbl_805A0984;
extern DVDDiskID *lbl_805A098C;
extern DVDCommandBlock *executing_805A0990;
extern void fn_801D76BC(void *, u32);
extern void fn_801FEA54(int);
extern void fn_801F7F2C(u32);
extern void fn_801F8830(u32);
extern int fn_803F6150(const void *, const void *, u32);
extern void fn_801FD7F8(void *, u32, u32, void (*)(u32));
extern void fn_801FD98C(int, int, void (*)(u32));

#define FN_STAMP(cmd, p1, p2) { \
    BOOL enabled = OSDisableInterrupts(); \
    if (lbl_805A0900 >= 5) { \
        lbl_805A0900 = 0; \
    } \
    lbl_804E4580.info[lbl_805A0900].command = (cmd); \
    lbl_804E4580.info[lbl_805A0900].param1 = (p1); \
    lbl_804E4580.info[lbl_805A0900].param2 = (p2); \
    lbl_804E4580.info[lbl_805A0900].tick = OSGetTick(); \
    lbl_805A0900++; \
    OSRestoreInterrupts(enabled); \
}

void fn_801F7BF4(void) {
    char *base = lbl_804DF740;
    switch (lbl_805A0984) {
    case 3:
        lbl_805A0934 = 0;
        if (DVDCompareDiskID((DVDDiskID *)(base + 0x4bc0), executing_805A0990->id)) {
            memcpy(lbl_805A098C, base + 0x4bc0, 0x20);
            executing_805A0990->state = 1;
            fn_801D76BC(base + 0x4b00, 0x20);
            lbl_805A0918 = 0;
            fn_801FEA54(0);
            FN_STAMP(0x21, 0x10000, 0x20);
            fn_801FD7F8(base + 0x4be0, 0x20, 0x10000, fn_801F7F2C);
        } else {
            FN_STAMP(0x10, 0, 0);
            fn_801FD98C(0, 0, fn_801F8830);
        }
        break;
    default:
        if (fn_803F6150(base + 0x4bc0, lbl_805A098C, 0x20)) {
            FN_STAMP(0x10, 0, 0);
            fn_801FD98C(0, 0, fn_801F8830);
        } else {
            lbl_805A0918 = 0;
            fn_801FEA54(0);
            FN_STAMP(0x21, 0x10000, 0x20);
            fn_801FD7F8(base + 0x4be0, 0x20, 0x10000, fn_801F7F2C);
        }
        break;
    }
}
