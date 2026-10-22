#pragma force_active on
extern "C" {
    char* fn_801CC2E4();
    void OSLockMutex(void* m);
    void OSUnlockMutex(void* m);
    void fn_801C093C(void* a, void* b, unsigned int c);
}

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_801CD554(Obj* self) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    self->f2();
    if (((unsigned char*)self)[0xB8] == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }
    *(int*)((char*)self + 0x7B8) = 0;
    fn_801C093C((char*)self + 0x134, (char*)self + 0x138, 0x680);
    ((unsigned char*)self)[0xB8] = 0;
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
