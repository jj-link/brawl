#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern "C" char* fn_801CC2E4();
extern "C" void fn_801CC7B0(char*, void*);
extern "C" int fn_801D4284(char* p) {
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    char* node = p;
    if (p != 0) node = p + 0x80;
    fn_801CC7B0(fn_801CC2E4(), node);
    p[0x8d] = 1;
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    return 1;
}