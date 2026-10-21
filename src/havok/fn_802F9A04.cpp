#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_802EFF2C(u8 *, s8 *);
extern void fn_802F9A5C(u8 *, s32, s32);

void fn_802F9A04(u8 *arg0, u8 *arg1, u8 *arg2) {
    struct {
        u8 kind;
        u8 pad[3];
        u8 *a;
        u8 *b;
    } msg;
    s32 r6;
    s32 r0;

    r6 = *(s32 *)(arg1 + 0x58);
    r0 = *(s32 *)(arg2 + 0x58);
    if (*(s32 *)(arg0 + 0x7C) != 0) {
        msg.kind = 0xC;
        msg.a = arg1;
        msg.b = arg2;
        fn_802EFF2C(arg0, (s8 *)&msg);
        return;
    }
    fn_802F9A5C(arg0, r6, r0);
}
}
