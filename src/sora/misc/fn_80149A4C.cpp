#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" char lbl_8049EC78[0x18];

extern "C" void fn_80149A4C(void*, void* ptr) {
    if (ptr != 0) {
        OSLockMutex(lbl_8049EC78);
        free__13gfHeapManagerFPv(ptr);
        OSUnlockMutex(lbl_8049EC78);
    }
}
