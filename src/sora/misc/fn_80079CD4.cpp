#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);

extern "C" int fn_80079CD4(char* self) {
    int result;
    OSLockMutex(self + 0x340);
    result = (*(int*)(self + 0xCC8) + *(int*)(self + 0xCCC)) == 0;
    OSUnlockMutex(self + 0x340);
    return result;
}
