#pragma force_active on
#include <revolution/OS/OSMutex.h>

extern "C" void
Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);

extern "C" void fn_801CC818(void* self, void* node) {
    OSMutex* mutex = (OSMutex*)((char*)self + 0x354);
    OSLockMutex(mutex);
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode((void*)((char*)self + 0x384), node);
    OSUnlockMutex(mutex);
}
