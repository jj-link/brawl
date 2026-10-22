#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_80025F2C(void*, int);
extern "C" char lbl_8049EC78[0x18];
extern "C" void* lbl_805A0434;

struct DWCAllocType {
    void ntFree(int size, void* ptr);
};

void DWCAllocType::ntFree(int size, void* ptr) {
    if (size != 0) {
        OSLockMutex(lbl_8049EC78);
        fn_80025F2C(*(void**)((char*)lbl_805A0434 + 0x353C), size);
        OSUnlockMutex(lbl_8049EC78);
    }
}
