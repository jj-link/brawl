#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_8022E928(const char*, ...);
extern int fn_8023A5C0(u8, u8);
extern char lbl_804FB4A0[];
extern char lbl_8047EE00[];
extern char lbl_8047EE18[];

s32 fn_8022BEEC(s8 arg0) {
    s32 result = 0;
    char* base = lbl_804FB4A0;
    s8 ch = arg0;
    s32 n0;
    s32 n1;
    s32 x;
    s32 state;
    s32 tmp;
    BOOL enabled;

    fn_8022E928(lbl_8047EE00);
    if (ch < 0 || ch > 0xD) {
        return 0;
    }
    enabled = OSDisableInterrupts();
    state = (s8)base[0x708];
    OSRestoreInterrupts(enabled);
    if ((u32)state == 3) {
        if (ch == 0) {
            n0 = 0xFF;
            n1 = 0xFF;
        } else {
            x = (ch + 1) * 5;
            n0 = x - 0xE;
            n1 = x + 0xE;
            if (n0 < 0) {
                n0 = 0;
            }
            if (n1 > 0x4E) {
                n1 = 0x4E;
            }
        }
        tmp = fn_8023A5C0((u8)n0, (u8)n1);
        fn_8022E928(lbl_8047EE18, (u8)tmp);
        result = 1;
    }
    return result;
}
