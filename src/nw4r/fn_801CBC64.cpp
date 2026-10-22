#pragma force_active on
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);

class VObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};

extern "C" void fn_801CBC64(char* self, unsigned int arg) {
    void* m = self + 0x48;
    OSLockMutex(m);
    *(unsigned short*)(self + 0x24) = (unsigned short)arg;
    if (*(unsigned char*)(self + 0x2d) != 0) {
        unsigned int a = (unsigned short)arg;
        unsigned short lim = *(unsigned short*)(self + 0x26);
        if (a > lim) {
            a = lim;
        }
        *(unsigned short*)(self + 0x24) = (unsigned short)a;
    }
    while (*(int*)self > (int)*(unsigned short*)(self + 0x24)) {
        char* p = *(char**)(self + 0x10) - 0xC8;
        VObj* o = (VObj*)p;
        o->f8();
    }
    OSUnlockMutex(m);
}
