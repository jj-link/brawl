#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C4DD0(void*, s32, s32);
extern "C" void fn_801C4DE0(void*);
extern "C" char* fn_801CC2E4();

extern "C" void fn_801C3540(char* arg0, s32 arg1, s32 arg2) {
    char* obj;

    OSLockMutex(fn_801CC2E4() + 0x354);
    obj = *(char**)(arg0 + 0xB8);
    if (arg1 != 0) {
        fn_801C4DD0(obj, arg1, arg2);
        fn_801C4DE0(obj);
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
