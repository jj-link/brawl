#pragma force_active on

typedef unsigned char u8;

struct Node {
    u8 pad[0xE0];
    Node* next;
};

class Listener {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void remove(Node*);
};

struct Object {
    u8 pad[0xB8];
    Listener* listener;
    Node* head;
};

extern "C" u8* fn_801CC2E4();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801BE7A4(Node*);

extern "C" void fn_801C5744(Node* node, int mode, Object* owner) {
    OSLockMutex(fn_801CC2E4() + 0x354);

    switch (mode) {
    case 0:
    case 2:
        fn_801BE7A4(node);
        break;
    case 1:
        break;
    }

    if (owner->listener) {
        owner->listener->remove(node);
    }

    Node* current = owner->head;
    if (current == node) {
        owner->head = node->next;
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }

    for (; current->next; current = current->next) {
        if (current->next == node) {
            current->next = node->next;
            OSUnlockMutex(fn_801CC2E4() + 0x354);
            return;
        }
    }

    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
