#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" u8* fn_801CC2E4();

extern "C" void fn_801C380C(u8* arg0, s32 arg1, s32 arg2) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    if (arg0[0x8C] == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }
    switch (arg1) {
    case 0:
        *(s32*)(arg0 + 0x9C) += arg2;
        break;
    case 1:
        *(f32*)(arg0 + 0xA0) += (f32)arg2;
        break;
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
