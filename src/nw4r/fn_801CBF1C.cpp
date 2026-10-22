#pragma force_active on
typedef int s32;

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void* list, void* it, void* node);

struct Owner {
    char pad[0x48];
    char mutex[0x18];
};

struct Holder {
    char pad[4];
    void* node;
};

extern "C" void fn_801CBF1C(char* self, Holder* arg1) {
    s32 it;
    void* mutex = self + 0x48;
    void* node;

    OSLockMutex(mutex);
    node = arg1->node;
    if (node != 0) {
        it = (s32)(self + 0x1C);
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(self + 0x18, &it, (char*)node + 0x2C);
    }
    if (node != 0) {
        *(s32*)((char*)node + 0x34) = 0;
    }
    arg1->node = 0;
    OSUnlockMutex(mutex);
}
