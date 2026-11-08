#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#include <types.h>
#pragma force_active on
extern char lbl_804FB4A0[];
extern u8 lbl_805A0CF8;
extern void fn_8022A944(OSAlarm*, OSContext*);
static inline void start(char *p, s8 a, s8 b, u8 c, s32 d) {
    s32 intr = OSDisableInterrupts();
    lbl_805A0CF8 = c;
    p[0xC] = 1;
    p[0x6E8] = b;
    p[0x6E9] = a;
    p[0x6E7] = d != 0;
    p[0x6E6] = 0;
    *(u16 *)(p + 0x748) = 50;
    *(u16 *)(p + 0x74A) = 200;
    OSCreateAlarm((OSAlarm *)(p + 0x710));
    OSSetPeriodicAlarm((OSAlarm *)(p + 0x710), OSGetTime(), (u64)((*(u32 *)0x800000F8 / 4 / 1000) * 20), fn_8022A944);
    OSRestoreInterrupts(intr);
}
s32 fn_8022BC78(s8 arg0, s8 arg1, u8 arg2, s32 arg3) {
    char *p = lbl_804FB4A0;
    s32 result = 0;
    s32 intr;
    s32 state;
    s32 allowed;
    intr = OSDisableInterrupts();
    state = (s8)p[0x708];
    OSRestoreInterrupts(intr);
    if ((u32)state == 3) {
        intr = OSDisableInterrupts();
        if ((u8)p[0x0C] == 0 && (u8)p[0x0D] == 0 && (u8)p[0x0F] == 4 && (u8)p[0x10] == 5) {
            OSRestoreInterrupts(intr);
            allowed = 0;
        } else {
            OSRestoreInterrupts(intr);
            allowed = 1;
        }
        if (allowed == 0) {
            start(p, arg0, arg1, arg2, arg3);
            result = 1;
        }
    }
    return result;
}