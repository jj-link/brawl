#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

typedef struct {
    u32 command;
    u32 param1;
    u32 param2;
    u32 intType;
    u32 tick;
} CmdInfo;

typedef struct {
    u8 pad[0x1c];
    CmdInfo info[5];
} ErrorInfo;

extern ErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern void fn_801F7008(void);
extern void fn_801F6FF4(void);
extern void fn_801FC1C0(u32, void (*)(void));
extern u32 fn_801FEA38(void);

void fn_801F78E0(u32 arg0) {
    BOOL enabled;

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
    if (arg0 & 2) {
        fn_801FC1C0(0x01234567, fn_801F6FF4);
        return;
    }
    fn_801FC1C0(fn_801FEA38(), fn_801F6FF4);
}