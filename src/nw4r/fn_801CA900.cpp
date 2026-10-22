#pragma force_active on

extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" int fn_801BFB88(void* a, int b, void* c, int d);
extern "C" void fn_801CAA9C(void);

extern "C" int fn_801CA900(void* obj, int arg) {
    int result;
    OSLockMutex((char*)obj + 4);
    result = fn_801BFB88((char*)obj + 0x1C, arg, (void*)fn_801CAA9C, 0);
    OSUnlockMutex((char*)obj + 4);
    return result;
}
