#pragma force_active on

extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void* fn_801BFC2C(void* p);

extern "C" void* fn_801CA9D4(void* obj) {
    void* result;
    OSLockMutex((char*)obj + 4);
    result = fn_801BFC2C((char*)obj + 0x1C);
    OSUnlockMutex((char*)obj + 4);
    return result;
}
