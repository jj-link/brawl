#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);

extern "C" {
void fn_801CAE60(void* self, void* node) {
    OSLockMutex((OSMutex*)((char*)self + 0x48));
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(self, (char*)node + 0xC0);
    *(int*)((char*)node + 0x10) = 0;
    OSUnlockMutex((OSMutex*)((char*)self + 0x48));
}
}
