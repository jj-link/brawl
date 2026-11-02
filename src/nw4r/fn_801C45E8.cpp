#pragma force_active on
extern "C" void fn_801BD158(void*);
extern "C" void* fn_801CFA14();
extern "C" void fn_801CFEEC(void*, void*);
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);
extern "C" void fn_801C0A68(void*, void*);

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Self {
    virtual void f0();
    virtual void f1(int);
    char pad[0x1f8 - 4];
    char* list;
    char pad2[0x208 - 0x1fc];
    unsigned char flag;
    char pad3[3];
    Sub* sub;
};

extern "C" void fn_801C45E8(Self* self) {
    if (self->flag != 0) {
        fn_801CFEEC(fn_801CFA14(), (char*)self + 0x410);
    }
    if (self->sub != 0) {
        self->sub->f2();
        self->sub = 0;
    }
    fn_801BD158(self);
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
