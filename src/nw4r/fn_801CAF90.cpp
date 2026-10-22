#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);

extern "C" {
void fn_801CAF90(void* a, void* b) {
    char* p = (char*)a;
    OSMutex* mtx = (OSMutex*)(p + 0x48);
    OSLockMutex(mtx);
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(p + 0xC, (char*)b + 0xC8);
    OSUnlockMutex(mtx);
}
}
