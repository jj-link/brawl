#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" char* fn_801CC2E4();
extern "C" void fn_801BFA5C(void*);

extern "C" void fn_801CA970(char* obj) {
    OSMutex* mutex = (OSMutex*)(obj + 4);
    OSLockMutex(mutex);
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    fn_801BFA5C(obj + 0x1C);
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    OSUnlockMutex(mutex);
}