#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void* alloc__12gfMemoryPoolFPvUli(void*, unsigned long, int);
extern "C" char lbl_8049EC78[0x18];
extern "C" void* lbl_805A0434;

struct DWCAllocType {
    void* ntAlloc(int size, unsigned long a, unsigned long b);
};

void* DWCAllocType::ntAlloc(int size, unsigned long a, unsigned long b) {
    if (size != 0) {
        OSLockMutex(lbl_8049EC78);
        void* result = alloc__12gfMemoryPoolFPvUli(*(void**)((char*)lbl_805A0434 + 0x353C), (unsigned long)size, 0x20);
        OSUnlockMutex(lbl_8049EC78);
        return result;
    }
    return 0;
}