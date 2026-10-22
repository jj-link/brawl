#include <types.h>
#pragma force_active on

extern s32 fn_803930B8(s32);
extern void fn_803930AC(s32);
extern void OSInitMessageQueue(s32, s32, s32);
extern s32 OSCreateThread(s32, s32, s32, s32, u32, s32, u16);
extern s32 OSResumeThread(s32);
extern s32 fn_80390AFC(s32);

s32 fn_80390954(s32 arg0, s32 arg1, s32 arg2) {
    if (fn_803930B8(arg0) == 0) {
        OSInitMessageQueue(arg0, arg0 + 0x20, 3);
        fn_803930AC(arg0);
    }
    OSCreateThread(arg0 + 0x30, (s32)fn_80390AFC, 0, arg2 + 0x2000, 0x2000, arg1, 0);
    OSResumeThread(arg0 + 0x30);
    return 1;
}
