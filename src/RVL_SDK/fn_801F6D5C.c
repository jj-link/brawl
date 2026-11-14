#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

typedef struct {
    u32 command; // at 0x0
    u32 param1;  // at 0x4
    u32 param2;  // at 0x8
    u32 intType; // at 0xC
    u32 tick;    // at 0x10
} CmdInfo;

typedef struct {
    u8 pad[0x1c];
    CmdInfo info[5];
} ErrorInfo;

extern ErrorInfo lbl_804E4580;
extern DVDCommandBlock DummyCommandBlock_804E4260;
extern DVDCommandBlock *executing_805A0990;
extern u32v lbl_805A0900;
extern u32 lbl_805A0918;

void fn_801F5ED8(void);
void fn_801F9688(void);
void fn_801F7008(void);
void fn_801F71FC(void);
void fn_801FC1C0(u32, void (*)(void));
void fn_801FDC88(void (*)(void));

void fn_801F6D5C(u32 arg0) {
    BOOL enabled;
    DVDCommandBlock *block;
    ErrorInfo *error;

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
        lbl_805A0918 = 0;
        fn_801F5ED8();
        block = executing_805A0990;
        executing_805A0990 = &DummyCommandBlock_804E4260;
        block->state = 0;
        if (block->callback != NULL) {
            block->callback(0, block);
        }
        fn_801F9688();
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
    fn_801FDC88(fn_801F71FC);
}
