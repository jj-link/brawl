#pragma force_active on
struct Subject {
    unsigned char pad[0xB0];
    unsigned int taskId;
};

struct Node0 {
    unsigned char pad[0x60];
    struct Node1* next;
};

struct Node1 {
    unsigned char pad[0xD8];
    struct Node2* next;
};

struct Node2 {
    unsigned char pad[0x70];
    struct Node3* next;
};

struct Node3 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int call();
};

extern "C" void* getInstance__9emManagerFv();
extern "C" void* fn_41_D044(void*, unsigned int);
extern "C" int fn_41_D0A8(void*, void*);
extern "C" struct Node0* fn_41_CECC(void*, void*);

extern "C" int fn_41_B4C4(struct Subject* subject) {
    void* task = fn_41_D044(getInstance__9emManagerFv(), subject->taskId);
    if (!fn_41_D0A8(getInstance__9emManagerFv(), task)) {
        return -1;
    }
    struct Node0* node0 = fn_41_CECC(getInstance__9emManagerFv(), task);
    struct Node3* node3 = node0->next->next->next;
    return node3->call();
}
