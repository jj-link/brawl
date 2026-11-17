#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

extern DVDErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern void fn_801FC1C0(u32, void (*)(void));
extern void fn_801FD98C(int, int, void (*)(void));
extern void fn_801FDC88(void (*)(void));
extern void fn_801F7008(void);
extern void fn_801F78E0(void);
extern void fn_801F79B4(void);

void fn_801F7700(u32 arg0)
{
    BOOL enabled;
    DVDErrorInfo *error;

    enabled = OSDisableInterrupts();
    if (lbl_805A0900 == 0) {
        lbl_804E4580.info[DVD_ERROR_CMD_MAX - 1].intType = arg0;
    } else {
        lbl_804E4580.info[lbl_805A0900 - 1].intType = arg0;
    }
    OSRestoreInterrupts(enabled);
    if (arg0 == 0x10) {
        fn_801FC1C0(0x01234568, fn_801F7008);
        return;
    }
    if (arg0 == 0x20) {
        fn_801FC1C0(0x01234569, fn_801F7008);
        return;
    }
    if (arg0 & 1) {
        enabled = OSDisableInterrupts();
        if (lbl_805A0900 >= DVD_ERROR_CMD_MAX) {
            lbl_805A0900 = 0;
        }
        error = &lbl_804E4580;
        error->info[lbl_805A0900].command = 0x10;
        error->info[lbl_805A0900].param1 = 0;
        error->info[lbl_805A0900].param2 = 0;
        error->info[lbl_805A0900].tick = OSGetTick();
        lbl_805A0900 = lbl_805A0900 + 1;
        OSRestoreInterrupts(enabled);
        fn_801FD98C(0, 0, fn_801F79B4);
        return;
    }
    enabled = OSDisableInterrupts();
    if (lbl_805A0900 >= DVD_ERROR_CMD_MAX) {
        lbl_805A0900 = 0;
    }
    error = &lbl_804E4580;
    error->info[lbl_805A0900].command = 0x27;
    error->info[lbl_805A0900].param1 = 0;
    error->info[lbl_805A0900].param2 = 0;
    error->info[lbl_805A0900].tick = OSGetTick();
    lbl_805A0900 = lbl_805A0900 + 1;
    OSRestoreInterrupts(enabled);
    fn_801FDC88(fn_801F78E0);
}
