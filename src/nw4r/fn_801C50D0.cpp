#pragma force_active on

typedef unsigned char u8;

struct Node {
    u8 pad0[0x32];
    u8 active;
    u8 pad33[0xAD];
    Node* next;
};

struct Object {
    void* vtable;
    u8 pad4;
    u8 flag;
    u8 pad6[0xB6];
    Node* head;
};

extern "C" u8* fn_801CC2E4();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C51F4(Object*);
extern "C" void fn_801BE2D4(Node*);
extern "C" void fn_801BF3A0(Node*, u8);

extern "C" void fn_801C50D0(Object* self, int arg1) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    fn_801C51F4(self);

    for (Node* node = self->head; node != 0; node = node->next) {
        if (node->active != 0) {
            if (arg1 >= 0) {
                fn_801BF3A0(node, (u8)arg1);
            }
            fn_801BE2D4(node);
        }
    }

    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
