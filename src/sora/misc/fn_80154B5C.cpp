#pragma force_active on
#include <revolution/OS/OSThread.h>
#include <types.h>

extern "C" int OSIsThreadTerminated(OSThread*);

static inline unsigned int terminated_check(OSThread* t) {
    return (unsigned int)__cntlzw((unsigned int)OSIsThreadTerminated(t) - 1) >> 5;
}

extern "C" s32 fn_80154B5C(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 r;

    if (terminated_check((OSThread*)(arg0 + 8))) {
        return 0;
    }
    if (*(s32*)(arg0 + 0x354) != 0x64) {
        return 0;
    }
    if (arg2 == 0 || arg3 == 0) {
        return 0;
    }
    r = -1;
    if (arg1 == 0) {
        r = 2;
    } else if (arg1 == 1) {
        r = 1;
    } else if (arg1 == 2) {
        r = 3;
    }
    if (r == -1) {
        return 0;
    }
    *(s32*)(arg0 + 0x354) = r;
    *(s32*)(arg0 + 0x358) = arg2;
    *(s32*)(arg0 + 0x35C) = arg3;
    OSResumeThread((OSThread*)(arg0 + 8));
    return 1;
}
