#pragma force_active on

extern "C" void fn_801BD158();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);
extern "C" void fn_801C0A68(void*, void*);

struct Self {
    virtual void f0();
    virtual void f1(int);
    char pad[0x924 - 4];
    char* list;
};

extern "C" void fn_801CF774(Self* self) {
    fn_801BD158();
    char* mtx;
    char* list = self->list;
    mtx = list + 0x10;
    OSLockMutex(mtx);
    if (*(int*)(list + 4) == 0) {
        OSUnlockMutex(mtx);
        return;
    }
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(list + 4, (char*)self + 0xb8);
    self->f1(-1);
    fn_801C0A68(list, self);
    OSUnlockMutex(mtx);
}
