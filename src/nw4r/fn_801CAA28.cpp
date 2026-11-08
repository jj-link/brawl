#pragma force_active on
#include <revolution/OS/OSMutex.h>

extern "C" void fn_801BFCF8(void*, void*);
extern "C" char* fn_801CC2E4();

extern "C" void fn_801CAA28(void* a, void* b) {
    char* p = (char*)a;
    void* self = p + 0x4;
    char* list = p + 0x1C;
    OSLockMutex((OSMutex*)self);
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    fn_801BFCF8(list, b);
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    OSUnlockMutex((OSMutex*)self);
}
