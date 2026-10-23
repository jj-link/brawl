#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Mutex {
    u8 d[24];
};

extern "C" void OSLockMutex(Mutex*);
extern "C" void OSUnlockMutex(Mutex*);

struct Link {
    Link* next;
};

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u32);

    u8 pad[0xBC];
    Link link;
};

extern "C" void fn_801CAD90(Link* self, u32 arg1) {
    Link* head = self;
    Link* p;
    Mutex* m = (Mutex*)((u8*)self + 0x48);

    OSLockMutex(m);
    p = (++head)->next;
    while (p != head) {
        Obj* cur = (Obj*)((u8*)p - 0xC0);
        p = cur->link.next;
        cur->f4(arg1);
    }
    OSUnlockMutex(m);
}
