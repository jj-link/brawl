#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801CAFEC(void*);

struct Node {
    Node* next;
};

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[0xBC];
};

struct Owner {
    char pad[4];
    Node head;
};

extern "C" void fn_801CAD08(Owner* self) {
    Node* cur;
    Node* head;
    void* mutex;

    mutex = (char*)self + 0x48;
    OSLockMutex(mutex);
    head = &self->head;
    cur = self->head.next;

    while (cur != head) {
        Node* old = cur;
        cur = cur->next;
        ((Obj*)old - 1)->f2();
    }

    fn_801CAFEC(self);
    OSUnlockMutex(mutex);
}
