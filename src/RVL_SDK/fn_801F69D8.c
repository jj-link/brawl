#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

typedef struct {
    u32 command;
    u32 param1;
    u32 param2;
    u32 pad;
    u32 tick;
} CmdInfo;

typedef struct {
    u8 pad[0x1c];
    CmdInfo info[5];
} ErrorInfo;

extern ErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;

void fn_801F69D8(u32 arg0, u32 arg1, u32 arg2) {
    ErrorInfo *error;
    BOOL state;

    state = OSDisableInterrupts();
    if (lbl_805A0900 >= 5) {
        lbl_805A0900 = 0;
    }
    error = &lbl_804E4580;
    error->info[lbl_805A0900].command = arg0;
    error->info[lbl_805A0900].param1 = arg1;
    error->info[lbl_805A0900].param2 = arg2;
    error->info[lbl_805A0900].tick = OSGetTick();
    lbl_805A0900 = lbl_805A0900 + 1;
    OSRestoreInterrupts(state);
}
