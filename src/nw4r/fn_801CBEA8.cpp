#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void* m);
extern "C" void OSUnlockMutex(void* m);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void* list, void** it, void* node);

extern "C" void fn_801CBEA8(char* self, char* node) {
    char* mtx = self + 0x48;
    void* it;
    OSLockMutex(mtx);
    *(char**)(node + 0x38) = self;
    it = self + 0x1c;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(self + 0x18, &it, node + 0x2c);
    self[0x2d] = 1;
    OSUnlockMutex(mtx);
}
