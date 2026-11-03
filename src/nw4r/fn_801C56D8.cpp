#pragma force_active on
extern "C" {
    char* fn_801CC2E4();
    void OSLockMutex(void* m);
    void OSUnlockMutex(void* m);
    void fn_801BE7A4(void* p);
}

extern "C" void fn_801C56D8(char* arg0) {
    void* p;
    OSLockMutex(fn_801CC2E4() + 0x354);
    p = *(void**)(arg0 + 0xBC);
    while (p != 0) {
        fn_801BE7A4(p);
        p = *(void**)((char*)p + 0xE0);
    }
    *(int*)(arg0 + 0xBC) = 0;
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
