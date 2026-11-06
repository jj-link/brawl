#pragma force_active on
#include <revolution/OS/OSMutex.h>

extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" void fn_801CC7B0(void* self, void* node) {
    OSMutex* mutex = (OSMutex*)((char*)self + 0x354);
    void* it;
    OSLockMutex(mutex);
    it = (char*)self + 0x388;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode((char*)self + 0x384, &it, node);
    OSUnlockMutex(mutex);
}
