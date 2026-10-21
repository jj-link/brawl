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

extern "C" u8 lbl_80466AE0[];
extern "C" u8* fn_801CC2E4();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C51F4(Object*);
extern "C" void fn_801BE2D4(Node*);
extern "C" void fn_801BE7A4(Node*);
extern "C" void __dl__FPv(void*);

extern "C" Object* fn_801C4B68(Object* self, int deleting) {
    if (self != 0) {
        self->vtable = lbl_80466AE0;
        OSLockMutex(fn_801CC2E4() + 0x354);
        OSLockMutex(fn_801CC2E4() + 0x354);
        fn_801C51F4(self);

        for (Node* node = self->head; node != 0; node = node->next) {
            if (node->active != 0) {
                fn_801BE2D4(node);
            }
        }

        OSUnlockMutex(fn_801CC2E4() + 0x354);
        OSLockMutex(fn_801CC2E4() + 0x354);

        for (Node* node = self->head; node != 0; node = node->next) {
            fn_801BE7A4(node);
        }

        self->head = 0;
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        self->flag = 0;
        OSUnlockMutex(fn_801CC2E4() + 0x354);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
