#include <types.h>
#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern s32 lbl_805A06D0;
extern s32 fn_801DD044(s32, s32);
extern s32 fn_801D6410(s32, void*);
extern void fn_801DD644(void);

static inline void update(s32 arg0, u8 *base) {
    s32 mask;
    s32 enabled;
    s32 previous;
    s32 user;
    s32 pending;

    enabled = OSDisableInterrupts();
    previous = *(s32 *)(base + 0xC4);
    user = *(s32 *)(base + 0xC8);
    pending = arg0 & ~(previous | user);
    arg0 |= previous;
    *(s32 *)(base + 0xC4) = arg0;
    mask = arg0 | user;
    while (pending != 0) {
        pending = fn_801DD044(pending, mask);
    }
    OSRestoreInterrupts(enabled);
}

void fn_801DCF80(void) {
    u8 *base = (u8 *)0x80000000;
    lbl_805A06D0 = (s32)(base + 0x3040);
    memset(base + 0x3040, 0, 0x80);
    *(s32 *)(base + 0xC4) = 0;
    *(s32 *)(base + 0xC8) = 0;
    *(s32 *)0xCC003004 = 0xF0;
    *(s32 *)0xCD000034 = 0x40000000;
    update(-0x10, base);
    fn_801D6410(4, (void *)fn_801DD644);
}