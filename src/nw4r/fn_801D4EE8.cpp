#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801BE7A4(char*);
extern "C" char* fn_801CC2E4();

extern "C" void fn_801D4EE8(char* arg0, s32 arg1, char* arg2) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    if (arg1 == 2) {
        fn_801BE7A4(arg0);
    }
    *(s32*)(arg2 + 0xD4) = 0;
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
