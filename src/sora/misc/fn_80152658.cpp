#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_80358D94(void*, void*);
extern "C" void fn_801525B4(void*, void*, void*);
extern "C" char lbl_8049ED08[];

struct Guard {
    void* mutex;
    unsigned char flag : 8;
};

extern "C" void fn_80152658(void* arg0) {
    int sp24[5];
    int sp10[5];
    Guard g;
    Guard* p = &g;

    p->mutex = lbl_8049ED08;
    p->flag = 1;
    if (p->flag != 0) {
        OSLockMutex(lbl_8049ED08);
    }
    fn_80358D94(sp24, sp10);
    if (p->flag != 0) {
        OSUnlockMutex(p->mutex);
    }
    fn_801525B4(arg0, sp24, sp10);
}
