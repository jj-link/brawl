#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

typedef struct {
    u32 command; // at 0x0
    u32 param1;  // at 0x4
    u32 param2;  // at 0x8
    u32 pad;     // at 0xC
    u32 tick;    // at 0x10
} CmdInfo;

typedef struct {
    u8 pad[0x1c];
    CmdInfo info[5];
} ErrorInfo;

extern ErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern void fn_801F79B4(void);
extern void fn_801FD98C(int, int, void (*)(void));

void fn_801F7138(void) {
    ErrorInfo *error;
    BOOL state;

    state = OSDisableInterrupts();
    if (lbl_805A0900 >= 5) {
        lbl_805A0900 = 0;
    }
    error = &lbl_804E4580;
    error->info[lbl_805A0900].command = 0x10;
    error->info[lbl_805A0900].param1 = 0;
    error->info[lbl_805A0900].param2 = 0;
    error->info[lbl_805A0900].tick = OSGetTick();
    lbl_805A0900 = lbl_805A0900 + 1;
    OSRestoreInterrupts(state);
    fn_801FD98C(0, 0, fn_801F79B4);
}
